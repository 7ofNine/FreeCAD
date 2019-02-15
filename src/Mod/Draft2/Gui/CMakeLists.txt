
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${QT_INCLUDE_DIR}
	${XercesC_INCLUDE_DIRS}
)


# Gui resources for QT
if (BUILD_QT5)
    qt5_add_resources(Draft2Gui_QRC_SRCS Resources/Draft.qrc)
else()
    qt4_add_resources(Draft2Gui_QRC_SRCS Resources/Draft.qrc)
endif()


# Source files
set(Draft2Gui_SOURCES 
    ${Draft2Gui_QRC_SRCS}   
    Workbench.cpp
    AppDraftGui.cpp
    CmdDraftMakeLine.cpp
    CmdDraftMakeWire.cpp
	CmdDraftSelectPlane.cpp
)

# source_group("Application" FILES ${Draft2Gui_SOURCES})

# Header files
set(Draft2Gui_HEADERS
    config.h
    Workbench.h
    AppDraftGui.h
    Commands.h
    )

source_group("Headers" FILES ${Draft2Gui_HEADERS})

# Scripts
set(Draft2Gui_INIT InitGui.py)    
set(Draft2Gui_SCRIPTS
    ../${Draft2Gui_INIT})

source_group("Scripts" FILES ${Draft2Gui_SCRIPTS})

# temporary: license header
set(Draft2Gui_LICENSE_HEADER Gui.licenseheader)
set(Draft2Gui_LICENSE ../${Draft2Gui_LICENSE_HEADER})


# needed libraries
set(Draft2Gui_LIBS
    FreeCADGui    
)


# define the project
add_library(Draft2Gui SHARED ${Draft2Gui_SOURCES})
target_link_libraries(Draft2Gui ${Draft2Gui_LIBS})
target_sources(Draft2Gui  PRIVATE ${Draft2Gui_HEADERS} PRIVATE ${Draft2Gui_SCRIPTS} PRIVATE ${Draft2Gui_LICENSE} )
SET_PYTHON_PREFIX_SUFFIX(Draft2Gui) # change .dll to .pyd

# set up the target directory for the binaries (dll)
SET_BIN_DIR(Draft2Gui Draft2Gui /Mod/Draft2) # what does that really do ?

INSTALL(TARGETS Draft2Gui DESTINATION ${CMAKE_INSTALL_LIBDIR})


fc_target_copy_resource(Draft2Gui ${CMAKE_SOURCE_DIR}/src/Mod/Draft2 ${CMAKE_BINARY_DIR}/Mod/Draft2 ${Draft2Gui_INIT})

# setup the module icon
SET(DraftGuiIcon_SVG Resources/icons/DraftWorkbench.svg)
fc_copy_sources(Draft2Gui "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_DATADIR}/Mod/Draft2" ${DraftGuiIcon_SVG})
INSTALL(FILES ${DraftGuiIcon_SVG} DESTINATION "${CMAKE_INSTALL_DATADIR}/Mod/Draft2/Resources/icons")


