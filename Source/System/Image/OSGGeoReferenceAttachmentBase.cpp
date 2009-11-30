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
 **     class GeoReferenceAttachment!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEGEOREFERENCEATTACHMENTINST

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OSGConfig.h>




#include "OSGGeoReferenceAttachmentBase.h"
#include "OSGGeoReferenceAttachment.h"

#include "boost/bind.hpp"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::GeoReferenceAttachment
    
 */

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

/*! \var UInt32          GeoReferenceAttachmentBase::_sfDatum
    
*/

/*! \var Vec2f           GeoReferenceAttachmentBase::_sfEllipsoidAxis
    
*/

/*! \var Vec2f           GeoReferenceAttachmentBase::_sfOrigin
    
*/

/*! \var Vec2f           GeoReferenceAttachmentBase::_sfPixelSize
    
*/

/*! \var Real64          GeoReferenceAttachmentBase::_sfNoDataValue
    
*/


void GeoReferenceAttachmentBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUInt32::Description(
        SFUInt32::getClassType(),
        "datum",
        "",
        DatumFieldId, DatumFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&GeoReferenceAttachmentBase::editHandleDatum),
        static_cast<FieldGetMethodSig >(&GeoReferenceAttachmentBase::getHandleDatum));

    oType.addInitialDesc(pDesc);

    pDesc = new SFVec2f::Description(
        SFVec2f::getClassType(),
        "ellipsoidAxis",
        "",
        EllipsoidAxisFieldId, EllipsoidAxisFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&GeoReferenceAttachmentBase::editHandleEllipsoidAxis),
        static_cast<FieldGetMethodSig >(&GeoReferenceAttachmentBase::getHandleEllipsoidAxis));

    oType.addInitialDesc(pDesc);

    pDesc = new SFVec2f::Description(
        SFVec2f::getClassType(),
        "origin",
        "",
        OriginFieldId, OriginFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&GeoReferenceAttachmentBase::editHandleOrigin),
        static_cast<FieldGetMethodSig >(&GeoReferenceAttachmentBase::getHandleOrigin));

    oType.addInitialDesc(pDesc);

    pDesc = new SFVec2f::Description(
        SFVec2f::getClassType(),
        "pixelSize",
        "",
        PixelSizeFieldId, PixelSizeFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&GeoReferenceAttachmentBase::editHandlePixelSize),
        static_cast<FieldGetMethodSig >(&GeoReferenceAttachmentBase::getHandlePixelSize));

    oType.addInitialDesc(pDesc);

    pDesc = new SFReal64::Description(
        SFReal64::getClassType(),
        "noDataValue",
        "",
        NoDataValueFieldId, NoDataValueFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&GeoReferenceAttachmentBase::editHandleNoDataValue),
        static_cast<FieldGetMethodSig >(&GeoReferenceAttachmentBase::getHandleNoDataValue));

    oType.addInitialDesc(pDesc);
}


