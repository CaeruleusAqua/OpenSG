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
 **     class ScreenTransform!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE



//! access the type of the class
inline
OSG::FieldContainerType &ScreenTransformBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 ScreenTransformBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 ScreenTransformBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the ScreenTransform::_sfInvertWorldTransform field.

inline
bool &ScreenTransformBase::editInvertWorldTransform(void)
{
    editSField(InvertWorldTransformFieldMask);

    return _sfInvertWorldTransform.getValue();
}

//! Get the value of the ScreenTransform::_sfInvertWorldTransform field.
inline
      bool  ScreenTransformBase::getInvertWorldTransform(void) const
{
    return _sfInvertWorldTransform.getValue();
}

//! Set the value of the ScreenTransform::_sfInvertWorldTransform field.
inline
void ScreenTransformBase::setInvertWorldTransform(const bool value)
{
    editSField(InvertWorldTransformFieldMask);

    _sfInvertWorldTransform.setValue(value);
}
//! Get the value of the ScreenTransform::_sfInvertViewTransform field.

inline
bool &ScreenTransformBase::editInvertViewTransform(void)
{
    editSField(InvertViewTransformFieldMask);

    return _sfInvertViewTransform.getValue();
}

//! Get the value of the ScreenTransform::_sfInvertViewTransform field.
inline
      bool  ScreenTransformBase::getInvertViewTransform(void) const
{
    return _sfInvertViewTransform.getValue();
}

//! Set the value of the ScreenTransform::_sfInvertViewTransform field.
inline
void ScreenTransformBase::setInvertViewTransform(const bool value)
{
    editSField(InvertViewTransformFieldMask);

    _sfInvertViewTransform.setValue(value);
}
//! Get the value of the ScreenTransform::_sfApplyBeaconRotation field.

inline
bool &ScreenTransformBase::editApplyBeaconRotation(void)
{
    editSField(ApplyBeaconRotationFieldMask);

    return _sfApplyBeaconRotation.getValue();
}

//! Get the value of the ScreenTransform::_sfApplyBeaconRotation field.
inline
      bool  ScreenTransformBase::getApplyBeaconRotation(void) const
{
    return _sfApplyBeaconRotation.getValue();
}

//! Set the value of the ScreenTransform::_sfApplyBeaconRotation field.
inline
void ScreenTransformBase::setApplyBeaconRotation(const bool value)
{
    editSField(ApplyBeaconRotationFieldMask);

    _sfApplyBeaconRotation.setValue(value);
}
//! Get the value of the ScreenTransform::_sfApplyBeaconScreenTranslation field.

inline
bool &ScreenTransformBase::editApplyBeaconScreenTranslation(void)
{
    editSField(ApplyBeaconScreenTranslationFieldMask);

    return _sfApplyBeaconScreenTranslation.getValue();
}

//! Get the value of the ScreenTransform::_sfApplyBeaconScreenTranslation field.
inline
      bool  ScreenTransformBase::getApplyBeaconScreenTranslation(void) const
{
    return _sfApplyBeaconScreenTranslation.getValue();
}

//! Set the value of the ScreenTransform::_sfApplyBeaconScreenTranslation field.
inline
void ScreenTransformBase::setApplyBeaconScreenTranslation(const bool value)
{
    editSField(ApplyBeaconScreenTranslationFieldMask);

    _sfApplyBeaconScreenTranslation.setValue(value);
}
//! Get the value of the ScreenTransform::_sfView field.

inline
Matrix &ScreenTransformBase::editView(void)
{
    editSField(ViewFieldMask);

    return _sfView.getValue();
}

//! Get the value of the ScreenTransform::_sfView field.
inline
const Matrix &ScreenTransformBase::getView(void) const
{
    return _sfView.getValue();
}

//! Set the value of the ScreenTransform::_sfView field.
inline
void ScreenTransformBase::setView(const Matrix &value)
{
    editSField(ViewFieldMask);

    _sfView.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void ScreenTransformBase::execSync (      ScreenTransformBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (BeaconFieldMask & whichField))
        _sfBeacon.syncWith(pFrom->_sfBeacon);

    if(FieldBits::NoField != (InvertWorldTransformFieldMask & whichField))
        _sfInvertWorldTransform.syncWith(pFrom->_sfInvertWorldTransform);

    if(FieldBits::NoField != (InvertViewTransformFieldMask & whichField))
        _sfInvertViewTransform.syncWith(pFrom->_sfInvertViewTransform);

    if(FieldBits::NoField != (ApplyBeaconRotationFieldMask & whichField))
        _sfApplyBeaconRotation.syncWith(pFrom->_sfApplyBeaconRotation);

    if(FieldBits::NoField != (ApplyBeaconScreenTranslationFieldMask & whichField))
        _sfApplyBeaconScreenTranslation.syncWith(pFrom->_sfApplyBeaconScreenTranslation);

    if(FieldBits::NoField != (ViewFieldMask & whichField))
        _sfView.syncWith(pFrom->_sfView);
}
#endif


inline
const Char8 *ScreenTransformBase::getClassname(void)
{
    return "ScreenTransform";
}
OSG_GEN_CONTAINERPTR(ScreenTransform);

OSG_END_NAMESPACE

