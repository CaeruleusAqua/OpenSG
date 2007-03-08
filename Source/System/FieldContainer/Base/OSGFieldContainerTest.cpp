/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *                  Copyright (C) 2006 by the OpenSG Forum                   *
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

#include <UnitTest++.h>

#include <OpenSG/OSGFieldContainer.h>
#include <OpenSG/OSGNode.h>
#include <OpenSG/OSGNodeCore.h>

#include <iostream>
#include <string>
#include <vector>

SUITE(FieldContainerTests)
{

TEST(appendTypesVector)
{
    std::vector<std::string>                     typeNames;
    std::vector<const OSG::FieldContainerType *> types;

    typeNames.push_back("Node");
    typeNames.push_back("NodeCore");
    typeNames.push_back("FieldContainer");

    OSG::appendTypesVector(typeNames, types);

    CHECK_EQUAL(types.size(), 3);
    CHECK(OSG::osgStringCmp(types[0]->getCName(),
                            OSG::Node::getClassType().getCName()          ) == 0);
    CHECK(OSG::osgStringCmp(types[1]->getCName(),
                            OSG::NodeCore::getClassType().getCName()      ) == 0);
    CHECK(OSG::osgStringCmp(types[2]->getCName(),
                            OSG::FieldContainer::getClassType().getCName()) == 0);
}

TEST(appendGroupsVector)
{
    std::vector<std::string> groupNames;
    std::vector<OSG::UInt16> groups;

    groupNames.push_back("Node");
    groupNames.push_back("NodeCores");
    groupNames.push_back("FieldContainer");

    OSG::appendGroupsVector(groupNames, groups);

    CHECK_EQUAL(groups.size(), 3);
    CHECK_EQUAL(groups[0], OSG::Node::getClassGroupId());
    CHECK_EQUAL(groups[1], OSG::NodeCore::getClassGroupId());
    CHECK_EQUAL(groups[2], OSG::FieldContainer::getClassGroupId());
}

TEST(appendTypesString)
{
    std::string                                  typesString;
    std::vector<const OSG::FieldContainerType *> types;

    typesString.assign("Node, NodeCore,FieldContainer");

    OSG::appendTypesString(typesString, types);

    CHECK_EQUAL(types.size(), 3);
    CHECK(OSG::osgStringCmp(types[0]->getCName(),
                            OSG::Node::getClassType().getCName()          ) == 0);
    CHECK(OSG::osgStringCmp(types[1]->getCName(),
                            OSG::NodeCore::getClassType().getCName()      ) == 0);
    CHECK(OSG::osgStringCmp(types[2]->getCName(),
                            OSG::FieldContainer::getClassType().getCName()) == 0);

    typesString.assign("Node");
    types.clear();

    OSG::appendTypesString(typesString, types);

    CHECK_EQUAL(types.size(), 1);
    CHECK(OSG::osgStringCmp(types[0]->getCName(),
                            OSG::Node::getClassType().getCName()) == 0);
}

TEST(checkMemoryCleanup)
{
   // Check to make sure the memory is cleaned up correctly with an FCPtr
   OSG::NodeRefPtr  node(OSG::Node::create());
   OSG::UInt32   node_id   = node.get().getId();
   OSG::Int32    ref_count = node.get().getRefCount();
   OSG::commitChanges();
   CHECK(OSG::FieldContainerFactory::the()->getContainer(node_id) != OSG::NullFC);

   // Now release the ref and check that it was collected
   node = OSG::NullFC;
   OSG::commitChanges();
   CHECK(OSG::FieldContainerFactory::the()->getContainer(node_id) == OSG::NullFC);
}

} // SUITE
