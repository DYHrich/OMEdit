# file(GLOB_RECURSE OMEDITLIB_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

# file(GLOB_RECURSE OMEDITLIB_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
# set(OMEDITLIB_SOURCES resource_omedit.qrc ${OMEDITLIB_SOURCES})


# This small module (OpenModelica/cmake/modules/Findbinutils.cmake) finds and sets up
# libbfd which is need for providing bactrace support for OMEdit.
# It is required always on MinGW for now. Can be made optional with some changes.
if(MINGW)
  find_package(binutils REQUIRED)
endif()

#omc_add_subdirectory(Debugger/Parser)
omc_add_subdirectory(3rdParty/open62541)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(OMEDITLIB_SOURCES Util/Helper.cpp
                      Util/Utilities.cpp
                      Util/StringHandler.cpp
                      Util/OutputPlainTextEdit.cpp
                      Util/DirectoryOrFileSelector.cpp
                      MainWindow.cpp
                      OMC/OMCProxy.cpp
                      OMC/PythonEnv.cpp
                      OMC/PythonQtConverter.cpp
                      Modeling/Model.cpp
                      Modeling/MessagesWidget.cpp
                      Modeling/ItemDelegate.cpp
                      Modeling/LibraryTreeWidget.cpp
                      Modeling/ElementTreeWidget.cpp
                      Modeling/Commands.cpp
                      Modeling/ModelWidgetContainer.cpp
                      Modeling/ModelicaClassDialog.cpp
                      Modeling/FunctionArgumentDialog.cpp
                      Modeling/InstallLibraryDialog.cpp
                      Search/SearchWidget.cpp
                      Options/OptionsDialog.cpp
                      Editors/BaseEditor.cpp
                      Editors/ModelicaEditor.cpp
                      Editors/TransformationsEditor.cpp
                      Editors/TextEditor.cpp
                      Editors/CEditor.cpp
                      Editors/CRMLEditor.cpp
                      Editors/MOSEditor.cpp
                      Editors/OMSimulatorEditor.cpp
                      Editors/MetaModelicaEditor.cpp
                      Editors/HTMLEditor.cpp
                      Plotting/PlotWindowContainer.cpp
                      Element/Element.cpp
                      Annotations/ShapeAnnotation.cpp
                      Element/CornerItem.cpp
                      Annotations/LineAnnotation.cpp
                      Annotations/PolygonAnnotation.cpp
                      Annotations/RectangleAnnotation.cpp
                      Annotations/EllipseAnnotation.cpp
                      Annotations/TextAnnotation.cpp
                      Annotations/BitmapAnnotation.cpp
                      Annotations/DynamicAnnotation.cpp
                      Annotations/BooleanAnnotation.cpp
                      Annotations/PointAnnotation.cpp
                      Annotations/RealAnnotation.cpp
                      Annotations/ColorAnnotation.cpp
                      Annotations/LinePatternAnnotation.cpp
                      Annotations/FillPatternAnnotation.cpp
                      Annotations/PointArrayAnnotation.cpp
                      Annotations/ArrowAnnotation.cpp
                      Annotations/SmoothAnnotation.cpp
                      Annotations/ExtentAnnotation.cpp
                      Annotations/BorderPatternAnnotation.cpp
                      Annotations/EllipseClosureAnnotation.cpp
                      Annotations/StringAnnotation.cpp
                      Annotations/TextAlignmentAnnotation.cpp
                      Annotations/TextStyleAnnotation.cpp
                      Element/ElementProperties.cpp
                      Element/Transformation.cpp
                      Modeling/DocumentationWidget.cpp
                      Simulation/TranslationFlagsWidget.cpp
                      Simulation/SimulationDialog.cpp
                      Simulation/SimulationOutputWidget.cpp
                      Simulation/SimulationOutputHandler.cpp
                      Simulation/OpcUaClient.cpp
                      Simulation/ArchivedSimulationsWidget.cpp
                      FMI/ImportFMUDialog.cpp
                      FMI/ImportFMUModelDescriptionDialog.cpp
                      FMI/FMUExportOutputWidget.cpp
                      Plotting/VariablesWidget.cpp
                      Plotting/DiagramWindow.cpp
                      Options/NotificationsDialog.cpp
                      Annotations/ShapePropertiesDialog.cpp
                      TransformationalDebugger/OMDumpXML.cpp
                      TransformationalDebugger/diff_match_patch.cpp
                      TransformationalDebugger/TransformationsWidget.cpp
#                      Debugger/GDB/CommandFactory.cpp
#                      Debugger/GDB/GDBAdapter.cpp
#                      Debugger/StackFrames/StackFramesWidget.cpp
#                      Debugger/Locals/LocalsWidget.cpp
#                      Debugger/Locals/ModelicaValue.cpp
#                      Debugger/Breakpoints/BreakpointMarker.cpp
#                      Debugger/Breakpoints/BreakpointsWidget.cpp
#                      Debugger/Breakpoints/BreakpointDialog.cpp
#                      Debugger/DebuggerConfigurationsDialog.cpp
#                      Debugger/Attach/AttachToProcessDialog.cpp
#                      Debugger/Attach/ProcessListModel.cpp
                      CrashReport/backtrace.c
                      CrashReport/GDBBacktrace.cpp
                      CrashReport/CrashReportDialog.cpp
                      CRML/CRMLTranslateAsDialog.cpp
                      CRML/CRMLTranslatorOutputWidget.cpp
                      Git/GitCommands.cpp
                      Git/CommitChangesDialog.cpp
                      Git/RevertCommitsDialog.cpp
                      Git/CleanDialog.cpp
                      OMEditApplication.cpp
                      Traceability/TraceabilityGraphViewWidget.cpp
                      Traceability/TraceabilityInformationURI.cpp
                      OMS/OMSProxy.cpp
                      OMS/ModelDialog.cpp
                      OMS/BusDialog.cpp
                      OMS/ElementPropertiesDialog.cpp
                      OMS/SystemSimulationInformationDialog.cpp
                      OMS/OMSSimulationDialog.cpp
                      OMS/OMSSimulationOutputWidget.cpp
#                      Animation/TimeManager.cpp
                      Util/ResourceCache.cpp
                      Util/NetworkAccessManager.cpp
                      Util/GitHubArtifactDownloader.cpp
                      FlatModelica/Expression.cpp
                      FlatModelica/ExpressionFuncs.cpp
                      FlatModelica/Parser.cpp
                      Animation/TimeManager.cpp
#                      Animation/OpenGLWidget.cpp
#                      Animation/AbstractAnimationWindow.cpp
#                      Animation/ViewerWidget.cpp
#                      Animation/AnimationWindow.cpp
#                      Animation/ExtraShapes.cpp
#                      Animation/Visualization.cpp
#                      Animation/VisualizationMAT.cpp
#                      Animation/VisualizationCSV.cpp
#                      Animation/VisualizationFMU.cpp
#                      Animation/FMUSettingsDialog.cpp
#                      Animation/FMUWrapper.cpp
#                      Animation/AbstractVisualizer.cpp
#                      Animation/Shape.cpp
#                      Animation/Vector.cpp
                      SimulationRuntime/c/gc/memory_pool.c
                      SimulationRuntime/c/gc/omc_gc.c
                      SimulationRuntime/c/util/omc_init.h
                      SimulationRuntime/c/util/omc_error.c
                      SimulationRuntime/c/util/omc_file.c
                      SimulationRuntime/c/util/omc_msvc.c
                      SimulationRuntime/c/util/omc_numbers.c
                      SimulationRuntime/c/util/read_csv.c
                      SimulationRuntime/c/util/read_matlab4.c
                      SimulationRuntime/c/util/simulation_options.c
                      SimulationRuntime/c/util/libcsv.c
                      SimulationRuntime/c/util/rtclock.c
#                      3rdParty/ryu/om_format.c
                      Compiler/runtime/settingsimpl.c                     
                      resource_omedit.qrc)

