/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
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

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 **     Do not change this file, changes should be done in the derived      **
 **     class AnimTemplate!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OSGConfig.h>



#include "OSGAnimDataSource.h"          // Sources Class

#include "OSGAnimTemplateBase.h"
#include "OSGAnimTemplate.h"

#include "boost/bind.hpp"

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::AnimTemplate
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var AnimDataSource * AnimTemplateBase::_mfSources
    
*/

/*! \var string          AnimTemplateBase::_mfTargetIds
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<AnimTemplate *>::_type("AnimTemplatePtr", "AttachmentContainerPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(AnimTemplate *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           AnimTemplate *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           AnimTemplate *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void AnimTemplateBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new MFUnrecAnimDataSourcePtr::Description(
        MFUnrecAnimDataSourcePtr::getClassType(),
        "sources",
        "",
        SourcesFieldId, SourcesFieldMask,
        false,
        (Field::FThreadLocal),
        static_cast<FieldEditMethodSig>(&AnimTemplate::editHandleSources),
        static_cast<FieldGetMethodSig >(&AnimTemplate::getHandleSources));

    oType.addInitialDesc(pDesc);

    pDesc = new MFString::Description(
        MFString::getClassType(),
        "targetIds",
        "",
        TargetIdsFieldId, TargetIdsFieldMask,
        false,
        (Field::FThreadLocal),
        static_cast<FieldEditMethodSig>(&AnimTemplate::editHandleTargetIds),
        static_cast<FieldGetMethodSig >(&AnimTemplate::getHandleTargetIds));

    oType.addInitialDesc(pDesc);
}


AnimTemplateBase::TypeObject AnimTemplateBase::_type(
    AnimTemplateBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    NULL,
    AnimTemplate::initMethod,
    AnimTemplate::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&AnimTemplate::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "   name=\"AnimTemplate\"\n"
    "   parent=\"AttachmentContainer\"\n"
    "   library=\"Dynamics\"\n"
    "   pointerfieldtypes=\"both\"\n"
    "   structure=\"abstract\"\n"
    "   systemcomponent=\"true\"\n"
    "   parentsystemcomponent=\"true\"\n"
    "   decoratable=\"false\"\n"
    "   useLocalIncludes=\"false\"\n"
    "   isNodeCore=\"true\"\n"
    "   isBundle=\"false\"\n"
    "   parentFields=\"none\"\n"
    "   >\n"
    "  <Field\n"
    "     name=\"sources\"\n"
    "     category=\"pointer\"\n"
    "     type=\"AnimDataSource\"\n"
    "     cardinality=\"multi\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     fieldFlags=\"FThreadLocal\"\n"
    "     >\n"
    "    </Field>\n"
    "  <Field\n"
    "     name=\"targetIds\"\n"
    "     category=\"data\"\n"
    "     type=\"string\"\n"
    "     cardinality=\"multi\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     fieldFlags=\"FThreadLocal\"\n"
    "     >\n"
    "  </Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &AnimTemplateBase::getType(void)
{
    return _type;
}

const FieldContainerType &AnimTemplateBase::getType(void) const
{
    return _type;
}

UInt32 AnimTemplateBase::getContainerSize(void) const
{
    return sizeof(AnimTemplate);
}

/*------------------------- decorator get ------------------------------*/


//! Get the AnimTemplate::_mfSources field.
const MFUnrecAnimDataSourcePtr *AnimTemplateBase::getMFSources(void) const
{
    return &_mfSources;
}

MFUnrecAnimDataSourcePtr *AnimTemplateBase::editMFSources        (void)
{
    editMField(SourcesFieldMask, _mfSources);

    return &_mfSources;
}

MFString *AnimTemplateBase::editMFTargetIds(void)
{
    editMField(TargetIdsFieldMask, _mfTargetIds);

    return &_mfTargetIds;
}

const MFString *AnimTemplateBase::getMFTargetIds(void) const
{
    return &_mfTargetIds;
}




void AnimTemplateBase::pushToSources(AnimDataSource * const value)
{
    editMField(SourcesFieldMask, _mfSources);

    _mfSources.push_back(value);
}

void AnimTemplateBase::assignSources  (const MFUnrecAnimDataSourcePtr &value)
{
    MFUnrecAnimDataSourcePtr::const_iterator elemIt  =
        value.begin();
    MFUnrecAnimDataSourcePtr::const_iterator elemEnd =
        value.end  ();

    static_cast<AnimTemplate *>(this)->clearSources();

    while(elemIt != elemEnd)
    {
        this->pushToSources(*elemIt);

        ++elemIt;
    }
}

void AnimTemplateBase::removeFromSources(UInt32 uiIndex)
{
    if(uiIndex < _mfSources.size())
    {
        editMField(SourcesFieldMask, _mfSources);

        _mfSources.erase(uiIndex);
    }
}

