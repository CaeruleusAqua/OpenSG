
#include "OSGGLUT.h"
#include "OSGConfig.h"
#include "OSGSimpleGeometry.h"
#include "OSGPassiveWindow.h"
#include "OSGSimpleSceneManager.h"
#include "OSGSceneFileHandler.h"

#include "OSGDrawable.h"
#include "OSGSimpleStatisticsForeground.h"
#include "OSGStatElemTypes.h"
#include "OSGStatCollector.h"
#include "OSGRenderAction.h"
#include "OSGTextureObjChunk.h"
#include "OSGMaterialChunk.h"
#include "OSGSimpleSHLChunk.h"


OSG::SimpleSceneManagerRefPtr mgr  = NULL;
OSG::RenderActionRefPtr       ract = NULL;

OSG::PassiveWindowRecPtr              pwin;
OSG::SimpleStatisticsForegroundRecPtr statfg;

OSG::StatCollector         *collector(NULL);

bool show = true;
bool bGLFinish = false;

// Enum to track which stat method we are using
enum StatMethod
{ USE_CUSTOM, USE_SIMPLE, USE_NONE };

StatMethod gStatMethod(USE_CUSTOM);

// redraw the window
void display(void)
{
    mgr->redraw();

    // all done, swap
    glutSwapBuffers();
}

// react to size changes
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    mgr->resize(w,h);
    glutPostRedisplay();
}

// react to mouse button presses
void mouse(int button, int state, int x, int y)
{
    if (state)
        mgr->mouseButtonRelease(button, x, y);
    else
        mgr->mouseButtonPress(button, x, y);

    glutPostRedisplay();
}

// react to mouse motions with pressed buttons
void motion(int x, int y)
{
    mgr->mouseMove(x, y);
    glutPostRedisplay();
}

void initElements(void)
{
    if(collector != NULL)
    {
        collector->clearElems();
    }

    // add optional elements
//    collector->getElem(Drawable::statNTriangles);
}

void setStatMethod(StatMethod method)
{
    // Disable old method
    if (gStatMethod == USE_CUSTOM)
    {
        pwin->getPort(0)->removeObjFromForegrounds(statfg);
    }
    else if(gStatMethod == USE_SIMPLE)
    {
        mgr->setStatistics(false);
    }

    // Enable new method
    if(method == USE_CUSTOM)
    {
        std::cerr << "Setting to custom stats.\n";
        pwin->getPort(0)->addForeground(statfg);
        ract->setStatCollector(collector);
    }
    else if(method == USE_SIMPLE)
    {
        std::cerr << "Setting to ssm stats.\n";
        mgr->setStatistics(true);
    }
    else
    {
        std::cerr << "Setting to no stats.\n";
    }
    gStatMethod = method;
}


// react to keys
void keyboard(unsigned char k, int, int)
{
    switch(k)
    {
        case 27:
        {
            mgr    = NULL;
            pwin   = NULL;
            statfg = NULL;

            OSG::osgExit();
            exit(0);
        }

        // Output help about the controls
        // - If you add an option, please add it here too.
       case '?':
       case '/':
       case 'h':
       {
          std::cerr << "\nControls:"
                    << "v: Toggle drawing of volumes.\n"
                    << "z: Toggle zwrite on rendering action.\n"
                    << "r: switch to render action.\n"
                    << "t: switch to traversal action.\n"
                    << "n: toggle state sorting on action.\n"
                    << "m: set keygen to 0.\n"
                    << "s: set keygen for shaders.\n"
                    << "g: toggle using gl finish.\n"
                    << "x: toggle stat mode.\n"
                    << std::endl;
       }
       break;

        case 'v':
        {
            mgr->getRenderAction()->setVolumeDrawing(
                !mgr->getRenderAction()->getVolumeDrawing());
            std::cerr << "Volume Drawing: "
                      << (mgr->getRenderAction()->getVolumeDrawing() ?
                          "on":"off")
                      << std::endl;
        }
        break;

        case 'x':
        {
            if(USE_CUSTOM == gStatMethod)
            { setStatMethod(USE_SIMPLE); }
            else if(USE_SIMPLE == gStatMethod)
            { setStatMethod(USE_NONE); }
            else
            { setStatMethod(USE_CUSTOM); }
        }
        break;

        case 'r':
            initElements();
            mgr->setUseTraversalAction(false);
            break;
        case 't':
            initElements();
            mgr->setUseTraversalAction(true);
            break;

        case 'm':
            ract->setKeyGen(0);
            break;

        case 's':
        {
            OSG::UInt32 uiSId = 
                OSG::SimpleSHLChunk  ::getStaticClassId() & 0x000003FF;
            OSG::UInt32 uiTId = 
                OSG::TextureBaseChunk::getStaticClassId() & 0x000003FF;
            OSG::UInt32 uiMId = 
                OSG::MaterialChunk   ::getStaticClassId() & 0x000003FF;


            OSG::UInt32 uiKeyGen = (uiSId) | (uiTId << 10) | (uiMId << 20);

            ract->setKeyGen(uiKeyGen);
        }
        break;

        case 'g':
            bGLFinish = !bGLFinish;
            ract->setUseGLFinish(bGLFinish);
            //act->setUseGLFinish(bGLFinish);
            std::cerr << "Set use gl finish to: " << bGLFinish << std::endl;
            break;
    }
}


