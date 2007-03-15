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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"
#include <OSGLog.h>
#include <OSGQuaternion.h>
#include <OSGMaterial.h>
#include <OSGSimpleMaterial.h>
#include <OSGLineChunk.h>
#include <OSGGeoProperties.h>
#include "OSGSimpleGeometry.h"  // for DefaultMaterials
#include "OSGTypedGeoIntegralProperty.h"
#include "OSGTypedGeoVectorProperty.h"

//#include <OSGTriangleIterator.h>

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

#if defined(OSG_WIN32_ICL) && !defined(OSG_CHECK_FIELDSETARG)
#pragma warning (disable : 383)
#endif

// The Simple Geometry creation functions

/*! Creates a plane in the x/y plane. It spans the [-\a xsize /2,\a
    xsize /2] x [-\a ysize /2,\a ysize/2] area and is subdivided into \a hor *
    \a vert quads.

    \param[in] xsize Length of plane edge in x direction.
    \param[in] ysize Length of plane edge in y direction.
    \param[in] hor Number of quads in x direction.
    \param[in] vert Number of quads in y direction.
    \return NodePtr to a newly created Node with a Geometry core.

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
NodePtr makePlane(Real32 xsize, Real32 ysize, UInt16 hor, UInt16 vert)
{
    GeometryPtr pGeo = makePlaneGeo(xsize, ysize, hor, vert);

    if(pGeo == NullFC)
    {
        return NullFC;
    }

    NodePtr node = Node::create();

    node->setCore(pGeo);

    return node;
}

/*! Create the Geometry core used by OSG::makePlane.

    \param[in] xsize Length of plane edge in x direction.
    \param[in] ysize Length of plane edge in y direction.
    \param[in] hor Number of quads in x direction.
    \param[in] vert Number of quads in y direction.
    \return GeometryPtr to a newly created Geometry core.

    \sa OSG::makePlane

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
GeometryPtr makePlaneGeo(Real32 xsize, Real32 ysize,
                         UInt16 hor,   UInt16 vert)
{
    if(! hor || ! vert)
    {
        SWARNING << "makePlane: illegal parameters hor=" << hor << ", vert="
                 << vert << std::endl;
        return NullFC;
    }

    GeoPnt3fPropertyPtr  pnts  = GeoPnt3fProperty ::create();
    GeoVec3fPropertyPtr  norms = GeoVec3fProperty ::create();
    GeoVec2fPropertyPtr  tex   = GeoVec2fProperty ::create();
    GeoUInt32PropertyPtr index = GeoUInt32Property::create();
    GeoUInt32PropertyPtr lens  = GeoUInt32Property::create();
    GeoUInt8PropertyPtr  types = GeoUInt8Property ::create();

    UInt16 x,y;
    Real32 xstep,ystep;
    xstep=xsize / hor;
    ystep=ysize / vert;

    // calc the vertices

    GeoPnt3fProperty::StoredFieldType *p  = pnts ->editFieldPtr();
    GeoVec3fProperty::StoredFieldType *n  = norms->editFieldPtr();
    GeoVec2fProperty::StoredFieldType *tx = tex ->editFieldPtr();

    for(y = 0; y <= vert; y++)
    {
        for(x = 0; x <= hor; x++)
        {
            p->push_back(Pnt3f(x * xstep - xsize / 2, y * ystep - ysize / 2, 0));
            n->push_back(Vec3f(0, 0, 1));
            tx->push_back(Vec2f(x / (Real32) hor, y / (Real32) vert));
        }
    }

    // create the faces

    GeoUInt32Property::StoredFieldType *i = index->editFieldPtr();
    GeoUInt32Property::StoredFieldType *l = lens ->editFieldPtr();
    GeoUInt8Property::StoredFieldType  *t = types->editFieldPtr();

    for(y = 0; y < vert; y++)
    {
        t->push_back(GL_TRIANGLE_STRIP);
        l->push_back(2 * (hor + 1));

        for(x = 0; x <= hor; x++)
        {
            i->push_back((y + 1) * (hor + 1) + x);
            i->push_back( y      * (hor + 1) + x);
        }
    }

    // create the geometry

    GeometryPtr geo = Geometry::create();

    geo->setMaterial(getDefaultMaterial());
    geo->setPositions(pnts);
    geo->setNormals(norms);
    geo->setTexCoords(tex);
    geo->setIndices(index);
    geo->setTypes(types);
    geo->setLengths(lens);

    return geo;
}

/*! Creates a cone. It's center is in the origin and the bottom is parallel to
    the x/y plane.
    It's radius is \a botradius and the base is subdivided into \a sides parts.

    Each part of the cone (bottom cap, sides) can be enabled or disabled.

    \param[in] height Height of the cone.
    \param[in] botradius Radius if the bottom.
    \param[in] sides Number of sides the base is subdivided into.
    \param[in] doSide If true side faces are created.
    \param[in] doBttom If true bottom faces are created.
    \return NodePtr to a newly created Node with a Geometry core.

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
*/
NodePtr makeCone(Real32 height,
                 Real32 botradius,
                 UInt16 sides,
                 bool   doSide,
                 bool   doBottom)
{
    return makeConicalFrustum(height,
                              0,
                              botradius,
                              sides,
                              doSide,
                              false,
                              doBottom);
}

/*! Create the Geometry Core used by OSG::makeCone.

    \param[in] height Height of the cone.
    \param[in] botradius Radius if the bottom.
    \param[in] sides Number of sides the base is subdivided into.
    \param[in] doSide If true side faces are created.
    \param[in] doBttom If true bottom faces are created.
    \return GeometryPtr to a newly created Geometry core.

    \sa OSG::makeCone

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
*/
GeometryPtr makeConeGeo(Real32 height,
                        Real32 botradius,
                        UInt16 sides,
                        bool   doSide,
                        bool   doBottom)
{
    return makeConicalFrustumGeo(height,
                                 0,
                                 botradius,
                                 sides,
                                 doSide,
                                 false,
                                 doBottom);
}

/*! Creates a cylinder. It's center is in the origin with top and bottom
    parallel to the x/y plane. It's radius is \a radius and the base is
    subdivided into \a sides parts.

    Each part of the cylinder (top cap, bottom cap, sides) can be enabled or
    disabled.

    \param[in] height Height of the cylinder.
    \param[in] radius Radius of the cylinder.
    \param[in] sides Number of sides the base is subdivided into.
    \param[in] doSide If true, side faces are created.
    \param[in] doTop If true, top cap faces are created.
    \param[in] doBttom If true, bottom cap faces are created.
    \return NodePtr to a newly created Node with a Geometry core.

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
*/
NodePtr makeCylinder(Real32 height,
                     Real32 radius,
                     UInt16 sides,
                     bool   doSide,
                     bool   doTop,
                     bool   doBottom)
{
    return makeConicalFrustum(height,
                              radius,
                              radius,
                              sides,
                              doSide,
                              doTop,
                              doBottom);
}

/*! Create the Geometry Core used by OSG::makeCylinder.

    \param[in] height Height of the cylinder.
    \param[in] radius Radius of the cylinder.
    \param[in] sides Number of sides the base is subdivided into.
    \param[in] doSide If true, side faces are created.
    \param[in] doTop If true, top cap faces are created.
    \param[in] doBttom If true, bottom cap faces are created.
    \return GeometryPtr to a newly created Geometry core.

    \sa OSG::makeCylinder

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
*/
GeometryPtr makeCylinderGeo(Real32 height,
                            Real32 radius,
                            UInt16 sides,
                            bool   doSide,
                            bool   doTop,
                            bool   doBottom)
{
    return makeConicalFrustumGeo(height,
                                 radius,
                                 radius,
                                 sides,
                                 doSide,
                                 doTop,
                                 doBottom);
}


