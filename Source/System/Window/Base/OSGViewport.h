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


#ifndef _OSGVIEWPORT_H_
#define _OSGVIEWPORT_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGViewportBase.h"
#include "OSGWindowFields.h"
#include "OSGBackground.h"
#include "OSGCamera.h"

OSG_BEGIN_NAMESPACE

#ifdef OSG_OLD_RENDER_ACTION
class DrawActionBase;
#endif

#ifdef OSG_CLEANED_RENDERACTION
class RenderTraversalActionBase;
class StageValidator;
#endif

/*! \brief Viewport base class. See \ref 
    PageSystemWindowViewports for a description.
*/

class OSG_SYSTEM_DLLMAPPING Viewport : public ViewportBase
{
    /*==========================  PUBLIC  =================================*/

  public:

    typedef ViewportBase                           Inherited;

    /*---------------------------------------------------------------------*/
    /*! \name                    access                                    */
    /*! \{                                                                 */

    void setSize        (Real32 left,  
                         Real32 bottom, 
                         Real32 right, 
                         Real32 top   );
    
    virtual Int32 getPixelLeft  (void) const;
    virtual Int32 getPixelRight (void) const;
    virtual Int32 getPixelBottom(void) const;
    virtual Int32 getPixelTop   (void) const;

            Int32 getPixelWidth (void) const;
            Int32 getPixelHeight(void) const;
    
    virtual bool  isFullWindow  (void) const;

    WindowPtrConst getParent(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    your_category                             */
    /*! \{                                                                 */

#if 0 // Have to check GV
    virtual void activateSize(void                             );
    virtual void activate    (void                             );
    virtual void deactivate  (void                             );
#endif

#ifdef OSG_OLD_RENDER_ACTION
    virtual void render      (DrawActionBase            *action);
#endif

#ifdef OSG_CLEANED_RENDERACTION
    virtual void render      (RenderTraversalActionBase *action);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    void setParent(      ParentFieldContainerPtrConstArg value,
                   const UInt16                          uiStoredInFieldId = 
                                                            InvalidParentEPos);
    

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    StageValidator *getStageValidator(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   change                                     */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField, 
                         UInt32            origin    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   dump                                       */
    /*! \{                                                                 */

    virtual void dump(      UInt32    uiIndent = 0, 
                      const BitVector bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

 protected:

    StageValidator *_pStageValidator;

    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    Viewport(void);
    Viewport(const Viewport &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~Viewport(void); 
    
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */
    
    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                MT Construction                               */
    /*! \{                                                                 */

    void onCreate       (const Viewport *source = NULL);

    void onCreateAspect (const Viewport *createAspect,
                         const Viewport *source = NULL);
    
    void onDestroy      (      UInt32    uiContainerId);

    void onDestroyAspect(      UInt32    uiContainerId,
                               UInt32    uiAspect     );
    
    /*! \}                                                                 */
    /*=========================  PRIVATE    ===============================*/

 private:

    friend class FieldContainer;
    friend class ViewportBase;
   
    // prohibit default functions (move to 'public' if you need one)
    void operator =(const Viewport &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------

typedef Viewport *ViewportP;

OSG_END_NAMESPACE

#include "OSGViewportBase.inl"
#include "OSGViewport.inl"

#endif /* _OSGVIEWPORT_H_ */
