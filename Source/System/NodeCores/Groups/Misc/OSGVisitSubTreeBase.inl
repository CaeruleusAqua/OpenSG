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
 **     class VisitSubTree!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE



//! access the type of the class
inline
OSG::FieldContainerType &VisitSubTreeBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 VisitSubTreeBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 VisitSubTreeBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the VisitSubTree::_sfSubTreeTravMask field.

inline
UInt32 &VisitSubTreeBase::editSubTreeTravMask(void)
{
    editSField(SubTreeTravMaskFieldMask);

    return _sfSubTreeTravMask.getValue();
}

//! Get the value of the VisitSubTree::_sfSubTreeTravMask field.
inline
      UInt32  VisitSubTreeBase::getSubTreeTravMask(void) const
{
    return _sfSubTreeTravMask.getValue();
}

//! Set the value of the VisitSubTree::_sfSubTreeTravMask field.
inline
void VisitSubTreeBase::setSubTreeTravMask(const UInt32 value)
{
    editSField(SubTreeTravMaskFieldMask);

    _sfSubTreeTravMask.setValue(value);
}
//! Get the value of the VisitSubTree::_sfTravMaskMode field.

inline
UInt32 &VisitSubTreeBase::editTravMaskMode(void)
{
    editSField(TravMaskModeFieldMask);

    return _sfTravMaskMode.getValue();
}

//! Get the value of the VisitSubTree::_sfTravMaskMode field.
inline
      UInt32  VisitSubTreeBase::getTravMaskMode(void) const
{
    return _sfTravMaskMode.getValue();
}

//! Set the value of the VisitSubTree::_sfTravMaskMode field.
inline
void VisitSubTreeBase::setTravMaskMode(const UInt32 value)
{
    editSField(TravMaskModeFieldMask);

    _sfTravMaskMode.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void VisitSubTreeBase::execSync (      VisitSubTreeBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (SubTreeRootFieldMask & whichField))
        _sfSubTreeRoot.syncWith(pFrom->_sfSubTreeRoot);

    if(FieldBits::NoField != (SubTreeTravMaskFieldMask & whichField))
        _sfSubTreeTravMask.syncWith(pFrom->_sfSubTreeTravMask);

    if(FieldBits::NoField != (TravMaskModeFieldMask & whichField))
        _sfTravMaskMode.syncWith(pFrom->_sfTravMaskMode);
}
#endif


inline
const Char8 *VisitSubTreeBase::getClassname(void)
{
    return "VisitSubTree";
}
OSG_GEN_CONTAINERPTR(VisitSubTree);

OSG_END_NAMESPACE

