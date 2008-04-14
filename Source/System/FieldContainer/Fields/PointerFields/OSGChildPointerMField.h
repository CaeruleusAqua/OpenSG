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

#ifndef _OSGCHILDPOINTERMFIELD_H_
#define _OSGCHILDPOINTERMFIELD_H_

#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGChildPointerMFieldBase.h"

#ifdef OSG_DOC_FILES_IN_MODULE
/*! \file OSGChildPointerMField.h
    \ingroup GrpSystemFieldContainer
 */
#endif

OSG_BEGIN_NAMESPACE

// forward declarations
template <class ObjectTypeT, typename RefCountPolicy, Int32 NamespaceI>
class ChildPointerMField;

template <class ObjectTypeT, typename RefCountPolicy, Int32 NamespaceI>
class ChildMFieldConstIterator;

#ifndef OSG_CLEAN_FCFIELDS
template <class ObjectTypeT, typename RefCountPolicy, Int32 NamespaceI>
class ChildMFieldReferenceProxy;
#endif

/*---------------------------------------------------------------------------*/
/* ChildMFieldIterator<ObjectTypeT>                                          */
/*---------------------------------------------------------------------------*/

template <class ObjectTypeT, typename RefCountPolicy, Int32 iNamespace>
class ChildMFieldIterator :
    protected ChildPointerMField<ObjectTypeT, 
                                 RefCountPolicy, 
                                 iNamespace   >::PtrStoreItType
{
    template <class OT, typename RC, Int32 NI>
    friend class ChildPointerMField;

    template <class OT, typename RC, Int32 NI>
    friend class ChildMFieldConstIterator;

    /*==========================  PUBLIC  =================================*/

  public:

    /*---------------------------------------------------------------------*/
    /*! \name Public Types                                                 */
    /*! \{                                                                 */
    
    typedef          ChildMFieldIterator                Self;
           
    typedef          ChildPointerMField<ObjectTypeT, 
                                        RefCountPolicy, 
                                        iNamespace    > MFieldType;

    typedef typename MFieldType::PtrStoreItType         Inherited;

    typedef typename MFieldType::AccessHandler          AccessHandler;

    typedef          ObjectTypeT * const                const_value;
    
#ifndef OSG_CLEAN_FCFIELDS
    typedef          ChildMFieldReferenceProxy<
                         ObjectTypeT, 
                         RefCountPolicy, 
                         iNamespace                   > reference; 
#endif

    // store types
    typedef typename MFieldType::PtrStoreType           PtrStoreType;
    typedef typename MFieldType::PtrStoreItType         PtrStoreItType;

    typedef typename MFieldType::const_iterator         const_iterator;
    
    // std library typedefs
    typedef typename Inherited::iterator_category       iterator_category;
    typedef typename Inherited::difference_type         difference_type;

    typedef          ObjectTypeT                        ObjectType;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Constructors                                                 */
    /*! \{                                                                 */
    
    ChildMFieldIterator(      void                     );
    ChildMFieldIterator(const Self           &source   );
       
    ChildMFieldIterator(const PtrStoreItType &storeIter,
                              MFieldType     *pField   );
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Destructor                                                   */
    /*! \{                                                                 */
                               
    ~ChildMFieldIterator(void);
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Operators                                                    */
    /*! \{                                                                 */
    
#ifndef OSG_CLEAN_FCFIELDS
    reference   operator * (      void                  ) const;
    reference   operator [](const difference_type offset) const;
#else
    const_value operator * (      void                  ) const;
    const_value operator [](const difference_type offset) const;
#endif    

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Operators                                                    */
    /*! \{                                                                 */

    Self &operator ++(      void                  );
    Self  operator ++(      int                   );
    
    Self &operator --(      void                  );
    Self  operator --(      int                   );
    
    Self &operator +=(const difference_type offset);
    Self  operator + (const difference_type offset) const;
    
    Self &operator -=(const difference_type offset);
    Self  operator - (const difference_type offset) const;
        
    bool operator == (const Self            &rhs  ) const;
    bool operator != (const Self            &rhs  ) const;
    
    bool operator == (const const_iterator  &rhs  ) const;
    bool operator != (const const_iterator  &rhs  ) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    /*---------------------------------------------------------------------*/
    /*! \name Base                                                         */
    /*! \{                                                                 */
    
    const PtrStoreItType &base(void) const;
    
    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    MFieldType  *_pField;
};

