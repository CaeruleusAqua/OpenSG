/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *           Copyright (C) 2003 by the OpenSG Forum                          *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU Library General Public License as published    *
 * by the Free Software Foundation, version 2.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU Library General Public         *
 * License along with this library; if not, write to the Free Software       *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                Changes                                    *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
\*---------------------------------------------------------------------------*/

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include "OSGChangeList.h"
#include "OSGContainerPtrFuncs.h"

#include "OSGFieldContainer.h"
#include "OSGFieldContainerType.h"

#ifdef OSG_ENABLE_VALGRIND_CHECKS
#include <valgrind/memcheck.h>
#endif

OSG_USING_NAMESPACE

#define SILENT
#define SILENT_CPTR

#if 1
void ChangeList::addAddRefd(const UInt32 uiContainerId)
{
#ifdef OSG_ENABLE_VALGRIND_CHECKS
    VALGRIND_CHECK_VALUE_IS_DEFINED(uiContainerId);
#endif

#ifndef SILENT
    fprintf(stderr, "Add AddRef %u\n",
            uiContainerId);
#endif

    ContainerChangeEntry *pEntry = getNewEntry();

    pEntry->uiEntryDesc   = ContainerChangeEntry::AddReference;
    pEntry->uiContainerId = uiContainerId;
}

void ChangeList::addSubRefd(const UInt32 uiContainerId)
{
#ifdef OSG_ENABLE_VALGRIND_CHECKS
    VALGRIND_CHECK_VALUE_IS_DEFINED(uiContainerId);
#endif

#ifndef SILENT
    fprintf(stderr, "Add SubRef %u\n", uiContainerId);
#endif

    ContainerChangeEntry *pEntry = getNewEntry();

    if(_iSubRefLevel == 0)
    {
        pEntry->uiEntryDesc   = ContainerChangeEntry::SubReference;
    }
    else
    {
        pEntry->uiEntryDesc   = ContainerChangeEntry::DepSubReference;
    }

    pEntry->uiContainerId = uiContainerId;
}

void ChangeList::addCreated(const UInt32 uiContainerId)
{
#ifdef OSG_ENABLE_VALGRIND_CHECKS
    VALGRIND_CHECK_VALUE_IS_DEFINED(uiContainerId);
#endif

    FieldContainerPtr pTmp =
        FieldContainerFactory::the()->getContainer(uiContainerId);

#ifndef SILENT
    fprintf(stderr, "Add Create %u\n",
            uiContainerId);
#endif

    ContainerChangeEntry *pEntry = getNewCreatedEntry();

    pEntry->uiEntryDesc   = ContainerChangeEntry::Create;
    pEntry->uiContainerId = uiContainerId;
}

void ChangeList::addUncommited(ContainerChangeEntry *pEntry)
{
#ifndef SILENT
    fprintf(stderr, "Added changed %d\n", pEntry->uiContainerId);
#endif

    _uncommitedChanges.push_back(pEntry);
}
#endif



BitVector ContainerChangeEntry::defaultVec = TypeTraits<BitVector>::BitsClear;

void ContainerChangeEntry::commitChanges(void)
{
#ifdef OSG_ENABLE_VALGRIND_CHECKS
    VALGRIND_CHECK_VALUE_IS_DEFINED(uiContainerId);
#endif
    FieldContainerPtr pTmp =
        FieldContainerFactory::the()->getContainer(uiContainerId);

    if(pTmp != NullFC)
    {
#ifndef SILENT
        fprintf(stderr, "Commit for %u %s\n",
                uiContainerId, pTmp->getType().getCName());
#endif

        BitVector tmpChanges = uncommitedChanges;

        // moved to FieldContainer::changed()
        // pTmp->callChangedFunctors(uncommitedChanges);

        whichField        |= uncommitedChanges;
        uncommitedChanges  = TypeTraits<BitVector>::BitsClear;

        pTmp->changed      (tmpChanges, ChangedOrigin::Commit);
    }
}

void ContainerChangeEntry::commitChangesAndClear(void)
{
#ifdef OSG_ENABLE_VALGRIND_CHECKS
    VALGRIND_CHECK_VALUE_IS_DEFINED(uiContainerId);
#endif
    FieldContainerPtr pTmp =
        FieldContainerFactory::the()->getContainer(uiContainerId);

#ifndef SILENT
    fprintf(stderr, "Commit for and clear %u %s\n",
            uiContainerId, pTmp->getType().getCName());
#endif

    if(pTmp != NullFC)
    {
        pTmp->setChangeEntry(NULL);
        pTmp->changed(uncommitedChanges, ChangedOrigin::Commit);

        whichField        |= uncommitedChanges;
        uncommitedChanges  = TypeTraits<BitVector>::BitsClear;
    }
}

