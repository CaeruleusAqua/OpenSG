/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *                   Copyright (C) 2006 by the OpenSG Forum                  *
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

#include "OSGOSBGeometryElement.h"

#include "OSGOSBGeometryHelper.h"
#include "OSGOSBRootElement.h"
#include "OSGOSBGeoIntegralPropertyElement.h"
#include "OSGOSBGeoVectorPropertyElement.h"
#include "OSGTypedGeoIntegralProperty.h"
#include "OSGGeometry.h"

OSG_USING_NAMESPACE

/*-------------------------------------------------------------------------*/
/* OSBGeometryElement                                                     */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/* Static members                                                          */

OSBElementRegistrationHelper<OSBGeometryElement>
    OSBGeometryElement::_regHelper =
        OSBElementRegistrationHelper<OSBGeometryElement>("Geometry");

/*! Constants for the OpenSG 1.x index mapping.
    These values must match those used in the OpenSG 1.x Geometry class.
 */
const UInt16 OSBGeometryElement::MapPosition       = 1;
const UInt16 OSBGeometryElement::MapNormal         =
    OSBGeometryElement::MapPosition << 1;
const UInt16 OSBGeometryElement::MapColor          =
    OSBGeometryElement::MapNormal << 1;
const UInt16 OSBGeometryElement::MapSecondaryColor =
    OSBGeometryElement::MapColor << 1;
const UInt16 OSBGeometryElement::MapTexCoords      =
    OSBGeometryElement::MapSecondaryColor << 1;
const UInt16 OSBGeometryElement::MapTexCoords1     =
    OSBGeometryElement::MapTexCoords << 1;
const UInt16 OSBGeometryElement::MapTexCoords2     =
    OSBGeometryElement::MapTexCoords1 << 1;
const UInt16 OSBGeometryElement::MapTexCoords3     =
    OSBGeometryElement::MapTexCoords2 << 1;
const UInt16 OSBGeometryElement::MapTexCoords4     =
    OSBGeometryElement::MapTexCoords3 << 1;
const UInt16 OSBGeometryElement::MapTexCoords5     =
    OSBGeometryElement::MapTexCoords4 << 1;
const UInt16 OSBGeometryElement::MapTexCoords6     =
    OSBGeometryElement::MapTexCoords5 << 1;
const UInt16 OSBGeometryElement::MapTexCoords7     =
    OSBGeometryElement::MapTexCoords6 << 1;
const UInt16 OSBGeometryElement::MapEmpty          =
    OSBGeometryElement::MapTexCoords7 << 1;

/*-------------------------------------------------------------------------*/
/* Constructor                                                             */

OSBGeometryElement::OSBGeometryElement(OSBRootElement *root)
    : Inherited     (root, OSGOSBHeaderVersion200),
      _indexMapping (                            ),
      _indicesId    (0                           ),
      _indices      (NullFC                      ),
      _indices16Bit (false                       ),
      _indicesPacked(false                       ),
      _version      (OSGOSBHeaderVersion200      )
{
}

/*-------------------------------------------------------------------------*/
/* Destructor                                                              */

OSBGeometryElement::~OSBGeometryElement(void)
{
}

/*-------------------------------------------------------------------------*/
/* Reading                                                                 */

void
OSBGeometryElement::read(const std::string &typeName)
{
    FDEBUG(("OSBGeometryElement::read: [%s]\n", typeName.c_str()));

    BinaryReadHandler *rh = editRoot()->getReadHandler();

    rh->getValue(_version);
    FDEBUG(("OSBGeometryElement::read: version: [%u]\n", _version));

    if(_version >= OSGOSBHeaderVersion200)
    {
        if(_version > OSGOSBHeaderVersion200)
        {
            FINFO(("OSBGeometryElement::read: "
                   "Unknown version, trying to read as latest.\n"));
        }

        setContainer(Geometry::create());
        readFields("", "");
    }
    else if(_version >= OSGOSBHeaderVersion100)
    {
        readV100();
    }
}

void
OSBGeometryElement::postRead(void)
{
    FDEBUG(("OSBGeometryElement::postRead:\n"));

    if(_version >= OSGOSBHeaderVersion200)
    {
        if(_version > OSGOSBHeaderVersion200)
        {
            FINFO(("OSBGeometryElement::postRead: "
                   "Unknown version, trying to process as latest.\n"));
        }

        // postRead v2.0 Geometry - nothing to do.
    }
    else if(_version >= OSGOSBHeaderVersion100)
    {
        postReadV100();
    }
}

