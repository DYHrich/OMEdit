# Extract object files from the library
message(STATUS "Extracting object files from ${libpath}")
EXECUTE_PROCESS(COMMAND /usr/bin/ar -x ${libpath}
                WORKING_DIRECTORY /home/yuhangdai/OpenModelica/OMEdit/OMCompiler/3rdParty/FMIL/fmiimport.objdir)
# Save the list of object files
EXECUTE_PROCESS(COMMAND ls .
                OUTPUT_FILE /home/yuhangdai/OpenModelica/OMEdit/OMCompiler/3rdParty/FMIL/fmiimport.objlist
                WORKING_DIRECTORY /home/yuhangdai/OpenModelica/OMEdit/OMCompiler/3rdParty/FMIL/fmiimport.objdir)