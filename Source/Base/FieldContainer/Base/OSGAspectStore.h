/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2003 by the OpenSG Forum                   *
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

#ifndef _OSGASPECTSTORE_H_
#define _OSGASPECTSTORE_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGAtomic.h"

#ifdef OSG_MT_CPTR_ASPECT

#include "OSGThread.h"
#include "OSGThreadManager.h"
#include "OSGReflexiveContainer.h"

#include <vector>

OSG_BEGIN_NAMESPACE

class FieldContainer;

/*! \ingroup GrpBaseFieldContainerBase
    \ingroup GrpLibOSGBase
    \nohierarchy
 */

class OSG_BASE_DLLMAPPING AspectStore
{

    /*==========================  PUBLIC  =================================*/

  public:

    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */
 
    AspectStore(void);
    AspectStore(const  AspectStore &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Access                                   */
    /*! \{                                                                 */

    FieldContainer *getPtr            (      void                      ) const;
    FieldContainer *getPtr            (const UInt32          uiAspect  ) const;
    void            setPtrForAspect   (      FieldContainer *pContainer, 
                                       const UInt32          uiAspect  );
    void            removePtrForAspect(const UInt32          uiAspect  );
    UInt32          getAspect         (      FieldContainer *pContainer) const;

    UInt32          getNumAspects     (      void                      ) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                 Reference Counting                           */
    /*! \{                                                                 */

    void  addRef     (void);
    void  subRef     (void);    
    Int32 getRefCount(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                 Reference Counting                           */
    /*! \{                                                                 */

    void lock   (void);
    void release(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                 Reference Counting                           */
    /*! \{                                                                 */

    void fillOffsetArray(AspectOffsetStore &       oStore,
                         FieldContainer    * const pRef  );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                 Reference Counting                           */
    /*! \{                                                                 */

    void dump(void);

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    typedef std::vector<FieldContainer *> FieldContainerStore;

    FieldContainerStore _vAspects;

    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */
 
    ~AspectStore(void); 

    /*! \}                                                                 */
   /*==========================  PRIVATE  ================================*/

  private:

    UInt32        _uiSpinLock;
    RefCountStore _refCount;

    /*!\brief prohibit default function (move to 'public' if needed) */
    void operator =(const AspectStore &source);
};

typedef OSG::AspectStore *AspectStoreP;


/*! \ingroup GrpBaseFieldContainerBase
    \relatesalso OSG::AspectStore
 */

inline 
void addRef(const OSG::AspectStoreP pObject);

/*! \ingroup GrpBaseFieldContainerBase
    \relatesalso OSG::AspectStore
 */

inline
void subRef(const OSG::AspectStoreP pObject);

OSG_END_NAMESPACE

#include "OSGAspectStore.inl"

#endif

#endif /* _OSGASPECTSTORE_H_ */
