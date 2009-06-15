// all needed include files
#include <OpenSG/OSGGLUT.h>
#include <OpenSG/OSGConfig.h>
#include <OpenSG/OSGSimpleGeometry.h>
#include <OpenSG/OSGGLUTWindow.h>
#include <OpenSG/OSGSimpleSceneManager.h>
#include <OpenSG/OSGGeometry.h>

#include <OpenSG/OSGTypedGeoIntegralProperty.h>
#include <OpenSG/OSGTypedGeoVectorProperty.h>

// this will specify the resolution of the mesh
#define N   100

//the two dimensional array that will store all height values
OSG::Real32 wMesh[N][N];

//the origin of the water mesh
OSG::Pnt3f wOrigin = OSG::Pnt3f(0,0,0);

//width and length of the mesh
OSG::UInt16 width  = 100;
OSG::UInt16 length = 100;

OSG::SimpleSceneManager *mgr;
OSG::NodeRecPtr          scene;

int setupGLUT( int *argc, char *argv[] );

OSG::NodeTransitPtr createScenegraph(void)
{
    // the scene must be created here
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            wMesh[i][j] = 0;
    
    // the types of primitives that are used - an integerer propery
    OSG::GeoUInt8PropertyRecPtr types = OSG::GeoUInt8Property::create();
    
    // we want to use quads ONLY 
    types->addValue(GL_QUADS);
    
    // the number of vertices (or indices) we want to use with the primitive
    // type; types and lengths always have the same number of elements
    // (here both have just one)
    OSG::GeoUInt32PropertyRecPtr lengths = OSG::GeoUInt32Property::create();
    // the length of our quads is four ;-)
    lengths->addValue(4 * (N - 1) * (N - 1));

    // GeoPnt3fProperty stores the positions of all vertices used in
    // this specific geometry core
    OSG::GeoPnt3fPropertyRecPtr pos = OSG::GeoPnt3fProperty::create();
    // here they all come
    for (int x = 0; x < N; x++)
        for (int z = 0; z < N; z++)
            pos->addValue(OSG::Pnt3f(x, wMesh[x][z], z));

    // GeoColor3fProperty stores all color values that will be used
    OSG::GeoColor3fPropertyRecPtr colors = OSG::GeoColor3fProperty::create();
        for (int x = 0; x < N; x++)
            for (int z = 0; z < N; z++)
                colors->addValue(OSG::Color3f(0,0,1));
    
    // and finally the normals are stored in a GeoVec3fProperty
    OSG::GeoVec3fPropertyRecPtr norms = OSG::GeoVec3fProperty::create();
    for (int x = 0; x < N; x++)
        for (int z = 0; z < N; z++)
            // As initially all heights are set to zero thus yielding a plane,
            // we set all normals to (0,1,0) parallel to the y-axis
            norms->addValue(OSG::Vec3f(0,1,0));
    
    OSG::SimpleMaterialRecPtr mat = OSG::SimpleMaterial::create();
    
    // Indices define the order in which the entries in the above properties
    // are used
    OSG::GeoUInt32PropertyRecPtr indices = OSG::GeoUInt32Property::create();
    for (int x = 0; x < N-1; x++)
    {
        for (int z = 0; z < N-1; z++)
        {
            // points to four vertices that will
            // define a single quad
            indices->addValue( z    * N + x    );
            indices->addValue((z+1) * N + x    );
            indices->addValue((z+1) * N + x + 1);
            indices->addValue( z    * N + x + 1);
        }
    }

    OSG::GeometryRecPtr geo = OSG::Geometry::create();

    geo->setTypes    (types  );
    geo->setLengths  (lengths);
    geo->setIndices  (indices);
    geo->setPositions(pos    );
    geo->setNormals  (norms  );
    geo->setMaterial (mat    );
    geo->setColors   (colors );
    
    OSG::NodeRecPtr root = OSG::Node::create();
    root->setCore(geo);

    return OSG::NodeTransitPtr(root);
}

int main(int argc, char **argv)
{
    OSG::osgInit(argc,argv);
    
    {
        int winid = setupGLUT(&argc, argv);
        OSG::GLUTWindowRecPtr gwin = OSG::GLUTWindow::create();
        gwin->setGlutId(winid);
        gwin->init();
    
        scene = createScenegraph();
    
        mgr = new OSG::SimpleSceneManager;
        mgr->setWindow(gwin );
        mgr->setRoot  (scene);
        mgr->showAll();
        
        OSG::Navigator * nav = mgr->getNavigator();
        nav->setFrom(nav->getFrom()+OSG::Vec3f(0,2,0));
        
        OSG::commitChanges();
    }
    
    glutMainLoop();

    return 0;
}

void reshape(int w, int h)
{
    mgr->resize(w, h);
    glutPostRedisplay();
}

void display(void)
{
        mgr->redraw();
}

void mouse(int button, int state, int x, int y)
{
    if (state)
        mgr->mouseButtonRelease(button, x, y);
    else
        mgr->mouseButtonPress(button, x, y);
        
    glutPostRedisplay();
}

void motion(int x, int y)
{
    mgr->mouseMove(x, y);
    glutPostRedisplay();
}

int setupGLUT(int *argc, char *argv[])
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    
    int winid = glutCreateWindow("OpenSG First Application");
    
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    
    return winid;
}
