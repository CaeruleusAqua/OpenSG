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

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 488 )
#endif

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > 
template<class To> inline
To &FieldContainerPtrMField<ValueT, RefCountPolicy, iNamespace>::dcast(void)
{
    return reinterpret_cast<To &>(Self::_values); 
}

template<class    ValueT, 
         typename RefCountPolicy, 
          Int32   iNamespace    > 
template<class To> inline
const To &FieldContainerPtrMField<ValueT, 
                                  RefCountPolicy, 
                                  iNamespace    >::dcast(void) const 
{
    return reinterpret_cast<const To &>(Self::_values); 
}

#ifdef OSG_LINUX_ICC
#pragma warning( default : 488 )
#endif

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
FieldContainerPtrMField<ValueT, 
                        RefCountPolicy, 
                        iNamespace    >::FieldContainerPtrMField(void) :
    Inherited()
{
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
FieldContainerPtrMField<ValueT, 
                        RefCountPolicy, 
                        iNamespace    >::FieldContainerPtrMField(
    const Self &obj) :

    Inherited()
{
    if(obj._values.size() > 0)
    {
        _values.resize(obj._values.size(), NULL);

        typename StorageType::const_iterator sIt  = obj._values.begin();
        typename StorageType::const_iterator sEnd = obj._values.end  ();

        typename StorageType::iterator fIt  = _values.begin();
        
        while(sIt != sEnd)
        {
            RefCountPolicy::setRefd((*fIt), *sIt);

            ++sIt;
            ++fIt;
        }
    }
}


template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
FieldContainerPtrMField<ValueT, 
                        RefCountPolicy, 
                        iNamespace    >::FieldContainerPtrMField(
    const UInt32 size) : 

    Inherited(size)
{
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
FieldContainerPtrMField<ValueT, 
                        RefCountPolicy, 
                        iNamespace    >::~FieldContainerPtrMField(void)
{
    this->clear();
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
void FieldContainerPtrMField<ValueT, 
                             RefCountPolicy, 
                             iNamespace    >::copyFromBin(
                                 BinaryDataHandler &pMem)
{
    UInt32 n;

     pMem  .getValue(n);

     this->clear();

#ifdef __hpux
    FieldTypeT tmpVal = NULL;

    _values.resize(n, tmpVal);
#else
    _values.resize(n, NULL);
#endif

    if(n != 0)
    {
        MFieldTraits::copyFromBin(   pMem, 
                                  &(_values[0]),
                                     n);

        typename Inherited::const_iterator sIt  = _values.begin();
        typename Inherited::const_iterator sEnd = _values.end  ();

        while(sIt != sEnd)
        {
            RefCountPolicy::addRef(*sIt);

            ++sIt;
        }
    }
}


//reference getValue(void);
//const_reference getValue(void) const;

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
typename FieldContainerPtrMField<ValueT, RefCountPolicy, iNamespace>::iterator
    FieldContainerPtrMField<ValueT, RefCountPolicy, iNamespace>::begin_nc(void)
{
    return (this->template dcast<typename Self::StorageType>()).begin();
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
typename FieldContainerPtrMField<ValueT, RefCountPolicy, iNamespace>::iterator
    FieldContainerPtrMField<ValueT, RefCountPolicy, iNamespace>::end_nc(void)
{
    return (this->template dcast<typename Self::StorageType>()).end();
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
typename FieldContainerPtrMField<ValueT, 
                                 RefCountPolicy, 
                                 iNamespace    >::const_iterator
    FieldContainerPtrMField<ValueT, 
                            RefCountPolicy, 
                            iNamespace    >::begin(void) const
{
    return (this->template dcast<typename Self::StorageType>()).begin();
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
typename FieldContainerPtrMField<ValueT, 
                                 RefCountPolicy, 
                                 iNamespace    >::const_iterator
    FieldContainerPtrMField<ValueT, 
                            RefCountPolicy, 
                            iNamespace    >::end(void) const
{
    return (this->template dcast<typename Self::StorageType>()).end();
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
typename FieldContainerPtrMField<ValueT, RefCountPolicy, iNamespace>::iterator 
    FieldContainerPtrMField<ValueT, 
                            RefCountPolicy, 
                            iNamespace    >::insert(iterator     pos, 
                                                    ArgumentType value)
{
    RefCountPolicy::addRef(value);

    return (this->template dcast<typename Self::StorageType>()).insert(pos, 
                                                                       value);
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
void FieldContainerPtrMField<ValueT, RefCountPolicy, iNamespace>::clear(void)
{
    typename Inherited::iterator       fieldIt  = _values.begin();
    typename Inherited::const_iterator fieldEnd = _values.end  ();

    while(fieldIt != fieldEnd)
    {
        RefCountPolicy::subRef(*fieldIt);

        ++fieldIt;
    }

    _values.clear();
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
typename FieldContainerPtrMField<ValueT, RefCountPolicy, iNamespace>::iterator 
    FieldContainerPtrMField<ValueT, 
                            RefCountPolicy, 
                            iNamespace    >::erase(iterator pos)
{
    typename StorageType::iterator tmpIt(pos);
    
    RefCountPolicy::subRef(*tmpIt);

    return (this->template dcast<typename Self::StorageType>()).erase(pos);
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
typename FieldContainerPtrMField<ValueT, RefCountPolicy, iNamespace>::iterator
     FieldContainerPtrMField<ValueT, 
                             RefCountPolicy, 
                             iNamespace    >::erase(iterator     first,
                                                    iterator     last )
{
    typename StorageType::iterator tmpFirst(first);
    typename StorageType::iterator tmpLast (last );

    for(; first != last; ++first)
    {
        RefCountPolicy::subRef(first.deref());
    }
    
    return (this->template dcast<typename Self::StorageType>()).erase(tmpFirst,
                                                                      tmpLast);
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
void FieldContainerPtrMField<ValueT, 
                             RefCountPolicy, 
                             iNamespace    >::push_back(ArgumentType value)
{
    RefCountPolicy::addRef(value);

    _values.push_back(value);
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
void FieldContainerPtrMField<ValueT, 
                             RefCountPolicy, 
                             iNamespace    >::resize(size_t     newsize, 
                                                     StoredType t)
{
    size_t oldSize = _values.size();

    if(newsize < oldSize)
    {
        this->erase(this->begin_nc() + newsize, this->end_nc());
    }
    else
    {
        _values.resize(newsize, t);
        
        typename Inherited::iterator       vI = _values.begin() + oldSize;
        typename Inherited::const_iterator vE = _values.end  ();
        
        for(; vI != vE; ++vI)
        {
            RefCountPolicy::addRef(*vI);
        }
    }
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
void FieldContainerPtrMField<ValueT, 
                             RefCountPolicy, 
                             iNamespace    >::replace(UInt32       uiIdx, 
                                                      ArgumentType value)
{
    RefCountPolicy::setRefd(
        (this->template dcast<typename Self::StorageType>())[uiIdx],
        value);
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
void FieldContainerPtrMField<ValueT, 
                             RefCountPolicy, 
                             iNamespace    >::replace(iterator     pos, 
                                                      ArgumentType value)
{
    typename StorageType::iterator tmpIt(pos);

    RefCountPolicy::setRefd(*tmpIt, value);
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
typename FieldContainerPtrMField<ValueT, 
                                 RefCountPolicy, 
                                 iNamespace    >::const_reference 
    FieldContainerPtrMField<ValueT, 
                            RefCountPolicy, 
                            iNamespace    >::operator [](UInt32 index) const
{
    ValueT returnValue = 
        (this->template dcast<typename Self::StorageType>())[index];

    return RefCountPolicy::validate(returnValue);
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
typename FieldContainerPtrMField<ValueT, 
                                 RefCountPolicy, 
                                 iNamespace    >::reference 
    FieldContainerPtrMField<ValueT, 
                            RefCountPolicy, 
                            iNamespace    >::operator [](UInt32 index) 
{
    return typename Self::reference(this->begin_nc() + index);
}

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace    > inline
void FieldContainerPtrMField<ValueT, RefCountPolicy, iNamespace>::syncWith(
    Self               &source, 
    ConstFieldMaskArg   syncMode,
    UInt32              uiSyncInfo,
    AspectOffsetStore  &oOffsets    )
{
    if(source.size() != 0)
    {
        this->resize(source.size(), NullFC);

        Inherited::iterator sIt  = source._values.begin();
        Inherited::iterator sEnd = source._values.end  ();

        Inherited::iterator fIt  = _values.begin();
        
        while(sIt != sEnd)
        {
            RefCountPolicy::setRefd((*fIt),
                                    convertToCurrentAspect(*sIt));

            ++sIt;
            ++fIt;
        }
    }
    else
    {
        this->clear();
    }
}

OSG_END_NAMESPACE

