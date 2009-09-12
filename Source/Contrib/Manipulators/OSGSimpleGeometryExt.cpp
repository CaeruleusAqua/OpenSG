/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2002 by the OpenSG Forum                 *
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

#include "OSGSimpleGeometryExt.h"

#include <OSGSimpleMaterial.h>
#include <OSGLineChunk.h>
#include <OSGGroup.h>
#include <OSGSimpleGeometry.h>
#include <OSGFaceIterator.h>
#include <OSGComponentTransform.h>
#include <OSGTypedGeoVectorProperty.h>
#include <OSGTypedGeoIntegralProperty.h>

using namespace std;

OSG_BEGIN_NAMESPACE

GeometryTransitPtr makeGridGeo(const Real32   width,
                               const Real32   depth,
                               const Real32   hCellWidth,
                               const Color3f &color     )
{
    Int32       nCols, nRows;
    Real32      x, z;

    const Color3f darkerColor =
        Color3f(color[0] - 0.4, color[1] - 0.4, color[2] - 0.4);

    GeometryTransitPtr           geo     = Geometry::create();
    GeoPnt3fPropertyUnrecPtr   pnts    = GeoPnt3fProperty  ::create();
    GeoUInt32PropertyUnrecPtr  lens    = GeoUInt32Property ::create();
    GeoUInt8PropertyUnrecPtr   types   = GeoUInt8Property  ::create();
    GeoColor3fPropertyUnrecPtr colors  = GeoColor3fProperty::create();
//    GeoIndicesUI32Ptr  indices = GeoIndicesUI32::create();
    SimpleMaterialUnrecPtr  mat     = SimpleMaterial::create();

    Real32 height   (0.0        );
    Real32 widthHalf(width / 2.0);
    Real32 depthHalf(depth / 2.0);
//    hCellWidth     = 1;
    Real32 vCellWidth(hCellWidth);
    nCols        = Int32(width / hCellWidth);
    nRows        = Int32(depth / vCellWidth);

    /*
    SLOG << "creating Grid: width=" << width
         << ", depth=" << depth
         << ", hCellWidth=" << hCellWidth
         << ", vCellWidth=" << vCellWidth
         << ", nCols=" << nCols
         << ", nRows=" << nRows << endl;
    */
    Int32 pntCnt(0);

    // horizontal lines
    for( Real32 d = -nRows / 2; d <= nRows / 2; ++d )
    {
        z = d * vCellWidth;
        pnts->addValue(Pnt3f(-widthHalf, height, z));
        pnts->addValue(Pnt3f( widthHalf, height, z));
        ++pntCnt;
        ++pntCnt;
        colors->addValue(color);
        colors->addValue(color);
    }

    // vertical lines
    for( Real32 w = -nCols/2; w <= nCols/2; ++w )
    {
        x = w * hCellWidth;
        pnts->addValue(Pnt3f(x, height, -depthHalf));
        pnts->addValue(Pnt3f(x, height,  depthHalf));
        ++pntCnt;
        ++pntCnt;
        colors->addValue(color);
        colors->addValue(color);
    }

    /*
    // horizontal & vertical mid lines in different color
    pnts->addValue(Pnt3f(-widthHalf, height, 0));
    pnts->addValue(Pnt3f( widthHalf, height, 0));
    ++pntCnt;
    ++pntCnt;
    colors->addValue(darkerColor);
    colors->addValue(darkerColor);

    pnts->addValue(Pnt3f(0, height, -depthHalf));
    pnts->addValue(Pnt3f(0, height,  depthHalf));
    ++pntCnt;
    ++pntCnt;
    colors->addValue(darkerColor);
    colors->addValue(darkerColor);
    */

    //SLOG << "Grid has " << pntCnt << " points.\n" << endl;

    types->addValue(GL_LINES);
    lens->addValue (pntCnt  );

    // set the color for the grid
    mat->setAmbient(color);
    mat->setDiffuse(color);
    mat->setLit    (false);

    geo->setPositions(pnts   );
//    geo->setIndices  (indices);
    geo->setColors   (colors );
    geo->setTypes    (types  );
    geo->setLengths  (lens   );
    geo->setMaterial (mat    );

    commitChanges();

    return geo;
}

