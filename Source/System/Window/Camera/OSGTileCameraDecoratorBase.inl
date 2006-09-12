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
 **     class TileCameraDecorator!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &TileCameraDecoratorBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 TileCameraDecoratorBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

inline
OSG::UInt16 TileCameraDecoratorBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the TileCameraDecorator::_sfLeft field.

inline
Real32 &TileCameraDecoratorBase::editLeft(void)
{
    editSField(LeftFieldMask);

    return _sfLeft.getValue();
}

//! Get the value of the TileCameraDecorator::_sfLeft field.
inline
const Real32 &TileCameraDecoratorBase::getLeft(void) const
{
    return _sfLeft.getValue();
}

#ifdef OSG_1_COMPAT
inline
Real32 &TileCameraDecoratorBase::getLeft(void)
{
    return this->editLeft();
}
#endif

//! Set the value of the TileCameraDecorator::_sfLeft field.
inline
void TileCameraDecoratorBase::setLeft(const Real32 &value)
{
    editSField(LeftFieldMask);

    _sfLeft.setValue(value);
}
//! Get the value of the TileCameraDecorator::_sfRight field.

inline
Real32 &TileCameraDecoratorBase::editRight(void)
{
    editSField(RightFieldMask);

    return _sfRight.getValue();
}

//! Get the value of the TileCameraDecorator::_sfRight field.
inline
const Real32 &TileCameraDecoratorBase::getRight(void) const
{
    return _sfRight.getValue();
}

#ifdef OSG_1_COMPAT
inline
Real32 &TileCameraDecoratorBase::getRight(void)
{
    return this->editRight();
}
#endif

//! Set the value of the TileCameraDecorator::_sfRight field.
inline
void TileCameraDecoratorBase::setRight(const Real32 &value)
{
    editSField(RightFieldMask);

    _sfRight.setValue(value);
}
//! Get the value of the TileCameraDecorator::_sfBottom field.

inline
Real32 &TileCameraDecoratorBase::editBottom(void)
{
    editSField(BottomFieldMask);

    return _sfBottom.getValue();
}

//! Get the value of the TileCameraDecorator::_sfBottom field.
inline
const Real32 &TileCameraDecoratorBase::getBottom(void) const
{
    return _sfBottom.getValue();
}

#ifdef OSG_1_COMPAT
inline
Real32 &TileCameraDecoratorBase::getBottom(void)
{
    return this->editBottom();
}
#endif

//! Set the value of the TileCameraDecorator::_sfBottom field.
inline
void TileCameraDecoratorBase::setBottom(const Real32 &value)
{
    editSField(BottomFieldMask);

    _sfBottom.setValue(value);
}
//! Get the value of the TileCameraDecorator::_sfTop field.

inline
Real32 &TileCameraDecoratorBase::editTop(void)
{
    editSField(TopFieldMask);

    return _sfTop.getValue();
}

//! Get the value of the TileCameraDecorator::_sfTop field.
inline
const Real32 &TileCameraDecoratorBase::getTop(void) const
{
    return _sfTop.getValue();
}

#ifdef OSG_1_COMPAT
inline
Real32 &TileCameraDecoratorBase::getTop(void)
{
    return this->editTop();
}
#endif

//! Set the value of the TileCameraDecorator::_sfTop field.
inline
void TileCameraDecoratorBase::setTop(const Real32 &value)
{
    editSField(TopFieldMask);

    _sfTop.setValue(value);
}
//! Get the value of the TileCameraDecorator::_sfFullWidth field.

inline
UInt32 &TileCameraDecoratorBase::editFullWidth(void)
{
    editSField(FullWidthFieldMask);

    return _sfFullWidth.getValue();
}

//! Get the value of the TileCameraDecorator::_sfFullWidth field.
inline
const UInt32 &TileCameraDecoratorBase::getFullWidth(void) const
{
    return _sfFullWidth.getValue();
}

#ifdef OSG_1_COMPAT
inline
UInt32 &TileCameraDecoratorBase::getFullWidth(void)
{
    return this->editFullWidth();
}
#endif

//! Set the value of the TileCameraDecorator::_sfFullWidth field.
inline
void TileCameraDecoratorBase::setFullWidth(const UInt32 &value)
{
    editSField(FullWidthFieldMask);

    _sfFullWidth.setValue(value);
}
//! Get the value of the TileCameraDecorator::_sfFullHeight field.

inline
UInt32 &TileCameraDecoratorBase::editFullHeight(void)
{
    editSField(FullHeightFieldMask);

    return _sfFullHeight.getValue();
}

