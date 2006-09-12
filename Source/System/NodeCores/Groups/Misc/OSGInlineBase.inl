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
 **     class Inline!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &InlineBase::getClassType(void)
{
    return _type; 
} 

//! access the numerical type of the class
inline
OSG::UInt32 InlineBase::getClassTypeId(void) 
{
    return _type.getId(); 
} 

inline
OSG::UInt16 InlineBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the Inline::_sfLoaded field.

inline
bool &InlineBase::editLoaded(void)
{
    editSField(LoadedFieldMask);

    return _sfLoaded.getValue();
}

//! Get the value of the Inline::_sfLoaded field.
inline
const bool &InlineBase::getLoaded(void) const
{
    return _sfLoaded.getValue();
}

#ifdef OSG_1_COMPAT
inline
bool &InlineBase::getLoaded(void)
{
    return this->editLoaded();
}
#endif

//! Set the value of the Inline::_sfLoaded field.
inline
void InlineBase::setLoaded(const bool &value)
{
    editSField(LoadedFieldMask);

    _sfLoaded.setValue(value);
}

//! Get the value of the \a index element the Inline::_mfUrl field.
inline
const std::string &InlineBase::getUrl(const UInt32 index) const
{
    return _mfUrl[index];
}

inline
std::string &InlineBase::editUrl(const UInt32 index)
{
    editMField(UrlFieldMask, _mfUrl);

    return _mfUrl[index];
}

//! Get the Inline::_mfUrl field.
inline
MFString &InlineBase::editUrl(void)
{
    editMField(UrlFieldMask, _mfUrl);

    return _mfUrl;
}

#ifdef OSG_1_COMPAT
inline
std::string &InlineBase::getUrl(const UInt32 index)
{
    return this->editUrl(index);
}

inline
MFString &InlineBase::getUrl(void)
{
    return this->editUrl();
}

#endif


//! Get the Inline::_mfUrl field.
inline
const MFString &InlineBase::getUrl(void) const
{
    return _mfUrl;
}

//! create a new instance of the class
inline
InlinePtr InlineBase::create(void) 
{
    InlinePtr fc; 

    if(getClassType().getPrototype() != NullFC) 
    {
        fc = OSG::cast_dynamic<Inline::ObjPtr>(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

#ifdef OSG_MT_FIELDCONTAINERPTR
inline
void InlineBase::execSync(      InlineBase *pOther,
                                       ConstFieldMaskArg  whichField,
                                       ConstFieldMaskArg  syncMode  ,
                                 const UInt32             uiSyncInfo,
                                       UInt32             uiCopyOffset)
{
    Inherited::execSync(pOther, whichField, syncMode, uiSyncInfo, uiCopyOffset);

    if(FieldBits::NoField != (UrlFieldMask & whichField))
        _mfUrl.syncWith(pOther->_mfUrl, 
                                syncMode,
                                uiSyncInfo,
                                uiCopyOffset);

    if(FieldBits::NoField != (LoadedFieldMask & whichField))
        _sfLoaded.syncWith(pOther->_sfLoaded);
}
#endif

#ifdef OSG_MT_CPTR_ASPECT
inline
void InlineBase::execSync (      InlineBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode  ,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (UrlFieldMask & whichField))
        _mfUrl.syncWith(pFrom->_mfUrl, 
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (LoadedFieldMask & whichField))
        _sfLoaded.syncWith(pFrom->_sfLoaded);
}
#endif

#if 0
inline
void InlineBase::execBeginEdit(ConstFieldMaskArg whichField,
                                      UInt32            uiAspect,
                                      UInt32            uiContainerSize)
{
    Inherited::execBeginEdit(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (UrlFieldMask & whichField))
    {
        _mfUrl.beginEdit(uiAspect, uiContainerSize);
    }
}
#endif


inline
Char8 *InlineBase::getClassname(void)
{
    return "Inline";
}

typedef PointerBuilder<Inline>::ObjPtr          InlinePtr;
typedef PointerBuilder<Inline>::ObjPtrConst     InlinePtrConst;
typedef PointerBuilder<Inline>::ObjConstPtr     InlineConstPtr;

typedef PointerBuilder<Inline>::ObjPtrArg       InlinePtrArg;
typedef PointerBuilder<Inline>::ObjConstPtrArg  InlineConstPtrArg;
typedef PointerBuilder<Inline>::ObjPtrConstArg  InlinePtrConstArg;

OSG_END_NAMESPACE

#define OSGINLINEBASE_INLINE_CVSID "@(#)$Id: $"

