# Extract object files from the library
message(STATUS "Extracting object files from ${libpath}")
EXECUTE_PROCESS(COMMAND /usr/bin/ar -x ${libpath}
                WORKING_DIRECTORY /home/yuhangdai/OpenModelica/OMEdit/OMCompiler/3rdParty/FMIL/fmicapi.objdir)
# Save the list of object files
EXECUTE_PROCESS(COMMAND ls .
                OUTPUT_FILE /home/yuhangdai/OpenModelica/OMEdit/OMCompiler/3rdParty/FMIL/fmicapi.objlist
                WORKING_DIRECTORY /home/yuhangdai/OpenModelica/OMEdit/OMCompiler/3rdParty/FMIL/fmicapi.objdir)