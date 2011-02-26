/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *                Copyright (C) 2009 by the OpenSG Forum                     *
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

#if __GNUC__ >= 4 || __GNUC_MINOR__ >=3
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

#include "OSGColladaInstanceController.h"

#ifdef OSG_WITH_COLLADA

#include "OSGColladaLog.h"

#include <dom/domInstance_controller.h>

OSG_BEGIN_NAMESPACE

ColladaElementRegistrationHelper ColladaInstanceController::_regHelper(
    &ColladaInstanceController::create, "instance_controller");


ColladaElementTransitPtr
ColladaInstanceController::create(daeElement *elem, ColladaGlobal *global)
{
    return ColladaElementTransitPtr(
        new ColladaInstanceController(elem, global));
}

void
ColladaInstanceController::read(void)
{
    OSG_COLLADA_LOG(("ColladaInstanceController::read\n"));

    ColladaControllerRefPtr colCtrl = getTargetElem();

    if(colCtrl == NULL)
    {
        colCtrl = dynamic_pointer_cast<ColladaController>(
            ColladaElementFactory::the()->create(
                getTargetDOMElem(), getGlobal()));

        colCtrl->read();
    }

    domInstance_controllerRef instCtrl =
        getDOMElementAs<domInstance_controller>();
    domBind_materialRef       bindMat  = instCtrl->getBind_material();

    if(bindMat == NULL)
    {
        SWARNING << "ColladaInstanceController::read: "
                 << "No <bind_material> found." << std::endl;
        return;
    }

    Inherited::readBindMaterial(bindMat);
    readSkeleton();
}

Node *
ColladaInstanceController::process(ColladaElement *parent)
{
    OSG_COLLADA_LOG(("ColladaInstanceController::process\n"));

    ColladaControllerRefPtr colCtrl = getTargetElem();

    return colCtrl->createInstance(this);
}

ColladaController *
ColladaInstanceController::getTargetElem(void) const
{
    ColladaController *retVal     = NULL;
    daeElementRef      targetElem = getTargetDOMElem();

    if(targetElem != NULL)
    {
        retVal = getUserDataAs<ColladaController>(targetElem);
    }

    return retVal;
}

daeElement *
ColladaInstanceController::getTargetDOMElem(void) const
{
    domControllerRef          retVal   = NULL;
    domInstance_controllerRef instCtrl =
        getDOMElementAs<domInstance_controller>();

    if(instCtrl->getUrl().getElement() != NULL)
    {
        retVal = daeSafeCast<domController>(instCtrl->getUrl().getElement());
    }

    return retVal;
}

ColladaInstanceController::ColladaInstanceController(
    daeElement *elem, ColladaGlobal *global)

    : Inherited(elem, global)
{
}

ColladaInstanceController::~ColladaInstanceController(void)
{
}

void
ColladaInstanceController::readSkeleton(void)
{
    SWARNING << "ColladaInstanceController::readSkeleton: NIY"
             << std::endl;

    domInstance_controllerRef                        instCtrl =
        getDOMElementAs<domInstance_controller>();
    const domInstance_controller::domSkeleton_Array &skels    =
        instCtrl->getSkeleton_array();

    for(UInt32 i = 0; i < skels.getCount(); ++i)
    {
        OSG_COLLADA_LOG(("ColladaInstanceController::readSkeleton: "
                         "Skeleton root node: [%s]\n",
                         skels[i]->getValue().getURI()));
    }
}

OSG_END_NAMESPACE

#endif // OSG_WITH_COLLADA
