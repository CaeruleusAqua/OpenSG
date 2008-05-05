
#include "OSGBaseInitFunctions.h"
#include "OSGNode.h"
#include "OSGNodeCore.h"
#include "OSGTestFC.h"

static void dumpAspect(OSG::TestFC *pFC, OSG::UInt32 uiAspect)
{
    OSG::UInt32 uiCurrAspect= OSG::Thread::getCurrentAspect();

    OSG::Thread::setAspectTo(uiAspect);

#ifdef OSG_MT_CPTR_ASPECT
    OSG::TestFC *pAFC = OSG::convertToCurrentAspect(pFC);
#else
    OSG::TestFC *pAFC = getCPtr(pFC);
#endif

    if(pAFC != NULL)
    {
        pAFC->dump();
    }
    else
    {
        fprintf(stderr, "No Aspect Ptr\n");
    }

    OSG::Thread::setAspectTo(uiCurrAspect);
}

void applyToAspect(OSG::UInt32 uiAspect, bool bClear = true)
{
    OSG::UInt32 uiCurrAspect= OSG::Thread::getCurrentAspect();

    OSG::Thread::setAspectTo(uiAspect);

    OSG::Thread::getCurrentChangeList()->applyNoClear();

    if(bClear == true)
    {
        OSG::Thread::getCurrentChangeList()->clear();
    }

    OSG::Thread::setAspectTo(uiCurrAspect);
}

void applyToAspectAndClear(OSG::UInt32 uiAspect)
{
    OSG::UInt32 uiCurrAspect= OSG::Thread::getCurrentAspect();

    OSG::Thread::setAspectTo(uiAspect);

    OSG::Thread::getCurrentChangeList()->applyAndClear();

    OSG::Thread::setAspectTo(uiCurrAspect);
}

void testSharing(void)
{
    fprintf(stderr, "sharing\n");
    fprintf(stderr, "%d\n", sizeof(OSG::TestFC));

    OSG::TestFCUnrecPtr pTestFC = OSG::TestFC::create();

    fprintf(stderr, "sharing | created\n");

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

//    OSG::addRefX(pTestFC);
//    OSG::addRefX(pTestFC);

    OSG::Thread::getCurrentChangeList()->dump();

//    OSG::beginEdit(pTestFC, OSG::TestFC::Field1FieldMask);
    {
        pTestFC->editMFField1()->reserve  (32);
        pTestFC->editMFField1()->push_back( 0);
        pTestFC->editMFField1()->push_back( 1);
        pTestFC->editMFField1()->push_back( 2);
        pTestFC->editMFField1()->push_back( 3);
    }
//    OSG::endEdit  (pTestFC, OSG::TestFC::Field1FieldMask);

    OSG::Thread::getCurrentChangeList()->dump();

//    OSG::beginEdit(pTestFC, OSG::TestFC::Field2FieldMask);
    {
        pTestFC->editSFField2()->setValue(4);
    }
//    OSG::endEdit  (pTestFC, OSG::TestFC::Field2FieldMask);

    OSG::Thread::getCurrentChangeList()->dump();

    OSG::Thread::getCurrentChangeList()->commitChanges();

//    OSG::subRefX(pTestFC);

    OSG::Thread::getCurrentChangeList()->dump();

    fprintf(stderr, "sharing | filled\n");

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);
        dumpAspect(pTestFC, i);
    }

    fprintf(stderr, "sharing | apply\n");

    applyToAspect(1, false);
    applyToAspect(2);

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

    pTestFC->editMFField1()->clear();
    pTestFC->editMFField1()->push_back( 10);
    pTestFC->editMFField1()->push_back( 11);
    pTestFC->editMFField1()->push_back( 12);
    pTestFC->editMFField1()->push_back( 13);

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

    applyToAspect(1, false);
    applyToAspect(2);

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

    pTestFC = NULL;
}

