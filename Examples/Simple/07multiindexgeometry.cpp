// OpenSG Tutorial Example: Multiindex Geometry
//
// This example shows how to use an index mapping to use different indices
// for different attributes.
//

#ifdef OSG_BUILD_ACTIVE
// Headers
#include <OSGGLUT.h>
#include <OSGConfig.h>
#include <OSGSimpleGeometry.h>
#include <OSGGeoProperties.h>
#include <OSGGLUTWindow.h>
#include <OSGSimpleSceneManager.h>
#include <OSGBaseFunctions.h>
#include <OSGTransform.h>
#include <OSGGroup.h>
#include <OSGGeometry.h>
#else
// Headers
#include <OpenSG/OSGGLUT.h>
#include <OpenSG/OSGConfig.h>
#include <OpenSG/OSGSimpleGeometry.h>
#include <OpenSG/OSGGeoProperties.h>
#include <OpenSG/OSGGLUTWindow.h>
#include <OpenSG/OSGSimpleSceneManager.h>
#include <OpenSG/OSGBaseFunctions.h>
#include <OpenSG/OSGTransform.h>
#include <OpenSG/OSGGroup.h>
#include <OpenSG/OSGGeometry.h>
#endif

// The pointer to the transformation
OSG::TransformRefPtr trans;

// The SimpleSceneManager to manage simple applications
OSG::SimpleSceneManagerRefPtr mgr;

// forward declaration so we can have the interesting stuff upfront
int setupGLUT( int *argc, char *argv[] );

// redraw the window
void display( void )
{
    // create the matrix
    OSG::Matrix m;
    OSG::Real32 t = glutGet(GLUT_ELAPSED_TIME );
    
    m.setTransform(OSG::Quaternion(OSG::Vec3f(0,1,0), t / 1000.f));
    
    // set the transform's matrix
    trans->setMatrix(m);

    OSG::commitChanges();
   
    mgr->redraw();
}

