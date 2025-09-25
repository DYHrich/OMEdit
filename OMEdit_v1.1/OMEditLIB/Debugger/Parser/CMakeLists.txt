
add_custom_command(
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/GDBMIOutput.g
    COMMAND ${Java_JAVA_EXECUTABLE}
    ARGS -cp ${OMAntlr3_ANTLRJAR}
          org.antlr.Tool -Xconversiontimeout 10000
          -o ${CMAKE_CURRENT_BINARY_DIR}
          ${CMAKE_CURRENT_SOURCE_DIR}/GDBMIOutput.g

    COMMENT "Generating ${output_file_path_no_ext}.c/h for ANTLR file ${CMAKE_CURRENT_SOURCE_DIR}/GDBMIOutput.g."
    OUTPUT GDBMIOutputLexer.c
    OUTPUT GDBMIOutputLexer.h
    OUTPUT GDBMIOutputParser.c
    OUTPUT GDBMIOutputParser.h
    OUTPUT GDBMIOutput.tokens
  )

## This generated C files include Parser/GDBMIParser.h. Which is a C++ header. Therefore we need to
## compile them as C++ files.
## antlr3 did not get a C++ support until 3.4. We are using antlr 3.2
set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/GDBMIOutputLexer.c PROPERTIES LANGUAGE CXX)
set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/GDBMIOutputParser.c PROPERTIES LANGUAGE CXX)


# 注释掉ANTLR3依赖
add_library(libGDBMIParser STATIC GDBMIOutputLexer.c GDBMIOutputParser.c GDBMIParser.cpp)
add_library(omedit::debugger::parser ALIAS libGDBMIParser)

# 移除这行依赖
# target_link_libraries(libGDBMIParser PUBLIC omc::3rd::omantlr3)

# 如果需要，可以添加替代的系统ANTLR库
# find_package(PkgConfig REQUIRED)
# pkg_check_modules(ANTLR3 REQUIRED antlr3c)
# target_link_libraries(libGDBMIParser PUBLIC ${ANTLR3_LIBRARIES})

target_include_directories(libGDBMIParser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
## To pick up the generated header files.
target_include_directories(libGDBMIParser PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
