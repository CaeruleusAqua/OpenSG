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
 **     class Geometry!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGGeoIntegralProperty.h"     // Types Class
#include "OSGGeoVectorProperty.h"       // Properties Class

#include "OSGGeometryBase.h"
#include "OSGGeometry.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::Geometry
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var GeoIntegralProperty * GeometryBase::_sfTypes
    The types property contains the primitive's types. Legal values are 
    everything that can be passed to glBegin(). There have to be as many 
    types as lengths.
*/

/*! \var GeoIntegralProperty * GeometryBase::_sfLengths
    The lengths property contains the number of vertices to use for the 
    corresponding primitive. There have to be as many  lengths as types.
*/

/*! \var GeoVectorProperty * GeometryBase::_mfProperties
    The attributes used to render the geometry. The order is based on the 
    the one given in ARB_vertex_program.
*/

/*! \var GeoIntegralProperty * GeometryBase::_mfPropIndices
    The indices property contains the index data. See \ref 
    PageSystemGeoIndexing for a description of the indexing options.
*/

/*! \var bool            GeometryBase::_sfDlistCache
    Flag to activate caching the geometry inside a display list.
*/

/*! \var Int32           GeometryBase::_sfClassicGLId
    The dlist id for the classic rendering mode, if used.
*/

/*! \var Int32           GeometryBase::_sfAttGLId
    The dlist id for the attribute-based rendering mode, if used.
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<Geometry *>::_type("GeometryPtr", "MaterialDrawablePtr");
#endif

OSG_FIELDTRAITS_GETTYPE(Geometry *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           Geometry *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           Geometry *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void GeometryBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecChildGeoIntegralPropertyPtr::Description(
        SFUnrecChildGeoIntegralPropertyPtr::getClassType(),
        "types",
        "The types property contains the primitive's types. Legal values are \n"
        "everything that can be passed to glBegin(). There have to be as many \n"
        "types as lengths.\n",
        TypesFieldId, TypesFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Geometry::editHandleTypes),
        static_cast<FieldGetMethodSig >(&Geometry::getHandleTypes));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecChildGeoIntegralPropertyPtr::Description(
        SFUnrecChildGeoIntegralPropertyPtr::getClassType(),
        "lengths",
        "The lengths property contains the number of vertices to use for the \n"
        "corresponding primitive. There have to be as many  lengths as types.\n",
        LengthsFieldId, LengthsFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Geometry::editHandleLengths),
        static_cast<FieldGetMethodSig >(&Geometry::getHandleLengths));

    oType.addInitialDesc(pDesc);

    pDesc = new MFUnrecChildGeoVectorPropertyPtr::Description(
        MFUnrecChildGeoVectorPropertyPtr::getClassType(),
        "properties",
        "The attributes used to render the geometry. The order is based on the \n"
        "the one given in ARB_vertex_program.\n",
        PropertiesFieldId, PropertiesFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Geometry::editHandleProperties),
        static_cast<FieldGetMethodSig >(&Geometry::getHandleProperties));

    oType.addInitialDesc(pDesc);

    pDesc = new MFUnrecChildGeoIntegralPropertyPtr::Description(
        MFUnrecChildGeoIntegralPropertyPtr::getClassType(),
        "propIndices",
        "The indices property contains the index data. See \\ref \n"
        "PageSystemGeoIndexing for a description of the indexing options.\n",
        PropIndicesFieldId, PropIndicesFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Geometry::editHandlePropIndices),
        static_cast<FieldGetMethodSig >(&Geometry::getHandlePropIndices));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "dlistCache",
        "Flag to activate caching the geometry inside a display list.\n",
        DlistCacheFieldId, DlistCacheFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Geometry::editHandleDlistCache),
        static_cast<FieldGetMethodSig >(&Geometry::getHandleDlistCache));

    oType.addInitialDesc(pDesc);

    pDesc = new SFInt32::Description(
        SFInt32::getClassType(),
        "classicGLId",
        "The dlist id for the classic rendering mode, if used.\n",
        ClassicGLIdFieldId, ClassicGLIdFieldMask,
        true,
        (Field::FClusterLocal),
        static_cast<FieldEditMethodSig>(&Geometry::editHandleClassicGLId),
        static_cast<FieldGetMethodSig >(&Geometry::getHandleClassicGLId));

    oType.addInitialDesc(pDesc);

    pDesc = new SFInt32::Description(
        SFInt32::getClassType(),
        "attGLId",
        "The dlist id for the attribute-based rendering mode, if used.\n",
        AttGLIdFieldId, AttGLIdFieldMask,
        true,
        (Field::FClusterLocal),
        static_cast<FieldEditMethodSig>(&Geometry::editHandleAttGLId),
        static_cast<FieldGetMethodSig >(&Geometry::getHandleAttGLId));

    oType.addInitialDesc(pDesc);
}


GeometryBase::TypeObject GeometryBase::_type(
    GeometryBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&GeometryBase::createEmptyLocal),
    Geometry::initMethod,
    Geometry::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&Geometry::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"Geometry\"\n"
    "\tparent=\"MaterialDrawable\"\n"
    "\tlibrary=\"Drawable\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "    isNodeCore=\"true\"\n"
    ">\n"
    "\t<Field\n"
    "\t\tname=\"types\"\n"
    "\t\ttype=\"GeoIntegralProperty\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "        category=\"childpointer\"\n"
    "        childParentType=\"FieldContainer\"\n"
    "        linkParentField=\"Parents\"\n"
    "\t>\n"
    "        The types property contains the primitive's types. Legal values are \n"
    "        everything that can be passed to glBegin(). There have to be as many \n"
    "        types as lengths.\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"lengths\"\n"
    "\t\ttype=\"GeoIntegralProperty\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "        category=\"childpointer\"\n"
    "        childParentType=\"FieldContainer\"\n"
    "        linkParentField=\"Parents\"\n"
    "\t>\n"
    "        The lengths property contains the number of vertices to use for the \n"
    "        corresponding primitive. There have to be as many  lengths as types.\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"properties\"\n"
    "\t\ttype=\"GeoVectorProperty\"\n"
    "\t\tcardinality=\"multi\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "        category=\"childpointer\"\n"
    "        childParentType=\"FieldContainer\"\n"
    "        linkParentField=\"Parents\"\n"
    "\t>\n"
    "        The attributes used to render the geometry. The order is based on the \n"
    "        the one given in ARB_vertex_program.\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"propIndices\"\n"
    "\t\ttype=\"GeoIntegralProperty\"\n"
    "\t\tcardinality=\"multi\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "        category=\"childpointer\"\n"
    "        childParentType=\"FieldContainer\"\n"
    "        linkParentField=\"Parents\"\n"
    "\t>\n"
    "        The indices property contains the index data. See \\ref \n"
    "        PageSystemGeoIndexing for a description of the indexing options.\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"dlistCache\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\tFlag to activate caching the geometry inside a display list.\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"classicGLId\"\n"
    "\t\ttype=\"Int32\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\tdefaultValue=\"0\"\n"
    "\t\taccess=\"protected\"\n"
    "\t\tfieldFlags=\"FClusterLocal\"\n"
    "\t>\n"
    "\tThe dlist id for the classic rendering mode, if used.\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"attGLId\"\n"
    "\t\ttype=\"Int32\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\tdefaultValue=\"0\"\n"
    "\t\taccess=\"protected\"\n"
    "\t\tfieldFlags=\"FClusterLocal\"\n"
    "\t>\n"
    "\tThe dlist id for the attribute-based rendering mode, if used.\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &GeometryBase::getType(void)
{
    return _type;
}

const FieldContainerType &GeometryBase::getType(void) const
{
    return _type;
}

UInt32 GeometryBase::getContainerSize(void) const
{
    return sizeof(Geometry);
}

/*------------------------- decorator get ------------------------------*/


