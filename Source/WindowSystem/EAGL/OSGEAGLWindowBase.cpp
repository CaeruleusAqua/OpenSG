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
 **     class EAGLWindow!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"




#include "OSGEAGLWindowBase.h"
#include "OSGEAGLWindow.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::EAGLWindow
    The class for MacOS X EAGL windows.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var EAGLContextP    EAGLWindowBase::_sfContext
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
PointerType FieldTraits<EAGLWindow *, nsOSG>::_type(
    "EAGLWindowPtr", 
    "WindowPtr", 
    EAGLWindow::getClassType(),
    nsOSG);
#endif

OSG_FIELDTRAITS_GETTYPE_NS(EAGLWindow *, nsOSG)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           EAGLWindow *,
                           nsOSG);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           EAGLWindow *,
                           nsOSG);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void EAGLWindowBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFEAGLContextP::Description(
        SFEAGLContextP::getClassType(),
        "context",
        "",
        ContextFieldId, ContextFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&EAGLWindow::editHandleContext),
        static_cast<FieldGetMethodSig >(&EAGLWindow::getHandleContext));

    oType.addInitialDesc(pDesc);
}


EAGLWindowBase::TypeObject EAGLWindowBase::_type(
    EAGLWindowBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    nsOSG, //Namespace
    reinterpret_cast<PrototypeCreateF>(&EAGLWindowBase::createEmptyLocal),
    EAGLWindow::initMethod,
    EAGLWindow::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&EAGLWindow::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "   name=\"EAGLWindow\"\n"
    "   parent=\"Window\"\n"
    "   library=\"WindowEAGL\"\n"
    "   pointerfieldtypes=\"both\"\n"
    "   structure=\"concrete\"\n"
    "   systemcomponent=\"true\"\n"
    "   parentsystemcomponent=\"true\"\n"
    "   docGroupBase=\"GrpWindowCocao\"\n"
    "   >\n"
    "  The class for MacOS X EAGL windows.\n"
    "  <Field\n"
    "\t name=\"context\"\n"
    "\t type=\"EAGLContextP\"\n"
    "\t cardinality=\"single\"\n"
    "\t visibility=\"internal\"\n"
    "\t defaultValue=\"0\"\n"
    "\t fieldHeader=\"OSGEAGLWindowDataFields.h\"\n"
    "\t access=\"public\"\n"
    "\t >\n"
    "  </Field>\n"
    "</FieldContainer>\n",
    "The class for MacOS X EAGL windows.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &EAGLWindowBase::getType(void)
{
    return _type;
}

const FieldContainerType &EAGLWindowBase::getType(void) const
{
    return _type;
}

UInt32 EAGLWindowBase::getContainerSize(void) const
{
    return sizeof(EAGLWindow);
}

/*------------------------- decorator get ------------------------------*/


SFEAGLContextP *EAGLWindowBase::editSFContext(void)
{
    editSField(ContextFieldMask);

    return &_sfContext;
}

const SFEAGLContextP *EAGLWindowBase::getSFContext(void) const
{
    return &_sfContext;
}






/*------------------------------ access -----------------------------------*/

SizeT EAGLWindowBase::getBinSize(ConstFieldMaskArg whichField)
{
    SizeT returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ContextFieldMask & whichField))
    {
        returnValue += _sfContext.getBinSize();
    }

    return returnValue;
}

void EAGLWindowBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ContextFieldMask & whichField))
    {
        _sfContext.copyToBin(pMem);
    }
}

void EAGLWindowBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ContextFieldMask & whichField))
    {
        editSField(ContextFieldMask);
        _sfContext.copyFromBin(pMem);
    }
}

//! create a new instance of the class
EAGLWindowTransitPtr EAGLWindowBase::createLocal(BitVector bFlags)
{
    EAGLWindowTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<EAGLWindow>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
EAGLWindowTransitPtr EAGLWindowBase::createDependent(BitVector bFlags)
{
    EAGLWindowTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<EAGLWindow>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
EAGLWindowTransitPtr EAGLWindowBase::create(void)
{
    EAGLWindowTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<EAGLWindow>(tmpPtr);
    }

    return fc;
}

EAGLWindow *EAGLWindowBase::createEmptyLocal(BitVector bFlags)
{
    EAGLWindow *returnValue;

    newPtr<EAGLWindow>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
EAGLWindow *EAGLWindowBase::createEmpty(void)
{
    EAGLWindow *returnValue;

    newPtr<EAGLWindow>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr EAGLWindowBase::shallowCopyLocal(
    BitVector bFlags) const
{
    EAGLWindow *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const EAGLWindow *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr EAGLWindowBase::shallowCopyDependent(
    BitVector bFlags) const
{
    EAGLWindow *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const EAGLWindow *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr EAGLWindowBase::shallowCopy(void) const
{
    EAGLWindow *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const EAGLWindow *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

EAGLWindowBase::EAGLWindowBase(void) :
    Inherited(),
    _sfContext                (EAGLContextP(0))
{
}

EAGLWindowBase::EAGLWindowBase(const EAGLWindowBase &source) :
    Inherited(source),
    _sfContext                (source._sfContext                )
{
}


/*-------------------------- destructors ----------------------------------*/

EAGLWindowBase::~EAGLWindowBase(void)
{
}


GetFieldHandlePtr EAGLWindowBase::getHandleContext         (void) const
{
    SFEAGLContextP::GetHandlePtr returnValue(
        new  SFEAGLContextP::GetHandle(
             &_sfContext,
             this->getType().getFieldDesc(ContextFieldId),
             const_cast<EAGLWindowBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr EAGLWindowBase::editHandleContext        (void)
{
    SFEAGLContextP::EditHandlePtr returnValue(
        new  SFEAGLContextP::EditHandle(
             &_sfContext,
             this->getType().getFieldDesc(ContextFieldId),
             this));


    editSField(ContextFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void EAGLWindowBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    EAGLWindow *pThis = static_cast<EAGLWindow *>(this);

    pThis->execSync(static_cast<EAGLWindow *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *EAGLWindowBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    EAGLWindow *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const EAGLWindow *>(pRefAspect),
                  dynamic_cast<const EAGLWindow *>(this));

    return returnValue;
}
#endif

void EAGLWindowBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
