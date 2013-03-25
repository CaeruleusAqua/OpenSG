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
 **     class DisplayFilterStage!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE



//! access the type of the class
inline
OSG::FieldContainerType &DisplayFilterStageBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 DisplayFilterStageBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 DisplayFilterStageBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the DisplayFilterStage::_sfActiveGroup field.

inline
Int32 &DisplayFilterStageBase::editActiveGroup(void)
{
    editSField(ActiveGroupFieldMask);

    return _sfActiveGroup.getValue();
}

//! Get the value of the DisplayFilterStage::_sfActiveGroup field.
inline
      Int32  DisplayFilterStageBase::getActiveGroup(void) const
{
    return _sfActiveGroup.getValue();
}

//! Set the value of the DisplayFilterStage::_sfActiveGroup field.
inline
void DisplayFilterStageBase::setActiveGroup(const Int32 value)
{
    editSField(ActiveGroupFieldMask);

    _sfActiveGroup.setValue(value);
}
//! Get the value of the DisplayFilterStage::_sfEnableMultiSample field.

inline
bool &DisplayFilterStageBase::editEnableMultiSample(void)
{
    editSField(EnableMultiSampleFieldMask);

    return _sfEnableMultiSample.getValue();
}

//! Get the value of the DisplayFilterStage::_sfEnableMultiSample field.
inline
      bool  DisplayFilterStageBase::getEnableMultiSample(void) const
{
    return _sfEnableMultiSample.getValue();
}

//! Set the value of the DisplayFilterStage::_sfEnableMultiSample field.
inline
void DisplayFilterStageBase::setEnableMultiSample(const bool value)
{
    editSField(EnableMultiSampleFieldMask);

    _sfEnableMultiSample.setValue(value);
}
//! Get the value of the DisplayFilterStage::_sfColorSamples field.

inline
UInt32 &DisplayFilterStageBase::editColorSamples(void)
{
    editSField(ColorSamplesFieldMask);

    return _sfColorSamples.getValue();
}

//! Get the value of the DisplayFilterStage::_sfColorSamples field.
inline
      UInt32  DisplayFilterStageBase::getColorSamples(void) const
{
    return _sfColorSamples.getValue();
}

//! Set the value of the DisplayFilterStage::_sfColorSamples field.
inline
void DisplayFilterStageBase::setColorSamples(const UInt32 value)
{
    editSField(ColorSamplesFieldMask);

    _sfColorSamples.setValue(value);
}
//! Get the value of the DisplayFilterStage::_sfCoverageSamples field.

inline
UInt32 &DisplayFilterStageBase::editCoverageSamples(void)
{
    editSField(CoverageSamplesFieldMask);

    return _sfCoverageSamples.getValue();
}

//! Get the value of the DisplayFilterStage::_sfCoverageSamples field.
inline
      UInt32  DisplayFilterStageBase::getCoverageSamples(void) const
{
    return _sfCoverageSamples.getValue();
}

//! Set the value of the DisplayFilterStage::_sfCoverageSamples field.
inline
void DisplayFilterStageBase::setCoverageSamples(const UInt32 value)
{
    editSField(CoverageSamplesFieldMask);

    _sfCoverageSamples.setValue(value);
}
//! Get the value of the DisplayFilterStage::_sfFixedSampleLocation field.

inline
bool &DisplayFilterStageBase::editFixedSampleLocation(void)
{
    editSField(FixedSampleLocationFieldMask);

    return _sfFixedSampleLocation.getValue();
}

//! Get the value of the DisplayFilterStage::_sfFixedSampleLocation field.
inline
      bool  DisplayFilterStageBase::getFixedSampleLocation(void) const
{
    return _sfFixedSampleLocation.getValue();
}

//! Set the value of the DisplayFilterStage::_sfFixedSampleLocation field.
inline
void DisplayFilterStageBase::setFixedSampleLocation(const bool value)
{
    editSField(FixedSampleLocationFieldMask);

    _sfFixedSampleLocation.setValue(value);
}




#ifdef OSG_MT_CPTR_ASPECT
inline
void DisplayFilterStageBase::execSync (      DisplayFilterStageBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (CalibrationPatternFilterFieldMask & whichField))
        _sfCalibrationPatternFilter.syncWith(pFrom->_sfCalibrationPatternFilter);

    if(FieldBits::NoField != (ResolutionFilterFieldMask & whichField))
        _sfResolutionFilter.syncWith(pFrom->_sfResolutionFilter);

    if(FieldBits::NoField != (ColorFilterFieldMask & whichField))
        _sfColorFilter.syncWith(pFrom->_sfColorFilter);

    if(FieldBits::NoField != (DistortionFilterFieldMask & whichField))
        _sfDistortionFilter.syncWith(pFrom->_sfDistortionFilter);

    if(FieldBits::NoField != (FilterGroupsFieldMask & whichField))
        _mfFilterGroups.syncWith(pFrom->_mfFilterGroups,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (ActiveGroupFieldMask & whichField))
        _sfActiveGroup.syncWith(pFrom->_sfActiveGroup);

    if(FieldBits::NoField != (EnableMultiSampleFieldMask & whichField))
        _sfEnableMultiSample.syncWith(pFrom->_sfEnableMultiSample);

    if(FieldBits::NoField != (ColorSamplesFieldMask & whichField))
        _sfColorSamples.syncWith(pFrom->_sfColorSamples);

    if(FieldBits::NoField != (CoverageSamplesFieldMask & whichField))
        _sfCoverageSamples.syncWith(pFrom->_sfCoverageSamples);

    if(FieldBits::NoField != (FixedSampleLocationFieldMask & whichField))
        _sfFixedSampleLocation.syncWith(pFrom->_sfFixedSampleLocation);

    if(FieldBits::NoField != (ForegroundsFieldMask & whichField))
        _mfForegrounds.syncWith(pFrom->_mfForegrounds,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);
}
#endif


inline
const Char8 *DisplayFilterStageBase::getClassname(void)
{
    return "DisplayFilterStage";
}
OSG_GEN_CONTAINERPTR(DisplayFilterStage);

OSG_END_NAMESPACE

