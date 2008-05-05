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


#ifndef _OSGMATERIALMERGEGRAPHOP_H_
#define _OSGMATERIALMERGEGRAPHOP_H_
#ifdef __sgi
#pragma once
#endif

#include <list>
#include <map>

#include "OSGGraphOp.h"
#include "OSGAction.h"
#include "OSGGeometry.h"
#include "OSGMaterialGroup.h"

OSG_BEGIN_NAMESPACE

class OSG_UTIL_DLLMAPPING MaterialMergeGraphOp : public GraphOp
{
public:
    class MaterialObject
    {
    public:
        MaterialObject(Geometry *geo)
        {
            _geo = geo;
        }

        MaterialObject(MaterialGroup *mg)
        {
            _mg = mg;
        }

        Material *getMaterial() {
            return (_geo != NULL
                    ? _geo->getMaterial()
                    : _mg->getMaterial());
        }

        void setMaterial(Material *mat) {
            if (_geo != NULL)
            {
                _geo->setMaterial(mat);
            }
            else
            {
                _mg->setMaterial(mat);
            }
        }

    private:
        Geometry      *_geo;
        MaterialGroup *_mg;
    };

    static const char *getClassname(void) { return "MaterialMergeGraphOp"; };

    MaterialMergeGraphOp(const char* name = "MaterialMerge");

    GraphOp* create();

    bool traverse(Node *node);

    void setParams(const std::string params);
    
    std::string usage(void);

protected:
    virtual ~MaterialMergeGraphOp(void);

private:
    Action::ResultE traverseEnter(Node * const node);
    Action::ResultE traverseLeave(Node * const node, Action::ResultE res);

    void addObject(MaterialObject m);

    typedef std::list<MaterialObject> MaterialObjectList;
    typedef std::map<Material *, MaterialObjectList> MaterialObjectMap;

    MaterialObjectMap _materialObjects;
};

OSG_END_NAMESPACE

#endif /* _OSGMERGEGRAPHOP_H_ */
