/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *           Copyright (C) 2003 by the OpenSG Forum                          *
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

/*---------------------------------------------------------------------*/

inline
GetSFieldHandle<SFAttachmentPtrMap>::GetSFieldHandle(
    const GetSFieldHandle &source) :

    Inherited(source)
{
}

inline
GetSFieldHandle<SFAttachmentPtrMap>::GetSFieldHandle(
    const SFAttachmentPtrMap   *pField, 
    const FieldDescriptionBase *pDescription) :

    Inherited(pField, pDescription)
{
}

inline
const FieldType &
    GetSFieldHandle<SFAttachmentPtrMap>::getType(void) const
{
    return SFAttachmentPtrMap::getClassType();
}


inline
bool 
   GetSFieldHandle<SFAttachmentPtrMap>::isPointerField(void) const
{
    return true;
}

inline
void GetSFieldHandle<SFAttachmentPtrMap>::pushValueToStream(
    OutStream &str) const
{
    FWARNING(("illegal pushValueToStream called for %s\n", 
              this->getName().c_str()));
    OSG_ASSERT(false);
}

inline
void GetSFieldHandle<SFAttachmentPtrMap>::pushSizeToStream(
    OutStream &str) const
{
    FWARNING(("illegal pushSizeToStream called for %s\n", 
              this->getName().c_str()));
    OSG_ASSERT(false);
}

inline
bool GetSFieldHandle<SFAttachmentPtrMap>::equal(
    Inherited::Ptr rhs) const
{
    Ptr pOther = boost::dynamic_pointer_cast<GetSFieldHandle>(rhs);

    if(pOther == NULL)
    {
        return false;
    }

    SFAttachmentPtrMap const *pLhs = 
        static_cast<SFAttachmentPtrMap const *>(        _pField);

    SFAttachmentPtrMap const *pRhs = 
        static_cast<SFAttachmentPtrMap const *>(pOther->_pField);

    return (*pLhs) == (*pRhs);
}

inline
SFAttachmentPtrMap const *
    GetSFieldHandle<SFAttachmentPtrMap>::operator ->(void)
{
    return static_cast<SFAttachmentPtrMap const *>(_pField);
}

inline
SFAttachmentPtrMap const &
    GetSFieldHandle<SFAttachmentPtrMap>::operator * (void)
{
    return *(static_cast<SFAttachmentPtrMap const *>(_pField));
}

/*---------------------------------------------------------------------*/

inline
EditSFieldHandle<SFAttachmentPtrMap>::EditSFieldHandle(
    const EditSFieldHandle &source) :

     Inherited (source            ),
    _pContainer(source._pContainer),
    _fAddMethod(source._fAddMethod)
{
}

inline
EditSFieldHandle<SFAttachmentPtrMap>::EditSFieldHandle(      
          SFAttachmentPtrMap *pField, 
    const FieldDescriptionBase             *pDescription) :

     Inherited (pField, 
                pDescription),
    _pContainer(NULL        ),
    _fAddMethod(NULL        )
{
}

inline
const FieldType &
    EditSFieldHandle<SFAttachmentPtrMap>::getType(void) const
{
    return SFAttachmentPtrMap::getClassType();
}

inline
bool EditSFieldHandle<SFAttachmentPtrMap>::isPointerField(void) const
{
    return true;
}

inline
void EditSFieldHandle<SFAttachmentPtrMap>::add(
    const FieldContainerPtr rhs,
          UInt32            uiBindings)
{
    const AttachmentPtr pVal = 
        dynamic_cast<const AttachmentPtr>(rhs);

    if(rhs != NULL && pVal == NULL)
        return;

    // for whatever reason VS2003 does not like == NULL
    if(_fAddMethod)
    {
        _fAddMethod(pVal, uiBindings);
    }
}

inline
void EditSFieldHandle<SFAttachmentPtrMap>::pushValueToStream(
    OutStream &str) const
{
    FWARNING(("illegal pushValueToStream called for %s\n", 
              this->getName().c_str()));
    OSG_ASSERT(false);
}

inline
void EditSFieldHandle<SFAttachmentPtrMap>::pushSizeToStream(
    OutStream &str) const
{
    FWARNING(("illegal pushSizeToStream called for %s\n", 
              this->getName().c_str()));
    OSG_ASSERT(false);
}

