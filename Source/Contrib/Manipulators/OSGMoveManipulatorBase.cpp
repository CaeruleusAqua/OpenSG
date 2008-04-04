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
 **     class MoveManipulator!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEMOVEMANIPULATORINST

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OSGConfig.h>




#include "OSGMoveManipulatorBase.h"
#include "OSGMoveManipulator.h"

#include "boost/bind.hpp"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::MoveManipulator
    The MoveHandle is used for moving objects. It consist of three axis which can be picked and translated and one center box to translate freely in 3D.
 */


MoveManipulatorBase::TypeObject MoveManipulatorBase::_type(
    MoveManipulatorBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    (PrototypeCreateF) &MoveManipulatorBase::createEmpty,
    MoveManipulator::initMethod,
    MoveManipulator::exitMethod,
    NULL,
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"MoveManipulator\"\n"
    "\tparent=\"Manipulator\"\n"
    "\tlibrary=\"ContribGUI\"\n"
    "\tpointerfieldtypes=\"none\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "\tuseLocalIncludes=\"true\"\n"
    ">\n"
    "The MoveHandle is used for moving objects. It consist of three axis which can be picked and translated and one center box to translate freely in 3D.\n"
    "</FieldContainer>\n",
    "The MoveHandle is used for moving objects. It consist of three axis which can be picked and translated and one center box to translate freely in 3D.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &MoveManipulatorBase::getType(void)
{
    return _type;
}

const FieldContainerType &MoveManipulatorBase::getType(void) const
{
    return _type;
}

UInt32 MoveManipulatorBase::getContainerSize(void) const
{
    return sizeof(MoveManipulator);
}

/*------------------------- decorator get ------------------------------*/






/*------------------------------ access -----------------------------------*/

UInt32 MoveManipulatorBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);


    return returnValue;
}

void MoveManipulatorBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

}

void MoveManipulatorBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

}

//! create a new instance of the class
MoveManipulatorPtr MoveManipulatorBase::create(void)
{
    MoveManipulatorPtr fc;

    if(getClassType().getPrototype() != NullFC)
    {
        fc = dynamic_cast<MoveManipulator::ObjPtr>(
            getClassType().getPrototype()-> shallowCopy());
    }

    return fc;
}

//! create an empty new instance of the class, do not copy the prototype
MoveManipulatorPtr MoveManipulatorBase::createEmpty(void)
{
    MoveManipulatorPtr returnValue;

    newPtr<MoveManipulator>(returnValue);

    return returnValue;
}

FieldContainerPtr MoveManipulatorBase::shallowCopy(void) const
{
    MoveManipulatorPtr returnValue;

    newPtr(returnValue, dynamic_cast<const MoveManipulator *>(this));

    return returnValue;
}



/*------------------------- constructors ----------------------------------*/

MoveManipulatorBase::MoveManipulatorBase(void) :
    Inherited()
{
}

MoveManipulatorBase::MoveManipulatorBase(const MoveManipulatorBase &source) :
    Inherited(source)
{
}


/*-------------------------- destructors ----------------------------------*/

MoveManipulatorBase::~MoveManipulatorBase(void)
{
}



#ifdef OSG_MT_CPTR_ASPECT
void MoveManipulatorBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    this->execSync(static_cast<MoveManipulatorBase *>(&oFrom),
                   whichField,
                   oOffsets,
                   syncMode,
                   uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainerPtr MoveManipulatorBase::createAspectCopy(void) const
{
    MoveManipulatorPtr returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const MoveManipulator *>(this));

    return returnValue;
}
#endif

void MoveManipulatorBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<MoveManipulatorPtr>::_type("MoveManipulatorPtr", "ManipulatorPtr");
#endif


OSG_END_NAMESPACE
