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
#include "AppDraftGui.h"
#include "Workbench.h"
#include "Commands.h"

#include "Base/Console.h"
#include "Base/PyObjectBase.h"

#include "Gui/Application.h"

//using namespace DraftGui;

// TODO: rename back to Draft when done
namespace DraftGui {

Module::Module():Py::ExtensionModule<Module>("Draft2Gui")
{
    initialize("This module is the DraftGui module.");  // register with Python
    initModule();
}

Module::~Module(){}

void Module::initModule()
{
    DraftGui::Workbench::init();

    createCommands();
}

void Module::createCommands()
{
    Gui::CommandManager &commandManager = Gui::Application::Instance->commandManager();
    commandManager.addCommand(new CmdDraftMakeLine);
    commandManager.addCommand(new CmdDraftMakeWire);

}

// namespace DraftGui {

    PyObject* initModule()
    {
        return (new Module)->module().ptr();
    }

}



PyMOD_INIT_FUNC(Draft2Gui)
{
    if (!Gui::Application::Instance) {
        PyErr_SetString(PyExc_ImportError, "Cannot load Draft Gui module in console application.");
        PyMOD_Return(0);
    }
//
//    // load needed modules
//    try {
//        Base::Interpreter().runString("import Part");
//    }
//    catch (const Base::Exception& e) {
//        PyErr_SetString(PyExc_ImportError, e.what());
//        PyMOD_Return(0);
//    }

      PyObject* draftGuiModule = DraftGui::initModule();

    Base::Console().Log("Loading GUI of Draft module... done\n");

//#if PY_MAJOR_VERSION >= 3
//    static struct PyModuleDef pAttachEngineTextsModuleDef = { PyModuleDef_HEAD_INIT, "AttachEngineResources", "AttachEngineResources", -1, 0 };
//    PyObject* pAttachEngineTextsModule = PyModule_Create(&pAttachEngineTextsModuleDef);
//#else
//    PyObject* pAttachEngineTextsModule = Py_InitModule3("AttachEngineResources", AttacherGui::AttacherGuiPy::Methods,
//        "AttachEngine Gui resources");
//#endif
//
//    Py_INCREF(pAttachEngineTextsModule);
//    PyModule_AddObject(partGuiModule, "AttachEngineResources", pAttachEngineTextsModule);
//
//    PartGui::SoBrepFaceSet::initClass();
//    PartGui::SoBrepEdgeSet::initClass();
//    PartGui::SoBrepPointSet::initClass();
//    PartGui::SoFCControlPoints::initClass();
//    PartGui::ViewProviderPartExt::init();
//    PartGui::ViewProviderPart::init();
//    PartGui::ViewProviderEllipsoid::init();
//    PartGui::ViewProviderPython::init();
//    PartGui::ViewProviderBox::init();
//    PartGui::ViewProviderPrism::init();
//    PartGui::ViewProviderRegularPolygon::init();
//    PartGui::ViewProviderWedge::init();
//    PartGui::ViewProviderImport::init();
//    PartGui::ViewProviderCurveNet::init();
//    PartGui::ViewProviderExtrusion::init();
//    PartGui::ViewProvider2DObject::init();
//    PartGui::ViewProvider2DObjectPython::init();
//    PartGui::ViewProviderMirror::init();
//    PartGui::ViewProviderFillet::init();
//    PartGui::ViewProviderChamfer::init();
//    PartGui::ViewProviderRevolution::init();
//    PartGui::ViewProviderLoft::init();
//    PartGui::ViewProviderSweep::init();
//    PartGui::ViewProviderOffset::init();
//    PartGui::ViewProviderOffset2D::init();
//    PartGui::ViewProviderThickness::init();
//    PartGui::ViewProviderCustom::init();
//    PartGui::ViewProviderCustomPython::init();
//    PartGui::ViewProviderBoolean::init();
//    PartGui::ViewProviderMultiFuse::init();
//    PartGui::ViewProviderMultiCommon::init();
//    PartGui::ViewProviderCompound::init();
//    PartGui::ViewProviderSpline::init();
//    PartGui::ViewProviderCircleParametric::init();
//    PartGui::ViewProviderLineParametric::init();
//    PartGui::ViewProviderPointParametric::init();
//    PartGui::ViewProviderEllipseParametric::init();
//    PartGui::ViewProviderHelixParametric::init();
//    PartGui::ViewProviderSpiralParametric::init();
//    PartGui::ViewProviderPlaneParametric::init();
//    PartGui::ViewProviderSphereParametric::init();
//    PartGui::ViewProviderCylinderParametric::init();
//    PartGui::ViewProviderConeParametric::init();
//    PartGui::ViewProviderTorusParametric::init();
//    PartGui::ViewProviderRuledSurface::init();
//    PartGui::ViewProviderFace::init();
//    PartGui::DimensionLinear::initClass();
//    PartGui::DimensionAngular::initClass();
//    PartGui::ArcEngine::initClass();
//
//      DraftGui::Workbench::init();
//
//    // instantiating the commands
//    CreatePartCommands();
//    CreateSimplePartCommands();
//    CreateParamPartCommands();
//    try{
//        Py::Object ae = Base::Interpreter().runStringObject("__import__('AttachmentEditor.Commands').Commands");
//        Py::Module(partGuiModule).setAttr(std::string("AttachmentEditor"), ae);
//    }
//    catch (Base::PyException &err){
//        err.ReportException();
//    }
//
//
//    // register preferences pages
//    (void)new Gui::PrefPageProducer<PartGui::DlgSettingsGeneral>(QT_TRANSLATE_NOOP("QObject", "Part design"));
//    (void)new Gui::PrefPageProducer<PartGui::DlgSettings3DViewPart>(QT_TRANSLATE_NOOP("QObject", "Part design"));
//    (void)new Gui::PrefPageProducer<PartGui::DlgImportExportIges>(QT_TRANSLATE_NOOP("QObject", "Import-Export"));
//    (void)new Gui::PrefPageProducer<PartGui::DlgImportExportStep>(QT_TRANSLATE_NOOP("QObject", "Import-Export"));
//    (void)new Gui::PrefPageProducer<PartGui::DlgSettingsObjectColor>(QT_TRANSLATE_NOOP("QObject", "Display"));
//    Gui::ViewProviderBuilder::add(
//        Part::PropertyPartShape::getClassTypeId(),
//        PartGui::ViewProviderPart::getClassTypeId());
//
//    // add resources and reloads the translators
//    loadPartResource();
//
//    // register bitmaps
//    Gui::BitmapFactoryInst& rclBmpFactory = Gui::BitmapFactory();
//    rclBmpFactory.addXPM("PartFeature", (const char**)PartFeature_xpm);
//    rclBmpFactory.addXPM("PartFeatureImport", (const char**)PartFeatureImport_xpm);

    PyMOD_Return(draftGuiModule);
}
