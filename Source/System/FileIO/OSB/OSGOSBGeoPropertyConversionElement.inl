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

#include "OSGOSBRootElement.h"

#include "OSGTypedGeoIntegralProperty.h"
#include "OSGTypedGeoVectorProperty.h"

OSG_BEGIN_NAMESPACE

/*-------------------------------------------------------------------------*/
/* OSBGeoPropertyConversionElement                                         */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/* Constructor                                                             */

template <class GeoPropertyTypeT>
OSBGeoPropertyConversionElement<GeoPropertyTypeT>::
    OSBGeoPropertyConversionElement(OSBRootElement *root)
    : Inherited(root, OSGOSBHeaderVersion200)
{
}

/*-------------------------------------------------------------------------*/
/* Destructor                                                              */

template <class GeoPropertyTypeT>
OSBGeoPropertyConversionElement<GeoPropertyTypeT>::
    ~OSBGeoPropertyConversionElement(void)
{
}

/*-------------------------------------------------------------------------*/
/* Reading                                                                 */

template <class GeoPropertyTypeT>
void
OSBGeoPropertyConversionElement<GeoPropertyTypeT>::read(
    const std::string &typeName)
{
    FDEBUG(("OSBGeoPropertyConversionElement<>::read: typeName: [%s]\n",
            typeName.c_str()));

    OSBRootElement          *root      = editRoot();
    BinaryReadHandler       *rh        = editRoot()->getReadHandler();
    GeoPropertyUnrecPtrType  prop      = GeoPropertyType::create();
    GeoPropertyFieldType    *propField = prop->editFieldPtr();

    setContainer(prop);

    UInt8  fcPtrType;
    UInt16 version;
    rh->getValue(fcPtrType);
    rh->getValue(version  );

    if(version > OSGOSBHeaderVersion100)
    {
        FWARNING(("OSBGeoPropertyConversionElement<>::read: "
                  "Unknown version, trying to read as OpenSG 1.\n"));
    }

    while(true)
    {
        std::string    fieldName;
        std::string    fieldTypeName;
        UInt32         fieldSize;
        PtrFieldListIt ptrFieldIt;

        if(!readFieldHeader("", fieldName, fieldTypeName, fieldSize))
        {
            FDEBUG(("OSBGeoPropertyConversionElement<>::read: "
                    "Reading stopped at field: [%s].\n", fieldName.c_str()));
            break;
        }

        // Depending on what OpenSG 1 property is read, the field holding the
        // data has different names, while in OpenSG 2 the field is always
        // named "values"

        if(fieldName == "positions")
        {
            FDEBUG(("OSBGeoPropertyConversionElement<>::read: "
                    "[%s] [%s] [%u]\n",
                    fieldName.c_str(), fieldTypeName.c_str(), fieldSize));

            propField->copyFromBin(*rh);
        }
        else if(fieldName == "normals")
        {
            FDEBUG(("OSBGeoPropertyConversionElement<>::read: "
                    "[%s] [%s] [%u]\n",
                    fieldName.c_str(), fieldTypeName.c_str(), fieldSize));

            propField->copyFromBin(*rh);
        }
        else if(fieldName == "TexCoords")
        {
            FDEBUG(("OSBGeoPropertyConversionElement<>::read: "
                    "[%s] [%s] [%u]\n",
                    fieldName.c_str(), fieldTypeName.c_str(), fieldSize));

            propField->copyFromBin(*rh);
        }
        else if(fieldName == "colors")
        {
            FDEBUG(("OSBGeoPropertyConversionElement<>::read: "
                    "[%s] [%s] [%u]\n",
                    fieldName.c_str(), fieldTypeName.c_str(), fieldSize));

            propField->copyFromBin(*rh);
        }
        else if(fieldName == "types")
        {
            FDEBUG(("OSBGeoPropertyConversionElement<>::read: "
                    "[%s] [%s] [%u]\n",
                    fieldName.c_str(), fieldTypeName.c_str(), fieldSize));

            propField->copyFromBin(*rh);
        }
        else if(fieldName == "lengths")
        {
            FDEBUG(("OSBGeoPropertyConversionElement<>::read: "
                    "[%s] [%s] [%u]\n",
                    fieldName.c_str(), fieldTypeName.c_str(), fieldSize));

            propField->copyFromBin(*rh);
        }
        else if(fieldName == "indices")
        {
            FDEBUG(("OSBGeoPropertyConversionElement<>::read: "
                    "[%s] [%s] [%u]\n",
                    fieldName.c_str(), fieldTypeName.c_str(), fieldSize));

            propField->copyFromBin(*rh);
        }
        else
        {
            // all other fields can be read normally
            readFieldContent(fieldName, fieldTypeName,
                             fieldSize, "", ptrFieldIt);
        }
    }
}

template <class GeoPropertyTypeT>
void
OSBGeoPropertyConversionElement<GeoPropertyTypeT>::postRead(void)
{
    FDEBUG(("OSBGeoPropertyConversionElement<>::postRead:\n"));
}

/*-------------------------------------------------------------------------*/
/* Writing                                                                 */

template <class GeoPropertyTypeT>
void
OSBGeoPropertyConversionElement<GeoPropertyTypeT>::preWrite(
    const FieldContainerPtr &fc)
{
    FFATAL(("OSBGeoPropertyConversionElement<>::preWrite: "
            "This should NEVER be called.\n"));
}

template <class GeoPropertyTypeT>
void
OSBGeoPropertyConversionElement<GeoPropertyTypeT>::write(void)
{
    FFATAL(("OSBGeoPropertyConversionElement<>::preWrite: "
            "This should NEVER be called.\n"));
}

OSG_END_NAMESPACE