GeoReferenceAttachmentBase::TypeObject GeoReferenceAttachmentBase::_type(
    GeoReferenceAttachmentBase::getClassname(),
    Inherited::getClassname(),
    "GeoReferenceAttachment",
    0,
    (PrototypeCreateF) &GeoReferenceAttachmentBase::createEmptyLocal,
    GeoReferenceAttachment::initMethod,
    GeoReferenceAttachment::exitMethod,
    (InitalInsertDescFunc) &GeoReferenceAttachmentBase::classDescInserter,
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"GeoReferenceAttachment\"\n"
    "\tparent=\"Attachment\"\n"
    "\tlibrary=\"System\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    ">\n"
    "\t<Field\n"
    "\t\tname=\"datum\"\n"
    "\t\ttype=\"UInt32\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"GeoReferenceAttachment::WGS84\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"ellipsoidAxis\"\n"
    "\t\ttype=\"Vec2f\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"origin\"\n"
    "\t\ttype=\"Vec2f\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"pixelSize\"\n"
    "\t\ttype=\"Vec2f\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"noDataValue\"\n"
    "\t\ttype=\"Real64\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &GeoReferenceAttachmentBase::getType(void)
{
    return _type;
}

const FieldContainerType &GeoReferenceAttachmentBase::getType(void) const
{
    return _type;
}

UInt32 GeoReferenceAttachmentBase::getContainerSize(void) const
{
    return sizeof(GeoReferenceAttachment);
}

/*------------------------- decorator get ------------------------------*/


SFUInt32 *GeoReferenceAttachmentBase::editSFDatum(void)
{
    editSField(DatumFieldMask);

    return &_sfDatum;
}

const SFUInt32 *GeoReferenceAttachmentBase::getSFDatum(void) const
{
    return &_sfDatum;
}

#ifdef OSG_1_GET_COMPAT
SFUInt32            *GeoReferenceAttachmentBase::getSFDatum          (void)
{
    return this->editSFDatum          ();
}
#endif

SFVec2f *GeoReferenceAttachmentBase::editSFEllipsoidAxis(void)
{
    editSField(EllipsoidAxisFieldMask);

    return &_sfEllipsoidAxis;
}

const SFVec2f *GeoReferenceAttachmentBase::getSFEllipsoidAxis(void) const
{
    return &_sfEllipsoidAxis;
}

#ifdef OSG_1_GET_COMPAT
SFVec2f             *GeoReferenceAttachmentBase::getSFEllipsoidAxis  (void)
{
    return this->editSFEllipsoidAxis  ();
}
#endif

SFVec2f *GeoReferenceAttachmentBase::editSFOrigin(void)
{
    editSField(OriginFieldMask);

    return &_sfOrigin;
}

const SFVec2f *GeoReferenceAttachmentBase::getSFOrigin(void) const
{
    return &_sfOrigin;
}

#ifdef OSG_1_GET_COMPAT
SFVec2f             *GeoReferenceAttachmentBase::getSFOrigin         (void)
{
    return this->editSFOrigin         ();
}
#endif

SFVec2f *GeoReferenceAttachmentBase::editSFPixelSize(void)
{
    editSField(PixelSizeFieldMask);

    return &_sfPixelSize;
}

const SFVec2f *GeoReferenceAttachmentBase::getSFPixelSize(void) const
{
    return &_sfPixelSize;
}

#ifdef OSG_1_GET_COMPAT
SFVec2f             *GeoReferenceAttachmentBase::getSFPixelSize      (void)
{
    return this->editSFPixelSize      ();
}
#endif

SFReal64 *GeoReferenceAttachmentBase::editSFNoDataValue(void)
{
    editSField(NoDataValueFieldMask);

    return &_sfNoDataValue;
}

const SFReal64 *GeoReferenceAttachmentBase::getSFNoDataValue(void) const
{
    return &_sfNoDataValue;
}

#ifdef OSG_1_GET_COMPAT
SFReal64            *GeoReferenceAttachmentBase::getSFNoDataValue    (void)
{
    return this->editSFNoDataValue    ();
}
#endif





/*------------------------------ access -----------------------------------*/

UInt32 GeoReferenceAttachmentBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (DatumFieldMask & whichField))
    {
        returnValue += _sfDatum.getBinSize();
    }
    if(FieldBits::NoField != (EllipsoidAxisFieldMask & whichField))
    {
        returnValue += _sfEllipsoidAxis.getBinSize();
    }
    if(FieldBits::NoField != (OriginFieldMask & whichField))
    {
        returnValue += _sfOrigin.getBinSize();
    }
    if(FieldBits::NoField != (PixelSizeFieldMask & whichField))
    {
        returnValue += _sfPixelSize.getBinSize();
    }
    if(FieldBits::NoField != (NoDataValueFieldMask & whichField))
    {
        returnValue += _sfNoDataValue.getBinSize();
    }

    return returnValue;
}

void GeoReferenceAttachmentBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (DatumFieldMask & whichField))
    {
        _sfDatum.copyToBin(pMem);
    }
    if(FieldBits::NoField != (EllipsoidAxisFieldMask & whichField))
    {
        _sfEllipsoidAxis.copyToBin(pMem);
    }
    if(FieldBits::NoField != (OriginFieldMask & whichField))
    {
        _sfOrigin.copyToBin(pMem);
    }
    if(FieldBits::NoField != (PixelSizeFieldMask & whichField))
    {
        _sfPixelSize.copyToBin(pMem);
    }
    if(FieldBits::NoField != (NoDataValueFieldMask & whichField))
    {
        _sfNoDataValue.copyToBin(pMem);
    }
}

void GeoReferenceAttachmentBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (DatumFieldMask & whichField))
    {
        _sfDatum.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (EllipsoidAxisFieldMask & whichField))
    {
        _sfEllipsoidAxis.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (OriginFieldMask & whichField))
    {
        _sfOrigin.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (PixelSizeFieldMask & whichField))
    {
        _sfPixelSize.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (NoDataValueFieldMask & whichField))
    {
        _sfNoDataValue.copyFromBin(pMem);
    }
}

//! create a new instance of the class
GeoReferenceAttachmentTransitPtr GeoReferenceAttachmentBase::create(void)
{
    GeoReferenceAttachmentTransitPtr fc;

    if(getClassType().getPrototype() != NullFC)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<GeoReferenceAttachment>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
GeoReferenceAttachmentTransitPtr GeoReferenceAttachmentBase::createLocal(BitVector bFlags)
{
    GeoReferenceAttachmentTransitPtr fc;

    if(getClassType().getPrototype() != NullFC)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<GeoReferenceAttachment>(tmpPtr);
    }

    return fc;
}

//! create an empty new instance of the class, do not copy the prototype
GeoReferenceAttachmentPtr GeoReferenceAttachmentBase::createEmpty(void)
{
    GeoReferenceAttachmentPtr returnValue;

    newPtr<GeoReferenceAttachment>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &= 
        ~Thread::getCurrentLocalFlags(); 

    return returnValue;
}

