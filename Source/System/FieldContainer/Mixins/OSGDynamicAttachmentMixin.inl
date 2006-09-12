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

template <class AttachmentDescT> inline
typename DynFieldAttachment<AttachmentDescT>::TypeObject &
    DynFieldAttachment<AttachmentDescT>::getType(void)
{
    return _localType;
}

template <class AttachmentDescT> inline
const typename DynFieldAttachment<AttachmentDescT>::TypeObject &
    DynFieldAttachment<AttachmentDescT>::getType(void) const
{
    return _localType;
}

/*-------------------------------------------------------------------------*/
/*                            Field Access                                 */

template <class AttachmentDescT> inline
UInt32 DynFieldAttachment<AttachmentDescT>::addField(
    const FieldDescriptionBase &fieldDesc)
{
    UInt32                returnValue = 0;
    Field                *fieldP      = NULL;
    FieldDescriptionBase *descP       = NULL;

    returnValue = _localType.addDescription(fieldDesc);

    if(returnValue != 0)
    {
        descP = _localType.getFieldDesc(returnValue);

        if(descP != NULL)
        {
            descP->setFieldId  (returnValue);
            descP->setFieldMask(
                        TypeTraits<BitVector>::One << returnValue);

            fieldP = fieldDesc.createField();

            if(_dynFieldsV.size() <=
               returnValue - Inherited::NextFieldId)
            {
                _dynFieldsV.resize((returnValue -
                                    Inherited::NextFieldId) + 1);
            }

            _dynFieldsV[returnValue - Inherited::NextFieldId] = fieldP;
        }
    }

    return returnValue;
}

template <class AttachmentDescT> inline
void DynFieldAttachment<AttachmentDescT>::subField(UInt32 fieldId)
{
    if(_localType.subDescription(fieldId) == true)
    {
        std::vector<Field *>::iterator vIt = _dynFieldsV.begin();

        vIt += fieldId - Inherited::NextFieldId;

        if(vIt != _dynFieldsV.end())
        {
            delete (*vIt);

            (*vIt) = NULL;
        }
    }
}

template <class AttachmentDescT> inline
const Field *DynFieldAttachment<AttachmentDescT>::getDynamicField(
    UInt32 index) const
{
    return _dynFieldsV[index - Inherited::NextFieldId];
}

template <class AttachmentDescT> inline
Field *DynFieldAttachment<AttachmentDescT>::editDynamicField(
    UInt32 index) 
{
    return NULL;
//    Field *returnValue = _dynFieldsV[index - Inherited::NextFieldId];
}

template <class AttachmentDescT> inline
const Field *DynFieldAttachment<AttachmentDescT>::getDynamicFieldByName(
    const Char8  *szName) const
{
    
    const FieldDescriptionBase *descP = NULL;

    descP = _localType.getFieldDesc(szName);

    if(descP != NULL)
    {
        return descP->getField(*this);
    }
    else
    {
        return NULL;
    }
}

template <class AttachmentDescT> inline
Field *DynFieldAttachment<AttachmentDescT>::editDynamicFieldByName(
    const Char8  *szName) 
{
    return NULL;
}

template <class AttachmentDescT> inline
void DynFieldAttachment<AttachmentDescT>::dump(
          UInt32    uiIndent, 
    const BitVector bvFlags ) const
{
    indentLog(uiIndent, PLOG);
    PLOG << "DynFieldAttachment"
         << std::endl;

    indentLog(uiIndent, PLOG);
    PLOG << "{" << std::endl;

    uiIndent += 4;

    for(UInt32 i = 1; i <= getType().getNumFieldDescs(); i++)
    {
        indentLog(uiIndent, PLOG);
        PLOG <<      getType().getFieldDesc(i)->getCName ()
             << " ("
             << const_cast<Self *>(this)->getField(
                     getType().getFieldDesc(i)->getFieldId())
             << ")"
             << std::endl;
    }

    uiIndent -= 4;

    indentLog(uiIndent, PLOG);
    PLOG << "}" << std::endl;
}

OSG_FIELD_CONTAINER_TMPL_NO_TYPE_DEF  (DynFieldAttachment, AttachmentDescT)
OSG_RC_GET_STATIC_TYPE_INL_TMPL_DEF   (DynFieldAttachment, AttachmentDescT)
OSG_RC_GET_STATIC_TYPE_ID_INL_TMPL_DEF(DynFieldAttachment, AttachmentDescT)

/*-------------------------------------------------------------------------*/
/*                            Constructors                                 */

template <class AttachmentDescT> inline
DynFieldAttachment<AttachmentDescT>::DynFieldAttachment(void) :
     Inherited (           ),
    _localType (Self::_type),
    _dynFieldsV(           )
{
    _localType.initialize();
}

template <class AttachmentDescT> inline
DynFieldAttachment<AttachmentDescT>::DynFieldAttachment(
    const DynFieldAttachment &source) :

     Inherited ( source            ),
    _localType (Self::_type        ),
    _dynFieldsV( source._dynFieldsV) // Do a real copy soon ;-)
{
    _localType.initialize();
}

/*-------------------------------------------------------------------------*/
/*                             Destructor                                  */

template <class AttachmentDescT> inline
DynFieldAttachment<AttachmentDescT>::~DynFieldAttachment(void)
{
}
 
template <class AttachmentDescT> inline
void DynFieldAttachment<AttachmentDescT>::execSyncV(
          FieldContainer     &oFrom,
          ConstFieldMaskArg   whichField,
          ConstFieldMaskArg   syncMode  ,
    const UInt32              uiSyncInfo,
          UInt32              uiCopyOffset)
{
    OSG_ASSERT(false);
}

template <class AttachmentDescT> inline
void DynFieldAttachment<AttachmentDescT>::execBeginEditV(
    ConstFieldMaskArg whichField, 
    UInt32            uiAspect,
    UInt32            uiContainerSize)
{
    OSG_ASSERT(false);
}

OSG_END_NAMESPACE

#define OSGDYNAMICATTACHMENTMIXIN_INLINE_CVSID "@(#)$Id: $"

