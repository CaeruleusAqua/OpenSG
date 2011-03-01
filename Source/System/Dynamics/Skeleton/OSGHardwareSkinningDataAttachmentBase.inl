/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
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
 **     class HardwareSkinningDataAttachment!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &HardwareSkinningDataAttachmentBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 HardwareSkinningDataAttachmentBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 HardwareSkinningDataAttachmentBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/


//! Get the value of the HardwareSkinningDataAttachment::_sfShaderCode field.
inline
ShaderProgramChunk * HardwareSkinningDataAttachmentBase::getShaderCode(void) const
{
    return _sfShaderCode.getValue();
}

//! Set the value of the HardwareSkinningDataAttachment::_sfShaderCode field.
inline
void HardwareSkinningDataAttachmentBase::setShaderCode(ShaderProgramChunk * const value)
{
    editSField(ShaderCodeFieldMask);

    _sfShaderCode.setValue(value);
}
//! Get the value of the HardwareSkinningDataAttachment::_sfDataValid field.

inline
bool &HardwareSkinningDataAttachmentBase::editDataValid(void)
{
    editSField(DataValidFieldMask);

    return _sfDataValid.getValue();
}

//! Get the value of the HardwareSkinningDataAttachment::_sfDataValid field.
inline
      bool  HardwareSkinningDataAttachmentBase::getDataValid(void) const
{
    return _sfDataValid.getValue();
}

//! Set the value of the HardwareSkinningDataAttachment::_sfDataValid field.
inline
void HardwareSkinningDataAttachmentBase::setDataValid(const bool value)
{
    editSField(DataValidFieldMask);

    _sfDataValid.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void HardwareSkinningDataAttachmentBase::execSync (      HardwareSkinningDataAttachmentBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (ShaderCodeFieldMask & whichField))
        _sfShaderCode.syncWith(pFrom->_sfShaderCode);

    if(FieldBits::NoField != (DataValidFieldMask & whichField))
        _sfDataValid.syncWith(pFrom->_sfDataValid);
}
#endif


inline
const Char8 *HardwareSkinningDataAttachmentBase::getClassname(void)
{
    return "HardwareSkinningDataAttachment";
}
OSG_GEN_CONTAINERPTR(HardwareSkinningDataAttachment);

OSG_END_NAMESPACE
