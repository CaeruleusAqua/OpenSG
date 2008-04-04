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
 **     class GLUTWindow!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEGLUTWINDOWINST

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OSGConfig.h>




#include "OSGGLUTWindowBase.h"
#include "OSGGLUTWindow.h"

#include "boost/bind.hpp"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::GLUTWindow
    The class for GLUT-based windows. See \ref PageWindowGlut for a description.
 */

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

/*! \var Int32           GLUTWindowBase::_sfGlutId
    
*/


void GLUTWindowBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFInt32::Description(
        SFInt32::getClassType(),
        "glutId",
        "",
        GlutIdFieldId, GlutIdFieldMask,
        true,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&GLUTWindowBase::editHandleGlutId),
        static_cast<FieldGetMethodSig >(&GLUTWindowBase::getHandleGlutId));

    oType.addInitialDesc(pDesc);
}


GLUTWindowBase::TypeObject GLUTWindowBase::_type(
    GLUTWindowBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    (PrototypeCreateF) &GLUTWindowBase::createEmpty,
    GLUTWindow::initMethod,
    GLUTWindow::exitMethod,
    (InitalInsertDescFunc) &GLUTWindowBase::classDescInserter,
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"GLUTWindow\"\n"
    "\tparent=\"Window\"\n"
    "\tlibrary=\"WindowGLUT\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    ">\n"
    "The class for GLUT-based windows. See \\ref PageWindowGlut for a description.\n"
    "\t<Field\n"
    "\t\tname=\"glutId\"\n"
    "\t\ttype=\"Int32\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\tdefaultValue=\"0\"\n"
    "\t\theader=\"\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "The class for GLUT-based windows. See \\ref PageWindowGlut for a description.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &GLUTWindowBase::getType(void)
{
    return _type;
}

const FieldContainerType &GLUTWindowBase::getType(void) const
{
    return _type;
}

UInt32 GLUTWindowBase::getContainerSize(void) const
{
    return sizeof(GLUTWindow);
}

/*------------------------- decorator get ------------------------------*/


SFInt32 *GLUTWindowBase::editSFGlutId(void)
{
    editSField(GlutIdFieldMask);

    return &_sfGlutId;
}

const SFInt32 *GLUTWindowBase::getSFGlutId(void) const
{
    return &_sfGlutId;
}

#ifdef OSG_1_GET_COMPAT
SFInt32             *GLUTWindowBase::getSFGlutId         (void)
{
    return this->editSFGlutId         ();
}
#endif





/*------------------------------ access -----------------------------------*/

UInt32 GLUTWindowBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (GlutIdFieldMask & whichField))
    {
        returnValue += _sfGlutId.getBinSize();
    }

    return returnValue;
}

void GLUTWindowBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (GlutIdFieldMask & whichField))
    {
        _sfGlutId.copyToBin(pMem);
    }
}

void GLUTWindowBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (GlutIdFieldMask & whichField))
    {
        _sfGlutId.copyFromBin(pMem);
    }
}

//! create a new instance of the class
GLUTWindowPtr GLUTWindowBase::create(void)
{
    GLUTWindowPtr fc;

    if(getClassType().getPrototype() != NullFC)
    {
        fc = dynamic_cast<GLUTWindow::ObjPtr>(
            getClassType().getPrototype()-> shallowCopy());
    }

    return fc;
}

//! create an empty new instance of the class, do not copy the prototype
GLUTWindowPtr GLUTWindowBase::createEmpty(void)
{
    GLUTWindowPtr returnValue;

    newPtr<GLUTWindow>(returnValue);

    return returnValue;
}

FieldContainerPtr GLUTWindowBase::shallowCopy(void) const
{
    GLUTWindowPtr returnValue;

    newPtr(returnValue, dynamic_cast<const GLUTWindow *>(this));

    return returnValue;
}



/*------------------------- constructors ----------------------------------*/

GLUTWindowBase::GLUTWindowBase(void) :
    Inherited(),
    _sfGlutId                 (Int32(0))
{
}

GLUTWindowBase::GLUTWindowBase(const GLUTWindowBase &source) :
    Inherited(source),
    _sfGlutId                 (source._sfGlutId                 )
{
}


/*-------------------------- destructors ----------------------------------*/

GLUTWindowBase::~GLUTWindowBase(void)
{
}


GetFieldHandlePtr GLUTWindowBase::getHandleGlutId          (void) const
{
    SFInt32::GetHandlePtr returnValue(
        new  SFInt32::GetHandle(
             &_sfGlutId, 
             this->getType().getFieldDesc(GlutIdFieldId)));

    return returnValue;
}

EditFieldHandlePtr GLUTWindowBase::editHandleGlutId         (void)
{
    SFInt32::EditHandlePtr returnValue(
        new  SFInt32::EditHandle(
             &_sfGlutId, 
             this->getType().getFieldDesc(GlutIdFieldId)));

    editSField(GlutIdFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void GLUTWindowBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    this->execSync(static_cast<GLUTWindowBase *>(&oFrom),
                   whichField,
                   oOffsets,
                   syncMode,
                   uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainerPtr GLUTWindowBase::createAspectCopy(void) const
{
    GLUTWindowPtr returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const GLUTWindow *>(this));

    return returnValue;
}
#endif

void GLUTWindowBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE

#include "OSGSFieldAdaptor.ins"
#include "OSGMFieldAdaptor.ins"

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<GLUTWindowPtr>::_type("GLUTWindowPtr", "WindowPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(GLUTWindowPtr)

OSG_FIELD_DLLEXPORT_DEF2(SFieldAdaptor, GLUTWindowPtr, SFFieldContainerPtr);
OSG_FIELD_DLLEXPORT_DEF2(MFieldAdaptor, GLUTWindowPtr, MFFieldContainerPtr);

OSG_END_NAMESPACE