set(OMEDITLIB_HEADERS Util/Helper.h
                      Util/Utilities.h
                      Util/StringHandler.h
                      Util/OutputPlainTextEdit.h
                      Util/DirectoryOrFileSelector.h
                      MainWindow.h
                      OMC/OMCProxy.h
                      OMC/PythonEnv.h
                      OMC/PythonQtConverter.h
                      Modeling/Model.h
                      Modeling/MessagesWidget.h
                      Modeling/ItemDelegate.h
                      Modeling/LibraryTreeWidget.h
                      Modeling/ElementTreeWidget.h
                      Modeling/Commands.h
                      Modeling/ModelWidgetContainer.h
                      Modeling/ModelicaClassDialog.h
                      Modeling/FunctionArgumentDialog.h
                      Modeling/InstallLibraryDialog.h
                      Search/SearchWidget.h
                      Options/OptionsDefaults.h
                      Options/OptionsDialog.h
                      Editors/BaseEditor.h
                      Editors/ModelicaEditor.h
                      Editors/TransformationsEditor.h
                      Editors/TextEditor.h
                      Editors/CEditor.h
                      Editors/CRMLEditor.h
                      Editors/MOSEditor.h
                      Editors/OMSimulatorEditor.h
                      Editors/MetaModelicaEditor.h
                      Editors/HTMLEditor.h
                      Plotting/PlotWindowContainer.h
                      Element/Element.h
                      Annotations/ShapeAnnotation.h
                      Element/CornerItem.h
                      Annotations/LineAnnotation.h
                      Annotations/PolygonAnnotation.h
                      Annotations/RectangleAnnotation.h
                      Annotations/EllipseAnnotation.h
                      Annotations/TextAnnotation.h
                      Annotations/BitmapAnnotation.h
                      Annotations/DynamicAnnotation.h
                      Annotations/BooleanAnnotation.h
                      Annotations/PointAnnotation.h
                      Annotations/RealAnnotation.h
                      Annotations/ColorAnnotation.h
                      Annotations/LinePatternAnnotation.h
                      Annotations/FillPatternAnnotation.h
                      Annotations/PointArrayAnnotation.h
                      Annotations/ArrowAnnotation.h
                      Annotations/SmoothAnnotation.h
                      Annotations/ExtentAnnotation.h
                      Annotations/BorderPatternAnnotation.h
                      Annotations/EllipseClosureAnnotation.h
                      Annotations/StringAnnotation.h
                      Annotations/TextAlignmentAnnotation.h
                      Annotations/TextStyleAnnotation.h
                      Element/ElementProperties.h
                      Element/Transformation.h
                      Modeling/DocumentationWidget.h
                      Simulation/SimulationOptions.h
                      Simulation/TranslationFlagsWidget.h
                      Simulation/SimulationDialog.h
                      Simulation/SimulationOutputWidget.h
                      Simulation/SimulationOutputHandler.h
                      Simulation/OpcUaClient.h
                      Simulation/ArchivedSimulationsWidget.h
                      FMI/ImportFMUDialog.h
                      FMI/ImportFMUModelDescriptionDialog.h
                      FMI/FMUExportOutputWidget.h
                      Plotting/VariablesWidget.h
                      Plotting/DiagramWindow.h
                      Options/NotificationsDialog.h
                      Annotations/ShapePropertiesDialog.h
                      TransformationalDebugger/OMDumpXML.cpp
                      TransformationalDebugger/diff_match_patch.h
                      TransformationalDebugger/TransformationsWidget.h
#                      Debugger/GDB/CommandFactory.h
#                      Debugger/GDB/GDBAdapter.h
#                      Debugger/StackFrames/StackFramesWidget.h
#                      Debugger/Locals/LocalsWidget.h
#                      Debugger/Locals/ModelicaValue.h
#                      Debugger/Breakpoints/BreakpointMarker.h
#                      Debugger/Breakpoints/BreakpointsWidget.h
#                      Debugger/Breakpoints/BreakpointDialog.h
#                      Debugger/DebuggerConfigurationsDialog.h
#                      Debugger/Attach/AttachToProcessDialog.h
#                      Debugger/Attach/ProcessListModel.h
                      CrashReport/backtrace.h
                      CrashReport/GDBBacktrace.h
                      CrashReport/CrashReportDialog.h
                      CRML/CRMLTranslateAsDialog.h
                      CRML/CRMLTranslatorOptions.h
                      CRML/CRMLTranslatorOutputWidget.h
                      Git/GitCommands.h
                      Git/CommitChangesDialog.h
                      Git/RevertCommitsDialog.h
                      Git/CleanDialog.h
                      OMEditApplication.h
                      Traceability/TraceabilityGraphViewWidget.h
                      Traceability/TraceabilityInformationURI.h
                      OMS/OMSProxy.h
                      OMS/ModelDialog.h
                      OMS/BusDialog.h
                      OMS/ElementPropertiesDialog.h
                      OMS/SystemSimulationInformationDialog.h
                      OMS/OMSSimulationDialog.h
                      OMS/OMSSimulationOutputWidget.h
                      Interfaces/InformationInterface.h
                      Interfaces/ModelInterface.h
                      Util/ResourceCache.h
                      Util/NetworkAccessManager.h
                      Util/GitHubArtifactDownloader.h
                      FlatModelica/Expression.h
                      FlatModelica/ExpressionFuncs.h
                      FlatModelica/Parser.h
                      Animation/TimeManager.h                      
#                      Animation/OpenGLWidget.h
#                      Animation/AbstractAnimationWindow.h
#                      Animation/ViewerWidget.h
#                      Animation/AnimationWindow.h
#                      Animation/AnimationUtil.h
#                      Animation/ExtraShapes.h
#                      Animation/Visualization.h
#                      Animation/VisualizationMAT.h
#                      Animation/VisualizationCSV.h
#                      Animation/VisualizationFMU.h
#                      Animation/FMUSettingsDialog.h
#                      Animation/FMUWrapper.h
#                      Animation/AbstractVisualizer.h
#                      Animation/Shape.h
#                      Animation/Vector.h
                      SimulationRuntime/c/omc_inline.h
                      SimulationRuntime/c/omc_simulation_settings.h
                      SimulationRuntime/c/openmodelica.h
                      SimulationRuntime/c/openmodelica_types.h
                      SimulationRuntime/c/gc/memory_pool.h
                      SimulationRuntime/c/gc/omc_gc.h
                      SimulationRuntime/c/util/omc_init.h
                      SimulationRuntime/c/util/omc_error.h
                      SimulationRuntime/c/util/omc_file.h
                      SimulationRuntime/c/util/omc_msvc.h
                      SimulationRuntime/c/util/omc_numbers.h
                      SimulationRuntime/c/util/read_csv.h
                      SimulationRuntime/c/util/read_matlab4.h
                      SimulationRuntime/c/util/simulation_options.h
                      SimulationRuntime/c/util/libcsv.h
                      SimulationRuntime/c/util/rtclock.h
#                      3rdParty/ryu/ryu.h
#                      3rdParty/ryu/om_format.h
#                      3rdParty/libzmq/include/zmq.h
#                      3rdParty/libzmq/include/zmq_utils.h
#                      3rdParty/gc/include/gc.h
#                      3rdParty/gc/include/gc_version.h  
#                      3rdParty/gc/include/gc_config_macros.h
#                      Compiler/boot/tarball-include/OpenModelicaBootstrappingHeader.h
                      Compiler/runtime/settingsimpl.h
                      Compiler/omc_config.h
                      Compiler/omc_config.unix.h
#                      Compiler/OpenModelicaBootstrappingHeader.h
#                      Compiler/revision.h
                      OMSimulator/OMSimulator.h
                      OMSimulator/Types.h                         
                      Animation/rapidxml.hpp)

