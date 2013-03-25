/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2013 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: dirk@opensg.org, gerrit.voss@vossg.org, carsten_neumann@gmx.net  *
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
 **     class VariantMaterial!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"



#include "OSGPrimeMaterial.h"           // FallbackMaterial Class

#include "OSGVariantMaterialBase.h"
#include "OSGVariantMaterial.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::VariantMaterial
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var PrimeMaterial * VariantMaterialBase::_sfFallbackMaterial
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
PointerType FieldTraits<VariantMaterial *, nsOSG>::_type(
    "VariantMaterialPtr", 
    "CompositeMaterialPtr", 
    VariantMaterial::getClassType(),
    nsOSG);
#endif

OSG_FIELDTRAITS_GETTYPE_NS(VariantMaterial *, nsOSG)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           VariantMaterial *,
                           nsOSG);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           VariantMaterial *,
                           nsOSG);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void VariantMaterialBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecPrimeMaterialPtr::Description(
        SFUnrecPrimeMaterialPtr::getClassType(),
        "fallbackMaterial",
        "",
        FallbackMaterialFieldId, FallbackMaterialFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&VariantMaterial::editHandleFallbackMaterial),
        static_cast<FieldGetMethodSig >(&VariantMaterial::getHandleFallbackMaterial));

    oType.addInitialDesc(pDesc);
}


VariantMaterialBase::TypeObject VariantMaterialBase::_type(
    VariantMaterialBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    nsOSG, //Namespace
    reinterpret_cast<PrototypeCreateF>(&VariantMaterialBase::createEmptyLocal),
    VariantMaterial::initMethod,
    VariantMaterial::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&VariantMaterial::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "   name=\"VariantMaterial\"\n"
    "   parent=\"CompositeMaterial\"\n"
    "   library=\"System\"\n"
    "   structure=\"concrete\"\n"
    "   pointerfieldtypes=\"both\"\n"
    "   systemcomponent=\"true\"\n"
    "   parentsystemcomponent=\"true\"\n"
    "   docGroupBase=\"GrpSystemMaterial\"\n"
    "   >\n"
    "  <Field\n"
    "\t name=\"fallbackMaterial\"\n"
    "\t type=\"PrimeMaterialPtr\"\n"
    "\t cardinality=\"single\"\n"
    "\t visibility=\"external\"\n"
    "\t access=\"public\"\n"
    "\t >\n"
    "  </Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &VariantMaterialBase::getType(void)
{
    return _type;
}

const FieldContainerType &VariantMaterialBase::getType(void) const
{
    return _type;
}

UInt32 VariantMaterialBase::getContainerSize(void) const
{
    return sizeof(VariantMaterial);
}

/*------------------------- decorator get ------------------------------*/


//! Get the VariantMaterial::_sfFallbackMaterial field.
const SFUnrecPrimeMaterialPtr *VariantMaterialBase::getSFFallbackMaterial(void) const
{
    return &_sfFallbackMaterial;
}

SFUnrecPrimeMaterialPtr *VariantMaterialBase::editSFFallbackMaterial(void)
{
    editSField(FallbackMaterialFieldMask);

    return &_sfFallbackMaterial;
}

//! Get the value of the VariantMaterial::_sfFallbackMaterial field.
PrimeMaterial * VariantMaterialBase::getFallbackMaterial(void) const
{
    return _sfFallbackMaterial.getValue();
}

//! Set the value of the VariantMaterial::_sfFallbackMaterial field.
void VariantMaterialBase::setFallbackMaterial(PrimeMaterial * const value)
{
    editSField(FallbackMaterialFieldMask);

    _sfFallbackMaterial.setValue(value);
}






/*------------------------------ access -----------------------------------*/

SizeT VariantMaterialBase::getBinSize(ConstFieldMaskArg whichField)
{
    SizeT returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (FallbackMaterialFieldMask & whichField))
    {
        returnValue += _sfFallbackMaterial.getBinSize();
    }

    return returnValue;
}

void VariantMaterialBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (FallbackMaterialFieldMask & whichField))
    {
        _sfFallbackMaterial.copyToBin(pMem);
    }
}

void VariantMaterialBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (FallbackMaterialFieldMask & whichField))
    {
        editSField(FallbackMaterialFieldMask);
        _sfFallbackMaterial.copyFromBin(pMem);
    }
}

//! create a new instance of the class
VariantMaterialTransitPtr VariantMaterialBase::createLocal(BitVector bFlags)
{
    VariantMaterialTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<VariantMaterial>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
VariantMaterialTransitPtr VariantMaterialBase::createDependent(BitVector bFlags)
{
    VariantMaterialTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<VariantMaterial>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
VariantMaterialTransitPtr VariantMaterialBase::create(void)
{
    VariantMaterialTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<VariantMaterial>(tmpPtr);
    }

    return fc;
}

VariantMaterial *VariantMaterialBase::createEmptyLocal(BitVector bFlags)
{
    VariantMaterial *returnValue;

    newPtr<VariantMaterial>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
VariantMaterial *VariantMaterialBase::createEmpty(void)
{
    VariantMaterial *returnValue;

    newPtr<VariantMaterial>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr VariantMaterialBase::shallowCopyLocal(
    BitVector bFlags) const
{
    VariantMaterial *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const VariantMaterial *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr VariantMaterialBase::shallowCopyDependent(
    BitVector bFlags) const
{
    VariantMaterial *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const VariantMaterial *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr VariantMaterialBase::shallowCopy(void) const
{
    VariantMaterial *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const VariantMaterial *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

VariantMaterialBase::VariantMaterialBase(void) :
    Inherited(),
    _sfFallbackMaterial       (NULL)
{
}

VariantMaterialBase::VariantMaterialBase(const VariantMaterialBase &source) :
    Inherited(source),
    _sfFallbackMaterial       (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

VariantMaterialBase::~VariantMaterialBase(void)
{
}

void VariantMaterialBase::onCreate(const VariantMaterial *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        VariantMaterial *pThis = static_cast<VariantMaterial *>(this);

        pThis->setFallbackMaterial(source->getFallbackMaterial());
    }
}

GetFieldHandlePtr VariantMaterialBase::getHandleFallbackMaterial (void) const
{
    SFUnrecPrimeMaterialPtr::GetHandlePtr returnValue(
        new  SFUnrecPrimeMaterialPtr::GetHandle(
             &_sfFallbackMaterial,
             this->getType().getFieldDesc(FallbackMaterialFieldId),
             const_cast<VariantMaterialBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr VariantMaterialBase::editHandleFallbackMaterial(void)
{
    SFUnrecPrimeMaterialPtr::EditHandlePtr returnValue(
        new  SFUnrecPrimeMaterialPtr::EditHandle(
             &_sfFallbackMaterial,
             this->getType().getFieldDesc(FallbackMaterialFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&VariantMaterial::setFallbackMaterial,
                    static_cast<VariantMaterial *>(this), _1));

    editSField(FallbackMaterialFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void VariantMaterialBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    VariantMaterial *pThis = static_cast<VariantMaterial *>(this);

    pThis->execSync(static_cast<VariantMaterial *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *VariantMaterialBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    VariantMaterial *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const VariantMaterial *>(pRefAspect),
                  dynamic_cast<const VariantMaterial *>(this));

    return returnValue;
}
#endif

void VariantMaterialBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<VariantMaterial *>(this)->setFallbackMaterial(NULL);


}


OSG_END_NAMESPACE
