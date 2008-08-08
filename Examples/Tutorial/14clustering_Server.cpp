#include <OpenSG/OSGGLUT.h>
#include <OpenSG/OSGConfig.h>
#include <OpenSG/OSGClusterServer.h>
#include <OpenSG/OSGGLUTWindow.h>
#include <OpenSG/OSGRenderAction.h>

OSG_USING_NAMESPACE

GLUTWindowRecPtr   window;
RenderAction      *ract;
ClusterServer     *server;

void display(void);
void reshape(int width, int height);

int main(int argc,char **argv)
{
    int winid;

    // initialize Glut
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_RGB |GLUT_DEPTH | GLUT_DOUBLE);

    if(!argv[1])
    {
        std::cout << "No name was given!" << std::endl;
        return -1;
    }
    
    // init OpenSG
    osgInit(argc, argv);

    winid = glutCreateWindow(argv[1]);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutSetCursor(GLUT_CURSOR_NONE);

    ract = RenderAction::create();

    window = GLUTWindow::create();
    window->setGlutId(winid);
    window->init();

    //create a new server that will be connected via multicast
    //argv[1] is the name of the server (at least it should be...)
    server = new ClusterServer(window, argv[1], "Multicast", "");
    server->start();

    glutMainLoop();

    return 0;
}

void display(void)
{
    //simply execute the render action
    server->render(ract);
    //and delete the change list
    OSG::Thread::getCurrentChangeList()->clear();
}

void reshape(int width, int height)
{
    window->resize(width, height);
}
