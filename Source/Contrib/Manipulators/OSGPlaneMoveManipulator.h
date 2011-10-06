/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2002 by the OpenSG Forum                 *
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

#ifndef _OSGPLANEMOVEMANIPULATOR_H_
#define _OSGPLANEMOVEMANIPULATOR_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"

#include "OSGPlaneMoveManipulatorBase.h"

OSG_BEGIN_NAMESPACE

/*! \brief PlaneMoveManipulator class. See \ref
           PageManipulatorsPlaneMoveManipulator for a description.
*/

class OSG_CONTRIBGUI_DLLMAPPING PlaneMoveManipulator : public PlaneMoveManipulatorBase
{
    /*==========================  PUBLIC  =================================*/
  public:

    virtual void mouseMove(Int16        x,
                           Int16        y);

    virtual void mouseButtonPress(UInt16        button,
                                   Int16        x,
                                   Int16        y     );

    virtual void mouseButtonRelease(UInt16      button,
                                     Int16      x,
                                     Int16      y     );

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         detail);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/
  protected:

    // Variables should all be in PlaneMoveManipulatorBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    PlaneMoveManipulator(void);
    PlaneMoveManipulator(const PlaneMoveManipulator &source);

    void onCreate();
    void onCreate(const PlaneMoveManipulator* source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~PlaneMoveManipulator(void);


    /*! \}                                                                 */

    virtual NodeTransitPtr makeHandleGeo();

    /*==========================  PRIVATE  ================================*/
private:

    typedef PlaneMoveManipulatorBase Inherited;

    friend class FieldContainer;
    friend class PlaneMoveManipulatorBase;

    static void initMethod(InitPhase ePhase);

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const PlaneMoveManipulator &source);
};

typedef PlaneMoveManipulator *PlaneMoveManipulatorP;

OSG_END_NAMESPACE

#include "OSGPlaneMoveManipulatorBase.inl"
#include "OSGPlaneMoveManipulator.inl"

#endif /* _OSGMOVEMANIPULATOR_H_ */
