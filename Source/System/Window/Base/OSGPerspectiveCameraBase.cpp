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
 **     class PerspectiveCamera!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGPerspectiveCameraBase.h"
#include "OSGPerspectiveCamera.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::PerspectiveCamera
    \ingroup GrpSystemWindowCameras

    The Perspective Camera class, see \ref PageSystemWindowCameraPerspective for 
    a description.

    The only new parameter is the _sfFov.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Real32          PerspectiveCameraBase::_sfFov
    The vertical field of view, in radians.
*/

/*! \var UInt32          PerspectiveCameraBase::_sfFovMode
    Defines whether the field of view is measured vertically, horizontally or
    in the smaller direction. See OSG::PerspectiveCamera::FovMode enum for
    the actual values, 
*/

/*! \var Real32          PerspectiveCameraBase::_sfAspect
    The aspect ratio (i.e. width / height) of a pixel.
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<PerspectiveCamera *>::_type("PerspectiveCameraPtr", "CameraPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(PerspectiveCamera *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           PerspectiveCamera *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           PerspectiveCamera *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void PerspectiveCameraBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "fov",
        "The vertical field of view, in radians.\n",
        FovFieldId, FovFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&PerspectiveCamera::editHandleFov),
        static_cast<FieldGetMethodSig >(&PerspectiveCamera::getHandleFov));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUInt32::Description(
        SFUInt32::getClassType(),
        "fovMode",
        "Defines whether the field of view is measured vertically, horizontally or\n"
        "in the smaller direction. See OSG::PerspectiveCamera::FovMode enum for\n"
        "the actual values, \n",
        FovModeFieldId, FovModeFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&PerspectiveCamera::editHandleFovMode),
        static_cast<FieldGetMethodSig >(&PerspectiveCamera::getHandleFovMode));

    oType.addInitialDesc(pDesc);

    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "aspect",
        "The aspect ratio (i.e. width / height) of a pixel.\n",
        AspectFieldId, AspectFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&PerspectiveCamera::editHandleAspect),
        static_cast<FieldGetMethodSig >(&PerspectiveCamera::getHandleAspect));

    oType.addInitialDesc(pDesc);
}


PerspectiveCameraBase::TypeObject PerspectiveCameraBase::_type(
    PerspectiveCameraBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&PerspectiveCameraBase::createEmptyLocal),
    PerspectiveCamera::initMethod,
    PerspectiveCamera::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&PerspectiveCamera::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\" ?>\n"
    "\n"
    "<FieldContainer\n"
    "    name=\"PerspectiveCamera\"\n"
    "    parent=\"Camera\"\n"
    "    library=\"System\"\n"
    "    structure=\"concrete\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    ">\n"
    "\\ingroup GrpSystemWindowCameras\n"
    "\n"
    "The Perspective Camera class, see \\ref PageSystemWindowCameraPerspective for \n"
    "a description.\n"
    "\n"
    "The only new parameter is the _sfFov.\n"
    "    <Field\n"
    "        name=\"fov\"\n"
    "        type=\"Real32\"\n"
    "        cardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "    >\n"
    "    The vertical field of view, in radians.\n"
    "    </Field>\n"
    "    <Field\n"
    "        name=\"fovMode\"\n"
    "        type=\"UInt32\"\n"
    "        cardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "        defaultValue=\"0\"\n"
    "        access=\"public\"\n"
    "    >\n"
    "    Defines whether the field of view is measured vertically, horizontally or\n"
    "    in the smaller direction. See OSG::PerspectiveCamera::FovMode enum for\n"
    "    the actual values, \n"
    "    </Field>\n"
    "    <Field\n"
    "        name=\"aspect\"\n"
    "        type=\"Real32\"\n"
    "        cardinality=\"single\"\n"
    "        visibility=\"external\"\n"
    "        defaultValue=\"1\"\n"
    "    >\n"
    "    The aspect ratio (i.e. width / height) of a pixel.\n"
    "    </Field>\n"
    "</FieldContainer>\n",
    "\\ingroup GrpSystemWindowCameras\n"
    "\n"
    "The Perspective Camera class, see \\ref PageSystemWindowCameraPerspective for \n"
    "a description.\n"
    "\n"
    "The only new parameter is the _sfFov.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &PerspectiveCameraBase::getType(void)
{
    return _type;
}

const FieldContainerType &PerspectiveCameraBase::getType(void) const
{
    return _type;
}

UInt32 PerspectiveCameraBase::getContainerSize(void) const
{
    return sizeof(PerspectiveCamera);
}

/*------------------------- decorator get ------------------------------*/


SFReal32 *PerspectiveCameraBase::editSFFov(void)
{
    editSField(FovFieldMask);

    return &_sfFov;
}

const SFReal32 *PerspectiveCameraBase::getSFFov(void) const
{
    return &_sfFov;
}


SFUInt32 *PerspectiveCameraBase::editSFFovMode(void)
{
    editSField(FovModeFieldMask);

    return &_sfFovMode;
}

const SFUInt32 *PerspectiveCameraBase::getSFFovMode(void) const
{
    return &_sfFovMode;
}


SFReal32 *PerspectiveCameraBase::editSFAspect(void)
{
    editSField(AspectFieldMask);

    return &_sfAspect;
}

