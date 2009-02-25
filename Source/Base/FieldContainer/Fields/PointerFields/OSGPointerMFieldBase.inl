/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *           Copyright (C) 2008 by the OpenSG Forum                          *
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

/*! \class PointerMFieldBase

    \brief Base class of all fields that store FieldContainerPtr.
    
    It provides the const parts of the std::vector interface, but the pointers
    returned/accepted by these functions are always pointers to the base
    class FieldContainer, not the derived type.
    To access those as well as for write access one of the derived classes
    has to be used.
 */


inline
UInt32 PointerMFieldBase::getBinSize(void) const
{
    return 
        sizeof(size_type) + // num elements
        (_ptrStore.size() ? 
         MFieldTraits::getBinSize(&(_ptrStore[0]), _ptrStore.size()) : 0);
}


inline
void PointerMFieldBase::copyToBin(BinaryDataHandler &pMem) const
{
    UInt32 n = _ptrStore.size();

    pMem.putValue(n);

    if(n != 0)
    {
        MFieldTraits::copyToBin(   pMem, 
                                &(_ptrStore[0]),
                                  _ptrStore.size());
    }
}

/*-------------------------------------------------------------------------*/
/* Std Library Const Interface                                             */

inline 
PointerMFieldBase::const_iterator PointerMFieldBase::begin(void) const
{
    return _ptrStore.begin();
}

inline 
PointerMFieldBase::const_iterator PointerMFieldBase::end(void) const
{
    return _ptrStore.end();
}
    
inline 
PointerMFieldBase::const_reverse_iterator PointerMFieldBase::rbegin(void) const
{
    return _ptrStore.rbegin();
}

inline 
PointerMFieldBase::const_reverse_iterator PointerMFieldBase::rend(void) const
{
    return _ptrStore.rend();
}

inline 
PointerMFieldBase::const_value PointerMFieldBase::front(void) const
{
    return _ptrStore.front();
}

inline 
PointerMFieldBase::const_value PointerMFieldBase::back(void) const
{
    return _ptrStore.back();
}

inline 
bool PointerMFieldBase::empty(void) const
{
    return _ptrStore.empty();
}

inline 
PointerMFieldBase::size_type PointerMFieldBase::size(void) const
{
    return _ptrStore.size();
}

inline 
PointerMFieldBase::size_type PointerMFieldBase::max_size(void) const
{
    return _ptrStore.max_size();
}

inline 
PointerMFieldBase::size_type PointerMFieldBase::capacity(void) const
{
    return _ptrStore.capacity();
}
    
inline
PointerMFieldBase::difference_type 
    PointerMFieldBase::findIndex(const_value value) const
{
    const_iterator it = std::find(_ptrStore.begin(), _ptrStore.end(), value);

    if(it != _ptrStore.end())
    {
        return it - _ptrStore.begin();
    }
    else
    {
        return -1;
    }
}

inline 
void PointerMFieldBase::reserve(size_type size)
{
    return _ptrStore.reserve(size);
}

inline 
PointerMFieldBase::const_value 
    PointerMFieldBase::operator[](UInt32 const index) const
{
    return _ptrStore[index];
}

inline 
PointerMFieldBase::const_value 
    PointerMFieldBase::at(UInt32 const index) const
{
    return _ptrStore.at(index);
}
    
inline
bool PointerMFieldBase::operator ==(const Self &source) const
{
    return _ptrStore == source._ptrStore;
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void PointerMFieldBase::beginEdit(UInt32              ,
                                  AspectOffsetStore  &)
{
}

inline
PointerMFieldBase::Self *
    PointerMFieldBase::resolveShare(UInt32              , 
                                    AspectOffsetStore  &)
{
    return NULL;
}

inline
void PointerMFieldBase::terminateShare(UInt32              , 
                                       AspectOffsetStore  &)
{
    
}

inline
bool PointerMFieldBase::isShared(void)
{
    return false;
}
#endif

/*-------------------------------------------------------------------------*/
/* Constructors                                                            */

inline
PointerMFieldBase::PointerMFieldBase(void) :
     Inherited(),
    _ptrStore ()
{
}

/*-------------------------------------------------------------------------*/
/* Destructor                                                              */

inline
PointerMFieldBase::~PointerMFieldBase(void)
{
}


/*-------------------------------------------------------------------------*/
/* Raw Store Access                                                        */

inline 
PointerMFieldBase::StorageType &
    PointerMFieldBase::editRawStore(void)
{
    return _ptrStore;
}

inline 
PointerMFieldBase::StorageType const &
    PointerMFieldBase::getRawStore(void) const
{
    return _ptrStore;
}

/*-------------------------------------------------------------------------*/
/* Cast Store Access                                                       */

template <class TargetStoredTypeT> inline 
typename PointerMFieldBase::rebindStore<TargetStoredTypeT>::type &
    PointerMFieldBase::editStore(void)
{
    return
        reinterpret_cast<typename rebindStore<TargetStoredTypeT>::type &>(
            _ptrStore);
}

template <class TargetStoredTypeT> inline 
typename PointerMFieldBase::rebindStore<TargetStoredTypeT>::type const &
    PointerMFieldBase::getStore(void) const
{
    return
        reinterpret_cast<typename rebindStore<TargetStoredTypeT>::type const &>(
            _ptrStore);
}

OSG_END_NAMESPACE