void testSharing1(void)
{
    fprintf(stderr, "sharing\n");
    fprintf(stderr, "%d\n", sizeof(OSG::TestFC));

    OSG::TestFCUnrecPtr pTestFC = OSG::TestFC::create();

    fprintf(stderr, "sharing | created\n");

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

//    OSG::addRefX(pTestFC);
//    OSG::addRefX(pTestFC);

    OSG::Thread::getCurrentChangeList()->dump();

    pTestFC->editMFField1()->reserve  (1024);

    for(OSG::UInt32 i = 0; i < 1024; ++i)
    {
        pTestFC->editMFField1()->push_back(i);
    }

    OSG::Thread::getCurrentChangeList()->dump();

    OSG::Thread::getCurrentChangeList()->commitChanges();

//    OSG::subRefX(pTestFC);

    OSG::Thread::getCurrentChangeList()->dump();

    fprintf(stderr, "sharing | filled\n");

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);
        dumpAspect(pTestFC, i);
    }

    fprintf(stderr, "sharing | apply\n");

    applyToAspect(1);


    while(1)
    {
        pTestFC->editMFField1();
        OSG::Thread::getCurrentChangeList()->commitChanges();
        applyToAspect(1);
    }


    pTestFC = NULL;
}

void testSharing2(void)
{
    fprintf(stderr, "sharing\n");
    fprintf(stderr, "%d\n", sizeof(OSG::TestFC));

    OSG::TestFCUnrecPtr pTestFC = OSG::TestFC::create();

    fprintf(stderr, "sharing | created\n");

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

//    OSG::addRefX(pTestFC);
//    OSG::addRefX(pTestFC);

    OSG::Thread::getCurrentChangeList()->dump();

    pTestFC->editMFField1()->reserve  (1024);

    for(OSG::UInt32 i = 0; i < 1024; ++i)
    {
        pTestFC->editMFField1()->push_back(i);
    }

    OSG::Thread::getCurrentChangeList()->dump();

    OSG::Thread::getCurrentChangeList()->commitChanges();

//    OSG::subRefX(pTestFC);

    OSG::Thread::getCurrentChangeList()->dump();

    fprintf(stderr, "sharing | filled\n");

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);
        dumpAspect(pTestFC, i);
    }

    fprintf(stderr, "sharing | apply\n");

    applyToAspect(1);



    pTestFC = NULL;

    applyToAspect(1);
}

void testNode(void)
{
#if 0
    OSG::SFNodePtr sfNode;
    OSG::MFNodePtr mfNode;

    OSG::NodePtr pNode = OSG::Node::create();

    sfNode.setValue(pNode);
    mfNode.push_back(pNode);

/*
    fprintf(stderr, "%p %p %p | %d %d\n", 
            pNode, 
            sfNode.getValue(), 
            mfNode[0],
            OSG::Node::VolumeFieldId,
            OSG::Node::TravMaskFieldId);
 */

    OSG::NodePtr pNode1 = OSG::Node::create();

    sfNode.setValue(pNode1);
    mfNode.resize(2);
    mfNode.replace(1, pNode1);

    const OSG::Field *pF1 = pNode->getSFVolume();
          OSG::Field *pF2 = pNode->editSFVolume();

    OSG::GetFieldHandlePtr  pRF1 = pNode->getField("volume");
    OSG::EditFieldHandlePtr pRF2 = pNode->editField("volume");

    fprintf(stderr, "#### Field %p %p | %p %p\n", 
            pF1, 
            pF2, 
            pRF1.get(), 
            pRF2.get());

//    fprintf(stderr, "%p %p %p\n", pNode1, sfNode.getValue(), mfNode[1]);

    const OSG::SFNodePtr constSFNode;

//    fprintf(stderr, "%p %p\n", pNode1, constSFNode.getValue());

    OSG::FieldContainerPtr pNodeClone = deepClone(pNode);

    OSG::subRefX(pNode);
    OSG::subRefX(pNode1);
    OSG::subRefX(pNodeClone);

    OSG::FieldContainerPtr pFC = 
        OSG::FieldContainerFactory::the()->createContainer("Billboard");

    fprintf(stderr, "### FOO %p\n", getCPtr(pFC));

    OSG::subRefX(pFC);
#endif
}


