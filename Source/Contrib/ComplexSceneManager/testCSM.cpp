
#include <OpenSG/OSGComplexSceneManager.h>
#include <OpenSG/OSGOSGSceneFileType.h>
#include <OpenSG/OSGBaseInitFunctions.h>

int init(int argc, char **argv)
{
    OSG::osgInit(argc,argv);

    OSG::OSGSceneFileType::the().readContainer(
        "Source/Contrib/ComplexSceneManager/data/system.osg");

    fprintf(stderr, "Got %p\n", OSG::ComplexSceneManager::the());

    char *argvTmp[] = 
    {
        "testCSM",
        "Source/Contrib/ComplexSceneManager/data/system.osg",
        "--data",
        "TestData/tie.wrl",
        "--global",
        "Source/Contrib/ComplexSceneManager/data/simple_mouse.osg"
    };
    
    int argcTmp = 6;

    OSG::ComplexSceneManager::the()->init(argcTmp, argvTmp);

    OSG::ComplexSceneManager::the()->run();

//    OSG::osgExit();

    return 0;
}

int main (int argc, char **argv)
{
    init(argc, argv);

    return 0;
}
