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

#ifndef _OSGMFIELD_H_
#define _OSGMFIELD_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGField.h"
#include "OSGFieldTraits.h"
#include "OSGSysFieldTraits.h"
#include "OSGFieldType.h"
#include "OSGMFieldVector.h"
#include "OSGBinaryDataHandler.h"

#include <algorithm>

OSG_BEGIN_NAMESPACE

#ifdef OSG_DOC_FILES_IN_MODULE
/*! \file OSGMField.h
    \ingroup GrpBaseField
    \ingroup GrpBaseFieldMulti
 */
#endif

/*! Base class for all multi field, for example MFMatrix
   \ingroup GrpBaseField
   \ingroup GrpBaseFieldMulti
 */

template<class ValueT, Int32 iNamespace = 0>
class MField : public Field
{
    /*==========================  PUBLIC  =================================*/

  public:

    typedef          MFieldVector<ValueT>               StorageType;
    typedef typename StorageType::Inherited             StorageTypeParent;

    typedef typename StorageType::iterator              iterator;
    typedef typename StorageType::const_iterator        const_iterator;

    typedef typename 
                    StorageType::reverse_iterator       reverse_iterator;
    typedef typename 
                    StorageType::const_reverse_iterator const_reverse_iterator;


    typedef typename StorageType::reference             reference;
    typedef typename StorageType::const_reference       const_reference;

    typedef          FieldTraits      <ValueT, 
                                       iNamespace>      MFieldTraits;
 
    typedef          MField           <ValueT, 
                                       iNamespace>      Self;

    typedef          ValueT                             StoredType;

    typedef typename MFieldTraits::ArgumentType         ArgumentType;

    typedef          FieldDescription<MFieldTraits,
                                      MultiField     >  Description;

    static const Int32 Namespace = iNamespace;

    static const bool isSField = false;
    static const bool isMField = true;

    /*---------------------------------------------------------------------*/
    /*! \name                   Class Get                                  */
    /*! \{                                                                 */

    static const FieldType &getClassType(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

             MField(void);
             MField(const MField  &obj);
    explicit MField(const UInt32   size);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructor                                 */
    /*! \{                                                                 */

    ~MField(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Get                                     */
    /*! \{                                                                 */

          StorageType &getValues(void);
    const StorageType &getValues(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Set                                     */
    /*! \{                                                                 */

    void setValues          (const StorageType       &value);
    void setValues          (const StorageTypeParent &value);
    void setValues          (const Self              &obj  );
    
    void addValueFromCString(const Char8             *str  );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Push                                    */
    /*! \{                                                                 */

    void pushValuesToString  (std::string  &str) const;
    void pushValuesFromStream(std::istream &str);
    void pushValuesToStream  (OutStream    &str) const;
    void pushSizeToStream    (OutStream    &str) const;
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Interface                           */
    /*! \{                                                                 */

    UInt32 getBinSize (void                   ) const;
    
    void   copyToBin  (BinaryDataHandler &pMem) const;
    void   copyFromBin(BinaryDataHandler &pMem);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   STL Interface                              */
    /*! \{                                                                 */

    iterator               begin    (void                              );
    iterator               end      (void                              );

    reverse_iterator       rbegin   (void                              );
    reverse_iterator       rend     (void                              );

    
    const_iterator         begin    (void                              ) const;
    const_iterator         end      (void                              ) const;
    
    const_reverse_iterator rbegin   (void                              ) const;
    const_reverse_iterator rend     (void                              ) const;


    reference              front    (void                              );
    const_reference        front    (void                              ) const;
    
    reference              back     (void                              );
    const_reference        back     (void                              ) const;
    
    void                   clear    (void                              );
    
    iterator               insert   (iterator     pos, 
                                     ArgumentType value                );
#ifdef __STL_MEMBER_TEMPLATES
    template <class InputIterator>
    void                   insert   (iterator      pos, 
                                     InputIterator first, 
                                     InputIterator last                );
#else
    void                   insert   (iterator      pos, 
                                     iterator      first,
                                     iterator      last                );
#endif /* __STL_MEMBER_TEMPLATES */
 
    iterator               erase    (iterator     pos                  );
    
    iterator               find     (ArgumentType value                );
    const_iterator         find     (ArgumentType value                ) const;
    Int32                  findIndex(ArgumentType value                ) const;

    void                   push_back(ArgumentType value                );
    
    void                   resize   (size_t       newsize, 
                                     StoredType   t      = StoredType());
    void                   reserve  (size_t       newsize              );
    
    UInt32                 size     (void                              ) const;
    UInt32                 capacity (void                              ) const;
    bool                   empty    (void                              ) const;
    void                   swap     (MField                      &right);

#ifdef OSG_1_COMPAT
    void                   addValue (ArgumentType value                );
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                  Index Operator                              */
    /*! \{                                                                 */

          reference operator [](UInt32 index);
    const_reference operator [](UInt32 index) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                  Compare                                     */
    /*! \{                                                                 */

    bool operator ==(const MField &source) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                  Assignment                                  */
    /*! \{                                                                 */

    void operator =(const MField &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      MT Sync                                 */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    void syncWith       (Self               &source, 
                         ConstFieldMaskArg   syncMode,
                         UInt32              uiSyncInfo,
                         AspectOffsetStore  &oOffsets    );

    void beginEdit      (UInt32              uiAspect,
                         AspectOffsetStore  &oOffsets    );


    Self *resolveShare  (UInt32              uiAspect, 
                         AspectOffsetStore  &oOffsets    );

    void  terminateShare(UInt32              uiAspect, 
                         AspectOffsetStore  &oOffsets    );

    bool  isShared      (void                            );
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      MT Sync                                 */
    /*! \{                                                                 */

    void dump(      UInt32    uiIndent = 0, 
              const BitVector bvFlags  = 0) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      MT Sync                                 */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    /*---------------------------------------------------------------------*/
    /*! \name                  Type information                            */
    /*! \{                                                                 */

    typedef Field Inherited;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Member                                  */
    /*! \{                                                                 */

    static FieldType   _fieldType;

           StorageType _values;

#ifdef OSG_MT_CPTR_ASPECT
           UInt32      _uiSharedWith;
#endif

#if defined(OSG_TMPL_STATIC_MEMBER_NEEDS_HELPER_FCT)
    const FieldType &fieldTypeExportHelper(void);
#endif

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:
};

OSG_END_NAMESPACE

#include "OSGMField.inl"

#endif /* _OSGMFIELD_H_ */
