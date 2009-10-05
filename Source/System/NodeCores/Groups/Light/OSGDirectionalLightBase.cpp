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
 **     class DirectionalLight!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGDirectionalLightBase.h"
#include "OSGDirectionalLight.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::DirectionalLight
    DirectionalLight is an infinitely distant lightsource. Its only
    attribute is the light's direction.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Vec3r           DirectionalLightBase::_sfDirection
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<DirectionalLight *>::_type("DirectionalLightPtr", "LightPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(DirectionalLight *)

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void DirectionalLightBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFVec3r::Description(
        SFVec3r::getClassType(),
        "direction",
        "",
        DirectionFieldId, DirectionFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&DirectionalLight::editHandleDirection),
        static_cast<FieldGetMethodSig >(&DirectionalLight::getHandleDirection));

    oType.addInitialDesc(pDesc);
}


DirectionalLightBase::TypeObject DirectionalLightBase::_type(
    DirectionalLightBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&DirectionalLightBase::createEmptyLocal),
    DirectionalLight::initMethod,
    DirectionalLight::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&DirectionalLight::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\" ?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"DirectionalLight\"\n"
    "\tparent=\"Light\"\n"
    "\tlibrary=\"Group\"\n"
    "\tstructure=\"concrete\"\n"
    "\tpointerfieldtypes=\"none\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "    isNodeCore=\"true\"\n"
    ">\n"
    "DirectionalLight is an infinitely distant lightsource. Its only\n"
    "attribute is the light's direction.\n"
    "\t<Field\n"
    "\t\tname=\"direction\"\n"
    "\t\ttype=\"Vec3r\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "                defaultValue=\"0.f,0.f,1.f\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "DirectionalLight is an infinitely distant lightsource. Its only\n"
    "attribute is the light's direction.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &DirectionalLightBase::getType(void)
{
    return _type;
}

const FieldContainerType &DirectionalLightBase::getType(void) const
{
    return _type;
}

UInt32 DirectionalLightBase::getContainerSize(void) const
{
    return sizeof(DirectionalLight);
}

/*------------------------- decorator get ------------------------------*/


SFVec3r *DirectionalLightBase::editSFDirection(void)
{
    editSField(DirectionFieldMask);

    return &_sfDirection;
}

const SFVec3r *DirectionalLightBase::getSFDirection(void) const
{
    return &_sfDirection;
}






/*------------------------------ access -----------------------------------*/

UInt32 DirectionalLightBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (DirectionFieldMask & whichField))
    {
        returnValue += _sfDirection.getBinSize();
    }

    return returnValue;
}

void DirectionalLightBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (DirectionFieldMask & whichField))
    {
        _sfDirection.copyToBin(pMem);
    }
}

void DirectionalLightBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (DirectionFieldMask & whichField))
    {
        _sfDirection.copyFromBin(pMem);
    }
}

//! create a new instance of the class
DirectionalLightTransitPtr DirectionalLightBase::createLocal(BitVector bFlags)
{
    DirectionalLightTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<DirectionalLight>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
DirectionalLightTransitPtr DirectionalLightBase::createDependent(BitVector bFlags)
{
    DirectionalLightTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<DirectionalLight>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
DirectionalLightTransitPtr DirectionalLightBase::create(void)
{
    DirectionalLightTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<DirectionalLight>(tmpPtr);
    }

    return fc;
}

DirectionalLight *DirectionalLightBase::createEmptyLocal(BitVector bFlags)
{
    DirectionalLight *returnValue;

    newPtr<DirectionalLight>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
DirectionalLight *DirectionalLightBase::createEmpty(void)
{
    DirectionalLight *returnValue;

    newPtr<DirectionalLight>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr DirectionalLightBase::shallowCopyLocal(
    BitVector bFlags) const
{
    DirectionalLight *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const DirectionalLight *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr DirectionalLightBase::shallowCopyDependent(
    BitVector bFlags) const
{
    DirectionalLight *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const DirectionalLight *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr DirectionalLightBase::shallowCopy(void) const
{
    DirectionalLight *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const DirectionalLight *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

DirectionalLightBase::DirectionalLightBase(void) :
    Inherited(),
    _sfDirection              (Vec3r(0.f,0.f,1.f))
{
}

DirectionalLightBase::DirectionalLightBase(const DirectionalLightBase &source) :
    Inherited(source),
    _sfDirection              (source._sfDirection              )
{
}


/*-------------------------- destructors ----------------------------------*/

DirectionalLightBase::~DirectionalLightBase(void)
{
}


GetFieldHandlePtr DirectionalLightBase::getHandleDirection       (void) const
{
    SFVec3r::GetHandlePtr returnValue(
        new  SFVec3r::GetHandle(
             &_sfDirection,
             this->getType().getFieldDesc(DirectionFieldId),
             const_cast<DirectionalLightBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr DirectionalLightBase::editHandleDirection      (void)
{
    SFVec3r::EditHandlePtr returnValue(
        new  SFVec3r::EditHandle(
             &_sfDirection,
             this->getType().getFieldDesc(DirectionFieldId),
             this));


    editSField(DirectionFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void DirectionalLightBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    DirectionalLight *pThis = static_cast<DirectionalLight *>(this);

    pThis->execSync(static_cast<DirectionalLight *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *DirectionalLightBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    DirectionalLight *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const DirectionalLight *>(pRefAspect),
                  dynamic_cast<const DirectionalLight *>(this));

    return returnValue;
}
#endif

void DirectionalLightBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
