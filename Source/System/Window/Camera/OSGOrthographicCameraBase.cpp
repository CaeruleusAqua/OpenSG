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
 **     class OrthographicCamera!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGOrthographicCameraBase.h"
#include "OSGOrthographicCamera.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::OrthographicCamera
    A perspective camera with a symmetric frustum.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Real32          OrthographicCameraBase::_sfVerticalSize
    The vertical size of the camera box, in world units. Ignored when less then or equal to zero.
*/

/*! \var Real32          OrthographicCameraBase::_sfHorizontalSize
    The horizontal size of the camera box, in world units. Ignored when less then or equal to zero.
*/

/*! \var Real32          OrthographicCameraBase::_sfAspect
    The aspect ratio (i.e. width / height) of a pixel.
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<OrthographicCamera *>::_type("OrthographicCameraPtr", "CameraPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(OrthographicCamera *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           OrthographicCamera *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           OrthographicCamera *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void OrthographicCameraBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "verticalSize",
        "The vertical size of the camera box, in world units. Ignored when less then or equal to zero.\n",
        VerticalSizeFieldId, VerticalSizeFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&OrthographicCamera::editHandleVerticalSize),
        static_cast<FieldGetMethodSig >(&OrthographicCamera::getHandleVerticalSize));

    oType.addInitialDesc(pDesc);

    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "horizontalSize",
        "The horizontal size of the camera box, in world units. Ignored when less then or equal to zero.\n",
        HorizontalSizeFieldId, HorizontalSizeFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&OrthographicCamera::editHandleHorizontalSize),
        static_cast<FieldGetMethodSig >(&OrthographicCamera::getHandleHorizontalSize));

    oType.addInitialDesc(pDesc);

    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "aspect",
        "The aspect ratio (i.e. width / height) of a pixel.\n",
        AspectFieldId, AspectFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&OrthographicCamera::editHandleAspect),
        static_cast<FieldGetMethodSig >(&OrthographicCamera::getHandleAspect));

    oType.addInitialDesc(pDesc);
}


OrthographicCameraBase::TypeObject OrthographicCameraBase::_type(
    OrthographicCameraBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&OrthographicCameraBase::createEmptyLocal),
    OrthographicCamera::initMethod,
    OrthographicCamera::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&OrthographicCamera::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\" ?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"OrthographicCamera\"\n"
    "\tparent=\"Camera\"\n"
    "\tlibrary=\"Window\"\n"
    "\tstructure=\"concrete\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    ">\n"
    "A perspective camera with a symmetric frustum.\n"
    "\t<Field\n"
    "\t\tname=\"verticalSize\"\n"
    "\t\ttype=\"Real32\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t>\n"
    "\tThe vertical size of the camera box, in world units. Ignored when less then or equal to zero.\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"horizontalSize\"\n"
    "\t\ttype=\"Real32\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "        defaultValue=\"-1\"\n"
    "\t>\n"
    "\tThe horizontal size of the camera box, in world units. Ignored when less then or equal to zero.\n"
    " \t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"aspect\"\n"
    "\t\ttype=\"Real32\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "        defaultValue=\"1\"\n"
    "\t>\n"
    "\tThe aspect ratio (i.e. width / height) of a pixel.\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "A perspective camera with a symmetric frustum.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &OrthographicCameraBase::getType(void)
{
    return _type;
}

const FieldContainerType &OrthographicCameraBase::getType(void) const
{
    return _type;
}

UInt32 OrthographicCameraBase::getContainerSize(void) const
{
    return sizeof(OrthographicCamera);
}

/*------------------------- decorator get ------------------------------*/


SFReal32 *OrthographicCameraBase::editSFVerticalSize(void)
{
    editSField(VerticalSizeFieldMask);

    return &_sfVerticalSize;
}

const SFReal32 *OrthographicCameraBase::getSFVerticalSize(void) const
{
    return &_sfVerticalSize;
}


SFReal32 *OrthographicCameraBase::editSFHorizontalSize(void)
{
    editSField(HorizontalSizeFieldMask);

    return &_sfHorizontalSize;
}

const SFReal32 *OrthographicCameraBase::getSFHorizontalSize(void) const
{
    return &_sfHorizontalSize;
}


SFReal32 *OrthographicCameraBase::editSFAspect(void)
{
    editSField(AspectFieldMask);

    return &_sfAspect;
}

const SFReal32 *OrthographicCameraBase::getSFAspect(void) const
{
    return &_sfAspect;
}






/*------------------------------ access -----------------------------------*/

