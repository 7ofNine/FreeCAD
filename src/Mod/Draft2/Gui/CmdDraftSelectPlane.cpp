/***************************************************************************
 *   Copyright (c) 2017 Hartmuth Gutsche <hartmuthgutsche[at]gmail.com>    *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/
#include "Commands.h"

#include "QGlobalStatic"


// Utilility command 

namespace Draft2Gui {

    CmdDraftSelectPlane::CmdDraftSelectPlane(): Command("Draft_SelectPlane")
    {
        sAppModule = "Draft";
        sGroup = QT_TRANSLATE_NOOP("Draft_Gui", "Draft");
        sMenuText = QT_TRANSLATE_NOOP("Draft_Gui", "Select Plane");
        sToolTipText = QT_TRANSLATE_NOOP("Draft_Gui", "Select a working plane for geomtery creation");
        sWhatsThis = getName();
        sStatusTip = sToolTipText;
        sPixmap = "Draft_SelectPlane";
        sAccel = "W, P";
    }
    
    bool CmdDraftSelectPlane::isActive()
    {
        return hasActiveDocument();
    }


    void CmdDraftSelectPlane::activated(int)
    {
    
    }

}
