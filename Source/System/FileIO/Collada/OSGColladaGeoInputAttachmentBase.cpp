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
 **     class ColladaGeoInputAttachment!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGGeoVectorProperty.h"       // Properties Class
#include "OSGGeoIntegralProperty.h"     // PropIndices Class

#include "OSGColladaGeoInputAttachmentBase.h"
#include "OSGColladaGeoInputAttachment.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::ColladaGeoInputAttachment
    Attachment that stores information about the inputs of a Collada geometry. This
    can be used to access inputs that are not consumed by the geometry or its material, e.g.
    to access texture coordinates when the material does not specify a texture.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var std::string     ColladaGeoInputAttachmentBase::_mfSemantics
    Semantics of the inputs, in the order they are present in the Collada Geometry.
*/

/*! \var Int32           ColladaGeoInputAttachmentBase::_mfSets
    Sets of the inputs, in the order they are present in the Collada Geometry.
*/

/*! \var GeoVectorProperty * ColladaGeoInputAttachmentBase::_mfProperties
    Properties corresponding to the inputs, in the order they are present in the Collada Geometry.
*/

/*! \var GeoIntegralProperty * ColladaGeoInputAttachmentBase::_mfPropIndices
    Indices corresponding to the inputs, in the order they are present in the Collada Geometry.
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<ColladaGeoInputAttachment *>::_type("ColladaGeoInputAttachmentPtr", "AttachmentPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(ColladaGeoInputAttachment *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           ColladaGeoInputAttachment *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           ColladaGeoInputAttachment *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void ColladaGeoInputAttachmentBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new MFString::Description(
        MFString::getClassType(),
        "semantics",
        "Semantics of the inputs, in the order they are present in the Collada Geometry.\n",
        SemanticsFieldId, SemanticsFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ColladaGeoInputAttachment::editHandleSemantics),
        static_cast<FieldGetMethodSig >(&ColladaGeoInputAttachment::getHandleSemantics));

    oType.addInitialDesc(pDesc);

    pDesc = new MFInt32::Description(
        MFInt32::getClassType(),
        "sets",
        "Sets of the inputs, in the order they are present in the Collada Geometry.\n",
        SetsFieldId, SetsFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ColladaGeoInputAttachment::editHandleSets),
        static_cast<FieldGetMethodSig >(&ColladaGeoInputAttachment::getHandleSets));

    oType.addInitialDesc(pDesc);

    pDesc = new MFUnrecChildGeoVectorPropertyPtr::Description(
        MFUnrecChildGeoVectorPropertyPtr::getClassType(),
        "properties",
        "Properties corresponding to the inputs, in the order they are present in the Collada Geometry.\n",
        PropertiesFieldId, PropertiesFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ColladaGeoInputAttachment::editHandleProperties),
        static_cast<FieldGetMethodSig >(&ColladaGeoInputAttachment::getHandleProperties));

    oType.addInitialDesc(pDesc);

    pDesc = new MFUnrecChildGeoIntegralPropertyPtr::Description(
        MFUnrecChildGeoIntegralPropertyPtr::getClassType(),
        "propIndices",
        "Indices corresponding to the inputs, in the order they are present in the Collada Geometry.\n",
        PropIndicesFieldId, PropIndicesFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ColladaGeoInputAttachment::editHandlePropIndices),
        static_cast<FieldGetMethodSig >(&ColladaGeoInputAttachment::getHandlePropIndices));

    oType.addInitialDesc(pDesc);
}


ColladaGeoInputAttachmentBase::TypeObject ColladaGeoInputAttachmentBase::_type(
    ColladaGeoInputAttachmentBase::getClassname(),
    Inherited::getClassname(),
    "ColladaGeoInputAttachment",
    0,
    reinterpret_cast<PrototypeCreateF>(&ColladaGeoInputAttachmentBase::createEmptyLocal),
    ColladaGeoInputAttachment::initMethod,
    ColladaGeoInputAttachment::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&ColladaGeoInputAttachment::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "    name=\"ColladaGeoInputAttachment\"\n"
    "    parent=\"Attachment\"\n"
    "    library=\"FileIO\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "    structure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    ">\n"
    "Attachment that stores information about the inputs of a Collada geometry. This\n"
    "can be used to access inputs that are not consumed by the geometry or its material, e.g.\n"
    "to access texture coordinates when the material does not specify a texture.\n"
    "    <Field\n"
    "        name=\"semantics\"\n"
    "        type=\"std::string\"\n"
    "        cardinality=\"multi\"\n"
    "        visibility=\"external\"\n"
    "        access=\"public\"\n"
    "        defaultValue=\"\"\n"
    "    >\n"
    "    Semantics of the inputs, in the order they are present in the Collada Geometry.\n"
    "    </Field>\n"
    "    <Field\n"
    "        name=\"sets\"\n"
    "        type=\"Int32\"\n"
    "        cardinality=\"multi\"\n"
    "        visibility=\"external\"\n"
    "        access=\"public\"\n"
    "        defaultValue=\"\"\n"
    "    >\n"
    "    Sets of the inputs, in the order they are present in the Collada Geometry.\n"
    "    </Field>\n"
    "    <Field\n"
    "        name=\"properties\"\n"
    "        type=\"GeoVectorProperty\"\n"
    "        cardinality=\"multi\"\n"
    "        visibility=\"external\"\n"
    "        access=\"public\"\n"
    "        category=\"childpointer\"\n"
    "        childParentType=\"FieldContainer\"\n"
    "        linkParentField=\"Parents\"\n"
    "    >\n"
    "    Properties corresponding to the inputs, in the order they are present in the Collada Geometry.\n"
    "    </Field>\n"
    "    <Field\n"
    "        name=\"propIndices\"\n"
    "        type=\"GeoIntegralProperty\"\n"
    "        cardinality=\"multi\"\n"
    "        visibility=\"external\"\n"
    "        access=\"public\"\n"
    "        category=\"childpointer\"\n"
    "        childParentType=\"FieldContainer\"\n"
    "        linkParentField=\"Parents\"\n"
    "    >\n"
    "    Indices corresponding to the inputs, in the order they are present in the Collada Geometry.\n"
    "    </Field>\n"
    "</FieldContainer>\n",
    "Attachment that stores information about the inputs of a Collada geometry. This\n"
    "can be used to access inputs that are not consumed by the geometry or its material, e.g.\n"
    "to access texture coordinates when the material does not specify a texture.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &ColladaGeoInputAttachmentBase::getType(void)
{
    return _type;
}

const FieldContainerType &ColladaGeoInputAttachmentBase::getType(void) const
{
    return _type;
}

UInt32 ColladaGeoInputAttachmentBase::getContainerSize(void) const
{
    return sizeof(ColladaGeoInputAttachment);
}

/*------------------------- decorator get ------------------------------*/


