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

#include "OSGOSBTypedGeoVectorPropertyElement.h"
#include "OSGOSBElementFactoryHelper.h"

#include "OSGTypedGeoVectorProperty.h"

OSG_USING_NAMESPACE

/*-------------------------------------------------------------------------*/
/* OSBTypedGeoVectorPropertyElement                                       */
/*-------------------------------------------------------------------------*/

/*! \class OSBTypedGeoVectorPropertyElement<GeoPropertyTypeT>
    A specialization of this template is registered for each specialization of
    TypedGeoVectorProperty.
 */

/*-------------------------------------------------------------------------*/
/*                                                                         */

namespace {

// Pnt properties
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt1ubProperty> >
        _regPnt1ub("GeoPnt1ubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt2ubProperty> >
        _regPnt2ub("GeoPnt2ubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt3ubProperty> >
        _regPnt3ub("GeoPnt3ubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt4ubProperty> >
        _regPnt4ub("GeoPnt4ubProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt1bProperty> >
        _regPnt1b("GeoPnt1bProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt2bProperty> >
        _regPnt2b("GeoPnt2bProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt3bProperty> >
        _regPnt3b("GeoPnt3bProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt4bProperty> >
        _regPnt4b("GeoPnt4bProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt1usProperty> >
        _regPnt1us("GeoPnt1usProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt2usProperty> >
        _regPnt2us("GeoPnt2usProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt3usProperty> >
        _regPnt3us("GeoPnt3usProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt4usProperty> >
        _regPnt4us("GeoPnt4usProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt1sProperty> >
        _regPnt1s("GeoPnt1sProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt2sProperty> >
        _regPnt2s("GeoPnt2sProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt3sProperty> >
        _regPnt3s("GeoPnt3sProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt4sProperty> >
        _regPnt4s("GeoPnt4sProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt1NubProperty> >
        _regPnt1Nub("GeoPnt1NubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt2NubProperty> >
        _regPnt2Nub("GeoPnt2NubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt3NubProperty> >
        _regPnt3Nub("GeoPnt3NubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt4NubProperty> >
        _regPnt4Nub("GeoPnt4NubProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt1NbProperty> >
        _regPnt1Nb("GeoPnt1NbProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt2NbProperty> >
        _regPnt2Nb("GeoPnt2NbProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt3NbProperty> >
        _regPnt3Nb("GeoPnt3NbProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt4NbProperty> >
        _regPnt4Nb("GeoPnt4NbProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt1NusProperty> >
        _regPnt1Nus("GeoPnt1NusProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt2NusProperty> >
        _regPnt2Nus("GeoPnt2NusProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt3NusProperty> >
        _regPnt3Nus("GeoPnt3NusProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt4NusProperty> >
        _regPnt4Nus("GeoPnt4NusProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt1NsProperty> >
        _regPnt1Ns("GeoPnt1NsProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt2NsProperty> >
        _regPnt2Ns("GeoPnt2NsProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt3NsProperty> >
        _regPnt3Ns("GeoPnt3NsProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt4NsProperty> >
        _regPnt4Ns("GeoPnt4NsProperty");

#ifndef OSG_WINCE
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt1fProperty> >
        _regPnt1f("GeoPnt1fProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt2fProperty> >
        _regPnt2f("GeoPnt2fProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt3fProperty> >
        _regPnt3f("GeoPnt3fProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt4fProperty> >
        _regPnt4f("GeoPnt4fProperty");
#endif

#ifdef OSG_WINCE
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt1fxProperty> >
        _regPnt1fx("GeoPnt1fxProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt2fxProperty> >
        _regPnt2fx("GeoPnt2fxProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt3fxProperty> >
        _regPnt3fx("GeoPnt3fxProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt4fxProperty> >
        _regPnt4fx("GeoPnt4fxProperty");
#endif

#ifndef OSG_WINCE
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt1dProperty> >
        _regPnt1d("GeoPnt1dProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt2dProperty> >
        _regPnt2d("GeoPnt2dProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt3dProperty> >
        _regPnt3d("GeoPnt3dProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoPnt4dProperty> >
        _regPnt4d("GeoPnt4dProperty");
#endif

// Vec properties
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec1ubProperty> >
        _regVec1ub("GeoVec1ubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec2ubProperty> >
        _regVec2ub("GeoVec2ubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec3ubProperty> >
        _regVec3ub("GeoVec3ubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec4ubProperty> >
        _regVec4ub("GeoVec4ubProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec1bProperty> >
        _regVec1b("GeoVec1bProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec2bProperty> >
        _regVec2b("GeoVec2bProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec3bProperty> >
        _regVec3b("GeoVec3bProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec4bProperty> >
        _regVec4b("GeoVec4bProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec1usProperty> >
        _regVec1us("GeoVec1usProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec2usProperty> >
        _regVec2us("GeoVec2usProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec3usProperty> >
        _regVec3us("GeoVec3usProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec4usProperty> >
        _regVec4us("GeoVec4usProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec1sProperty> >
        _regVec1s("GeoVec1sProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec2sProperty> >
        _regVec2s("GeoVec2sProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec3sProperty> >
        _regVec3s("GeoVec3sProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec4sProperty> >
        _regVec4s("GeoVec4sProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec1NubProperty> >
        _regVec1Nub("GeoVec1NubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec2NubProperty> >
        _regVec2Nub("GeoVec2NubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec3NubProperty> >
        _regVec3Nub("GeoVec3NubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec4NubProperty> >
        _regVec4Nub("GeoVec4NubProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec1NbProperty> >
        _regVec1Nb("GeoVec1NbProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec2NbProperty> >
        _regVec2Nb("GeoVec2NbProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec3NbProperty> >
        _regVec3Nb("GeoVec3NbProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec4NbProperty> >
        _regVec4Nb("GeoVec4NbProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec1NusProperty> >
        _regVec1Nus("GeoVec1NusProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec2NusProperty> >
        _regVec2Nus("GeoVec2NusProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec3NusProperty> >
        _regVec3Nus("GeoVec3NusProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec4NusProperty> >
        _regVec4Nus("GeoVec4NusProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec1NsProperty> >
        _regVec1Ns("GeoVec1NsProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec2NsProperty> >
        _regVec2Ns("GeoVec2NsProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec3NsProperty> >
        _regVec3Ns("GeoVec3NsProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec4NsProperty> >
        _regVec4Ns("GeoVec4NsProperty");

#ifndef OSG_WINCE
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec1fProperty> >
        _regVec1f("GeoVec1fProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec2fProperty> >
        _regVec2f("GeoVec2fProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec3fProperty> >
        _regVec3f("GeoVec3fProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec4fProperty> >
        _regVec4f("GeoVec4fProperty");
#endif

#ifdef OSG_WINCE
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec1fxProperty> >
        _regVec1fx("GeoVec1fxProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec2fxProperty> >
        _regVec2fx("GeoVec2fxProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec3fxProperty> >
        _regVec3fx("GeoVec3fxProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec4fxProperty> >
        _regVec4fx("GeoVec4fxProperty");
#endif

#ifndef OSG_WINCE
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec1dProperty> >
        _regVec1d("GeoVec1dProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec2dProperty> >
        _regVec2d("GeoVec2dProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec3dProperty> >
        _regVec3d("GeoVec3dProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoVec4dProperty> >
        _regVec4d("GeoVec4dProperty");
#endif

// Color properties
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoColor3ubProperty> >
        _regColor3ub("GeoColor3ubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoColor4ubProperty> >
        _regColor4ub("GeoColor4ubProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoColor3NubProperty> >
        _regColor3Nub("GeoColor3NubProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoColor4NubProperty> >
        _regColor4Nub("GeoColor4NubProperty");

static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoColor3fProperty> >
        _regColor3f("GeoColor3fProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoColor4fProperty> >
        _regColor4f("GeoColor4fProperty");

#ifdef OSG_WINCE
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoColor3fxProperty> >
        _regColor3fx("GeoColor3fxProperty");
static OSBElementRegistrationHelper<
    OSBTypedGeoVectorPropertyElement<GeoColor4fxProperty> >
        _regColor4fx("GeoColor4fxProperty");
#endif

} // namespace
