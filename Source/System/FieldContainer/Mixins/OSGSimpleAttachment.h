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

#ifndef _OSGSIMPLEATTACHMENT_H_
#define _OSGSIMPLEATTACHMENT_H_

#ifdef __sgi
#pragma once
#endif

#include "OSGFieldContainerAttachment.h"
#include "OSGContainerPtrFuncs.h"

#include "boost/bind.hpp"

OSG_BEGIN_NAMESPACE

//! Template to build simple attachment classes which store only one field.
//! \ingroup GrpSystemFieldContainer

template <class AttachmentDescT>
class SimpleAttachment : public FieldContainerAttachment
{

    /*==========================  PUBLIC  =================================*/

  public:

    typedef FieldContainerAttachment Inherited;
    typedef FieldContainerAttachment ParentContainer;

    typedef          AttachmentDescT                   SimpleDesc;
    typedef typename SimpleDesc::FieldTypeT            StoredFieldType;
    typedef typename StoredFieldType::ArgumentType     ArgumentType;

    typedef          SimpleAttachment<AttachmentDescT> Self;

    typedef typename StoredFieldType::GetHandle        GetHandle;
    typedef typename StoredFieldType::GetHandlePtr     GetHandlePtr;
    
    typedef typename StoredFieldType::EditHandle       EditHandle;
    typedef typename StoredFieldType::EditHandlePtr    EditHandlePtr;
    
     /*=========================  PROTECTED  ===============================*/

  protected:

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    struct SFieldValFunctions
    {
        static StoredFieldType   *editFieldPtr   (StoredFieldType  *pField,
                                                  SimpleAttachment *pThis );


        static EditFieldHandlePtr editHandleField(StoredFieldType  *pField,
                                                  SimpleAttachment *pThis);
    };

    struct SFieldPtrFunctions
    {
        static StoredFieldType   *editFieldPtr   (StoredFieldType  *pField,
                                                  SimpleAttachment *pThis );


        static EditFieldHandlePtr editHandleField(StoredFieldType  *pField,
                                                  SimpleAttachment *pThis);
    };

    struct MFieldValFunctions
    {
        static StoredFieldType   *editFieldPtr   (StoredFieldType  *pField,
                                                  SimpleAttachment *pThis );


        static EditFieldHandlePtr editHandleField(StoredFieldType  *pField,
                                                  SimpleAttachment *pThis);
    };

    struct MFieldPtrFunctions
    {
        static StoredFieldType   *editFieldPtr   (StoredFieldType  *pField,
                                                  SimpleAttachment *pThis );


        static EditFieldHandlePtr editHandleField(StoredFieldType  *pField,
                                                  SimpleAttachment *pThis);
    };


    typedef typename
        boost::mpl::if_<boost::mpl::bool_<
                             (StoredFieldType::isPointerField == true)>,
                         SFieldPtrFunctions,
                         SFieldValFunctions>::type SFieldFunctions;

    typedef typename
        boost::mpl::if_<boost::mpl::bool_<
                             (StoredFieldType::isPointerField == true)>,
                         MFieldPtrFunctions,
                         MFieldValFunctions>::type MFieldFunctions;

    typedef typename
        boost::mpl::if_<boost::mpl::bool_<(StoredFieldType::isSField == true)>,
                         SFieldFunctions,
                         MFieldFunctions>::type FieldFunctions;


    /*==========================  PUBLIC  =================================*/

  public:


   OSG_GEN_INTERNALPTR(Self);

    enum 
    { 
        SimpleFieldId     = Inherited::NextFieldId, 
        NextFieldId       = SimpleFieldId + 1
    };

    static const BitVector SimpleFieldMask = Inherited::NextFieldMask;
    static const BitVector NextFieldMask   = SimpleFieldMask << 1;


    /*---------------------------------------------------------------------*/
    /*! \name        General Fieldcontainer Declaration                    */
    /*! \{                                                                 */

    OSG_FIELD_CONTAINER_TMPL_DECL;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Get                                     */
    /*! \{                                                                 */

          StoredFieldType *editFieldPtr(void);
    const StoredFieldType *getFieldPtr (void) const;

    const StoredFieldType &getField    (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Access                              */
    /*! \{                                                                 */

    virtual UInt32 getBinSize (ConstFieldMaskArg  whichField);

    virtual void   copyToBin  (BinaryDataHandler &pMem, 
                               ConstFieldMaskArg  whichField);
    virtual void   copyFromBin(BinaryDataHandler &pMem, 
                               ConstFieldMaskArg  whichField);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                        Dump                                  */
    /*! \{                                                                 */

    virtual void dump(      UInt32    uiIndent = 0, 
                      const BitVector bvFlags  = 0) const;

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  protected:
    
    /*---------------------------------------------------------------------*/
    /*! \name                  Type information                            */
    /*! \{                                                                 */

    static TypeObject _type;

    static void   classDescInserter(TypeObject &oType);
    static Char8 *getClassname     (void             );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    StoredFieldType _field;
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    SimpleAttachment(void);
    SimpleAttachment(const SimpleAttachment &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~SimpleAttachment(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual ObjPtr createAspectCopy(void) const;
#endif
    

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Sync                                     */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual void execSyncV(      FieldContainer    &oFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);

            void execSync (      SimpleAttachment  *pFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);
#endif
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleField (void) const;
    EditFieldHandlePtr editHandleField(void);
    
    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    
    /*! \brief prohibit default functions (move to 'public' if needed) */
    SimpleAttachment &operator =(const SimpleAttachment &source);

    void setPointerValue(ArgumentType pVal);
    void addPointerValue(ArgumentType pVal);
};

OSG_END_NAMESPACE

#include "OSGSimpleAttachment.inl"

#endif /* _OSGSIMPLEATTACHMENT_H_ */
