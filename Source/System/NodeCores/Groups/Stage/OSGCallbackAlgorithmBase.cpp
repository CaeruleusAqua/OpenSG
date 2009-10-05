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
 **     class CallbackAlgorithm!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGCallbackAlgorithmBase.h"
#include "OSGCallbackAlgorithm.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::CallbackAlgorithm
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var RenderFunctorCallback CallbackAlgorithmBase::_sfCallback
    Inherited the parent target if none is set  
*/

/*! \var RenderActionFunctorCallback CallbackAlgorithmBase::_sfRenderEnter
    Inherited the parent target if none is set  
*/

/*! \var RenderActionFunctorCallback CallbackAlgorithmBase::_sfRenderLeave
    Inherited the parent target if none is set  
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<CallbackAlgorithm *>::_type("CallbackAlgorithmPtr", "AlgorithmPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(CallbackAlgorithm *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           CallbackAlgorithm *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           CallbackAlgorithm *,
                           0);

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void CallbackAlgorithmBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFRenderFunctorCallback::Description(
        SFRenderFunctorCallback::getClassType(),
        "callback",
        "Inherited the parent target if none is set  \n",
        CallbackFieldId, CallbackFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast     <FieldEditMethodSig>(&CallbackAlgorithm::invalidEditField),
        static_cast     <FieldGetMethodSig >(&CallbackAlgorithm::invalidGetField));

    oType.addInitialDesc(pDesc);

    pDesc = new SFRenderActionFunctorCallback::Description(
        SFRenderActionFunctorCallback::getClassType(),
        "renderEnter",
        "Inherited the parent target if none is set  \n",
        RenderEnterFieldId, RenderEnterFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast     <FieldEditMethodSig>(&CallbackAlgorithm::invalidEditField),
        static_cast     <FieldGetMethodSig >(&CallbackAlgorithm::invalidGetField));

    oType.addInitialDesc(pDesc);

    pDesc = new SFRenderActionFunctorCallback::Description(
        SFRenderActionFunctorCallback::getClassType(),
        "renderLeave",
        "Inherited the parent target if none is set  \n",
        RenderLeaveFieldId, RenderLeaveFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast     <FieldEditMethodSig>(&CallbackAlgorithm::invalidEditField),
        static_cast     <FieldGetMethodSig >(&CallbackAlgorithm::invalidGetField));

    oType.addInitialDesc(pDesc);
}


CallbackAlgorithmBase::TypeObject CallbackAlgorithmBase::_type(
    CallbackAlgorithmBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&CallbackAlgorithmBase::createEmptyLocal),
    CallbackAlgorithm::initMethod,
    CallbackAlgorithm::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&CallbackAlgorithm::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "   name=\"CallbackAlgorithm\"\n"
    "   parent=\"Algorithm\"\n"
    "   library=\"Group\"\n"
    "   pointerfieldtypes=\"both\"\n"
    "   structure=\"concrete\"\n"
    "   systemcomponent=\"true\"\n"
    "   parentsystemcomponent=\"true\"\n"
    "   decoratable=\"false\"\n"
    "   useLocalIncludes=\"false\"\n"
    "   isNodeCore=\"false\"\n"
    "   >\n"
    "  <Field\n"
    "     name=\"callback\"\n"
    "     type=\"RenderFunctorCallback\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     access=\"none\"\n"
    "     >\n"
    "    Inherited the parent target if none is set  \n"
    "  </Field>\n"
    "\n"
    "  <Field\n"
    "     name=\"renderEnter\"\n"
    "     type=\"RenderActionFunctorCallback\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     access=\"none\"\n"
    "     >\n"
    "    Inherited the parent target if none is set  \n"
    "  </Field>\n"
    "\n"
    "  <Field\n"
    "     name=\"renderLeave\"\n"
    "     type=\"RenderActionFunctorCallback\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     access=\"none\"\n"
    "     >\n"
    "    Inherited the parent target if none is set  \n"
    "  </Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &CallbackAlgorithmBase::getType(void)
{
    return _type;
}

const FieldContainerType &CallbackAlgorithmBase::getType(void) const
{
    return _type;
}

UInt32 CallbackAlgorithmBase::getContainerSize(void) const
{
    return sizeof(CallbackAlgorithm);
}

/*------------------------- decorator get ------------------------------*/









/*------------------------------ access -----------------------------------*/

UInt32 CallbackAlgorithmBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (CallbackFieldMask & whichField))
    {
        returnValue += _sfCallback.getBinSize();
    }
    if(FieldBits::NoField != (RenderEnterFieldMask & whichField))
    {
        returnValue += _sfRenderEnter.getBinSize();
    }
    if(FieldBits::NoField != (RenderLeaveFieldMask & whichField))
    {
        returnValue += _sfRenderLeave.getBinSize();
    }

    return returnValue;
}

void CallbackAlgorithmBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (CallbackFieldMask & whichField))
    {
        _sfCallback.copyToBin(pMem);
    }
    if(FieldBits::NoField != (RenderEnterFieldMask & whichField))
    {
        _sfRenderEnter.copyToBin(pMem);
    }
    if(FieldBits::NoField != (RenderLeaveFieldMask & whichField))
    {
        _sfRenderLeave.copyToBin(pMem);
    }
}

void CallbackAlgorithmBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (CallbackFieldMask & whichField))
    {
        _sfCallback.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (RenderEnterFieldMask & whichField))
    {
        _sfRenderEnter.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (RenderLeaveFieldMask & whichField))
    {
        _sfRenderLeave.copyFromBin(pMem);
    }
}

//! create a new instance of the class
CallbackAlgorithmTransitPtr CallbackAlgorithmBase::createLocal(BitVector bFlags)
{
    CallbackAlgorithmTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<CallbackAlgorithm>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
CallbackAlgorithmTransitPtr CallbackAlgorithmBase::createDependent(BitVector bFlags)
{
    CallbackAlgorithmTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<CallbackAlgorithm>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
CallbackAlgorithmTransitPtr CallbackAlgorithmBase::create(void)
{
    CallbackAlgorithmTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<CallbackAlgorithm>(tmpPtr);
    }

    return fc;
}

CallbackAlgorithm *CallbackAlgorithmBase::createEmptyLocal(BitVector bFlags)
{
    CallbackAlgorithm *returnValue;

    newPtr<CallbackAlgorithm>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
CallbackAlgorithm *CallbackAlgorithmBase::createEmpty(void)
{
    CallbackAlgorithm *returnValue;

    newPtr<CallbackAlgorithm>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr CallbackAlgorithmBase::shallowCopyLocal(
    BitVector bFlags) const
{
    CallbackAlgorithm *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const CallbackAlgorithm *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr CallbackAlgorithmBase::shallowCopyDependent(
    BitVector bFlags) const
{
    CallbackAlgorithm *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const CallbackAlgorithm *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr CallbackAlgorithmBase::shallowCopy(void) const
{
    CallbackAlgorithm *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const CallbackAlgorithm *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

CallbackAlgorithmBase::CallbackAlgorithmBase(void) :
    Inherited(),
    _sfCallback               (),
    _sfRenderEnter            (),
    _sfRenderLeave            ()
{
}

CallbackAlgorithmBase::CallbackAlgorithmBase(const CallbackAlgorithmBase &source) :
    Inherited(source),
    _sfCallback               (source._sfCallback               ),
    _sfRenderEnter            (source._sfRenderEnter            ),
    _sfRenderLeave            (source._sfRenderLeave            )
{
}


/*-------------------------- destructors ----------------------------------*/

CallbackAlgorithmBase::~CallbackAlgorithmBase(void)
{
}


GetFieldHandlePtr CallbackAlgorithmBase::getHandleCallback        (void) const
{
    SFRenderFunctorCallback::GetHandlePtr returnValue;

    return returnValue;
}

EditFieldHandlePtr CallbackAlgorithmBase::editHandleCallback       (void)
{
    EditFieldHandlePtr returnValue;

    return returnValue;
}

GetFieldHandlePtr CallbackAlgorithmBase::getHandleRenderEnter     (void) const
{
    SFRenderActionFunctorCallback::GetHandlePtr returnValue;

    return returnValue;
}

EditFieldHandlePtr CallbackAlgorithmBase::editHandleRenderEnter    (void)
{
    EditFieldHandlePtr returnValue;

    return returnValue;
}

GetFieldHandlePtr CallbackAlgorithmBase::getHandleRenderLeave     (void) const
{
    SFRenderActionFunctorCallback::GetHandlePtr returnValue;

    return returnValue;
}

EditFieldHandlePtr CallbackAlgorithmBase::editHandleRenderLeave    (void)
{
    EditFieldHandlePtr returnValue;

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void CallbackAlgorithmBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    CallbackAlgorithm *pThis = static_cast<CallbackAlgorithm *>(this);

    pThis->execSync(static_cast<CallbackAlgorithm *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *CallbackAlgorithmBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    CallbackAlgorithm *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const CallbackAlgorithm *>(pRefAspect),
                  dynamic_cast<const CallbackAlgorithm *>(this));

    return returnValue;
}
#endif

void CallbackAlgorithmBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
