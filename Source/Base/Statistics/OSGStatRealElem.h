/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2002 by the OpenSG Forum                   *
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

#ifndef _OSGSTATREALELEM_H_
#define _OSGSTATREALELEM_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGStatElem.h"

#include <string>

OSG_BEGIN_NAMESPACE

class StatElemDescBase;

/*! \brief Real32 Statistics element, see \ref PageSystemStatistics for 
           details.
    \ingroup GrpBaseStatistics
    \ingroup GrpLibOSGBase
 */

class OSG_BASE_DLLMAPPING StatRealElem : public StatElem 
{
    /*==========================  PUBLIC  =================================*/

  public:

    /*---------------------------------------------------------------------*/
    /*! \name                    your_category                             */
    /*! \{                                                                 */

    static StatElem *create(StatElemDescBase *desc);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    instance                                  */
    /*! \{                                                                 */

            void   set  (Real32 value);
            Real32 get  (void        ) const;

            void   add  (Real32 v    );
            void   sub  (Real32 v    );
    
    virtual void   reset(void        );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    instance                                  */
    /*! \{                                                                 */

    virtual void   putToString   (      std::string  &str, 
                                  const std::string &format = std::string()) const;

    virtual bool   getFromCString(const Char8       *&inVal        );

    virtual Real64 getValue      (      void                       ) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    comparison                                */
    /*! \{                                                                 */

    bool operator < (const StatRealElem &other) const;
 
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Creation                                   */
    /*! \{                                                                 */

    virtual StatElem *clone(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Operators                                */
    /*! \{                                                                 */

    virtual StatElem &operator += (const StatElem &other);

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    StatRealElem(StatElemDescBase *desc);

    virtual ~StatRealElem(void); 

    /*! \}                                                                 */
    /*=========================  PRIVATE    ===============================*/

  private:

    typedef StatElem Inherited;

    Real32 _value;
 
    // prohibit default functions (move to 'public' if you need one)
    StatRealElem(const StatRealElem &source);
    StatRealElem& operator =(const StatRealElem &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------

typedef StatRealElem *StatRealElemP;

OSG_END_NAMESPACE

#include "OSGStatRealElem.inl"

#endif /* _OSGSTATREALELEM_H_ */
