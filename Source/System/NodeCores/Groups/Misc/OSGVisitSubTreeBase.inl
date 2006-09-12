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


//! Get the value of the VisitSubTree::_sfSubTreeRoot field.
inline
NodePtrConst VisitSubTreeBase::getSubTreeRoot(void) const
{
    return _sfSubTreeRoot.getValue();
}

//! Set the value of the VisitSubTree::_sfSubTreeRoot field.
inline
void VisitSubTreeBase::setSubTreeRoot(NodePtrConstArg value)
{
    editSField(SubTreeRootFieldMask);

    setRefd(_sfSubTreeRoot.getValue(), value);

}

//! create a new instance of the class
inline
VisitSubTreePtr VisitSubTreeBase::create(void) 
{
    VisitSubTreePtr fc; 

    if(getClassType().getPrototype() != NullFC) 
    {
        fc = OSG::cast_dynamic<VisitSubTree::ObjPtr>(
            getClassType().getPrototype()-> shallowCopy()); 
    }
    
    return fc; 
}

#ifdef OSG_MT_FIELDCONTAINERPTR
inline
void VisitSubTreeBase::execSync(      VisitSubTreeBase *pOther,
                                       ConstFieldMaskArg  whichField,
                                       ConstFieldMaskArg  syncMode  ,
                                 const UInt32             uiSyncInfo,
                                       UInt32             uiCopyOffset)
{
    Inherited::execSync(pOther, whichField, syncMode, uiSyncInfo, uiCopyOffset);

    if(FieldBits::NoField != (SubTreeRootFieldMask & whichField))
        _sfSubTreeRoot.syncWith(pOther->_sfSubTreeRoot);
}
#endif

#ifdef OSG_MT_CPTR_ASPECT
inline
void VisitSubTreeBase::execSync (      VisitSubTreeBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode  ,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (SubTreeRootFieldMask & whichField))
        _sfSubTreeRoot.syncWith(pFrom->_sfSubTreeRoot);
}
#endif

#if 0
inline
void VisitSubTreeBase::execBeginEdit(ConstFieldMaskArg whichField,
                                      UInt32            uiAspect,
                                      UInt32            uiContainerSize)
{
    Inherited::execBeginEdit(whichField, uiAspect, uiContainerSize);
}
#endif


inline
Char8 *VisitSubTreeBase::getClassname(void)
{
    return "VisitSubTree";
}

typedef PointerBuilder<VisitSubTree>::ObjPtr          VisitSubTreePtr;
typedef PointerBuilder<VisitSubTree>::ObjPtrConst     VisitSubTreePtrConst;
typedef PointerBuilder<VisitSubTree>::ObjConstPtr     VisitSubTreeConstPtr;

typedef PointerBuilder<VisitSubTree>::ObjPtrArg       VisitSubTreePtrArg;
typedef PointerBuilder<VisitSubTree>::ObjConstPtrArg  VisitSubTreeConstPtrArg;
typedef PointerBuilder<VisitSubTree>::ObjPtrConstArg  VisitSubTreePtrConstArg;

OSG_END_NAMESPACE

#define OSGVISITSUBTREEBASE_INLINE_CVSID "@(#)$Id: $"

