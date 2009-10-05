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
 **     class ShaderParameterMInt!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGShaderParameterMIntBase.h"
#include "OSGShaderParameterMInt.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::ShaderParameterMInt
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Int32           ShaderParameterMIntBase::_mfValue
    parameter value
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<ShaderParameterMInt *>::_type("ShaderParameterMIntPtr", "ShaderParameterPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(ShaderParameterMInt *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           ShaderParameterMInt *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           ShaderParameterMInt *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void ShaderParameterMIntBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new MFInt32::Description(
        MFInt32::getClassType(),
        "value",
        "parameter value\n",
        ValueFieldId, ValueFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ShaderParameterMInt::editHandleValue),
        static_cast<FieldGetMethodSig >(&ShaderParameterMInt::getHandleValue));

    oType.addInitialDesc(pDesc);
}


ShaderParameterMIntBase::TypeObject ShaderParameterMIntBase::_type(
    ShaderParameterMIntBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&ShaderParameterMIntBase::createEmptyLocal),
    ShaderParameterMInt::initMethod,
    ShaderParameterMInt::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&ShaderParameterMInt::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"ShaderParameterMInt\"\n"
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
    "\t\ttype=\"Int32\"\n"
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

FieldContainerType &ShaderParameterMIntBase::getType(void)
{
    return _type;
}

const FieldContainerType &ShaderParameterMIntBase::getType(void) const
{
    return _type;
}

UInt32 ShaderParameterMIntBase::getContainerSize(void) const
{
    return sizeof(ShaderParameterMInt);
}

/*------------------------- decorator get ------------------------------*/


MFInt32 *ShaderParameterMIntBase::editMFValue(void)
{
    editMField(ValueFieldMask, _mfValue);

    return &_mfValue;
}

const MFInt32 *ShaderParameterMIntBase::getMFValue(void) const
{
    return &_mfValue;
}






/*------------------------------ access -----------------------------------*/

UInt32 ShaderParameterMIntBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        returnValue += _mfValue.getBinSize();
    }

    return returnValue;
}

void ShaderParameterMIntBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        _mfValue.copyToBin(pMem);
    }
}

void ShaderParameterMIntBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        _mfValue.copyFromBin(pMem);
    }
}

//! create a new instance of the class
ShaderParameterMIntTransitPtr ShaderParameterMIntBase::createLocal(BitVector bFlags)
{
    ShaderParameterMIntTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<ShaderParameterMInt>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
ShaderParameterMIntTransitPtr ShaderParameterMIntBase::createDependent(BitVector bFlags)
{
    ShaderParameterMIntTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<ShaderParameterMInt>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
ShaderParameterMIntTransitPtr ShaderParameterMIntBase::create(void)
{
    ShaderParameterMIntTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<ShaderParameterMInt>(tmpPtr);
    }

    return fc;
}

ShaderParameterMInt *ShaderParameterMIntBase::createEmptyLocal(BitVector bFlags)
{
    ShaderParameterMInt *returnValue;

    newPtr<ShaderParameterMInt>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
ShaderParameterMInt *ShaderParameterMIntBase::createEmpty(void)
{
    ShaderParameterMInt *returnValue;

    newPtr<ShaderParameterMInt>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr ShaderParameterMIntBase::shallowCopyLocal(
    BitVector bFlags) const
{
    ShaderParameterMInt *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ShaderParameterMInt *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr ShaderParameterMIntBase::shallowCopyDependent(
    BitVector bFlags) const
{
    ShaderParameterMInt *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ShaderParameterMInt *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr ShaderParameterMIntBase::shallowCopy(void) const
{
    ShaderParameterMInt *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const ShaderParameterMInt *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

ShaderParameterMIntBase::ShaderParameterMIntBase(void) :
    Inherited(),
    _mfValue                  ()
{
}

ShaderParameterMIntBase::ShaderParameterMIntBase(const ShaderParameterMIntBase &source) :
    Inherited(source),
    _mfValue                  (source._mfValue                  )
{
}


/*-------------------------- destructors ----------------------------------*/

ShaderParameterMIntBase::~ShaderParameterMIntBase(void)
{
}


GetFieldHandlePtr ShaderParameterMIntBase::getHandleValue           (void) const
{
    MFInt32::GetHandlePtr returnValue(
        new  MFInt32::GetHandle(
             &_mfValue,
             this->getType().getFieldDesc(ValueFieldId),
             const_cast<ShaderParameterMIntBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ShaderParameterMIntBase::editHandleValue          (void)
{
    MFInt32::EditHandlePtr returnValue(
        new  MFInt32::EditHandle(
             &_mfValue,
             this->getType().getFieldDesc(ValueFieldId),
             this));


    editMField(ValueFieldMask, _mfValue);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void ShaderParameterMIntBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    ShaderParameterMInt *pThis = static_cast<ShaderParameterMInt *>(this);

    pThis->execSync(static_cast<ShaderParameterMInt *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *ShaderParameterMIntBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    ShaderParameterMInt *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const ShaderParameterMInt *>(pRefAspect),
                  dynamic_cast<const ShaderParameterMInt *>(this));

    return returnValue;
}
#endif

void ShaderParameterMIntBase::resolveLinks(void)
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
