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
#include "OSGUpdateAction.h"

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
//         RenderAction::registerEnterDefault(
//             SkeletonJoint::getClassType(),
//             reinterpret_cast<Action::Callback>(&SkeletonJoint::renderEnter));
//         RenderAction::registerLeaveDefault(
//             SkeletonJoint::getClassType(),
//             reinterpret_cast<Action::Callback>(&SkeletonJoint::renderLeave));

        UpdateAction::registerEnterDefault(
            SkeletonJoint::getClassType(),
            reinterpret_cast<Action::Callback>(&SkeletonJoint::updateEnter));
        UpdateAction::registerLeaveDefault(
            SkeletonJoint::getClassType(),
            reinterpret_cast<Action::Callback>(&SkeletonJoint::updateLeave));
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
    : Inherited()
{
}

SkeletonJoint::SkeletonJoint(const SkeletonJoint &source)
    : Inherited(source)
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
    if(((InvBindMatrixFieldMask |
         MatrixFieldMask          ) & whichField) != 0x0000)
    {
        invalidateVolume();
    }

    Inherited::changed(whichField, origin, details);
}

Action::ResultE
SkeletonJoint::renderEnter(Action *action)
{
    Action::ResultE  res  = Action::Continue;
    RenderAction    *ract =
        boost::polymorphic_downcast<RenderAction *>(action);
    Skeleton        *skel = getSkeleton();

#ifdef OSG_DEBUG
    if(_sfJointId.getValue() == INVALID_JOINT_ID)
    {
        SWARNING << "SkeletonJoint::renderEnter: Joint has invalid jointId. "
                 << "Ignoring." << std::endl;
        return res;
    }
    
    if(skel == NULL)
    {
        SWARNING << "SkeletonJoint::renderEnter: Joint has no skeleton. "
                 << "Ignoring." << std::endl;
        return res;
    }
#endif

    Int16                                jointId    = _sfJointId.getValue();
    Skeleton::MFJointMatricesType       *jointMats  =
        skel->editMFJointMatrices();
    Skeleton::MFJointNormalMatricesType *jointNMats =
        skel->editMFJointNormalMatrices();

    ract->pushVisibility(                    );
    ract->pushMatrix    (_sfMatrix.getValue());

    Matrix jointMat(ract->topMatrix());

    if(skel->getUseInvBindMatrix() == true)
        jointMat.mult(_sfInvBindMatrix.getValue());

    (*jointMats)[jointId] = jointMat;

    if(skel->getCalcNormalMatrices() == true)
    {
        jointMat.invert   ();
        jointMat.transpose();

        (*jointNMats)[jointId] = jointMat;
    }

    return res;
}

Action::ResultE
SkeletonJoint::renderLeave(Action *action)
{
    Action::ResultE  res  = Action::Continue;
    RenderAction    *ract =
        boost::polymorphic_downcast<RenderAction *>(action);
    Skeleton        *skel = getSkeleton();

    // need to make symmetric checks to renderEnter, otherwise the
    // matrix stack gets corrupted
#ifdef OSG_DEBUG
    if(_sfJointId.getValue() == INVALID_JOINT_ID)
    {
        SWARNING << "SkeletonJoint::renderLeave: Joint has invalid jointId. "
                 << "Ignoring." << std::endl;
        return res;
    }
    
    if(skel == NULL)
    {
        SWARNING << "SkeletonJoint::renderLeave: Joint has no skeleton. "
                 << "Ignoring." << std::endl;
        return res;
    }
#endif

    ract->popMatrix    ();
    ract->popVisibility();

    return res;
}

Action::ResultE
SkeletonJoint::updateEnter(Action *action)
{
    UpdateAction    *ua      = dynamic_cast<UpdateAction *>(action);
    Action::ResultE  res     = Action::Continue;
    Skeleton        *skel    = _sfSkeleton.getValue();
    Int16            jointId = _sfJointId .getValue();

#ifdef OSG_DEBUG
    if(jointId == INVALID_JOINT_ID)
    {
        SWARNING << "SkeletonJoint::updateEnter: Joint has invalid jointId. "
                 << "Ignoring." << std::endl;
        return res;
    }
    
    if(skel == NULL)
    {
        SWARNING << "SkeletonJoint::updateEnter: Joint has no skeleton. "
                 << "Ignoring." << std::endl;
        return res;
    }
#endif // OSG_DEBUG

    ua->pushMatrix(_sfMatrix.getValue());

    Matrix jointMat(ua->getModelMatrix());

    if(skel->getUseInvBindMatrix() == true)
        jointMat.mult(_sfInvBindMatrix.getValue());

    (*skel->editMFJointMatrices())[jointId] = jointMat;

    if(skel->getCalcNormalMatrices() == true)
    {
        jointMat.invert   ();
        jointMat.transpose();

        (*skel->editMFJointNormalMatrices())[jointId] = jointMat;
    }

    return res;
}

Action::ResultE
SkeletonJoint::updateLeave(Action *action)
{
    UpdateAction    *ua      = dynamic_cast<UpdateAction *>(action);
    Action::ResultE  res     = Action::Continue;
    Skeleton        *skel    = _sfSkeleton.getValue();
    Int16            jointId = _sfJointId .getValue();

#ifdef OSG_DEBUG
    if(jointId == INVALID_JOINT_ID)
    {
        SWARNING << "SkeletonJoint::updateLeave: Joint has invalid jointId. "
                 << "Ignoring." << std::endl;
        return res;
    }
    
    if(skel == NULL)
    {
        SWARNING << "SkeletonJoint::updateLeave: Joint has no skeleton. "
                 << "Ignoring." << std::endl;
        return res;
    }
#endif // OSG_DEBUG

    ua->popMatrix();

    return res;
}

void
SkeletonJoint::accumulateMatrix(Matrix &result)
{
    result.mult(_sfMatrix.getValue());
}

void
SkeletonJoint::adjustVolume(Volume &volume)
{
    volume.transform(_sfMatrix.getValue()   );
    volume.extendBy (Pnt3f( Eps,  Eps,  Eps));
    volume.extendBy (Pnt3f(-Eps, -Eps, -Eps));

//     volume.extendBy (Pnt3f(-0.01f, -0.01f, -0.01f));
//     volume.extendBy (Pnt3f( 0.01f,  0.01f,  0.01f));
}

void SkeletonJoint::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump SkeletonJoint NI" << std::endl;
}

OSG_END_NAMESPACE