/*! Creates a conical frustum. It's center is in the origin with top and bottom
    parallel to the x/y plane. The height is \a height and the base is
    subdivided into \a sides parts. The top radius is \a topradius, while the
    bottom radius is \a botradius.

    Each part of the frustum (top cap, bottom cap, sides) can be enabled or
    disabled. Caps for radii 0 are automatically disabled.

    \param[in] height Height of the conical frustum.
    \param[in] topradius Radius at the top of the conical frustum.
    \param[in] botradius Radius at the bottom of the conical frustum.
    \param[in] sides Number of sides the base is subdivided into.
    \param[in] doSide If true, side faces are created.
    \param[in] doTop If true, top cap faces are created.
    \param[in] doBttom If true, bottom cap faces are created.
    \return NodePtr to a newly created Node with a Geometry core.

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
NodePtr makeConicalFrustum(Real32 height,
                           Real32 topradius,
                           Real32 botradius,
                           UInt16 sides,
                           bool   doSide,
                           bool   doTop,
                           bool   doBottom)
{
    GeometryPtr pGeo = makeConicalFrustumGeo(height,
                                             topradius,
                                             botradius,
                                             sides,
                                             doSide,
                                             doTop,
                                             doBottom);

    if(pGeo == NullFC)
    {
        return NullFC;
    }

    NodePtr node = Node::create();

    node->setCore(pGeo);

    return node;
}

/*! Create the Geometry Core used by OSG::makeConicalFrustum.

    \param[in] height Height of the conical frustum.
    \param[in] topradius Radius at the top of the conical frustum.
    \param[in] botradius Radius at the bottom of the conical frustum.
    \param[in] sides Number of sides the base is subdivided into.
    \param[in] doSide If true, side faces are created.
    \param[in] doTop If true, top cap faces are created.
    \param[in] doBttom If true, bottom cap faces are created.
    \return GeometryPtr to a newly created Geometry core.

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
GeometryPtr makeConicalFrustumGeo(Real32 height,
                                  Real32 topradius,
                                  Real32 botradius,
                                  UInt16 sides,
                                  bool   doSide,
                                  bool   doTop,
                                  bool   doBottom)
{
    if(height <= 0 || topradius < 0 || botradius < 0 || sides < 3)
    {
        SWARNING << "makeConicalFrustum: illegal parameters height=" << height
                 << ", topradius=" << topradius
                 << ", botradius=" << botradius
                 << ", sides=" << sides
                 << std::endl;
        return NullFC;
    }

    GeoPnt3fPropertyPtr  pnts  = GeoPnt3fProperty ::create();
    GeoVec3fPropertyPtr  norms = GeoVec3fProperty ::create();
    GeoVec2fPropertyPtr  tex   = GeoVec2fProperty ::create();
    GeoUInt32PropertyPtr index = GeoUInt32Property::create();
    GeoUInt32PropertyPtr lens  = GeoUInt32Property::create();
    GeoUInt8PropertyPtr  types = GeoUInt8Property ::create();

    Int16  j;
    Real32 delta = 2.f * Pi / sides;
    Real32 beta, x, z;
    Real32 incl = (botradius - topradius) / height;
    Real32 nlen = 1.f / osgSqrt(1 + incl * incl);

    // vertices

    GeoPnt3fProperty::StoredFieldType  *p  = pnts ->editFieldPtr();
    GeoVec3fProperty::StoredFieldType  *n  = norms->editFieldPtr();
    GeoVec2fProperty::StoredFieldType  *tx = tex  ->editFieldPtr();

    // faces

    GeoUInt32Property::StoredFieldType *i  = index->editFieldPtr();
    GeoUInt32Property::StoredFieldType *l  = lens ->editFieldPtr();
    GeoUInt8Property::StoredFieldType  *t  = types->editFieldPtr();

    if(doSide)
    {
        UInt32 baseindex = p->size();

        for(j = 0; j <= sides; j++)
        {
            beta = j * delta;
            x    =  osgSin(beta);
            z    = -osgCos(beta);

            p->push_back(Pnt3f(x * topradius, height/2, z * topradius));
            n->push_back(Vec3f(x/nlen, incl/nlen, z/nlen));
            tx->push_back(Vec2f(1.f - j / (Real32) sides, 1));
        }

        for(j = 0; j <= sides; j++)
        {
            beta = j * delta;
            x    =  osgSin(beta);
            z    = -osgCos(beta);

            p->push_back(Pnt3f(x * botradius, -height/2, z * botradius));
            n->push_back(Vec3f(x/nlen, incl/nlen, z/nlen));
            tx->push_back(Vec2f(1.f - j / (Real32) sides, 0));
        }

        t->push_back(GL_TRIANGLE_STRIP);
        l->push_back(2 * (sides + 1));

        for(j = 0; j <= sides; j++)
        {
                i->push_back(baseindex + sides + 1 + j);
                i->push_back(baseindex + j);
        }
    }

    if(doTop && topradius > 0)
    {
        UInt32 baseindex = p->size();

        // need to duplicate the points fornow, as we don't have multi-index geo yet

        for(j = sides - 1; j >= 0; j--)
        {
            beta = j * delta;
            x    =  topradius * osgSin(beta);
            z    = -topradius * osgCos(beta);

            p->push_back(Pnt3f(x, height/2, z));
            n->push_back(Vec3f(0, 1, 0));
            tx->push_back(Vec2f(x / topradius / 2 + .5f, -z / topradius / 2 + .5f));
        }

        t->push_back(GL_POLYGON);
        l->push_back(sides);

        for(j = 0; j < sides; j++)
        {
            i->push_back(baseindex + j);
        }
    }

    if(doBottom && botradius > 0 )
    {
        UInt32 baseindex = p->size();

        // need to duplicate the points fornow, as we don't have multi-index geo yet

        for(j = sides - 1; j >= 0; j--)
        {
            beta = j * delta;
            x    =  botradius * osgSin(beta);
            z    = -botradius * osgCos(beta);

            p->push_back(Pnt3f(x, -height/2, z));
            n->push_back(Vec3f(0, -1, 0));
            tx->push_back(Vec2f(x / botradius / 2 + .5f, z / botradius / 2 + .5f));
        }

        t->push_back(GL_POLYGON);
        l->push_back(sides);

        for(j = 0; j < sides; j++)
        {
            i->push_back(baseindex + sides - 1 - j);
        }
    }

    // create the geometry

    GeometryPtr geo = Geometry::create();

    geo->setMaterial(getDefaultMaterial());
    geo->setPositions(pnts);
    geo->setNormals(norms);
    geo->setTexCoords(tex);
    geo->setIndices(index);
    geo->setTypes(types);
    geo->setLengths(lens);

    return geo;
}

/*! Creates a torus in the x/y plane. The number of subdivisions for
    the inner radius is \a sides, for the outer radius it is \a rings.

    \param[in] innerRadius Inner radius of the torus.
    \param[in] outerRadius Outer radius of the torus.
    \param[in] sides Number of subdivisions along the inner radius.
    \param[in] rings Number of subdivisions along the outer radius.
    \return NodePtr to a newly created Node with a Geometry core.

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
NodePtr makeTorus(Real32 innerRadius, Real32 outerRadius, UInt16 sides,
                  UInt16 rings)
{
    GeometryPtr pGeo = makeTorusGeo(innerRadius, outerRadius, sides, rings);

    if(pGeo == NullFC)
    {
        return NullFC;
    }

    NodePtr node = Node::create();

    node->setCore(pGeo);

    return node;
}

/*! Create the Geometry Core used by OSG::makeTorus.

    \param[in] innerRadius Inner radius of the torus.
    \param[in] outerRadius Outer radius of the torus.
    \param[in] sides Number of subdivisions along the inner radius.
    \param[in] rings Number of subdivisions along the outer radius.
    \return GeometryPtr to a newly created Geometry core.

    \sa OSG::makeTorus

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
GeometryPtr makeTorusGeo(Real32 innerRadius, Real32 outerRadius, UInt16 sides,
                         UInt16 rings)
{
    if(innerRadius <= 0 || outerRadius <= 0 || sides < 3 || rings < 3)
    {
        SWARNING << "makeTorus: illegal parameters innerRadius=" << innerRadius
                 << ", outerRadius=" << outerRadius
                 << ", sides=" << sides
                 << ", rings=" << rings
                 << std::endl;
        return NullFC;
    }

    GeoPnt3fPropertyPtr  pnts  = GeoPnt3fProperty ::create();
    GeoVec3fPropertyPtr  norms = GeoVec3fProperty ::create();
    GeoVec2fPropertyPtr  tex   = GeoVec2fProperty ::create();
    GeoUInt32PropertyPtr index = GeoUInt32Property::create();
    GeoUInt32PropertyPtr lens  = GeoUInt32Property::create();
    GeoUInt8PropertyPtr  types = GeoUInt8Property ::create();

    UInt16 a, b;
    Real32 theta, phi;
    Real32 cosTheta, sinTheta;
    Real32 ringDelta, sideDelta;

    // calc the vertices

    GeoPnt3fProperty::StoredFieldType  *p  = pnts ->editFieldPtr();
    GeoVec3fProperty::StoredFieldType  *n  = norms->editFieldPtr();
    GeoVec2fProperty::StoredFieldType  *tx = tex  ->editFieldPtr();

    ringDelta = 2.f * Pi / rings;
    sideDelta = 2.f * Pi / sides;

    for(a = 0, theta = 0.0; a <= rings; a++, theta += ringDelta)
    {
        cosTheta = osgCos(theta);
        sinTheta = osgSin(theta);

        for(b = 0, phi = 0; b <= sides; b++, phi += sideDelta)
        {
            GLfloat cosPhi, sinPhi, dist;

            cosPhi = osgCos(phi);
            sinPhi = osgSin(phi);
            dist   = outerRadius + innerRadius * cosPhi;

            n->push_back(Vec3f(cosTheta * cosPhi,
                              -sinTheta * cosPhi,
                              sinPhi));
            p->push_back(Pnt3f(cosTheta * dist,
                              -sinTheta * dist,
                              innerRadius * sinPhi));
            tx->push_back(Vec2f(- a / (Real32) rings, b / (Real32)sides));
        }
    }

    // create the faces

    GeoUInt32Property::StoredFieldType *i  = index->editFieldPtr();
    GeoUInt32Property::StoredFieldType *l  = lens ->editFieldPtr();
    GeoUInt8Property::StoredFieldType  *t  = types->editFieldPtr();

    for(a = 0; a < sides; a++)
    {
        t->push_back(GL_TRIANGLE_STRIP);
        l->push_back((rings + 1) * 2);

        for(b = 0; b <= rings; b++)
        {
            i->push_back(b * (sides+1) + a);
            i->push_back(b * (sides+1) + a + 1);
        }
    }

    // create the geometry

    GeometryPtr geo = Geometry::create();

    geo->setMaterial(getDefaultMaterial());
    geo->setPositions(pnts);
    geo->setNormals(norms);
    geo->setTexCoords(tex);
    geo->setIndices(index);
    geo->setTypes(types);
    geo->setLengths(lens);

    return geo;
}

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)

/*! Scale the vector \a vec to the given \a length. If \a vec is degenerate,
    i.e. has length 0 it is not changed.

    \param[in,out] vec The vector to scale.
    \param[in] length Length to scale \a vec to.
    \return The \a length argument.
 */
