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

#include <stdlib.h>
#include <stdio.h>

#include "OSGConfig.h"

#include <OSGRenderAction.h>
#include <OSGIntersectAction.h>

#include "OSGShadowMapEngine.h"
#include "OSGPassMaskPool.h"
#include "OSGChunkMaterial.h"
#include "OSGMaterialChunk.h"

OSG_USING_NAMESPACE

/*! \class OSG::ShadowMapEngine
*/

BitVector ShadowMapEngine::bvLightPassMask   = 0;
BitVector ShadowMapEngine::bvAmbientPassMask = 0;
BitVector ShadowMapEngine::bvDiffusePassMask = 0;

ChunkMaterialPtr ShadowMapEngine::_pLightPassMat = NullFC;

/*-------------------------------------------------------------------------*/
/*                               Sync                                      */

void ShadowMapEngine::changed(ConstFieldMaskArg whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);
}

/*-------------------------------------------------------------------------*/
/*                               Dump                                      */

void ShadowMapEngine::dump(      UInt32    uiIndent, 
                           const BitVector bvFlags) const
{
   Inherited::dump(uiIndent, bvFlags);
}

/*-------------------------------------------------------------------------*/
/*                            Constructors                                 */

ShadowMapEngine::ShadowMapEngine(void) :
    Inherited()
{
}

ShadowMapEngine::ShadowMapEngine(const ShadowMapEngine &source) :
    Inherited(source)
{
}

/*-------------------------------------------------------------------------*/
/*                             Destructor                                  */

ShadowMapEngine::~ShadowMapEngine(void)
{
}

/*-------------------------------------------------------------------------*/
/*                                Init                                     */

void ShadowMapEngine::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);


    if(ePhase == TypeObject::SystemPost)
    {
        bvLightPassMask   = 
            PassMaskPool::the()->get("shadowMapEngine::LightPass");
        bvAmbientPassMask = 
            PassMaskPool::the()->get("shadowMapEngine::AmbientPass");
        bvDiffusePassMask = 
            PassMaskPool::the()->get("shadowMapEngine::DiffusePass");
    }
    else if(ePhase == TypeObject::FactoryPost)
    {
        if(_pLightPassMat == NullFC)
        {
            fprintf(stderr, "######## F POST\n");

            _pLightPassMat = ChunkMaterial::create();

            MaterialChunkPtr pMatChunk = MaterialChunk::create();

            pMatChunk->setLit          (false  );
            pMatChunk->setColorMaterial(GL_NONE);

            _pLightPassMat->addChunk(pMatChunk);
        }
    }
}


/*-------------------------------------------------------------------------*/
/*                              cvs id's                                   */

#ifdef __sgi
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 177 )
#endif

namespace
{
    static Char8 cvsid_cpp[] = "@(#)$Id: OSGShadowMapEngine.cpp,v 1.1.2.1 2006/04/21 02:27:50 vossg Exp $";
    static Char8 cvsid_hpp[] = OSGSHADOWMAPENGINE_HEADER_CVSID;
    static Char8 cvsid_inl[] = OSGSHADOWMAPENGINE_INLINE_CVSID;
}





