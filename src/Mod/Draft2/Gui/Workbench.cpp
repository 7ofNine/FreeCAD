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
#include "Workbench.h"

#include "Gui/MenuManager.h"
#include "Gui/ToolBarManager.h"

using namespace DraftGui;


/// @namespace DraftGui @class Workbench
TYPESYSTEM_SOURCE(DraftGui::Workbench, Gui::StdWorkbench)


Workbench::Workbench(){}

Workbench::~Workbench(){}


Gui::MenuItem* Workbench::setupMenuBar() const
{
    Gui::MenuItem* const root = StdWorkbench::setupMenuBar();
    Gui::MenuItem* const item = root->findItem("&Windows");

    Gui::MenuItem * draft = new Gui::MenuItem;

    draft->setCommand("&Draft");
    *draft << "Draft_MakeLine"
           << "Draft_MakeWire";

    root->insertItem(item, draft);
    return root;
}

Gui::ToolBarItem*  Workbench::setupToolBars() const
{
    Gui::ToolBarItem* const root = StdWorkbench::setupToolBars();

    Gui::ToolBarItem* const draftTools = new Gui::ToolBarItem(root);
    draftTools->setCommand("Draft Tools");

    *draftTools << "Draft_MakeLine"
                << "Draft_MakeWire";

    return root;
}

Gui::ToolBarItem*  Workbench::setupCommandBars() const
{
    return NULL;
}

