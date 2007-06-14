/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright(C) 2000-2002 by the OpenSG Forum                   *
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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include <OSGGL.h>

#include <OSGField.h>
#include <OSGFieldContainer.h>
#include <OSGAction.h>
#include <OSGDrawActionBase.h>

#ifdef OSG_CLEANED_RENDERACTION
#include <OSGRenderTraversalActionBase.h>
#endif

#include <OSGDrawEnv.h>

#include "OSGBackground.h"
#include "OSGViewport.h"
#include "OSGWindow.h"
#include "OSGCamera.h"
#include "OSGForeground.h"

#include "OSGStageValidator.h"

OSG_USING_NAMESPACE

// Documentation for this class is emited in the
// OSGViewportBase.cpp file.
// To modify it, please change the .fcd file (OSGViewport.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  public                                                                 -
\*-------------------------------------------------------------------------*/

void Viewport::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);
}

void Viewport::onCreate      (const Viewport *source)
{
    Inherited::onCreate(source);
}

void Viewport::onCreateAspect(const Viewport *createAspect,
                              const Viewport *source)
{
    Inherited::onCreateAspect(createAspect, source);

    // Don't add the prototype instances to the list
    if(GlobalSystemState != Running)
        return;

    _pStageValidator = new StageValidator;
}

void Viewport::onDestroy(UInt32 uiContainerId)
{
    Inherited::onDestroy(uiContainerId);
}

void Viewport::onDestroyAspect(UInt32    uiContainerId,
                               UInt32    uiAspect     )
{
    delete _pStageValidator;

    _pStageValidator = NULL;

    Inherited::onDestroyAspect(uiContainerId, uiAspect);
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*------------- constructors & destructors --------------------------------*/

Viewport::Viewport(void) :
     Inherited      (    ),
    _pStageValidator(NULL)
{
}

Viewport::Viewport(const Viewport &source) :
     Inherited      (source),
    _pStageValidator(NULL  )
{
}

Viewport::~Viewport(void)
{
}

void Viewport::changed(ConstFieldMaskArg whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);
}

/*---------------------------- properties ---------------------------------*/

/*! Calculate the positon of the left border of the viewport. Needs a valid
    _sfParent value.
 */

Int32 Viewport::getPixelLeft(void) const
{
    if(getLeft() > 1)
        return Int32(getLeft());
    
    return Int32(getParent()->getWidth() * getLeft());
}

/*! Calculate the positon of the right border of the viewport. Needs a valid
    _sfParent value.
 */

Int32 Viewport::getPixelRight(void) const
{
    // >1: pixel
    if(getRight() > 1)
        return Int32(getRight());
    
    // <=1: partial screen, use 1 less to not overlap other windows
    return Int32(getParent()->getWidth() * getRight() - 1);
}

/*! Calculate the positon of the bottom border of the viewport. Needs a valid
    _sfParent value.
 */

Int32 Viewport::getPixelBottom(void) const
{
    if(getBottom() > 1)
        return Int32(getBottom());
    
    return Int32(getParent()->getHeight() * getBottom());
}

/*! Calculate the positon of the top border of the viewport. Needs a valid
    _sfParent value.
 */

Int32 Viewport::getPixelTop(void) const
{
    // >1: pixel
    if(getTop() > 1)
        return Int32(getTop());
    
    // <=1: partial screen, use 1 less to not overlap other windows
    return Int32(getParent()->getHeight() * getTop() - 1);
}

/*! Checks if the viewport fills the whole window. Needs a valid
  _sfParent value.
 */
bool Viewport::isFullWindow(void) const
{
    return  
        getPixelBottom() == 0 &&
        getPixelLeft()   == 0 &&
        getPixelTop()    == getParent()->getHeight() - 1 &&
        getPixelRight()  == getParent()->getWidth () - 1;
}

WindowPtrConst Viewport::getParent(void) const
{
    return dynamic_cast<WindowPtrConst>(_sfParent.getValue().getCPtr());
}