/*-------------------------------------------------------------------------*/
/*                            Constructors                                 */

ChangeList::ChangeList(void) :
     Inherited         (                   ),
    _entryPool         (                   ),
    _currentPoolElement(                   ),
    _currentEntry      (                   ),
    _changedStore      (                   ),
    _createdStore      (                   ),
    _uncommitedChanges (                   ),
    _workStore         (                   ),
    _uiAspect          (                  0),
    _iSubRefLevel      (                  0)
{
    _entryPool.push_back(ChangeEntryStore());

    _currentPoolElement = _entryPool.begin();

    _currentPoolElement->resize(32);

    _currentEntry = _currentPoolElement->begin();
}

/*-------------------------------------------------------------------------*/
/*                             Destructor                                  */

ChangeList::~ChangeList(void)
{
}

/*-------------------------------------------------------------------------*/
/*                             Assignment                                  */

ContainerChangeEntry *ChangeList::createNewEntry(void)
{
    if(_currentEntry == _currentPoolElement->end())
    {
        ++_currentPoolElement;

        if(_currentPoolElement == _entryPool.end())
        {
            _entryPool.push_back(ChangeEntryStore());

              _currentPoolElement = _entryPool.end();
            --_currentPoolElement;

              _currentPoolElement->resize(32);
        }

        _currentEntry = _currentPoolElement->begin();
    }

    ContainerChangeEntry *returnValue = &(*_currentEntry);

    ++_currentEntry;

    return returnValue;
}




ContainerChangeEntry *ChangeList::getNewEntry(void)
{
    ContainerChangeEntry *returnValue = createNewEntry();


    _changedStore.push_back(returnValue);


    returnValue->clear();

    return returnValue;
}

ContainerChangeEntry *ChangeList::getNewEntry(BitVector &bv)
{
    ContainerChangeEntry *returnValue = createNewEntry();


    _changedStore.push_back(returnValue);


    new (returnValue) ContainerChangeEntry(bv);

    return returnValue;
}

ContainerChangeEntry *ChangeList::getNewCreatedEntry(void)
{

    ContainerChangeEntry *returnValue = createNewEntry();


    returnValue->clear();


    _createdStore.push_back(returnValue);

    return returnValue;
}

template<ChangeList::CommitFunction func> inline
void ChangeList::doCommitChanges(void)
{
    if(_workStore.empty() == false)
    {
        fprintf(stderr, "warning non empty workstore found\n");
    }

    _workStore.clear();

    while(_uncommitedChanges.empty() == false)
    {
        _workStore.swap(_uncommitedChanges);
        _uncommitedChanges.clear();

        ChangedStore::iterator       changesIt  = _workStore.begin();
        ChangedStore::const_iterator changesEnd = _workStore.end  ();

        while(changesIt != changesEnd)
        {
            ((*changesIt)->*func)();

            ++changesIt;
        }

        _workStore.clear();
    }
}

void ChangeList::commitChanges(void)
{
    doCommitChanges<&ContainerChangeEntry::commitChanges>();
}

void ChangeList::commitChangesAndClear(void)
{
    doCommitChanges<&ContainerChangeEntry::commitChangesAndClear>();

    clearPool();
}


