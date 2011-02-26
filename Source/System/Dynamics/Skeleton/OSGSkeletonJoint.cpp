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

#include "OSGConfig.h"

#include "OSGSkeletonJoint.h"
#include "OSGRenderAction.h"

#include <boost/cast.hpp>

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGSkeletonJointBase.cpp file.
// To modify it, please change the .fcd file (OSGSkeletonJoint.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

const Int16 SkeletonJoint::INVALID_JOINT_ID;

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void SkeletonJoint::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
        RenderAction::registerEnterDefault(
            SkeletonJoint::getClassType(),
            reinterpret_cast<Action::Callback>(&SkeletonJoint::renderEnter));
        RenderAction::registerLeaveDefault(
            SkeletonJoint::getClassType(),
            reinterpret_cast<Action::Callback>(&SkeletonJoint::renderLeave));
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

SkeletonJoint::SkeletonJoint(void)
    : Inherited             ()
    , _identityInvBindMatrix(false)
{
}

SkeletonJoint::SkeletonJoint(const SkeletonJoint &source)
    : Inherited             (source)
    , _identityInvBindMatrix(false)
{
}

SkeletonJoint::~SkeletonJoint(void)
{
}

/*----------------------------- class specific ----------------------------*/

void SkeletonJoint::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    if((InvBindMatrixFieldMask & whichField) != 0)
    {
        if(getInvBindMatrix() == Matrix::identity())
        {
            _identityInvBindMatrix = true;
        }
        else
        {
            _identityInvBindMatrix = false;
        }
    }

    Inherited::changed(whichField, origin, details);
}

Action::ResultE
SkeletonJoint::renderEnter(Action *action)
{
    Action::ResultE  res  = Action::Continue;
    RenderAction    *ract =
        boost::polymorphic_downcast<RenderAction *>(action);

#ifdef OSG_DEBUG
    if(_sfJointId.getValue() == INVALID_JOINT_ID)
    {
        SWARNING << "SkeletonJoint::renderEnter: Joint has invalid jointId. "
                 << "Ignoring." << std::endl;
        return res;
    }
    
    if(getSkeleton() == NULL)
    {
        SWARNING << "SkeletonJoint::renderEnter: Joint has no skeleton. "
                 << "Ignoring." << std::endl;
        return res;
    }
#endif

    Int16                                jointId    = _sfJointId.getValue();
    Skeleton                            *skel       = getSkeleton();
    Skeleton::MFJointMatricesType       *jointMats  =
        skel->editMFJointMatrices();
    Skeleton::MFJointNormalMatricesType *jointNMats =
        skel->editMFJointNormalMatrices();

    if(_identityInvBindMatrix == false)
        ract->pushMatrix(_sfInvBindMatrix.getValue());

    ract->pushMatrix(_sfMatrix.getValue());

    (*jointMats)[jointId] = ract->topMatrix();

    if(skel->getCalcNormalMatrices() == true)
    {
        Matrix jointNMat = ract->topMatrix();
  
        jointNMat.invert   ();
        jointNMat.transpose();

        (*jointNMats)[jointId] = jointNMat;
    }

    return res;
}

Action::ResultE
SkeletonJoint::renderLeave(Action *action)
{
    Action::ResultE  res  = Action::Continue;
    RenderAction    *ract =
        boost::polymorphic_downcast<RenderAction *>(action);

    // need to make symmetric checks to renderEnter, otherwise the
    // matrix stack gets corrupted
#ifdef OSG_DEBUG
    if(_sfJointId.getValue() == INVALID_JOINT_ID)
    {
        SWARNING << "SkeletonJoint::renderEnter: Joint has invalid jointId. "
                 << "Ignoring." << std::endl;
        return res;
    }
    
    if(getSkeleton() == NULL)
    {
        SWARNING << "SkeletonJoint::renderEnter: Joint has no skeleton. "
                 << "Ignoring." << std::endl;
        return res;
    }
#endif

    Int16 jointId   = _sfJointId.getValue();

    if(_identityInvBindMatrix == false)
        ract->popMatrix();

    ract->popMatrix();

    return res;
}

void SkeletonJoint::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump SkeletonJoint NI" << std::endl;
}

OSG_END_NAMESPACE
