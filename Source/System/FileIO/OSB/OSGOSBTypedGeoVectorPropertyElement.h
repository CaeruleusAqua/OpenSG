/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *                   Copyright (C) 2007 by the OpenSG Forum                  *
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

#ifndef _OSGOSBTYPEDGEOVECTORPROPERTYELEMENT_H_
#define _OSGOSBTYPEDGEOVECTORPROPERTYELEMENT_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGFileIODef.h"

#include "OSGOSBGeoVectorPropertyElement.h"

OSG_BEGIN_NAMESPACE

class OSBRootElement;

template <class GeoPropertyTypeT>
class OSG_FILEIO_DLLMAPPING OSBTypedGeoVectorPropertyElement
    : public OSBGeoVectorPropertyElement
{
    /*==========================  PUBLIC  =================================*/
  public:
    /*---------------------------------------------------------------------*/
    /*! \name Types                                                        */
    /*! \{                                                                 */

    typedef          GeoPropertyTypeT                  GeoPropertyType;
    typedef typename GeoPropertyType::ObjPtr           GeoPropertyPtrType;
    typedef typename GeoPropertyType::StoredFieldType  GeoPropertyFieldType;
    typedef typename GeoPropertyFieldType::StoredType  VectorType;
    typedef typename VectorType::ValueType             ElementType;

    typedef OSBTypedGeoVectorPropertyElement<GeoPropertyType> Self;
    typedef OSBGeoVectorPropertyElement                       Inherited;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Constructor                                                  */
    /*! \{                                                                 */

    OSBTypedGeoVectorPropertyElement(OSBRootElement *root);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Destructor                                                   */
    /*! \{                                                                 */

    virtual ~OSBTypedGeoVectorPropertyElement(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Reading                                                      */
    /*! \{                                                                 */

    virtual void read    (const std::string &typeName);
    virtual void postRead(      void                 );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Writing                                                      */
    /*! \{                                                                 */

    virtual void preWrite(const FieldContainerPtr &fc);
    virtual void write   (      void                 );

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/
  protected:

    /*==========================  PRIVATE  ================================*/
  private:
    static const UInt8 FlagQuantizeResolutionMask = 0x03;
};

OSG_END_NAMESPACE

#include "OSGOSBTypedGeoVectorPropertyElement.inl"

#endif /* _OSGOSBTYPEDGEOVECTORPROPERTYELEMENT_H_ */
