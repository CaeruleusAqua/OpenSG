/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2002 by the OpenSG Forum                   *
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


#ifndef _OSGGeoSimpleGeometry_H_
#define _OSGGeoSimpleGeometry_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGBaseTypes.h"
#include "OSGNode.h"
#include "OSGDrawableDef.h"
#include "OSGGeometry.h"


OSG_BEGIN_NAMESPACE

/*---------------------------------------------------------------------*/
/*! \name                   Construction functions                     */
/*! \{                                                                 */

OSG_DRAWABLE_DLLMAPPING
GeometryPtr               makePlaneGeo          (Real32 xsize,
                                                 Real32 ysize,
                                                 UInt16 hor,
                                                 UInt16 vert);

OSG_DRAWABLE_DLLMAPPING
NodePtr                   makePlane             (Real32 xsize,
                                                 Real32 ysize,
                                                 UInt16 hor,
                                                 UInt16 vert);

OSG_DRAWABLE_DLLMAPPING
GeometryPtr               makeBoxGeo            (Real32 xsize,
                                                 Real32 ysize,
                                                 Real32 zsize,
                                                 UInt16 hor,
                                                 UInt16 vert,
                                                 UInt16 depth);

OSG_DRAWABLE_DLLMAPPING
NodePtr                   makeBox               (Real32 xsize,
                                                 Real32 ysize,
                                                 Real32 zsize,
                                                 UInt16 hor,
                                                 UInt16 vert,
                                                 UInt16 depth);

OSG_DRAWABLE_DLLMAPPING
GeometryPtr               makeConeGeo           (Real32 height,
                                                 Real32 botradius,
                                                 UInt16 sides,
                                                 bool   doSide,
                                                 bool   doBottom);

OSG_DRAWABLE_DLLMAPPING
NodePtr                   makeCone              (Real32 height,
                                                 Real32 botradius,
                                                 UInt16 sides,
                                                 bool   doSide,
                                                 bool   doBottom);

OSG_DRAWABLE_DLLMAPPING
GeometryPtr               makeCylinderGeo       (Real32 height,
                                                 Real32 radius,
                                                 UInt16 sides,
                                                 bool   doSide,
                                                 bool   doTop,
                                                 bool   doBottom);

OSG_DRAWABLE_DLLMAPPING
NodePtr                   makeCylinder          (Real32 height,
                                                 Real32 radius,
                                                 UInt16 sides,
                                                 bool   doSide,
                                                 bool   doTop,
                                                 bool   doBottom);

OSG_DRAWABLE_DLLMAPPING
GeometryPtr               makeTorusGeo          (Real32 innerRadius,
                                                 Real32 outerRadius,
                                                 UInt16 sides,
                                                 UInt16 rings );


OSG_DRAWABLE_DLLMAPPING
NodePtr                   makeTorus             (Real32 innerRadius,
                                                 Real32 outerRadius,
                                                 UInt16 sides,
                                                 UInt16 rings);

OSG_DRAWABLE_DLLMAPPING
GeometryPtr               makeSphereGeo         (UInt16 depth,
                                                 Real32 radius);

OSG_DRAWABLE_DLLMAPPING
NodePtr                   makeSphere            (UInt16 depth,
                                                 Real32 radius);

OSG_DRAWABLE_DLLMAPPING
GeometryPtr               makeLatLongSphereGeo  (UInt16 latres,
                                                 UInt16 longres,
                                                 Real32 radius);

OSG_DRAWABLE_DLLMAPPING
NodePtr                   makeLatLongSphere     (UInt16 latres,
                                                 UInt16 longres,
                                                 Real32 radius);

OSG_DRAWABLE_DLLMAPPING
GeometryPtr               makeConicalFrustumGeo (Real32 height,
                                                 Real32 topradius,
                                                 Real32 botradius,
                                                 UInt16 sides,
                                                 bool   doSide,
                                                 bool   doTop,
                                                 bool   doBottom);

OSG_DRAWABLE_DLLMAPPING
NodePtr                   makeConicalFrustum    (Real32 height,
                                                 Real32 topradius,
                                                 Real32 botradius,
                                                 UInt16 sides,
                                                 bool   doSide,
                                                 bool   doTop,
                                                 bool   doBottom);
OSG_DRAWABLE_DLLMAPPING
NodePtr                   makeCoordAxis(Real32 length,
                                        Real32 lineWidth    = 2.0f,
                                        bool   showAxisName = true);

OSG_DRAWABLE_DLLMAPPING
GeometryPtr               makeCoordAxisGeo(Real32 length,
                                           Real32 lineWidth    = 2.0f,
                                           bool   showAxisName = true);

OSG_DRAWABLE_DLLMAPPING
GeometryPtr               makeTeapotGeo(UInt16 depth);

OSG_DRAWABLE_DLLMAPPING
NodePtr                   makeTeapot         (UInt16 depth);

/*! \}                                                                 */

OSG_END_NAMESPACE

#endif /* _OSGGeoSimpleGeometry_H_ */
