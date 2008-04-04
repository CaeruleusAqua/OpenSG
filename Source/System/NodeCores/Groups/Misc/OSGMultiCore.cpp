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

#include "OSGMultiCore.h"
#include "OSGRenderAction.h"

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGMultiCoreBase.cpp file.
// To modify it, please change the .fcd file (OSGMultiCore.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void MultiCore::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
        RenderAction::registerEnterDefault(
            MultiCore::getClassType(), 
            reinterpret_cast<Action::Callback>(&MultiCore::renderEnter));
        
        RenderAction::registerLeaveDefault( 
            MultiCore::getClassType(), 
            reinterpret_cast<Action::Callback>(&MultiCore::renderLeave));
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

MultiCore::MultiCore(void) :
    Inherited()
{
}

MultiCore::MultiCore(const MultiCore &source) :
    Inherited(source)
{
}

MultiCore::~MultiCore(void)
{
}

/*----------------------------- class specific ----------------------------*/

void MultiCore::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    if(whichField & CoresFieldMask)
    {
        invalidateVolume();
    }

    Inherited::changed(whichField, origin, details);
}

/*-------------------------------------------------------------------------*/
/*                               Helper                                    */

void MultiCore::accumulateMatrix(Matrix &result)
{
    MFUnrecNodeCorePtr::iterator coreIt  = _mfCores.begin();
    MFUnrecNodeCorePtr::iterator coreEnd = _mfCores.end  ();

    while(coreIt != coreEnd)
    {
        (*coreIt)->accumulateMatrix(result);

        ++coreIt;
    }
}

void MultiCore::adjustVolume(Volume &volume)
{
    MFUnrecNodeCorePtr::iterator coreIt  = _mfCores.begin();
    MFUnrecNodeCorePtr::iterator coreEnd = _mfCores.end  ();

    while(coreIt != coreEnd)
    {
        (*coreIt)->adjustVolume(volume);

        ++coreIt;
    }
}

void MultiCore::dump(      UInt32    ,
                         const BitVector ) const
{
    SLOG << "Dump MultiCore NI" << std::endl;
}

ActionBase::ResultE MultiCore::renderEnter(Action *action)
{
    RenderAction *a = dynamic_cast<RenderAction *>(action);

    MFUnrecNodeCorePtr::const_iterator coreIt  = this->getCores().begin();
    MFUnrecNodeCorePtr::const_iterator coreEnd = this->getCores().end  ();

    Action::ResultE returnValue = Action::Continue;

    while(coreIt != coreEnd)
    {
        returnValue = action->callEnter(*coreIt);

        if(returnValue != Action::Continue)
            break;

        ++coreIt;
    }    

    if(returnValue == Action::Skip)
        returnValue = Action::Continue;

    return returnValue;
}

ActionBase::ResultE MultiCore::renderLeave(Action *action)
{
    RenderAction *a = dynamic_cast<RenderAction *>(action);

    MFUnrecNodeCorePtr::const_iterator coreIt  = this->getCores().begin();
    MFUnrecNodeCorePtr::const_iterator coreEnd = this->getCores().end  ();

    Action::ResultE returnValue = Action::Continue;

    while(coreIt != coreEnd)
    {
        returnValue = action->callLeave(*coreIt);

        if(returnValue != Action::Continue)
            break;

        ++coreIt;
    }    

    if(returnValue == Action::Skip)
        returnValue = Action::Continue;

    return returnValue;
}

OSG_END_NAMESPACE