set(TS_FILES Resources/nls/OMEdit_de.ts
             Resources/nls/OMEdit_es.ts
             Resources/nls/OMEdit_fr.ts
             Resources/nls/OMEdit_it.ts
             Resources/nls/OMEdit_ja.ts
             Resources/nls/OMEdit_ro.ts
             Resources/nls/OMEdit_ru.ts
             Resources/nls/OMEdit_sv.ts
             Resources/nls/OMEdit_zh_CN.ts)

# Add the translation files.
find_package(Qt${OM_QT_MAJOR_VERSION} REQUIRED COMPONENTS LinguistTools)
# Create the output folder, lrelease doesn't do it automatically.
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Resources/nls)
set_source_files_properties(${TS_FILES} PROPERTIES OUTPUT_LOCATION "Resources/nls")
if (OM_QT_MAJOR_VERSION VERSION_GREATER_EQUAL 6)
  qt_add_translation(OMEDITLIB_TRANSLATIONS ${TS_FILES})
else()
  qt5_add_translation(OMEDITLIB_TRANSLATIONS ${TS_FILES})
endif()

# Add the local OpenModelicaScriptingAPIQt and PythonEnv files to sources
set(OMEDITLIB_HEADERS ${OMEDITLIB_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/OMC/OpenModelicaScriptingAPIQt.h)
set(OMEDITLIB_HEADERS ${OMEDITLIB_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/OMC/PythonEnv.h)
set(OMEDITLIB_SOURCES ${OMEDITLIB_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/OMC/OpenModelicaScriptingAPIQt.cpp)
set(OMEDITLIB_SOURCES ${OMEDITLIB_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/OMC/PythonEnv.cpp)


# libzmq
set (ZMQ_BUILD_TESTS OFF CACHE BOOL "Build the tests for ZeroMQ")
set (ZMQ_BUILD_STATIC ON CACHE BOOL "Whether or not to build the static object")
set (ZMQ_BUILD_SHARED OFF CACHE BOOL "Whether or not to build the shared object")
omc_add_subdirectory(3rdParty/libzmq)
add_library(omedit::3rd::libzmq ALIAS libzmq-static)

#gc
option(GC_BUILD_SHARED_LIBS "Build shared libraries" ON)
option(enable_java_finalization "Support for java finalization" OFF)
option(enable_gcj_support "Support for gcj" OFF)
option(enable_large_config "Optimize for large heap or root set" ON)
omc_add_subdirectory(3rdParty/gc)
target_include_directories(omcgc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/gc/include)
# make sure every target that links to gc-lib has its sources
# compiled with -DGC_WIN32_PTHREADS (for pthreads on Windows, i.e., OMDev or MSVC)
# Or -DGC_THREADS (for auto detection on other systems.)
# Even on Windows OM uses pthreads. GC_WIN32_PTHREADS is required
# to be set explicitly for use of pthreads API on Windows.
if(WIN32)
    target_compile_definitions(omcgc PUBLIC GC_WIN32_PTHREADS)
else()
    target_compile_definitions(omcgc PUBLIC GC_THREADS)
endif()

# Finally add an alias for clarity purposes.
add_library(omedit::3rd::omcgc ALIAS omcgc)


# ryu
omc_add_subdirectory(3rdParty/ryu)
add_library(omedit::3rd::ryu ALIAS ryu)


add_library(OMEditLib STATIC ${OMEDITLIB_SOURCES} ${OMEDITLIB_HEADERS} ${OMEDITLIB_TRANSLATIONS})

target_include_directories(OMEditLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# OpenSceneGraph does not provide imported targets yet. Add includes manually.
target_include_directories(OMEditLib PUBLIC ${OPENSCENEGRAPH_INCLUDE_DIRS})

# qmake adds -DUNICODE by defult (As far as I can gather).
# So add it for CMake as well to avoid having to modify the code.
if(WIN32)
  target_compile_definitions(OMEditLib PRIVATE UNICODE)
endif()

if(OM_ENABLE_ENCRYPTION)
  target_compile_definitions(OMEditLib PRIVATE OM_ENABLE_ENCRYPTION)
endif()

# Disable MetaModelica functionality
target_compile_definitions(OMEditLib PUBLIC DISABLE_META_MODELICA)
target_compile_definitions(OMEditLib PUBLIC OM_DISABLE_ANIMA)
target_compile_definitions(OMEditLib PUBLIC OM_DISABLE_DEBUG)
target_compile_definitions(OMEditLib PUBLIC WITHOUT_OSG)


target_link_libraries(OMEditLib PUBLIC omedit::3rd::libzmq)
target_link_libraries(OMEditLib PUBLIC omedit::config)
target_link_libraries(OMEditLib PUBLIC omedit::3rd::omcgc)
target_link_libraries(OMEditLib PUBLIC omedit::3rd::ryu)
# target_link_libraries(OMEditLib PUBLIC OMSimulatorLib)  # 注释掉这行
target_link_libraries(OMEditLib PUBLIC OMParser)
#target_link_libraries(OMEditLib PUBLIC omedit::debugger::parser)
target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::Xml)
target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::Widgets)
target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::PrintSupport)
target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::OpenGL)
target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::Network)
target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::Svg)