//! Get the Geometry::_sfTypes field.
const SFUnrecChildGeoIntegralPropertyPtr *GeometryBase::getSFTypes(void) const
{
    return &_sfTypes;
}

SFUnrecChildGeoIntegralPropertyPtr *GeometryBase::editSFTypes          (void)
{
    editSField(TypesFieldMask);

    return &_sfTypes;
}

//! Get the Geometry::_sfLengths field.
const SFUnrecChildGeoIntegralPropertyPtr *GeometryBase::getSFLengths(void) const
{
    return &_sfLengths;
}

SFUnrecChildGeoIntegralPropertyPtr *GeometryBase::editSFLengths        (void)
{
    editSField(LengthsFieldMask);

    return &_sfLengths;
}

//! Get the Geometry::_mfProperties field.
const MFUnrecChildGeoVectorPropertyPtr *GeometryBase::getMFProperties(void) const
{
    return &_mfProperties;
}

MFUnrecChildGeoVectorPropertyPtr *GeometryBase::editMFProperties     (void)
{
    editMField(PropertiesFieldMask, _mfProperties);

    return &_mfProperties;
}

//! Get the Geometry::_mfPropIndices field.
const MFUnrecChildGeoIntegralPropertyPtr *GeometryBase::getMFPropIndices(void) const
{
    return &_mfPropIndices;
}

