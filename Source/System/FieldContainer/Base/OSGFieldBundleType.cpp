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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include "OSGFieldBundleType.h"
#include "OSGContainerPtrFuncs.h"
#include "OSGFieldBundleFactory.h"

OSG_USING_NAMESPACE

/*-------------------------------------------------------------------------*/
/*                            Constructors                                 */

FieldBundleType::FieldBundleType(
    const Char8                *szName,
    const Char8                *szParentName,
    const Char8                *szGroupName,
    const UInt32                uiNameSpace,
          ProtoBundleCreateF    fPrototypeCreate,
          InitBundleF           fInitMethod,
          InitalInsertDescFunc  descInsertFunc,
          bool                  bDescsAddable,
          BitVector             bvUnmarkedOnCreate,
          std::string           szFcdXML,
          std::string           szTypeDoc) :

     Inherited       (szName,
                      szParentName,
                      szGroupName,
                      uiNameSpace,
                      descInsertFunc,
                      bDescsAddable,
                      bvUnmarkedOnCreate),
    _pPrototype      (NULL             ),
    _fPrototypeCreate(fPrototypeCreate ),
    _fInitMethod     (fInitMethod      ),
    _szFcdXML        (szFcdXML         ),
    _szTypeDoc       (szTypeDoc        )
{
    registerType();

    if(fInitMethod != NULL)
        fInitMethod(Static);
}

/*-------------------------------------------------------------------------*/
/*                             Destructor                                  */

FieldBundleType::~FieldBundleType(void)
{
}


bool FieldBundleType::initialize(void)
{
    if(_bInitialized == true)
        return true;

    if(_fInitMethod != NULL)
        _fInitMethod(SystemPre);

    _bInitialized = Inherited::initialize();

    if(_bInitialized == false)
        return false;

    _bInitialized = initPrototype   ();

    if(_bInitialized == false)
        return false;

    if(_fInitMethod != NULL)
        _fInitMethod(SystemPost);

    return _bInitialized;
}

void FieldBundleType::terminate(void)
{
    subRefX(_pPrototype);
}

bool FieldBundleType::initialize(InitPhase ePhase)
{
    if(_fInitMethod != NULL)
        _fInitMethod(ePhase);

    return true;
}

bool FieldBundleType::initPrototype(void)
{
    if(_fPrototypeCreate != NULL && _pPrototype == NULL)
    {
        _pPrototype = _fPrototypeCreate();

        addRefX(_pPrototype);
    }

    return true;
}

void FieldBundleType::registerType(void)
{
    FieldBundleFactory::the()->registerType(this);

    _uiGroupId = FieldBundleFactory::the()->registerGroup(
        _szGroupName.str() != NULL ? _szGroupName.str() : _szName.str());
}

FieldBundleP FieldBundleType::getPrototype(void) const
{
    return _pPrototype;
}


FieldBundleP FieldBundleType::createContainer(void) const
{
    FieldBundleP fp = NilP;

    if(isAbstract() == false)
    {
        fp = _pPrototype->shallowCopy();
    }

    return fp;
}
