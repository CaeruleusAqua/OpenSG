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
 **     class KeySensor!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"




#include "OSGKeySensorBase.h"
#include "OSGKeySensor.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::KeySensor
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var std::string     KeySensorBase::_sfKey
    
*/

/*! \var bool            KeySensorBase::_sfStateRaw
    
*/

/*! \var bool            KeySensorBase::_sfStateFlipFlop
    
*/

/*! \var OSGAny          KeySensorBase::_sfSignalPressed
    
*/

/*! \var OSGAny          KeySensorBase::_sfSignalReleased
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<KeySensor *>::_type("KeySensorPtr", "AttachmentContainerPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(KeySensor *)

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void KeySensorBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFString::Description(
        SFString::getClassType(),
        "key",
        "",
        KeyFieldId, KeyFieldMask,
        true,
        (Field::FThreadLocal),
        static_cast<FieldEditMethodSig>(&KeySensor::editHandleKey),
        static_cast<FieldGetMethodSig >(&KeySensor::getHandleKey));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "stateRaw",
        "",
        StateRawFieldId, StateRawFieldMask,
        true,
        (Field::FThreadLocal),
        static_cast<FieldEditMethodSig>(&KeySensor::editHandleStateRaw),
        static_cast<FieldGetMethodSig >(&KeySensor::getHandleStateRaw));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "stateFlipFlop",
        "",
        StateFlipFlopFieldId, StateFlipFlopFieldMask,
        true,
        (Field::FThreadLocal),
        static_cast<FieldEditMethodSig>(&KeySensor::editHandleStateFlipFlop),
        static_cast<FieldGetMethodSig >(&KeySensor::getHandleStateFlipFlop));

    oType.addInitialDesc(pDesc);

    pDesc = new SFOSGAny::Description(
        SFOSGAny::getClassType(),
        "signalPressed",
        "",
        SignalPressedFieldId, SignalPressedFieldMask,
        true,
        (Field::FThreadLocal),
        static_cast<FieldEditMethodSig>(&KeySensor::editHandleSignalPressed),
        static_cast<FieldGetMethodSig >(&KeySensor::getHandleSignalPressed));

    oType.addInitialDesc(pDesc);

    pDesc = new SFOSGAny::Description(
        SFOSGAny::getClassType(),
        "signalReleased",
        "",
        SignalReleasedFieldId, SignalReleasedFieldMask,
        true,
        (Field::FThreadLocal),
        static_cast<FieldEditMethodSig>(&KeySensor::editHandleSignalReleased),
        static_cast<FieldGetMethodSig >(&KeySensor::getHandleSignalReleased));

    oType.addInitialDesc(pDesc);
}


KeySensorBase::TypeObject KeySensorBase::_type(
    KeySensorBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&KeySensorBase::createEmptyLocal),
    KeySensor::initMethod,
    KeySensor::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&KeySensor::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "    name=\"KeySensor\"\n"
    "    parent=\"AttachmentContainer\"\n"
    "    library=\"ContribCSM\"\n"
    "    pointerfieldtypes=\"none\"\n"
    "    structure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    decoratable=\"false\"\n"
    "    useLocalIncludes=\"false\"\n"
    "    isNodeCore=\"false\"\n"
    "    isBundle=\"true\"\n"
    "    parentFields=\"none\"\n"
    ">\n"
    "\t<Field\n"
    "\t\tname=\"key\"\n"
    "\t\ttype=\"std::string\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"protected\"\n"
    "        defaultValue=\"\"\n"
    "        fieldFlags=\"FThreadLocal\"\n"
    " \t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"stateRaw\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"public\"\n"
    "        defaultValue=\"true\"\n"
    "        fieldFlags=\"FThreadLocal\"\n"
    " \t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"stateFlipFlop\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"public\"\n"
    "        defaultValue=\"false\"\n"
    "        fieldFlags=\"FThreadLocal\"\n"
    "\t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"signalPressed\"\n"
    "\t\ttype=\"OSGAny\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"protected\"\n"
    "        fieldFlags=\"FThreadLocal\"\n"
    " \t>\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"signalReleased\"\n"
    "\t\ttype=\"OSGAny\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"internal\"\n"
    "\t\taccess=\"protected\"\n"
    "        fieldFlags=\"FThreadLocal\"\n"
    " \t>\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &KeySensorBase::getType(void)
{
    return _type;
}

const FieldContainerType &KeySensorBase::getType(void) const
{
    return _type;
}

UInt32 KeySensorBase::getContainerSize(void) const
{
    return sizeof(KeySensor);
}

/*------------------------- decorator get ------------------------------*/


