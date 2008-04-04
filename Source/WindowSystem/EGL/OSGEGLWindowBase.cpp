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
 **     class EGLWindow!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILEEGLWINDOWINST

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OSGConfig.h>




#include "OSGEGLWindowBase.h"
#include "OSGEGLWindow.h"

#include "boost/bind.hpp"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::EGLWindow
    The class for EGL windows.
 */

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

/*! \var EGLDisplay      EGLWindowBase::_sfDisplay
    
*/

/*! \var EGLSurface      EGLWindowBase::_sfWindow
    
*/

/*! \var EGLContext      EGLWindowBase::_sfContext
    
*/


void EGLWindowBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFEGLDisplay::Description(
        SFEGLDisplay::getClassType(),
        "display",
        "",
        DisplayFieldId, DisplayFieldMask,
        true,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&EGLWindowBase::editHandleDisplay),
        static_cast<FieldGetMethodSig >(&EGLWindowBase::getHandleDisplay));

    oType.addInitialDesc(pDesc);

    pDesc = new SFEGLSurface::Description(
        SFEGLSurface::getClassType(),
        "window",
        "",
        WindowFieldId, WindowFieldMask,
        true,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&EGLWindowBase::editHandleWindow),
        static_cast<FieldGetMethodSig >(&EGLWindowBase::getHandleWindow));

    oType.addInitialDesc(pDesc);

    pDesc = new SFEGLContext::Description(
        SFEGLContext::getClassType(),
        "context",
        "",
        ContextFieldId, ContextFieldMask,
        true,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&EGLWindowBase::editHandleContext),
        static_cast<FieldGetMethodSig >(&EGLWindowBase::getHandleContext));

    oType.addInitialDesc(pDesc);
}


EGLWindowBase::TypeObject EGLWindowBase::_type(
    EGLWindowBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    (PrototypeCreateF) &EGLWindowBase::createEmpty,
    EGLWindow::initMethod,
    EGLWindow::exitMethod,
    (InitalInsertDescFunc) &EGLWindowBase::classDescInserter,
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"EGLWindow\"\n"
    "\tparent=\"Window\"\n"
    "\tlibrary=\"WindowEGL\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    ">\n"
    "The class for EGL windows.\n"
    "\t<Field\n"
    "\t\tname=\"display\"\n"
    "\t\ttype=\"EGLDisplay\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\tdefaultValue=\"0\"\n"
    "\t\theader=\"OSGEGLWindowDataFields.h\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"window\"\n"
    "\t\ttype=\"EGLSurface\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\tdefaultValue=\"0\"\n"
    "\t\theader=\"OSGEGLWindowDataFields.h\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"context\"\n"
    "\t\ttype=\"EGLContext\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\tdefaultValue=\"0\"\n"
    "\t\theader=\"OSGEGLWindowDataFields.h\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "The class for EGL windows.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &EGLWindowBase::getType(void)
{
    return _type;
}

const FieldContainerType &EGLWindowBase::getType(void) const
{
    return _type;
}

UInt32 EGLWindowBase::getContainerSize(void) const
{
    return sizeof(EGLWindow);
}

/*------------------------- decorator get ------------------------------*/


SFEGLDisplay *EGLWindowBase::editSFDisplay(void)
{
    editSField(DisplayFieldMask);

    return &_sfDisplay;
}

const SFEGLDisplay *EGLWindowBase::getSFDisplay(void) const
{
    return &_sfDisplay;
}

#ifdef OSG_1_GET_COMPAT
SFEGLDisplay        *EGLWindowBase::getSFDisplay        (void)
{
    return this->editSFDisplay        ();
}
#endif

SFEGLSurface *EGLWindowBase::editSFWindow(void)
{
    editSField(WindowFieldMask);

    return &_sfWindow;
}

const SFEGLSurface *EGLWindowBase::getSFWindow(void) const
{
    return &_sfWindow;
}

#ifdef OSG_1_GET_COMPAT
SFEGLSurface        *EGLWindowBase::getSFWindow         (void)
{
    return this->editSFWindow         ();
}
#endif

SFEGLContext *EGLWindowBase::editSFContext(void)
{
    editSField(ContextFieldMask);

    return &_sfContext;
}

const SFEGLContext *EGLWindowBase::getSFContext(void) const
{
    return &_sfContext;
}

#ifdef OSG_1_GET_COMPAT
SFEGLContext        *EGLWindowBase::getSFContext        (void)
{
    return this->editSFContext        ();
}
#endif





/*------------------------------ access -----------------------------------*/

UInt32 EGLWindowBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (DisplayFieldMask & whichField))
    {
        returnValue += _sfDisplay.getBinSize();
    }
    if(FieldBits::NoField != (WindowFieldMask & whichField))
    {
        returnValue += _sfWindow.getBinSize();
    }
    if(FieldBits::NoField != (ContextFieldMask & whichField))
    {
        returnValue += _sfContext.getBinSize();
    }

    return returnValue;
}

void EGLWindowBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (DisplayFieldMask & whichField))
    {
        _sfDisplay.copyToBin(pMem);
    }
    if(FieldBits::NoField != (WindowFieldMask & whichField))
    {
        _sfWindow.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ContextFieldMask & whichField))
    {
        _sfContext.copyToBin(pMem);
    }
}

void EGLWindowBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (DisplayFieldMask & whichField))
    {
        _sfDisplay.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (WindowFieldMask & whichField))
    {
        _sfWindow.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ContextFieldMask & whichField))
    {
        _sfContext.copyFromBin(pMem);
    }
}

//! create a new instance of the class
EGLWindowPtr EGLWindowBase::create(void)
{
    EGLWindowPtr fc;

    if(getClassType().getPrototype() != NullFC)
    {
        fc = dynamic_cast<EGLWindow::ObjPtr>(
            getClassType().getPrototype()-> shallowCopy());
    }

    return fc;
}

//! create an empty new instance of the class, do not copy the prototype
EGLWindowPtr EGLWindowBase::createEmpty(void)
{
    EGLWindowPtr returnValue;

    newPtr<EGLWindow>(returnValue);

    return returnValue;
}

FieldContainerPtr EGLWindowBase::shallowCopy(void) const
{
    EGLWindowPtr returnValue;

    newPtr(returnValue, dynamic_cast<const EGLWindow *>(this));

    return returnValue;
}



/*------------------------- constructors ----------------------------------*/

EGLWindowBase::EGLWindowBase(void) :
    Inherited(),
    _sfDisplay                (EGLDisplay(0)),
    _sfWindow                 (EGLSurface(0)),
    _sfContext                (EGLContext(0))
{
}

EGLWindowBase::EGLWindowBase(const EGLWindowBase &source) :
    Inherited(source),
    _sfDisplay                (source._sfDisplay                ),
    _sfWindow                 (source._sfWindow                 ),
    _sfContext                (source._sfContext                )
{
}


/*-------------------------- destructors ----------------------------------*/

EGLWindowBase::~EGLWindowBase(void)
{
}


GetFieldHandlePtr EGLWindowBase::getHandleDisplay         (void) const
{
    SFEGLDisplay::GetHandlePtr returnValue(
        new  SFEGLDisplay::GetHandle(
             &_sfDisplay, 
             this->getType().getFieldDesc(DisplayFieldId)));

    return returnValue;
}

EditFieldHandlePtr EGLWindowBase::editHandleDisplay        (void)
{
    SFEGLDisplay::EditHandlePtr returnValue(
        new  SFEGLDisplay::EditHandle(
             &_sfDisplay, 
             this->getType().getFieldDesc(DisplayFieldId)));

    editSField(DisplayFieldMask);

    return returnValue;
}

GetFieldHandlePtr EGLWindowBase::getHandleWindow          (void) const
{
    SFEGLSurface::GetHandlePtr returnValue(
        new  SFEGLSurface::GetHandle(
             &_sfWindow, 
             this->getType().getFieldDesc(WindowFieldId)));

    return returnValue;
}

EditFieldHandlePtr EGLWindowBase::editHandleWindow         (void)
{
    SFEGLSurface::EditHandlePtr returnValue(
        new  SFEGLSurface::EditHandle(
             &_sfWindow, 
             this->getType().getFieldDesc(WindowFieldId)));

    editSField(WindowFieldMask);

    return returnValue;
}

GetFieldHandlePtr EGLWindowBase::getHandleContext         (void) const
{
    SFEGLContext::GetHandlePtr returnValue(
        new  SFEGLContext::GetHandle(
             &_sfContext, 
             this->getType().getFieldDesc(ContextFieldId)));

    return returnValue;
}

EditFieldHandlePtr EGLWindowBase::editHandleContext        (void)
{
    SFEGLContext::EditHandlePtr returnValue(
        new  SFEGLContext::EditHandle(
             &_sfContext, 
             this->getType().getFieldDesc(ContextFieldId)));

    editSField(ContextFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void EGLWindowBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    this->execSync(static_cast<EGLWindowBase *>(&oFrom),
                   whichField,
                   oOffsets,
                   syncMode,
                   uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainerPtr EGLWindowBase::createAspectCopy(void) const
{
    EGLWindowPtr returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const EGLWindow *>(this));

    return returnValue;
}
#endif

void EGLWindowBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE

#include "OSGSFieldAdaptor.ins"
#include "OSGMFieldAdaptor.ins"

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<EGLWindowPtr>::_type("EGLWindowPtr", "WindowPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(EGLWindowPtr)

OSG_FIELD_DLLEXPORT_DEF2(SFieldAdaptor, EGLWindowPtr, SFFieldContainerPtr);
OSG_FIELD_DLLEXPORT_DEF2(MFieldAdaptor, EGLWindowPtr, MFFieldContainerPtr);

OSG_END_NAMESPACE
