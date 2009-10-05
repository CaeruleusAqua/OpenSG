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
 **     class ShaderParameterMVec3f!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGShaderParameterMVec3fBase.h"
#include "OSGShaderParameterMVec3f.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::ShaderParameterMVec3f
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Vec3f           ShaderParameterMVec3fBase::_mfValue
    parameter value
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<ShaderParameterMVec3f *>::_type("ShaderParameterMVec3fPtr", "ShaderParameterPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(ShaderParameterMVec3f *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           ShaderParameterMVec3f *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           ShaderParameterMVec3f *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void ShaderParameterMVec3fBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new MFVec3f::Description(
        MFVec3f::getClassType(),
        "value",
        "parameter value\n",
        ValueFieldId, ValueFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ShaderParameterMVec3f::editHandleValue),
        static_cast<FieldGetMethodSig >(&ShaderParameterMVec3f::getHandleValue));

    oType.addInitialDesc(pDesc);
}


ShaderParameterMVec3fBase::TypeObject ShaderParameterMVec3fBase::_type(
    ShaderParameterMVec3fBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&ShaderParameterMVec3fBase::createEmptyLocal),
    ShaderParameterMVec3f::initMethod,
    ShaderParameterMVec3f::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&ShaderParameterMVec3f::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"ShaderParameterMVec3f\"\n"
    "\tparent=\"ShaderParameter\"\n"
    "\tlibrary=\"State\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "\tuseLocalIncludes=\"false\"\n"
    ">\n"
    "\t<Field\n"
    "\t\tname=\"value\"\n"
    "\t\ttype=\"Vec3f\"\n"
    "\t\tcardinality=\"multi\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\tparameter value\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &ShaderParameterMVec3fBase::getType(void)
{
    return _type;
}

const FieldContainerType &ShaderParameterMVec3fBase::getType(void) const
{
    return _type;
}

UInt32 ShaderParameterMVec3fBase::getContainerSize(void) const
{
    return sizeof(ShaderParameterMVec3f);
}

/*------------------------- decorator get ------------------------------*/


MFVec3f *ShaderParameterMVec3fBase::editMFValue(void)
{
    editMField(ValueFieldMask, _mfValue);

    return &_mfValue;
}

const MFVec3f *ShaderParameterMVec3fBase::getMFValue(void) const
{
    return &_mfValue;
}






/*------------------------------ access -----------------------------------*/

UInt32 ShaderParameterMVec3fBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        returnValue += _mfValue.getBinSize();
    }

    return returnValue;
}

void ShaderParameterMVec3fBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        _mfValue.copyToBin(pMem);
    }
}

void ShaderParameterMVec3fBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        _mfValue.copyFromBin(pMem);
    }
}

//! create a new instance of the class
ShaderParameterMVec3fTransitPtr ShaderParameterMVec3fBase::createLocal(BitVector bFlags)
{
    ShaderParameterMVec3fTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<ShaderParameterMVec3f>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
ShaderParameterMVec3fTransitPtr ShaderParameterMVec3fBase::createDependent(BitVector bFlags)
{
    ShaderParameterMVec3fTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<ShaderParameterMVec3f>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
ShaderParameterMVec3fTransitPtr ShaderParameterMVec3fBase::create(void)
{
    ShaderParameterMVec3fTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<ShaderParameterMVec3f>(tmpPtr);
    }

    return fc;
}

ShaderParameterMVec3f *ShaderParameterMVec3fBase::createEmptyLocal(BitVector bFlags)
{
    ShaderParameterMVec3f *returnValue;

    newPtr<ShaderParameterMVec3f>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
ShaderParameterMVec3f *ShaderParameterMVec3fBase::createEmpty(void)
{
    ShaderParameterMVec3f *returnValue;

    newPtr<ShaderParameterMVec3f>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr ShaderParameterMVec3fBase::shallowCopyLocal(
    BitVector bFlags) const
{
    ShaderParameterMVec3f *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ShaderParameterMVec3f *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr ShaderParameterMVec3fBase::shallowCopyDependent(
    BitVector bFlags) const
{
    ShaderParameterMVec3f *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ShaderParameterMVec3f *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr ShaderParameterMVec3fBase::shallowCopy(void) const
{
    ShaderParameterMVec3f *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const ShaderParameterMVec3f *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

ShaderParameterMVec3fBase::ShaderParameterMVec3fBase(void) :
    Inherited(),
    _mfValue                  ()
{
}

ShaderParameterMVec3fBase::ShaderParameterMVec3fBase(const ShaderParameterMVec3fBase &source) :
    Inherited(source),
    _mfValue                  (source._mfValue                  )
{
}


/*-------------------------- destructors ----------------------------------*/

ShaderParameterMVec3fBase::~ShaderParameterMVec3fBase(void)
{
}


GetFieldHandlePtr ShaderParameterMVec3fBase::getHandleValue           (void) const
{
    MFVec3f::GetHandlePtr returnValue(
        new  MFVec3f::GetHandle(
             &_mfValue,
             this->getType().getFieldDesc(ValueFieldId),
             const_cast<ShaderParameterMVec3fBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ShaderParameterMVec3fBase::editHandleValue          (void)
{
    MFVec3f::EditHandlePtr returnValue(
        new  MFVec3f::EditHandle(
             &_mfValue,
             this->getType().getFieldDesc(ValueFieldId),
             this));


    editMField(ValueFieldMask, _mfValue);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void ShaderParameterMVec3fBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    ShaderParameterMVec3f *pThis = static_cast<ShaderParameterMVec3f *>(this);

    pThis->execSync(static_cast<ShaderParameterMVec3f *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *ShaderParameterMVec3fBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    ShaderParameterMVec3f *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const ShaderParameterMVec3f *>(pRefAspect),
                  dynamic_cast<const ShaderParameterMVec3f *>(this));

    return returnValue;
}
#endif

void ShaderParameterMVec3fBase::resolveLinks(void)
{
    Inherited::resolveLinks();

#ifdef OSG_MT_CPTR_ASPECT
    AspectOffsetStore oOffsets;

    _pAspectStore->fillOffsetArray(oOffsets, this);
#endif

#ifdef OSG_MT_CPTR_ASPECT
    _mfValue.terminateShare(Thread::getCurrentAspect(),
                                      oOffsets);
#endif
}


OSG_END_NAMESPACE