#if 0
template <class ObjectTypeT, Int32 iNamespace>
typename ChildMFieldIterator<ObjectTypeT, iNamespace>::difference_type
    operator-(ChildMFieldIterator<ObjectTypeT, iNamespace> const &lhs,
              ChildMFieldIterator<ObjectTypeT, iNamespace> const &rhs );

template <class ObjectTypeT, Int32 iNamespace>
ChildMFieldIterator<ObjectTypeT, iNamespace>
    operator+(
        typename ChildMFieldIterator<ObjectTypeT, iNamespace>::differece_type const offset,
        ChildMFieldIterator<ObjectTypeT, iNamespace>                          const &rhs   );
#endif

/*---------------------------------------------------------------------------*/
/* ChildMFieldConstIterator<ObjectTypeT>                                     */
/*---------------------------------------------------------------------------*/

template <class ObjectTypeT, typename RefCountPolicy, Int32 iNamespace>
class ChildMFieldConstIterator :
    protected ChildPointerMField<ObjectTypeT, 
                                 RefCountPolicy, 
                                 iNamespace    >::PtrStoreConstItType
{
    template <class OT, typename RC, Int32 NI>
    friend class ChildPointerMField;

    template <class OT, typename RC, Int32 NI>
    friend class ChildMFieldIterator;

    /*==========================  PUBLIC  =================================*/

  public:

    /*---------------------------------------------------------------------*/
    /*! \name Public Types                                                 */
    /*! \{                                                                 */
    
    typedef          ChildMFieldConstIterator           Self;

    typedef          ChildPointerMField<ObjectTypeT, 
                                        RefCountPolicy, 
                                        iNamespace    > MFieldType;

    typedef typename MFieldType::PtrStoreConstItType    Inherited;
           
    typedef typename MFieldType::AccessHandler          AccessHandler;

    typedef          ObjectTypeT * const                const_value;
    
    // store types
    typedef typename MFieldType::PtrStoreType           PtrStoreType;
    typedef typename MFieldType::PtrStoreConstItType    PtrStoreConstItType;

    typedef typename MFieldType::iterator               iterator;
    
    // std library types
    typedef typename Inherited::iterator_category       iterator_category;
    typedef typename Inherited::difference_type         difference_type;

    typedef          ObjectTypeT                        ObjectType;
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Constructors                                                 */
    /*! \{                                                                 */
    
    ChildMFieldConstIterator(      void                          );
    ChildMFieldConstIterator(const Self                &source   );
    ChildMFieldConstIterator(const iterator            &fieldIter);
    ChildMFieldConstIterator(const PtrStoreConstItType &storeIter);
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Destructor                                                   */
    /*! \{                                                                 */
                               
    ~ChildMFieldConstIterator(void);
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Operators                                                    */
    /*! \{                                                                 */
    
    const_value operator * (void                  ) const;   
    const_value operator [](difference_type offset) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Operators                                                    */
    /*! \{                                                                 */
    
    Self &operator ++(void);
    Self  operator ++(int );
    
    Self &operator --(void);
    Self  operator --(int );
    
    Self &operator +=(const difference_type offset);
    Self  operator + (const difference_type offset) const;
    
    Self &operator -=(const difference_type offset);
    Self  operator - (const difference_type offset) const;

    bool operator == (const Self            &rhs  ) const;
    bool operator != (const Self            &rhs  ) const;

    bool operator == (const iterator        &rhs  ) const;
    bool operator != (const iterator        &rhs  ) const;
       
    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    /*---------------------------------------------------------------------*/
    /*! \name Base                                                         */
    /*! \{                                                                 */
    
    PtrStoreConstItType const &base(void) const;
    
    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:
};

#if 0
template <class ObjectTypeT, Int32 iNamespace>
typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::difference_type
    operator-(ChildMFieldConstIterator<ObjectTypeT, iNamespace> const &lhs,
              ChildMFieldConstIterator<ObjectTypeT, iNamespace> const &rhs );
              
template <class ObjectTypeT, Int32 iNamespace>
typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::difference_type
    operator-(ChildMFieldIterator     <ObjectTypeT, iNamespace> const &lhs,
              ChildMFieldConstIterator<ObjectTypeT, iNamespace> const &rhs );

template <class ObjectTypeT, Int32 iNamespace>
typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::difference_type
    operator-(ChildMFieldConstIterator<ObjectTypeT, iNamespace> const &lhs,
              ChildMFieldIterator     <ObjectTypeT, iNamespace> const &rhs );
              
