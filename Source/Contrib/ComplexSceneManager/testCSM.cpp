
#include <OpenSG/OSGComplexSceneManager.h>
#include <OpenSG/OSGOSGSceneFileType.h>
#include <OpenSG/OSGBaseInitFunctions.h>

int init(int argc, char **argv)
{
    OSG::osgInit(argc,argv);

    // Assume dir is given
    if(argc == 2) 
    {
//        fprintf(stderr, "start from dir\n");

        std::string szParamFilename = argv[1];
        
        if(szParamFilename[szParamFilename.length() - 1] == '/')
        {
            szParamFilename += "params.csm";
        }
        else
        {
            szParamFilename += "/params.csm";
        }

        fprintf(stderr, "Trying to start from : %s\n", szParamFilename.c_str());

        OSG::ComplexSceneManager::startFrom(szParamFilename);
    }
    else
    {
        OSG::OSGSceneFileType::the().readContainer(
            "Source/Contrib/ComplexSceneManager/data/system-native.osg");
        
        fprintf(stderr, "Got %p\n", OSG::ComplexSceneManager::the());
        
        char *argvTmp[] = 
        {
            "testCSM",
            "Source/Contrib/ComplexSceneManager/data/system-native.osg",
            "--data",
            "TestData/tie.wrl",
            "--global",
            "Source/Contrib/ComplexSceneManager/data/simple_mouse.osg"
        };
    
        int argcTmp = 6;
        
        OSG::ComplexSceneManager::the()->init(argcTmp, argvTmp);
        
        OSG::ComplexSceneManager::the()->run();
    }
    
//    OSG::osgExit();

    return 0;
}

int main (int argc, char **argv)
{
    init(argc, argv);

    return 0;
}
