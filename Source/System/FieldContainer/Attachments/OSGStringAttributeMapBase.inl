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
 **     class StringAttributeMap!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE



//! access the type of the class
inline
OSG::FieldContainerType &StringAttributeMapBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 StringAttributeMapBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 StringAttributeMapBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/


//! Get the value of the \a index element the StringAttributeMap::_mfKeys field.
inline
const std::string &StringAttributeMapBase::getKeys(const UInt32 index) const
{
    return _mfKeys[index];
}

inline
std::string &StringAttributeMapBase::editKeys(const UInt32 index)
{
    editMField(KeysFieldMask, _mfKeys);

    return _mfKeys[index];
}

//! Get the value of the \a index element the StringAttributeMap::_mfValues field.
inline
const std::string &StringAttributeMapBase::getValues(const UInt32 index) const
{
    return _mfValues[index];
}

inline
std::string &StringAttributeMapBase::editValues(const UInt32 index)
{
    editMField(ValuesFieldMask, _mfValues);

    return _mfValues[index];
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void StringAttributeMapBase::execSync (      StringAttributeMapBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (KeysFieldMask & whichField))
        _mfKeys.syncWith(pFrom->_mfKeys,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (ValuesFieldMask & whichField))
        _mfValues.syncWith(pFrom->_mfValues,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);
}
#endif


inline
const Char8 *StringAttributeMapBase::getClassname(void)
{
    return "StringAttributeMap";
}
OSG_GEN_CONTAINERPTR(StringAttributeMap);

OSG_END_NAMESPACE