/*-------------------------------------------------------------------------*/
/* Writing                                                                 */

void
OSBGeometryElement::preWrite(const FieldContainerPtr &fc)
{
    FDEBUG(("OSBGeometryElement::preWrite\n"));

    OSBRootElement *root       = editRoot();
    UInt32          fieldCount = fc->getType().getNumFieldDescs();

    UInt8 quanResPositions = root->getOptions().quantizePositions();
    UInt8 quanResNormals   = root->getOptions().quantizeNormals  ();
    UInt8 quanResTexCoords = root->getOptions().quantizeTexCoords();
    bool  packIndices      = root->getOptions().packIndices      ();

    // go through all fields and find those refering to other FCs
    for(UInt32 fieldId = 1; fieldId <= fieldCount; ++fieldId)
    {
        const FieldDescriptionBase *fieldDesc = fc->getFieldDescription(fieldId);
        const FieldType            &fieldType = fieldDesc->getFieldType();
        BitVector                   fieldMask = fieldDesc->getFieldMask();
        std::string                 fieldName = fieldDesc->getCName    ();

        // skip internal fields
        if(fieldDesc->isInternal())
        {
            FDEBUG(("OSBGeometryElement::preWrite: "
                    "Skipping internal field: [%s]\n", fieldName.c_str()));
            continue;
        }

        if(fieldName == "properties")
        {
            // "properties" might be quantized
            const MFGeoVectorPropertyPtr *field =
                static_cast<const MFGeoVectorPropertyPtr *>(
                    getContainer()->getField(fieldId));

            MFGeoVectorPropertyPtr::const_iterator fieldIt  = field->begin();
            MFGeoVectorPropertyPtr::const_iterator fieldEnd = field->end  ();

            for(UInt32 i = 0; fieldIt != fieldEnd; ++fieldIt, ++i)
            {
                FieldContainerPtr refedFC = *fieldIt;

                if(refedFC == NullFC)
                    continue;

                UInt32      refedId  = OSG::getContainerId(refedFC);
                std::string typeName = refedFC->getType().getCName();

                // only schedule a container once
                if(root->getIdSet().count(refedId) > 0)
                    continue;

                OSBElementBase              *elem     =
                    OSBElementFactory::the()->acquire(typeName, root);
                OSBGeoVectorPropertyElement *propElem =
                    dynamic_cast<OSBGeoVectorPropertyElement *>(elem);

                if((propElem != 0) && (i == Geometry::PositionsIndex))
                {
                    propElem->setQuantizeResolution(quanResPositions);
                }
                else if((propElem != 0) && (i == Geometry::NormalsIndex))
                {
                    propElem->setQuantizeResolution(quanResNormals);
                }
                else if((propElem != 0) && (i >= Geometry::TexCoordsIndex) &&
                        (i <= Geometry::TexCoords7Index)                     )
                {
                    propElem->setQuantizeResolution(quanResTexCoords);
                }

                root->editIdSet      ().insert   (refedId);
                root->editElementList().push_back(elem   );
                elem->setContainer(refedFC);
                elem->preWrite    (refedFC);
            }
        }
        else if(fieldName == "propIndices")
        {
            // "propIndices" might be packed
            const MFGeoIntegralPropertyPtr *field =
                static_cast<const MFGeoIntegralPropertyPtr *>(
                    getContainer()->getField(fieldId));

            MFGeoIntegralPropertyPtr::const_iterator fieldIt  = field->begin();
            MFGeoIntegralPropertyPtr::const_iterator fieldEnd = field->end  ();

            for(UInt32 i = 0; fieldIt != fieldEnd; ++fieldIt, ++i)
            {
                FieldContainerPtr refedFC = *fieldIt;

                if(refedFC == NullFC)
                    continue;

                UInt32      refedId  = OSG::getContainerId(refedFC);
                std::string typeName = refedFC->getType().getCName();

                // only schedule a container once
                if(root->getIdSet().count(refedId) > 0)
                    continue;

                OSBElementBase                *elem     =
                    OSBElementFactory::the()->acquire(typeName, root);
                OSBGeoIntegralPropertyElement *propElem =
                    dynamic_cast<OSBGeoIntegralPropertyElement *>(elem);

                if((propElem != 0) && (packIndices == true))
                {
                    propElem->setPackData(true);
                }

                root->editIdSet      ().insert   (refedId);
                root->editElementList().push_back(elem   );
                elem->setContainer(refedFC);
                elem->preWrite    (refedFC);
            }
        }
        else
        {
            // check if field refers to another FC, i.e. its a field holding
            // FieldContainerPtr or an FieldContainerAttachmentMap
            if(fieldType.getContentType().isDerivedFrom(
                FieldTraits<FieldContainerPtr>::getType()) == true)
            {
                if(fieldType.getCardinality() == FieldType::SINGLE_FIELD)
                {
                    preWritePtrSingleField(fieldId);
                }
                else if(fieldType.getCardinality() == FieldType::MULTI_FIELD)
                {
                    preWritePtrMultiField(fieldId);
                }
            }
            else if(fieldType.getContentType().isDerivedFrom(
                FieldTraits<FieldContainerAttachmentMap>::getType()) == true)
            {
                preWriteAttachmentMapField(fieldId);
            }
        }
    }
}

