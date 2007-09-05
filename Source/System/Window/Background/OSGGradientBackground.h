/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2005 by the OpenSG Forum                   *
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


#ifndef _OSGGRADIENTBACKGROUND_H_
#define _OSGGRADIENTBACKGROUND_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"

#include "OSGGradientBackgroundBase.h"

OSG_BEGIN_NAMESPACE

class DrawActionBase;
class Viewport;

/*! \brief Background clearing with a color gradient. See \ref 
    PageSystemWindowBackground for a description.
*/

class OSG_WINDOW_DLLMAPPING GradientBackground : public GradientBackgroundBase
{
    /*==========================  PUBLIC  =================================*/
 public:

    static const OSG::BitVector LineFieldMask;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    your_category                             */
    /*! \{                                                                 */
    
    void clear(DrawEnv *);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    your_category                             */
    /*! \{                                                                 */

    void addLine   (Color3f color, 
                    Real32  position);

    void clearLines(void            );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     transformation                           */
    /*! \{                                                                 */
    
    virtual void changed(ConstFieldMaskArg whichField, 
                         UInt32            origin,
                         BitVector         detail);
 
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   dump                                       */
    /*! \{                                                                 */

    virtual void dump(      UInt32    uiIndent = 0, 
                      const BitVector bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

 protected:

                                                                     
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */
    
    GradientBackground(void);
    GradientBackground(const GradientBackground &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */
    
    virtual ~GradientBackground(void); 
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Init                                   */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);
    
    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/  

private:

    typedef GradientBackgroundBase Inherited;

    friend class FieldContainer;
    friend class GradientBackgroundBase;

    void operator =(const GradientBackground &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------

typedef GradientBackground *GradientBackgroundP;

OSG_END_NAMESPACE

#include "OSGGradientBackgroundBase.inl"
#include "OSGGradientBackground.inl"

#endif /* _OSGGRADIENTBACKGROUND_H_ */
