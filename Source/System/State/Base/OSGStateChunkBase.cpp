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

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 **     Do not change this file, changes should be done in the derived      **
 **     class StateChunk!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILESTATECHUNKINST

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OSGConfig.h>




#include "OSGStateChunkBase.h"
#include "OSGStateChunk.h"

#include "boost/bind.hpp"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::StateChunk
    \ingroup GrpSystemState

    See \ref PageSystemState for the conceptual background.
 */

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

/*! \var bool            StateChunkBase::_sfIgnore
    Enables / disables a chunk
*/


void StateChunkBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "ignore",
        "Enables / disables a chunk\n",
        IgnoreFieldId, IgnoreFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&StateChunkBase::editHandleIgnore),
        static_cast<FieldGetMethodSig >(&StateChunkBase::getHandleIgnore));

    oType.addInitialDesc(pDesc);
}


StateChunkBase::TypeObject StateChunkBase::_type(
    StateChunkBase::getClassname(),
    Inherited::getClassname(),
    "StateChunk",
    0,
    NULL,
    StateChunk::initMethod,
    StateChunk::exitMethod,
    (InitalInsertDescFunc) &StateChunkBase::classDescInserter,
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"StateChunk\"\n"
    "\tparent=\"FieldContainerAttachment\"\n"
    "\tlibrary=\"System\"\n"
    "\tstructure=\"abstract\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "\tuseLocalIncludes=\"false\"\n"
    ">\n"
    "\\ingroup GrpSystemState\n"
    "\n"
    "See \\ref PageSystemState for the conceptual background.\n"
    "\t<Field\n"
    "\t\tname=\"ignore\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"false\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\tEnables / disables a chunk\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "\\ingroup GrpSystemState\n"
    "\n"
    "See \\ref PageSystemState for the conceptual background.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &StateChunkBase::getType(void)
{
    return _type;
}

const FieldContainerType &StateChunkBase::getType(void) const
{
    return _type;
}

UInt32 StateChunkBase::getContainerSize(void) const
{
    return sizeof(StateChunk);
}

/*------------------------- decorator get ------------------------------*/


SFBool *StateChunkBase::editSFIgnore(void)
{
    editSField(IgnoreFieldMask);

    return &_sfIgnore;
}

const SFBool *StateChunkBase::getSFIgnore(void) const
{
    return &_sfIgnore;
}

#ifdef OSG_1_GET_COMPAT
SFBool              *StateChunkBase::getSFIgnore         (void)
{
    return this->editSFIgnore         ();
}
#endif





/*------------------------------ access -----------------------------------*/

UInt32 StateChunkBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (IgnoreFieldMask & whichField))
    {
        returnValue += _sfIgnore.getBinSize();
    }

    return returnValue;
}

void StateChunkBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (IgnoreFieldMask & whichField))
    {
        _sfIgnore.copyToBin(pMem);
    }
}

void StateChunkBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (IgnoreFieldMask & whichField))
    {
        _sfIgnore.copyFromBin(pMem);
    }
}




/*------------------------- constructors ----------------------------------*/

StateChunkBase::StateChunkBase(void) :
    Inherited(),
    _sfIgnore                 (bool(false))
{
}

StateChunkBase::StateChunkBase(const StateChunkBase &source) :
    Inherited(source),
    _sfIgnore                 (source._sfIgnore                 )
{
}


/*-------------------------- destructors ----------------------------------*/

StateChunkBase::~StateChunkBase(void)
{
}


GetFieldHandlePtr StateChunkBase::getHandleIgnore          (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfIgnore, 
             this->getType().getFieldDesc(IgnoreFieldId)));

    return returnValue;
}

EditFieldHandlePtr StateChunkBase::editHandleIgnore         (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfIgnore, 
             this->getType().getFieldDesc(IgnoreFieldId)));

    editSField(IgnoreFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void StateChunkBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    this->execSync(static_cast<StateChunkBase *>(&oFrom),
                   whichField,
                   oOffsets,
                   syncMode,
                   uiSyncInfo);
}
#endif



void StateChunkBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE

#include "OSGSFieldAdaptor.ins"
#include "OSGMFieldAdaptor.ins"

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<StateChunkPtr>::_type("StateChunkPtr", "FieldContainerAttachmentPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(StateChunkPtr)

OSG_FIELD_DLLEXPORT_DEF2(SFieldAdaptor, StateChunkPtr, SFFieldContainerPtr);
OSG_FIELD_DLLEXPORT_DEF2(MFieldAdaptor, StateChunkPtr, MFFieldContainerPtr);

OSG_END_NAMESPACE
