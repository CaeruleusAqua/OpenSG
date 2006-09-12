
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


/***************************************************************************\
*                             Includes                                    *
\***************************************************************************/

#include <boost/bind.hpp>

#include "OSGMergeGraphOp.h"
#include "OSGDirectionalLight.h"
#include "OSGSpotLight.h"
#include "OSGLight.h"
#include "OSGPointLight.h"
#include "OSGSwitch.h"
#include "OSGDistanceLOD.h"
#include "OSGBillboard.h"
#include "OSGMaterialGroup.h"
#include "OSGComponentTransform.h"
#include "OSGPrimitiveIterator.h"
#include "OSGGeometry.h"
#include "OSGGeoFunctions.h"

// need to implement the merge methods amz
#define OSG2_MERGE_MISSING

OSG_USING_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::MergeGraphOp
    \ingroup GrpSystemNodeCoresDrawablesGeometry
    
A class used to optimize geometries a bit.

*/

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  public                                                                 -
\*-------------------------------------------------------------------------*/


/*------------- constructors & destructors --------------------------------*/

MergeGraphOp::MergeGraphOp(const char* name): GraphOp(name),
    _secondary_color_is_vector(false),
    _texcoord0_is_vector(false),
    _texcoord1_is_vector(false),
    _texcoord2_is_vector(false),
    _texcoord3_is_vector(false)
{
}

MergeGraphOp::~MergeGraphOp(void)
{
}

GraphOp* MergeGraphOp::create()
{
    MergeGraphOp* inst = new MergeGraphOp();
    return inst;
}

UInt32 countNodes(const NodePtr& node)
{
    if (node == NullFC)
        return 0;

    UInt32 total = 1;
    for (UInt32 i = 0; i < node->getNChildren(); ++i)
        total += countNodes(node->getChild(i));
    return total;
}

bool MergeGraphOp::traverse(NodePtr& node)
{
    // This is a hack and should be treated as such.
    // The fact that it helps means there is something wrong with
    // the merger. FIXME!!!
    UInt32 next = countNodes(node);
    SINFO << "MergeGraphOp::traverse: Number of nodes before merge: " 
          << next << endLog;
    bool result = true;
    UInt32 current;
    do {
        current = next;
        result &= mergeOnce(node);
        if (!result)
            break;
        next = countNodes(node);
    } while (next < current);

    SINFO << "MergeGraphOp::traverse: Number of nodes after merge: " 
          << current << endLog;

    return result;
}

void MergeGraphOp::setParams(const std::string params)
{
    ParamSet ps(params);   

    ps("color_is_vector", _color_is_vector);
    ps("secondary_color_is_vector", _secondary_color_is_vector);
    ps("texcoord_is_vector", _texcoord0_is_vector);
    ps("texcoord0_is_vector", _texcoord0_is_vector);
    ps("texcoord1_is_vector", _texcoord1_is_vector);
    ps("texcoord2_is_vector", _texcoord2_is_vector);
    ps("texcoord3_is_vector", _texcoord3_is_vector);

    std::string out = ps.getUnusedParams();
    if(out.length())
    {
        FWARNING(("MergeGraphOp doesn't have parameters '%s'.\n",
                out.c_str()));
    }
}

std::string MergeGraphOp::usage(void)
{
    return 
    "Merge: merge all geometries in a subtree\n"
    "  Tries to merge all Geometries in a subtree into the minimal number.\n"
    "  of Nodes. Flattens Transformations and transforms indices on the way.\n"
    "Params: name (type, default)\n"
    " (The following params are useful for transforming tangent space vectors.)\n"
    "  color_is_vector  (bool, false): transform color as if it were a normal\n"
    "  secondary_color_is_vector  (bool, false): transform secondary color as if it were a normal\n"
    "  texcoord_is_vector  (bool, false): transform texcoord0 as if it were a normal\n"
    "  texcoord0_is_vector  (bool, false): transform texcoord0 as if it were a normal\n"
    "  texcoord1_is_vector  (bool, false): transform texcoord1 as if it were a normal\n"
    "  texcoord2_is_vector  (bool, false): transform texcoord2 as if it were a normal\n"
    "  texcoord3_is_vector  (bool, false): transform texcoord3 as if it were a normal\n"
    ;
}

