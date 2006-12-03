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
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGGEOMULTIPROPERTYDATAFIELDS_H_
#define _OSGGEOMULTIPROPERTYDATAFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGDrawableDef.h"

#include "OSGStateChunkFields.h"

#include "OSGSFieldAdaptor.h"
#include "OSGMFieldAdaptor.h"


OSG_BEGIN_NAMESPACE

class GeoMultiPropertyData;

#if !defined(OSG_DO_DOC) // created as a dummy class, remove to prevent doubles
//! GeoMultiPropertyDataPtr

typedef PointerFwdBuilder<StateChunkPtr,
                          StateChunkConstPtr,
                          GeoMultiPropertyData>::ObjPtr         GeoMultiPropertyDataPtr;
typedef PointerFwdBuilder<StateChunkPtr,
                          StateChunkConstPtr,
                          GeoMultiPropertyData>::ObjPtrConst    GeoMultiPropertyDataPtrConst;
typedef PointerFwdBuilder<StateChunkPtr,
                          StateChunkConstPtr,
                          GeoMultiPropertyData>::ObjConstPtr    GeoMultiPropertyDataConstPtr;
typedef PointerFwdBuilder<StateChunkPtr,
                          StateChunkConstPtr,
                          GeoMultiPropertyData>::ObjPtrArg      GeoMultiPropertyDataPtrArg;
typedef PointerFwdBuilder<StateChunkPtr,
                          StateChunkConstPtr,
                          GeoMultiPropertyData>::ObjConstPtrArg GeoMultiPropertyDataConstPtrArg;
typedef PointerFwdBuilder<StateChunkPtr,
                          StateChunkConstPtr,
                          GeoMultiPropertyData>::ObjPtrConstArg GeoMultiPropertyDataPtrConstArg;

#endif

#if !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)
/*! \ingroup GrpDrawableFieldTraits
 */
#if !defined(OSG_DOC_DEV_TRAITS)
/*! \hideinhierarchy */
#endif

template <>
struct FieldTraits<GeoMultiPropertyDataPtr> :
    public FieldTraitsTemplateBase<GeoMultiPropertyDataPtr>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<GeoMultiPropertyDataPtr>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_DRAWABLE_DLLMAPPING
                     DataType &getType (void);

    static const char *getSName(void) { return "SFGeoMultiPropertyDataPtr"; }
    static const char *getMName(void) { return "MFGeoMultiPropertyDataPtr"; }
};

#if !defined(OSG_DOC_DEV_TRAITS)
/*! \class  FieldTraitsTemplateBase<GeoMultiPropertyDataPtr, 0>
    \hideinhierarchy
 */
#endif

#endif // !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS)
/*! \ingroup GrpDrawableFieldSingle */

typedef SFieldAdaptor<GeoMultiPropertyDataPtr, SFFieldContainerPtr> SFGeoMultiPropertyDataPtr;
#endif

#ifndef OSG_COMPILEGEOMULTIPROPERTYDATAINST
OSG_FIELD_DLLEXPORT_DECL1(SField, GeoMultiPropertyDataPtr, OSG_DRAWABLE_DLLTMPLMAPPING)
#endif

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS)
/*! \ingroup GrpDrawableFieldMulti */

typedef MFieldAdaptor<GeoMultiPropertyDataPtr, MFFieldContainerPtr> MFGeoMultiPropertyDataPtr;
#endif

#ifndef OSG_COMPILEGEOMULTIPROPERTYDATAINST
OSG_FIELD_DLLEXPORT_DECL1(MField, GeoMultiPropertyDataPtr, OSG_DRAWABLE_DLLTMPLMAPPING)
#endif

OSG_END_NAMESPACE

#define OSGGEOMULTIPROPERTYDATAFIELDS_HEADER_CVSID "@(#)$Id$"

#endif /* _OSGGEOMULTIPROPERTYDATAFIELDS_H_ */
