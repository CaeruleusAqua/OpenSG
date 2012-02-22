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

#ifndef _OSGCSMWINDOW_H_
#define _OSGCSMWINDOW_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGCSMWindowBase.h"
#include "OSGWindow.h"
#include "OSGCSMViewport.h"

OSG_BEGIN_NAMESPACE

class StatisticsForeground;

/*! \brief CSMWindow class. See \ref
           PageContribCSMCSMWindow for a description.
*/

class RenderAction;
class CSMDrawer;

class OSG_CONTRIBCSM_DLLMAPPING CSMWindow : public CSMWindowBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef CSMWindowBase Inherited;
    typedef CSMWindow     Self;

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         details    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual bool init(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    Real32     getXPos  (void) const;
    Real32     getYPos  (void) const;

    Real32     getXSize (void) const;
    Real32     getYSize (void) const;

    CSMDrawer *getParent(void) const;

    Window    *getWindow(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual Vec2f translateScreenCoordinatesRel  (Real32 rX,
                                                  Real32 rY);

    virtual Vec2i translateGlobalCoordinatesRel  (Real32 rX,
                                                  Real32 rY);

    virtual Vec2i translateGlobalCoordinatesAbs  (Int32  iX,
                                                  Int32  iY);

    virtual Vec2f translateToScreenCoordinatesAbs(Real32 rX,
                                                  Real32 rY);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual FieldContainer *findNamedComponent(const Char8 *szName);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    void queueTask(DrawTask *pTask);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    static UInt32 _extMultiSample;
    static UInt32 _extNVMultiSampleHint;
    static UInt32 FuncIdSampleCoverage;

    // Variables should all be in CSMWindowBase.

    WindowRecPtr            _pWindow;
    StatisticsForeground   *_pStatFG;
    bool                    _bFirstFrame;

    MTouchData::MTouchBlob  _oTouchBlob;
    UInt32                  _uiTouchMode;
    bool                    _bMouseActive;

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    CSMWindow(void);
    CSMWindow(const CSMWindow &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~CSMWindow(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    void reshape            (Int32 w, 
                             Int32 h          );

    void mouse              (Int32 iButton, 
                             Int32 iState,
                             Int32 iModifier,
                             Int32 x,       
                             Int32 y          );

    void motion             (Int32 x, 
                             Int32 y,
                             Int32 iModifier  );

    void addMTouchCursor    (Int32  iCursorId,
                             Int32  x,
                             Int32  y,
                             UInt32 uiCoordSys);

    void updateMTouchCursor (Int32  iCursorId,
                             Int32  x,
                             Int32  y,
                             UInt32 uiCoordSys);

    void removeMTouchCursor (Int32  iCursorId );
    void commitMTouchCursors(void             );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    void render             (RenderAction *pAction);

    void frameRenderNoFinish(RenderAction *pAction);
    void frameFinish        (void                 );
    void frameExit          (void                 );

    void postSync           (void                 );

    void shutdown           (void                 );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    virtual void terminateGLContext(void) = 0;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    bool requestStereoVisual(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class CSMWindowBase;
    friend class CSMDrawer;
    friend class CSMViewport;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const CSMWindow &source);
};

typedef CSMWindow *CSMWindowP;

OSG_END_NAMESPACE

#include "OSGCSMWindowBase.inl"
#include "OSGCSMWindow.inl"

#endif /* _OSGCSMWINDOW_H_ */