void testRefCount(void)
{
#if 0
    OSG::NodePtr pNode = OSG::Node::create();

    OSG::NodePtr pNode1 = OSG::Node::create();

    fprintf(stderr, "1\n");

//XX
#if 0
    pNode.dump();
    pNode1.dump();
#endif

    pNode->addChild(pNode1);

    fprintf(stderr, "2\n");

//XX
#if 0
    pNode.dump();
    pNode1.dump();
#endif

    OSG::addRefX(pNode);

    fprintf(stderr, "3\n");

//XX
#if 0
    pNode.dump();
    pNode1.dump();
#endif

    applyToAspect(1, false);
    applyToAspect(2);

    fprintf(stderr, "4\n");

//XX
#if 0
    pNode.dump();
    pNode1.dump();
#endif
    
    OSG::subRefX(pNode);

    fprintf(stderr, "5\n");

//XX
#if 0
    pNode.dump();
    pNode1.dump();
#endif

    applyToAspect(1, false);

    fprintf(stderr, "6\n");

//XX
#if 0
    pNode.dump();
    pNode1.dump();
#endif

    applyToAspect(2);

    fprintf(stderr, "7\n");
#endif
}

void testChangeList(void)
{
    fprintf(stderr, "testChangeList\n");
    fprintf(stderr, "%d\n", sizeof(OSG::TestFC));

    OSG::TestFCUnrecPtr pTestFC = OSG::TestFC::create();

    fprintf(stderr, "sharing | created\n");

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

//    OSG::addRefX(pTestFC);

    OSG::Thread::getCurrentChangeList()->dump();

    fprintf(stderr, "=================================================\n");

    pTestFC->editSFField2()->setValue(4);

    fprintf(stderr, "Changed\n");
    OSG::Thread::getCurrentChangeList()->dump();

    OSG::Thread::getCurrentChangeList()->commitChanges();

    fprintf(stderr, "Commited\n");
    OSG::Thread::getCurrentChangeList()->dump();

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

    fprintf(stderr, "=================================================\n");

    pTestFC->editSFField2()->setValue(4);

    fprintf(stderr, "Changed\n");
    OSG::Thread::getCurrentChangeList()->dump();

    OSG::Thread::getCurrentChangeList()->commitChangesAndClear();

    fprintf(stderr, "CommitAndCleared\n");
    OSG::Thread::getCurrentChangeList()->dump();

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

    fprintf(stderr, "=================================================\n");

    pTestFC->editSFField2()->setValue(4);

    fprintf(stderr, "Changed\n");
    OSG::Thread::getCurrentChangeList()->dump();

//    OSG::Thread::getCurrentChangeList()->commitChanges();

    applyToAspectAndClear(1);

    fprintf(stderr, "Changed\n");
    OSG::Thread::getCurrentChangeList()->dump();

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

    fprintf(stderr, "=================================================\n");

    pTestFC->editSFField2()->setValue(4);

    fprintf(stderr, "Changed\n");
    OSG::Thread::getCurrentChangeList()->dump();

//    OSG::Thread::getCurrentChangeList()->commitChanges();

    applyToAspect(1, false);

    fprintf(stderr, "Changed\n");
    OSG::Thread::getCurrentChangeList()->dump();

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

    fprintf(stderr, "=================================================\n");

    pTestFC->editSFField2()->setValue(4);

    fprintf(stderr, "Changed\n");
    OSG::Thread::getCurrentChangeList()->dump();

//    OSG::Thread::getCurrentChangeList()->commitChanges();

    applyToAspect(1, true);

    fprintf(stderr, "Changed\n");
    OSG::Thread::getCurrentChangeList()->dump();

    for(OSG::UInt32 i = 0; i < OSG::ThreadManager::getNumAspects(); ++i)
    {
        fprintf(stderr, "Aspect %d\n", i);

        dumpAspect(pTestFC, i);
    }

    pTestFC = NULL;
}

int main (int argc, char **argv)
{
    OSG::ThreadManager::setNumAspects(3);
    OSG::osgInit(argc, argv);

    OSG::Thread::getCurrentChangeList()->dump ();
    OSG::Thread::getCurrentChangeList()->clear();

    OSG::Node    ::getClassType().dump();
    OSG::NodeCore::getClassType().dump();    

//    testRefCount();
//    testNode();

    testSharing();

//    testChangeList();

    fprintf(stderr, "exit\n");

    OSG::osgExit();
}
