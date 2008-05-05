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

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include "OSGShadowMapEngine.h"
#include "OSGPassMaskPool.h"
#include "OSGChunkMaterial.h"
#include "OSGMaterialChunk.h"

OSG_USING_NAMESPACE

// Documentation for this class is emited in the
// OSGShadowMapEngineBase.cpp file.
// To modify it, please change the .fcd file (OSGShadowMapEngine.fcd) and
// regenerate the base file.

BitVector ShadowMapEngine::bvLightPassMask   = 0;
BitVector ShadowMapEngine::bvAmbientPassMask = 0;
BitVector ShadowMapEngine::bvDiffusePassMask = 0;

ChunkMaterialUnrecPtr ShadowMapEngine::_pLightPassMat = NULL;

/*-------------------------------------------------------------------------*/
/*                               Sync                                      */

void ShadowMapEngine::changed(ConstFieldMaskArg whichField, 
                              UInt32            origin,
                              BitVector         details)
{
    Inherited::changed(whichField, origin, details);
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
     Inherited  (  )

{
}

ShadowMapEngine::ShadowMapEngine(const ShadowMapEngine &source) :
     Inherited  (source)
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
        if(_pLightPassMat == NULL)
        {
            _pLightPassMat = ChunkMaterial::createLocal();

            MaterialChunkUnrecPtr pMatChunk = MaterialChunk::createLocal();

            pMatChunk->setLit          (false  );
            pMatChunk->setColorMaterial(GL_NONE);

            _pLightPassMat->addChunk(pMatChunk);

            _pLightPassMat->changed(FieldBits::AllFields,
                                    ChangedOrigin::Commit,
                                    0);

//            OSG::addRefX(_pLightPassMat);
        }
    }
}

void ShadowMapEngine::exitMethod(InitPhase ePhase)
{
    Inherited::exitMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
//        OSG::subRefX(_pLightPassMat);       
        _pLightPassMat = NULL;
    }
}