SFString *KeySensorBase::editSFKey(void)
{
    editSField(KeyFieldMask);

    return &_sfKey;
}

const SFString *KeySensorBase::getSFKey(void) const
{
    return &_sfKey;
}


SFBool *KeySensorBase::editSFStateRaw(void)
{
    editSField(StateRawFieldMask);

    return &_sfStateRaw;
}

const SFBool *KeySensorBase::getSFStateRaw(void) const
{
    return &_sfStateRaw;
}


SFBool *KeySensorBase::editSFStateFlipFlop(void)
{
    editSField(StateFlipFlopFieldMask);

    return &_sfStateFlipFlop;
}

const SFBool *KeySensorBase::getSFStateFlipFlop(void) const
{
    return &_sfStateFlipFlop;
}


SFOSGAny *KeySensorBase::editSFSignalPressed(void)
{
    editSField(SignalPressedFieldMask);

    return &_sfSignalPressed;
}

const SFOSGAny *KeySensorBase::getSFSignalPressed(void) const
{
    return &_sfSignalPressed;
}


SFOSGAny *KeySensorBase::editSFSignalReleased(void)
{
    editSField(SignalReleasedFieldMask);

    return &_sfSignalReleased;
}

const SFOSGAny *KeySensorBase::getSFSignalReleased(void) const
{
    return &_sfSignalReleased;
}






/*------------------------------ access -----------------------------------*/

UInt32 KeySensorBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (KeyFieldMask & whichField))
    {
        returnValue += _sfKey.getBinSize();
    }
    if(FieldBits::NoField != (StateRawFieldMask & whichField))
    {
        returnValue += _sfStateRaw.getBinSize();
    }
    if(FieldBits::NoField != (StateFlipFlopFieldMask & whichField))
    {
        returnValue += _sfStateFlipFlop.getBinSize();
    }
    if(FieldBits::NoField != (SignalPressedFieldMask & whichField))
    {
        returnValue += _sfSignalPressed.getBinSize();
    }
    if(FieldBits::NoField != (SignalReleasedFieldMask & whichField))
    {
        returnValue += _sfSignalReleased.getBinSize();
    }

    return returnValue;
}

void KeySensorBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (KeyFieldMask & whichField))
    {
        _sfKey.copyToBin(pMem);
    }
    if(FieldBits::NoField != (StateRawFieldMask & whichField))
    {
        _sfStateRaw.copyToBin(pMem);
    }
    if(FieldBits::NoField != (StateFlipFlopFieldMask & whichField))
    {
        _sfStateFlipFlop.copyToBin(pMem);
    }
    if(FieldBits::NoField != (SignalPressedFieldMask & whichField))
    {
        _sfSignalPressed.copyToBin(pMem);
    }
    if(FieldBits::NoField != (SignalReleasedFieldMask & whichField))
    {
        _sfSignalReleased.copyToBin(pMem);
    }
}

void KeySensorBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (KeyFieldMask & whichField))
    {
        _sfKey.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (StateRawFieldMask & whichField))
    {
        _sfStateRaw.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (StateFlipFlopFieldMask & whichField))
    {
        _sfStateFlipFlop.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (SignalPressedFieldMask & whichField))
    {
        _sfSignalPressed.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (SignalReleasedFieldMask & whichField))
    {
        _sfSignalReleased.copyFromBin(pMem);
    }
}