GeometryTransitPtr makeGridBorderGeo(const Real32   width,
                                     const Real32   depth,
                                     const Color3f &color)
{
    const Color3f darkerColor =
        Color3f( color[0]-0.4, color[1]-0.4, color[2]-0.4 );

    GeometryTransitPtr           geo    = Geometry::create();
    GeoPnt3fPropertyUnrecPtr   pnts   = GeoPnt3fProperty::create();
    GeoUInt32PropertyUnrecPtr  lens   = GeoUInt32Property::create();
    GeoUInt8PropertyUnrecPtr   types  = GeoUInt8Property::create();
    GeoColor3fPropertyUnrecPtr colors = GeoColor3fProperty::create();
//    GeoIndicesUI32Ptr  indices   = GeoIndicesUI32::create();
    SimpleMaterialUnrecPtr  mat       = SimpleMaterial::create();
    LineChunkUnrecPtr       lineChunk = LineChunk::create();

    Real32 height   (0.0        );
    Real32 widthHalf(width / 2.0);
    Real32 depthHalf(depth / 2.0);

    Int32 pntCnt(0);

    // horizontal & vertical mid lines in different color
    pnts->addValue(Pnt3f(-widthHalf, height, 0));
    pnts->addValue(Pnt3f( widthHalf, height, 0));
    pntCnt++; pntCnt++;
    colors->addValue(darkerColor);
    colors->addValue(darkerColor);

    pnts->addValue(Pnt3f(0, height, -depthHalf));
    pnts->addValue(Pnt3f(0, height,  depthHalf));
    ++pntCnt;
    ++pntCnt;
    colors->addValue(darkerColor);
    colors->addValue(darkerColor);

    // the border
    pnts->addValue(Pnt3f(-widthHalf, 0, depthHalf));
    pnts->addValue(Pnt3f( widthHalf, 0, depthHalf));
    ++pntCnt;
    ++pntCnt;
    colors->addValue(darkerColor);
    colors->addValue(darkerColor);

    pnts->addValue(Pnt3f(widthHalf, 0,  depthHalf));
    pnts->addValue(Pnt3f(widthHalf, 0, -depthHalf));
    ++pntCnt;
    ++pntCnt;
    colors->addValue(darkerColor);
    colors->addValue(darkerColor);

    pnts->addValue(Pnt3f( widthHalf, 0, -depthHalf));
    pnts->addValue(Pnt3f(-widthHalf, 0, -depthHalf));
    ++pntCnt;
    ++pntCnt;
    colors->addValue(darkerColor);
    colors->addValue(darkerColor);

    pnts->addValue(Pnt3f(-widthHalf, 0, -depthHalf));
    pnts->addValue(Pnt3f(-widthHalf, 0,  depthHalf));
    ++pntCnt;
    ++pntCnt;
    colors->addValue(darkerColor);
    colors->addValue(darkerColor);

    lineChunk->setWidth (1   );
    lineChunk->setSmooth(true);

    types->addValue(GL_LINES);
    lens->addValue (pntCnt  );

    // set the color for the grid
    mat->setLit  (false    );
    mat->addChunk(lineChunk);

    geo->setPositions(pnts   );
//    geo->setIndices  (indices);
    geo->setColors   (colors );
    geo->setTypes    (types  );
    geo->setLengths  (lens   );
    geo->setMaterial (mat    );

    commitChanges();

    return geo;
}

/*! \brief create a grid
 *  \ingroup SimpleGeometryExt
 *
 * Creates a grid with the specified <i>width</i> and <i>height</i>.
 * The grid has the base color <i>color</i>.
 */
NodeTransitPtr makeGrid(const Real32   width,
                        const Real32   depth,
                        const Real32   hCellWidth,
                        const Color3f &color     )
{
    NodeTransitPtr grpNode    = Node::create();
    GroupUnrecPtr  grpCore    = Group::create();
    NodeUnrecPtr   gridNode   = Node::create();
    NodeUnrecPtr   borderNode = Node::create();

    gridNode->setCore  (makeGridGeo(width, depth, hCellWidth, color));
    borderNode->setCore(makeGridBorderGeo(width, depth, color)      );

    grpNode->setCore (grpCore   );
    grpNode->addChild(gridNode  );
    grpNode->addChild(borderNode);

    commitChanges();

    return grpNode;
}


