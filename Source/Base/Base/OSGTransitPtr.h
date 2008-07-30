/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *                       Copyright 2008 by OpenSG Forum                      *
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

#ifndef _OSGTRANSITPOINTER_H_
#define _OSGTRANSITPOINTER_H_

#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGBaseFunctions.h"

#ifdef OSG_DOC_FILES_IN_MODULE
/*! \file OSGReferenceCountPointerDecl.h
    \ingroup GrpSystemFieldContainer
 */
#endif

OSG_BEGIN_NAMESPACE

/*! \ingroup GrpSystemFieldContainer
 */

template <class ObjectT, 
          class RefCountPolicyT>
class RefCountPtr;

template <class TargetObjectT, class SourceObjectT> inline
TransitPtr<TargetObjectT> dynamic_pointer_cast(
    TransitPtr<SourceObjectT> const &source);

template <class TargetObjectT, class SourceObjectT> inline
TransitPtr<TargetObjectT> static_pointer_cast(
    TransitPtr<SourceObjectT> const &source);

template <class ObjectT>
class TransitPtr
{
    /*==========================  PUBLIC  =================================*/

    template <class ObjT, class RefCountPolicyT>
    friend class RefCountPtr;

    template<class OtherT>
    friend class TransitPtr;

  public:

    /*---------------------------------------------------------------------*/
    /*! \name Public Types                                                 */
    /*! \{                                                                 */
  
    typedef ObjectT                                          Object;
    typedef TransitPtr<Object>                               Self;
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Constructors                                                 */
    /*! \{                                                                 */
  
    TransitPtr(      void        );
    TransitPtr(      Self  &other);
    TransitPtr(const Self  &other);
   
    explicit
    TransitPtr(Object * const pObj);
    
    template<class OtherObjT> explicit 
    TransitPtr(TransitPtr<OtherObjT> const &other);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Desctructor                                                  */
    /*! \{                                                                 */

    ~TransitPtr(void);
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Assignment                                                   */
    /*! \{                                                                 */
    
    Self &operator =(      Self           &other);
    Self &operator =(const Self           &other);
    Self &operator =(      Object * const  pObj );

    template<class OtherObjT> 
    Self &operator =(TransitPtr<OtherObjT> const &other);
  
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Conversion                                                   */
    /*! \{                                                                 */

    Object *operator->(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Access                                                       */
    /*! \{                                                                 */
    
    bool operator ==(FieldContainer * const rhs);
    bool operator !=(FieldContainer * const rhs);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Access                                                       */
    /*! \{                                                                 */

#ifdef REFPTR_UNITTEST
    inline
    Object *getRaw(void) const
    {
        return _pObj;
    }
#endif

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    /*==========================  PRIVATE  ================================*/

    /*---------------------------------------------------------------------*/
    /*! \name Member                                                       */
    /*! \{                                                                 */
    
    mutable Object *_pObj;
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Access                                                       */
    /*! \{                                                                 */

    template<class SourceObjectT>
    void dynamic_cast_set(TransitPtr<SourceObjectT> const &source);

    template<class SourceObjectT>
    void static_cast_set (TransitPtr<SourceObjectT> const &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/

  private:

    /*---------------------------------------------------------------------*/
    /*! \name Internal Helpers                                             */
    /*! \{                                                                 */

    template <class TargetObjectT, class SourceObjectT> 
    friend TransitPtr<TargetObjectT> dynamic_pointer_cast(
        TransitPtr<SourceObjectT> const &source);

    template <class TargetObjectT, class SourceObjectT> 
    friend TransitPtr<TargetObjectT> static_pointer_cast(
        TransitPtr<SourceObjectT> const &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
  
};

template <class TargetObjectT, class SourceObjectT> inline
TransitPtr<TargetObjectT> dynamic_pointer_cast(
    TransitPtr<SourceObjectT> const &source)
{
    TransitPtr<TargetObjectT> returnValue;

    returnValue.dynamic_cast_set(source);

    return returnValue;
}
       

OSG_END_NAMESPACE


#if 0
namespace boost
{

template <class TargetObjectT, class SourceObjectT, class BaseObjectT>
OSG::TransitPointer<TargetObjectT, BaseObjectT>
static_pointer_cast(OSG::TransitPointer<SourceObjectT, BaseObjectT> const &source);

template <class TargetObjectT, class SourceObjectT, class BaseObjectT>
OSG::TransitPointer<TargetObjectT, BaseObjectT>
const_pointer_cast(OSG::TransitPointer<SourceObjectT, BaseObjectT> const &source);

template <class TargetObjectT, class SourceObjectT, class BaseObjectT>
OSG::TransitPointer<TargetObjectT, BaseObjectT>
dynamic_pointer_cast(OSG::TransitPointer<SourceObjectT, BaseObjectT> const &source);
          
} // namespace boost
#endif

#include "OSGTransitPtr.inl"

#endif // _OSGTRANSITPOINTER_H_