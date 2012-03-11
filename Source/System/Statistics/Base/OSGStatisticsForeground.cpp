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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include "OSGStatisticsForeground.h"

OSG_USING_NAMESPACE

// Documentation for this class is emited in the
// OSGStatisticsForegroundBase.cpp file.
// To modify it, please change the .fcd file (OSGStatisticsForeground.fcd) and
// regenerate the base file.

/*----------------------- constructors & destructors ----------------------*/

StatisticsForeground::StatisticsForeground(void) :
    Inherited()
{
}

StatisticsForeground::StatisticsForeground(const StatisticsForeground &source) :
    Inherited(source)
{
}

StatisticsForeground::~StatisticsForeground(void)
{
}

/*----------------------------- class specific ----------------------------*/

void StatisticsForeground::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);
}

void StatisticsForeground::onCreateAspect(
    const StatisticsForeground *createAspect,
    const StatisticsForeground *source)
{
    Inherited::onCreateAspect(createAspect, source);

    // Avoid prototype
    if(GlobalSystemState == Running)
    {
        StatCollectorP pColl = new StatCollector;

        addRef(pColl);

        _sfCollector.setValue(pColl);
    }
}

void StatisticsForeground::onDestroyAspect(UInt32 uiContainerId,
                                           UInt32 uiAspect     )
{
    subRef(_sfCollector.getValue());

    _sfCollector.setValue(NULL);

    Inherited::onDestroyAspect(uiContainerId, uiAspect);
}

void StatisticsForeground::changed(ConstFieldMaskArg whichField, 
                                   UInt32            origin,
                                   BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void StatisticsForeground::dump(      UInt32    ,
                                const BitVector ) const
{
    SLOG << "Dump StatisticsForeground NI" << std::endl;
}

