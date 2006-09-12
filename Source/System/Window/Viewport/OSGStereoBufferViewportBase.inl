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
 **     class StereoBufferViewport!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &StereoBufferViewportBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 StereoBufferViewportBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

inline
OSG::UInt16 StereoBufferViewportBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the StereoBufferViewport::_sfLeftBuffer field.

inline
bool &StereoBufferViewportBase::editLeftBuffer(void)
{
    editSField(LeftBufferFieldMask);

    return _sfLeftBuffer.getValue();
}

//! Get the value of the StereoBufferViewport::_sfLeftBuffer field.
inline
const bool &StereoBufferViewportBase::getLeftBuffer(void) const
{
    return _sfLeftBuffer.getValue();
}

#ifdef OSG_1_COMPAT
inline
bool &StereoBufferViewportBase::getLeftBuffer(void)
{
    return this->editLeftBuffer();
}
#endif

//! Set the value of the StereoBufferViewport::_sfLeftBuffer field.
inline
void StereoBufferViewportBase::setLeftBuffer(const bool &value)
{
    editSField(LeftBufferFieldMask);

    _sfLeftBuffer.setValue(value);
}
//! Get the value of the StereoBufferViewport::_sfRightBuffer field.

inline
bool &StereoBufferViewportBase::editRightBuffer(void)
{
    editSField(RightBufferFieldMask);

    return _sfRightBuffer.getValue();
}

//! Get the value of the StereoBufferViewport::_sfRightBuffer field.
inline
const bool &StereoBufferViewportBase::getRightBuffer(void) const
{
    return _sfRightBuffer.getValue();
}

#ifdef OSG_1_COMPAT
inline
bool &StereoBufferViewportBase::getRightBuffer(void)
{
    return this->editRightBuffer();
}
#endif

//! Set the value of the StereoBufferViewport::_sfRightBuffer field.
inline
void StereoBufferViewportBase::setRightBuffer(const bool &value)
{
    editSField(RightBufferFieldMask);

    _sfRightBuffer.setValue(value);
}

//! create a new instance of the class
inline
StereoBufferViewportPtr StereoBufferViewportBase::create(void) 
{
    StereoBufferViewportPtr fc; 

    if(getClassType().getPrototype() != NullFC) 
    {
        fc = OSG::cast_dynamic<StereoBufferViewport::ObjPtr>(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

#ifdef OSG_MT_FIELDCONTAINERPTR
inline
void StereoBufferViewportBase::execSync(      StereoBufferViewportBase *pOther,
                                       ConstFieldMaskArg  whichField,
                                       ConstFieldMaskArg  syncMode  ,
                                 const UInt32             uiSyncInfo,
                                       UInt32             uiCopyOffset)
{
    Inherited::execSync(pOther, whichField, syncMode, uiSyncInfo, uiCopyOffset);

    if(FieldBits::NoField != (LeftBufferFieldMask & whichField))
        _sfLeftBuffer.syncWith(pOther->_sfLeftBuffer);

    if(FieldBits::NoField != (RightBufferFieldMask & whichField))
        _sfRightBuffer.syncWith(pOther->_sfRightBuffer);
}
#endif

#ifdef OSG_MT_CPTR_ASPECT
inline
void StereoBufferViewportBase::execSync (      StereoBufferViewportBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode  ,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (LeftBufferFieldMask & whichField))
        _sfLeftBuffer.syncWith(pFrom->_sfLeftBuffer);

    if(FieldBits::NoField != (RightBufferFieldMask & whichField))
        _sfRightBuffer.syncWith(pFrom->_sfRightBuffer);
}
#endif

#if 0
inline
void StereoBufferViewportBase::execBeginEdit(ConstFieldMaskArg whichField,
                                      UInt32            uiAspect,
                                      UInt32            uiContainerSize)
{
    Inherited::execBeginEdit(whichField, uiAspect, uiContainerSize);
}
#endif


inline
Char8 *StereoBufferViewportBase::getClassname(void)
{
    return "StereoBufferViewport";
}

typedef PointerBuilder<StereoBufferViewport>::ObjPtr          StereoBufferViewportPtr;
typedef PointerBuilder<StereoBufferViewport>::ObjPtrConst     StereoBufferViewportPtrConst;
typedef PointerBuilder<StereoBufferViewport>::ObjConstPtr     StereoBufferViewportConstPtr;

typedef PointerBuilder<StereoBufferViewport>::ObjPtrArg       StereoBufferViewportPtrArg;
typedef PointerBuilder<StereoBufferViewport>::ObjConstPtrArg  StereoBufferViewportConstPtrArg;
typedef PointerBuilder<StereoBufferViewport>::ObjPtrConstArg  StereoBufferViewportPtrConstArg;

OSG_END_NAMESPACE

#define OSGSTEREOBUFFERVIEWPORTBASE_INLINE_CVSID "@(#)$Id: $"

