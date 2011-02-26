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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include <OSGConfig.h>

#include "OSGSkeletonSkinningAlgorithm.h"
#include "OSGPrimeMaterial.h"

#include <boost/cast.hpp>

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGSkeletonSkinningAlgorithmBase.cpp file.
// To modify it, please change the .fcd file (OSGSkeletonSkinningAlgorithm.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void SkeletonSkinningAlgorithm::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

SkeletonSkinningAlgorithm::SkeletonSkinningAlgorithm(void) :
    Inherited()
{
}

SkeletonSkinningAlgorithm::SkeletonSkinningAlgorithm(const SkeletonSkinningAlgorithm &source) :
    Inherited(source)
{
}

SkeletonSkinningAlgorithm::~SkeletonSkinningAlgorithm(void)
{
}

/*----------------------------- class specific ----------------------------*/

void
SkeletonSkinningAlgorithm::adjustVolume(Volume &volume)
{
    SkinnedGeometry *skinGeo = getParent();
    Skeleton        *skel    = skinGeo->getSkeleton();

    skel->adjustVolume(volume);
}

ActionBase::ResultE
SkeletonSkinningAlgorithm::renderEnter(Action *action)
{
    Action::ResultE  res  = Action::Continue;
    RenderAction    *ract =
        boost::polymorphic_downcast<RenderAction *>(action);

    const SkinnedGeometry *skinGeo = getParent();
    const Skeleton        *skel    = skinGeo->getSkeleton();

    const Skeleton::MFJointsType        *joints       = skel->getMFJoints();
    const Skeleton::MFParentJointsType  *parentJoints =
        skel->getMFParentJoints();
    const Skeleton::MFJointMatricesType *jointMats    =
        skel->getMFJointMatrices();

    Real32 axisLen   = 1.f;
    UInt32 numJoints = joints->size();
    
    _mfDrawPositions.resize(4 * numJoints);
    _mfDrawIndex    .clear (             );

    for(UInt32 i = 0; i < numJoints; ++i)
    {
        (*jointMats)[i].mult(Pnt3f(0.f, 0.f, 0.f), _mfDrawPositions[4 * i + 0]);

        if((*parentJoints)[i] != NULL)
        {
            _mfDrawIndex.push_back(4 * i                                + 0);
            _mfDrawIndex.push_back(4 * (*parentJoints)[i]->getJointId() + 0);

            Vec3f vec = _mfDrawPositions[4 * i                                + 0] -
                        _mfDrawPositions[4 * (*parentJoints)[i]->getJointId() + 0];

            axisLen = 0.2f * vec.length();
        }
        else
        {
            axisLen = 1.f;
        }

        (*jointMats)[i].mult(
            Pnt3f(axisLen, 0.f,     0.f    ), _mfDrawPositions[4 * i + 1]);
        (*jointMats)[i].mult(
            Pnt3f(0.f,     axisLen, 0.f    ), _mfDrawPositions[4 * i + 2]);
        (*jointMats)[i].mult(
            Pnt3f(0.f,     0.f,     axisLen), _mfDrawPositions[4 * i + 3]);

//         _mfDrawIndex.push_back(4 * i + 0);
//         _mfDrawIndex.push_back(4 * i + 1);
//         _mfDrawIndex.push_back(4 * i + 0);
//         _mfDrawIndex.push_back(4 * i + 2);
//         _mfDrawIndex.push_back(4 * i + 0);
//         _mfDrawIndex.push_back(4 * i + 3);
    }

    Material::DrawFunctor  drawFunc =
        boost::bind(&SkeletonSkinningAlgorithm::drawFunc, this, _1);
    PrimeMaterial         *skelMat  = getDefaultUnlitMaterial();
    State                 *state    = skelMat->getState      ();

    ract->dropFunctor(drawFunc, state, skelMat->getSortKey());

    return res;
}

ActionBase::ResultE
SkeletonSkinningAlgorithm::renderLeave(Action *action)
{
    return Action::Continue;
}

ActionBase::ResultE
SkeletonSkinningAlgorithm::drawFunc(DrawEnv *drawEnv)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    {
        glVertexPointer(3, GL_FLOAT, 0, &(_mfDrawPositions.front()));
        glDrawElements (GL_LINES, _mfDrawIndex.size(), GL_UNSIGNED_INT,
                        &(_mfDrawIndex.front()));
    }
    glDisableClientState(GL_VERTEX_ARRAY);

    return Action::Continue;
}

void SkeletonSkinningAlgorithm::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void SkeletonSkinningAlgorithm::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump SkeletonSkinningAlgorithm NI" << std::endl;
}

OSG_END_NAMESPACE