void ChangeList::doApply(void)
{
#ifdef OSG_MT_FIELDCONTAINERPTR
    ChangedStoreIt      cIt  = _changedStore.begin();
    ChangedStoreConstIt cEnd = _changedStore.end  ();

#ifndef SILENT
    fprintf(stderr, "CL apply %u -> %u\n",
            _uiAspect,
            Thread::getCurrentAspect());
#endif

    FieldContainerPtr pTmp;
    BitVector syncMode = 0;

    while(cIt != cEnd)
    {
        pTmp = FieldContainerFactory::the()->getContainer(
            (*cIt)->uiContainerId);

#ifndef SILENT
        fprintf(stderr, "process changes for %d %s\n",
                        (*cIt)->uiContainerId, pTmp->getType().getCName());
#endif

        if(pTmp != NullFC)
        {
            pTmp.getAspectCPtr(_uiAspect)->setChangeEntry(NULL);

            if((*cIt)->uiEntryDesc == ContainerChangeEntry::Change)
            {
                executeSync(  pTmp,
                             _uiAspect,
                              Thread::getCurrentAspect(),
                              (*cIt)->whichField,
                              syncMode,
                              0                         );
            }
            else if((*cIt)->uiEntryDesc == ContainerChangeEntry::AddReference)
            {
#ifndef SILENT
                fprintf(stderr, "Execute add Ref for %d %s\n",
                        (*cIt)->uiContainerId, pTmp->getType().getCName());
#endif

#ifdef OSG_ASPECT_REFCOUNT
                pTmp.addAReference();
#endif
            }
            else if(
                (*cIt)->uiEntryDesc == ContainerChangeEntry::SubReference ||
                (*cIt)->uiEntryDesc == ContainerChangeEntry::DepSubReference)
            {
#ifndef SILENT
                fprintf(stderr, "Execute sub Ref for %d %s\n",
                        (*cIt)->uiContainerId, pTmp->getType().getCName());
#endif

#ifdef OSG_ASPECT_REFCOUNT
                pTmp.subAReference();
#endif
            }
        }
        ++cIt;
    }
#else
#ifdef OSG_MT_CPTR_ASPECT


    FieldContainerPtr   pSrc = NULL;
    FieldContainerPtr   pDst = NULL;

    ChangedStoreConstIt ccIt  = _createdStore.begin();
    ChangedStoreConstIt ccEnd = _createdStore.end  ();


    while(ccIt != ccEnd)
    {
        AspectStoreP pHandler =
            FieldContainerFactory::the()->getContainerHandler(
                (*ccIt)->uiContainerId);

        if(pHandler == NULL)
            continue;

        pSrc = pHandler->getPtr(_uiAspect                 );
        pDst = pHandler->getPtr(Thread::getCurrentAspect());

        if(pSrc == NULL)
            continue;

        if(pDst == NULL)
        {
            pDst = pSrc->getType().createAspectCopy((*ccIt)->uiContainerId);

            pDst->setupAspectStore(pHandler);

#ifndef SILENT_CPTR
            pHandler->dump();
#endif
        }

        ++ccIt;
    }


    ChangedStoreIt      cIt  = _changedStore.begin();
    ChangedStoreConstIt cEnd = _changedStore.end  ();

#ifndef SILENT_CPTR
    fprintf(stderr, "CL apply %u -> %u\n",
            _uiAspect,
            Thread::getCurrentAspect());
#endif

    BitVector         syncMode = 0;

    AspectOffsetStore oOffsets;

    while(cIt != cEnd)
    {
        AspectStoreP pHandler =
            FieldContainerFactory::the()->getContainerHandler(
                (*cIt)->uiContainerId);

        if(pHandler == NULL)
            continue;

        pSrc = pHandler->getPtr(_uiAspect                 );
        pDst = pHandler->getPtr(Thread::getCurrentAspect());


#ifndef SILENT_CPTR
        fprintf(stderr, "process changes for %d %p %s %p %s\n",
                (*cIt)->uiContainerId,
                pSrc,
                pSrc != NULL ? pSrc->getType().getCName() : "null",
                pDst,
                pDst != NULL ? pSrc->getType().getCName() : "null");
#endif

        if(pSrc == NULL)
            continue;

        if(pDst == NULL)
        {
            pDst = pSrc->getType().createAspectCopy((*cIt)->uiContainerId);

            pDst->setupAspectStore(pHandler);

#ifndef SILENT_CPTR
            pHandler->dump();
#endif
        }

#ifndef SILENT_CPTR
        fprintf(stderr, "Xprocess changes for %d %p %s %p %s | %d %d %p\n",
                (*cIt)->uiContainerId,
                pSrc,
                pSrc != NULL ? pSrc->getType().getCName() : "null",
                pDst,
                pDst != NULL ? pSrc->getType().getCName() : "null",
                _uiAspect,
                Thread::getCurrentAspect(),
                pHandler);
#endif

        if(pSrc != NULL)
        {
            pSrc->setChangeEntry(NULL);

#if 1
            if((*cIt)->uiEntryDesc == ContainerChangeEntry::Change)
            {
                pHandler->fillOffsetArray(oOffsets, pDst);

#ifndef SILENT_CPTR
                for(UInt32 i = 0; i < ThreadManager::getNumAspects(); ++i)
                {
                    fprintf(stderr, "offset %d %d\n", i, oOffsets[i]);
                }
#endif

               UInt32 uiSInfo =
                   /*uiSyncInfo*/ 0 |
                   (_uiAspect << 24) |
                   (Thread::getCurrentAspect() << 16);


                pDst->execSyncV(*pSrc,
                                (*cIt)->whichField,
                                oOffsets,
                                syncMode,
                                uiSInfo);


/*
                executeSync( pDst,
                            _uiAspect,
                             Thread::getCurrentAspect(),
                             oOffsets,
                             (*cIt)->whichField,
                             syncMode,
                             0);
 */

            }
            else
#endif
                if((*cIt)->uiEntryDesc == ContainerChangeEntry::AddReference)
            {
#ifndef SILENT_CPTR
                fprintf(stderr, "Execute add Ref for %d %s\n",
                        (*cIt)->uiContainerId, pDst->getType().getCName());
#endif

#ifdef OSG_ASPECT_REFCOUNT
                pDst->addReference();
#endif
            }
            else if(
                (*cIt)->uiEntryDesc == ContainerChangeEntry::SubReference ||
                (*cIt)->uiEntryDesc == ContainerChangeEntry::DepSubReference)
            {
#ifndef SILENT_CPTR
                fprintf(stderr, "Execute sub Ref for %d %s\n",
                        (*cIt)->uiContainerId, pDst->getType().getCName());
#endif

#ifdef OSG_ASPECT_REFCOUNT
                pDst->subReference();
#endif
            }
        }

        ++cIt;
    }
#endif
#endif
}

