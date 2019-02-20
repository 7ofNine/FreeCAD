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

#ifndef DRAFT_COMMANDS_H
#define DRAFT_COMMANDS_H

#include "config.h"

#include "Gui/Command.h"

namespace Draft2Gui {

    DEF_STD_CMD_A(CmdDraftSelectPlane)

    // standard creation commands
    DEF_STD_CMD_A(CmdDraftMakeLine);
    DEF_STD_CMD_A(CmdDraftMakeWire);
    DEF_STD_CMD_A(CmdDraftBSpline);
    DEF_STD_CMD_A(CmdDraftCircle);
    DEF_STD_CMD_A(CmdDraftEllipse);
    DEF_STD_CMD_A(cmdDraftArc);
    DEF_STD_CMD_A(CmdDraftPolygon);
    DEF_STD_CMD_A(CmdDraftRectangle);
}
#endif