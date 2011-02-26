/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *                  Copyright (C) 2009 by the OpenSG Forum                   *
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

#ifndef _OSGANIMBINDACTION_H_
#define _OSGANIMBINDACTION_H_

#include "OSGConfig.h"
#include "OSGDynamicsDef.h"
#include "OSGAction.h"

OSG_BEGIN_NAMESPACE

// forward decl
class AnimTemplate;
class Animation;

OSG_GEN_CONTAINERPTR(AnimTemplate);
OSG_GEN_CONTAINERPTR(Animation   );

/*---------------------------------------------------------------------------*\
 * AnimBindAction                                                            *
\*---------------------------------------------------------------------------*/

class OSG_DYNAMICS_DLLMAPPING AnimBindAction : public Action
{
  public:
    typedef Action         Inherited;
    typedef AnimBindAction Self;

    virtual ~AnimBindAction(void);

    static AnimBindAction *create(void);

    static void registerEnterDefault(const FieldContainerType &type,
                                     const Action::Functor    &func );
    static void registerLeaveDefault(const FieldContainerType &type,
                                     const Action::Functor    &func );

    AnimTemplate *getTemplate(void                  ) const;
    void          setTemplate(AnimTemplate *animTmpl);

    Animation    *getAnim    (void                  ) const;
    void          setAnim    (Animation    *anim    );

  protected:
    AnimBindAction(void                        );
    AnimBindAction(const AnimBindAction &source);

    virtual FunctorStore *getDefaultEnterFunctors(void);
    virtual FunctorStore *getDefaultLeaveFunctors(void);

    static  bool          terminateEnter         (void);
    static  bool          terminateLeave         (void);

    static FunctorStore *_defaultEnterFunctors;
    static FunctorStore *_defaultLeaveFunctors;


  private:
    AnimTemplateUnrecPtr _animTmpl;
    AnimationUnrecPtr    _anim;

};

Action::ResultE
transformKFBindEnter(NodeCore *core, Action *action);

Action::ResultE
skeletonKFBindEnter(NodeCore *core, Action *action);

OSG_END_NAMESPACE

#endif // _OSGANIMBINDACTION_H_