/*-------------------------------------------------------------------------*\
 -  private                                                                -
\*-------------------------------------------------------------------------*/

bool MergeGraphOp::mergeOnce(NodePtr& node)
{
    std::list<NodeConstPtr> tempList;
    tempList.clear();
    tempList.splice(tempList.end(),_excludeListNodes);
    makeExcludeList(node);
    bool result = GraphOp::traverse(node);
    _excludeListNodes.clear();    
    _excludeListNodes.splice(_excludeListNodes.end(),tempList);
    return result;
}

void MergeGraphOp::makeExcludeList(NodePtr& node)
{
    /*
    ::traverse(node,
        osgTypedMethodFunctor1ObjPtrCPtrRef<Action::ResultE,
        MergeGraphOp,
        NodePtr>(this,&MergeGraphOp::excludeListEnter),
        osgTypedMethodFunctor2ObjPtrCPtrRef<Action::ResultE,
        MergeGraphOp,
        NodePtr,
        Action::ResultE>(this,&MergeGraphOp::excludeListLeave));
    */
    ::traverse(node, 
               boost::bind(&MergeGraphOp::excludeListEnter, this, _1    ),
               boost::bind(&MergeGraphOp::excludeListLeave, this, _1, _2) );
}


Action::ResultE MergeGraphOp::excludeListEnter(NodePtrConstArg node)
{
    if (node==NullFC) ; else ;    
    return Action::Continue;
}

Action::ResultE MergeGraphOp::excludeListLeave(NodePtrConstArg node, Action::ResultE res)
{
    DirectionalLightPtr dlight = cast_dynamic<DirectionalLightPtr>(node->getCore());
    if (dlight!=NullFC)
        addToExcludeList(dlight->getBeacon());
    
    LightPtr light = cast_dynamic<LightPtr>(node->getCore());
    if (light!=NullFC)
        addToExcludeList(light->getBeacon());    
    
    PointLightPtr plight = cast_dynamic<PointLightPtr>(node->getCore());
    if (plight!=NullFC)
        addToExcludeList(plight->getBeacon());
    
    SpotLightPtr slight = cast_dynamic<SpotLightPtr>(node->getCore());
    if (slight!=NullFC)
        addToExcludeList(slight->getBeacon());    
    
    return res;
}

Action::ResultE MergeGraphOp::traverseEnter(NodePtrConstArg node)
{
    SwitchPtr switch_ = cast_dynamic<SwitchPtr>(node->getCore());
    if (switch_!=NullFC) return Action::Skip;
    
    DistanceLODPtr dlod = cast_dynamic<DistanceLODPtr>(node->getCore());
    if (dlod!=NullFC) return Action::Skip;
    
    //leaf, don't enter, cause no job here
    if (isLeaf(node)) return Action::Skip;
    
    return Action::Continue;    
}

Action::ResultE MergeGraphOp::traverseLeave(NodePtrConstArg node, Action::ResultE res)
{
    processGroups(node);
    processTransformations(node);
    processGeometries(node);
    return res;
}

bool MergeGraphOp::isLeaf(NodePtrConst node)
{
    if (node->getMFChildren()->getValues().begin()==
        node->getMFChildren()->getValues().end()) return true;
    else return false;    
}

/*! checks whether a node is a group and nothing else
*/
bool MergeGraphOp::isGroup(NodePtrConst node)
{
    if(  node->getCore()->getType().isDerivedFrom( Group::getClassType()              ) &&
        !node->getCore()->getType().isDerivedFrom( Transform::getClassType()          ) &&
        !node->getCore()->getType().isDerivedFrom( ComponentTransform::getClassType() ) &&
        !node->getCore()->getType().isDerivedFrom( Switch::getClassType()             ) &&
        !node->getCore()->getType().isDerivedFrom( MaterialGroup::getClassType()      ) &&
        !node->getCore()->getType().isDerivedFrom( DistanceLOD::getClassType()        ) &&
        !node->getCore()->getType().isDerivedFrom( Billboard::getClassType()          )) 
        return true;
    else return false;
}

