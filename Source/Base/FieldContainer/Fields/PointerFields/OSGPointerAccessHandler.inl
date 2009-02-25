/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *                 Copyright (C) 2008 by the OpenSG Forum                    *
 *                                                                           *
 *                            www.opensg.org                                 *
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

OSG_BEGIN_NAMESPACE

/*-------------------------------------------------------------------------*/
/* Access Handling                                                         */

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onAdd(
    SFieldBaseType * const, 
    FieldContainer * const pObj)
{
    RefCountPolicyType::addRef(pObj);
}

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onAdd(
    MFieldBaseType * const, 
    FieldContainer * const pObj)
{
    RefCountPolicyType::addRef(pObj);
}

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onSub(
    SFieldBaseType * const, 
    FieldContainer * const pObj)
{
    RefCountPolicyType::subRef(pObj);
}

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onSub(
    MFieldBaseType * const, 
    FieldContainer * const pObj)
{
    RefCountPolicyType::subRef(pObj);
}

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onReplace(
    SFieldBaseType * const pSField,
    FieldContainer * const pOldObj,
    FieldContainer * const pNewObj)
{
    onAdd(pSField, pNewObj);
    onSub(pSField, pOldObj);
}

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onReplace(
    MFieldBaseType * const pMField,
    FieldContainer * const pOldObj,
    FieldContainer * const pNewObj)
{
    onAdd(pMField, pNewObj);
    onSub(pMField, pOldObj);
}

/*-------------------------------------------------------------------------*/
/* Sync Access Handling                                                    */

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onSyncAdd(
    SFieldBaseType * const pSField, 
    FieldContainer * const pObj   )
{
    onAdd(pSField, pObj);
}

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onSyncAdd(
    MFieldBaseType * const pMField, 
    FieldContainer * const pObj   )
{
    onAdd(pMField, pObj);
}

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onSyncSub(
    SFieldBaseType * const pSField, 
    FieldContainer * const pObj   )
{
    if(pObj != NULL)
    {
        Thread::getCurrentChangeList()->addDelayedSubRef<
            RefCountPolicyT>(pObj);
    }

//    onSub(pSField, pObj);
}

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onSyncSub(
    MFieldBaseType * const pMField, 
    FieldContainer * const pObj   )
{
    if(pObj != NULL)
    {
        Thread::getCurrentChangeList()->addDelayedSubRef<
            RefCountPolicyT>(pObj);
    }

//    onSub(pMField, pObj);
}

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onSyncReplace(
    SFieldBaseType * const pSField,
    FieldContainer * const pOldObj,
    FieldContainer * const pNewObj)
{
    onSyncAdd(pSField, pNewObj);
    onSyncSub(pSField, pOldObj);
}

template<typename RefCountPolicyT> inline 
void PointerAccessHandler<RefCountPolicyT>::onSyncReplace(
    MFieldBaseType * const pMField,
    FieldContainer * const pOldObj,
    FieldContainer * const pNewObj)
{
    onSyncAdd(pMField, pNewObj);
    onSyncSub(pMField, pOldObj);
}

OSG_END_NAMESPACE