Real32 setVecLen(Vec3f &vec, Real32 length)
{
    Real32 len = vec.length();
    if(len == 0.0)
    {
        len = 1;
    }
    else
    {
        len = length / len;
    }
    vec *= len;

    return length;
}

Real32 calcTexS(Vec3f &n, Real32 theta)
{
    const Real32 TwoPi  = 6.283185307179586;
    const Real32 HalfPi = 1.570796326794897;

    Real32 phi = osgATan2(-n[2], n[0]) - HalfPi;

    if (phi <= -Eps)
        phi += TwoPi;
    phi /= TwoPi;

    return phi;
}

void addPoint(Pnt3f v, UInt32 index, Real32 radius,
              GeoPnt3fProperty::StoredFieldType *p,
              GeoVec3fProperty::StoredFieldType *n,
              GeoVec2fProperty::StoredFieldType *tx)
{
    Vec3f norm(v[0], v[1], v[2]);

    norm.normalize();
    n->push_back(norm);

    Pnt3f pnt(radius * norm);
    p->push_back(pnt);

    Vec2f texCoord;

    // Theta -> v
    texCoord[1] = (Pi - osgACos(norm[1])) / Pi;

    texCoord[0] = calcTexS(norm, texCoord[1]);

    tx->push_back(texCoord);
}

void subdivideTriangle( UInt32 i1,
                        UInt32 i2,
                        UInt32 i3,
                        Int32 depth,
                        GeoPnt3fProperty::StoredFieldType  *p,
                        GeoVec3fProperty::StoredFieldType  *n,
                        GeoVec2fProperty::StoredFieldType  *tx,
                        GeoUInt32Property::StoredFieldType *i,
                        GeoUInt32Property::StoredFieldType *tci,
                        UInt32& z, Real32 radius )
{
    if (depth == 0)
    {
        i->push_back(i1);
        tci->push_back(i1);
        i->push_back(i2);
        tci->push_back(i2);
        i->push_back(i3);
        tci->push_back(i3);

        return;
    }

    Pnt3f v1 = (*p)[i1],
          v2 = (*p)[i2],
          v3 = (*p)[i3];
    Pnt3f v12, v23, v31;

    v12 = v1 + (v2 - v1) * .5f;
    v23 = v2 + (v3 - v2) * .5f;
    v31 = v3 + (v1 - v3) * .5f;

    v12 /= 2.0f;
    v23 /= 2.0f;
    v31 /= 2.0f;

    UInt32 i12 = z++, i23 = z++, i31 = z++;

    addPoint(v12,i12,radius,p,n,tx);
    addPoint(v23,i23,radius,p,n,tx);
    addPoint(v31,i31,radius,p,n,tx);

    subdivideTriangle( i1, i12, i31, depth - 1, p,n,tx,i,tci, z, radius);
    subdivideTriangle( i2, i23, i12, depth - 1, p,n,tx,i,tci, z, radius);
    subdivideTriangle( i3, i31, i23, depth - 1, p,n,tx,i,tci, z, radius);
    subdivideTriangle(i12, i23, i31, depth - 1, p,n,tx,i,tci, z, radius);
}

#endif            // exclude from doc