void MergeGraphOp::processGroups(NodePtrConst node)
{
    std::vector<NodePtr>::const_iterator it = node->getMFChildren()->getValues().begin();
    std::vector<NodePtr>::const_iterator en = node->getMFChildren()->getValues().end  ();
    std::vector<NodePtr> toAdd;
    std::vector<NodePtr> toSub;
    
    for ( ; it != en; ++it )
    {
        bool special=isInExcludeList(*it);
        bool leaf=isLeaf(*it);
        
        if (isGroup(*it))
        {
            if (!leaf && !special)
            {
                std::vector<NodePtr>::const_iterator it2 = (*it)->getMFChildren()->getValues().begin();
                std::vector<NodePtr>::const_iterator en2 = (*it)->getMFChildren()->getValues().end  ();
                
                for ( ; it2 != en2; ++it2 )
                {
                    toAdd.push_back(*it2);
                }                
            }
            
            if (!special)
            {
                toSub.push_back(*it);
                continue;
            }
            
            if (leaf && special)
            {
                //what to do?
            }
            if (!leaf && special)
            {
                //what to do?
            }
            continue;
        }
        else if ((*it)->getCore()->getType().isDerivedFrom( MaterialGroup::getClassType() ))
        {
            MaterialGroupPtr mg = cast_dynamic<MaterialGroupPtr>((*it)->getCore());
            
            std::vector<NodePtr>::const_iterator it2 = (*it)->getMFChildren()->getValues().begin();
            std::vector<NodePtr>::const_iterator en2 = (*it)->getMFChildren()->getValues().end  ();
            
            bool empty=true;
            
            for ( ; it2 != en2; ++it2 )
            {
                if (!isInExcludeList(*it2))
                {
                    //check if geometry
                    if ((*it2)->getCore()->getType().isDerivedFrom(Geometry::getClassType()))
                    {
                        if(!isLeaf(*it2))
                        {
                            //hmm...bad tree...
                            empty=false;
                        }
                        else
                        {                                
                            //it is a leaf geometry, so apply the transformation
                            GeometryPtr geo = cast_dynamic<GeometryPtr>((*it2)->getCore());
                            geo->setMaterial(mg->getMaterial());
                            toAdd.push_back(*it2);                            
                        }
                    } else empty=false;
                } else empty=false;                
            }
            
            if (empty) toSub.push_back(*it);
            
        }
    }
    
    it = toAdd.begin();
    en = toAdd.end  ();
    
    for ( ; it != en; ++it )
    {
        node->addChild(*it);
    }
    
    it = toSub.begin();
    en = toSub.end  ();
    
    for ( ; it != en; ++it )
    {
        node->subChild(*it);
    }
}