int main(int argc, char **argv)
{
    OSG::osgInit(argc,argv);

    // GLUT init
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenSG");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    pwin = OSG::PassiveWindow::create();
    pwin->init();

    {
        // create the scene
        OSG::NodeUnrecPtr scene;

        if(argc > 1 && !strcmp(argv[1],"-s"))
        {
            gStatMethod = USE_NONE;
            argv++;
            argc--;
        }

        OSG::NodeUnrecPtr file;

        if(argc > 1)
        {
            scene = OSG::Node::create();
            OSG::GroupUnrecPtr g = OSG::Group::create();

            scene->setCore(g);


            for(OSG::UInt16 i = 1; i < argc; ++i)
            {
                file = OSG::SceneFileHandler::the()->read(argv[i]);
                scene->addChild(file);
            }
        }
        else
        {
            scene = OSG::makeTorus(.5, 3, 16, 16);
        }

        // create the SimpleSceneManager helper
        mgr = OSG::SimpleSceneManager::create();

        // create the window and initial camera/viewport
        mgr->setWindow(pwin );
        // tell the manager what to manage
        mgr->setRoot  (scene);

        OSG::Thread::getCurrentChangeList()->commitChanges();

        // show the whole scene
        mgr->showAll();

        // add the statistics forground

        statfg = OSG::SimpleStatisticsForeground::create();

        statfg->setSize(25);
        statfg->setColor(OSG::Color4f(0,1,0,0.7f));

        statfg->addElement(OSG::RenderAction::statDrawTime, "Draw FPS: %r.3f");
        statfg->addElement(OSG::RenderAction::statDrawTime, "DrawTime: %.3f s");
        statfg->addElement(OSG::RenderAction::statTravTime, "TravTime: %.3f s");
        
        statfg->addElement(OSG::RenderAction::statNStates,   "%d state changes");
        statfg->addElement(OSG::RenderAction::statNMatrices, "%d matrix changes");
        statfg->addElement(OSG::RenderAction::statNGeometries, "%d Geometries drawn");
        statfg->addElement(OSG::RenderAction::statNShaders, "%d shaders");
        statfg->addElement(OSG::RenderAction::statNShaders, "%d shader parameters");

        statfg->addElement(OSG::Drawable::statNVertices, "%d vertices drawn");
        statfg->addElement(OSG::Drawable::statNPrimitives, "%d primitives drawn");
        statfg->addElement(OSG::Drawable::statNTriangles, "%d triangles drawn");
        statfg->addElement(OSG::Drawable::statNLines, "%d lines drawn");
        statfg->addElement(OSG::Drawable::statNPoints, "%d points drawn");
        
        statfg->addElement(OSG::TextureObjChunk::statNTextures, "%d textures");
        statfg->addElement(OSG::TextureObjChunk::statNTexBytes, "%d bytes of textures");

        collector = statfg->getCollector();

        ract = OSG::RenderAction::create();
        ract->setStatCollector(collector);

        mgr->setAction(ract);

        setStatMethod(gStatMethod);
    }

    // GLUT main loop
    glutMainLoop();

    return 0;
}

