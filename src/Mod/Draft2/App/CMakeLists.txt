# set project name. Temporary to be able to easily change it
# SET(GUT_DRAFT_APP "Draft2")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
#	${XercesC_INCLUDE_DIRS}
)

# define source files
set(Draft2_SOURCES    
    empty.cpp
)
SOURCE_GROUP("Application" FILES ${Draft2_SOURCES})

set(Draft2_HEADERS
    empty.h
    )
SOURCE_GROUP("Headers" FILES ${Draft2_HEADERS})    

#scripts 
set(Draft2_INIT Init.py)
set(Draft2_SCRIPTS
    ../${Draft2_INIT})
    
source_group("Scripts" FILES ${Draft2_SCRIPTS})

## define needed libraries
set(Draft2_LIBS
    FreeCADApp
	FreeCADBase
)


# define the project
add_library(Draft2 SHARED ${Draft2_SOURCES})
target_link_libraries(Draft2 ${Draft2_LIBS})
target_sources(Draft2  PRIVATE ${Draft2_HEADERS} PRIVATE ${Draft2_SCRIPTS}) 

# What does this actually do ??
fc_target_copy_resource(Draft2 ${CMAKE_SOURCE_DIR}/src/Mod/Draft2 ${CMAKE_BINARY_DIR}/Mod/Draft2 ${Draft2_INIT})

# set up the target directory for the binaries (dll)
SET_BIN_DIR(Draft2 Draft2 /Mod/Draft2)
# create dll as python extension i.e. *.pyd
SET_PYTHON_PREFIX_SUFFIX(Draft2)

#final destination for the library upon install
INSTALL(TARGETS Draft2 DESTINATION ${CMAKE_INSTALL_LIBDIR} )