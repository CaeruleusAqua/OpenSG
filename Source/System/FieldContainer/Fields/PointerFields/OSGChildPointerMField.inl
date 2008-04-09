

#ifdef OSG_DOC_FILES_IN_MODULE
/*! \file OSGChildPointerMFieldBase.inl
    \ingroup GrpSystemFieldContainer
 */
#endif

OSG_BEGIN_NAMESPACE

/*-------------------------------------------------------------------------*/
/* ChildMFieldIterator<ObjectTypeT>                                        */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/* Constructors                                                            */

template <class ObjectTypeT, Int32 iNamespace>
inline 
ChildMFieldIterator<ObjectTypeT, iNamespace>::ChildMFieldIterator(void)
    
    : Inherited(    ),
      _pField  (NULL)
{
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline 
    ChildMFieldIterator<ObjectTypeT, iNamespace>::ChildMFieldIterator(Self const &source)
    
    : Inherited(source        ),
      _pField  (source._pField)
{
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline 
    ChildMFieldIterator<ObjectTypeT, iNamespace>::ChildMFieldIterator(
        PtrStoreItType const &storeIter,  MFieldType *pField)
    
    : Inherited(storeIter),
      _pField  (pField   )
{
}

/*-------------------------------------------------------------------------*/
/* Destructor                                                              */

template <class ObjectTypeT, Int32 iNamespace>
inline 
    ChildMFieldIterator<ObjectTypeT, iNamespace>::~ChildMFieldIterator(void)
{
}

/*-------------------------------------------------------------------------*/
/* Operators                                                               */

template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::reference
    ChildMFieldIterator<ObjectTypeT, iNamespace>::operator* (void) const
{
    return reference(*this, _pField);
}

/*! 
    \warning Do NOT attempt to write to this field through the pointer
    returned by this function, it will break the reference counting.
 */
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::pointer
    ChildMFieldIterator<ObjectTypeT, iNamespace>::operator->(void) const
{
    return reinterpret_cast<pointer>(this->Inherited::operator->());
}

template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::reference
    ChildMFieldIterator<ObjectTypeT, iNamespace>::operator[](
        difference_type const offset) const
{
    return reference(*this + offset, _pField);
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::Self &
    ChildMFieldIterator<ObjectTypeT, iNamespace>::operator++(void)
{
    this->Inherited::operator++();
    
    return *this;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::Self
    ChildMFieldIterator<ObjectTypeT, iNamespace>::operator++(int)
{
    Self retVal = *this;
    
    this->Inherited::operator++();
    
    return retVal;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::Self &
    ChildMFieldIterator<ObjectTypeT, iNamespace>::operator--(void)
{
    this->Inherited::operator--();
    
    return *this;
}

template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::Self
    ChildMFieldIterator<ObjectTypeT, iNamespace>::operator--(int)
{
    Self retVal = *this;
    
    this->Inherited::operator--();
    
    return retVal;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::Self &
    ChildMFieldIterator<ObjectTypeT, iNamespace>::operator+=(difference_type const offset)
{
    this->Inherited::operator+=(offset);
    
    return *this;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::Self
    ChildMFieldIterator<ObjectTypeT, iNamespace>::operator+ (
        difference_type const offset) const
{
    Self retVal = *this;
    
    return retVal += offset;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::Self &
    ChildMFieldIterator<ObjectTypeT, iNamespace>::operator-=(difference_type const offset)
{
    this->Inherited::operator-=(offset);
    
    return *this;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::Self
    ChildMFieldIterator<ObjectTypeT, iNamespace>::operator- (
        difference_type const offset) const
{
    Self retVal = *this;
    
    return retVal -= offset;
}

/*-------------------------------------------------------------------------*/
/* Base                                                                    */

template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldIterator<ObjectTypeT, iNamespace>::PtrStoreItType const &
    ChildMFieldIterator<ObjectTypeT, iNamespace>::base(void) const
{
    return *this;
}

/*-------------------------------------------------------------------------*/
/* Free Functions                                                          */

template <class ObjectTypeT, Int32 iNamespace>
typename ChildMFieldIterator<ObjectTypeT, iNamespace>::difference_type
    operator-(ChildMFieldIterator<ObjectTypeT, iNamespace> const &lhs,
              ChildMFieldIterator<ObjectTypeT, iNamespace> const &rhs )
{
    return std::distance<
        typename ChildMFieldIterator<ObjectTypeT, iNamespace>::StoreItType
                         >(lhs, rhs);
}

template <class ObjectTypeT, Int32 iNamespace>
ChildMFieldIterator<ObjectTypeT, iNamespace>
    operator+(
        typename ChildMFieldIterator<ObjectTypeT, iNamespace>::differece_type const offset,
        ChildMFieldIterator<ObjectTypeT, iNamespace>                          const &rhs   )
{
    return ChildMFieldIterator<ObjectTypeT, iNamespace>(rhs) += offset;
}

/*-------------------------------------------------------------------------*/
/* ChildMFieldConstIterator<ObjectTypeT>                            */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/* Constructors                                                            */

template <class ObjectTypeT, Int32 iNamespace>
inline 
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::ChildMFieldConstIterator(void)
    
    : Inherited()
{
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline 
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::ChildMFieldConstIterator(
        Self const &source)
    
    : Inherited(source)
{
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::ChildMFieldConstIterator(
        ChildMFieldIterator<ObjectTypeT, iNamespace> const &fieldIter)
        
    : Inherited(fieldIter.base())
{
}

template <class ObjectTypeT, Int32 iNamespace>
inline 
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::ChildMFieldConstIterator(
        PtrStoreConstItType const &storeIter)
    
    : Inherited(storeIter)
{
}

/*-------------------------------------------------------------------------*/
/* Destructor                                                              */

template <class ObjectTypeT, Int32 iNamespace>
inline 
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::~ChildMFieldConstIterator(void)
{
}

/*-------------------------------------------------------------------------*/
/* Operators                                                               */

template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::reference
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::operator* (void) const
{
    return reinterpret_cast<reference>(this->Inherited::operator*());
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::pointer
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::operator->(void) const
{
    return reinterpret_cast<pointer>(this->Inherited::operator->());
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::reference
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::operator[](
        difference_type const offset) const
{
    return *(*this + offset);
}

template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::Self &
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::operator++(void)
{
    this->Inherited::operator++();
    
    return *this;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::Self
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::operator++(int)
{
    Self retVal = *this;
    
    this->Inherited::operator++();
    
    return retVal;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::Self &
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::operator--(void)
{
    this->Inherited::operator--();
    
    return *this;
}

template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::Self
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::operator--(int)
{
    Self retVal = *this;
    
    this->Inherited::oprator--();
    
    return retVal;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::Self &
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::operator+=(
        difference_type const offset)
{
    this->Inherited::operator+=(offset);
    
    return *this;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::Self
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::operator+ (
        difference_type const offset) const
{
    Self retVal = *this;
    
    return retVal += offset;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::Self &
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::operator-=(
        difference_type const offset)
{
    this->Inherited::operator-=(offset);
    
    return *this;
}
    
template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::Self
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::operator- (
        difference_type const offset) const
{
    Self retVal = *this;
    
    return retVal -= offset;
}

/*-------------------------------------------------------------------------*/
/* Base                                                                    */

template <class ObjectTypeT, Int32 iNamespace>
inline typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::PtrStoreConstItType const &
    ChildMFieldConstIterator<ObjectTypeT, iNamespace>::base(void) const
{
    return *this;
}

/*-------------------------------------------------------------------------*/
/* Free Functions                                                          */

template <class ObjectTypeT, Int32 iNamespace>
typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::difference_type
    operator-(ChildMFieldConstIterator<ObjectTypeT, iNamespace> const &lhs,
              ChildMFieldConstIterator<ObjectTypeT, iNamespace> const &rhs )
{
    return typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::
               PtrStoreConstItType(lhs) -
           typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::
               PtrStoreConstItType(rhs);
}
              
template <class ObjectTypeT, Int32 iNamespace>
typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::difference_type
    operator-(ChildMFieldIterator     <ObjectTypeT, iNamespace> const &lhs,
              ChildMFieldConstIterator<ObjectTypeT, iNamespace> const &rhs )
{
    return typename ChildMFieldIterator<ObjectTypeT, iNamespace>::
               PtrStoreItType(lhs) -
           typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::
               PtrStoreConstItType(rhs);
}

template <class ObjectTypeT, Int32 iNamespace>
typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::difference_type
    operator-(ChildMFieldConstIterator<ObjectTypeT, iNamespace> const &lhs,
              ChildMFieldIterator     <ObjectTypeT, iNamespace> const &rhs )
{
    return typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::
               PtrStoreConstItType(lhs) -
           typename ChildMFieldIterator<ObjectTypeT, iNamespace>::
               PtrStoreItType(rhs);
}             
              
template <class ObjectTypeT, Int32 iNamespace>
ChildMFieldConstIterator<ObjectTypeT, iNamespace>
    operator+(
        typename ChildMFieldConstIterator<ObjectTypeT, iNamespace>::difference_type const offset,
        ChildMFieldConstIterator<ObjectTypeT, iNamespace>                           const &rhs   )
{
    return ChildMFieldConstIterator<ObjectTypeT, iNamespace>(rhs) += offset;
}

/*-------------------------------------------------------------------------*/
/* ChildMFieldReferenceProxy<ObjectTypeT>                                  */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/* Constructors                                                            */

template <class ObjectTypeT>
inline
    ChildMFieldReferenceProxy<ObjectTypeT>::ChildMFieldReferenceProxy(
        PtrStoreItType const &storeIter, MFieldType *pField)

    : _storeIter(storeIter),
      _pField   (pField   )
{
}

template <class ObjectTypeT>
    ChildMFieldReferenceProxy<ObjectTypeT>::ChildMFieldReferenceProxy(
        Self const &source)
    
    : _storeIter(source._storeIter),
      _pField   (source._pField   )
{
}

/*-------------------------------------------------------------------------*/
/* Destructor                                                              */

template <class ObjectTypeT>
inline
    ChildMFieldReferenceProxy<ObjectTypeT>::~ChildMFieldReferenceProxy(void)
{
}

/*-------------------------------------------------------------------------*/
/* Operators                                                               */

template <class ObjectTypeT>
inline
    ChildMFieldReferenceProxy<ObjectTypeT>::operator value_type(void) const
{
    return AccessHandler::validate(*_storeIter);
}
            
template <class ObjectTypeT>
inline  typename ChildMFieldReferenceProxy<ObjectTypeT>::value_type
     ChildMFieldReferenceProxy<ObjectTypeT>::operator->(void) const
{
    return AccessHandler::validate(*_storeIter);
}
    
template <class ObjectTypeT>
inline void
     ChildMFieldReferenceProxy<ObjectTypeT>::operator=(value_type newValue)
{
    AccessHandler::onReplace(
        _pField, *_storeIter, newValue);
    
    *_storeIter = newValue;
}

/*-------------------------------------------------------------------------*/
/* ChildPointerMField<ObjectTypeT,                                         */
/*                    NamespaceI  >                                        */
/*-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------*/
/* Class Type                                                              */

template <class ObjectTypeT, Int32 NamespaceI>
inline FieldType const &
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::getClassType(void)
{
    return _fieldType;
}

/*-------------------------------------------------------------------------*/
/* Constructors                                                            */

template <class ObjectTypeT, Int32 NamespaceI>
inline
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::ChildPointerMField(void)
    : Inherited()
{
}

template <class ObjectTypeT, Int32 NamespaceI>
inline
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::ChildPointerMField(Self const &other)
    : Inherited(other)
{
}

template <class ObjectTypeT, Int32 NamespaceI>
inline
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::ChildPointerMField(UInt32 const size)
    : Inherited(size)
{
}

/*-------------------------------------------------------------------------*/
/* Destructor                                                              */

template <class ObjectTypeT, Int32 NamespaceI>
inline
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::~ChildPointerMField(void)
{
}

/*-------------------------------------------------------------------------*/
/* Std Library Interface                                                   */

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::iterator
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::begin(void)
{
    return iterator(this->editRawStore().begin(), this);
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::iterator
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::end(void)
{
    return iterator(this->editRawStore().end(), this);
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::reverse_iterator
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::rbegin(void)
{
    return reverse_iterator(this->end());
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::reverse_iterator
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::rend(void)
{
    return reverse_iterator(this->begin());
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::const_iterator
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::begin(void) const
{
    return const_iterator(this->getRawStore().begin());
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::const_iterator
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::end(void) const
{
    return const_iterator(this->getRawStore().end());
}
    
template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::const_reverse_iterator
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::rbegin(void) const
{
    return const_reverse_iterator(this->cend());
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::const_reverse_iterator
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::rend(void) const
{
    return const_reverse_iterator(this->cbegin());
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::reference
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::front(void)
{
    return reference(this->editRawStore().begin(), this);
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::const_reference
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::front(void) const
{
    return this->template getStore<ValueType>().front();
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::reference
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::back(void)
{
    return reference(this->editRawStore().end() - 1, this);
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::const_reference
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::back(void) const
{
    return this->template getStore<ValueType>().back();
}

template <class ObjectTypeT, Int32 NamespaceI>
inline void
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::assign(
        size_type newSize, ValueType value)
{
    this->ptrStoreClear();

    for(size_type i = 0; i < newSize; ++i)
        this->ptrStoreAppend(value);
}

template <class ObjectTypeT,   Int32 NamespaceI>
template <class InputIteratorT                 >
inline void
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::assign(
        InputIteratorT first, InputIteratorT last)
{
    this->ptrStoreAssign(first, last);
}
   
template <class ObjectTypeT, Int32 NamespaceI>
inline void
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::insert(
        iterator pos, ValueType value)
{
    this->ptrStoreInsert(pos.base(), value);
}

template <class ObjectTypeT,   Int32 NamespaceI>
template <class InputIteratorT                 >
inline void
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::insert(
        iterator pos, InputIteratorT first, InputIteratorT last)
{
    this->ptrStoreInsert(pos.base(), first, last);
}
 
template <class ObjectTypeT, Int32 NamespaceI>
inline void
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::erase(iterator pos)
{
    this->ptrStoreErase(pos.base());
}

template <class ObjectTypeT, Int32 NamespaceI>
inline void
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::erase(
        iterator first, iterator last)
{
    this->ptrStoreErase(first.base(), last.base());
}
    
template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::iterator
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::find(ValueType value)
{
    return iterator(this->ptrStoreFind(value),
                    this                                                            );
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::const_iterator
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::find(ValueType value) const
{
    return const_iterator(
        this->ptrStoreFind(value),
        this                     );
}

template <class ObjectTypeT, Int32 NamespaceI>
inline Int32
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::findIndex(ValueType value) const
{
    return this->ptrStoreFindIndex(value);
}

template <class ObjectTypeT, Int32 NamespaceI>
inline void
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::push_back(ValueType value)
{
    this->ptrStoreAppend(value);
}
   
template <class ObjectTypeT, Int32 NamespaceI>
inline void
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::resize(size_t newSize, ValueType value)
{
    this->ptrStoreResize(newSize, value);
}

template <class ObjectTypeT, Int32 NamespaceI>
inline void
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::clear(void)
{
    this->ptrStoreClear();
}
                               
#ifdef OSG_1_COMPAT
template <class ObjectTypeT, Int32 NamespaceI>
inline void
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::addValue(ValueType value)
{
    this->push_back(value);
}
#endif

/*-------------------------------------------------------------------------*/
/* Index Operator                                                          */

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::reference
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::operator [](UInt32 const index)
{
    return reference(this->editRawStore().begin() + index, this);
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::const_reference
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::operator [](UInt32 const index) const
{
    return this->template getStore<ValueType>()[index];
}

/*-------------------------------------------------------------------------*/
/* Assignment                                                              */

template <class ObjectTypeT, Int32 NamespaceI>
inline void
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::setValues(Self const &source)
{
    this->assign(source.begin(), source.end());
}

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::Self &
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::operator=(Self const &source)
{
    this->setValues(source);
    
    return *this;
}

/*-------------------------------------------------------------------------*/
/* Value Access                                                            */

template <class ObjectTypeT, Int32 NamespaceI>
inline typename ChildPointerMField<ObjectTypeT,
                                   NamespaceI  >::ValueStoreType const &
    ChildPointerMField<ObjectTypeT,
                       NamespaceI  >::getValues(void) const
{
    return this->template getStore<ValueType>();
}

OSG_END_NAMESPACE
