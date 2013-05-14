/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2013 by the OpenSG Forum                 *
 *                                                                           *
 * contact: dirk@opensg.org, gerrit.voss@vossg.org, carsten_neumann@gmx.net  *
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
 **     class ComplexSceneManager!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE



//! access the type of the class
inline
OSG::FieldContainerType &ComplexSceneManagerBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 ComplexSceneManagerBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 ComplexSceneManagerBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the ComplexSceneManager::_sfStartTime field.

inline
Time &ComplexSceneManagerBase::editStartTime(void)
{
    editSField(StartTimeFieldMask);

    return _sfStartTime.getValue();
}

//! Get the value of the ComplexSceneManager::_sfStartTime field.
inline
const Time &ComplexSceneManagerBase::getStartTime(void) const
{
    return _sfStartTime.getValue();
}

//! Set the value of the ComplexSceneManager::_sfStartTime field.
inline
void ComplexSceneManagerBase::setStartTime(const Time &value)
{
    editSField(StartTimeFieldMask);

    _sfStartTime.setValue(value);
}
//! Get the value of the ComplexSceneManager::_sfTimeScale field.

inline
Time &ComplexSceneManagerBase::editTimeScale(void)
{
    editSField(TimeScaleFieldMask);

    return _sfTimeScale.getValue();
}

//! Get the value of the ComplexSceneManager::_sfTimeScale field.
inline
const Time &ComplexSceneManagerBase::getTimeScale(void) const
{
    return _sfTimeScale.getValue();
}

//! Set the value of the ComplexSceneManager::_sfTimeScale field.
inline
void ComplexSceneManagerBase::setTimeScale(const Time &value)
{
    editSField(TimeScaleFieldMask);

    _sfTimeScale.setValue(value);
}
//! Get the value of the ComplexSceneManager::_sfConstantTimeStep field.

inline
Time &ComplexSceneManagerBase::editConstantTimeStep(void)
{
    editSField(ConstantTimeStepFieldMask);

    return _sfConstantTimeStep.getValue();
}

//! Get the value of the ComplexSceneManager::_sfConstantTimeStep field.
inline
const Time &ComplexSceneManagerBase::getConstantTimeStep(void) const
{
    return _sfConstantTimeStep.getValue();
}

//! Set the value of the ComplexSceneManager::_sfConstantTimeStep field.
inline
void ComplexSceneManagerBase::setConstantTimeStep(const Time &value)
{
    editSField(ConstantTimeStepFieldMask);

    _sfConstantTimeStep.setValue(value);
}
//! Get the value of the ComplexSceneManager::_sfConstantTime field.

inline
bool &ComplexSceneManagerBase::editConstantTime(void)
{
    editSField(ConstantTimeFieldMask);

    return _sfConstantTime.getValue();
}

//! Get the value of the ComplexSceneManager::_sfConstantTime field.
inline
      bool  ComplexSceneManagerBase::getConstantTime(void) const
{
    return _sfConstantTime.getValue();
}

//! Set the value of the ComplexSceneManager::_sfConstantTime field.
inline
void ComplexSceneManagerBase::setConstantTime(const bool value)
{
    editSField(ConstantTimeFieldMask);

    _sfConstantTime.setValue(value);
}
//! Get the value of the ComplexSceneManager::_sfPaused field.

inline
bool &ComplexSceneManagerBase::editPaused(void)
{
    editSField(PausedFieldMask);

    return _sfPaused.getValue();
}

//! Get the value of the ComplexSceneManager::_sfPaused field.
inline
      bool  ComplexSceneManagerBase::getPaused(void) const
{
    return _sfPaused.getValue();
}

//! Set the value of the ComplexSceneManager::_sfPaused field.
inline
void ComplexSceneManagerBase::setPaused(const bool value)
{
    editSField(PausedFieldMask);

    _sfPaused.setValue(value);
}
//! Get the value of the ComplexSceneManager::_sfDumpFrameStart field.

inline
bool &ComplexSceneManagerBase::editDumpFrameStart(void)
{
    editSField(DumpFrameStartFieldMask);

    return _sfDumpFrameStart.getValue();
}

//! Get the value of the ComplexSceneManager::_sfDumpFrameStart field.
inline
      bool  ComplexSceneManagerBase::getDumpFrameStart(void) const
{
    return _sfDumpFrameStart.getValue();
}

//! Set the value of the ComplexSceneManager::_sfDumpFrameStart field.
inline
void ComplexSceneManagerBase::setDumpFrameStart(const bool value)
{
    editSField(DumpFrameStartFieldMask);

    _sfDumpFrameStart.setValue(value);
}
//! Get the value of the ComplexSceneManager::_sfEnableWebService field.

inline
bool &ComplexSceneManagerBase::editEnableWebService(void)
{
    editSField(EnableWebServiceFieldMask);

    return _sfEnableWebService.getValue();
}

//! Get the value of the ComplexSceneManager::_sfEnableWebService field.
inline
      bool  ComplexSceneManagerBase::getEnableWebService(void) const
{
    return _sfEnableWebService.getValue();
}