/*! Creates a sphere centered in the origin. It is created by
    recursive subdivision of an icosahedron, with \a depth giving the number
    of subdivisions and \a radius being the radius.

    \param[in] depth Number of recursive subdivisions to perform.
    \param[in] radius Radius of sphere.
    \return NodePtr to a newly created Node with a Geometry core.

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
NodePtr makeSphere(UInt16 depth, Real32 radius)
{
    GeometryPtr pGeo = makeSphereGeo(depth, radius);

    if(pGeo == NullFC)
    {
        return NullFC;
    }

    NodePtr node = Node::create();

    node->setCore(pGeo);

    return node;
}

/*! Create the Geometry Core for used by OSG::makeSphere.

    \param[in] depth Number of recursive subdivisions to perform.
    \param[in] radius Radius of sphere.
    \return GeometryPtr to a newly created Geometry core.

    \sa OSG::makeSphere

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
GeometryPtr makeSphereGeo(UInt16 depth, Real32 radius)
{
    const Real32 X = .525731112119133606;
    const Real32 Z = .850650808352039932;
    const Real32 HalfPi = 1.570796326794897;

    GeoPnt3fPropertyPtr  pnts    = GeoPnt3fProperty ::create();
    GeoVec3fPropertyPtr  norms   = GeoVec3fProperty ::create();
    GeoVec2fPropertyPtr  tex     = GeoVec2fProperty ::create();
    GeoUInt32PropertyPtr index   = GeoUInt32Property::create();
    GeoUInt32PropertyPtr tcindex = GeoUInt32Property::create();
    GeoUInt32PropertyPtr lens    = GeoUInt32Property::create();
    GeoUInt8PropertyPtr  types   = GeoUInt8Property ::create();

    UInt32              j,z;

    static Vec3f v[12] = {  Vec3f(-X, 0.,  Z),
                            Vec3f( X, 0.,  Z),
                            Vec3f(-X, 0., -Z),
                            Vec3f( X, 0., -Z),
                            Vec3f(0.,  Z,  X),
                            Vec3f(0.,  Z, -X),
                            Vec3f(0., -Z,  X),
                            Vec3f(0., -Z, -X),
                            Vec3f( Z,  X, 0.),
                            Vec3f(-Z,  X, 0.),
                            Vec3f( Z, -X, 0.),
                            Vec3f(-Z, -X, 0.)  };

    Quaternion q(Vec3f(0,1,0), osgACos(Z) + HalfPi);
    Matrix mat;

    mat.setTransform(q);

    for (j=0; j<12; j++)
        mat.mult(v[j]);

    Int32 tr[20][3] = { {1,4,0},  {4,9,0},  {4,5,9},  {8,5,4},  {1,8,4},
                        {1,10,8}, {10,3,8}, {8,3,5},  {3,2,5},  {3,7,2},
                        {3,10,7}, {10,6,7}, {6,11,7}, {6,0,11}, {6,1,0},
                        {10,1,6}, {11,0,9}, {2,11,9}, {5,2,9},  {11,2,7} };

    GeoPnt3fProperty::StoredFieldType  *p  = pnts ->editFieldPtr();
    GeoVec3fProperty::StoredFieldType  *n  = norms->editFieldPtr();
    GeoVec2fProperty::StoredFieldType  *tx = tex  ->editFieldPtr();

    GeoUInt32Property::StoredFieldType *i   = index  ->editFieldPtr();
    GeoUInt32Property::StoredFieldType *tci = tcindex->editFieldPtr();

    // initial sizing to prevent reallocation halfway through
    UInt32 estimatedSize = UInt32(osgPow(4.f, (Real32) depth) * 20.f);

    p->reserve (estimatedSize);
    n->reserve (estimatedSize);
    tx->reserve(estimatedSize);
    i->reserve (estimatedSize);
    tci->reserve (estimatedSize);

    // add the initial points to the fields
    for (j=0; j<12; j++)
    {
        Vec3f pnt = v[j];
        Vec3f norm = v[j];

        setVecLen(pnt, radius);
        norm.normalize();

        p->push_back(pnt.addToZero());
        n->push_back(norm);

        Vec2f texCoord;

        // Theta -> v
        texCoord[1] = (Pi - osgACos(norm[1])) / Pi;

        // Phi -> u
        texCoord[0] = calcTexS(norm, texCoord[1]);

        tx->push_back(texCoord);
    }

    // subdivide the triangles
    z=12;
    for(j=0; j<20; j++)
    {
        subdivideTriangle(tr[j][0], tr[j][1], tr[j][2],
                          depth, p, n, tx, i, tci, z, radius);
    }

    types->push_back(GL_TRIANGLES);
    lens->push_back(i->size());

    // create the geometry
    GeometryPtr geo = Geometry::create();

    geo->setMaterial(getDefaultMaterial());
    geo->setPositions(pnts);
    geo->setNormals(norms);
    geo->setTexCoords(tex);
    geo->setIndices(index);
    geo->setIndex(tcindex, Geometry::TexCoordsIndex);
    geo->setTypes(types);
    geo->setLengths(lens);


#if 0 // not sure what this was needed for??? *DR*
    // now check triangles
    beginEditCP(geo);

    for (TriangleIterator ti = geo->beginTriangles();
                          ti != geo->endTriangles(); ++ti)
    {
        Vec3f q[3];
        q[0] = ti.getNormal(0);
        q[1] = ti.getNormal(1);
        q[2] = ti.getNormal(2);

        if  ( (osgAbs(q[0][0]) <= 0.01 && q[0][2] >= Eps) ||
              (osgAbs(q[1][0]) <= 0.01 && q[1][2] >= Eps) ||
              (osgAbs(q[2][0]) <= 0.01 && q[2][2] >= Eps) )
        {
            for (UInt16 i=0; i<3; i++)
            {
                Vec3f norm(q[i]);

                if (osgAbs(norm[0]) <= Eps && norm[2] <= Eps)
                {
                    Real32 theta = ti.getTexCoords(i).y();

                    if( !(q[0][0] <= -Eps ||
                          q[1][0] <= -Eps ||
                          q[2][0] <= -Eps  ) )
                    {
                        Vec2f texCoord(1, theta);

                        if(osgAbs(osgAbs(norm[1]) - 1) <= Eps)
                            texCoord[0] = 0.5;

                        tex->push_back(texCoord);

                        tcindex->setValue( tex->size() - 1, ti.getTexCoordsIndex(i));
                    }
                    else
                    {
                        Vec2f texCoord(0, theta);

                        if (osgAbs(osgAbs(norm[1]) - 1) <= Eps)
                            texCoord[0] = 0.5;

                        tex->push_back(texCoord);

                        index->setValue( tex->size() - 1, ti.getTexCoordsIndex(i));
                    }
                }
            }
        }
    }

    endEditCP(geo);
#endif

    return geo;
}

/*! Creates a sphere centered in the origin and divided in latitude
    and longitude. \a radius is the radius of the sphere, \a latres and
    \a longres are the number of subdivisions along the latitudes and longitudes.

    \param[in] latres Number of subdivisions along latitudes.
    \param[in] longres Number of subdivisions along longitudes.
    \param[in] radius Radius of sphere.
    \return NodePtr to a newly created Node with a Geometry core.

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
NodePtr makeLatLongSphere(UInt16 latres, UInt16 longres, Real32 radius)
{
    GeometryPtr pGeo = makeLatLongSphereGeo(latres, longres, radius);

    if(pGeo == NullFC)
    {
        return NullFC;
    }

    NodePtr node = Node::create();

    node->setCore(pGeo);

    return node;
}

/*! Create the Geometry Core used by OSG::makeLatLongSphere.

    \param[in] latres Number of subdivisions along latitudes.
    \param[in] longres Number of subdivisions along longitudes.
    \param[in] radius Radius of sphere.
    \return GeometryPtr to a newly created Geometry core.

    \sa OSG::makeLatLongSphere

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
GeometryPtr makeLatLongSphereGeo(UInt16 latres, UInt16 longres,
                                      Real32 radius)
{
    if(radius <= 0 || latres < 4 || longres < 4)
    {
        SWARNING << "makeLatLongSphere: illegal parameters "
                 << "latres=" << latres
                 << ", longres=" << longres
                 << ", radius=" << radius
                 << std::endl;
        return NullFC;
    }

    GeoPnt3fPropertyPtr  pnts  = GeoPnt3fProperty ::create();
    GeoVec3fPropertyPtr  norms = GeoVec3fProperty ::create();
    GeoVec2fPropertyPtr  tex   = GeoVec2fProperty ::create();
    GeoUInt32PropertyPtr index = GeoUInt32Property::create();
    GeoUInt32PropertyPtr lens  = GeoUInt32Property::create();
    GeoUInt8PropertyPtr  types = GeoUInt8Property ::create();

    UInt16 a, b;
    Real32 theta, phi;
    Real32 cosTheta, sinTheta;
    Real32 latDelta, longDelta;

    // calc the vertices

    GeoPnt3fProperty::StoredFieldType  *p  = pnts ->editFieldPtr();
    GeoVec3fProperty::StoredFieldType  *n  = norms->editFieldPtr();
    GeoVec2fProperty::StoredFieldType  *tx = tex  ->editFieldPtr();

    latDelta  =       Pi / latres;
    longDelta = 2.f * Pi / longres;

    for(a = 0, theta = -Pi / 2; a <= latres; a++, theta += latDelta)
    {
        cosTheta = osgCos(theta);
        sinTheta = osgSin(theta);

        for(b = 0, phi = -Pi; b <= longres; b++, phi += longDelta)
        {
            GLfloat cosPhi, sinPhi;

            cosPhi = osgCos(phi);
            sinPhi = osgSin(phi);

            n->push_back(Vec3f( cosTheta * sinPhi,
                               sinTheta,
                               cosTheta * cosPhi));
            p->push_back(Pnt3f( cosTheta * sinPhi * radius,
                               sinTheta          * radius,
                               cosTheta * cosPhi * radius));
            tx->push_back(Vec2f(b / (Real32)longres,
                               a / (Real32)latres));
        }
    }

    // create the faces

    GeoUInt32Property::StoredFieldType *i  = index->editFieldPtr();
    GeoUInt32Property::StoredFieldType *l  = lens ->editFieldPtr();
    GeoUInt8Property::StoredFieldType  *t  = types->editFieldPtr();

    for(a = 0; a < longres; a++)
    {
        t->push_back(GL_TRIANGLE_STRIP);
        l->push_back((latres + 1) * 2);

        for(b = 0; b <= latres; b++)
        {
            i->push_back(b * (longres+1) + a);
            i->push_back(b * (longres+1) + a + 1);
        }
    }

    // create the geometry

    GeometryPtr geo = Geometry::create();

    geo->setMaterial(getDefaultMaterial());
    geo->setPositions(pnts);
    geo->setNormals(norms);
    geo->setTexCoords(tex);
    geo->setIndices(index);
    geo->setTypes(types);
    geo->setLengths(lens);

    return geo;
}

/*! Creates a box around the origin. It spans the [-\a xsize /2,\a
    xsize /2] x [-\a ysize /2, \a ysize/2] x [-\a zsize /2,\a zsize/2] volume
    and is subdivided into \a hor * \a vert * \a depth quads.

    \param[in] xsize Length of edge along the x axis.
    \param[in] ysize Length of edge along the y axis.
    \param[in] zsize Length of edge along the z axis.
    \param[in] hor Number of quads along the x axis.
    \param[in] vert Number of quads along the y axis.
    \param[in] depth Number of quads along the z axis.
    \return NodePtr to a newly created Node with a Geometry core.

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
NodePtr makeBox(Real32 xsize, Real32 ysize, Real32 zsize,
                     UInt16 hor  , UInt16 vert , UInt16 depth)
{
    GeometryPtr pGeo = makeBoxGeo(xsize, ysize, zsize, hor, vert, depth);

    if(pGeo == NullFC)
    {
        return NullFC;
    }

    NodePtr node = Node::create();

    node->setCore(pGeo);

    return node;
}

/*! Create the Geometry Core used by OSG::makeBox.

    \param[in] xsize Length of edge along the x axis.
    \param[in] ysize Length of edge along the y axis.
    \param[in] zsize Length of edge along the z axis.
    \param[in] hor Number of quads along the x axis.
    \param[in] vert Number of quads along the y axis.
    \param[in] depth Number of quads along the z axis.
    \return GeometryPtr to a newly created Geometry core.

    \sa OSG::makeBox

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
GeometryPtr makeBoxGeo(Real32 xsize, Real32 ysize, Real32 zsize,
                       UInt16 hor  , UInt16 vert , UInt16 depth)
{
    if(! hor || ! vert || ! depth)
    {
        SWARNING << "makeBox: illegal parameters hor=" << hor << ", vert="
                 << vert << ", depth=" << depth << std::endl;
        return NullFC;
    }

    GeoPnt3fPropertyPtr  pnts  = GeoPnt3fProperty ::create();
    GeoVec3fPropertyPtr  norms = GeoVec3fProperty ::create();
    GeoVec2fPropertyPtr  tex   = GeoVec2fProperty ::create();
    GeoUInt32PropertyPtr index = GeoUInt32Property::create();
    GeoUInt32PropertyPtr lens  = GeoUInt32Property::create();
    GeoUInt8PropertyPtr  types = GeoUInt8Property ::create();

    UInt16 x,y,pl;
    Vec3f size(xsize,  ysize,  zsize);
    Vec3f step(xsize / hor, ysize / vert, zsize / depth);
    Vec3f res(hor,  vert,  depth);

    // calc the vertices

    GeoPnt3fProperty::StoredFieldType  *p  = pnts ->editFieldPtr();
    GeoVec3fProperty::StoredFieldType  *n  = norms->editFieldPtr();
    GeoVec2fProperty::StoredFieldType  *tx = tex  ->editFieldPtr();

    static int inds[6][2] =  { {0,1}, {0,1}, {2,1}, {2,1}, {0,2}, {0,2} };
    static int signs[6][2] = { {1,1}, {-1,1}, {-1,1}, {1,1}, {1,-1}, {1,1} };
    static int asigns[6] = { 1, -1, 1, -1, 1, -1 };

    for(pl = 0; pl < 6; pl++)
    {
        UInt16 axis = 3 - inds[pl][0] - inds[pl][1];

        for(y = 0; y <= res[inds[pl][1]] ; y++)
        {
            for(x = 0; x <= res[inds[pl][0]]; x++)
            {
                Pnt3f pnt;
                pnt[ inds[pl][0] ] = (x * step[inds[pl][0]] - size[inds[pl][0]] / 2) *
                                        signs[pl][0];
                pnt[ inds[pl][1] ] = (y * step[inds[pl][1]] - size[inds[pl][1]] / 2) *
                                        signs[pl][1];
                pnt[ axis ] = size[ axis ] * asigns[ pl ] / 2;
                p->push_back(pnt);

                Vec3f norm(0, 0, 0);
                norm[ axis ] = Real32(asigns[ pl ]);
                n->push_back(norm);
                tx->push_back(Vec2f(x / (Real32) res[inds[pl][0]],
                                    y / (Real32) res[inds[pl][1]]));
            }
        }
    }

    // create the faces

    GeoUInt32Property::StoredFieldType *i  = index->editFieldPtr();
    GeoUInt32Property::StoredFieldType *l  = lens ->editFieldPtr();
    GeoUInt8Property::StoredFieldType  *t  = types->editFieldPtr();

    UInt32 basepoint = 0;

    for(pl = 0; pl < 6; pl++)
    {
        for(y = 0; y < res[inds[pl][1]]; y++)
        {
            UInt16 h = UInt16(res[inds[pl][0]]);

            t->push_back(GL_TRIANGLE_STRIP);
            l->push_back(2 * (h + 1));

            for(x = 0; x <= h; x++)
            {
                i->push_back(basepoint + (y + 1) * (h + 1) + x);
                i->push_back(basepoint +  y      * (h + 1) + x);
            }
        }
        basepoint += UInt32((res[inds[pl][0]] + 1.f) *
                            (res[inds[pl][1]] + 1.f) );
    }

    // create the geometry

    GeometryPtr geo = Geometry::create();

    geo->setMaterial(getDefaultMaterial());
    geo->setPositions(pnts);
    geo->setNormals(norms);
    geo->setTexCoords(tex);
    geo->setIndices(index);
    geo->setTypes(types);
    geo->setLengths(lens);

    return geo;
}

/*! Create a model of the famous Utah teapot, based on Eric Haines' SPD code
    (http://www1.acm.org/tog/resources/SPD).

    \param[in] depth Subdivision depth.
    \return NodePtr to a newly created Node with a Geometry core.

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
NodePtr makeTeapot(UInt16 depth)
{
    GeometryPtr pGeo = makeTeapotGeo(depth);

    if(pGeo == NullFC)
    {
        return NullFC;
    }

    NodePtr node = Node::create();

    node->setCore(pGeo);

    return node;
}

namespace {

// Teapot data and helper functions

/* Teapot function. Taken from Eric Haines' SPD package
   (http://www1.acm.org/tog/resources/SPD)

   Slightly C++-ized for OpenSG
 */

