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
 **     class LightEngine!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILELIGHTENGINEINST

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OSGConfig.h>




#include "OSGLightEngineBase.h"
#include "OSGLightEngine.h"

#include "boost/bind.hpp"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::LightEngine
    
 */

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

/*! \var bool            LightEngineBase::_sfEnabled
    
*/


void LightEngineBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "enabled",
        "",
        EnabledFieldId, EnabledFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&LightEngineBase::editHandleEnabled),
        static_cast<FieldGetMethodSig >(&LightEngineBase::getHandleEnabled));

    oType.addInitialDesc(pDesc);
}


LightEngineBase::TypeObject LightEngineBase::_type(
    LightEngineBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    NULL,
    LightEngine::initMethod,
    LightEngine::exitMethod,
    (InitalInsertDescFunc) &LightEngineBase::classDescInserter,
    false,
    0,
    "<?xml version=\"1.0\" ?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"LightEngine\"\n"
    "\tparent=\"AttachmentContainer\"\n"
    "\tlibrary=\"System\"\n"
    "\tstructure=\"abstract\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "    isNodeCore=\"false\"\n"
    ">\n"
    "\t<Field\n"
    "\t\tname=\"enabled\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &LightEngineBase::getType(void)
{
    return _type;
}

const FieldContainerType &LightEngineBase::getType(void) const
{
    return _type;
}

UInt32 LightEngineBase::getContainerSize(void) const
{
    return sizeof(LightEngine);
}

/*------------------------- decorator get ------------------------------*/


SFBool *LightEngineBase::editSFEnabled(void)
{
    editSField(EnabledFieldMask);

    return &_sfEnabled;
}

const SFBool *LightEngineBase::getSFEnabled(void) const
{
    return &_sfEnabled;
}

#ifdef OSG_1_GET_COMPAT
SFBool              *LightEngineBase::getSFEnabled        (void)
{
    return this->editSFEnabled        ();
}
#endif





/*------------------------------ access -----------------------------------*/

UInt32 LightEngineBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (EnabledFieldMask & whichField))
    {
        returnValue += _sfEnabled.getBinSize();
    }

    return returnValue;
}

void LightEngineBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (EnabledFieldMask & whichField))
    {
        _sfEnabled.copyToBin(pMem);
    }
}

void LightEngineBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (EnabledFieldMask & whichField))
    {
        _sfEnabled.copyFromBin(pMem);
    }
}




/*------------------------- constructors ----------------------------------*/

LightEngineBase::LightEngineBase(void) :
    Inherited(),
    _sfEnabled                (bool(true))
{
}

LightEngineBase::LightEngineBase(const LightEngineBase &source) :
    Inherited(source),
    _sfEnabled                (source._sfEnabled                )
{
}


/*-------------------------- destructors ----------------------------------*/

LightEngineBase::~LightEngineBase(void)
{
}


GetFieldHandlePtr LightEngineBase::getHandleEnabled         (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfEnabled, 
             this->getType().getFieldDesc(EnabledFieldId)));

    return returnValue;
}

EditFieldHandlePtr LightEngineBase::editHandleEnabled        (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfEnabled, 
             this->getType().getFieldDesc(EnabledFieldId)));

    editSField(EnabledFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void LightEngineBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    this->execSync(static_cast<LightEngineBase *>(&oFrom),
                   whichField,
                   oOffsets,
                   syncMode,
                   uiSyncInfo);
}
#endif



void LightEngineBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE

#include "OSGSFieldAdaptor.ins"
#include "OSGMFieldAdaptor.ins"

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<LightEnginePtr>::_type("LightEnginePtr", "AttachmentContainerPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(LightEnginePtr)

OSG_FIELD_DLLEXPORT_DEF2(SFieldAdaptor, LightEnginePtr, SFFieldContainerPtr);
OSG_FIELD_DLLEXPORT_DEF2(MFieldAdaptor, LightEnginePtr, MFFieldContainerPtr);

OSG_END_NAMESPACE