//! create a new instance of the class
KeySensorTransitPtr KeySensorBase::createLocal(BitVector bFlags)
{
    KeySensorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<KeySensor>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
KeySensorTransitPtr KeySensorBase::createDependent(BitVector bFlags)
{
    KeySensorTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<KeySensor>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
KeySensorTransitPtr KeySensorBase::create(void)
{
    return createLocal();
}

KeySensor *KeySensorBase::createEmptyLocal(BitVector bFlags)
{
    KeySensor *returnValue;

    newPtr<KeySensor>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
KeySensor *KeySensorBase::createEmpty(void)
{
    return createEmptyLocal();
}


FieldContainerTransitPtr KeySensorBase::shallowCopyLocal(
    BitVector bFlags) const
{
    KeySensor *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const KeySensor *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr KeySensorBase::shallowCopyDependent(
    BitVector bFlags) const
{
    KeySensor *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const KeySensor *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr KeySensorBase::shallowCopy(void) const
{
    return shallowCopyLocal();
}




/*------------------------- constructors ----------------------------------*/

KeySensorBase::KeySensorBase(void) :
    Inherited(),
    _sfKey                    (),
    _sfStateRaw               (bool(true)),
    _sfStateFlipFlop          (bool(false)),
    _sfSignalPressed          (),
    _sfSignalReleased         ()
{
}

KeySensorBase::KeySensorBase(const KeySensorBase &source) :
    Inherited(source),
    _sfKey                    (source._sfKey                    ),
    _sfStateRaw               (source._sfStateRaw               ),
    _sfStateFlipFlop          (source._sfStateFlipFlop          ),
    _sfSignalPressed          (source._sfSignalPressed          ),
    _sfSignalReleased         (source._sfSignalReleased         )
{
}


/*-------------------------- destructors ----------------------------------*/

KeySensorBase::~KeySensorBase(void)
{
}


GetFieldHandlePtr KeySensorBase::getHandleKey             (void) const
{
    SFString::GetHandlePtr returnValue(
        new  SFString::GetHandle(
             &_sfKey,
             this->getType().getFieldDesc(KeyFieldId),
             const_cast<KeySensorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr KeySensorBase::editHandleKey            (void)
{
    SFString::EditHandlePtr returnValue(
        new  SFString::EditHandle(
             &_sfKey,
             this->getType().getFieldDesc(KeyFieldId),
             this));


    editSField(KeyFieldMask);

    return returnValue;
}

GetFieldHandlePtr KeySensorBase::getHandleStateRaw        (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfStateRaw,
             this->getType().getFieldDesc(StateRawFieldId),
             const_cast<KeySensorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr KeySensorBase::editHandleStateRaw       (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfStateRaw,
             this->getType().getFieldDesc(StateRawFieldId),
             this));


    editSField(StateRawFieldMask);

    return returnValue;
}

GetFieldHandlePtr KeySensorBase::getHandleStateFlipFlop   (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfStateFlipFlop,
             this->getType().getFieldDesc(StateFlipFlopFieldId),
             const_cast<KeySensorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr KeySensorBase::editHandleStateFlipFlop  (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfStateFlipFlop,
             this->getType().getFieldDesc(StateFlipFlopFieldId),
             this));


    editSField(StateFlipFlopFieldMask);

    return returnValue;
}

GetFieldHandlePtr KeySensorBase::getHandleSignalPressed   (void) const
{
    SFOSGAny::GetHandlePtr returnValue(
        new  SFOSGAny::GetHandle(
             &_sfSignalPressed,
             this->getType().getFieldDesc(SignalPressedFieldId),
             const_cast<KeySensorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr KeySensorBase::editHandleSignalPressed  (void)
{
    SFOSGAny::EditHandlePtr returnValue(
        new  SFOSGAny::EditHandle(
             &_sfSignalPressed,
             this->getType().getFieldDesc(SignalPressedFieldId),
             this));


    editSField(SignalPressedFieldMask);

    return returnValue;
}

GetFieldHandlePtr KeySensorBase::getHandleSignalReleased  (void) const
{
    SFOSGAny::GetHandlePtr returnValue(
        new  SFOSGAny::GetHandle(
             &_sfSignalReleased,
             this->getType().getFieldDesc(SignalReleasedFieldId),
             const_cast<KeySensorBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr KeySensorBase::editHandleSignalReleased (void)
{
    SFOSGAny::EditHandlePtr returnValue(
        new  SFOSGAny::EditHandle(
             &_sfSignalReleased,
             this->getType().getFieldDesc(SignalReleasedFieldId),
             this));


    editSField(SignalReleasedFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void KeySensorBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    KeySensor *pThis = static_cast<KeySensor *>(this);

    pThis->execSync(static_cast<KeySensor *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *KeySensorBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    KeySensor *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const KeySensor *>(pRefAspect),
                  dynamic_cast<const KeySensor *>(this));

    return returnValue;
}
#endif

void KeySensorBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
