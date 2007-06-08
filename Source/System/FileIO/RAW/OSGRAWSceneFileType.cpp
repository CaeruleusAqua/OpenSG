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

//-------------------------------
//  Includes
//-------------------------------

#include <stdlib.h>
#include <stdio.h>

#include "OSGConfig.h"

#include <iostream>
#include <fstream>

#include <OSGLog.h>

#include <OSGNode.h>
#include <OSGGeometry.h>
#include <OSGSimpleMaterial.h>
#include "OSGTypedGeoIntegralProperty.h"

#include "OSGRAWSceneFileType.h"

OSG_USING_NAMESPACE

#if defined(OSG_WIN32_ICL) && !defined(OSG_CHECK_FIELDSETARG)
#pragma warning (disable : 383)
#endif


/*! \class osg::RAWSceneFileType
    \ingroup GrpSystemFileIO

 */

/*****************************
 *   Types
 *****************************/
// Static Class Varible implementations:

const Char8            *RAWSceneFileType::_suffixA[] = {"raw"};


RAWSceneFileType  RAWSceneFileType::_the(_suffixA,
                                         sizeof(_suffixA),
                                         false,
                                         10,
                                         SceneFileType::OSG_READ_SUPPORTED);

/*****************************
 *    Classvariables
 *****************************/


/********************************
 *    Class methodes
 *******************************/


/*******************************
*public
*******************************/

//----------------------------
// Function name: read
//----------------------------
//
//Parameters:
//p: Scene &image, const char *fileName
//GlobalVars:
//g:
//Returns:
//r:bool
// Caution
//c:
//Assumations:
//a:
//Describtions:
//d: read the image from the given file
//SeeAlso:
//s:
//
//------------------------------

#ifdef __sgi
#pragma set woff 1209
#endif

NodePtr RAWSceneFileType::read(std::istream &is, const Char8 *) const
{
    NodePtr                 root;
    GeometryPtr             geo;
    GeoPnt3fPropertyPtr     points;
    GeoVec3fPropertyPtr     normals;
    GeoIntegralPropertyPtr  index;
    GeoIntegralPropertyPtr  lens;
    GeoIntegralPropertyPtr  type;

    Vec3f vec[3];

    UInt32 i = 0, n, triCount = 0;

    Real32 x,y,z;

    if(is)
    {
        root = Node    ::create();
        geo  = Geometry::create();

        root->setCore( geo );

        points = GeoPnt3fProperty::create();

        geo->setPositions(points);

        normals = GeoVec3fProperty::create();

        geo->setNormals(normals);

        triCount = i = 0;


        while(1) 
        {
            is >> x >> y >> z;

            if(is.eof())
            {
                break;
            }
            else 
            {
                points->editFieldPtr()->push_back(Pnt3f(x, y, z));

                vec[i].setValues(x,y,z);

                if(i == 2) 
                {
                    vec[0] -= vec[1];
                    vec[1] -= vec[2];
                    vec[0].crossThis(vec[1]);
                    vec[0].normalize();

                    normals->editFieldPtr()->push_back(vec[0]);
                    normals->editFieldPtr()->push_back(vec[0]);
                    normals->editFieldPtr()->push_back(vec[0]);

                    i = 0;
                    triCount++;
                }
                else
                {
                    i++;
                }
            }
        }

        if(triCount != 0)
        {
            index = GeoUInt32Property::create();

            geo->setIndex(index, Geometry::PositionsIndex);
            geo->setIndex(index, Geometry::NormalsIndex  );

            n = triCount * 3;

            for(i = 0; i < n; i++)
                index->push_back(i);



            lens = GeoUInt32Property::create();

            geo->setLengths(lens);

            lens->push_back(n);

            type = GeoUInt8Property::create();

            geo->setTypes(type);

            type->push_back(GL_TRIANGLES);
        }

        SimpleMaterialPtr mat = SimpleMaterial::create();

        mat->setDiffuse  (Color3f(  .8,  .8,  .8));
        mat->setSpecular (Color3f( 1,   1,   1  ));
        mat->setShininess(20                     );

        geo->setMaterial(mat);
    }

    if(triCount)
    {
        SNOTICE << triCount << " triangle read " << std::endl;
    }

    return root;
}

#ifdef __sgi
#pragma reset woff 1209
#endif

/******************************
*protected
******************************/


/******************************
*private
******************************/


/***************************
*instance methodes
***************************/


/***************************
*public
***************************/


/**constructors & destructors**/


RAWSceneFileType::RAWSceneFileType(const Char8  *suffixArray[],
                                         UInt16  suffixByteCount,
                                         bool    override,
                                         UInt32  overridePriority,
                                         UInt32  flags) :
    SceneFileType(suffixArray,
                  suffixByteCount,
                  override,
                  overridePriority,
                  flags)
{
}

RAWSceneFileType &RAWSceneFileType::the(void)
{
    return _the;
}

const Char8 *RAWSceneFileType::getName(void) const
{
    return "RAW Geometry";
}


RAWSceneFileType::~RAWSceneFileType (void )
{
    return;
}


