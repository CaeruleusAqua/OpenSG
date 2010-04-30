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
 **     class AnimMatrixChannel!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGAnimMatrixDataSource.h"    // Data Class

#include "OSGAnimMatrixChannelBase.h"
#include "OSGAnimMatrixChannel.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::AnimMatrixChannel
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var AnimMatrixDataSource * AnimMatrixChannelBase::_sfData
    
*/

/*! \var Matrix          AnimMatrixChannelBase::_sfOutValue
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<AnimMatrixChannel *>::_type("AnimMatrixChannelPtr", "AnimChannelPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(AnimMatrixChannel *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           AnimMatrixChannel *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           AnimMatrixChannel *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void AnimMatrixChannelBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecAnimMatrixDataSourcePtr::Description(
        SFUnrecAnimMatrixDataSourcePtr::getClassType(),
        "data",
        "",
        DataFieldId, DataFieldMask,
        true,
        (Field::FClusterLocal | Field::FThreadLocal),
        static_cast<FieldEditMethodSig>(&AnimMatrixChannel::editHandleData),
        static_cast<FieldGetMethodSig >(&AnimMatrixChannel::getHandleData));

    oType.addInitialDesc(pDesc);

    pDesc = new SFMatrix::Description(
        SFMatrix::getClassType(),
        "outValue",
        "",
        OutValueFieldId, OutValueFieldMask,
        true,
        (Field::FClusterLocal | Field::FThreadLocal),
        static_cast<FieldEditMethodSig>(&AnimMatrixChannel::editHandleOutValue),
        static_cast<FieldGetMethodSig >(&AnimMatrixChannel::getHandleOutValue));

    oType.addInitialDesc(pDesc);
}


AnimMatrixChannelBase::TypeObject AnimMatrixChannelBase::_type(
    AnimMatrixChannelBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&AnimMatrixChannelBase::createEmptyLocal),
    AnimMatrixChannel::initMethod,
    AnimMatrixChannel::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&AnimMatrixChannel::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "    name=\"AnimMatrixChannel\"\n"
    "    parent=\"AnimChannel\"\n"
    "    library=\"Dynamics\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "    structure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    decoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"true\"\n"
    "    isBundle=\"false\"\n"
    "    parentFields=\"none\"\n"
    ">\n"
    "  <Field\n"
    "     name=\"data\"\n"
    "     category=\"pointer\"\n"
    "     type=\"AnimMatrixDataSource\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"internal\"\n"
    "     access=\"public\"\n"
    "     defaultValue=\"NULL\"\n"
    "     fieldFlags=\"FClusterLocal, FThreadLocal\"\n"
    "     >\n"
    "  </Field>\n"
    "  <Field\n"
    "     name=\"outValue\"\n"
    "     category=\"data\"\n"
    "     type=\"Matrix\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"internal\"\n"
    "     access=\"public\"\n"
    "     defaultValue=\"0.f, 0.f, 0.f\"\n"
    "     fieldFlags=\"FClusterLocal, FThreadLocal\"\n"
    "     >\n"
    "  </Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &AnimMatrixChannelBase::getType(void)
{
    return _type;
}

const FieldContainerType &AnimMatrixChannelBase::getType(void) const
{
    return _type;
}

UInt32 AnimMatrixChannelBase::getContainerSize(void) const
{
    return sizeof(AnimMatrixChannel);
}

/*------------------------- decorator get ------------------------------*/


//! Get the AnimMatrixChannel::_sfData field.
const SFUnrecAnimMatrixDataSourcePtr *AnimMatrixChannelBase::getSFData(void) const
{
    return &_sfData;
}

SFUnrecAnimMatrixDataSourcePtr *AnimMatrixChannelBase::editSFData           (void)
{
    editSField(DataFieldMask);

    return &_sfData;
}

SFMatrix *AnimMatrixChannelBase::editSFOutValue(void)
{
    editSField(OutValueFieldMask);

    return &_sfOutValue;
}

const SFMatrix *AnimMatrixChannelBase::getSFOutValue(void) const
{
    return &_sfOutValue;
}






/*------------------------------ access -----------------------------------*/

UInt32 AnimMatrixChannelBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (DataFieldMask & whichField))
    {
        returnValue += _sfData.getBinSize();
    }
    if(FieldBits::NoField != (OutValueFieldMask & whichField))
    {
        returnValue += _sfOutValue.getBinSize();
    }

    return returnValue;
}

void AnimMatrixChannelBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (DataFieldMask & whichField))
    {
        _sfData.copyToBin(pMem);
    }
    if(FieldBits::NoField != (OutValueFieldMask & whichField))
    {
        _sfOutValue.copyToBin(pMem);
    }
}

void AnimMatrixChannelBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (DataFieldMask & whichField))
    {
        editSField(DataFieldMask);
        _sfData.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (OutValueFieldMask & whichField))
    {
        editSField(OutValueFieldMask);
        _sfOutValue.copyFromBin(pMem);
    }
}

//! create a new instance of the class
AnimMatrixChannelTransitPtr AnimMatrixChannelBase::createLocal(BitVector bFlags)
{
    AnimMatrixChannelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<AnimMatrixChannel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
AnimMatrixChannelTransitPtr AnimMatrixChannelBase::createDependent(BitVector bFlags)
{
    AnimMatrixChannelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<AnimMatrixChannel>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
AnimMatrixChannelTransitPtr AnimMatrixChannelBase::create(void)
{
    AnimMatrixChannelTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<AnimMatrixChannel>(tmpPtr);
    }

    return fc;
}

AnimMatrixChannel *AnimMatrixChannelBase::createEmptyLocal(BitVector bFlags)
{
    AnimMatrixChannel *returnValue;

    newPtr<AnimMatrixChannel>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
AnimMatrixChannel *AnimMatrixChannelBase::createEmpty(void)
{
    AnimMatrixChannel *returnValue;

    newPtr<AnimMatrixChannel>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr AnimMatrixChannelBase::shallowCopyLocal(
    BitVector bFlags) const
{
    AnimMatrixChannel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const AnimMatrixChannel *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr AnimMatrixChannelBase::shallowCopyDependent(
    BitVector bFlags) const
{
    AnimMatrixChannel *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const AnimMatrixChannel *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr AnimMatrixChannelBase::shallowCopy(void) const
{
    AnimMatrixChannel *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const AnimMatrixChannel *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

AnimMatrixChannelBase::AnimMatrixChannelBase(void) :
    Inherited(),
    _sfData                   (NULL),
    _sfOutValue               (Matrix(0.f, 0.f, 0.f))
{
}

AnimMatrixChannelBase::AnimMatrixChannelBase(const AnimMatrixChannelBase &source) :
    Inherited(source),
    _sfData                   (NULL),
    _sfOutValue               (source._sfOutValue               )
{
}


/*-------------------------- destructors ----------------------------------*/

AnimMatrixChannelBase::~AnimMatrixChannelBase(void)
{
}

void AnimMatrixChannelBase::onCreate(const AnimMatrixChannel *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        AnimMatrixChannel *pThis = static_cast<AnimMatrixChannel *>(this);

        pThis->setData(source->getData());
    }
}

GetFieldHandlePtr AnimMatrixChannelBase::getHandleData            (void) const
{
    SFUnrecAnimMatrixDataSourcePtr::GetHandlePtr returnValue(
        new  SFUnrecAnimMatrixDataSourcePtr::GetHandle(
             &_sfData,
             this->getType().getFieldDesc(DataFieldId),
             const_cast<AnimMatrixChannelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr AnimMatrixChannelBase::editHandleData           (void)
{
    SFUnrecAnimMatrixDataSourcePtr::EditHandlePtr returnValue(
        new  SFUnrecAnimMatrixDataSourcePtr::EditHandle(
             &_sfData,
             this->getType().getFieldDesc(DataFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&AnimMatrixChannel::setData,
                    static_cast<AnimMatrixChannel *>(this), _1));

    editSField(DataFieldMask);

    return returnValue;
}

GetFieldHandlePtr AnimMatrixChannelBase::getHandleOutValue        (void) const
{
    SFMatrix::GetHandlePtr returnValue(
        new  SFMatrix::GetHandle(
             &_sfOutValue,
             this->getType().getFieldDesc(OutValueFieldId),
             const_cast<AnimMatrixChannelBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr AnimMatrixChannelBase::editHandleOutValue       (void)
{
    SFMatrix::EditHandlePtr returnValue(
        new  SFMatrix::EditHandle(
             &_sfOutValue,
             this->getType().getFieldDesc(OutValueFieldId),
             this));


    editSField(OutValueFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void AnimMatrixChannelBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    AnimMatrixChannel *pThis = static_cast<AnimMatrixChannel *>(this);

    pThis->execSync(static_cast<AnimMatrixChannel *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *AnimMatrixChannelBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    AnimMatrixChannel *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const AnimMatrixChannel *>(pRefAspect),
                  dynamic_cast<const AnimMatrixChannel *>(this));

    return returnValue;
}
#endif

void AnimMatrixChannelBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<AnimMatrixChannel *>(this)->setData(NULL);


}


OSG_END_NAMESPACE