MFUnrecChildGeoIntegralPropertyPtr *GeometryBase::editMFPropIndices    (void)
{
    editMField(PropIndicesFieldMask, _mfPropIndices);

    return &_mfPropIndices;
}

SFBool *GeometryBase::editSFDlistCache(void)
{
    editSField(DlistCacheFieldMask);

    return &_sfDlistCache;
}

const SFBool *GeometryBase::getSFDlistCache(void) const
{
    return &_sfDlistCache;
}


SFInt32 *GeometryBase::editSFClassicGLId(void)
{
    editSField(ClassicGLIdFieldMask);

    return &_sfClassicGLId;
}

const SFInt32 *GeometryBase::getSFClassicGLId(void) const
{
    return &_sfClassicGLId;
}


SFInt32 *GeometryBase::editSFAttGLId(void)
{
    editSField(AttGLIdFieldMask);

    return &_sfAttGLId;
}

const SFInt32 *GeometryBase::getSFAttGLId(void) const
{
    return &_sfAttGLId;
}




void GeometryBase::pushToProperties(GeoVectorProperty * const value)
{
    editMField(PropertiesFieldMask, _mfProperties);

    _mfProperties.push_back(value);
}

void GeometryBase::assignProperties(const MFUnrecChildGeoVectorPropertyPtr &value)
{
    MFUnrecChildGeoVectorPropertyPtr::const_iterator elemIt  =
        value.begin();
    MFUnrecChildGeoVectorPropertyPtr::const_iterator elemEnd =
        value.end  ();

    static_cast<Geometry *>(this)->clearProperties();

    while(elemIt != elemEnd)
    {
        this->pushToProperties(*elemIt);

        ++elemIt;
    }
}

void GeometryBase::removeFromProperties(UInt32 uiIndex)
{
    if(uiIndex < _mfProperties.size())
    {
        editMField(PropertiesFieldMask, _mfProperties);

        _mfProperties.erase(uiIndex);
    }
}

void GeometryBase::removeObjFromProperties(GeoVectorProperty * const value)
{
    Int32 iElemIdx = _mfProperties.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(PropertiesFieldMask, _mfProperties);

        _mfProperties.erase(iElemIdx);
    }
}
void GeometryBase::clearProperties(void)
{
    editMField(PropertiesFieldMask, _mfProperties);


    _mfProperties.clear();
}

void GeometryBase::pushToPropIndices(GeoIntegralProperty * const value)
{
    editMField(PropIndicesFieldMask, _mfPropIndices);

    _mfPropIndices.push_back(value);
}

void GeometryBase::assignPropIndices(const MFUnrecChildGeoIntegralPropertyPtr &value)
{
    MFUnrecChildGeoIntegralPropertyPtr::const_iterator elemIt  =
        value.begin();
    MFUnrecChildGeoIntegralPropertyPtr::const_iterator elemEnd =
        value.end  ();

    static_cast<Geometry *>(this)->clearPropIndices();

    while(elemIt != elemEnd)
    {
        this->pushToPropIndices(*elemIt);

        ++elemIt;
    }
}

void GeometryBase::removeFromPropIndices(UInt32 uiIndex)
{
    if(uiIndex < _mfPropIndices.size())
    {
        editMField(PropIndicesFieldMask, _mfPropIndices);

        _mfPropIndices.erase(uiIndex);
    }
}

void GeometryBase::removeObjFromPropIndices(GeoIntegralProperty * const value)
{
    Int32 iElemIdx = _mfPropIndices.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(PropIndicesFieldMask, _mfPropIndices);

        _mfPropIndices.erase(iElemIdx);
    }
}
void GeometryBase::clearPropIndices(void)
{
    editMField(PropIndicesFieldMask, _mfPropIndices);


    _mfPropIndices.clear();
}



/*------------------------------ access -----------------------------------*/