template <class ObjectTypeT, Int32 iNamespace>
ChildMFieldConstIterator<ObjectTypeT, iNamespace>
    operator+(
        typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::difference_type const  offset,
        ChildMFieldConstIterator<ObjectTypeT, iNamespace>                           const &rhs    );
#endif

/*-------------------------------------------------------------------------*/
/* ChildMFieldReferenceProxy<ObjectTypeT>                                  */
/*-------------------------------------------------------------------------*/

template <class ObjectTypeT, typename RefCountPolicy, Int32 iNamespace>
class ChildMFieldReferenceProxy
{
    /*==========================  PUBLIC  =================================*/

  public:

    /*---------------------------------------------------------------------*/
    /*! \name Public Types                                                 */
    /*! \{                                                                 */
    
    typedef          ObjectTypeT                         ObjectType;
    
    typedef          ChildMFieldReferenceProxy           Self;
            
    typedef          ChildPointerMField<ObjectTypeT, 
                                        RefCountPolicy, 
                                        iNamespace    >  MFieldType;
    typedef typename MFieldType::AccessHandler           AccessHandler;
    
    // store types
    typedef typename MFieldType::StoredType              StoredType;
    typedef typename MFieldType::PtrStoreType            PtrStoreType;    
    typedef typename MFieldType::PtrStoreItType          PtrStoreItType;
    typedef typename MFieldType::PtrStoreConstItType     PtrStoreConstItType;
    
    // std library types
    typedef          ObjectTypeT * const                 const_value;
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Constructors                                                 */
    /*! \{                                                                 */
    
    ChildMFieldReferenceProxy(const PtrStoreItType &storeIter,
                                    MFieldType     *pField   );
    ChildMFieldReferenceProxy(const Self           &source   );
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Destructor                                                   */
    /*! \{                                                                 */
    
    ~ChildMFieldReferenceProxy(void);
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Operators                                                    */
    /*! \{                                                                 */
    
                operator const_value(void                ) const;
    const_value operator->          (void                ) const;
    
    void        operator =          (const_value newValue);
    
    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    PtrStoreItType  _storeIter;
    MFieldType     *_pField;
};

/*---------------------------------------------------------------------------*/
/* ChildPointerMField<FieldConfigT>                                          */
/*---------------------------------------------------------------------------*/

template <class    ObjectTypeT,
          typename RefCountPolicy,
          Int32    NamespaceI  = 0>