MFString *ColladaGeoInputAttachmentBase::editMFSemantics(void)
{
    editMField(SemanticsFieldMask, _mfSemantics);

    return &_mfSemantics;
}

const MFString *ColladaGeoInputAttachmentBase::getMFSemantics(void) const
{
    return &_mfSemantics;
}


MFInt32 *ColladaGeoInputAttachmentBase::editMFSets(void)
{
    editMField(SetsFieldMask, _mfSets);

    return &_mfSets;
}

const MFInt32 *ColladaGeoInputAttachmentBase::getMFSets(void) const
{
    return &_mfSets;
}


//! Get the ColladaGeoInputAttachment::_mfProperties field.
const MFUnrecChildGeoVectorPropertyPtr *ColladaGeoInputAttachmentBase::getMFProperties(void) const
{
    return &_mfProperties;
}

MFUnrecChildGeoVectorPropertyPtr *ColladaGeoInputAttachmentBase::editMFProperties     (void)
{
    editMField(PropertiesFieldMask, _mfProperties);

    return &_mfProperties;
}

//! Get the ColladaGeoInputAttachment::_mfPropIndices field.
const MFUnrecChildGeoIntegralPropertyPtr *ColladaGeoInputAttachmentBase::getMFPropIndices(void) const
{
    return &_mfPropIndices;
}