NodeTransitPtr makeSelection(Node *geoN)
{
    NodeTransitPtr             transN = Node::create();
    NodeUnrecPtr               node   = Node::create();
    ComponentTransformUnrecPtr transC = ComponentTransform::create();

    node->setCore(makeSelectionGeo(geoN));

    transN->setCore (transC);
    transN->addChild(node  );

    commitChanges();

    return transN;
}

GeometryTransitPtr makeSelectionGeo(Node *geoN)
{
    Pnt3f min, max;
    geoN->getVolume().getBounds(min, max);

    GeometryTransitPtr         geo       = Geometry::create();
    GeoPnt3fPropertyUnrecPtr   newPnts   = GeoPnt3fProperty::create();
    GeoUInt32PropertyUnrecPtr  lens      = GeoUInt32Property::create();
    GeoUInt8PropertyUnrecPtr   types     = GeoUInt8Property::create();
    GeoColor3fPropertyUnrecPtr colors    = GeoColor3fProperty::create();

//    GeoIndicesUI32Ptr  indices   = GeoIndicesUI32::create();
    SimpleMaterialUnrecPtr  mat       = SimpleMaterial::create();

    LineChunkUnrecPtr       lineChunk = LineChunk::create();

    Geometry *selGeoC = dynamic_cast<Geometry *>(geoN->getCore());
    if( selGeoC != NULL )
    {
        FaceIterator fi;

        for(fi=selGeoC->beginFaces(); fi!=selGeoC->endFaces(); ++fi)
        {
            newPnts->addValue(fi.getPosition(0));
            newPnts->addValue(fi.getPosition(1));
            newPnts->addValue(fi.getPosition(2));

            colors->addValue(Color3f(1, 1, 1));
            colors->addValue(Color3f(1, 1, 1));
            colors->addValue(Color3f(1, 1, 1));

            types->addValue(GL_LINE_STRIP);
            lens->addValue (3            );
        }
    }

    lineChunk->setWidth (1    );
    lineChunk->setSmooth(false);

    // set the color for the grid
    mat->setLit  (false    );
    mat->addChunk(lineChunk);

    geo->setPositions(newPnts);
//    geo->setIndices  (indices);
//    geo->setColors   (colors );
    geo->setTypes    (types  );
    geo->setLengths  (lens   );
    geo->setMaterial (mat    );

    commitChanges();

    return geo;
}


PolygonChunkUnrecPtr _gayaPolygonChunk;

PolygonChunk *getPolygonChunk(const UInt16 faces,
                              const UInt16 mode )
{
    if( _gayaPolygonChunk == NULL )
    {
        _gayaPolygonChunk = PolygonChunk::create();

        _gayaPolygonChunk->setCullFace(faces);
        _gayaPolygonChunk->setFrontMode(mode);
        _gayaPolygonChunk->setSmooth(true);
        _gayaPolygonChunk->setOffsetLine(true);
        _gayaPolygonChunk->setOffsetFill(false);
        _gayaPolygonChunk->setOffsetFactor(-1);
//        _gayaPolygonChunk->setOffsetBias(1);

        commitChanges();
    }
    return _gayaPolygonChunk;
}

MaterialChunkRecPtr _gayaMaterialChunk;

MaterialChunk *getMaterialChunk(const Color4f &ambientColor,
                                const Color4f &diffuseColor,
                                const Color4f &specularColor,
                                const bool     lit          )
{
    if( _gayaMaterialChunk == NULL )
    {
        _gayaMaterialChunk = MaterialChunk::create();

        _gayaMaterialChunk->setDiffuse(diffuseColor);
        _gayaMaterialChunk->setAmbient(ambientColor);
        _gayaMaterialChunk->setSpecular(specularColor);
        _gayaMaterialChunk->setLit(lit);

        commitChanges();
    }
    return _gayaMaterialChunk;
}

ChunkMaterialRecPtr _gayaSelectionMaterial;

ChunkMaterial *getSelectionMaterial()
{
    if( _gayaSelectionMaterial == NULL )
    {
        _gayaSelectionMaterial = ChunkMaterial::create();

        _gayaSelectionMaterial->addChunk(getPolygonChunk());
        _gayaSelectionMaterial->addChunk(getMaterialChunk(Color4f(1,1,1,0),
                                                          Color4f(1,1,1,0)));

        commitChanges();
    }
    return _gayaSelectionMaterial;
}


OSG_END_NAMESPACE