// Initialize GLUT & OpenSG and set up the scene
int main(int argc, char **argv)
{
    // OSG init
    OSG::osgInit(argc,argv);

    // GLUT init
    int winid = setupGLUT(&argc, argv);

    /*
       open a new scope, because the pointers below should go out of scope
       before entering glutMainLoop.
       Otherwise OpenSG will complain about objects being alive after shutdown.
    */
    {
        // the connection between GLUT and OpenSG
        OSG::GLUTWindowRefPtr gwin = OSG::GLUTWindow::create();
        gwin->setGlutId(winid);
        gwin->init();
    
        /*
           create the scene

           In the previous example, the colors and positions used the same
           indices. That might not always be the preferred way, and it might not
           make sense for other properties, e.g. normals.

           It is possible to assign a different index for every property. See the
           indices section below for details.


           The initial setup is the same as in 06indexgeometry
        */

        OSG::GeoUInt8PropertyRefPtr type = OSG::GeoUInt8Property::create();
        type->addValue(GL_POLYGON  );
        type->addValue(GL_TRIANGLES);
        type->addValue(GL_QUADS    );
    
        OSG::GeoUInt32PropertyRefPtr lens = OSG::GeoUInt32Property::create();
        lens->addValue(4);
        lens->addValue(6);
        lens->addValue(8);
        
        // positions
        OSG::GeoPnt3fPropertyRefPtr pnts = OSG::GeoPnt3fProperty::create();
        // the base
        pnts->addValue(OSG::Pnt3f(-1, -1, -1));
        pnts->addValue(OSG::Pnt3f(-1, -1,  1));
        pnts->addValue(OSG::Pnt3f( 1, -1,  1));
        pnts->addValue(OSG::Pnt3f( 1, -1, -1));
    
        // the roof base
        pnts->addValue(OSG::Pnt3f(-1,  0, -1));
        pnts->addValue(OSG::Pnt3f(-1,  0,  1));
        pnts->addValue(OSG::Pnt3f( 1,  0,  1));
        pnts->addValue(OSG::Pnt3f( 1,  0, -1));
    
        // the gable
        pnts->addValue(OSG::Pnt3f( 0,  1, -1));
        pnts->addValue(OSG::Pnt3f( 0,  1,  1));
    
        // colors
        OSG::GeoVec3fPropertyRefPtr colors = OSG::GeoVec3fProperty::create();
        colors->push_back(OSG::Color3f(1, 1, 0));
        colors->push_back(OSG::Color3f(1, 0, 0));
        colors->push_back(OSG::Color3f(1, 0, 0));
        colors->push_back(OSG::Color3f(1, 1, 0));
        colors->push_back(OSG::Color3f(0, 1, 1));
        colors->push_back(OSG::Color3f(1, 0, 1));
        
        /*
           A new property: normals.

           They are used for lighting calculations and have to point away from the
           surface. Normals are standard vectors.
        */
        
        OSG::GeoVec3fPropertyRefPtr norms = OSG::GeoVec3fProperty::create();
        norms->push_back(OSG::Vec3f(-1,  0,  0));
        norms->push_back(OSG::Vec3f( 1,  0,  0));
        norms->push_back(OSG::Vec3f( 0, -1,  0));
        norms->push_back(OSG::Vec3f( 0,  1,  0));
        norms->push_back(OSG::Vec3f( 0,  0, -1));
        norms->push_back(OSG::Vec3f( 0,  0,  1));
        
        /*
           To use more than one index for a geometry, create multiple
           GeoUInt32Property (or GeoUInt8Property or GeoUInt16Property) objects
           and add them as index for the corresponding property you want to
           index.
        */
        
        OSG::GeoUInt32PropertyRefPtr ind1 = OSG::GeoUInt32Property::create();
        OSG::GeoUInt32PropertyRefPtr ind2 = OSG::GeoUInt32Property::create();
        
        // fill first index (will be used for positions)
        ind1->push_back(0);     // polygon
        ind1->push_back(1);
        ind1->push_back(2);
        ind1->push_back(3);
        
        ind1->push_back(7);     // triangle 1
        ind1->push_back(4);
        ind1->push_back(8);
        ind1->push_back(5);     // triangle 2
        ind1->push_back(6);
        ind1->push_back(9);
        
        ind1->push_back(1);     // quad 1
        ind1->push_back(2);
        ind1->push_back(6);
        ind1->push_back(5);
        ind1->push_back(3);     // quad 2
        ind1->push_back(0);
        ind1->push_back(4);
        ind1->push_back(7);
        
        // fill second index (will be used for colors/normals)
        ind2->push_back(3);     // polygon
        ind2->push_back(3);
        ind2->push_back(3);
        ind2->push_back(3);
        
        ind2->push_back(4);     // triangle 1
        ind2->push_back(4);
        ind2->push_back(4);
        ind2->push_back(5);     // triangle 2
        ind2->push_back(5);
        ind2->push_back(5);
        
        ind2->push_back(5);     // quad 1
        ind2->push_back(5);
        ind2->push_back(5);
        ind2->push_back(5);
        ind2->push_back(4);     // quad 2
        ind2->push_back(4);
        ind2->push_back(4);
        ind2->push_back(4);
        

        /*
            Put it all together into a Geometry NodeCore.
        */
        OSG::GeometryRefPtr geo = OSG::Geometry::create();
        geo->setTypes    (type);
        geo->setLengths  (lens);
        
        /*
           Set the properties and indices used to index them.
           Calling geo->setProperty(pnts, Geometry::PositionsIndex) is the
           same as calling geo->setPositions(pnts), but this way it is
           more obvious which properties and indices go together.
        */
        
        geo->setProperty(pnts,   OSG::Geometry::PositionsIndex);
        geo->setIndex   (ind1,   OSG::Geometry::PositionsIndex);
        
        geo->setProperty(norms,  OSG::Geometry::NormalsIndex  );
        geo->setIndex   (ind2,   OSG::Geometry::NormalsIndex  );
        
        geo->setProperty(colors, OSG::Geometry::ColorsIndex   );
        geo->setIndex   (ind2,   OSG::Geometry::ColorsIndex   );
        
        geo->setMaterial (OSG::getDefaultMaterial());   
        
        // put the geometry core into a node
        OSG::NodeRefPtr n = OSG::Node::create();
        n->setCore(geo);
        
        // add a transformation to make it move     
        OSG::NodeRefPtr scene = OSG::Node::create();
        trans = OSG::Transform::create();
        scene->setCore(trans);
        scene->addChild(n);
    
        OSG::commitChanges();
    
        // create the SimpleSceneManager helper
        mgr = OSG::SimpleSceneManager::create();
    
        // tell the manager what to manage
        mgr->setWindow(gwin );
        mgr->setRoot  (scene);
    
        // show the whole scene
        mgr->showAll();
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
    mgr->resize(w, h);
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

// react to keys
void keyboard(unsigned char k, int x, int y)
{
    switch(k)
    {
        case 27:    
        {
            // clean up global variables
            trans = NULL;
            mgr   = NULL;

            OSG::osgExit();
            exit(0);
        }
        break;

        case 's':
        {
            mgr->setStatistics(!mgr->getStatistics());
        }
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
    glutIdleFunc(display);

    return winid;
}
