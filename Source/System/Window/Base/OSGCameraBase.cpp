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
 **     class Camera!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILECAMERAINST

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OSGConfig.h>



#include <OSGNode.h> // Beacon Class

#include "OSGCameraBase.h"
#include "OSGCamera.h"

#include "boost/bind.hpp"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::Camera
    \ingroup GrpSystemWindowCameras

    The Camera base class, see \ref PageSystemWindowCamera for a description.

    The only common fields are _sfNear and _sfFar.
 */

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

/*! \var NodePtr         CameraBase::_sfBeacon
    The object that define's the camera's coordinate system. The camera is positioned
    at the origin of the system and looks down the negative z-axis (OpenGL-style).
*/

/*! \var Real32          CameraBase::_sfNear
    The near distance of the camera.
*/

/*! \var Real32          CameraBase::_sfFar
    The far distance of the camera.
*/


void CameraBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFNodePtr::Description(
        SFNodePtr::getClassType(),
        "beacon",
        "The object that define's the camera's coordinate system. The camera is positioned\n"
        "at the origin of the system and looks down the negative z-axis (OpenGL-style).\n",
        BeaconFieldId, BeaconFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&CameraBase::editHandleBeacon),
        static_cast<FieldGetMethodSig >(&CameraBase::getHandleBeacon));

    oType.addInitialDesc(pDesc);

    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "near",
        "The near distance of the camera.\n",
        NearFieldId, NearFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&CameraBase::editHandleNear),
        static_cast<FieldGetMethodSig >(&CameraBase::getHandleNear));

    oType.addInitialDesc(pDesc);

    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "far",
        "The far distance of the camera.\n",
        FarFieldId, FarFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&CameraBase::editHandleFar),
        static_cast<FieldGetMethodSig >(&CameraBase::getHandleFar));

    oType.addInitialDesc(pDesc);
}


CameraBase::TypeObject CameraBase::_type(
    CameraBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    NULL,
    Camera::initMethod,
    Camera::exitMethod,
    (InitalInsertDescFunc) &CameraBase::classDescInserter,
    false,
    0,
    "<?xml version=\"1.0\" ?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"Camera\"\n"
    "\tparent=\"AttachmentContainer\"\n"
    "\tlibrary=\"System\"\n"
    "\tstructure=\"abstract\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"true\"\n"
    ">\n"
    "\\ingroup GrpSystemWindowCameras\n"
    "\n"
    "The Camera base class, see \\ref PageSystemWindowCamera for a description.\n"
    "\n"
    "The only common fields are _sfNear and _sfFar.\n"
    "\t<Field\n"
    "\t\tname=\"beacon\"\n"
    "\t\ttype=\"NodePtr\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t>\n"
    "\tThe object that define's the camera's coordinate system. The camera is positioned\n"
    "\tat the origin of the system and looks down the negative z-axis (OpenGL-style).\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"near\"\n"
    "\t\ttype=\"Real32\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t>\n"
    "\tThe near distance of the camera.\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"far\"\n"
    "\t\ttype=\"Real32\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t>\n"
    "\tThe far distance of the camera.\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "\\ingroup GrpSystemWindowCameras\n"
    "\n"
    "The Camera base class, see \\ref PageSystemWindowCamera for a description.\n"
    "\n"
    "The only common fields are _sfNear and _sfFar.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &CameraBase::getType(void)
{
    return _type;
}

const FieldContainerType &CameraBase::getType(void) const
{
    return _type;
}

UInt32 CameraBase::getContainerSize(void) const
{
    return sizeof(Camera);
}

/*------------------------- decorator get ------------------------------*/


//! Get the Camera::_sfBeacon field.
const SFNodePtr *CameraBase::getSFBeacon(void) const
{
    return &_sfBeacon;
}

SFReal32 *CameraBase::editSFNear(void)
{
    editSField(NearFieldMask);

    return &_sfNear;
}

const SFReal32 *CameraBase::getSFNear(void) const
{
    return &_sfNear;
}

#ifdef OSG_1_GET_COMPAT
SFReal32            *CameraBase::getSFNear           (void)
{
    return this->editSFNear           ();
}
#endif

SFReal32 *CameraBase::editSFFar(void)
{
    editSField(FarFieldMask);

    return &_sfFar;
}

const SFReal32 *CameraBase::getSFFar(void) const
{
    return &_sfFar;
}

#ifdef OSG_1_GET_COMPAT
SFReal32            *CameraBase::getSFFar            (void)
{
    return this->editSFFar            ();
}
#endif





/*------------------------------ access -----------------------------------*/

UInt32 CameraBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (BeaconFieldMask & whichField))
    {
        returnValue += _sfBeacon.getBinSize();
    }
    if(FieldBits::NoField != (NearFieldMask & whichField))
    {
        returnValue += _sfNear.getBinSize();
    }
    if(FieldBits::NoField != (FarFieldMask & whichField))
    {
        returnValue += _sfFar.getBinSize();
    }

    return returnValue;
}

void CameraBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (BeaconFieldMask & whichField))
    {
        _sfBeacon.copyToBin(pMem);
    }
    if(FieldBits::NoField != (NearFieldMask & whichField))
    {
        _sfNear.copyToBin(pMem);
    }
    if(FieldBits::NoField != (FarFieldMask & whichField))
    {
        _sfFar.copyToBin(pMem);
    }
}

void CameraBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (BeaconFieldMask & whichField))
    {
        _sfBeacon.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (NearFieldMask & whichField))
    {
        _sfNear.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (FarFieldMask & whichField))
    {
        _sfFar.copyFromBin(pMem);
    }
}




/*------------------------- constructors ----------------------------------*/

CameraBase::CameraBase(void) :
    Inherited(),
    _sfBeacon                 (NullFC),
    _sfNear                   (),
    _sfFar                    ()
{
}

CameraBase::CameraBase(const CameraBase &source) :
    Inherited(source),
    _sfBeacon                 (NullFC),
    _sfNear                   (source._sfNear                   ),
    _sfFar                    (source._sfFar                    )
{
}


/*-------------------------- destructors ----------------------------------*/

CameraBase::~CameraBase(void)
{
}

void CameraBase::onCreate(const Camera *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {

        this->setBeacon(source->getBeacon());
    }
}

GetFieldHandlePtr CameraBase::getHandleBeacon          (void) const
{
    SFNodePtr::GetHandlePtr returnValue(
        new  SFNodePtr::GetHandle(
             &_sfBeacon, 
             this->getType().getFieldDesc(BeaconFieldId)));

    return returnValue;
}

EditFieldHandlePtr CameraBase::editHandleBeacon         (void)
{
    SFNodePtr::EditHandlePtr returnValue(
        new  SFNodePtr::EditHandle(
             &_sfBeacon, 
             this->getType().getFieldDesc(BeaconFieldId)));

    returnValue->setSetMethod(boost::bind(&Camera::setBeacon, 
                                          static_cast<Camera *>(this), _1));

    editSField(BeaconFieldMask);

    return returnValue;
}

GetFieldHandlePtr CameraBase::getHandleNear            (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfNear, 
             this->getType().getFieldDesc(NearFieldId)));

    return returnValue;
}

EditFieldHandlePtr CameraBase::editHandleNear           (void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfNear, 
             this->getType().getFieldDesc(NearFieldId)));

    editSField(NearFieldMask);

    return returnValue;
}

GetFieldHandlePtr CameraBase::getHandleFar             (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfFar, 
             this->getType().getFieldDesc(FarFieldId)));

    return returnValue;
}

EditFieldHandlePtr CameraBase::editHandleFar            (void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfFar, 
             this->getType().getFieldDesc(FarFieldId)));

    editSField(FarFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void CameraBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    this->execSync(static_cast<CameraBase *>(&oFrom),
                   whichField,
                   oOffsets,
                   syncMode,
                   uiSyncInfo);
}
#endif



void CameraBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<Camera *>(this)->setBeacon(NullFC);


}

/*------------------------------ get -----------------------------------*/


//! Get the value of the Camera::_sfBeacon field.
NodePtrConst CameraBase::getBeacon(void) const
{
    return _sfBeacon.getValue();
}

//! Set the value of the Camera::_sfBeacon field.
void CameraBase::setBeacon(NodePtrConstArg value)
{
    editSField(BeaconFieldMask);

    setRefd(_sfBeacon.getValue(), value);
}
//! Get the value of the Camera::_sfNear field.

Real32 &CameraBase::editNear(void)
{
    editSField(NearFieldMask);

    return _sfNear.getValue();
}

//! Get the value of the Camera::_sfNear field.
const Real32 &CameraBase::getNear(void) const
{
    return _sfNear.getValue();
}

#ifdef OSG_1_GET_COMPAT
Real32              &CameraBase::getNear           (void)
{
    return this->editNear           ();
}
#endif

//! Set the value of the Camera::_sfNear field.
void CameraBase::setNear(const Real32 &value)
{
    editSField(NearFieldMask);

    _sfNear.setValue(value);
}
//! Get the value of the Camera::_sfFar field.

Real32 &CameraBase::editFar(void)
{
    editSField(FarFieldMask);

    return _sfFar.getValue();
}

//! Get the value of the Camera::_sfFar field.
const Real32 &CameraBase::getFar(void) const
{
    return _sfFar.getValue();
}

#ifdef OSG_1_GET_COMPAT
Real32              &CameraBase::getFar            (void)
{
    return this->editFar            ();
}
#endif

//! Set the value of the Camera::_sfFar field.
void CameraBase::setFar(const Real32 &value)
{
    editSField(FarFieldMask);

    _sfFar.setValue(value);
}


OSG_END_NAMESPACE

#include "OSGSFieldAdaptor.ins"
#include "OSGMFieldAdaptor.ins"

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<CameraPtr>::_type("CameraPtr", "AttachmentContainerPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(CameraPtr)

OSG_FIELD_DLLEXPORT_DEF2(SFieldAdaptor, CameraPtr, SFFieldContainerPtr);
OSG_FIELD_DLLEXPORT_DEF2(MFieldAdaptor, CameraPtr, MFFieldContainerPtr);

OSG_END_NAMESPACE
