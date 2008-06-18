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

#ifndef _OSGFIELDCONTAINERSFIELDHANDLE_H_
#define _OSGFIELDCONTAINERSFIELDHANDLE_H_
#ifdef __sgi
#pragma once
#endif

#include <boost/function.hpp>  

OSG_BEGIN_NAMESPACE

template <>
class OSG_SYSTEM_DLLMAPPING EditSFieldHandle<FieldContainerPtrSFieldBase> : 
    public EditFieldHandle
{
    /*=========================  PROTECTED  ===============================*/
  protected:

    typedef EditFieldHandle Inherited;
    
    /*==========================  PUBLIC  =================================*/
  public:
    /*---------------------------------------------------------------------*/
    /*! \name Public Types                                                 */
    /*! \{                                                                 */
  
    typedef boost::shared_ptr<EditSFieldHandle> Ptr;
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Constructors                                                 */
    /*! \{                                                                 */

    EditSFieldHandle(const EditSFieldHandle            &source);
    EditSFieldHandle(      FieldContainerPtrSFieldBase *pField, 
                     const FieldDescriptionBase        *pDescription);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Field Type Query                                             */
    /*! \{                                                                 */

    virtual const FieldType &getType       (void) const;
    virtual       bool       isPointerField(void) const;

    virtual       bool       supportsSet   (void) const = 0;
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Access                                                       */
    /*! \{                                                                 */

    virtual FieldContainer *get(void                 ) const = 0;
    
    virtual bool            set(FieldContainer *newFC)       = 0;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Stream/String IO                                             */
    /*! \{                                                                 */

    virtual void pushValueToStream   (      OutStream &str) const;
    virtual void pushSizeToStream    (      OutStream &str) const;

    virtual void pushValueFromCString(const Char8     *str);
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Comparison                                                   */
    /*! \{                                                                 */

    virtual bool equal(Inherited::Ptr rhs) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Copy/Share/Clone                                             */
    /*! \{                                                                 */

    virtual void copyValues (GetFieldHandlePtr  source) const;
    virtual void shareValues(GetFieldHandlePtr  source) const;

    virtual void cloneValues(
              GetFieldHandlePtr  pSrc,
        const TypePtrVector     &shareTypes     = TypePtrVector(),
        const TypePtrVector     &ignoreTypes    = TypePtrVector(),
        const TypeIdVector      &shareGroupIds  = TypeIdVector (),
        const TypeIdVector      &ignoreGroupIds = TypeIdVector ()) const;
        
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
};

template <>
class OSG_SYSTEM_DLLMAPPING GetSFieldHandle<FieldContainerPtrSFieldBase> : 
    public GetFieldHandle
{
    /*=========================  PROTECTED  ===============================*/
  protected:

    typedef GetFieldHandle Inherited;

    /*==========================  PUBLIC  =================================*/
  public:
    /*---------------------------------------------------------------------*/
    /*! \name Public Types                                                 */
    /*! \{                                                                 */

    typedef boost::shared_ptr<GetSFieldHandle> Ptr;

    /*---------------------------------------------------------------------*/
    /*! \name Constructors                                                 */
    /*! \{                                                                 */

    GetSFieldHandle(const GetSFieldHandle             &source);
    GetSFieldHandle(const FieldContainerPtrSFieldBase *pField, 
                    const FieldDescriptionBase        *pDescription);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Field Type Query                                             */
    /*! \{                                                                 */

    virtual const FieldType &getType       (void) const;
    virtual       bool       isPointerField(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Stream/String IO                                             */
    /*! \{                                                                 */

    virtual void pushValueToStream(OutStream &str) const;
    virtual void pushSizeToStream (OutStream &str) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Comparison                                                   */
    /*! \{                                                                 */

    virtual bool equal(Inherited::Ptr rhs) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Access                                                       */
    /*! \{                                                                 */
    
    virtual FieldContainer *get(void) const = 0;

    FieldContainerPtrSFieldBase const * operator ->(void);
    FieldContainerPtrSFieldBase const & operator * (void);
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
};


template <class FieldT>
class GetFCPtrSFieldHandle : 
    public  GetSFieldHandle<FieldContainerPtrSFieldBase>
{
    /*=========================  PROTECTED  ===============================*/
  protected:
    typedef FieldT                                       HandledField;
    typedef GetSFieldHandle<FieldContainerPtrSFieldBase> Inherited;

    /*==========================  PUBLIC  =================================*/
  public:
    /*---------------------------------------------------------------------*/
    /*! \name Constructors                                                 */
    /*! \{                                                                 */

    GetFCPtrSFieldHandle(const GetFCPtrSFieldHandle &source);
    GetFCPtrSFieldHandle(const FieldT               *pField, 
                         const FieldDescriptionBase *pDescription);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Field Type Query                                             */
    /*! \{                                                                 */

    virtual const FieldType &getType(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Stream/String IO                                             */
    /*! \{                                                                 */

    virtual void pushValueToStream(OutStream &str) const;
    virtual void pushSizeToStream (OutStream &str) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Access                                                       */
    /*! \{                                                                 */

    virtual FieldContainer *get(void) const;
    
    FieldT const * operator ->(void);
    FieldT const & operator * (void);
    
    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/
  private:
    const HandledField *dcast_const(void) const;
};

template <class FieldT>
class EditFCPtrSFieldHandle : 
    public EditSFieldHandle<FieldContainerPtrSFieldBase>
{
    /*=========================  PROTECTED  ===============================*/
  protected:
    typedef FieldT                                               HandledField;
    typedef EditSFieldHandle<FieldContainerPtrSFieldBase>        Inherited;

    typedef boost::function<void (typename FieldT::const_value)> SetMethod;

    SetMethod _fSetMethod;

    /*==========================  PUBLIC  =================================*/
  public:
    /*---------------------------------------------------------------------*/
    /*! \name Constructors                                                 */
    /*! \{                                                                 */

    EditFCPtrSFieldHandle(const EditFCPtrSFieldHandle &source      );
    EditFCPtrSFieldHandle(      FieldT                *pField, 
                          const FieldDescriptionBase  *pDescription);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Field Type Query                                             */
    /*! \{                                                                 */

    virtual const FieldType &getType    (void) const;

    virtual       bool       supportsSet(void) const;
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Access                                                       */
    /*! \{                                                                 */

    virtual FieldContainer *get(void                 ) const;
    
    virtual bool            set(FieldContainer *newFC);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Stream/String IO                                             */
    /*! \{                                                                 */

    virtual void pushValueToStream   (      OutStream &str) const;
    virtual void pushSizeToStream    (      OutStream &str) const;

    virtual void pushValueFromCString(const Char8     *str);
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Callback Setup                                               */
    /*! \{                                                                 */

    void setSetMethod(SetMethod fMethod);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name Copy/Share/Clone                                             */
    /*! \{                                                                 */
    
    virtual void copyValues (GetFieldHandlePtr  source) const;
    virtual void shareValues(GetFieldHandlePtr  source) const;
    
    virtual void cloneValues(
              GetFieldHandlePtr  pSrc,
        const TypePtrVector     &shareTypes     = TypePtrVector(),
        const TypePtrVector     &ignoreTypes    = TypePtrVector(),
        const TypeIdVector      &shareGroupIds  = TypeIdVector (),
        const TypeIdVector      &ignoreGroupIds = TypeIdVector ()) const;
    
    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/
  private:
          HandledField *dcast      (void);
    const HandledField *dcast_const(void) const;
};

OSG_END_NAMESPACE

#include "OSGFieldContainerSFieldHandle.inl"

#endif /* _OSGFIELDCONTAINERSFIELDHANDLE_H_ */
