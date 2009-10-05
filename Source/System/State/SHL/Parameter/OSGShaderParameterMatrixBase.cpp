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
 **     class ShaderParameterMatrix!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGShaderParameterMatrixBase.h"
#include "OSGShaderParameterMatrix.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::ShaderParameterMatrix
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Matrix          ShaderParameterMatrixBase::_sfValue
    parameter value
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<ShaderParameterMatrix *>::_type("ShaderParameterMatrixPtr", "ShaderParameterPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(ShaderParameterMatrix *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           ShaderParameterMatrix *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           ShaderParameterMatrix *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void ShaderParameterMatrixBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFMatrix::Description(
        SFMatrix::getClassType(),
        "value",
        "parameter value\n",
        ValueFieldId, ValueFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ShaderParameterMatrix::editHandleValue),
        static_cast<FieldGetMethodSig >(&ShaderParameterMatrix::getHandleValue));

    oType.addInitialDesc(pDesc);
}


ShaderParameterMatrixBase::TypeObject ShaderParameterMatrixBase::_type(
    ShaderParameterMatrixBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&ShaderParameterMatrixBase::createEmptyLocal),
    ShaderParameterMatrix::initMethod,
    ShaderParameterMatrix::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&ShaderParameterMatrix::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"ShaderParameterMatrix\"\n"
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
    "\t\ttype=\"Matrix\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\tparameter value\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &ShaderParameterMatrixBase::getType(void)
{
    return _type;
}

const FieldContainerType &ShaderParameterMatrixBase::getType(void) const
{
    return _type;
}

UInt32 ShaderParameterMatrixBase::getContainerSize(void) const
{
    return sizeof(ShaderParameterMatrix);
}

/*------------------------- decorator get ------------------------------*/


SFMatrix *ShaderParameterMatrixBase::editSFValue(void)
{
    editSField(ValueFieldMask);

    return &_sfValue;
}

const SFMatrix *ShaderParameterMatrixBase::getSFValue(void) const
{
    return &_sfValue;
}






/*------------------------------ access -----------------------------------*/

UInt32 ShaderParameterMatrixBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        returnValue += _sfValue.getBinSize();
    }

    return returnValue;
}

void ShaderParameterMatrixBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        _sfValue.copyToBin(pMem);
    }
}

void ShaderParameterMatrixBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        _sfValue.copyFromBin(pMem);
    }
}

//! create a new instance of the class
ShaderParameterMatrixTransitPtr ShaderParameterMatrixBase::createLocal(BitVector bFlags)
{
    ShaderParameterMatrixTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<ShaderParameterMatrix>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
ShaderParameterMatrixTransitPtr ShaderParameterMatrixBase::createDependent(BitVector bFlags)
{
    ShaderParameterMatrixTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<ShaderParameterMatrix>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
ShaderParameterMatrixTransitPtr ShaderParameterMatrixBase::create(void)
{
    ShaderParameterMatrixTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<ShaderParameterMatrix>(tmpPtr);
    }

    return fc;
}

ShaderParameterMatrix *ShaderParameterMatrixBase::createEmptyLocal(BitVector bFlags)
{
    ShaderParameterMatrix *returnValue;

    newPtr<ShaderParameterMatrix>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
ShaderParameterMatrix *ShaderParameterMatrixBase::createEmpty(void)
{
    ShaderParameterMatrix *returnValue;

    newPtr<ShaderParameterMatrix>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr ShaderParameterMatrixBase::shallowCopyLocal(
    BitVector bFlags) const
{
    ShaderParameterMatrix *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ShaderParameterMatrix *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr ShaderParameterMatrixBase::shallowCopyDependent(
    BitVector bFlags) const
{
    ShaderParameterMatrix *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ShaderParameterMatrix *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr ShaderParameterMatrixBase::shallowCopy(void) const
{
    ShaderParameterMatrix *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const ShaderParameterMatrix *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

ShaderParameterMatrixBase::ShaderParameterMatrixBase(void) :
    Inherited(),
    _sfValue                  ()
{
}

ShaderParameterMatrixBase::ShaderParameterMatrixBase(const ShaderParameterMatrixBase &source) :
    Inherited(source),
    _sfValue                  (source._sfValue                  )
{
}


/*-------------------------- destructors ----------------------------------*/

ShaderParameterMatrixBase::~ShaderParameterMatrixBase(void)
{
}


GetFieldHandlePtr ShaderParameterMatrixBase::getHandleValue           (void) const
{
    SFMatrix::GetHandlePtr returnValue(
        new  SFMatrix::GetHandle(
             &_sfValue,
             this->getType().getFieldDesc(ValueFieldId),
             const_cast<ShaderParameterMatrixBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ShaderParameterMatrixBase::editHandleValue          (void)
{
    SFMatrix::EditHandlePtr returnValue(
        new  SFMatrix::EditHandle(
             &_sfValue,
             this->getType().getFieldDesc(ValueFieldId),
             this));


    editSField(ValueFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void ShaderParameterMatrixBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    ShaderParameterMatrix *pThis = static_cast<ShaderParameterMatrix *>(this);

    pThis->execSync(static_cast<ShaderParameterMatrix *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *ShaderParameterMatrixBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    ShaderParameterMatrix *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const ShaderParameterMatrix *>(pRefAspect),
                  dynamic_cast<const ShaderParameterMatrix *>(this));

    return returnValue;
}
#endif

void ShaderParameterMatrixBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
