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
 **     class DisplayFilter!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE



//! access the type of the class
inline
OSG::FieldContainerType &DisplayFilterBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 DisplayFilterBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 DisplayFilterBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the DisplayFilter::_sfEnabled field.

inline
bool &DisplayFilterBase::editEnabled(void)
{
    editSField(EnabledFieldMask);

    return _sfEnabled.getValue();
}

//! Get the value of the DisplayFilter::_sfEnabled field.
inline
      bool  DisplayFilterBase::getEnabled(void) const
{
    return _sfEnabled.getValue();
}

//! Set the value of the DisplayFilter::_sfEnabled field.
inline
void DisplayFilterBase::setEnabled(const bool value)
{
    editSField(EnabledFieldMask);

    _sfEnabled.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void DisplayFilterBase::execSync (      DisplayFilterBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (EnabledFieldMask & whichField))
        _sfEnabled.syncWith(pFrom->_sfEnabled);
}
#endif


inline
const Char8 *DisplayFilterBase::getClassname(void)
{
    return "DisplayFilter";
}
OSG_GEN_CONTAINERPTR(DisplayFilter);

OSG_END_NAMESPACE