/* comment out the next line to generate all patches except the bottom,
 * i.e. the original Newell teapot
 */
#define BOTTOM

#ifdef BOTTOM
#define NUM_PATCHES 32
#else
#define NUM_PATCHES 28
#endif

static int Patches[32][4][4] = {
/* rim */
{{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}},
{{3, 16, 17, 18}, {7, 19, 20, 21}, {11, 22, 23, 24}, {15, 25, 26, 27}},
{{18, 28, 29, 30}, {21, 31, 32, 33}, {24, 34, 35, 36}, {27, 37, 38, 39}},
{{30, 40, 41, 0}, {33, 42, 43, 4}, {36, 44, 45, 8}, {39, 46, 47, 12}},
/* body */
{{12, 13, 14, 15}, {48, 49, 50, 51}, {52, 53, 54, 55}, {56, 57, 58, 59}},
{{15, 25, 26, 27}, {51, 60, 61, 62}, {55, 63, 64, 65}, {59, 66, 67, 68}},
{{27, 37, 38, 39}, {62, 69, 70, 71}, {65, 72, 73, 74}, {68, 75, 76, 77}},
{{39, 46, 47, 12}, {71, 78, 79, 48}, {74, 80, 81, 52}, {77, 82, 83, 56}},
{{56, 57, 58, 59}, {84, 85, 86, 87}, {88, 89, 90, 91}, {92, 93, 94, 95}},
{{59, 66, 67, 68}, {87, 96, 97, 98}, {91, 99, 100, 101}, {95, 102, 103, 104}},
{{68, 75, 76, 77}, {98, 105, 106, 107}, {101, 108, 109, 110}, {104, 111, 112, 113}},
{{77, 82, 83, 56}, {107, 114, 115, 84}, {110, 116, 117, 88}, {113, 118, 119, 92}},
/* handle */
{{120, 121, 122, 123}, {124, 125, 126, 127}, {128, 129, 130, 131}, {132, 133, 134, 135}},
{{123, 136, 137, 120}, {127, 138, 139, 124}, {131, 140, 141, 128}, {135, 142, 143, 132}},
{{132, 133, 134, 135}, {144, 145, 146, 147}, {148, 149, 150, 151}, {68, 152, 153, 154}},
{{135, 142, 143, 132}, {147, 155, 156, 144}, {151, 157, 158, 148}, {154, 159, 160, 68}},
/* spout */
{{161, 162, 163, 164}, {165, 166, 167, 168}, {169, 170, 171, 172}, {173, 174, 175, 176}},
{{164, 177, 178, 161}, {168, 179, 180, 165}, {172, 181, 182, 169}, {176, 183, 184, 173}},
{{173, 174, 175, 176}, {185, 186, 187, 188}, {189, 190, 191, 192}, {193, 194, 195, 196}},
{{176, 183, 184, 173}, {188, 197, 198, 185}, {192, 199, 200, 189}, {196, 201, 202, 193}},
/* lid */
{{203, 203, 203, 203}, {204, 205, 206, 207}, {208, 208, 208, 208}, {209, 210, 211, 212}},
{{203, 203, 203, 203}, {207, 213, 214, 215}, {208, 208, 208, 208}, {212, 216, 217, 218}},
{{203, 203, 203, 203}, {215, 219, 220, 221}, {208, 208, 208, 208}, {218, 222, 223, 224}},
{{203, 203, 203, 203}, {221, 225, 226, 204}, {208, 208, 208, 208}, {224, 227, 228, 209}},
{{209, 210, 211, 212}, {229, 230, 231, 232}, {233, 234, 235, 236}, {237, 238, 239, 240}},
{{212, 216, 217, 218}, {232, 241, 242, 243}, {236, 244, 245, 246}, {240, 247, 248, 249}},
{{218, 222, 223, 224}, {243, 250, 251, 252}, {246, 253, 254, 255}, {249, 256, 257, 258}},
{{224, 227, 228, 209}, {252, 259, 260, 229}, {255, 261, 262, 233}, {258, 263, 264, 237}},
/* bottom */
{{265, 265, 265, 265}, {266, 267, 268, 269}, {270, 271, 272, 273}, {92, 119, 118, 113}},
{{265, 265, 265, 265}, {269, 274, 275, 276}, {273, 277, 278, 279}, {113, 112, 111, 104}},
{{265, 265, 265, 265}, {276, 280, 281, 282}, {279, 283, 284, 285}, {104, 103, 102, 95}},
{{265, 265, 265, 265}, {282, 286, 287, 266}, {285, 288, 289, 270}, {95, 94, 93, 92}}
};