UInt32 OrthographicCameraBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (VerticalSizeFieldMask & whichField))
    {
        returnValue += _sfVerticalSize.getBinSize();
    }
    if(FieldBits::NoField != (HorizontalSizeFieldMask & whichField))
    {
        returnValue += _sfHorizontalSize.getBinSize();
    }
    if(FieldBits::NoField != (AspectFieldMask & whichField))
    {
        returnValue += _sfAspect.getBinSize();
    }

    return returnValue;
}

void OrthographicCameraBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (VerticalSizeFieldMask & whichField))
    {
        _sfVerticalSize.copyToBin(pMem);
    }
    if(FieldBits::NoField != (HorizontalSizeFieldMask & whichField))
    {
        _sfHorizontalSize.copyToBin(pMem);
    }
    if(FieldBits::NoField != (AspectFieldMask & whichField))
    {
        _sfAspect.copyToBin(pMem);
    }
}

void OrthographicCameraBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (VerticalSizeFieldMask & whichField))
    {
        _sfVerticalSize.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (HorizontalSizeFieldMask & whichField))
    {
        _sfHorizontalSize.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (AspectFieldMask & whichField))
    {
        _sfAspect.copyFromBin(pMem);
    }
}

//! create a new instance of the class
OrthographicCameraTransitPtr OrthographicCameraBase::createLocal(BitVector bFlags)
{
    OrthographicCameraTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<OrthographicCamera>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
OrthographicCameraTransitPtr OrthographicCameraBase::createDependent(BitVector bFlags)
{
    OrthographicCameraTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<OrthographicCamera>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
OrthographicCameraTransitPtr OrthographicCameraBase::create(void)
{
    OrthographicCameraTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<OrthographicCamera>(tmpPtr);
    }

    return fc;
}

OrthographicCamera *OrthographicCameraBase::createEmptyLocal(BitVector bFlags)
{
    OrthographicCamera *returnValue;

    newPtr<OrthographicCamera>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
OrthographicCamera *OrthographicCameraBase::createEmpty(void)
{
    OrthographicCamera *returnValue;

    newPtr<OrthographicCamera>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr OrthographicCameraBase::shallowCopyLocal(
    BitVector bFlags) const
{
    OrthographicCamera *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const OrthographicCamera *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr OrthographicCameraBase::shallowCopyDependent(
    BitVector bFlags) const
{
    OrthographicCamera *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const OrthographicCamera *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr OrthographicCameraBase::shallowCopy(void) const
{
    OrthographicCamera *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const OrthographicCamera *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

OrthographicCameraBase::OrthographicCameraBase(void) :
    Inherited(),
    _sfVerticalSize           (),
    _sfHorizontalSize         (Real32(-1)),
    _sfAspect                 (Real32(1))
{
}

OrthographicCameraBase::OrthographicCameraBase(const OrthographicCameraBase &source) :
    Inherited(source),
    _sfVerticalSize           (source._sfVerticalSize           ),
    _sfHorizontalSize         (source._sfHorizontalSize         ),
    _sfAspect                 (source._sfAspect                 )
{
}


/*-------------------------- destructors ----------------------------------*/

OrthographicCameraBase::~OrthographicCameraBase(void)
{
}


GetFieldHandlePtr OrthographicCameraBase::getHandleVerticalSize    (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfVerticalSize,
             this->getType().getFieldDesc(VerticalSizeFieldId),
             const_cast<OrthographicCameraBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr OrthographicCameraBase::editHandleVerticalSize   (void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfVerticalSize,
             this->getType().getFieldDesc(VerticalSizeFieldId),
             this));


    editSField(VerticalSizeFieldMask);

    return returnValue;
}

GetFieldHandlePtr OrthographicCameraBase::getHandleHorizontalSize  (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfHorizontalSize,
             this->getType().getFieldDesc(HorizontalSizeFieldId),
             const_cast<OrthographicCameraBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr OrthographicCameraBase::editHandleHorizontalSize (void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfHorizontalSize,
             this->getType().getFieldDesc(HorizontalSizeFieldId),
             this));


    editSField(HorizontalSizeFieldMask);

    return returnValue;
}

GetFieldHandlePtr OrthographicCameraBase::getHandleAspect          (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfAspect,
             this->getType().getFieldDesc(AspectFieldId),
             const_cast<OrthographicCameraBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr OrthographicCameraBase::editHandleAspect         (void)
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
void OrthographicCameraBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    OrthographicCamera *pThis = static_cast<OrthographicCamera *>(this);

    pThis->execSync(static_cast<OrthographicCamera *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *OrthographicCameraBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    OrthographicCamera *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const OrthographicCamera *>(pRefAspect),
                  dynamic_cast<const OrthographicCamera *>(this));

    return returnValue;
}
#endif

void OrthographicCameraBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
