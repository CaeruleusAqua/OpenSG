/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
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

#include <OSGConfig.h>

#include "OSGChunkOverrideGroup.h"
#include "OSGRenderAction.h"

OSG_BEGIN_NAMESPACE

// Documentation for this class is emitted in the
// OSGChunkOverrideGroupBase.cpp file.
// To modify it, please change the .fcd file (OSGChunkOverrideGroup.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void ChunkOverrideGroup::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
        RenderAction::registerEnterDefault(
            ChunkOverrideGroup::getClassType(), 
            reinterpret_cast<Action::Callback>(
                &ChunkOverrideGroup::renderEnter));

        RenderAction::registerLeaveDefault(
            ChunkOverrideGroup::getClassType(), 
            reinterpret_cast<Action::Callback>(
                &ChunkOverrideGroup::renderLeave));
    }
}


/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

/*----------------------- constructors & destructors ----------------------*/

ChunkOverrideGroup::ChunkOverrideGroup(void) :
    Inherited()
{
}

ChunkOverrideGroup::ChunkOverrideGroup(const ChunkOverrideGroup &source) :
    Inherited(source)
{
}

ChunkOverrideGroup::~ChunkOverrideGroup(void)
{
}

/*----------------------------- class specific ----------------------------*/

bool ChunkOverrideGroup::addChunk(StateChunk *chunk, 
                                  Int32       slot)
{
    if(chunk == NULL)
    {
        SWARNING << "addChunk: no chunk given, use subChunk to clear a slot" 
                 << std::endl;

        return false;
    }

    if(slot > 0 && slot > chunk->getClass()->getNumSlots())
    {
        SWARNING << "addChunk: index " 
                 << slot
                 << " > Numslots "
                 << chunk->getClass()->getNumSlots()
                 << ",  ignored!" 
                 << std::endl;

        return false;
    }

    UInt32 cindex =  chunk->getClassId();
    UInt32 csize  = _mfChunks.size();

    // special case: find empty slot automatically
    if(slot == State::AutoSlot || slot == State::AutoSlotReplace)
    {
        UInt8 nslots = chunk->getClass()->getNumSlots();
        UInt8 ci;

        for(ci = cindex; ci < cindex + nslots && ci < csize; ++ci)
        {
            if(_mfChunks[ci] == NULL)
            {
                break;
            }
        }

        if(ci >= cindex + nslots)    // no free slot found
        {
            if(slot == State::AutoSlot)
            {
                SWARNING << "addChunk: no free slot found for "
                         << chunk->getClass()->getName() 
                         << " class, ignored!" << std::endl;
                return false;
            }
            // use last slot
            --ci;
        }

        cindex = ci;
    }
    else
    {
        cindex += slot;
    }

    editMField(ChunksFieldMask, _mfChunks);

    // add the chunk to the state at cindex
    if(cindex >= csize)
    {
        UInt32 oldsize = csize;
        UInt32 newsize = cindex + 1;

        _mfChunks.resize(newsize);

        for(UInt32 i = oldsize; i < newsize; i++)
        {
            _mfChunks.replace(i, NULL);
        }
    }

    _mfChunks.replace(cindex, chunk);
    
    return true;
}

bool ChunkOverrideGroup::subChunk(StateChunk *chunk, 
                                  Int32       slot)
{
    if(chunk == NULL)
        return false;
        
    UInt32 cindex =  chunk->getClassId();
    UInt32 csize  = _mfChunks.size();

    // special case: find it in the slots
    UInt8 nslots = chunk->getClass()->getNumSlots();
    UInt8 ci;

    if(slot == State::AutoSlot || slot == State::AutoSlotReplace)
    {
        for(ci = cindex; ci < cindex + nslots && ci < csize; ci++)
        {
            if(_mfChunks[ci] == chunk)
            {
                break;
            }
        }
        
        if(ci >= cindex + nslots || ci >= csize)    // chunk not found
        {
            SWARNING << "subChunk: chunk " 
                     << chunk
                     << " of class "
                     << chunk->getClass()->getName()
                     << " not found!" 
                     << std::endl;
            return false;
        }
        
        editMField(ChunksFieldMask, _mfChunks);
        
        // remove the chunk from the state
        
//        subRef(_mfChunks[ci]);
        
//        _mfChunks[ci] = NULL;
        _mfChunks.replace(ci, NULL);
    }
    else
    {
        ci = cindex + slot;

        if(ci    >=  cindex + nslots || 
           ci    >= _mfChunks.size() ||
           chunk != _mfChunks[ci]     )    // chunk not found
        {
            SWARNING << "subChunk: chunk " 
                     << chunk
                     << " of class "
                     << chunk->getClass()->getName()
                     << " not found!" 
                     << std::endl;
            return false;
        }        

        editMField(ChunksFieldMask, _mfChunks);
        
        // remove the chunk from the state
        
//        subRef(_mfChunks[ci]);
        
//        _mfChunks[ci] = NULL;
        _mfChunks.replace(ci, NULL);
    }

    return true;
}

Int32 ChunkOverrideGroup::find(StateChunk *chunk)
{
    UInt32 i;
    
    for(i = 0; i < _mfChunks.size(); ++i)
    {
        if(_mfChunks[i] == chunk)
            return i;
    }
             
    return -1;
}

StateChunk *ChunkOverrideGroup::find(const StateChunkClass &type, 
                                           Int32            slot)
{
    UInt32 cindex =  type.getId();
    UInt32 csize  = _mfChunks.size();

    // special case: find it in the slots
    UInt8 nslots = type.getNumSlots();
    UInt8 ci;

    if(slot == State::AutoSlot || slot == State::AutoSlotReplace)
    {
        for(ci = cindex; ci < cindex + nslots && ci < csize; ci++)
        {
            StateChunk *chunk = _mfChunks[ci];

            if(chunk != NULL && *(chunk->getClass()) == type)
            {
                return chunk;
            }
        }
    }
    else
    {
        ci = cindex + slot;

        if(ci    <  cindex + nslots || 
           ci    < _mfChunks.size()  )    
        {
            StateChunk *chunk = _mfChunks[ci];

            if(chunk != NULL && *(chunk->getClass()) == type)
            {
                return chunk;
            }
        }
    }

    return NULL;
}


void ChunkOverrideGroup::changed(ConstFieldMaskArg whichField, 
                                 UInt32            origin,
                                 BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void ChunkOverrideGroup::dump(      UInt32    ,
                              const BitVector ) const
{
    SLOG << "Dump ChunkOverrideGroup NI" << std::endl;
}

ActionBase::ResultE ChunkOverrideGroup::renderEnter(Action *action)
{
    RenderAction *pAction = 
        dynamic_cast<RenderAction *>(action);

    if(pAction != NULL)
    {
        pAction->pushState();

        MFUnrecStateChunkPtr::const_iterator chIt   = this->beginChunks();
        MFUnrecStateChunkPtr::const_iterator chEnd  = this->endChunks  ();
        UInt32                               uiSlot = 0;

        while(chIt != chEnd)
        {
            if(*chIt != NULL)
                pAction->addOverride(uiSlot, *chIt);
            
            ++uiSlot;
            ++chIt;
        }
    }

    return Inherited::renderEnter(action);
}

ActionBase::ResultE ChunkOverrideGroup::renderLeave(Action *action)
{
    RenderAction *pAction = 
        dynamic_cast<RenderAction *>(action);

    if(pAction != NULL)
    {
        pAction->popState();
    }


    return Inherited::renderLeave(action);
}

OSG_END_NAMESPACE