static Vec3f Verts[290] = {
    Vec3f(1.4, 0, 2.4),
    Vec3f(1.4, -0.784, 2.4),
    Vec3f(0.784, -1.4, 2.4),
    Vec3f(0, -1.4, 2.4),
    Vec3f(1.3375, 0, 2.53125),
    Vec3f(1.3375, -0.749, 2.53125),
    Vec3f(0.749, -1.3375, 2.53125),
    Vec3f(0, -1.3375, 2.53125),
    Vec3f(1.4375, 0, 2.53125),
    Vec3f(1.4375, -0.805, 2.53125),
    Vec3f(0.805, -1.4375, 2.53125),
    Vec3f(0, -1.4375, 2.53125),
    Vec3f(1.5, 0, 2.4),
    Vec3f(1.5, -0.84, 2.4),
    Vec3f(0.84, -1.5, 2.4),
    Vec3f(0, -1.5, 2.4),
    Vec3f(-0.784, -1.4, 2.4),
    Vec3f(-1.4, -0.784, 2.4),
    Vec3f(-1.4, 0, 2.4),
    Vec3f(-0.749, -1.3375, 2.53125),
    Vec3f(-1.3375, -0.749, 2.53125),
    Vec3f(-1.3375, 0, 2.53125),
    Vec3f(-0.805, -1.4375, 2.53125),
    Vec3f(-1.4375, -0.805, 2.53125),
    Vec3f(-1.4375, 0, 2.53125),
    Vec3f(-0.84, -1.5, 2.4),
    Vec3f(-1.5, -0.84, 2.4),
    Vec3f(-1.5, 0, 2.4),
    Vec3f(-1.4, 0.784, 2.4),
    Vec3f(-0.784, 1.4, 2.4),
    Vec3f(0, 1.4, 2.4),
    Vec3f(-1.3375, 0.749, 2.53125),
    Vec3f(-0.749, 1.3375, 2.53125),
    Vec3f(0, 1.3375, 2.53125),
    Vec3f(-1.4375, 0.805, 2.53125),
    Vec3f(-0.805, 1.4375, 2.53125),
    Vec3f(0, 1.4375, 2.53125),
    Vec3f(-1.5, 0.84, 2.4),
    Vec3f(-0.84, 1.5, 2.4),
    Vec3f(0, 1.5, 2.4),
    Vec3f(0.784, 1.4, 2.4),
    Vec3f(1.4, 0.784, 2.4),
    Vec3f(0.749, 1.3375, 2.53125),
    Vec3f(1.3375, 0.749, 2.53125),
    Vec3f(0.805, 1.4375, 2.53125),
    Vec3f(1.4375, 0.805, 2.53125),
    Vec3f(0.84, 1.5, 2.4),
    Vec3f(1.5, 0.84, 2.4),
    Vec3f(1.75, 0, 1.875),
    Vec3f(1.75, -0.98, 1.875),
    Vec3f(0.98, -1.75, 1.875),
    Vec3f(0, -1.75, 1.875),
    Vec3f(2, 0, 1.35),
    Vec3f(2, -1.12, 1.35),
    Vec3f(1.12, -2, 1.35),
    Vec3f(0, -2, 1.35),
    Vec3f(2, 0, 0.9),
    Vec3f(2, -1.12, 0.9),
    Vec3f(1.12, -2, 0.9),
    Vec3f(0, -2, 0.9),
    Vec3f(-0.98, -1.75, 1.875),
    Vec3f(-1.75, -0.98, 1.875),
    Vec3f(-1.75, 0, 1.875),
    Vec3f(-1.12, -2, 1.35),
    Vec3f(-2, -1.12, 1.35),
    Vec3f(-2, 0, 1.35),
    Vec3f(-1.12, -2, 0.9),
    Vec3f(-2, -1.12, 0.9),
    Vec3f(-2, 0, 0.9),
    Vec3f(-1.75, 0.98, 1.875),
    Vec3f(-0.98, 1.75, 1.875),
    Vec3f(0, 1.75, 1.875),
    Vec3f(-2, 1.12, 1.35),
    Vec3f(-1.12, 2, 1.35),
    Vec3f(0, 2, 1.35),
    Vec3f(-2, 1.12, 0.9),
    Vec3f(-1.12, 2, 0.9),
    Vec3f(0, 2, 0.9),
    Vec3f(0.98, 1.75, 1.875),
    Vec3f(1.75, 0.98, 1.875),
    Vec3f(1.12, 2, 1.35),
    Vec3f(2, 1.12, 1.35),
    Vec3f(1.12, 2, 0.9),
    Vec3f(2, 1.12, 0.9),
    Vec3f(2, 0, 0.45),
    Vec3f(2, -1.12, 0.45),
    Vec3f(1.12, -2, 0.45),
    Vec3f(0, -2, 0.45),
    Vec3f(1.5, 0, 0.225),
    Vec3f(1.5, -0.84, 0.225),
    Vec3f(0.84, -1.5, 0.225),
    Vec3f(0, -1.5, 0.225),
    Vec3f(1.5, 0, 0.15),
    Vec3f(1.5, -0.84, 0.15),
    Vec3f(0.84, -1.5, 0.15),
    Vec3f(0, -1.5, 0.15),
    Vec3f(-1.12, -2, 0.45),
    Vec3f(-2, -1.12, 0.45),
    Vec3f(-2, 0, 0.45),
    Vec3f(-0.84, -1.5, 0.225),
    Vec3f(-1.5, -0.84, 0.225),
    Vec3f(-1.5, 0, 0.225),
    Vec3f(-0.84, -1.5, 0.15),
    Vec3f(-1.5, -0.84, 0.15),
    Vec3f(-1.5, 0, 0.15),
    Vec3f(-2, 1.12, 0.45),
    Vec3f(-1.12, 2, 0.45),
    Vec3f(0, 2, 0.45),
    Vec3f(-1.5, 0.84, 0.225),
    Vec3f(-0.84, 1.5, 0.225),
    Vec3f(0, 1.5, 0.225),
    Vec3f(-1.5, 0.84, 0.15),
    Vec3f(-0.84, 1.5, 0.15),
    Vec3f(0, 1.5, 0.15),
    Vec3f(1.12, 2, 0.45),
    Vec3f(2, 1.12, 0.45),
    Vec3f(0.84, 1.5, 0.225),
    Vec3f(1.5, 0.84, 0.225),
    Vec3f(0.84, 1.5, 0.15),
    Vec3f(1.5, 0.84, 0.15),
    Vec3f(-1.6, 0, 2.025),
    Vec3f(-1.6, -0.3, 2.025),
    Vec3f(-1.5, -0.3, 2.25),
    Vec3f(-1.5, 0, 2.25),
    Vec3f(-2.3, 0, 2.025),
    Vec3f(-2.3, -0.3, 2.025),
    Vec3f(-2.5, -0.3, 2.25),
    Vec3f(-2.5, 0, 2.25),
    Vec3f(-2.7, 0, 2.025),
    Vec3f(-2.7, -0.3, 2.025),
    Vec3f(-3, -0.3, 2.25),
    Vec3f(-3, 0, 2.25),
    Vec3f(-2.7, 0, 1.8),
    Vec3f(-2.7, -0.3, 1.8),
    Vec3f(-3, -0.3, 1.8),
    Vec3f(-3, 0, 1.8),
    Vec3f(-1.5, 0.3, 2.25),
    Vec3f(-1.6, 0.3, 2.025),
    Vec3f(-2.5, 0.3, 2.25),
    Vec3f(-2.3, 0.3, 2.025),
    Vec3f(-3, 0.3, 2.25),
    Vec3f(-2.7, 0.3, 2.025),
    Vec3f(-3, 0.3, 1.8),
    Vec3f(-2.7, 0.3, 1.8),
    Vec3f(-2.7, 0, 1.575),
    Vec3f(-2.7, -0.3, 1.575),
    Vec3f(-3, -0.3, 1.35),
    Vec3f(-3, 0, 1.35),
    Vec3f(-2.5, 0, 1.125),
    Vec3f(-2.5, -0.3, 1.125),
    Vec3f(-2.65, -0.3, 0.9375),
    Vec3f(-2.65, 0, 0.9375),
    Vec3f(-2, -0.3, 0.9),
    Vec3f(-1.9, -0.3, 0.6),
    Vec3f(-1.9, 0, 0.6),
    Vec3f(-3, 0.3, 1.35),
    Vec3f(-2.7, 0.3, 1.575),
    Vec3f(-2.65, 0.3, 0.9375),
    Vec3f(-2.5, 0.3, 1.125),
    Vec3f(-1.9, 0.3, 0.6),
    Vec3f(-2, 0.3, 0.9),
    Vec3f(1.7, 0, 1.425),
    Vec3f(1.7, -0.66, 1.425),
    Vec3f(1.7, -0.66, 0.6),
    Vec3f(1.7, 0, 0.6),
    Vec3f(2.6, 0, 1.425),
    Vec3f(2.6, -0.66, 1.425),
    Vec3f(3.1, -0.66, 0.825),
    Vec3f(3.1, 0, 0.825),
    Vec3f(2.3, 0, 2.1),
    Vec3f(2.3, -0.25, 2.1),
    Vec3f(2.4, -0.25, 2.025),
    Vec3f(2.4, 0, 2.025),
    Vec3f(2.7, 0, 2.4),
    Vec3f(2.7, -0.25, 2.4),
    Vec3f(3.3, -0.25, 2.4),
    Vec3f(3.3, 0, 2.4),
    Vec3f(1.7, 0.66, 0.6),
    Vec3f(1.7, 0.66, 1.425),
    Vec3f(3.1, 0.66, 0.825),
    Vec3f(2.6, 0.66, 1.425),
    Vec3f(2.4, 0.25, 2.025),
    Vec3f(2.3, 0.25, 2.1),
    Vec3f(3.3, 0.25, 2.4),
    Vec3f(2.7, 0.25, 2.4),
    Vec3f(2.8, 0, 2.475),
    Vec3f(2.8, -0.25, 2.475),
    Vec3f(3.525, -0.25, 2.49375),
    Vec3f(3.525, 0, 2.49375),
    Vec3f(2.9, 0, 2.475),
    Vec3f(2.9, -0.15, 2.475),
    Vec3f(3.45, -0.15, 2.5125),
    Vec3f(3.45, 0, 2.5125),
    Vec3f(2.8, 0, 2.4),
    Vec3f(2.8, -0.15, 2.4),
    Vec3f(3.2, -0.15, 2.4),
    Vec3f(3.2, 0, 2.4),
    Vec3f(3.525, 0.25, 2.49375),
    Vec3f(2.8, 0.25, 2.475),
    Vec3f(3.45, 0.15, 2.5125),
    Vec3f(2.9, 0.15, 2.475),
    Vec3f(3.2, 0.15, 2.4),
    Vec3f(2.8, 0.15, 2.4),
    Vec3f(0, 0, 3.15),
    Vec3f(0.8, 0, 3.15),
    Vec3f(0.8, -0.45, 3.15),
    Vec3f(0.45, -0.8, 3.15),
    Vec3f(0, -0.8, 3.15),
    Vec3f(0, 0, 2.85),
    Vec3f(0.2, 0, 2.7),
    Vec3f(0.2, -0.112, 2.7),
    Vec3f(0.112, -0.2, 2.7),
    Vec3f(0, -0.2, 2.7),
    Vec3f(-0.45, -0.8, 3.15),
    Vec3f(-0.8, -0.45, 3.15),
    Vec3f(-0.8, 0, 3.15),
    Vec3f(-0.112, -0.2, 2.7),
    Vec3f(-0.2, -0.112, 2.7),
    Vec3f(-0.2, 0, 2.7),
    Vec3f(-0.8, 0.45, 3.15),
    Vec3f(-0.45, 0.8, 3.15),
    Vec3f(0, 0.8, 3.15),
    Vec3f(-0.2, 0.112, 2.7),
    Vec3f(-0.112, 0.2, 2.7),
    Vec3f(0, 0.2, 2.7),
    Vec3f(0.45, 0.8, 3.15),
    Vec3f(0.8, 0.45, 3.15),
    Vec3f(0.112, 0.2, 2.7),
    Vec3f(0.2, 0.112, 2.7),
    Vec3f(0.4, 0, 2.55),
    Vec3f(0.4, -0.224, 2.55),
    Vec3f(0.224, -0.4, 2.55),
    Vec3f(0, -0.4, 2.55),
    Vec3f(1.3, 0, 2.55),
    Vec3f(1.3, -0.728, 2.55),
    Vec3f(0.728, -1.3, 2.55),
    Vec3f(0, -1.3, 2.55),
    Vec3f(1.3, 0, 2.4),
    Vec3f(1.3, -0.728, 2.4),
    Vec3f(0.728, -1.3, 2.4),
    Vec3f(0, -1.3, 2.4),
    Vec3f(-0.224, -0.4, 2.55),
    Vec3f(-0.4, -0.224, 2.55),
    Vec3f(-0.4, 0, 2.55),
    Vec3f(-0.728, -1.3, 2.55),
    Vec3f(-1.3, -0.728, 2.55),
    Vec3f(-1.3, 0, 2.55),
    Vec3f(-0.728, -1.3, 2.4),
    Vec3f(-1.3, -0.728, 2.4),
    Vec3f(-1.3, 0, 2.4),
    Vec3f(-0.4, 0.224, 2.55),
    Vec3f(-0.224, 0.4, 2.55),
    Vec3f(0, 0.4, 2.55),
    Vec3f(-1.3, 0.728, 2.55),
    Vec3f(-0.728, 1.3, 2.55),
    Vec3f(0, 1.3, 2.55),
    Vec3f(-1.3, 0.728, 2.4),
    Vec3f(-0.728, 1.3, 2.4),
    Vec3f(0, 1.3, 2.4),
    Vec3f(0.224, 0.4, 2.55),
    Vec3f(0.4, 0.224, 2.55),
    Vec3f(0.728, 1.3, 2.55),
    Vec3f(1.3, 0.728, 2.55),
    Vec3f(0.728, 1.3, 2.4),
    Vec3f(1.3, 0.728, 2.4),
    Vec3f(0, 0, 0),
    Vec3f(1.425, 0, 0),
    Vec3f(1.425, 0.798, 0),
    Vec3f(0.798, 1.425, 0),
    Vec3f(0, 1.425, 0),
    Vec3f(1.5, 0, 0.075),
    Vec3f(1.5, 0.84, 0.075),
    Vec3f(0.84, 1.5, 0.075),
    Vec3f(0, 1.5, 0.075),
    Vec3f(-0.798, 1.425, 0),
    Vec3f(-1.425, 0.798, 0),
    Vec3f(-1.425, 0, 0),
    Vec3f(-0.84, 1.5, 0.075),
    Vec3f(-1.5, 0.84, 0.075),
    Vec3f(-1.5, 0, 0.075),
    Vec3f(-1.425, -0.798, 0),
    Vec3f(-0.798, -1.425, 0),
    Vec3f(0, -1.425, 0),
    Vec3f(-1.5, -0.84, 0.075),
    Vec3f(-0.84, -1.5, 0.075),
    Vec3f(0, -1.5, 0.075),
    Vec3f(0.798, -1.425, 0),
    Vec3f(1.425, -0.798, 0),
    Vec3f(0.84, -1.5, 0.075),
    Vec3f(1.5, -0.84, 0.075)
};