//! Get the value of the TileCameraDecorator::_sfFullHeight field.
inline
const UInt32 &TileCameraDecoratorBase::getFullHeight(void) const
{
    return _sfFullHeight.getValue();
}

#ifdef OSG_1_COMPAT
inline
UInt32 &TileCameraDecoratorBase::getFullHeight(void)
{
    return this->editFullHeight();
}
#endif

//! Set the value of the TileCameraDecorator::_sfFullHeight field.
inline
void TileCameraDecoratorBase::setFullHeight(const UInt32 &value)
{
    editSField(FullHeightFieldMask);

    _sfFullHeight.setValue(value);
}

//! create a new instance of the class
inline
TileCameraDecoratorPtr TileCameraDecoratorBase::create(void) 
{
    TileCameraDecoratorPtr fc; 

    if(getClassType().getPrototype() != NullFC) 
    {
        fc = OSG::cast_dynamic<TileCameraDecorator::ObjPtr>(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

#ifdef OSG_MT_FIELDCONTAINERPTR
inline
void TileCameraDecoratorBase::execSync(      TileCameraDecoratorBase *pOther,
                                       ConstFieldMaskArg  whichField,
                                       ConstFieldMaskArg  syncMode  ,
                                 const UInt32             uiSyncInfo,
                                       UInt32             uiCopyOffset)
{
    Inherited::execSync(pOther, whichField, syncMode, uiSyncInfo, uiCopyOffset);

    if(FieldBits::NoField != (LeftFieldMask & whichField))
        _sfLeft.syncWith(pOther->_sfLeft);

    if(FieldBits::NoField != (RightFieldMask & whichField))
        _sfRight.syncWith(pOther->_sfRight);

    if(FieldBits::NoField != (BottomFieldMask & whichField))
        _sfBottom.syncWith(pOther->_sfBottom);

    if(FieldBits::NoField != (TopFieldMask & whichField))
        _sfTop.syncWith(pOther->_sfTop);

    if(FieldBits::NoField != (FullWidthFieldMask & whichField))
        _sfFullWidth.syncWith(pOther->_sfFullWidth);

    if(FieldBits::NoField != (FullHeightFieldMask & whichField))
        _sfFullHeight.syncWith(pOther->_sfFullHeight);
}
#endif

#ifdef OSG_MT_CPTR_ASPECT
inline
void TileCameraDecoratorBase::execSync (      TileCameraDecoratorBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode  ,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (LeftFieldMask & whichField))
        _sfLeft.syncWith(pFrom->_sfLeft);

    if(FieldBits::NoField != (RightFieldMask & whichField))
        _sfRight.syncWith(pFrom->_sfRight);

    if(FieldBits::NoField != (BottomFieldMask & whichField))
        _sfBottom.syncWith(pFrom->_sfBottom);

    if(FieldBits::NoField != (TopFieldMask & whichField))
        _sfTop.syncWith(pFrom->_sfTop);

    if(FieldBits::NoField != (FullWidthFieldMask & whichField))
        _sfFullWidth.syncWith(pFrom->_sfFullWidth);

    if(FieldBits::NoField != (FullHeightFieldMask & whichField))
        _sfFullHeight.syncWith(pFrom->_sfFullHeight);
}
#endif

#if 0
inline
void TileCameraDecoratorBase::execBeginEdit(ConstFieldMaskArg whichField,
                                      UInt32            uiAspect,
                                      UInt32            uiContainerSize)
{
    Inherited::execBeginEdit(whichField, uiAspect, uiContainerSize);
}
#endif


inline
Char8 *TileCameraDecoratorBase::getClassname(void)
{
    return "TileCameraDecorator";
}

typedef PointerBuilder<TileCameraDecorator>::ObjPtr          TileCameraDecoratorPtr;
typedef PointerBuilder<TileCameraDecorator>::ObjPtrConst     TileCameraDecoratorPtrConst;
typedef PointerBuilder<TileCameraDecorator>::ObjConstPtr     TileCameraDecoratorConstPtr;

typedef PointerBuilder<TileCameraDecorator>::ObjPtrArg       TileCameraDecoratorPtrArg;
typedef PointerBuilder<TileCameraDecorator>::ObjConstPtrArg  TileCameraDecoratorConstPtrArg;
typedef PointerBuilder<TileCameraDecorator>::ObjPtrConstArg  TileCameraDecoratorPtrConstArg;

OSG_END_NAMESPACE

#define OSGTILECAMERADECORATORBASE_INLINE_CVSID "@(#)$Id: $"