void
OSBGeometryElement::write(void)
{
    FDEBUG(("OSBGeometryElement::write\n"));

    BinaryWriteHandler *wh = editRoot()->getWriteHandler();

//    wh->putValue(getFCPtrType(getContainer()));
    wh->putValue(getVersion());

    writeFields("", true);
}

/*-------------------------------------------------------------------------*/
/* Reading Helper Functions                                                */

void
OSBGeometryElement::readV100(void)
{
    FDEBUG(("OSBGeometryElement::readV100:\n"));

    OSBRootElement    *root = editRoot();
    BinaryReadHandler *rh   = editRoot()->getReadHandler();
    OSBGeometryHelper  gh;

    GeometryPtr geo = Geometry::create();
    setContainer(geo);

    // The "properties" mfield can be thought of the unification of the
    // "positions", "normals", etc sfields of the 1.x Geometry.
    // For the conversion the PtrFieldInfo structure for the "properties"
    // mfield is filled with the corresponding ids of the sfields from the
    // file. The remapping after postRead will fill in the right pointers.

    FieldDescriptionBase *propFieldDesc =
        geo->getFieldDescription("properties");
    UInt32                propFieldId   = propFieldDesc->getFieldId();

    root->editPtrFieldList().push_back(PtrFieldInfo(geo, propFieldId));
    PtrFieldInfo &propFieldPFI = root->editPtrFieldList().back();

    propFieldPFI.editIdStore().resize(Geometry::MaxAttribs);

    while(true)
    {
        std::string    fieldName;
        std::string    fieldTypeName;
        UInt32         fieldSize;
        PtrFieldListIt ptrFieldIt;

        if(!readFieldHeader("", fieldName, fieldTypeName, fieldSize))
        {
            FDEBUG(("OSBGeometryElement::readV100: "
                    "Reading stopped at field: [%s].\n", fieldName.c_str()));
            break;
        }

        if(fieldName == "indexMapping")
        {
            // read into temporary field
            MField<UInt16> indexMappingField;
            indexMappingField.copyFromBin(*rh);

            // copy to member for use in postRead
            indexMappingField.getValues().swap(_indexMapping);
        }
        else if(fieldName == "indices")
        {
            // read container id of indices property
            // postRead will handle the conversion of multi indices
            rh->getValue(_indicesId);
        }
        else if(fieldName == "positions")
        {
            UInt32 positionsId;
            rh->getValue(positionsId);
            propFieldPFI.editIdStore()[Geometry::PositionsIndex] = positionsId;
        }
        else if(fieldName == "normals")
        {
            UInt32 normalsId;
            rh->getValue(normalsId);
            propFieldPFI.editIdStore()[Geometry::NormalsIndex] = normalsId;
        }
        else if(fieldName == "colors")
        {
            UInt32 colorsId;
            rh->getValue(colorsId);
            propFieldPFI.editIdStore()[Geometry::ColorsIndex] = colorsId;
        }
        else if(fieldName == "secondaryColors")
        {
            UInt32 secondaryColorsId;
            rh->getValue(secondaryColorsId);
            propFieldPFI.editIdStore()[Geometry::SecondaryColorsIndex] =
                secondaryColorsId;
        }
        else if(fieldName == "texCoords")
        {
            UInt32 texCoordsId;
            rh->getValue(texCoordsId);
            propFieldPFI.editIdStore()[Geometry::TexCoordsIndex] =
                texCoordsId;
        }
        else if(fieldName == "texCoords1")
        {
            UInt32 texCoordsId1;
            rh->getValue(texCoordsId1);
            propFieldPFI.editIdStore()[Geometry::TexCoords1Index] =
                texCoordsId1;
        }
        else if(fieldName == "texCoords2")
        {
            UInt32 texCoordsId2;
            rh->getValue(texCoordsId2);
            propFieldPFI.editIdStore()[Geometry::TexCoords2Index] =
                texCoordsId2;
        }
        else if(fieldName == "texCoords3")
        {
            UInt32 texCoordsId3;
            rh->getValue(texCoordsId3);
            propFieldPFI.editIdStore()[Geometry::TexCoords3Index] =
                texCoordsId3;
        }
        else if(fieldName == "texCoords4")
        {
            UInt32 texCoordsId4;
            rh->getValue(texCoordsId4);
            propFieldPFI.editIdStore()[Geometry::TexCoords4Index] =
                texCoordsId4;
        }
        else if(fieldName == "texCoords5")
        {
            UInt32 texCoordsId5;
            rh->getValue(texCoordsId5);
            propFieldPFI.editIdStore()[Geometry::TexCoords5Index] =
                texCoordsId5;
        }
        else if(fieldName == "texCoords6")
        {
            UInt32 texCoordsId6;
            rh->getValue(texCoordsId6);
            propFieldPFI.editIdStore()[Geometry::TexCoords6Index] =
                texCoordsId6;
        }
        else if(fieldName == "texCoords7")
        {
            UInt32 texCoordsId7;
            rh->getValue(texCoordsId7);
            propFieldPFI.editIdStore()[Geometry::TexCoords7Index] =
                texCoordsId7;
        }
        else if(fieldName == "pindices")
        {
            UInt32 maxValue;
            UInt32 propSize;
            UInt32 byteSize;

            _indicesPacked = true;

            gh.readPackedIntegralPropertyHeader(rh, maxValue,
                                                propSize, byteSize);

            if(root->getOptions().unpack16BitIndices())
            {
                if(maxValue > TypeTraits<UInt16>::getMax())
                {
                    GeoUInt32PropertyPtr ui32Indices =
                        GeoUInt32Property::create();
                    gh.readPackedIntegralProperty(rh, ui32Indices, maxValue,
                                                  propSize, byteSize        );

                    _indices16Bit = false;
                    _indices      = ui32Indices;
                }
                else
                {
                    GeoUInt16PropertyPtr ui16Indices =
                        GeoUInt16Property::create();
                    gh.readPackedIntegralProperty(rh, ui16Indices, maxValue,
                                                  propSize, byteSize        );

                    _indices16Bit = true;
                    _indices      = ui16Indices;
                }
            }
            else
            {
                GeoUInt32PropertyPtr ui32Indices =
                    GeoUInt32Property::create();
                gh.readPackedIntegralProperty(rh, ui32Indices, maxValue,
                                              propSize, byteSize        );

                _indices16Bit = false;
                _indices      = ui32Indices;
            }
        }
        else if(fieldName == "qpositions")
        {
            // Quantized positions are stored inside the geometry object, not
            // in the geo-property. They are always of type Pnt3f.
            GeoPnt3fPropertyPtr propPos    = GeoPnt3fProperty::create();
            UInt8               resolution;
            Real32              minValue;
            Real32              maxValue;
            UInt32              propSize;

            gh.readQuantizedVectorPropertyHeader(rh, resolution, minValue,
                                                 maxValue, propSize       );
            gh.readQuantizedVectorProperty(rh, propPos, fieldSize, resolution,
                                           minValue, maxValue, propSize       );

            geo->setProperty(propPos, Geometry::PositionsIndex);
        }
        else if(fieldName == "qnormals")
        {
            // Quantized normals are stored inside the geometry object, not
            // in the geo-property. They are always of type Vec3f.
            GeoVec3fPropertyPtr propNorm   = GeoVec3fProperty::create();
            UInt8               resolution;
            Real32              minValue;
            Real32              maxValue;
            UInt32              propSize;

            gh.readQuantizedVectorPropertyHeader(
                rh, resolution, minValue, maxValue, propSize);
            gh.readQuantizedVectorProperty(
                rh, propNorm, fieldSize, resolution,
                minValue, maxValue, propSize        );

            geo->setProperty(propNorm, Geometry::NormalsIndex);
        }
        else if(fieldName == "qtexCoords")
        {
            // Quantized texCoords are stored inside the geometry object, not
            // in the geo-property. They are always of type Vec2f.
            GeoVec2fPropertyPtr propTexCoords = GeoVec2fProperty::create();
            UInt8               resolution;
            Real32              minValue;
            Real32              maxValue;
            UInt32              propSize;

            gh.readQuantizedVectorPropertyHeader(
                rh, resolution, minValue, maxValue, propSize);
            gh.readQuantizedVectorProperty(
                rh, propTexCoords, fieldSize, resolution,
                minValue, maxValue, propSize             );

            geo->setProperty(propTexCoords, Geometry::NormalsIndex);
        }
        else
        {
            readFieldContent(fieldName, fieldTypeName, fieldSize,
                             "", ptrFieldIt                      );
        }
    }
}