/* at the center of the lid's handle and at bottom are cusp points -
 * check if normal is (0 0 0), if so, check that polygon is not degenerate.
 * If degenerate, return FALSE, else set normal.
 */
static bool
check_for_cusp( int tot_vert, Pnt3f vert[], Vec3f norm[] )
{
    int count, i, nv ;

    for(count = 0, i = tot_vert; i--; )
    {
        /* check if vertex is at cusp */
        if(osgAbs(vert[i][0]) < 0.0001 &&
           osgAbs(vert[i][1]) < 0.0001    )
        {
            count++;
            nv = i;
        }
    }

    if(count > 1)
    {
        /* degenerate */
        return  false;
    }
    if(count == 1)
    {
        /* check if point is somewhere above the middle of the teapot */
        if(vert[nv][2] > 1.5)
        {
            /* cusp at lid */
            norm[nv].setValues(0.0, 0.0, 1.0);
        }
        else
        {
            /* cusp at bottom */
            norm[nv].setValues(0.0, 0.0, -1.0);
        }
    }
    return true;
}

static void
points_from_basis(int tot_vert, Real64 s[], Real64 t[], Matrix mgm[3],
    Pnt3f vert[], Vec3f norm[] )
{
    int    i, num_vert, p;
    double sval, tval, dsval, dtval, sxyz, txyz;
    Vec3f  sdir, tdir;
    Vec4f  sp, tp, dsp, dtp, tcoord;

    for(num_vert = 0; num_vert < tot_vert; num_vert++)
    {
        sxyz = s[num_vert] ;
        txyz = t[num_vert] ;

        /* get power vectors and their derivatives */
        for(p = 4, sval = tval = 1.0; p--; )
        {
            sp[p] = sval;
            tp[p] = tval;
            sval *= sxyz;
            tval *= txyz;

            if(p == 3)
            {
                dsp[p] = dtp[p] = 0.0;
                dsval  = dtval  = 1.0;
            }
            else
            {
                dsp[p] = dsval * static_cast<double>(3 - p);
                dtp[p] = dtval * static_cast<double>(3 - p);
                dsval *= sxyz;
                dtval *= txyz;
            }
        }

        /* do for x,y,z */
        for(i = 0; i < 3; ++i)
        {
            /* multiply power vectors times matrix to get value */
            mgm[i].multMatrixVec(sp, tcoord);
            vert[num_vert][i] = tcoord.dot(tp);

            /* get s and t tangent vectors */
            mgm[i].multMatrixVec(dsp, tcoord);
            sdir[i] = tcoord.dot(tp);

            mgm[i].multMatrixVec(sp, tcoord);
            tdir[i] = tcoord.dot(dtp);
        }

        /* find normal */
        norm[num_vert] = tdir.cross(sdir);
        norm[num_vert].normalize();
    }
}

} // namespace