if (OM_OMEDIT_ENABLE_QTWEBENGINE OR OM_QT_MAJOR_VERSION VERSION_GREATER_EQUAL 6)
  target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::WebEngineWidgets)
  target_compile_definitions(OMEditLib PUBLIC OM_OMEDIT_ENABLE_QTWEBENGINE)
else ()
  target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::WebKitWidgets)
endif ()

# Define OMEditself macro for proper header inclusion
target_compile_definitions(OMEditLib PRIVATE OMEditself)


target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::OpenGL)
if (OM_QT_MAJOR_VERSION VERSION_GREATER_EQUAL 6)
  target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::OpenGLWidgets)
endif ()
target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::Network)
target_link_libraries(OMEditLib PUBLIC Qt${OM_QT_MAJOR_VERSION}::Svg)

if (OM_QT_MAJOR_VERSION VERSION_GREATER_EQUAL 6)
  target_link_libraries(OMEditLib PUBLIC Qt6::Core5Compat)
endif ()

target_link_libraries(OMEditLib PUBLIC omedit_opcua)
target_link_libraries(OMEditLib PUBLIC OMPlotLib)
#target_link_libraries(OMEditLib PUBLIC OpenModelicaCompiler)
target_link_libraries(OMEditLib PUBLIC ${OPENSCENEGRAPH_LIBRARIES})
target_link_libraries(OMEditLib PUBLIC OpenGL::GL)

# Add Python3 and pybind11 support
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 REQUIRED)
target_link_libraries(OMEditLib PRIVATE pybind11::embed)
target_link_libraries(OMEditLib PRIVATE Python3::Python)

# Silence OpenGL deprecation warnings on macOS
if(APPLE)
  target_compile_definitions(OMEditLib PRIVATE GL_SILENCE_DEPRECATION)
endif()

if(MINGW)
  target_link_libraries(OMEditLib PUBLIC binutils::bfd)
  target_link_libraries(OMEditLib PUBLIC zlib)
endif()

target_include_directories(OMEditLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/OMC ${CMAKE_CURRENT_SOURCE_DIR})

# Install the translation files
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Resources/nls
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/omedit
        FILES_MATCHING PATTERN "*.qm")
