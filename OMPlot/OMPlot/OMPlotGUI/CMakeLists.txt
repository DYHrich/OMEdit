set(OMPLOTLIB_SOURCES Plot.cpp
                      PlotZoomer.cpp
                      Legend.cpp
                      PlotPanner.cpp
                      PlotPicker.cpp
                      PlotGrid.cpp
                      PlotCurve.cpp
                      PlotWindow.cpp
                      PlotApplication.cpp
                      PlotWindowContainer.cpp
                      PlotMainWindow.cpp
                      ScaleDraw.cpp
                      LogScaleEngine.cpp
                      LinearScaleEngine.cpp
                      # Add required utility sources with correct paths
                      ${CMAKE_SOURCE_DIR}/OMEdit/OMEditLIB/SimulationRuntime/c/util/read_csv.c
                      ${CMAKE_SOURCE_DIR}/OMEdit/OMEditLIB/SimulationRuntime/c/util/read_matlab4.c
                      ${CMAKE_SOURCE_DIR}/OMEdit/OMEditLIB/SimulationRuntime/c/util/omc_file.c
                      ${CMAKE_SOURCE_DIR}/OMEdit/OMEditLIB/SimulationRuntime/c/util/omc_numbers.c
                      ${CMAKE_SOURCE_DIR}/OMEdit/OMEditLIB/SimulationRuntime/c/util/omc_msvc.c
                      ${CMAKE_SOURCE_DIR}/OMEdit/OMEditLIB/SimulationRuntime/c/util/libcsv.c
                      resource_omplot.qrc)

set(OMPLOTLIB_HEADERS OMPlot.h
                      PlotZoomer.h
                      Legend.h
                      PlotPanner.h
                      PlotPicker.h
                      PlotGrid.h
                      PlotCurve.h
                      PlotWindow.h
                      PlotApplication.h
                      PlotWindowContainer.h
                      PlotMainWindow.h
                      ScaleDraw.h
                      LogScaleEngine.h
                      LinearScaleEngine.h)


add_library(OMPlotLib SHARED ${OMPLOTLIB_SOURCES} ${OMPLOTLIB_HEADERS})
target_compile_definitions(OMPlotLib PRIVATE OMPLOTLIB_MOC_INCLUDE DISABLE_META_MODELICA)

if(MSVC)
  set_target_properties(OMPlotLib PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS true)
endif()

target_include_directories(OMPlotLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Add include directories for the utility headers with correct paths
target_include_directories(OMPlotLib PRIVATE ${CMAKE_SOURCE_DIR}/OMEdit/OMEditLIB/SimulationRuntime/c/util)
target_include_directories(OMPlotLib PRIVATE ${CMAKE_SOURCE_DIR}/OMEdit/OMEditLIB/SimulationRuntime/c)

target_link_libraries(OMPlotLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::Widgets)
target_link_libraries(OMPlotLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::PrintSupport)

if (OM_QT_MAJOR_VERSION VERSION_GREATER_EQUAL 6)
  target_link_libraries(OMPlotLib PUBLIC Qt6::Core5Compat)
endif ()

target_link_libraries(OMPlotLib PUBLIC omqwt)

# Remove the omc::simrt::runtime dependency since we're including the sources directly
#target_link_libraries(OMPlotLib PUBLIC omc::simrt::runtime)

#if(TARGET omc::simrt::runtime)
#  target_link_libraries(OMPlotLib PUBLIC omc::simrt::runtime)
#endif()



if(APPLE)
  set(MACOSX_BUNDLE_ICON_FILE omplot.ico)

  # The following tells CMake where to find and install the file itself.
  set(app_icon_macos "${CMAKE_CURRENT_SOURCE_DIR}/Resources/icons/omplot.ico")
  set_source_files_properties(${app_icon_macos} PROPERTIES
       MACOSX_PACKAGE_LOCATION "Resources")
else()
  set(app_icon_macos "")
endif()

add_executable(OMPlot WIN32 MACOSX_BUNDLE main.cpp rc_omplot.rc ${app_icon_macos})
target_compile_definitions(OMPlot PRIVATE DISABLE_META_MODELICA)
target_link_libraries(OMPlot PRIVATE OMPlotLib)


install(TARGETS OMPlotLib)
install(TARGETS OMPlot
        BUNDLE DESTINATION ${OM_MACOS_INSTALL_BUNDLEDIR})