inline
bool EditSFieldHandle<SFAttachmentPtrMap>::equal(
    Inherited::Ptr rhs) const
{
    Ptr pOther = boost::dynamic_pointer_cast<EditSFieldHandle>(rhs);

    if(pOther == NULL)
    {
        return false;
    }

    SFAttachmentPtrMap *pLhs = 
        static_cast<SFAttachmentPtrMap *>(        _pField);

    SFAttachmentPtrMap *pRhs = 
        static_cast<SFAttachmentPtrMap *>(pOther->_pField);

    return (*pLhs) == (*pRhs);
}

inline
void EditSFieldHandle<SFAttachmentPtrMap>::setAddMethod(
    AddMethod fMethod)
{
    _fAddMethod = fMethod;
}

inline
void EditSFieldHandle<SFAttachmentPtrMap>::pushValueFromCString(
    const Char8 *str)
{
    FWARNING(("illegal pushValueFromCString called for %s\n", 
              this->getName().c_str()));
    OSG_ASSERT(false);
}

inline
void EditSFieldHandle<SFAttachmentPtrMap>::copyValues(
    GetFieldHandlePtr source) const
{
    FWARNING(("illegal copyValues called for %s\n", 
              this->getName().c_str()));
    OSG_ASSERT(false);
}

inline
void EditSFieldHandle<SFAttachmentPtrMap>::shareValues(
    GetFieldHandlePtr source) const
{
    SFAttachmentPtrMap::GetHandlePtr pGetHandle = 
        boost::dynamic_pointer_cast<
            SFAttachmentPtrMap::GetHandle>(source);

    if(pGetHandle == NULL || pGetHandle->isValid() == false)
        return;

    const SFAttachmentPtrMap &pAttMap = **pGetHandle;

    AttachmentMap::const_iterator mapIt  = pAttMap.getValue().begin();
    AttachmentMap::const_iterator mapEnd = pAttMap.getValue().end();

    for(; mapIt != mapEnd; ++mapIt)
    {
        AttachmentPtr att       = mapIt->second;
        UInt16        uiBinding = UInt16(mapIt->first &
                                         0x0000FFFF    );

        if(_fAddMethod)
        {
            _fAddMethod(att, uiBinding);
        }
    }
}


inline
void EditSFieldHandle<SFAttachmentPtrMap>::cloneValues(
          GetFieldHandlePtr  pSrc,
    const TypePtrVector     &shareTypes,
    const TypePtrVector     &ignoreTypes,
    const TypeIdVector      &shareGroupIds,
    const TypeIdVector      &ignoreGroupIds) const
{
    SFAttachmentPtrMap::GetHandlePtr pGetHandle = 
        boost::dynamic_pointer_cast<
            SFAttachmentPtrMap::GetHandle>(pSrc);

    if(pGetHandle == NULL || pGetHandle->isValid() == false)
        return;

    const SFAttachmentPtrMap &pAttMap = **pGetHandle;

    AttachmentMap::const_iterator mapIt  = pAttMap.getValue().begin();
    AttachmentMap::const_iterator mapEnd = pAttMap.getValue().end();

    for(; mapIt != mapEnd; ++mapIt)
    {
        AttachmentUnrecPtr att       = mapIt->second;
        UInt16             uiBinding = UInt16(mapIt->first &
                                              0x0000FFFF    );

        if(att != NullFC)
        {
            const FieldContainerType &attType = att->getType();

            // test if att type should NOT be ignored
            if(!TypePredicates::typeInGroupIds (ignoreGroupIds.begin(),
                                                ignoreGroupIds.end(),
                                                attType                ) &&
               !TypePredicates::typeDerivedFrom(ignoreTypes.begin(),
                                                ignoreTypes.end(),
                                                attType                )   )
            {
                // test if att should cloned
                if(!TypePredicates::typeInGroupIds (shareGroupIds.begin(),
                                                    shareGroupIds.end(),
                                                    attType               ) &&
                   !TypePredicates::typeDerivedFrom(shareTypes.begin(),
                                                    shareTypes.end(),
                                                    attType               )   )
                {
                    att = dynamic_pointer_cast<Attachment>(
                        OSG::deepClone(att, shareTypes,    ignoreTypes,
                                            shareGroupIds, ignoreGroupIds));
                }
            }
        }

        if(_fAddMethod)
        {
            _fAddMethod(att, uiBinding);
        }
    }
}


OSG_END_NAMESPACE
