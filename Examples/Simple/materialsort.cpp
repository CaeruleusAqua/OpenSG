// OpenSG Tutorial Example: Materials
//
// This example shows how to manually change the render order of materials.
// For intersecting geometries transparent sorting (on the object level) is
// not sufficient, so we help out manually and set a sort key for
// each material.

#ifdef OSG_BUILD_INTEGRATED
// Headers
#include <OSGGLUT.h>
#include <OSGConfig.h>
#include <OSGSimpleGeometry.h>
#include <OSGGLUTWindow.h>
#include <OSGSimpleSceneManager.h>
#include <OSGBaseFunctions.h>
#include <OSGTransform.h>
#include <OSGGroup.h>
#include <OSGPointLight.h>
#include <OSGRenderAction.h>
#include <OSGSceneFileHandler.h>
#include <OSGPolygonChunk.h>

// the headers for the SimpleMaterials
#include <OSGSimpleMaterial.h>
#include <OSGImage.h>
#else
// Headers
#include <OpenSG/OSGGLUT.h>
#include <OpenSG/OSGConfig.h>
#include <OpenSG/OSGSimpleGeometry.h>
#include <OpenSG/OSGGLUTWindow.h>
#include <OpenSG/OSGSimpleSceneManager.h>
#include <OpenSG/OSGBaseFunctions.h>
#include <OpenSG/OSGTransform.h>
#include <OpenSG/OSGGroup.h>
#include <OpenSG/OSGPointLight.h>
#include <OpenSG/OSGRenderAction.h>
#include <OpenSG/OSGSceneFileHandler.h>
#include <OpenSG/OSGPolygonChunk.h>

// the headers for the SimpleMaterials
#include <OpenSG/OSGSimpleMaterial.h>
#include <OpenSG/OSGImage.h>
#endif

// Activate the OpenSG namespace
OSG_USING_NAMESPACE

// The SimpleSceneManager to manage simple applications
SimpleSceneManager *_mgr   = NULL;
NodeRefPtr          _scene;

// forward declaration so we can have the interesting stuff upfront
int setupGLUT(int *argc, char *argv[]);

// redraw the window
void display(void)
{
    _mgr->redraw();
}

void update(void)
{
    glutPostRedisplay();
}

// Initialize GLUT & OpenSG and set up the scene
int main(int argc, char **argv)
{
    // OSG init
    osgInit(argc,argv);

    // GLUT init
    int winid = setupGLUT(&argc, argv);

    // open a new scope, because the pointers below should go out of scope
    // before entering glutMainLoop.
    // Otherwise OpenSG will complain about objects being alive after shutdown.
    {
        // the connection between GLUT and OpenSG
        GLUTWindowRefPtr gwin = GLUTWindow::create();
        gwin->setGlutId(winid);
        gwin->init();
    
        // create the scene
        _scene = makeCoredNode<Group>();
    
        // create a polygon chunk for backface culling.
        PolygonChunkRefPtr pchunk = PolygonChunk::create();
        pchunk->setCullFace(GL_BACK);
        
        // create three transparent boxes.
        SimpleMaterialRefPtr mat1 = SimpleMaterial::create();
        mat1->setAmbient      (Color3f(0.2,0.2,0.2));
        mat1->setDiffuse      (Color3f(1.0,0.0,0.0));
        mat1->setEmission     (Color3f(0.0,0.0,0.0));
        mat1->setSpecular     (Color3f(0.4,0.4,0.4));
        mat1->setShininess    (80);
        mat1->setTransparency (0.5);
        // render this first (key 0)
        mat1->setSortKey      (0);
        mat1->addChunk        (pchunk);

        NodeRefPtr     box1 = makeBox(2.5, 2.5, 2.5, 1, 1, 1);
        GeometryRefPtr geo  = dynamic_cast<Geometry *>(box1->getCore());
        geo->setMaterial(mat1);
        
        SimpleMaterialRefPtr mat2 = SimpleMaterial::create();
        mat2->setAmbient      (Color3f(0.2,0.2,0.2));
        mat2->setDiffuse      (Color3f(0.0,1.0,0.0));
        mat2->setEmission     (Color3f(0.0,0.0,0.0));
        mat2->setSpecular     (Color3f(0.4,0.4,0.4));
        mat2->setShininess    (80);
        mat2->setTransparency (0.5);
        // render this second (key 1)
        mat2->setSortKey      (1);
        mat2->addChunk        (pchunk);

        NodeRefPtr box2 = makeBox(5.0, 5.0, 5.0, 1, 1, 1);
        geo = dynamic_cast<Geometry *>(box2->getCore());
        geo->setMaterial(mat2);
        
        SimpleMaterialRefPtr mat3 = SimpleMaterial::create();
        mat3->setAmbient      (Color3f(0.2,0.2,0.2));
        mat3->setDiffuse      (Color3f(0.0,0.0,1.0));
        mat3->setEmission     (Color3f(0.0,0.0,0.0));
        mat3->setSpecular     (Color3f(0.4,0.4,0.4));
        mat3->setShininess    (80);
        mat3->setTransparency (0.5);
        // render this third (key 2)
        mat3->setSortKey      (2);
        mat3->addChunk        (pchunk);
        NodeRefPtr box3 = makeBox(10.0, 10.0, 10.0, 1, 1, 1);
        geo = dynamic_cast<Geometry *>(box3->getCore());
        geo->setMaterial(mat3);
    
        _scene->addChild(box1);
        _scene->addChild(box2);
        _scene->addChild(box3);
        
        commitChanges();
        
        // create the SimpleSceneManager helper
        _mgr = new SimpleSceneManager;
    
        // tell the manager what to manage
        _mgr->setWindow(gwin );
        _mgr->setRoot  (_scene);
    
        // show the whole scene
        _mgr->showAll();
    }

    // GLUT main loop
    glutMainLoop();

    return 0;
}

//
// GLUT callback functions
//

// react to size changes
void reshape(int w, int h)
{
    _mgr->resize(w, h);
    glutPostRedisplay();
}

// react to mouse button presses
void mouse(int button, int state, int x, int y)
{
    if (state)
        _mgr->mouseButtonRelease(button, x, y);
    else
        _mgr->mouseButtonPress(button, x, y);
        
    glutPostRedisplay();
}

// react to mouse motions with pressed buttons
void motion(int x, int y)
{
    _mgr->mouseMove(x, y);
    glutPostRedisplay();
}

// react to keys
void keyboard(unsigned char k, int x, int y)
{
    switch(k)
    {
        case 27:
            //clean up global variables
            delete _mgr;
            _scene = NULL;
            
            OSG::osgExit();
            exit(0);
        break;
        case 'w':
            SceneFileHandler::the()->write(_scene, "scene.osb.gz", true);
            printf("wrote scene.\n");
        break;
    }
}

// setup the GLUT library which handles the windows for us
int setupGLUT(int *argc, char *argv[])
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    
    int winid = glutCreateWindow("OpenSG");
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    // call the redraw function whenever there's nothing else to do
    glutIdleFunc(update);

    return winid;
}