UInt32 GeometryBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (TypesFieldMask & whichField))
    {
        returnValue += _sfTypes.getBinSize();
    }
    if(FieldBits::NoField != (LengthsFieldMask & whichField))
    {
        returnValue += _sfLengths.getBinSize();
    }
    if(FieldBits::NoField != (PropertiesFieldMask & whichField))
    {
        returnValue += _mfProperties.getBinSize();
    }
    if(FieldBits::NoField != (PropIndicesFieldMask & whichField))
    {
        returnValue += _mfPropIndices.getBinSize();
    }
    if(FieldBits::NoField != (DlistCacheFieldMask & whichField))
    {
        returnValue += _sfDlistCache.getBinSize();
    }
    if(FieldBits::NoField != (ClassicGLIdFieldMask & whichField))
    {
        returnValue += _sfClassicGLId.getBinSize();
    }
    if(FieldBits::NoField != (AttGLIdFieldMask & whichField))
    {
        returnValue += _sfAttGLId.getBinSize();
    }

    return returnValue;
}

void GeometryBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (TypesFieldMask & whichField))
    {
        _sfTypes.copyToBin(pMem);
    }
    if(FieldBits::NoField != (LengthsFieldMask & whichField))
    {
        _sfLengths.copyToBin(pMem);
    }
    if(FieldBits::NoField != (PropertiesFieldMask & whichField))
    {
        _mfProperties.copyToBin(pMem);
    }
    if(FieldBits::NoField != (PropIndicesFieldMask & whichField))
    {
        _mfPropIndices.copyToBin(pMem);
    }
    if(FieldBits::NoField != (DlistCacheFieldMask & whichField))
    {
        _sfDlistCache.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ClassicGLIdFieldMask & whichField))
    {
        _sfClassicGLId.copyToBin(pMem);
    }
    if(FieldBits::NoField != (AttGLIdFieldMask & whichField))
    {
        _sfAttGLId.copyToBin(pMem);
    }
}

void GeometryBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (TypesFieldMask & whichField))
    {
        _sfTypes.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (LengthsFieldMask & whichField))
    {
        _sfLengths.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (PropertiesFieldMask & whichField))
    {
        _mfProperties.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (PropIndicesFieldMask & whichField))
    {
        _mfPropIndices.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (DlistCacheFieldMask & whichField))
    {
        _sfDlistCache.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ClassicGLIdFieldMask & whichField))
    {
        _sfClassicGLId.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (AttGLIdFieldMask & whichField))
    {
        _sfAttGLId.copyFromBin(pMem);
    }
}

