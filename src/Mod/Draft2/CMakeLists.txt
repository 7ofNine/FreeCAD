add_subdirectory(App)
if(BUILD_GUI)
    add_subdirectory(Gui)
endif(BUILD_GUI)

set(Draft2_Scripts
    Init.py
)
if(BUILD_GUI)
    list(APPEND Draft2_Scripts
                InitGui.py
    )
endif(BUILD_GUI)
    
INSTALL(
       FILES
          ${Draft2_Scripts}
       DESTINATION
          Mod/Draft2
)
   