//! Set the value of the ComplexSceneManager::_sfEnableWebService field.
inline
void ComplexSceneManagerBase::setEnableWebService(const bool value)
{
    editSField(EnableWebServiceFieldMask);

    _sfEnableWebService.setValue(value);
}
//! Get the value of the ComplexSceneManager::_sfWebServicePort field.

inline
UInt32 &ComplexSceneManagerBase::editWebServicePort(void)
{
    editSField(WebServicePortFieldMask);

    return _sfWebServicePort.getValue();
}

//! Get the value of the ComplexSceneManager::_sfWebServicePort field.
inline
      UInt32  ComplexSceneManagerBase::getWebServicePort(void) const
{
    return _sfWebServicePort.getValue();
}

//! Set the value of the ComplexSceneManager::_sfWebServicePort field.
inline
void ComplexSceneManagerBase::setWebServicePort(const UInt32 value)
{
    editSField(WebServicePortFieldMask);

    _sfWebServicePort.setValue(value);
}
//! Get the value of the ComplexSceneManager::_sfWebServiceRoot field.

inline
std::string &ComplexSceneManagerBase::editWebServiceRoot(void)
{
    editSField(WebServiceRootFieldMask);

    return _sfWebServiceRoot.getValue();
}

//! Get the value of the ComplexSceneManager::_sfWebServiceRoot field.
inline
const std::string &ComplexSceneManagerBase::getWebServiceRoot(void) const
{
    return _sfWebServiceRoot.getValue();
}

//! Set the value of the ComplexSceneManager::_sfWebServiceRoot field.
inline
void ComplexSceneManagerBase::setWebServiceRoot(const std::string &value)
{
    editSField(WebServiceRootFieldMask);

    _sfWebServiceRoot.setValue(value);
}
//! Get the value of the ComplexSceneManager::_sfWaitKeyAfterFrame field.

inline
bool &ComplexSceneManagerBase::editWaitKeyAfterFrame(void)
{
    editSField(WaitKeyAfterFrameFieldMask);

    return _sfWaitKeyAfterFrame.getValue();
}

//! Get the value of the ComplexSceneManager::_sfWaitKeyAfterFrame field.
inline
      bool  ComplexSceneManagerBase::getWaitKeyAfterFrame(void) const
{
    return _sfWaitKeyAfterFrame.getValue();
}

//! Set the value of the ComplexSceneManager::_sfWaitKeyAfterFrame field.
inline
void ComplexSceneManagerBase::setWaitKeyAfterFrame(const bool value)
{
    editSField(WaitKeyAfterFrameFieldMask);

    _sfWaitKeyAfterFrame.setValue(value);
}



#ifdef OSG_MT_CPTR_ASPECT
inline
void ComplexSceneManagerBase::execSync (      ComplexSceneManagerBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (GlobalsFieldMask & whichField))
        _mfGlobals.syncWith(pFrom->_mfGlobals,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (DrawManagerFieldMask & whichField))
        _sfDrawManager.syncWith(pFrom->_sfDrawManager);

    if(FieldBits::NoField != (StartTimeFieldMask & whichField))
        _sfStartTime.syncWith(pFrom->_sfStartTime);

    if(FieldBits::NoField != (TimeScaleFieldMask & whichField))
        _sfTimeScale.syncWith(pFrom->_sfTimeScale);

    if(FieldBits::NoField != (ConstantTimeStepFieldMask & whichField))
        _sfConstantTimeStep.syncWith(pFrom->_sfConstantTimeStep);

    if(FieldBits::NoField != (ConstantTimeFieldMask & whichField))
        _sfConstantTime.syncWith(pFrom->_sfConstantTime);

    if(FieldBits::NoField != (PausedFieldMask & whichField))
        _sfPaused.syncWith(pFrom->_sfPaused);

    if(FieldBits::NoField != (DumpFrameStartFieldMask & whichField))
        _sfDumpFrameStart.syncWith(pFrom->_sfDumpFrameStart);

    if(FieldBits::NoField != (EnableWebServiceFieldMask & whichField))
        _sfEnableWebService.syncWith(pFrom->_sfEnableWebService);

    if(FieldBits::NoField != (WebServicePortFieldMask & whichField))
        _sfWebServicePort.syncWith(pFrom->_sfWebServicePort);

    if(FieldBits::NoField != (WebServiceRootFieldMask & whichField))
        _sfWebServiceRoot.syncWith(pFrom->_sfWebServiceRoot);

    if(FieldBits::NoField != (WaitKeyAfterFrameFieldMask & whichField))
        _sfWaitKeyAfterFrame.syncWith(pFrom->_sfWaitKeyAfterFrame);
}
#endif


inline
const Char8 *ComplexSceneManagerBase::getClassname(void)
{
    return "ComplexSceneManager";
}
OSG_GEN_CONTAINERPTR(ComplexSceneManager);

OSG_END_NAMESPACE