GeoReferenceAttachmentPtr GeoReferenceAttachmentBase::createEmptyLocal(BitVector bFlags)
{
    GeoReferenceAttachmentPtr returnValue;

    newPtr<GeoReferenceAttachment>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr GeoReferenceAttachmentBase::shallowCopy(void) const
{
    GeoReferenceAttachmentPtr tmpPtr;

    newPtr(tmpPtr, 
           dynamic_cast<const GeoReferenceAttachment *>(this), 
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}

FieldContainerTransitPtr GeoReferenceAttachmentBase::shallowCopyLocal(
    BitVector bFlags) const
{
    GeoReferenceAttachmentPtr tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const GeoReferenceAttachment *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}



/*------------------------- constructors ----------------------------------*/

GeoReferenceAttachmentBase::GeoReferenceAttachmentBase(void) :
    Inherited(),
    _sfDatum                  (UInt32(GeoReferenceAttachment::WGS84)),
    _sfEllipsoidAxis          (),
    _sfOrigin                 (),
    _sfPixelSize              (),
    _sfNoDataValue            ()
{
}

GeoReferenceAttachmentBase::GeoReferenceAttachmentBase(const GeoReferenceAttachmentBase &source) :
    Inherited(source),
    _sfDatum                  (source._sfDatum                  ),
    _sfEllipsoidAxis          (source._sfEllipsoidAxis          ),
    _sfOrigin                 (source._sfOrigin                 ),
    _sfPixelSize              (source._sfPixelSize              ),
    _sfNoDataValue            (source._sfNoDataValue            )
{
}


/*-------------------------- destructors ----------------------------------*/

GeoReferenceAttachmentBase::~GeoReferenceAttachmentBase(void)
{
}


GetFieldHandlePtr GeoReferenceAttachmentBase::getHandleDatum           (void) const
{
    SFUInt32::GetHandlePtr returnValue(
        new  SFUInt32::GetHandle(
             &_sfDatum, 
             this->getType().getFieldDesc(DatumFieldId)));

    return returnValue;
}

EditFieldHandlePtr GeoReferenceAttachmentBase::editHandleDatum          (void)
{
    SFUInt32::EditHandlePtr returnValue(
        new  SFUInt32::EditHandle(
             &_sfDatum, 
             this->getType().getFieldDesc(DatumFieldId)));

    editSField(DatumFieldMask);

    return returnValue;
}

GetFieldHandlePtr GeoReferenceAttachmentBase::getHandleEllipsoidAxis   (void) const
{
    SFVec2f::GetHandlePtr returnValue(
        new  SFVec2f::GetHandle(
             &_sfEllipsoidAxis, 
             this->getType().getFieldDesc(EllipsoidAxisFieldId)));

    return returnValue;
}

EditFieldHandlePtr GeoReferenceAttachmentBase::editHandleEllipsoidAxis  (void)
{
    SFVec2f::EditHandlePtr returnValue(
        new  SFVec2f::EditHandle(
             &_sfEllipsoidAxis, 
             this->getType().getFieldDesc(EllipsoidAxisFieldId)));

    editSField(EllipsoidAxisFieldMask);

    return returnValue;
}

GetFieldHandlePtr GeoReferenceAttachmentBase::getHandleOrigin          (void) const
{
    SFVec2f::GetHandlePtr returnValue(
        new  SFVec2f::GetHandle(
             &_sfOrigin, 
             this->getType().getFieldDesc(OriginFieldId)));

    return returnValue;
}

EditFieldHandlePtr GeoReferenceAttachmentBase::editHandleOrigin         (void)
{
    SFVec2f::EditHandlePtr returnValue(
        new  SFVec2f::EditHandle(
             &_sfOrigin, 
             this->getType().getFieldDesc(OriginFieldId)));

    editSField(OriginFieldMask);

    return returnValue;
}

GetFieldHandlePtr GeoReferenceAttachmentBase::getHandlePixelSize       (void) const
{
    SFVec2f::GetHandlePtr returnValue(
        new  SFVec2f::GetHandle(
             &_sfPixelSize, 
             this->getType().getFieldDesc(PixelSizeFieldId)));

    return returnValue;
}

EditFieldHandlePtr GeoReferenceAttachmentBase::editHandlePixelSize      (void)
{
    SFVec2f::EditHandlePtr returnValue(
        new  SFVec2f::EditHandle(
             &_sfPixelSize, 
             this->getType().getFieldDesc(PixelSizeFieldId)));

    editSField(PixelSizeFieldMask);

    return returnValue;
}

GetFieldHandlePtr GeoReferenceAttachmentBase::getHandleNoDataValue     (void) const
{
    SFReal64::GetHandlePtr returnValue(
        new  SFReal64::GetHandle(
             &_sfNoDataValue, 
             this->getType().getFieldDesc(NoDataValueFieldId)));

    return returnValue;
}

EditFieldHandlePtr GeoReferenceAttachmentBase::editHandleNoDataValue    (void)
{
    SFReal64::EditHandlePtr returnValue(
        new  SFReal64::EditHandle(
             &_sfNoDataValue, 
             this->getType().getFieldDesc(NoDataValueFieldId)));

    editSField(NoDataValueFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void GeoReferenceAttachmentBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    this->execSync(static_cast<GeoReferenceAttachmentBase *>(&oFrom),
                   whichField,
                   oOffsets,
                   syncMode,
                   uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainerPtr GeoReferenceAttachmentBase::createAspectCopy(void) const
{
    GeoReferenceAttachmentPtr returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const GeoReferenceAttachment *>(this));

    return returnValue;
}
#endif

void GeoReferenceAttachmentBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<GeoReferenceAttachmentPtr>::_type("GeoReferenceAttachmentPtr", "AttachmentPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(GeoReferenceAttachmentPtr)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField, 
                           GeoReferenceAttachmentPtr, 
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField, 
                           GeoReferenceAttachmentPtr, 
                           0);

OSG_END_NAMESPACE
