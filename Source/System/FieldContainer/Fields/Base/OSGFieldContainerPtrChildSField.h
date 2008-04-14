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

#ifndef _OSGFIELDCONTAINERPTRCHILDSFIELD_H_
#define _OSGFIELDCONTAINERPTRCHILDSFIELD_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGFieldContainerPtrSFieldBase.h"

#include <boost/function.hpp>  

OSG_BEGIN_NAMESPACE

template<class    ValueT, 
         typename RefCountPolicy, 
         Int32    iNamespace     = 0>
class FieldContainerPtrChildSField : public FieldContainerPtrSFieldBase
{
    /*==========================  PUBLIC  =================================*/

  public:

    typedef          FieldTraits           <ValueT, 
                                            iNamespace    >  SFieldTraits;

    typedef typename SFieldTraits::ParentType                ParentT;

    typedef          FieldContainerPtrChildSField<
                         ValueT, 
                         RefCountPolicy,
                         iNamespace                       >  Self;

    typedef          ValueT                                  StoredType;
    typedef const    ValueT                                  const_reference;
    typedef const    ValueT                                  const_value;
  

    typedef const    ValueT                                  ArgumentType;

    typedef          FieldDescription      <
                         SFieldTraits,
                         FieldType::SingleField,
                         RefCountPolicy,
                         FieldType::ChildPtrField         >  Description;

    typedef          EditFCPtrSFieldHandle <Self          >  EditHandle;
    typedef          boost::shared_ptr     <EditHandle    >  EditHandlePtr;

    typedef          GetFCPtrSFieldHandle  <Self          >  GetHandle;
    typedef          boost::shared_ptr     <GetHandle     >  GetHandlePtr;

    /*---------------------------------------------------------------------*/

    static const Int32            Namespace = iNamespace;

    static const FieldType::Class Class     = FieldType::ChildPtrField;

    /*---------------------------------------------------------------------*/
    /*! \name                   Class Get                                  */
    /*! \{                                                                 */

    static const FieldType &getClassType(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    FieldContainerPtrChildSField(ParentT      pParent,
                                 UInt16       usChildFieldId,
                                 UInt16       usParentFieldId);

    FieldContainerPtrChildSField(ArgumentType value,
                                 ParentT      pParent,
                                 UInt16       usChildFieldId,
                                 UInt16       usParentFieldId);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructor                                 */
    /*! \{                                                                 */

    ~FieldContainerPtrChildSField(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Get                                     */
    /*! \{                                                                 */

    const_reference getValue(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Set                                     */
    /*! \{                                                                 */

    void setValue(      ArgumentType  value);
    void setValue(const Self         &obj  );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Interface                           */
    /*! \{                                                                 */

    void copyFromBin(BinaryDataHandler &pMem);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      MT Sync                                 */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    void syncWith(Self &source);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Compare                                 */
    /*! \{                                                                 */

    bool operator ==(const Self &source) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Assign                                  */
    /*! \{                                                                 */

    void operator =(const Self &source);

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

#if 0
    struct SingleParentHandler
    {
        static void updateParentLinking(ArgumentType value,
                                        ParentT      pParent,
                                        UInt16       usParentFieldPos)
        {
            // already somebody else's child?
            if(value != NULL)
            {
                if(value->getParent() != NullFC)
                {
                    value->getParent()->subChildPointer(value, 
                                                        usParentFieldPos);
                }

                value->setParent(pParent, usParentFieldPos);
            }
        }

        static void clearParentLinking(ArgumentType value,
                                       ParentT      ,
                                       UInt16       usParentFieldPos)
        {
            if(value != NullFC)
                value->setParent(NullFC, usParentFieldPos);
        }
    };

    struct MultiParentHandler
    {
        static void updateParentLinking(ArgumentType value,
                                        ParentT      pParent,
                                        UInt16       usParentFieldPos)
        {
            // already somebody else's child?
            if(value != NULL)
            {
                value->addParent(pParent, usParentFieldPos);
            }
        }
 
        static void clearParentLinking(ArgumentType value,
                                       ParentT      pParent,
                                       UInt16              )
        {
            if(value != NullFC)
                value->subParent(pParent);
        }
    };

    typedef typename
      boost::mpl::if_<
        boost::mpl::bool_<
                  (SFieldTraits::eParentCard == FieldType::SingleField)>,
        SingleParentHandler,
        MultiParentHandler>::type ParentHandler;
#endif

    /*---------------------------------------------------------------------*/
    /*! \name                  Type information                            */
    /*! \{                                                                 */

    typedef FieldContainerPtrSFieldBase Inherited;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 488 )
#endif

    template<class To>
          To &dcast(void);

    template<class To>
    const To dcast(void) const;

#ifdef OSG_LINUX_ICC
#pragma warning( default : 488 )
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Member                                  */
    /*! \{                                                                 */

    ParentT _pParent;
    UInt16  _usChildFieldId;
    UInt16  _usParentFieldId;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Member                                  */
    /*! \{                                                                 */

    static FieldType            _fieldType;
     
#if defined(OSG_TMPL_STATIC_MEMBER_NEEDS_HELPER_FCT)
    const FieldType &fieldTypeExportHelper(void);
#endif

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:
};

OSG_END_NAMESPACE

#ifndef OSG_COMPILECONTAINERFIELDINST
#include "OSGFieldContainerPtrChildSField.inl"
#endif

#endif /* _OSGFIELDCONTAINERPTRSFIELD_H_ */