void MergeGraphOp::processTransformations(NodePtrConst node)
{
    std::vector<NodePtr>::const_iterator it = node->getMFChildren()->getValues().begin();
    std::vector<NodePtr>::const_iterator en = node->getMFChildren()->getValues().end  ();
    std::vector<NodePtr> toAdd;
    std::vector<NodePtr> toSub;
    
    for ( ; it != en; ++it )
    {
        bool special=isInExcludeList(*it);
        bool leaf=isLeaf(*it);
        bool empty=true;
        
        //if a transformation:
        if ((*it)->getCore()->getType().isDerivedFrom(Transform::getClassType()))
        {        
            if (!leaf && !special)
            {
                //try to apply it to children geometries
                //move all "moveable" children one level up
                //if empty after that, delete it
                std::vector<NodePtr>::const_iterator it2 = (*it)->getMFChildren()->getValues().begin();
                std::vector<NodePtr>::const_iterator en2 = (*it)->getMFChildren()->getValues().end  ();
                
                for ( ; it2 != en2; ++it2 )
                {
                    if (!isInExcludeList(*it2))
                    {
                        //check if geometry
                        if ((*it2)->getCore()->getType().isDerivedFrom(Geometry::getClassType()))
                        {
                            if(!isLeaf(*it2))
                            {
                                //hmm...bad tree...
                                empty=false;
                            }
                            else
                            {                                
                                //it is a leaf geometry, so apply the transformation
                                GeometryPtr geo_old = cast_dynamic<GeometryPtr>((*it2)->getCore());
                                //GeometryPtr geo = geo_old->clone();
                                GeometryPtr geo = cast_dynamic<GeometryPtr>(OSG::deepClone(geo_old, "Material"));
                                TransformPtr  t = cast_dynamic<TransformPtr>((*it)->getCore());
                                GeoPnt3fPropertyPtr pos  = cast_dynamic<GeoPnt3fPropertyPtr>(geo->getPositions());
                                GeoVec3fPropertyPtr   norm = cast_dynamic<GeoVec3fPropertyPtr>(geo->getNormals());
                                GeoColor3fPropertyPtr color = cast_dynamic<GeoColor3fPropertyPtr>(geo->getColors());
                                GeoColor3fPropertyPtr scolor = cast_dynamic<GeoColor3fPropertyPtr>(geo->getSecondaryColors());
                                GeoVec3fPropertyPtr texcoord0 = cast_dynamic<GeoVec3fPropertyPtr>(geo->getTexCoords());
                                GeoVec3fPropertyPtr texcoord1 = cast_dynamic<GeoVec3fPropertyPtr>(geo->getTexCoords1());
                                GeoVec3fPropertyPtr texcoord2 = cast_dynamic<GeoVec3fPropertyPtr>(geo->getTexCoords2());
                                GeoVec3fPropertyPtr texcoord3 = cast_dynamic<GeoVec3fPropertyPtr>(geo->getTexCoords3());
                                Matrix m=t->getMatrix();
                                if (pos!=NullFC) 
                                {
                                    for (UInt32 i=0; i<pos->getSize(); i++)
                                    {
                                        Pnt3f p=pos->getValue(i);
                                        m.multFullMatrixPnt(p);
                                        pos->setValue(p,i);
                                    }
                                }
                                
                                if (norm!=NullFC)
                                {
                                    for (UInt32 i=0; i<norm->getSize(); i++)
                                    {
                                        Vec3f n=norm->getValue(i);
                                        m.multMatrixVec(n);
                                        n.normalize();
                                        norm->setValue(n,i);
                                    }
                                }

                                if (color!=NullFC && _color_is_vector)
                                {
                                    for (UInt32 i=0; i<color->getSize(); i++)
                                    {
                                        Color3f c = color->getValue(i);
                                        Vec3f v;
                                        v.setValue(c.getValuesRGB());
                                        m.multMatrixVec(v);
                                        v.normalize();
                                        c.setValuesRGB(v[0], v[1], v[2]);
                                        color->setValue(c,i);
                                    }
                                }

                                if (scolor!=NullFC && _secondary_color_is_vector)
                                {
                                    for (UInt32 i=0; i<scolor->getSize(); i++)
                                    {
                                        Color3f c = scolor->getValue(i);
                                        Vec3f v;
                                        v.setValue(c.getValuesRGB());
                                        m.multMatrixVec(v);
                                        v.normalize();
                                        c.setValuesRGB(v[0], v[1], v[2]);
                                        scolor->setValue(c,i);
                                    }
                                }

                                if (texcoord0!=NullFC && _texcoord0_is_vector)
                                {
                                    for (UInt32 i=0; i<texcoord0->getSize(); i++)
                                    {
                                        Vec3f v=texcoord0->getValue(i);
                                        m.multMatrixVec(v);
                                        v.normalize();
                                        texcoord0->setValue(v,i);
                                    }
                                }

                                if (texcoord1!=NullFC && _texcoord1_is_vector)
                                {
                                    for (UInt32 i=0; i<texcoord1->getSize(); i++)
                                    {
                                        Vec3f v=texcoord1->getValue(i);
                                        m.multMatrixVec(v);
                                        v.normalize();
                                        texcoord1->setValue(v,i);
                                    }
                                }

                                if (texcoord2!=NullFC && _texcoord2_is_vector)
                                {
                                    for (UInt32 i=0; i<texcoord2->getSize(); i++)
                                    {
                                        Vec3f v=texcoord2->getValue(i);
                                        m.multMatrixVec(v);
                                        v.normalize();
                                        texcoord2->setValue(v,i);
                                    }
                                }

                                if (texcoord3!=NullFC && _texcoord3_is_vector)
                                {
                                    for (UInt32 i=0; i<texcoord3->getSize(); i++)
                                    {
                                        Vec3f v=texcoord3->getValue(i);
                                        m.multMatrixVec(v);
                                        v.normalize();
                                        texcoord3->setValue(v,i);
                                    }
                                }
                                (*it2)->setCore(geo);
                                toAdd.push_back(*it2);
                            }
                        } else empty=false;
                    } else empty=false;
                }                
            }
            
            //now check whether we have to remove it
            if ((empty||leaf) && !special)
            {
                toSub.push_back(*it);
                continue;
            }
            
            if (leaf && special)
            {
                //what to do?
            }
            if (!leaf && special)
            {
                //what to do?
            }
            continue;
        }
    }
    
    it = toAdd.begin();
    en = toAdd.end  ();
    
    for ( ; it != en; ++it )
    {
        node->addChild(*it);
    }
    
    it = toSub.begin();
    en = toSub.end  ();
    
    for ( ; it != en; ++it )
    {
        node->subChild(*it);
    }
}