void ChangeList::doClear(void)
{
#ifdef OSG_MT_FIELDCONTAINERPTR
    ChangedStoreIt      cIt  = _changedStore.begin();
    ChangedStoreConstIt cEnd = _changedStore.end  ();

    FieldContainerPtr pTmp;

    while(cIt != cEnd)
    {
        pTmp = FieldContainerFactory::the()->getContainer(
            (*cIt)->uiContainerId);

        if(pTmp != NullFC)
        {
            pTmp.getAspectCPtr(_uiAspect)->setChangeEntry(NULL);
        }

        ++cIt;
    }
#else
#ifdef OSG_MT_CPTR_ASPECT
    ChangedStoreIt      cIt  = _changedStore.begin();
    ChangedStoreConstIt cEnd = _changedStore.end  ();

    FieldContainerPtr   pDst = NULL;

    while(cIt != cEnd)
    {
        AspectStoreP pHandler =
            FieldContainerFactory::the()->getContainerHandler(
                (*cIt)->uiContainerId);

        if(pHandler == NULL)
            continue;

        pDst = pHandler->getPtr(Thread::getCurrentAspect());

        if(pDst != NULL)
        {
            pDst->setChangeEntry(NULL);
        }

        ++cIt;
    }
#endif
#endif
}


void ChangeList::swap(ChangeList &pOther)
{
    FFATAL(("**************************************\n"
            "ChangeList::swap: Not implemented yet!\n"
            "**************************************\n"));
}

void ChangeList::merge(ChangeList &other)
{
    FFATAL(("***************************************\n"
            "ChangeList::merge: Not implemented yet!\n"
            "***************************************\n"));
}

void ChangeList::copy(ChangeList &other)
{
    FFATAL(("**************************************\n"
            "ChangeList::copy: Not implemented yet!\n"
            "**************************************\n"));
}

#ifdef OSG_1_COMPAT
void ChangeList::setReadWriteDefault(void)
{
}
#endif

/*-------------------------------------------------------------------------*/
/*                             Comparison                                  */

void ChangeList::dump(      UInt32    uiIndent,
                      const BitVector bvFlags ) const
{
    ChangedStoreConstIt cIt  = _createdStore.begin();
    ChangedStoreConstIt cEnd = _createdStore.end  ();

    fprintf(stderr, "CL created dump\n");

    while(cIt != cEnd)
    {
        for(UInt32 i = 0; i < uiIndent + 4; ++i)
        {
            fprintf(stderr, " ");
        }

        fprintf(stderr, "CE : %u %u\n",
                (*cIt)->uiEntryDesc,
                (*cIt)->uiContainerId);

        ++cIt;
    }

    cIt  = _changedStore.begin();
    cEnd = _changedStore.end  ();

    fprintf(stderr, "CL changed dump\n");

    while(cIt != cEnd)
    {
        for(UInt32 i = 0; i < uiIndent + 4; ++i)
        {
            fprintf(stderr, " ");
        }

        fprintf(stderr, "CE : %u %u 0x%016llx 0x%016llx\n",
                (*cIt)->uiEntryDesc,
                (*cIt)->uiContainerId,
                (*cIt)->uncommitedChanges,
                (*cIt)->whichField);

        ++cIt;
    }


    cIt  = _uncommitedChanges.begin();
    cEnd = _uncommitedChanges.end  ();

    fprintf(stderr, "CL uncommited dump\n");

    while(cIt != cEnd)
    {
        for(UInt32 i = 0; i < uiIndent + 4; ++i)
        {
            fprintf(stderr, " ");
        }

        fprintf(stderr, "CE : %u %u 0x%016llx 0x%016llx\n",
                (*cIt)->uiEntryDesc,
                (*cIt)->uiContainerId,
                (*cIt)->uncommitedChanges,
                (*cIt)->whichField);

        ++cIt;
    }
}


/*-------------------------------------------------------------------------*/
/*                              cvs id's                                   */

#ifdef __sgi
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 177 )
#endif

namespace
{
    static Char8 cvsid_cpp[] = "@(#)$Id$";
    static Char8 cvsid_hpp[] = OSGCHANGELIST_HEADER_CVSID;
//    static Char8 cvsid_inl[] = OSGCHANGELIST_INLINE_CVSID;
}