MFUnrecChildGeoIntegralPropertyPtr *ColladaGeoInputAttachmentBase::editMFPropIndices    (void)
{
    editMField(PropIndicesFieldMask, _mfPropIndices);

    return &_mfPropIndices;
}



void ColladaGeoInputAttachmentBase::pushToProperties(GeoVectorProperty * const value)
{
    editMField(PropertiesFieldMask, _mfProperties);

    _mfProperties.push_back(value);
}

void ColladaGeoInputAttachmentBase::assignProperties(const MFUnrecChildGeoVectorPropertyPtr &value)
{
    MFUnrecChildGeoVectorPropertyPtr::const_iterator elemIt  =
        value.begin();
    MFUnrecChildGeoVectorPropertyPtr::const_iterator elemEnd =
        value.end  ();

    static_cast<ColladaGeoInputAttachment *>(this)->clearProperties();

    while(elemIt != elemEnd)
    {
        this->pushToProperties(*elemIt);

        ++elemIt;
    }
}

void ColladaGeoInputAttachmentBase::removeFromProperties(UInt32 uiIndex)
{
    if(uiIndex < _mfProperties.size())
    {
        editMField(PropertiesFieldMask, _mfProperties);

        _mfProperties.erase(uiIndex);
    }
}

void ColladaGeoInputAttachmentBase::removeObjFromProperties(GeoVectorProperty * const value)
{
    Int32 iElemIdx = _mfProperties.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(PropertiesFieldMask, _mfProperties);

        _mfProperties.erase(iElemIdx);
    }
}
void ColladaGeoInputAttachmentBase::clearProperties(void)
{
    editMField(PropertiesFieldMask, _mfProperties);


    _mfProperties.clear();
}

void ColladaGeoInputAttachmentBase::pushToPropIndices(GeoIntegralProperty * const value)
{
    editMField(PropIndicesFieldMask, _mfPropIndices);

    _mfPropIndices.push_back(value);
}

void ColladaGeoInputAttachmentBase::assignPropIndices(const MFUnrecChildGeoIntegralPropertyPtr &value)
{
    MFUnrecChildGeoIntegralPropertyPtr::const_iterator elemIt  =
        value.begin();
    MFUnrecChildGeoIntegralPropertyPtr::const_iterator elemEnd =
        value.end  ();

    static_cast<ColladaGeoInputAttachment *>(this)->clearPropIndices();

    while(elemIt != elemEnd)
    {
        this->pushToPropIndices(*elemIt);

        ++elemIt;
    }
}

void ColladaGeoInputAttachmentBase::removeFromPropIndices(UInt32 uiIndex)
{
    if(uiIndex < _mfPropIndices.size())
    {
        editMField(PropIndicesFieldMask, _mfPropIndices);

        _mfPropIndices.erase(uiIndex);
    }
}

void ColladaGeoInputAttachmentBase::removeObjFromPropIndices(GeoIntegralProperty * const value)
{
    Int32 iElemIdx = _mfPropIndices.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(PropIndicesFieldMask, _mfPropIndices);

        _mfPropIndices.erase(iElemIdx);
    }
}
void ColladaGeoInputAttachmentBase::clearPropIndices(void)
{
    editMField(PropIndicesFieldMask, _mfPropIndices);


    _mfPropIndices.clear();
}



/*------------------------------ access -----------------------------------*/

UInt32 ColladaGeoInputAttachmentBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (SemanticsFieldMask & whichField))
    {
        returnValue += _mfSemantics.getBinSize();
    }
    if(FieldBits::NoField != (SetsFieldMask & whichField))
    {
        returnValue += _mfSets.getBinSize();
    }
    if(FieldBits::NoField != (PropertiesFieldMask & whichField))
    {
        returnValue += _mfProperties.getBinSize();
    }
    if(FieldBits::NoField != (PropIndicesFieldMask & whichField))
    {
        returnValue += _mfPropIndices.getBinSize();
    }

    return returnValue;
}

void ColladaGeoInputAttachmentBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (SemanticsFieldMask & whichField))
    {
        _mfSemantics.copyToBin(pMem);
    }
    if(FieldBits::NoField != (SetsFieldMask & whichField))
    {
        _mfSets.copyToBin(pMem);
    }
    if(FieldBits::NoField != (PropertiesFieldMask & whichField))
    {
        _mfProperties.copyToBin(pMem);
    }
    if(FieldBits::NoField != (PropIndicesFieldMask & whichField))
    {
        _mfPropIndices.copyToBin(pMem);
    }
}

void ColladaGeoInputAttachmentBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (SemanticsFieldMask & whichField))
    {
        _mfSemantics.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (SetsFieldMask & whichField))
    {
        _mfSets.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (PropertiesFieldMask & whichField))
    {
        _mfProperties.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (PropIndicesFieldMask & whichField))
    {
        _mfPropIndices.copyFromBin(pMem);
    }
}

//! create a new instance of the class
ColladaGeoInputAttachmentTransitPtr ColladaGeoInputAttachmentBase::createLocal(BitVector bFlags)
{
    ColladaGeoInputAttachmentTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<ColladaGeoInputAttachment>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
ColladaGeoInputAttachmentTransitPtr ColladaGeoInputAttachmentBase::createDependent(BitVector bFlags)
{
    ColladaGeoInputAttachmentTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<ColladaGeoInputAttachment>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
ColladaGeoInputAttachmentTransitPtr ColladaGeoInputAttachmentBase::create(void)
{
    ColladaGeoInputAttachmentTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<ColladaGeoInputAttachment>(tmpPtr);
    }

    return fc;
}

ColladaGeoInputAttachment *ColladaGeoInputAttachmentBase::createEmptyLocal(BitVector bFlags)
{
    ColladaGeoInputAttachment *returnValue;

    newPtr<ColladaGeoInputAttachment>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
ColladaGeoInputAttachment *ColladaGeoInputAttachmentBase::createEmpty(void)
{
    ColladaGeoInputAttachment *returnValue;

    newPtr<ColladaGeoInputAttachment>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr ColladaGeoInputAttachmentBase::shallowCopyLocal(
    BitVector bFlags) const
{
    ColladaGeoInputAttachment *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ColladaGeoInputAttachment *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr ColladaGeoInputAttachmentBase::shallowCopyDependent(
    BitVector bFlags) const
{
    ColladaGeoInputAttachment *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ColladaGeoInputAttachment *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr ColladaGeoInputAttachmentBase::shallowCopy(void) const
{
    ColladaGeoInputAttachment *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const ColladaGeoInputAttachment *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

ColladaGeoInputAttachmentBase::ColladaGeoInputAttachmentBase(void) :
    Inherited(),
    _mfSemantics              (),
    _mfSets                   (),
    _mfProperties             (this,
                          PropertiesFieldId,
                          GeoVectorProperty::ParentsFieldId),
    _mfPropIndices            (this,
                          PropIndicesFieldId,
                          GeoIntegralProperty::ParentsFieldId)
{
}

ColladaGeoInputAttachmentBase::ColladaGeoInputAttachmentBase(const ColladaGeoInputAttachmentBase &source) :
    Inherited(source),
    _mfSemantics              (source._mfSemantics              ),
    _mfSets                   (source._mfSets                   ),
    _mfProperties             (this,
                          PropertiesFieldId,
                          GeoVectorProperty::ParentsFieldId),
    _mfPropIndices            (this,
                          PropIndicesFieldId,
                          GeoIntegralProperty::ParentsFieldId)
{
}


/*-------------------------- destructors ----------------------------------*/

ColladaGeoInputAttachmentBase::~ColladaGeoInputAttachmentBase(void)
{
}

/*-------------------------------------------------------------------------*/
/* Child linking                                                           */

bool ColladaGeoInputAttachmentBase::unlinkChild(
    FieldContainer * const pChild,
    UInt16           const childFieldId)
{
    if(childFieldId == PropertiesFieldId)
    {
        GeoVectorProperty * pTypedChild =
            dynamic_cast<GeoVectorProperty *>(pChild);

        if(pTypedChild != NULL)
        {
            Int32 iChildIdx = _mfProperties.findIndex(pTypedChild);

            if(iChildIdx != -1)
            {
                editMField(PropertiesFieldMask, _mfProperties);

                _mfProperties.erase(iChildIdx);

                return true;
            }

            FWARNING(("ColladaGeoInputAttachmentBase::unlinkParent: Child <-> "
                      "Parent link inconsistent.\n"));

            return false;
        }

        return false;
    }

    if(childFieldId == PropIndicesFieldId)
    {
        GeoIntegralProperty * pTypedChild =
            dynamic_cast<GeoIntegralProperty *>(pChild);

        if(pTypedChild != NULL)
        {
            Int32 iChildIdx = _mfPropIndices.findIndex(pTypedChild);

            if(iChildIdx != -1)
            {
                editMField(PropIndicesFieldMask, _mfPropIndices);

                _mfPropIndices.erase(iChildIdx);

                return true;
            }

            FWARNING(("ColladaGeoInputAttachmentBase::unlinkParent: Child <-> "
                      "Parent link inconsistent.\n"));

            return false;
        }

        return false;
    }


    return Inherited::unlinkChild(pChild, childFieldId);
}

void ColladaGeoInputAttachmentBase::onCreate(const ColladaGeoInputAttachment *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        ColladaGeoInputAttachment *pThis = static_cast<ColladaGeoInputAttachment *>(this);

        MFUnrecChildGeoVectorPropertyPtr::const_iterator PropertiesIt  =
            source->_mfProperties.begin();
        MFUnrecChildGeoVectorPropertyPtr::const_iterator PropertiesEnd =
            source->_mfProperties.end  ();

        while(PropertiesIt != PropertiesEnd)
        {
            pThis->pushToProperties(*PropertiesIt);

            ++PropertiesIt;
        }

        MFUnrecChildGeoIntegralPropertyPtr::const_iterator PropIndicesIt  =
            source->_mfPropIndices.begin();
        MFUnrecChildGeoIntegralPropertyPtr::const_iterator PropIndicesEnd =
            source->_mfPropIndices.end  ();

        while(PropIndicesIt != PropIndicesEnd)
        {
            pThis->pushToPropIndices(*PropIndicesIt);

            ++PropIndicesIt;
        }
    }
}

GetFieldHandlePtr ColladaGeoInputAttachmentBase::getHandleSemantics       (void) const
{
    MFString::GetHandlePtr returnValue(
        new  MFString::GetHandle(
             &_mfSemantics,
             this->getType().getFieldDesc(SemanticsFieldId),
             const_cast<ColladaGeoInputAttachmentBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ColladaGeoInputAttachmentBase::editHandleSemantics      (void)
{
    MFString::EditHandlePtr returnValue(
        new  MFString::EditHandle(
             &_mfSemantics,
             this->getType().getFieldDesc(SemanticsFieldId),
             this));


    editMField(SemanticsFieldMask, _mfSemantics);

    return returnValue;
}

GetFieldHandlePtr ColladaGeoInputAttachmentBase::getHandleSets            (void) const
{
    MFInt32::GetHandlePtr returnValue(
        new  MFInt32::GetHandle(
             &_mfSets,
             this->getType().getFieldDesc(SetsFieldId),
             const_cast<ColladaGeoInputAttachmentBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ColladaGeoInputAttachmentBase::editHandleSets           (void)
{
    MFInt32::EditHandlePtr returnValue(
        new  MFInt32::EditHandle(
             &_mfSets,
             this->getType().getFieldDesc(SetsFieldId),
             this));


    editMField(SetsFieldMask, _mfSets);

    return returnValue;
}

GetFieldHandlePtr ColladaGeoInputAttachmentBase::getHandleProperties      (void) const
{
    MFUnrecChildGeoVectorPropertyPtr::GetHandlePtr returnValue(
        new  MFUnrecChildGeoVectorPropertyPtr::GetHandle(
             &_mfProperties,
             this->getType().getFieldDesc(PropertiesFieldId),
             const_cast<ColladaGeoInputAttachmentBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ColladaGeoInputAttachmentBase::editHandleProperties     (void)
{
    MFUnrecChildGeoVectorPropertyPtr::EditHandlePtr returnValue(
        new  MFUnrecChildGeoVectorPropertyPtr::EditHandle(
             &_mfProperties,
             this->getType().getFieldDesc(PropertiesFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&ColladaGeoInputAttachment::pushToProperties,
                    static_cast<ColladaGeoInputAttachment *>(this), _1));
    returnValue->setRemoveMethod(
        boost::bind(&ColladaGeoInputAttachment::removeFromProperties,
                    static_cast<ColladaGeoInputAttachment *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&ColladaGeoInputAttachment::removeObjFromProperties,
                    static_cast<ColladaGeoInputAttachment *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&ColladaGeoInputAttachment::clearProperties,
                    static_cast<ColladaGeoInputAttachment *>(this)));

    editMField(PropertiesFieldMask, _mfProperties);

    return returnValue;
}

GetFieldHandlePtr ColladaGeoInputAttachmentBase::getHandlePropIndices     (void) const
{
    MFUnrecChildGeoIntegralPropertyPtr::GetHandlePtr returnValue(
        new  MFUnrecChildGeoIntegralPropertyPtr::GetHandle(
             &_mfPropIndices,
             this->getType().getFieldDesc(PropIndicesFieldId),
             const_cast<ColladaGeoInputAttachmentBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ColladaGeoInputAttachmentBase::editHandlePropIndices    (void)
{
    MFUnrecChildGeoIntegralPropertyPtr::EditHandlePtr returnValue(
        new  MFUnrecChildGeoIntegralPropertyPtr::EditHandle(
             &_mfPropIndices,
             this->getType().getFieldDesc(PropIndicesFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&ColladaGeoInputAttachment::pushToPropIndices,
                    static_cast<ColladaGeoInputAttachment *>(this), _1));
    returnValue->setRemoveMethod(
        boost::bind(&ColladaGeoInputAttachment::removeFromPropIndices,
                    static_cast<ColladaGeoInputAttachment *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&ColladaGeoInputAttachment::removeObjFromPropIndices,
                    static_cast<ColladaGeoInputAttachment *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&ColladaGeoInputAttachment::clearPropIndices,
                    static_cast<ColladaGeoInputAttachment *>(this)));

    editMField(PropIndicesFieldMask, _mfPropIndices);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void ColladaGeoInputAttachmentBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    ColladaGeoInputAttachment *pThis = static_cast<ColladaGeoInputAttachment *>(this);

    pThis->execSync(static_cast<ColladaGeoInputAttachment *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *ColladaGeoInputAttachmentBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    ColladaGeoInputAttachment *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const ColladaGeoInputAttachment *>(pRefAspect),
                  dynamic_cast<const ColladaGeoInputAttachment *>(this));

    return returnValue;
}
#endif

void ColladaGeoInputAttachmentBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<ColladaGeoInputAttachment *>(this)->clearProperties();

    static_cast<ColladaGeoInputAttachment *>(this)->clearPropIndices();

#ifdef OSG_MT_CPTR_ASPECT
    AspectOffsetStore oOffsets;

    _pAspectStore->fillOffsetArray(oOffsets, this);
#endif

#ifdef OSG_MT_CPTR_ASPECT
    _mfSemantics.terminateShare(Thread::getCurrentAspect(),
                                      oOffsets);
#endif
#ifdef OSG_MT_CPTR_ASPECT
    _mfSets.terminateShare(Thread::getCurrentAspect(),
                                      oOffsets);
#endif
}


OSG_END_NAMESPACE