/*! Create the Geometry Core used by OSG::makeTeapot.

    \param[in] depth Subdivision depth.
    \return GeometryPtr to a newly created Geometry core.

    \sa OSG::makeTeapot

    \ingroup GrpSystemDrawablesGeometrySimpleGeometry
 */
GeometryPtr makeTeapotGeo(UInt16 depth)
{
    GeoPnt3fPropertyPtr  pnts  = GeoPnt3fProperty ::create();
    GeoVec3fPropertyPtr  norms = GeoVec3fProperty ::create();
    GeoUInt32PropertyPtr lens  = GeoUInt32Property::create();
    GeoUInt8PropertyPtr  types = GeoUInt8Property ::create();

    // calc the triangles

    GeoPnt3fProperty::StoredFieldType  *p  = pnts ->editFieldPtr();
    GeoVec3fProperty::StoredFieldType  *n  = norms->editFieldPtr();

    UInt32 vcount = 0;

    /* bezier form */
    static Matrix ms( -1.0,  3.0, -3.0,  1.0,
                       3.0, -6.0,  3.0,  0.0,
                      -3.0,  3.0,  0.0,  0.0,
                       1.0,  0.0,  0.0,  0.0 );
    int    surf, i, r, c, sstep, tstep, num_tri, num_vert, num_tri_vert;
    double s[3], t[3];
    Pnt3f  vert[4];
    Vec3f  norm[4];
    Matrix mst, g, mgm[3], tmtx;

    mst.transposeFrom(ms);

    for(surf = 0; surf < NUM_PATCHES; ++surf)
    {
        /* get M * G * M matrix for x,y,z */
        for(i = 0; i < 3; ++i)
        {
            /* get control patches */
            for(r = 0; r < 4 ; ++r)
            {
                for(c = 0; c < 4; ++c)
                {
                    g[r][c] = Verts[Patches[surf][r][c]][i];
                }
            }

            tmtx = ms;
            tmtx.mult(g);
            tmtx.mult(mst);
            mgm[i] = tmtx;
        }

        /* step along, get points, and output */
        for(sstep = 0; sstep < depth; ++sstep)
        {
            for(tstep = 0; tstep < depth; ++tstep)
            {
                for(num_tri = 0; num_tri < 2; ++num_tri)
                {
                    for(num_vert = 0; num_vert < 3; ++num_vert)
                    {
                        num_tri_vert = (num_vert + num_tri * 2) % 4;
                        /* trickiness: add 1 to sstep if 1 or 2 */
                        s[num_vert] = static_cast<double>(
                                        sstep + (num_tri_vert / 2 ? 1 : 0)) /
                                            static_cast<double>(depth);

                        /* trickiness: add 1 to tstep if 2 or 3 */
                        t[num_vert] = static_cast<double>(
                                        tstep + (num_tri_vert % 3 ? 1 : 0)) /
                                            static_cast<double>(depth);
                    }
                    points_from_basis(3, s, t, mgm, vert, norm);
                    /* don't output degenerate polygons */
                    if(check_for_cusp( 3, vert, norm))
                    {
                        p->push_back(vert[0]);
                        p->push_back(vert[1]);
                        p->push_back(vert[2]);

                        n->push_back(norm[0]);
                        n->push_back(norm[1]);
                        n->push_back(norm[2]);

                        vcount += 3;
                    }
                }
            }
        }
    }

    types->push_back(GL_TRIANGLES);
    lens ->push_back(vcount);

    // create the geometry

    GeometryPtr geo = Geometry::create();

    geo->setMaterial(getDefaultMaterial());
    geo->setPositions(pnts);
    geo->setNormals(norms);
    geo->setTypes(types);
    geo->setLengths(lens);

    return geo;
}

NodePtr makeCoordAxis(Real32 length, Real32 lineWidth, bool showAxisName)
{
    GeometryPtr pGeo = makeCoordAxisGeo(length, lineWidth, showAxisName);

    if(pGeo == NullFC)
    {
        return NullFC;
    }

    NodePtr node = Node::create();

    node->setCore(pGeo);

    return node;
}

GeometryPtr makeCoordAxisGeo(Real32 length, Real32 lineWidth, bool showAxisName)
{
    GeoPnt3fPropertyPtr   pnts    = GeoPnt3fProperty ::create();
    GeoUInt32PropertyPtr  lens    = GeoUInt32Property::create();
    GeoUInt8PropertyPtr   types   = GeoUInt8Property ::create();
    GeoColor3fPropertyPtr colors  = GeoColors3f::create();

    Int32 pntCnt=0;

    GeoPnt3fProperty::StoredFieldType   *p = pnts ->editFieldPtr();
    GeoUInt32Property::StoredFieldType  *l = lens ->editFieldPtr();
    GeoUInt8Property::StoredFieldType   *t = types->editFieldPtr();
    GeoColor3fProperty::StoredFieldType *c = colors->editFieldPtr();

    // the x-axis coords and colors
    p->push_back( Pnt3f(0,0,0) );
    p->push_back( Pnt3f(length,0,0) );
    pntCnt += 2;
    c->push_back( Color3f(1,0,0) );
    c->push_back( Color3f(1,0,0) );

    // the y-axis coords and colors
    p->push_back( Pnt3f(0,0,0) );
    p->push_back( Pnt3f(0,length,0) );
    pntCnt += 2;
    c->push_back( Color3f(0,1,0) );
    c->push_back( Color3f(0,1,0) );

    // the z-axis coords and colors
    p->push_back( Pnt3f(0,0,0) );
    p->push_back( Pnt3f(0,0,length) );
    pntCnt += 2;
    c->push_back( Color3f(0,0,1) );
    c->push_back( Color3f(0,0,1) );

    if( showAxisName )
    {
       // the x text (drawn with lines)
       p->push_back( Pnt3f(length,         0.125,    0) );
       p->push_back( Pnt3f(length+0.25,    -0.125,    0) );
       p->push_back( Pnt3f(length,-0.125,0) );
       p->push_back( Pnt3f(length+0.25,0.125,0) );
       pntCnt += 4;
       for (unsigned i=0;i<4;i++)
       { c->push_back( Color3f(1,0,0) ); }

       // the y text (drawn with lines)
       p->push_back( Pnt3f(-0.125, length,        0) );
       p->push_back( Pnt3f( 0.125, length+0.25,    0) );
       p->push_back( Pnt3f(-0.125, length+0.25,        0) );
       p->push_back( Pnt3f( 0.000, length+0.125,0) );
       pntCnt += 4;
       for (unsigned i=0;i<4;i++)
       { c->push_back( Color3f(0,1,0) ); }

       // the z text (drawn with lines)
       p->push_back( Pnt3f(-0.125, 0,    length) );
       p->push_back( Pnt3f( 0.125, 0,    length) );
       p->push_back( Pnt3f( 0.125, 0,    length) );
       p->push_back( Pnt3f(-0.125, 0,    length+0.25) );
       p->push_back( Pnt3f(-0.125, 0,    length+0.25) );
       p->push_back( Pnt3f( 0.125, 0,    length+0.25) );
       pntCnt += 6;
       for (unsigned i=0;i<6;i++)
       { c->push_back( Color3f(0,0,1) ); }
    }


    //SLOG << "CoordAxis has " << pntCnt << " points.\n" << endl;
    t->push_back(GL_LINES);
    l->push_back(pntCnt);

    LineChunkPtr        lineChunk = LineChunk::create();
    lineChunk->setWidth(lineWidth);

    SimpleMaterialPtr    mat      = SimpleMaterial::create();
    mat->setLit(false);
    mat->addChunk(lineChunk);
    mat->setColorMaterial(GL_AMBIENT_AND_DIFFUSE);


    GeometryPtr geo = Geometry::create();
    geo->setMaterial(mat);
    geo->setPositions(pnts);
    geo->setTypes(types);
    geo->setLengths(lens);

    return geo;
}

OSG_END_NAMESPACE
