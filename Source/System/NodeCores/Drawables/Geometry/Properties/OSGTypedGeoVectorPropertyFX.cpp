/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2002 by the OpenSG Forum                   *
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

//---------------------------------------------------------------------------
 //  Includes
//---------------------------------------------------------------------------

#define OSG_COMPILENAMEDGEOPROPINST

#include <cstdlib>
#include <cstdio>

#include "OSGTypedGeoVectorProperty.h"

#include "OSGTypedGeoVectorPropertyFuncs.ins"

#include "OSGTypedGeoVectorProperty.ins"

OSG_USING_NAMESPACE

OSG_BEGIN_NAMESPACE

/*
OSG_FIELD_CONTAINER_NONINL_TMPL_DEF(TypedGeoVectorProperty,
                                    GeoPropertyDesc)

#define OSG_EXPORT_PROP(DESC)                           \
   OSG_RC_GET_TYPE_SPECIALIZED_TMPL_DEF(TypedGeoVectorProperty, DESC) \
   OSG_FC_CREATE_SPECIALIZED_TMPL_DEF(TypedGeoVectorProperty, DESC)   \
   template class OSG_DLL_EXPORT TypedGeoVectorProperty<DESC>;
*/


#ifdef OSG_WINCE
OSG_EXPORT_PROP(GeoVec1fxPropertyDesc)
OSG_EXPORT_PROP(GeoVec2fxPropertyDesc)
OSG_EXPORT_PROP(GeoVec3fxPropertyDesc)
OSG_EXPORT_PROP(GeoVec4fxPropertyDesc)

OSG_EXPORT_PROP(GeoPnt1fxPropertyDesc)
OSG_EXPORT_PROP(GeoPnt2fxPropertyDesc)
OSG_EXPORT_PROP(GeoPnt3fxPropertyDesc)
OSG_EXPORT_PROP(GeoPnt4fxPropertyDesc)
#endif

OSG_END_NAMESPACE