void MergeGraphOp::processGeometries(NodePtrConst node)
{
    std::vector<NodePtr>::const_iterator it = node->getMFChildren()->getValues().begin();
    std::vector<NodePtr>::const_iterator en = node->getMFChildren()->getValues().end  ();
    std::vector<NodePtr> toSub;
    std::vector<NodePtr> toAdd;
    
    for ( ; it != en; ++it )
    {
        bool special=isInExcludeList(*it);
        
        if ((*it)->getCore()->getType().isDerivedFrom(Geometry::getClassType()))
        {
            GeometryPtr geo = cast_dynamic<GeometryPtr>((*it)->getCore());
            //if a geometry, try to merge it in another geometry
            //if successfull, delete it.
            //check also if it is added for exclusion

            bool inSubList=false;

            std::vector<NodePtr>::const_iterator it3=toSub.begin();
            std::vector<NodePtr>::const_iterator en3=toSub.end();

            for ( ; it3 != en3; ++it3 ) 
                if (*it3==*it) { inSubList=true; break; }

            if (!special && !inSubList)
            {
                //ok, try
                std::vector<NodePtr>::const_iterator it2=it+1;
                GeometryPtr new_geo=NullFC;
                for ( ; it2!=en; ++it2)
                {
                    if (!isInExcludeList(*it2) && (*it2)->getCore()->getType().isDerivedFrom(Geometry::getClassType()))
                    {
                        GeometryPtr geo2 = cast_dynamic<GeometryPtr>((*it2)->getCore());
#ifndef OSG2_MERGE_MISSING
                        if (geo->isMergeable(geo2))
                        {
                            // HACK merge crashes when indices == NullFC!
                            if(geo->getIndices() == NullFC)
                                OSG::createSharedIndex(geo);
                            if(geo2->getIndices() == NullFC)
                                OSG::createSharedIndex(geo2);
                            if (new_geo==NullFC)
                            {
                                new_geo=Geometry::create();
                                if (new_geo->merge(geo))
                                    toSub.push_back(*it);
                                else FWARNING(("MergeGraphOp: processGeometries problem 1\n"));

                                if (new_geo->merge(geo2))
                                    toSub.push_back(*it2);
                                else FWARNING(("MergeGraphOp: processGeometries problem 2\n"));
                            }
                            else
                            {
                                if (new_geo->merge(geo2))
                                    toSub.push_back(*it2);
                            }
                        }
#endif
                    }
                }
                if (new_geo!=NullFC)
                {
                    NodePtr new_node=Node::create();
                    new_node->setCore(new_geo);

                    toAdd.push_back(new_node);
                }
            }
            else
            {
                //hmm...have to skip it
            }
        }
    }
    
    it = toAdd.begin();
    en = toAdd.end  ();
    
    for ( ; it != en; ++it )
    {
        node->addChild(*it);
    }

    it = toSub.begin();
    en = toSub.end  ();
    
    for ( ; it != en; ++it )
    {
        node->subChild(*it);
    }
}