/*-------------------------- your_category---------------------------------*/

/*! Draw the viewport. Restrict the OpenGL rendering to the given part of the
  window, clear it, draw it using the given DrawAction and add the Foregrounds.
  
  The _sfCamera, _sfBackground and _sfRoot Fields need to be valid, otherwise
  drawing will fail.
  
  \dev
  
  Activates scissoring only if the viewport doesn't fill the wholw window, as
  it significantly slows down some OpenGL implementations.
  
  \enddev
  
 */

#if 0 // Have to check GV
void Viewport::activateSize(void)
{
    GLint pl = getPixelLeft();
    GLint pr = getPixelRight();
    GLint pb = getPixelBottom();
    GLint pt = getPixelTop();
    GLint pw = pr - pl + 1;
    GLint ph = pt - pb + 1;

    glViewport(pl, pb, pw, ph);

    if(!isFullWindow())
    {
        glScissor(pl, pb, pw, ph);
        glEnable(GL_SCISSOR_TEST);
    }
    else
    {
       glDisable(GL_SCISSOR_TEST);
    }
        
}

void Viewport::activate(void)
{
    activateSize();
}

void Viewport::deactivate(void)
{
}
#endif

#ifdef OSG_OLD_RENDER_ACTION
void Viewport::render(DrawActionBase *action)
{
    if(getCamera() == NullFC)
    {
        SWARNING << "Viewport::render: no camera!" << std::endl;
        return;
    }
    if(getBackground() == NullFC)
    {
        SWARNING << "Viewport::render: no Background!" << std::endl;
        return;
    }
    if(getRoot() == NullFC)
    {
        SWARNING << "Viewport::render: no root!" << std::endl;
        return;
    }

#if 0 // Have to check GV
    activate();
#endif

    action->setCamera    (getCPtr(getCamera    ()));
    action->setBackground(getCPtr(getBackground()));
    action->setViewport  (this                     );
    action->setTravMask  (getTravMask()            );

    action->apply(getRoot());

    DrawEnv oEnv;
    
    oEnv.setWindow(action->getWindow());
    
    for(UInt16 i=0; i < getForegrounds().size(); i++)
        getForegrounds(i)->draw(&oEnv, this);

#if 0 // Have to check GV
    deactivate();
#endif
}
#endif

#ifdef OSG_CLEANED_RENDERACTION
void Viewport::render(RenderTraversalActionBase *action)
{
     _pStageValidator->incEventCounter();
 
    if(getCamera() == NullFC)
    {
        SWARNING << "Viewport::render: no camera!" << std::endl;
        return;
    }
    if(getBackground() == NullFC)
    {
        SWARNING << "Viewport::render: no Background!" << std::endl;
        return;
    }
    if(getRoot() == NullFC)
    {
        SWARNING << "Viewport::render: no root!" << std::endl;
        return;
    }

#if 0 // Have to check GV
    activate();
#endif

    action->setCamera    (getCPtr(getCamera    ()));
    action->setBackground(getCPtr(getBackground()));
    action->setViewport  (this                     );
    action->setTravMask  (getTravMask()            );

    action->apply(getRoot());

    DrawEnv oEnv;

    oEnv.setWindow(action->getWindow());

    for(UInt16 i=0; i < getForegrounds().size(); i++)
        getForegrounds(i)->draw(&oEnv, this);

#if 0 // Have to check GV
    deactivate();
#endif
}
#endif

/*------------------------------- dump ----------------------------------*/

void Viewport::dump(     UInt32    OSG_CHECK_ARG(uiIndent), 
                    const BitVector OSG_CHECK_ARG(bvFlags)) const
{
    SLOG << "Dump Viewport NI" << std::endl;

    fprintf(stderr, "%p %p %p\n", 
            this, 
            getCPtr(_sfCamera.getValue()),
            getCPtr(getCamera()));
}