//! create a new instance of the class
GeometryTransitPtr GeometryBase::createLocal(BitVector bFlags)
{
    GeometryTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<Geometry>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
GeometryTransitPtr GeometryBase::createDependent(BitVector bFlags)
{
    GeometryTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<Geometry>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
GeometryTransitPtr GeometryBase::create(void)
{
    GeometryTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<Geometry>(tmpPtr);
    }

    return fc;
}

Geometry *GeometryBase::createEmptyLocal(BitVector bFlags)
{
    Geometry *returnValue;

    newPtr<Geometry>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
Geometry *GeometryBase::createEmpty(void)
{
    Geometry *returnValue;

    newPtr<Geometry>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr GeometryBase::shallowCopyLocal(
    BitVector bFlags) const
{
    Geometry *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const Geometry *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr GeometryBase::shallowCopyDependent(
    BitVector bFlags) const
{
    Geometry *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const Geometry *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr GeometryBase::shallowCopy(void) const
{
    Geometry *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const Geometry *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

GeometryBase::GeometryBase(void) :
    Inherited(),
    _sfTypes                  (this,
                          TypesFieldId,
                          GeoIntegralProperty::ParentsFieldId),
    _sfLengths                (this,
                          LengthsFieldId,
                          GeoIntegralProperty::ParentsFieldId),
    _mfProperties             (this,
                          PropertiesFieldId,
                          GeoVectorProperty::ParentsFieldId),
    _mfPropIndices            (this,
                          PropIndicesFieldId,
                          GeoIntegralProperty::ParentsFieldId),
    _sfDlistCache             (bool(true)),
    _sfClassicGLId            (Int32(0)),
    _sfAttGLId                (Int32(0))
{
}

GeometryBase::GeometryBase(const GeometryBase &source) :
    Inherited(source),
    _sfTypes                  (this,
                          TypesFieldId,
                          GeoIntegralProperty::ParentsFieldId),
    _sfLengths                (this,
                          LengthsFieldId,
                          GeoIntegralProperty::ParentsFieldId),
    _mfProperties             (this,
                          PropertiesFieldId,
                          GeoVectorProperty::ParentsFieldId),
    _mfPropIndices            (this,
                          PropIndicesFieldId,
                          GeoIntegralProperty::ParentsFieldId),
    _sfDlistCache             (source._sfDlistCache             ),
    _sfClassicGLId            (source._sfClassicGLId            ),
    _sfAttGLId                (source._sfAttGLId                )
{
}


/*-------------------------- destructors ----------------------------------*/

GeometryBase::~GeometryBase(void)
{
}

/*-------------------------------------------------------------------------*/
/* Child linking                                                           */

bool GeometryBase::unlinkChild(
    FieldContainer * const pChild,
    UInt16           const childFieldId)
{
    if(childFieldId == TypesFieldId)
    {
        GeoIntegralProperty * pTypedChild =
            dynamic_cast<GeoIntegralProperty *>(pChild);

        if(pTypedChild != NULL)
        {
            if(pTypedChild == _sfTypes.getValue())
            {
                editSField(TypesFieldMask);

                _sfTypes.setValue(NULL);

                return true;
            }

            FWARNING(("GeometryBase::unlinkParent: Child <-> "
                      "Parent link inconsistent.\n"));

            return false;
        }

        return false;
    }

    if(childFieldId == LengthsFieldId)
    {
        GeoIntegralProperty * pTypedChild =
            dynamic_cast<GeoIntegralProperty *>(pChild);

        if(pTypedChild != NULL)
        {
            if(pTypedChild == _sfLengths.getValue())
            {
                editSField(LengthsFieldMask);

                _sfLengths.setValue(NULL);

                return true;
            }

            FWARNING(("GeometryBase::unlinkParent: Child <-> "
                      "Parent link inconsistent.\n"));

            return false;
        }

        return false;
    }

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

            FWARNING(("GeometryBase::unlinkParent: Child <-> "
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

            FWARNING(("GeometryBase::unlinkParent: Child <-> "
                      "Parent link inconsistent.\n"));

            return false;
        }

        return false;
    }


    return Inherited::unlinkChild(pChild, childFieldId);
}

void GeometryBase::onCreate(const Geometry *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        Geometry *pThis = static_cast<Geometry *>(this);

        pThis->setTypes(source->getTypes());

        pThis->setLengths(source->getLengths());

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

GetFieldHandlePtr GeometryBase::getHandleTypes           (void) const
{
    SFUnrecChildGeoIntegralPropertyPtr::GetHandlePtr returnValue(
        new  SFUnrecChildGeoIntegralPropertyPtr::GetHandle(
             &_sfTypes,
             this->getType().getFieldDesc(TypesFieldId),
             const_cast<GeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GeometryBase::editHandleTypes          (void)
{
    SFUnrecChildGeoIntegralPropertyPtr::EditHandlePtr returnValue(
        new  SFUnrecChildGeoIntegralPropertyPtr::EditHandle(
             &_sfTypes,
             this->getType().getFieldDesc(TypesFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&Geometry::setTypes,
                    static_cast<Geometry *>(this), _1));

    editSField(TypesFieldMask);

    return returnValue;
}

GetFieldHandlePtr GeometryBase::getHandleLengths         (void) const
{
    SFUnrecChildGeoIntegralPropertyPtr::GetHandlePtr returnValue(
        new  SFUnrecChildGeoIntegralPropertyPtr::GetHandle(
             &_sfLengths,
             this->getType().getFieldDesc(LengthsFieldId),
             const_cast<GeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GeometryBase::editHandleLengths        (void)
{
    SFUnrecChildGeoIntegralPropertyPtr::EditHandlePtr returnValue(
        new  SFUnrecChildGeoIntegralPropertyPtr::EditHandle(
             &_sfLengths,
             this->getType().getFieldDesc(LengthsFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&Geometry::setLengths,
                    static_cast<Geometry *>(this), _1));

    editSField(LengthsFieldMask);

    return returnValue;
}

GetFieldHandlePtr GeometryBase::getHandleProperties      (void) const
{
    MFUnrecChildGeoVectorPropertyPtr::GetHandlePtr returnValue(
        new  MFUnrecChildGeoVectorPropertyPtr::GetHandle(
             &_mfProperties,
             this->getType().getFieldDesc(PropertiesFieldId),
             const_cast<GeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GeometryBase::editHandleProperties     (void)
{
    MFUnrecChildGeoVectorPropertyPtr::EditHandlePtr returnValue(
        new  MFUnrecChildGeoVectorPropertyPtr::EditHandle(
             &_mfProperties,
             this->getType().getFieldDesc(PropertiesFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&Geometry::pushToProperties,
                    static_cast<Geometry *>(this), _1));
    returnValue->setRemoveMethod(
        boost::bind(&Geometry::removeFromProperties,
                    static_cast<Geometry *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&Geometry::removeObjFromProperties,
                    static_cast<Geometry *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&Geometry::clearProperties,
                    static_cast<Geometry *>(this)));

    editMField(PropertiesFieldMask, _mfProperties);

    return returnValue;
}

GetFieldHandlePtr GeometryBase::getHandlePropIndices     (void) const
{
    MFUnrecChildGeoIntegralPropertyPtr::GetHandlePtr returnValue(
        new  MFUnrecChildGeoIntegralPropertyPtr::GetHandle(
             &_mfPropIndices,
             this->getType().getFieldDesc(PropIndicesFieldId),
             const_cast<GeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GeometryBase::editHandlePropIndices    (void)
{
    MFUnrecChildGeoIntegralPropertyPtr::EditHandlePtr returnValue(
        new  MFUnrecChildGeoIntegralPropertyPtr::EditHandle(
             &_mfPropIndices,
             this->getType().getFieldDesc(PropIndicesFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&Geometry::pushToPropIndices,
                    static_cast<Geometry *>(this), _1));
    returnValue->setRemoveMethod(
        boost::bind(&Geometry::removeFromPropIndices,
                    static_cast<Geometry *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&Geometry::removeObjFromPropIndices,
                    static_cast<Geometry *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&Geometry::clearPropIndices,
                    static_cast<Geometry *>(this)));

    editMField(PropIndicesFieldMask, _mfPropIndices);

    return returnValue;
}

GetFieldHandlePtr GeometryBase::getHandleDlistCache      (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfDlistCache,
             this->getType().getFieldDesc(DlistCacheFieldId),
             const_cast<GeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GeometryBase::editHandleDlistCache     (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfDlistCache,
             this->getType().getFieldDesc(DlistCacheFieldId),
             this));


    editSField(DlistCacheFieldMask);

    return returnValue;
}

GetFieldHandlePtr GeometryBase::getHandleClassicGLId     (void) const
{
    SFInt32::GetHandlePtr returnValue(
        new  SFInt32::GetHandle(
             &_sfClassicGLId,
             this->getType().getFieldDesc(ClassicGLIdFieldId),
             const_cast<GeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GeometryBase::editHandleClassicGLId    (void)
{
    SFInt32::EditHandlePtr returnValue(
        new  SFInt32::EditHandle(
             &_sfClassicGLId,
             this->getType().getFieldDesc(ClassicGLIdFieldId),
             this));


    editSField(ClassicGLIdFieldMask);

    return returnValue;
}

GetFieldHandlePtr GeometryBase::getHandleAttGLId         (void) const
{
    SFInt32::GetHandlePtr returnValue(
        new  SFInt32::GetHandle(
             &_sfAttGLId,
             this->getType().getFieldDesc(AttGLIdFieldId),
             const_cast<GeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr GeometryBase::editHandleAttGLId        (void)
{
    SFInt32::EditHandlePtr returnValue(
        new  SFInt32::EditHandle(
             &_sfAttGLId,
             this->getType().getFieldDesc(AttGLIdFieldId),
             this));


    editSField(AttGLIdFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void GeometryBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Geometry *pThis = static_cast<Geometry *>(this);

    pThis->execSync(static_cast<Geometry *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *GeometryBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    Geometry *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const Geometry *>(pRefAspect),
                  dynamic_cast<const Geometry *>(this));

    return returnValue;
}
#endif

void GeometryBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<Geometry *>(this)->setTypes(NULL);

    static_cast<Geometry *>(this)->setLengths(NULL);

    static_cast<Geometry *>(this)->clearProperties();

    static_cast<Geometry *>(this)->clearPropIndices();


}


OSG_END_NAMESPACE
