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

#include <cstdlib>
#include <cstdio>

#include <sstream>
#include <fstream>

#include <OSGConfig.h>

#include <OSGAction.h>
#include <OSGCamera.h>
#include <OSGRenderAction.h>
#include <OSGSceneFileHandler.h>
#include <OSGVolumeDraw.h>

#include "OSGVisitSubTree.h"

OSG_USING_NAMESPACE

// Documentation for this class is emited in the
// OSGVisitSubTreeBase.cpp file.
// To modify it, please change the .fcd file (OSGVisitSubTree.fcd) and
// regenerate the base file.

/*-------------------------------------------------------------------------*/
/*                               Sync                                      */

void VisitSubTree::changed(ConstFieldMaskArg whichField, 
                           UInt32            origin,
                           BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

/*-------------------------------------------------------------------------*/
/*                               Dump                                      */

void VisitSubTree::dump(       UInt32    OSG_CHECK_ARG(uiIndent), 
                         const BitVector OSG_CHECK_ARG(bvFlags )) const
{
    SLOG << "Dump VisitSubTree NI" << std::endl;
}

/*-------------------------------------------------------------------------*/
/*                            Constructors                                 */

VisitSubTree::VisitSubTree(void) :
    Inherited()
{
}

VisitSubTree::VisitSubTree(const VisitSubTree &source) :
    Inherited(source)
{
}

/*-------------------------------------------------------------------------*/
/*                             Destructor                                  */

VisitSubTree::~VisitSubTree(void)
{
}

/*! 
  If url was loaded, extend volume by loaded geometry. Otherwise
  extend volume by the volume given in the proxy object
*/

void VisitSubTree::adjustVolume(Volume &volume)
{
    if(getSubTreeRoot() != NULL)
    {
        getSubTreeRoot()->updateVolume();

        volume.extendBy(getSubTreeRoot()->getVolume());
    }
}

/*-------------------------------------------------------------------------*/
/*                                Draw                                     */

/*!
  Draw loaded geometry. If nothing was loaded until now, start
  loading. If loading is not finished, draw the children of 
  thid group.
 */

#ifdef OSG_OLD_RENDER_ACTION
ActionBase::ResultE VisitSubTree::render(Action *action)
{
    DrawActionBase *da = dynamic_cast<DrawActionBase *>(action);

    da->useNodeList();
    
    if(da->isVisible(getSubTreeRoot()))
        da->addNode(getSubTreeRoot());

    return Action::Continue;
}
#endif

ActionBase::ResultE VisitSubTree::render(Action *action)
{
    RenderAction *a = dynamic_cast<RenderAction *>(action);

    a->useNodeList();
    
    if(a->isVisible(this->getSubTreeRoot()))
        a->addNode(this->getSubTreeRoot());

    return Action::Continue;
}

/*-------------------------------------------------------------------------*/
/*                               loading                                   */

/*-------------------------------------------------------------------------*/
/*                               Init                                      */

void VisitSubTree::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
        RenderAction::registerEnterDefault(
            VisitSubTree::getClassType(),
            reinterpret_cast<Action::Callback>(&VisitSubTree::render));
    }
}

