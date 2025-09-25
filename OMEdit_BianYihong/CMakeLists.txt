cmake_minimum_required(VERSION 3.14)

project(OMEdit)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置构建类型
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
      "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

# 设置位置无关代码
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# 包含实用宏（如果不存在则定义简化版本）
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/omc_utils.cmake")
  include("${CMAKE_CURRENT_SOURCE_DIR}/../cmake/omc_utils.cmake")
else()
  # 定义简化的宏
  macro(omc_option var help_text value)
    option(${var} ${help_text} ${value})
  endmacro()
  
  macro(omc_add_subdirectory var)
    add_subdirectory(${ARGV0} ${ARGV1} ${ARGV2})
  endmacro()
endif()

## 设置安装组件
set(CMAKE_INSTALL_DEFAULT_COMPONENT_NAME omedit)

## 选项配置
omc_option(OM_OMEDIT_INSTALL_RUNTIME_DLLS "Install the required runtime dll dependency DLLs to the binary directory. Valid only for Windows builds." ON)
omc_option(OM_OMEDIT_ENABLE_TESTS "Enable building of OMEdit Testsuite tests." OFF)
omc_option(OM_OMEDIT_ENABLE_QTWEBENGINE "Enable building of OMEdit with QtWebEngine instead of QtWebkit" OFF)
omc_option(OM_DISABLE_OMPLOT "Disable OMPlot plotting functionality in OMEdit" ON)

# 设置Qt版本
set(OM_QT_MAJOR_VERSION 5 CACHE STRING "Qt version")

## 查找依赖包
find_package(Qt${OM_QT_MAJOR_VERSION} COMPONENTS Widgets PrintSupport Xml OpenGL Network Svg REQUIRED)

if (OM_OMEDIT_ENABLE_QTWEBENGINE OR OM_QT_MAJOR_VERSION VERSION_GREATER_EQUAL 6)
  find_package(Qt${OM_QT_MAJOR_VERSION} COMPONENTS WebEngineWidgets REQUIRED)
else ()
  find_package(Qt${OM_QT_MAJOR_VERSION} COMPONENTS WebKitWidgets REQUIRED)
endif ()

if (OM_QT_MAJOR_VERSION VERSION_GREATER_EQUAL 6)
  find_package(Qt6 COMPONENTS OpenGLWidgets Core5Compat REQUIRED)
endif ()

find_package(OpenSceneGraph COMPONENTS osg osgViewer osgUtil osgDB osgGA REQUIRED)
find_package(OpenGL REQUIRED)

# 查找Python和pybind11
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 REQUIRED)

# 设置OpenModelica相关路径
set(OPENMODELICAHOME $ENV{OPENMODELICAHOME})
if(NOT OPENMODELICAHOME)
  set(OPENMODELICAHOME "${CMAKE_CURRENT_SOURCE_DIR}/..")
  message(WARNING "OPENMODELICAHOME not set, using: ${OPENMODELICAHOME}")
endif()

# 设置主机信息（简化版本）
set(host_short "linux-gnu")
if(WIN32)
  set(host_short "mingw32")
elseif(APPLE)
  set(host_short "darwin")
endif()

# 配置omedit_config.h
configure_file(omedit_config.h.in omedit_config.h)

## 创建配置库
add_library(omedit_config INTERFACE)
add_library(omedit::config ALIAS omedit_config)
target_include_directories(omedit_config INTERFACE ${CMAKE_CURRENT_BINARY_DIR})


if(NOT TARGET OMParser)
  add_library(OMParser INTERFACE)
  # 可以添加实际的OMParser库路径
endif()

# 添加OMPlot头文件路径
if(NOT TARGET OMPlotLib)
  add_library(OMPlotLib INTERFACE)
  target_include_directories(OMPlotLib INTERFACE 
    "${CMAKE_CURRENT_SOURCE_DIR}/../OMPlot/OMPlot/OMPlotGUI"
    "${CMAKE_CURRENT_SOURCE_DIR}/../OMPlot/qwt/src"
  )
endif()

# 添加OMSimulator头文件路径
if(NOT TARGET OMSimulatorLib)
  add_library(OMSimulatorLib INTERFACE)
  target_include_directories(OMSimulatorLib INTERFACE 
    "${CMAKE_CURRENT_SOURCE_DIR}/../OMSimulator/include"
  )
endif()

# 添加OMCompiler头文件路径
# 注释掉或删除OMCompiler相关配置
# if(NOT TARGET OpenModelicaCompiler)
#   add_library(OpenModelicaCompiler INTERFACE)
#   target_include_directories(OpenModelicaCompiler INTERFACE 
#     "${CMAKE_CURRENT_SOURCE_DIR}/../OMCompiler/Compiler/runtime"
#     "${CMAKE_CURRENT_SOURCE_DIR}/../OMCompiler/SimulationRuntime/c"
#     "${CMAKE_CURRENT_SOURCE_DIR}/../OMCompiler/SimulationRuntime/c/util"
#   )
# endif()

# 创建空的OpenModelicaCompiler目标（避免链接错误）
if(NOT TARGET OpenModelicaCompiler)
  add_library(OpenModelicaCompiler INTERFACE)
endif()

if(NOT TARGET omc::3rd::opcua)
  add_library(omc_3rd_opcua INTERFACE)
  add_library(omc::3rd::opcua ALIAS omc_3rd_opcua)
endif()

## 添加子目录
omc_add_subdirectory(OMEditLIB)
omc_add_subdirectory(OMEditGUI)

if(OM_OMEDIT_ENABLE_TESTS)
  omc_add_subdirectory(Testsuite)
endif()