void
OSBGeometryElement::postReadV100(void)
{
    FDEBUG(("OSBGeometryElement::postReadV100\n"));

    OSBRootElement  *root             = editRoot();
    GeometryPtr      geo              =
        cast_dynamic<GeometryPtr>(getContainer());
    UInt32           indexMappingSize = _indexMapping.size();

    if(indexMappingSize == 1)
    {
        FDEBUG(("OSBGeometryElement::postReadV100: "
                "Converting single index.\n"          ));

        if(_indicesPacked)
        {
            FDEBUG(("OSBGeometryElement::postReadV100: "
                    "Converting packed indices.\n"        ));
            geo->setIndices(_indices);
        }
        else
        {
            FDEBUG(("OSBGeometryElement::postReadV100: "
                    "Converting non-packed indices.\n"    ));

            // indices stored in container with id _indicesId
            // create PtrFieldInfo structure to set all entries of field
            // "propIndices" to the container with id _indicesId

            FieldDescriptionBase *indFieldDesc =
                geo->getFieldDescription("propIndices");
            UInt32                indFieldId   = indFieldDesc->getFieldId();

            root->editPtrFieldList().push_back(PtrFieldInfo(geo, indFieldId));
            PtrFieldInfo &indFieldPFI = root->editPtrFieldList().back();

            for(UInt32 i = 0; i < Geometry::MaxAttribs; ++i)
            {
                indFieldPFI.editIdStore().push_back(_indicesId);
            }
        }
    }
    else
    {
        FDEBUG(("OSBGeometryElement::postReadV100: "
                "Converting multi index.\n"          ));

        OSBGeometryHelper gh;

        if(_indicesPacked)
        {
            FDEBUG(("OSBGeometryElement::postReadV100: "
                    "Converting packed indices.\n"        ));

            // create 16 bit or 32 bit indices
            if(_indices16Bit)
            {
                GeoUInt16PropertyPtr ui16Indices =
                    cast_dynamic<GeoUInt16PropertyPtr>(_indices);

                gh.splitMultiIndex<GeoUInt16PropertyPtr>(
                    _indexMapping, ui16Indices, geo);
            }
            else
            {
                GeoUInt32PropertyPtr ui32Indices =
                    cast_dynamic<GeoUInt32PropertyPtr>(_indices);

                gh.splitMultiIndex<GeoUInt32PropertyPtr>(
                    _indexMapping, ui32Indices, geo);
            }
        }
        else
        {
            FDEBUG(("OSBGeometryElement::postReadV100: "
                    "Converting non-packed indices.\n"    ));

            FieldContainerIdMapConstIt mapIt =
                root->getIdMap().find(_indicesId);

            if(mapIt != root->getIdMap().end())
            {
                _indices = cast_dynamic<GeoIntegralPropertyPtr>(
                    FieldContainerFactory::the()->getContainer(mapIt->second));
            }
            else
            {
                FWARNING(("OSBGeometryElement::postReadV100: ",
                          "Could not find indices property.\n"));
                return;
            }

            if(_indices->getFormatSize() == sizeof(UInt16))
            {
                GeoUInt16PropertyPtr ui16Indices =
                    cast_dynamic<GeoUInt16PropertyPtr>(_indices);

                gh.splitMultiIndex<GeoUInt16PropertyPtr>(
                    _indexMapping, ui16Indices, geo);
            }
            else if(_indices->getFormatSize() == sizeof(UInt32))
            {
                GeoUInt32PropertyPtr ui32Indices =
                    cast_dynamic<GeoUInt32PropertyPtr>(_indices);

                gh.splitMultiIndex<GeoUInt32PropertyPtr>(
                    _indexMapping, ui32Indices, geo);
            }
        }
    }
}