class ChildPointerMField : 
    public ChildPointerMFieldBase<ChildAccessHandler<RefCountPolicy>,
                                  NamespaceI                        >
{

    /*==========================  PUBLIC  =================================*/

  public:

    /*---------------------------------------------------------------------*/
    /*! \name Public Types                                                 */
    /*! \{                                                                 */

    
    typedef ChildPointerMFieldBase<
                ChildAccessHandler  <RefCountPolicy>,
                NamespaceI                          > Inherited;

    typedef ChildPointerMField Self;
    
    typedef ObjectTypeT *                             value_type;
    typedef ObjectTypeT * const                       const_value;
    typedef value_type                                StoredType;

    typedef typename Inherited::size_type             size_type;
    typedef typename Inherited::difference_type       difference_type;

    typedef ChildMFieldIterator      <ObjectTypeT, 
                                      RefCountPolicy, 
                                      NamespaceI    > iterator;

    typedef ChildMFieldConstIterator <ObjectTypeT, 
                                      RefCountPolicy, 
                                      NamespaceI    > const_iterator;

    typedef std::reverse_iterator    <iterator      > reverse_iterator;
    typedef std::reverse_iterator    <const_iterator> const_reverse_iterator;

    typedef FieldTraits              <value_type,
                                      NamespaceI    > MFieldTraits;
    typedef FieldDescription<
                MFieldTraits,
                FieldType::MultiField,
                UnrecordedRefCountPolicy,
                FieldType::ChildPtrField            > Description;

#ifndef OSG_CLEAN_FCFIELDS
    typedef ChildMFieldReferenceProxy<ObjectTypeT,
                                      RefCountPolicy, 
                                      NamespaceI    > reference;
#endif

    typedef ObjectTypeT                               ObjectType;
                                      
    // handles
//    typedef          EditPointerMFieldHandle<Self>      EditHandle;
//    typedef typename EditPointerMFieldHandle<Self>::Ptr EditHandlePtr;
    
//    typedef          GetPointerMFieldHandle <Self>      GetHandle;
//    typedef typename GetPointerMFieldHandle <Self>::Ptr GetHandlePtr;
    
    // handles for dynamic fields -- XXX TODO
//    typedef          EditPointerMFieldHandle<Self>      DynamicEditHandle;
//    typedef typename EditPointerMFieldHandle<Self>::Ptr DynamicEditHandlePtr;
    
//    typedef          GetPointerMFieldHandle <Self>      DynamicGetHandle;
//    typedef typename GetPointerMFieldHandle <Self>::Ptr DynamicGetHandlePtr;
                             
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Constants                                                    */
    /*! \{                                                                 */
        
    static FieldType::Cardinality const fieldCard  = FieldType::MultiField;
    static FieldType::Class       const Class      = FieldType::ChildPtrField;
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Class Type                                                   */
    /*! \{                                                                 */

    static FieldType const &getClassType(void);
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Constructors                                                 */
    /*! \{                                                                 */

    ChildPointerMField(FieldContainerPtr pParent,
                       UInt16            usParentFieldPos);
    

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Destructor                                                   */
    /*! \{                                                                 */

    ~ChildPointerMField(void); 
       
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name String/Stream IO (Input)                                     */
    /*! \{                                                                 */
   
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Set                                     */
    /*! \{                                                                 */

#ifdef OSG_FIELD_TOCHECK
    void setValues(const StorageType       &value);
    void setValues(const StorageTypeParent &value);
    void setValues(const Self              &obj  );
#endif       

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Interface                           */
    /*! \{                                                                 */

    void copyFromBin(BinaryDataHandler &pMem);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   STL Interface                              */
    /*! \{                                                                 */

    iterator  begin_nc(void             );
    iterator  end_nc  (void             );

#ifndef OSG_CLEAN_FCFIELDS
    reference front_nc(void             );
    reference back_nc (void             );

    iterator  find_nc (const_value value);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Std Library Interface                                        */
    /*! \{                                                                 */
    
#ifndef OSG_CLEAN_FCFIELDS
    iterator               begin    (void                           );
    iterator               end      (void                           );

    reverse_iterator       rbegin   (void                           );
    reverse_iterator       rend     (void                           );
#endif

    const_iterator         begin    (void                           ) const;
    const_iterator         end      (void                           ) const;
    
    const_reverse_iterator rbegin   (void                           ) const;
    const_reverse_iterator rend     (void                           ) const;
    
#ifndef OSG_CLEAN_FCFIELDS
    reference              front    (void                           );
    reference              back     (void                           );
#endif

    const_value            front    (void                           ) const;
    const_value            back     (void                           ) const;
   
    iterator               insert   (iterator       pos,
                                     const_value    value           );

    template <class InputIteratorT>
    void                   insert   (iterator       pos, 
                                     InputIteratorT first,
                                     InputIteratorT last            );
 
    iterator               erase    (iterator       pos             );

    iterator               erase    (iterator       first,
                                     iterator       last            );
    
#ifndef OSG_CLEAN_FCFIELDS
    iterator               find     (const_value    value           );
#endif

    const_iterator         find     (const_value    value           ) const;

    void                   push_back(const_value    value           );
   
    void                   resize   (size_t         newSize,
                                     const_value    value   = NullFC);

    void                   clear    (void                           );
                               
#ifdef OSG_1_COMPAT
    void                   addValue (const_value    value           );
#endif

    void                   assign   (size_type      newSize,
                                     const_value    value   = NullFC);

    template <class InputIteratorT>
    void                   assign   (InputIteratorT first,
                                     InputIteratorT last            );

    void                   replace  (UInt32         uiIdx, 
                                     const_value    value           );

    void                   replace  (iterator       pos, 
                                     const_value    value           );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Index Operator                                               */
    /*! \{                                                                 */

#ifndef OSG_CLEAN_FCFIELDS
    reference   operator [](const UInt32 index);
#endif
    const_value operator [](const UInt32 index) const;
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Assignment                                                   */
    /*! \{                                                                 */

#ifdef OSG_FIELD_TOCHECK
    Self & operator =(const Self &source);
#endif
   
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      MT Sync                                 */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    void syncWith(Self               &source, 
                  ConstFieldMaskArg   syncMode,
                  UInt32              uiSyncInfo,
                  AspectOffsetStore  &oOffsets  );
#endif

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    /*---------------------------------------------------------------------*/
    /*! \name Members                                                      */
    /*! \{                                                                 */
    
    static FieldType _fieldType;
    
    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    ChildPointerMField(const Self &other);
};

OSG_END_NAMESPACE

#include "OSGChildPointerMField.inl"

#endif // _OSGCHILDPOINTERMFIELD_H_