const SFReal32 *PerspectiveCameraBase::getSFAspect(void) const
{
    return &_sfAspect;
}






/*------------------------------ access -----------------------------------*/

UInt32 PerspectiveCameraBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (FovFieldMask & whichField))
    {
        returnValue += _sfFov.getBinSize();
    }
    if(FieldBits::NoField != (FovModeFieldMask & whichField))
    {
        returnValue += _sfFovMode.getBinSize();
    }
    if(FieldBits::NoField != (AspectFieldMask & whichField))
    {
        returnValue += _sfAspect.getBinSize();
    }

    return returnValue;
}

void PerspectiveCameraBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (FovFieldMask & whichField))
    {
        _sfFov.copyToBin(pMem);
    }
    if(FieldBits::NoField != (FovModeFieldMask & whichField))
    {
        _sfFovMode.copyToBin(pMem);
    }
    if(FieldBits::NoField != (AspectFieldMask & whichField))
    {
        _sfAspect.copyToBin(pMem);
    }
}

void PerspectiveCameraBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (FovFieldMask & whichField))
    {
        _sfFov.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (FovModeFieldMask & whichField))
    {
        _sfFovMode.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (AspectFieldMask & whichField))
    {
        _sfAspect.copyFromBin(pMem);
    }
}

//! create a new instance of the class
PerspectiveCameraTransitPtr PerspectiveCameraBase::createLocal(BitVector bFlags)
{
    PerspectiveCameraTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<PerspectiveCamera>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
PerspectiveCameraTransitPtr PerspectiveCameraBase::createDependent(BitVector bFlags)
{
    PerspectiveCameraTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<PerspectiveCamera>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
PerspectiveCameraTransitPtr PerspectiveCameraBase::create(void)
{
    PerspectiveCameraTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<PerspectiveCamera>(tmpPtr);
    }

    return fc;
}

PerspectiveCamera *PerspectiveCameraBase::createEmptyLocal(BitVector bFlags)
{
    PerspectiveCamera *returnValue;

    newPtr<PerspectiveCamera>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
PerspectiveCamera *PerspectiveCameraBase::createEmpty(void)
{
    PerspectiveCamera *returnValue;

    newPtr<PerspectiveCamera>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr PerspectiveCameraBase::shallowCopyLocal(
    BitVector bFlags) const
{
    PerspectiveCamera *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const PerspectiveCamera *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr PerspectiveCameraBase::shallowCopyDependent(
    BitVector bFlags) const
{
    PerspectiveCamera *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const PerspectiveCamera *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr PerspectiveCameraBase::shallowCopy(void) const
{
    PerspectiveCamera *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const PerspectiveCamera *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

PerspectiveCameraBase::PerspectiveCameraBase(void) :
    Inherited(),
    _sfFov                    (),
    _sfFovMode                (UInt32(0)),
    _sfAspect                 (Real32(1))
{
}

PerspectiveCameraBase::PerspectiveCameraBase(const PerspectiveCameraBase &source) :
    Inherited(source),
    _sfFov                    (source._sfFov                    ),
    _sfFovMode                (source._sfFovMode                ),
    _sfAspect                 (source._sfAspect                 )
{
}


/*-------------------------- destructors ----------------------------------*/

PerspectiveCameraBase::~PerspectiveCameraBase(void)
{
}


GetFieldHandlePtr PerspectiveCameraBase::getHandleFov             (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfFov,
             this->getType().getFieldDesc(FovFieldId),
             const_cast<PerspectiveCameraBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr PerspectiveCameraBase::editHandleFov            (void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfFov,
             this->getType().getFieldDesc(FovFieldId),
             this));


    editSField(FovFieldMask);

    return returnValue;
}

GetFieldHandlePtr PerspectiveCameraBase::getHandleFovMode         (void) const
{
    SFUInt32::GetHandlePtr returnValue(
        new  SFUInt32::GetHandle(
             &_sfFovMode,
             this->getType().getFieldDesc(FovModeFieldId),
             const_cast<PerspectiveCameraBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr PerspectiveCameraBase::editHandleFovMode        (void)
{
    SFUInt32::EditHandlePtr returnValue(
        new  SFUInt32::EditHandle(
             &_sfFovMode,
             this->getType().getFieldDesc(FovModeFieldId),
             this));


    editSField(FovModeFieldMask);

    return returnValue;
}

GetFieldHandlePtr PerspectiveCameraBase::getHandleAspect          (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfAspect,
             this->getType().getFieldDesc(AspectFieldId),
             const_cast<PerspectiveCameraBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr PerspectiveCameraBase::editHandleAspect         (void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfAspect,
             this->getType().getFieldDesc(AspectFieldId),
             this));


    editSField(AspectFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void PerspectiveCameraBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    PerspectiveCamera *pThis = static_cast<PerspectiveCamera *>(this);

    pThis->execSync(static_cast<PerspectiveCamera *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *PerspectiveCameraBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    PerspectiveCamera *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const PerspectiveCamera *>(pRefAspect),
                  dynamic_cast<const PerspectiveCamera *>(this));

    return returnValue;
}
#endif

void PerspectiveCameraBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