void AnimTemplateBase::removeObjFromSources(AnimDataSource * const value)
{
    Int32 iElemIdx = _mfSources.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(SourcesFieldMask, _mfSources);

        _mfSources.erase(iElemIdx);
    }
}
void AnimTemplateBase::clearSources(void)
{
    editMField(SourcesFieldMask, _mfSources);


    _mfSources.clear();
}



/*------------------------------ access -----------------------------------*/

UInt32 AnimTemplateBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (SourcesFieldMask & whichField))
    {
        returnValue += _mfSources.getBinSize();
    }
    if(FieldBits::NoField != (TargetIdsFieldMask & whichField))
    {
        returnValue += _mfTargetIds.getBinSize();
    }

    return returnValue;
}

void AnimTemplateBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (SourcesFieldMask & whichField))
    {
        _mfSources.copyToBin(pMem);
    }
    if(FieldBits::NoField != (TargetIdsFieldMask & whichField))
    {
        _mfTargetIds.copyToBin(pMem);
    }
}

void AnimTemplateBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (SourcesFieldMask & whichField))
    {
        _mfSources.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (TargetIdsFieldMask & whichField))
    {
        _mfTargetIds.copyFromBin(pMem);
    }
}




/*------------------------- constructors ----------------------------------*/

AnimTemplateBase::AnimTemplateBase(void) :
    Inherited(),
    _mfSources                (),
    _mfTargetIds              ()
{
}

AnimTemplateBase::AnimTemplateBase(const AnimTemplateBase &source) :
    Inherited(source),
    _mfSources                (),
    _mfTargetIds              (source._mfTargetIds              )
{
}


/*-------------------------- destructors ----------------------------------*/

AnimTemplateBase::~AnimTemplateBase(void)
{
}

void AnimTemplateBase::onCreate(const AnimTemplate *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        AnimTemplate *pThis = static_cast<AnimTemplate *>(this);

        MFUnrecAnimDataSourcePtr::const_iterator SourcesIt  =
            source->_mfSources.begin();
        MFUnrecAnimDataSourcePtr::const_iterator SourcesEnd =
            source->_mfSources.end  ();

        while(SourcesIt != SourcesEnd)
        {
            pThis->pushToSources(*SourcesIt);

            ++SourcesIt;
        }
    }
}

GetFieldHandlePtr AnimTemplateBase::getHandleSources         (void) const
{
    MFUnrecAnimDataSourcePtr::GetHandlePtr returnValue(
        new  MFUnrecAnimDataSourcePtr::GetHandle(
             &_mfSources,
             this->getType().getFieldDesc(SourcesFieldId),
             const_cast<AnimTemplateBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr AnimTemplateBase::editHandleSources        (void)
{
    MFUnrecAnimDataSourcePtr::EditHandlePtr returnValue(
        new  MFUnrecAnimDataSourcePtr::EditHandle(
             &_mfSources,
             this->getType().getFieldDesc(SourcesFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&AnimTemplate::pushToSources,
                    static_cast<AnimTemplate *>(this), _1));
    returnValue->setRemoveMethod(
        boost::bind(&AnimTemplate::removeFromSources,
                    static_cast<AnimTemplate *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&AnimTemplate::removeObjFromSources,
                    static_cast<AnimTemplate *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&AnimTemplate::clearSources,
                    static_cast<AnimTemplate *>(this)));

    editMField(SourcesFieldMask, _mfSources);

    return returnValue;
}

GetFieldHandlePtr AnimTemplateBase::getHandleTargetIds       (void) const
{
    MFString::GetHandlePtr returnValue(
        new  MFString::GetHandle(
             &_mfTargetIds,
             this->getType().getFieldDesc(TargetIdsFieldId),
             const_cast<AnimTemplateBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr AnimTemplateBase::editHandleTargetIds      (void)
{
    MFString::EditHandlePtr returnValue(
        new  MFString::EditHandle(
             &_mfTargetIds,
             this->getType().getFieldDesc(TargetIdsFieldId),
             this));


    editMField(TargetIdsFieldMask, _mfTargetIds);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void AnimTemplateBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    AnimTemplate *pThis = static_cast<AnimTemplate *>(this);

    pThis->execSync(static_cast<AnimTemplate *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif



void AnimTemplateBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<AnimTemplate *>(this)->clearSources();

#ifdef OSG_MT_CPTR_ASPECT
    AspectOffsetStore oOffsets;

    _pAspectStore->fillOffsetArray(oOffsets, this);
#endif

#ifdef OSG_MT_CPTR_ASPECT
    _mfTargetIds.terminateShare(Thread::getCurrentAspect(),
                                      oOffsets);
#endif
}


OSG_END_NAMESPACE
