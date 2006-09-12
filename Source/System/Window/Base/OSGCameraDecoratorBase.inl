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
 **     class CameraDecorator!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &CameraDecoratorBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 CameraDecoratorBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

inline
OSG::UInt16 CameraDecoratorBase::getClassGroupId(void)
{
    return _type.getGroupId();
}


inline
const CameraPtrConst CameraDecoratorBase::getDecoratee(void) const
{
    return _sfDecoratee.getValue();
}

inline
void CameraDecoratorBase::setDecoratee(const CameraPtr &value)
{
    editSField(DecorateeFieldMask);

    setRefd(_sfDecoratee.getValue(), value);
}

#ifdef OSG_MT_FIELDCONTAINERPTR
inline
void CameraDecoratorBase::execSync(      CameraDecoratorBase *pOther,
                                       ConstFieldMaskArg  whichField,
                                       ConstFieldMaskArg  syncMode  ,
                                 const UInt32             uiSyncInfo,
                                       UInt32             uiCopyOffset)
{
    Inherited::execSync(pOther, whichField, syncMode, uiSyncInfo, uiCopyOffset);

    if(FieldBits::NoField != (DecorateeFieldMask & whichField))
    {
        _sfDecoratee.syncWith(pOther->_sfDecoratee);
    }
}
#endif

#ifdef OSG_MT_CPTR_ASPECT
inline
void CameraDecoratorBase::execSync (      CameraDecoratorBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode  ,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (DecorateeFieldMask & whichField))
    {
        _sfDecoratee.syncWith(pFrom->_sfDecoratee);
    }
}
#endif

#if 0
inline
void CameraDecoratorBase::execBeginEdit(ConstFieldMaskArg whichField,
                                      UInt32            uiAspect,
                                      UInt32            uiContainerSize)
{
    Inherited::execBeginEdit(whichField, uiAspect, uiContainerSize);
}
#endif


inline
Char8 *CameraDecoratorBase::getClassname(void)
{
    return "CameraDecorator";
}

typedef PointerBuilder<CameraDecorator>::ObjPtr          CameraDecoratorPtr;
typedef PointerBuilder<CameraDecorator>::ObjPtrConst     CameraDecoratorPtrConst;
typedef PointerBuilder<CameraDecorator>::ObjConstPtr     CameraDecoratorConstPtr;

typedef PointerBuilder<CameraDecorator>::ObjPtrArg       CameraDecoratorPtrArg;
typedef PointerBuilder<CameraDecorator>::ObjConstPtrArg  CameraDecoratorConstPtrArg;
typedef PointerBuilder<CameraDecorator>::ObjPtrConstArg  CameraDecoratorPtrConstArg;

OSG_END_NAMESPACE

#define OSGCAMERADECORATORBASE_INLINE_CVSID "@(#)$Id: $"

