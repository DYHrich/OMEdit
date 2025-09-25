encapsulated package OpenModelicaScriptingAPI

import Absyn;
import AbsynUtil;
import CevalScript;
import Parser;

protected

import Values;
import ValuesUtil;
constant Absyn.Msg dummyMsg = Absyn.MSG(SOURCEINFO("<interactive>",false,1,1,1,1,0.0));

public

function oms_getVersion
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getVersion", {}, dummyMsg);
end oms_getVersion;

function oms_terminate
  input String cref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_terminate", {Values.STRING(cref)}, dummyMsg);
end oms_terminate;

function oms_stepUntil
  input String cref;
  input Real stopTime;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_stepUntil", {Values.STRING(cref), Values.REAL(stopTime)}, dummyMsg);
end oms_stepUntil;

function oms_simulate
  input String cref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_simulate", {Values.STRING(cref)}, dummyMsg);
end oms_simulate;

function oms_setWorkingDirectory
  input String newWorkingDir;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setWorkingDirectory", {Values.STRING(newWorkingDir)}, dummyMsg);
end oms_setWorkingDirectory;

function oms_setVariableStepSize
  input String cref;
  input Real initialStepSize;
  input Real minimumStepSize;
  input Real maximumStepSize;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setVariableStepSize", {Values.STRING(cref), Values.REAL(initialStepSize), Values.REAL(minimumStepSize), Values.REAL(maximumStepSize)}, dummyMsg);
end oms_setVariableStepSize;

function oms_setTolerance
  input String cref;
  input Real absoluteTolerance;
  input Real relativeTolerance;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setTolerance", {Values.STRING(cref), Values.REAL(absoluteTolerance), Values.REAL(relativeTolerance)}, dummyMsg);
end oms_setTolerance;

function oms_setTLMSocketData
  input String cref;
  input String address;
  input Integer managerPort;
  input Integer monitorPort;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setTLMSocketData", {Values.STRING(cref), Values.STRING(address), Values.INTEGER(managerPort), Values.INTEGER(monitorPort)}, dummyMsg);
end oms_setTLMSocketData;

function oms_setTLMPositionAndOrientation
  input String cref;
  input Real x1;
  input Real x2;
  input Real x3;
  input Real A11;
  input Real A12;
  input Real A13;
  input Real A21;
  input Real A22;
  input Real A23;
  input Real A31;
  input Real A32;
  input Real A33;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setTLMPositionAndOrientation", {Values.STRING(cref), Values.REAL(x1), Values.REAL(x2), Values.REAL(x3), Values.REAL(A11), Values.REAL(A12), Values.REAL(A13), Values.REAL(A21), Values.REAL(A22), Values.REAL(A23), Values.REAL(A31), Values.REAL(A32), Values.REAL(A33)}, dummyMsg);
end oms_setTLMPositionAndOrientation;

function oms_setTempDirectory
  input String newTempDir;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setTempDirectory", {Values.STRING(newTempDir)}, dummyMsg);
end oms_setTempDirectory;

function oms_setStopTime
  input String cref;
  input Real stopTime;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setStopTime", {Values.STRING(cref), Values.REAL(stopTime)}, dummyMsg);
end oms_setStopTime;

function oms_setStartTime
  input String cref;
  input Real startTime;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setStartTime", {Values.STRING(cref), Values.REAL(startTime)}, dummyMsg);
end oms_setStartTime;

function oms_setSignalFilter
  input String cref;
  input String regex;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setSignalFilter", {Values.STRING(cref), Values.STRING(regex)}, dummyMsg);
end oms_setSignalFilter;

function oms_setResultFile
  input String cref;
  input String filename;
  input Integer bufferSize;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setResultFile", {Values.STRING(cref), Values.STRING(filename), Values.INTEGER(bufferSize)}, dummyMsg);
end oms_setResultFile;

function oms_setRealInputDerivative
  input String cref;
  input Real value;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setRealInputDerivative", {Values.STRING(cref), Values.REAL(value)}, dummyMsg);
end oms_setRealInputDerivative;

function oms_setReal
  input String cref;
  input Real value;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setReal", {Values.STRING(cref), Values.REAL(value)}, dummyMsg);
end oms_setReal;

function oms_setLoggingLevel
  input Integer logLevel;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setLoggingLevel", {Values.INTEGER(logLevel)}, dummyMsg);
end oms_setLoggingLevel;

function oms_setLoggingInterval
  input String cref;
  input Real loggingInterval;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setLoggingInterval", {Values.STRING(cref), Values.REAL(loggingInterval)}, dummyMsg);
end oms_setLoggingInterval;

function oms_setLogFile
  input String filename;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setLogFile", {Values.STRING(filename)}, dummyMsg);
end oms_setLogFile;

function oms_setInteger
  input String cref;
  input Integer value;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setInteger", {Values.STRING(cref), Values.INTEGER(value)}, dummyMsg);
end oms_setInteger;

function oms_setFixedStepSize
  input String cref;
  input Real stepSize;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setFixedStepSize", {Values.STRING(cref), Values.REAL(stepSize)}, dummyMsg);
end oms_setFixedStepSize;

function oms_setCommandLineOption
  input String cmd;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setCommandLineOption", {Values.STRING(cmd)}, dummyMsg);
end oms_setCommandLineOption;

function oms_setBoolean
  input String cref;
  input Boolean value;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_setBoolean", {Values.STRING(cref), Values.BOOL(value)}, dummyMsg);
end oms_setBoolean;

function oms_RunFile
  input String filename;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_RunFile", {Values.STRING(filename)}, dummyMsg);
end oms_RunFile;

function oms_reset
  input String cref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_reset", {Values.STRING(cref)}, dummyMsg);
end oms_reset;

function oms_rename
  input String cref;
  input String newCref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_rename", {Values.STRING(cref), Values.STRING(newCref)}, dummyMsg);
end oms_rename;

function oms_removeSignalsFromResults
  input String cref;
  input String regex;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_removeSignalsFromResults", {Values.STRING(cref), Values.STRING(regex)}, dummyMsg);
end oms_removeSignalsFromResults;

function oms_newModel
  input String cref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_newModel", {Values.STRING(cref)}, dummyMsg);
end oms_newModel;

function oms_loadSnapshot
  input String cref;
  input String snapshot;
  output String res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.STRING(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_loadSnapshot", {Values.STRING(cref), Values.STRING(snapshot)}, dummyMsg);
end oms_loadSnapshot;

function oms_listUnconnectedConnectors
  input String cref;
  output String res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.STRING(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_listUnconnectedConnectors", {Values.STRING(cref)}, dummyMsg);
end oms_listUnconnectedConnectors;

function oms_list
  input String cref;
  output String res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.STRING(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_list", {Values.STRING(cref)}, dummyMsg);
end oms_list;

function oms_instantiate
  input String cref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_instantiate", {Values.STRING(cref)}, dummyMsg);
end oms_instantiate;

function oms_initialize
  input String cref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_initialize", {Values.STRING(cref)}, dummyMsg);
end oms_initialize;

function oms_importSnapshot
  input String cref;
  input String snapshot;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_importSnapshot", {Values.STRING(cref), Values.STRING(snapshot)}, dummyMsg);
end oms_importSnapshot;

function oms_importFile
  input String filename;
  output String res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.STRING(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_importFile", {Values.STRING(filename)}, dummyMsg);
end oms_importFile;

function oms_getVariableStepSize
  input String cref;
  output Real res1;
  output Real res2;
  output Real res3;
  output Integer res4;
algorithm
  (_,Values.TUPLE({Values.REAL(res1), Values.REAL(res2), Values.REAL(res3), Values.INTEGER(res4)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getVariableStepSize", {Values.STRING(cref)}, dummyMsg);
end oms_getVariableStepSize;

function oms_getTolerance
  input String cref;
  output Real res1;
  output Real res2;
  output Integer res3;
algorithm
  (_,Values.TUPLE({Values.REAL(res1), Values.REAL(res2), Values.INTEGER(res3)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getTolerance", {Values.STRING(cref)}, dummyMsg);
end oms_getTolerance;

function oms_getSystemType
  input String cref;
  output Integer res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.INTEGER(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getSystemType", {Values.STRING(cref)}, dummyMsg);
end oms_getSystemType;

function oms_getSubModelPath
  input String cref;
  output String res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.STRING(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getSubModelPath", {Values.STRING(cref)}, dummyMsg);
end oms_getSubModelPath;

function oms_getStopTime
  input String cref;
  output Real res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.REAL(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getStopTime", {Values.STRING(cref)}, dummyMsg);
end oms_getStopTime;

function oms_getStartTime
  input String cref;
  output Real res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.REAL(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getStartTime", {Values.STRING(cref)}, dummyMsg);
end oms_getStartTime;

function oms_getSolver
  input String cref;
  output Integer res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.INTEGER(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getSolver", {Values.STRING(cref)}, dummyMsg);
end oms_getSolver;

function oms_getReal
  input String cref;
  output Real res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.REAL(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getReal", {Values.STRING(cref)}, dummyMsg);
end oms_getReal;

function oms_getModelState
  input String cref;
  output Integer res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.INTEGER(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getModelState", {Values.STRING(cref)}, dummyMsg);
end oms_getModelState;

function oms_getInteger
  input String cref;
  input Integer value;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getInteger", {Values.STRING(cref), Values.INTEGER(value)}, dummyMsg);
end oms_getInteger;

function oms_getFixedStepSize
  input String cref;
  output Real res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.REAL(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getFixedStepSize", {Values.STRING(cref)}, dummyMsg);
end oms_getFixedStepSize;

function oms_getBoolean
  input String cref;
  output Boolean res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.BOOL(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_getBoolean", {Values.STRING(cref)}, dummyMsg);
end oms_getBoolean;

function oms_extractFMIKind
  input String filename;
  output Integer res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.INTEGER(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_extractFMIKind", {Values.STRING(filename)}, dummyMsg);
end oms_extractFMIKind;

function oms_exportSnapshot
  input String cref;
  output String res1;
  output Integer res2;
algorithm
  (_,Values.TUPLE({Values.STRING(res1), Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_exportSnapshot", {Values.STRING(cref)}, dummyMsg);
end oms_exportSnapshot;

function oms_exportDependencyGraphs
  input String cref;
  input String initialization;
  input String event;
  input String simulation;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_exportDependencyGraphs", {Values.STRING(cref), Values.STRING(initialization), Values.STRING(event), Values.STRING(simulation)}, dummyMsg);
end oms_exportDependencyGraphs;

function oms_export
  input String cref;
  input String filename;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_export", {Values.STRING(cref), Values.STRING(filename)}, dummyMsg);
end oms_export;

function oms_deleteConnectorFromTLMBus
  input String busCref;
  input String connectorCref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_deleteConnectorFromTLMBus", {Values.STRING(busCref), Values.STRING(connectorCref)}, dummyMsg);
end oms_deleteConnectorFromTLMBus;

function oms_deleteConnectorFromBus
  input String busCref;
  input String connectorCref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_deleteConnectorFromBus", {Values.STRING(busCref), Values.STRING(connectorCref)}, dummyMsg);
end oms_deleteConnectorFromBus;

function oms_deleteConnection
  input String crefA;
  input String crefB;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_deleteConnection", {Values.STRING(crefA), Values.STRING(crefB)}, dummyMsg);
end oms_deleteConnection;

function oms_delete
  input String cref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_delete", {Values.STRING(cref)}, dummyMsg);
end oms_delete;

function oms_copySystem
  input String source;
  input String target;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_copySystem", {Values.STRING(source), Values.STRING(target)}, dummyMsg);
end oms_copySystem;

function oms_compareSimulationResults
  input String filenameA;
  input String filenameB;
  input String var;
  input Real relTol;
  input Real absTol;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_compareSimulationResults", {Values.STRING(filenameA), Values.STRING(filenameB), Values.STRING(var), Values.REAL(relTol), Values.REAL(absTol)}, dummyMsg);
end oms_compareSimulationResults;

function oms_addTLMConnection
  input String crefA;
  input String crefB;
  input Real delay;
  input Real alpha;
  input Real linearimpedance;
  input Real angularimpedance;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addTLMConnection", {Values.STRING(crefA), Values.STRING(crefB), Values.REAL(delay), Values.REAL(alpha), Values.REAL(linearimpedance), Values.REAL(angularimpedance)}, dummyMsg);
end oms_addTLMConnection;

function oms_addTimeIndicator
  input String signal;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addTimeIndicator", {Values.STRING(signal)}, dummyMsg);
end oms_addTimeIndicator;

function oms_addSubModel
  input String cref;
  input String fmuPath;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addSubModel", {Values.STRING(cref), Values.STRING(fmuPath)}, dummyMsg);
end oms_addSubModel;

function oms_addStaticValueIndicator
  input String signal;
  input Real lower;
  input Real upper;
  input Real stepSize;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addStaticValueIndicator", {Values.STRING(signal), Values.REAL(lower), Values.REAL(upper), Values.REAL(stepSize)}, dummyMsg);
end oms_addStaticValueIndicator;

function oms_addSignalsToResults
  input String cref;
  input String regex;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addSignalsToResults", {Values.STRING(cref), Values.STRING(regex)}, dummyMsg);
end oms_addSignalsToResults;

function oms_addExternalModel
  input String cref;
  input String path;
  input String startscript;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addExternalModel", {Values.STRING(cref), Values.STRING(path), Values.STRING(startscript)}, dummyMsg);
end oms_addExternalModel;

function oms_addEventIndicator
  input String signal;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addEventIndicator", {Values.STRING(signal)}, dummyMsg);
end oms_addEventIndicator;

function oms_addDynamicValueIndicator
  input String signal;
  input String lower;
  input String upper;
  input Real stepSize;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addDynamicValueIndicator", {Values.STRING(signal), Values.STRING(lower), Values.STRING(upper), Values.REAL(stepSize)}, dummyMsg);
end oms_addDynamicValueIndicator;

function oms_addConnectorToTLMBus
  input String busCref;
  input String connectorCref;
  input String type_;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addConnectorToTLMBus", {Values.STRING(busCref), Values.STRING(connectorCref), Values.STRING(type_)}, dummyMsg);
end oms_addConnectorToTLMBus;

function oms_addConnectorToBus
  input String busCref;
  input String connectorCref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addConnectorToBus", {Values.STRING(busCref), Values.STRING(connectorCref)}, dummyMsg);
end oms_addConnectorToBus;

function oms_addConnection
  input String crefA;
  input String crefB;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addConnection", {Values.STRING(crefA), Values.STRING(crefB)}, dummyMsg);
end oms_addConnection;

function oms_addBus
  input String cref;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "oms_addBus", {Values.STRING(cref)}, dummyMsg);
end oms_addBus;

function unloadOMSimulator
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "unloadOMSimulator", {}, dummyMsg);
end unloadOMSimulator;

function loadOMSimulator
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "loadOMSimulator", {}, dummyMsg);
end loadOMSimulator;

function getDefinitions
  input Boolean addFunctions;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getDefinitions", {Values.BOOL(addFunctions)}, dummyMsg);
end getDefinitions;

function qualifyPath
  input String classPath;
  input String path;
  output String res;
protected
  Absyn.Path res_path;
algorithm
  (_,Values.CODE(Absyn.C_TYPENAME(path=res_path))) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "qualifyPath", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(classPath))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(path)))}, dummyMsg);
  res := AbsynUtil.pathString(res_path);
end qualifyPath;

function restoreAST
  input Integer id;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "restoreAST", {Values.INTEGER(id)}, dummyMsg);
end restoreAST;

function storeAST
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "storeAST", {}, dummyMsg);
end storeAST;

function modifierToJSON
  input String modifier;
  input Boolean prettyPrint;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "modifierToJSON", {Values.STRING(modifier), Values.BOOL(prettyPrint)}, dummyMsg);
end modifierToJSON;

function getModelInstanceAnnotation
  input String className;
  input list<String> filter;
  input Boolean prettyPrint;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getModelInstanceAnnotation", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), ValuesUtil.makeArray(list(Values.STRING(filter_iter) for filter_iter in filter)), Values.BOOL(prettyPrint)}, dummyMsg);
end getModelInstanceAnnotation;

function getModelInstance
  input String className;
  input String modifier;
  input Boolean prettyPrint;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getModelInstance", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.STRING(modifier), Values.BOOL(prettyPrint)}, dummyMsg);
end getModelInstance;

function convertPackageToLibrary
  input String packageToConvert;
  input String library;
  input String libraryVersion;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "convertPackageToLibrary", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(packageToConvert))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(library))), Values.STRING(libraryVersion)}, dummyMsg);
end convertPackageToLibrary;

function runConversionScript
  input String packageToConvert;
  input String scriptFile;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "runConversionScript", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(packageToConvert))), Values.STRING(scriptFile)}, dummyMsg);
end runConversionScript;

function generateScriptingAPI
  input String cl;
  input String name;
  output Boolean res1;
  output String res2;
  output String res3;
  output String res4;
algorithm
  (_,Values.TUPLE({Values.BOOL(res1), Values.STRING(res2), Values.STRING(res3), Values.STRING(res4)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "generateScriptingAPI", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl))), Values.STRING(name)}, dummyMsg);
end generateScriptingAPI;

function deleteInitialState
  input String cl;
  input String state;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "deleteInitialState", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl))), Values.STRING(state)}, dummyMsg);
end deleteInitialState;

function getInitialStates
  input String cl;
  output list<list<String>> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getInitialStates", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
  res := list(list(match res_arr_iter_iter case Values.STRING() then res_arr_iter_iter.string; end match for res_arr_iter_iter in ValuesUtil.arrayValues(res_arr_iter)) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getInitialStates;

function deleteTransition
  input String cl;
  input String from;
  input String to;
  input String condition;
  input Boolean immediate;
  input Boolean reset;
  input Boolean synchronize;
  input Integer priority;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "deleteTransition", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl))), Values.STRING(from), Values.STRING(to), Values.STRING(condition), Values.BOOL(immediate), Values.BOOL(reset), Values.BOOL(synchronize), Values.INTEGER(priority)}, dummyMsg);
end deleteTransition;

function getTransitions
  input String cl;
  output list<list<String>> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getTransitions", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
  res := list(list(match res_arr_iter_iter case Values.STRING() then res_arr_iter_iter.string; end match for res_arr_iter_iter in ValuesUtil.arrayValues(res_arr_iter)) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getTransitions;

function getEnumerationLiterals
  input String className;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getEnumerationLiterals", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getEnumerationLiterals;

function getDefaultComponentPrefixes
  input String cl;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getDefaultComponentPrefixes", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end getDefaultComponentPrefixes;

function getDefaultComponentName
  input String cl;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getDefaultComponentName", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end getDefaultComponentName;

function getClassInformation
  input String cl;
  output String res1;
  output String res2;
  output Boolean res3;
  output Boolean res4;
  output Boolean res5;
  output String res6;
  output Boolean res7;
  output Integer res8;
  output Integer res9;
  output Integer res10;
  output Integer res11;
  output list<String> res12;
  output Boolean res13;
  output Boolean res14;
  output String res15;
  output String res16;
  output Boolean res17;
  output String res18;
  output String res19;
  output String res20;
  output String res21;
  output String res22;
protected
  Values.Value res12_arr;
algorithm
  (_,Values.TUPLE({Values.STRING(res1), Values.STRING(res2), Values.BOOL(res3), Values.BOOL(res4), Values.BOOL(res5), Values.STRING(res6), Values.BOOL(res7), Values.INTEGER(res8), Values.INTEGER(res9), Values.INTEGER(res10), Values.INTEGER(res11), res12_arr, Values.BOOL(res13), Values.BOOL(res14), Values.STRING(res15), Values.STRING(res16), Values.BOOL(res17), Values.STRING(res18), Values.STRING(res19), Values.STRING(res20), Values.STRING(res21), Values.STRING(res22)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getClassInformation", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
  res12 := list(match res12_arr_iter case Values.STRING() then res12_arr_iter.string; end match for res12_arr_iter in ValuesUtil.arrayValues(res12_arr));
end getClassInformation;

function sortStrings
  input list<String> arr;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "sortStrings", {ValuesUtil.makeArray(list(Values.STRING(arr_iter) for arr_iter in arr))}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end sortStrings;

function checkInterfaceOfPackages
  input String cl;
  input list<list<String>> dependencyMatrix;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "checkInterfaceOfPackages", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl))), ValuesUtil.makeArray(list(ValuesUtil.makeArray(list(Values.STRING(dependencyMatrix_iter_iter) for dependencyMatrix_iter_iter in dependencyMatrix_iter)) for dependencyMatrix_iter in dependencyMatrix))}, dummyMsg);
end checkInterfaceOfPackages;

function GC_set_max_heap_size
  input Integer size;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "GC_set_max_heap_size", {Values.INTEGER(size)}, dummyMsg);
end GC_set_max_heap_size;

function GC_expand_hp
  input Integer size;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "GC_expand_hp", {Values.INTEGER(size)}, dummyMsg);
end GC_expand_hp;

function GC_gcollect_and_unmap
algorithm
  (_,Values.NORETCALL()) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "GC_gcollect_and_unmap", {}, dummyMsg);
end GC_gcollect_and_unmap;

function getMemorySize
  output Real res;
algorithm
  (_,Values.REAL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getMemorySize", {}, dummyMsg);
end getMemorySize;

function threadWorkFailed
algorithm
  (_,Values.NORETCALL()) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "threadWorkFailed", {}, dummyMsg);
end threadWorkFailed;

function exit
  input Integer status;
algorithm
  (_,Values.NORETCALL()) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "exit", {Values.INTEGER(status)}, dummyMsg);
end exit;

function runScriptParallel
  input list<String> scripts;
  input Integer numThreads;
  input Boolean useThreads;
  output list<Boolean> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "runScriptParallel", {ValuesUtil.makeArray(list(Values.STRING(scripts_iter) for scripts_iter in scripts)), Values.INTEGER(numThreads), Values.BOOL(useThreads)}, dummyMsg);
  res := list(match res_arr_iter case Values.BOOL() then res_arr_iter.boolean; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end runScriptParallel;

function numProcessors
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "numProcessors", {}, dummyMsg);
end numProcessors;

function generateEntryPoint
  input String fileName;
  input String entryPoint;
  input String url;
algorithm
  (_,Values.NORETCALL()) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "generateEntryPoint", {Values.STRING(fileName), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(entryPoint))), Values.STRING(url)}, dummyMsg);
end generateEntryPoint;

function getDerivedClassModifierValue
  input String className;
  input String modifierName;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getDerivedClassModifierValue", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(modifierName)))}, dummyMsg);
end getDerivedClassModifierValue;

function getDerivedClassModifierNames
  input String className;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getDerivedClassModifierNames", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getDerivedClassModifierNames;

function getConversionsFromVersions
  input String pack;
  output list<String> res1;
  output list<String> res2;
protected
  Values.Value res1_arr;
  Values.Value res2_arr;
algorithm
  (_,Values.TUPLE({res1_arr, res2_arr})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getConversionsFromVersions", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(pack)))}, dummyMsg);
  res1 := list(match res1_arr_iter case Values.STRING() then res1_arr_iter.string; end match for res1_arr_iter in ValuesUtil.arrayValues(res1_arr));
  res2 := list(match res2_arr_iter case Values.STRING() then res2_arr_iter.string; end match for res2_arr_iter in ValuesUtil.arrayValues(res2_arr));
end getConversionsFromVersions;

function getUses
  input String pack;
  output list<list<String>> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getUses", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(pack)))}, dummyMsg);
  res := list(list(match res_arr_iter_iter case Values.STRING() then res_arr_iter_iter.string; end match for res_arr_iter_iter in ValuesUtil.arrayValues(res_arr_iter)) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getUses;

function upgradeInstalledPackages
  input Boolean installNewestVersions;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "upgradeInstalledPackages", {Values.BOOL(installNewestVersions)}, dummyMsg);
end upgradeInstalledPackages;

function getAvailablePackageConversionsFrom
  input String pkg;
  input String version;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAvailablePackageConversionsFrom", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(pkg))), Values.STRING(version)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getAvailablePackageConversionsFrom;

function getAvailablePackageConversionsTo
  input String pkg;
  input String version;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAvailablePackageConversionsTo", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(pkg))), Values.STRING(version)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getAvailablePackageConversionsTo;

function getAvailablePackageVersions
  input String pkg;
  input String version;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAvailablePackageVersions", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(pkg))), Values.STRING(version)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getAvailablePackageVersions;

function updatePackageIndex
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "updatePackageIndex", {}, dummyMsg);
end updatePackageIndex;

function installPackage
  input String pkg;
  input String version;
  input Boolean exactMatch;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "installPackage", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(pkg))), Values.STRING(version), Values.BOOL(exactMatch)}, dummyMsg);
end installPackage;

function getAvailableLibraryVersions
  input String libraryName;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAvailableLibraryVersions", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(libraryName)))}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getAvailableLibraryVersions;

function getAvailableLibraries
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAvailableLibraries", {}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getAvailableLibraries;

function searchClassNames
  input String searchText;
  input Boolean findInText;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "searchClassNames", {Values.STRING(searchText), Values.BOOL(findInText)}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end searchClassNames;

function extendsFrom
  input String className;
  input String baseClassName;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "extendsFrom", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(baseClassName)))}, dummyMsg);
end extendsFrom;

function getBooleanClassAnnotation
  input String className;
  input String annotationName;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getBooleanClassAnnotation", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(annotationName)))}, dummyMsg);
end getBooleanClassAnnotation;

function classAnnotationExists
  input String className;
  input String annotationName;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "classAnnotationExists", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(annotationName)))}, dummyMsg);
end classAnnotationExists;

function getAnnotationModifierValue
  input String className;
  input String annotationName;
  input String modifierName;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAnnotationModifierValue", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.STRING(annotationName), Values.STRING(modifierName)}, dummyMsg);
end getAnnotationModifierValue;

function getAnnotationNamedModifiers
  input String className;
  input String annotationName;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAnnotationNamedModifiers", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.STRING(annotationName)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getAnnotationNamedModifiers;

function getSimulationOptions
  input String name;
  input Real defaultStartTime;
  input Real defaultStopTime;
  input Real defaultTolerance;
  input Integer defaultNumberOfIntervals;
  input Real defaultInterval;
  output Real res1;
  output Real res2;
  output Real res3;
  output Integer res4;
  output Real res5;
algorithm
  (_,Values.TUPLE({Values.REAL(res1), Values.REAL(res2), Values.REAL(res3), Values.INTEGER(res4), Values.REAL(res5)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getSimulationOptions", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(name))), Values.REAL(defaultStartTime), Values.REAL(defaultStopTime), Values.REAL(defaultTolerance), Values.INTEGER(defaultNumberOfIntervals), Values.REAL(defaultInterval)}, dummyMsg);
end getSimulationOptions;

function isExperiment
  input String name;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isExperiment", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(name)))}, dummyMsg);
end isExperiment;

function getNthInheritedClass
  input String className;
  input Integer n;
  output String res;
protected
  Absyn.Path res_path;
algorithm
  (_,Values.CODE(Absyn.C_TYPENAME(path=res_path))) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthInheritedClass", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.INTEGER(n)}, dummyMsg);
  res := AbsynUtil.pathString(res_path);
end getNthInheritedClass;

function getInheritedClasses
  input String name;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getInheritedClasses", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(name)))}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getInheritedClasses;

function getInheritanceCount
  input String className;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getInheritanceCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end getInheritanceCount;

function isProtected
  input String componentName;
  input String className;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isProtected", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(componentName))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end isProtected;

function isConstant
  input String componentName;
  input String className;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isConstant", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(componentName))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end isConstant;

function isParameter
  input String componentName;
  input String className;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isParameter", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(componentName))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end isParameter;

function isPrimitive
  input String className;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isPrimitive", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end isPrimitive;

function getBuiltinType
  input String cl;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getBuiltinType", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end getBuiltinType;

function isProtectedClass
  input String cl;
  input String c2;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isProtectedClass", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl))), Values.STRING(c2)}, dummyMsg);
end isProtectedClass;

function isOperatorFunction
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isOperatorFunction", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isOperatorFunction;

function isOperatorRecord
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isOperatorRecord", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isOperatorRecord;

function isOperator
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isOperator", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isOperator;

function isEnumeration
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isEnumeration", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isEnumeration;

function isOptimization
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isOptimization", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isOptimization;

function isConnector
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isConnector", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isConnector;

function isModel
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isModel", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isModel;

function isRedeclare
  input String element;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isRedeclare", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(element)))}, dummyMsg);
end isRedeclare;

function isReplaceable
  input String element;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isReplaceable", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(element)))}, dummyMsg);
end isReplaceable;

function isPartial
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isPartial", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isPartial;

function isFunction
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isFunction", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isFunction;

function isBlock
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isBlock", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isBlock;

function isRecord
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isRecord", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isRecord;

function isClass
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isClass", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isClass;

function isPackage
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isPackage", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isPackage;

function isType
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isType", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end isType;

function getClassRestriction
  input String cl;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getClassRestriction", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end getClassRestriction;

function existClass
  input String cl;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "existClass", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end existClass;

function basename
  input String path;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "basename", {Values.STRING(path)}, dummyMsg);
end basename;

function dirname
  input String path;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "dirname", {Values.STRING(path)}, dummyMsg);
end dirname;

function getClassComment
  input String cl;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getClassComment", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end getClassComment;

function typeNameStrings
  input String cl;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "typeNameStrings", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end typeNameStrings;

function typeNameString
  input String cl;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "typeNameString", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end typeNameString;

function stringTypeName
  input String str;
  output String res;
protected
  Absyn.Path res_path;
algorithm
  (_,Values.CODE(Absyn.C_TYPENAME(path=res_path))) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "stringTypeName", {Values.STRING(str)}, dummyMsg);
  res := AbsynUtil.pathString(res_path);
end stringTypeName;

function getTimeStamp
  input String cl;
  output Real res1;
  output String res2;
algorithm
  (_,Values.TUPLE({Values.REAL(res1), Values.STRING(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getTimeStamp", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end getTimeStamp;

function setDocumentationAnnotation
  input String class_;
  input String info;
  input String revisions;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setDocumentationAnnotation", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.STRING(info), Values.STRING(revisions)}, dummyMsg);
end setDocumentationAnnotation;

function getDocumentationAnnotation
  input String cl;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getDocumentationAnnotation", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getDocumentationAnnotation;

function iconv
  input String string;
  input String from;
  input String to;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "iconv", {Values.STRING(string), Values.STRING(from), Values.STRING(to)}, dummyMsg);
end iconv;

function getNthImport
  input String class_;
  input Integer index;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthImport", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.INTEGER(index)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getNthImport;

function getImportedNames
  input String class_;
  output list<String> res1;
  output list<String> res2;
protected
  Values.Value res1_arr;
  Values.Value res2_arr;
algorithm
  (_,Values.TUPLE({res1_arr, res2_arr})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getImportedNames", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
  res1 := list(match res1_arr_iter case Values.STRING() then res1_arr_iter.string; end match for res1_arr_iter in ValuesUtil.arrayValues(res1_arr));
  res2 := list(match res2_arr_iter case Values.STRING() then res2_arr_iter.string; end match for res2_arr_iter in ValuesUtil.arrayValues(res2_arr));
end getImportedNames;

function getMMfileTotalDependencies
  input String in_package_name;
  input String public_imports_dir;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getMMfileTotalDependencies", {Values.STRING(in_package_name), Values.STRING(public_imports_dir)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getMMfileTotalDependencies;

function getImportCount
  input String class_;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getImportCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end getImportCount;

function getNthAnnotationString
  input String class_;
  input Integer index;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthAnnotationString", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.INTEGER(index)}, dummyMsg);
end getNthAnnotationString;

function getAnnotationCount
  input String class_;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAnnotationCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end getAnnotationCount;

function getNthInitialEquationItem
  input String class_;
  input Integer index;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthInitialEquationItem", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.INTEGER(index)}, dummyMsg);
end getNthInitialEquationItem;

function getInitialEquationItemsCount
  input String class_;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getInitialEquationItemsCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end getInitialEquationItemsCount;

function getNthEquationItem
  input String class_;
  input Integer index;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthEquationItem", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.INTEGER(index)}, dummyMsg);
end getNthEquationItem;

function getEquationItemsCount
  input String class_;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getEquationItemsCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end getEquationItemsCount;

function getNthInitialEquation
  input String class_;
  input Integer index;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthInitialEquation", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.INTEGER(index)}, dummyMsg);
end getNthInitialEquation;

function getInitialEquationCount
  input String class_;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getInitialEquationCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end getInitialEquationCount;

function getNthEquation
  input String class_;
  input Integer index;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthEquation", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.INTEGER(index)}, dummyMsg);
end getNthEquation;

function getEquationCount
  input String class_;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getEquationCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end getEquationCount;

function getNthInitialAlgorithmItem
  input String class_;
  input Integer index;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthInitialAlgorithmItem", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.INTEGER(index)}, dummyMsg);
end getNthInitialAlgorithmItem;

function getInitialAlgorithmItemsCount
  input String class_;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getInitialAlgorithmItemsCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end getInitialAlgorithmItemsCount;

function getNthAlgorithmItem
  input String class_;
  input Integer index;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthAlgorithmItem", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.INTEGER(index)}, dummyMsg);
end getNthAlgorithmItem;

function getAlgorithmItemsCount
  input String class_;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAlgorithmItemsCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end getAlgorithmItemsCount;

function getNthInitialAlgorithm
  input String class_;
  input Integer index;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthInitialAlgorithm", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.INTEGER(index)}, dummyMsg);
end getNthInitialAlgorithm;

function getInitialAlgorithmCount
  input String class_;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getInitialAlgorithmCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end getInitialAlgorithmCount;

function getNthAlgorithm
  input String class_;
  input Integer index;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthAlgorithm", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.INTEGER(index)}, dummyMsg);
end getNthAlgorithm;

function getAlgorithmCount
  input String class_;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAlgorithmCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end getAlgorithmCount;

function getConnectionList
  input String className;
  output list<list<String>> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getConnectionList", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
  res := list(list(match res_arr_iter_iter case Values.STRING() then res_arr_iter_iter.string; end match for res_arr_iter_iter in ValuesUtil.arrayValues(res_arr_iter)) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getConnectionList;

function getNthConnection
  input String className;
  input Integer index;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthConnection", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.INTEGER(index)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getNthConnection;

function getConnectionCount
  input String className;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getConnectionCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end getConnectionCount;

function updateConnectionNames
  input String className;
  input String from;
  input String to;
  input String fromNew;
  input String toNew;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "updateConnectionNames", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.STRING(from), Values.STRING(to), Values.STRING(fromNew), Values.STRING(toNew)}, dummyMsg);
end updateConnectionNames;

function updateConnectionAnnotation
  input String className;
  input String from;
  input String to;
  input String annotate;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "updateConnectionAnnotation", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.STRING(from), Values.STRING(to), Values.STRING(annotate)}, dummyMsg);
end updateConnectionAnnotation;

function getConnectorCount
  input String className;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getConnectorCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end getConnectorCount;

function setComponentProperties
  input String className;
  input String componentName;
  input list<Boolean> prefixArray;
  input list<String> variability;
  input list<Boolean> innerOuter;
  input list<String> direction;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setComponentProperties", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(componentName))), ValuesUtil.makeArray(list(Values.BOOL(prefixArray_iter) for prefixArray_iter in prefixArray)), ValuesUtil.makeArray(list(Values.STRING(variability_iter) for variability_iter in variability)), ValuesUtil.makeArray(list(Values.BOOL(innerOuter_iter) for innerOuter_iter in innerOuter)), ValuesUtil.makeArray(list(Values.STRING(direction_iter) for direction_iter in direction))}, dummyMsg);
end setComponentProperties;

function setComponentComment
  input String className;
  input String componentName;
  input String comment;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setComponentComment", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(componentName))), Values.STRING(comment)}, dummyMsg);
end setComponentComment;

function getComponentComment
  input String className;
  input String componentName;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getComponentComment", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(componentName)))}, dummyMsg);
end getComponentComment;

function removeExtendsModifiers
  input String className;
  input String baseClassName;
  input Boolean keepRedeclares;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "removeExtendsModifiers", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(baseClassName))), Values.BOOL(keepRedeclares)}, dummyMsg);
end removeExtendsModifiers;

function getInstantiatedParametersAndValues
  input String cls;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getInstantiatedParametersAndValues", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cls)))}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getInstantiatedParametersAndValues;

function getElementAnnotation
  input String elementName;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getElementAnnotation", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(elementName)))}, dummyMsg);
end getElementAnnotation;

function getNthComponentCondition
  input String className;
  input Integer n;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNthComponentCondition", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.INTEGER(n)}, dummyMsg);
end getNthComponentCondition;

function getComponentCount
  input String classPath;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getComponentCount", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(classPath)))}, dummyMsg);
end getComponentCount;

function isExtendsModifierFinal
  input String className;
  input String extendsName;
  input String modifierName;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isExtendsModifierFinal", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(extendsName))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(modifierName)))}, dummyMsg);
end isExtendsModifierFinal;

function removeElementModifiers
  input String className;
  input String componentName;
  input Boolean keepRedeclares;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "removeElementModifiers", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.STRING(componentName), Values.BOOL(keepRedeclares)}, dummyMsg);
end removeElementModifiers;

function getElementModifierValues
  input String className;
  input String modifier;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getElementModifierValues", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(modifier)))}, dummyMsg);
end getElementModifierValues;

function getElementModifierValue
  input String className;
  input String modifier;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getElementModifierValue", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(modifier)))}, dummyMsg);
end getElementModifierValue;

function getExtendsModifierNames
  input String className;
  input String extendsName;
  input Boolean useQuotes;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getExtendsModifierNames", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(extendsName))), Values.BOOL(useQuotes)}, dummyMsg);
end getExtendsModifierNames;

function getElementModifierNames
  input String className;
  input String elementName;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getElementModifierNames", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.STRING(elementName)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getElementModifierNames;

function removeComponentModifiers
  input String class_;
  input String componentName;
  input Boolean keepRedeclares;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "removeComponentModifiers", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.STRING(componentName), Values.BOOL(keepRedeclares)}, dummyMsg);
end removeComponentModifiers;

function getComponentModifierValues
  input String class_;
  input String modifier;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getComponentModifierValues", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(modifier)))}, dummyMsg);
end getComponentModifierValues;

function getComponentModifierValue
  input String class_;
  input String modifier;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getComponentModifierValue", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(modifier)))}, dummyMsg);
end getComponentModifierValue;

function getComponentModifierNames
  input String class_;
  input String componentName;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getComponentModifierNames", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.STRING(componentName)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getComponentModifierNames;

function getElements
  input String className;
  input Boolean useQuotes;
algorithm
  (_,Values.NORETCALL()) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getElements", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.BOOL(useQuotes)}, dummyMsg);
end getElements;

function getComponents
  input String className;
  input Boolean useQuotes;
algorithm
  (_,Values.NORETCALL()) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getComponents", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.BOOL(useQuotes)}, dummyMsg);
end getComponents;

function getParameterValue
  input String class_;
  input String parameterName;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getParameterValue", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.STRING(parameterName)}, dummyMsg);
end getParameterValue;

function getParameterNames
  input String class_;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getParameterNames", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getParameterNames;

function deleteComponent
  input String componentName;
  input String classPath;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "deleteComponent", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(componentName))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(classPath)))}, dummyMsg);
end deleteComponent;

function closeSimulationResultFile
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "closeSimulationResultFile", {}, dummyMsg);
end closeSimulationResultFile;

function checkCodeGraph
  input String graphfile;
  input String codefile;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "checkCodeGraph", {Values.STRING(graphfile), Values.STRING(codefile)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end checkCodeGraph;

function checkTaskGraph
  input String filename;
  input String reffilename;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "checkTaskGraph", {Values.STRING(filename), Values.STRING(reffilename)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end checkTaskGraph;

function diffSimulationResultsHtml
  input String var;
  input String actualFile;
  input String expectedFile;
  input Real relTol;
  input Real relTolDiffMinMax;
  input Real rangeDelta;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "diffSimulationResultsHtml", {Values.STRING(var), Values.STRING(actualFile), Values.STRING(expectedFile), Values.REAL(relTol), Values.REAL(relTolDiffMinMax), Values.REAL(rangeDelta)}, dummyMsg);
end diffSimulationResultsHtml;

function diffSimulationResults
  input String actualFile;
  input String expectedFile;
  input String diffPrefix;
  input Real relTol;
  input Real relTolDiffMinMax;
  input Real rangeDelta;
  input list<String> vars;
  input Boolean keepEqualResults;
  output Boolean res1;
  output list<String> res2;
protected
  Values.Value res2_arr;
algorithm
  (_,Values.TUPLE({Values.BOOL(res1), res2_arr})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "diffSimulationResults", {Values.STRING(actualFile), Values.STRING(expectedFile), Values.STRING(diffPrefix), Values.REAL(relTol), Values.REAL(relTolDiffMinMax), Values.REAL(rangeDelta), ValuesUtil.makeArray(list(Values.STRING(vars_iter) for vars_iter in vars)), Values.BOOL(keepEqualResults)}, dummyMsg);
  res2 := list(match res2_arr_iter case Values.STRING() then res2_arr_iter.string; end match for res2_arr_iter in ValuesUtil.arrayValues(res2_arr));
end diffSimulationResults;

function deltaSimulationResults
  input String filename;
  input String reffilename;
  input String method;
  input list<String> vars;
  output Real res;
algorithm
  (_,Values.REAL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "deltaSimulationResults", {Values.STRING(filename), Values.STRING(reffilename), Values.STRING(method), ValuesUtil.makeArray(list(Values.STRING(vars_iter) for vars_iter in vars))}, dummyMsg);
end deltaSimulationResults;

function compareSimulationResults
  input String filename;
  input String reffilename;
  input String logfilename;
  input Real relTol;
  input Real absTol;
  input list<String> vars;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "compareSimulationResults", {Values.STRING(filename), Values.STRING(reffilename), Values.STRING(logfilename), Values.REAL(relTol), Values.REAL(absTol), ValuesUtil.makeArray(list(Values.STRING(vars_iter) for vars_iter in vars))}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end compareSimulationResults;

function filterSimulationResults
  input String inFile;
  input String outFile;
  input list<String> vars;
  input Integer numberOfIntervals;
  input Boolean removeDescription;
  input Boolean hintReadAllVars;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "filterSimulationResults", {Values.STRING(inFile), Values.STRING(outFile), ValuesUtil.makeArray(list(Values.STRING(vars_iter) for vars_iter in vars)), Values.INTEGER(numberOfIntervals), Values.BOOL(removeDescription), Values.BOOL(hintReadAllVars)}, dummyMsg);
end filterSimulationResults;

function readSimulationResultVars
  input String fileName;
  input Boolean readParameters;
  input Boolean openmodelicaStyle;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "readSimulationResultVars", {Values.STRING(fileName), Values.BOOL(readParameters), Values.BOOL(openmodelicaStyle)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end readSimulationResultVars;

function readSimulationResultSize
  input String fileName;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "readSimulationResultSize", {Values.STRING(fileName)}, dummyMsg);
end readSimulationResultSize;

function plotAll
  input Boolean externalWindow;
  input String fileName;
  input String title;
  input String grid;
  input Boolean logX;
  input Boolean logY;
  input String xLabel;
  input String yLabel;
  input list<Real> xRange;
  input list<Real> yRange;
  input Real curveWidth;
  input Integer curveStyle;
  input String legendPosition;
  input String footer;
  input Boolean autoScale;
  input Boolean forceOMPlot;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "plotAll", {Values.BOOL(externalWindow), Values.STRING(fileName), Values.STRING(title), Values.STRING(grid), Values.BOOL(logX), Values.BOOL(logY), Values.STRING(xLabel), Values.STRING(yLabel), ValuesUtil.makeArray(list(Values.REAL(xRange_iter) for xRange_iter in xRange)), ValuesUtil.makeArray(list(Values.REAL(yRange_iter) for yRange_iter in yRange)), Values.REAL(curveWidth), Values.INTEGER(curveStyle), Values.STRING(legendPosition), Values.STRING(footer), Values.BOOL(autoScale), Values.BOOL(forceOMPlot)}, dummyMsg);
end plotAll;

function getAllSubtypeOf
  input String className;
  input String parentClass;
  input Boolean qualified;
  input Boolean includePartial;
  input Boolean sort;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAllSubtypeOf", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(parentClass))), Values.BOOL(qualified), Values.BOOL(includePartial), Values.BOOL(sort)}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getAllSubtypeOf;

function getPackages
  input String class_;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getPackages", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getPackages;

function getUsedClassNames
  input String className;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getUsedClassNames", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getUsedClassNames;

function getClassNames
  input String class_;
  input Boolean recursive;
  input Boolean qualified;
  input Boolean sort;
  input Boolean builtin;
  input Boolean showProtected;
  input Boolean includeConstants;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getClassNames", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.BOOL(recursive), Values.BOOL(qualified), Values.BOOL(sort), Values.BOOL(builtin), Values.BOOL(showProtected), Values.BOOL(includeConstants)}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getClassNames;

function setClassComment
  input String class_;
  input String filename;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setClassComment", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.STRING(filename)}, dummyMsg);
end setClassComment;

function isShortDefinition
  input String class_;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "isShortDefinition", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end isShortDefinition;

function setSourceFile
  input String class_;
  input String filename;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setSourceFile", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.STRING(filename)}, dummyMsg);
end setSourceFile;

function getSourceFile
  input String class_;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getSourceFile", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_)))}, dummyMsg);
end getSourceFile;

function refactorClass
  input String className;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "refactorClass", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end refactorClass;

function deleteClass
  input String className;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "deleteClass", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end deleteClass;

function renameClass
  input String oldName;
  input String newName;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "renameClass", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(oldName))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(newName)))}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end renameClass;

function copyClass
  input String className;
  input String newClassName;
  input String withIn;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "copyClass", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.STRING(newClassName), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(withIn)))}, dummyMsg);
end copyClass;

function moveClassToBottom
  input String className;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "moveClassToBottom", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end moveClassToBottom;

function moveClassToTop
  input String className;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "moveClassToTop", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end moveClassToTop;

function moveClass
  input String className;
  input Integer offset;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "moveClass", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.INTEGER(offset)}, dummyMsg);
end moveClass;

function newModel
  input String className;
  input String withinPath;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "newModel", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(withinPath)))}, dummyMsg);
end newModel;

function createModel
  input String className;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "createModel", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end createModel;

function reduceTerms
  input String className;
  input Real startTime;
  input Real stopTime;
  input Integer numberOfIntervals;
  input Real tolerance;
  input String method;
  input String fileNamePrefix;
  input String options;
  input String outputFormat;
  input String variableFilter;
  input String cflags;
  input String simflags;
  input String labelstoCancel;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "reduceTerms", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.REAL(startTime), Values.REAL(stopTime), Values.INTEGER(numberOfIntervals), Values.REAL(tolerance), Values.STRING(method), Values.STRING(fileNamePrefix), Values.STRING(options), Values.STRING(outputFormat), Values.STRING(variableFilter), Values.STRING(cflags), Values.STRING(simflags), Values.STRING(labelstoCancel)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end reduceTerms;

function buildLabel
  input String className;
  input Real startTime;
  input Real stopTime;
  input Integer numberOfIntervals;
  input Real tolerance;
  input String method;
  input String fileNamePrefix;
  input String options;
  input String outputFormat;
  input String variableFilter;
  input String cflags;
  input String simflags;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "buildLabel", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.REAL(startTime), Values.REAL(stopTime), Values.INTEGER(numberOfIntervals), Values.REAL(tolerance), Values.STRING(method), Values.STRING(fileNamePrefix), Values.STRING(options), Values.STRING(outputFormat), Values.STRING(variableFilter), Values.STRING(cflags), Values.STRING(simflags)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end buildLabel;

function buildEncryptedPackage
  input String className;
  input Boolean encrypt;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "buildEncryptedPackage", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.BOOL(encrypt)}, dummyMsg);
end buildEncryptedPackage;

function buildModelFMU
  input String className;
  input String version;
  input String fmuType;
  input String fileNamePrefix;
  input list<String> platforms;
  input Boolean includeResources;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "buildModelFMU", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.STRING(version), Values.STRING(fmuType), Values.STRING(fileNamePrefix), ValuesUtil.makeArray(list(Values.STRING(platforms_iter) for platforms_iter in platforms)), Values.BOOL(includeResources)}, dummyMsg);
end buildModelFMU;

function translateModelFMU
  input String className;
  input String version;
  input String fmuType;
  input String fileNamePrefix;
  input list<String> platforms;
  input Boolean includeResources;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "translateModelFMU", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.STRING(version), Values.STRING(fmuType), Values.STRING(fileNamePrefix), ValuesUtil.makeArray(list(Values.STRING(platforms_iter) for platforms_iter in platforms)), Values.BOOL(includeResources)}, dummyMsg);
end translateModelFMU;

function importFMUModelDescription
  input String filename;
  input String workdir;
  input Integer loglevel;
  input Boolean fullPath;
  input Boolean debugLogging;
  input Boolean generateInputConnectors;
  input Boolean generateOutputConnectors;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "importFMUModelDescription", {Values.STRING(filename), Values.STRING(workdir), Values.INTEGER(loglevel), Values.BOOL(fullPath), Values.BOOL(debugLogging), Values.BOOL(generateInputConnectors), Values.BOOL(generateOutputConnectors)}, dummyMsg);
end importFMUModelDescription;

function importFMU
  input String filename;
  input String workdir;
  input Integer loglevel;
  input Boolean fullPath;
  input Boolean debugLogging;
  input Boolean generateInputConnectors;
  input Boolean generateOutputConnectors;
  input String modelName;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "importFMU", {Values.STRING(filename), Values.STRING(workdir), Values.INTEGER(loglevel), Values.BOOL(fullPath), Values.BOOL(debugLogging), Values.BOOL(generateInputConnectors), Values.BOOL(generateOutputConnectors), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(modelName)))}, dummyMsg);
end importFMU;

function solveLinearSystem
  input list<list<Real>> A;
  input list<Real> B;
  output list<Real> res1;
  output Integer res2;
protected
  Values.Value res1_arr;
algorithm
  (_,Values.TUPLE({res1_arr, Values.INTEGER(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "solveLinearSystem", {ValuesUtil.makeArray(list(ValuesUtil.makeArray(list(Values.REAL(A_iter_iter) for A_iter_iter in A_iter)) for A_iter in A)), ValuesUtil.makeArray(list(Values.REAL(B_iter) for B_iter in B))}, dummyMsg);
  res1 := list(match res1_arr_iter case Values.REAL() then res1_arr_iter.real; end match for res1_arr_iter in ValuesUtil.arrayValues(res1_arr));
end solveLinearSystem;

function getLoadedLibraries
  output list<list<String>> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getLoadedLibraries", {}, dummyMsg);
  res := list(list(match res_arr_iter_iter case Values.STRING() then res_arr_iter_iter.string; end match for res_arr_iter_iter in ValuesUtil.arrayValues(res_arr_iter)) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getLoadedLibraries;

function uriToFilename
  input String uri;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "uriToFilename", {Values.STRING(uri)}, dummyMsg);
end uriToFilename;

function realpath
  input String name;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "realpath", {Values.STRING(name)}, dummyMsg);
end realpath;

function rewriteBlockCall
  input String className;
  input String inDefs;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "rewriteBlockCall", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(inDefs)))}, dummyMsg);
end rewriteBlockCall;

function generateVerificationScenarios
  input String path;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "generateVerificationScenarios", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(path)))}, dummyMsg);
end generateVerificationScenarios;

function inferBindings
  input String path;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "inferBindings", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(path)))}, dummyMsg);
end inferBindings;

function exportToFigaro
  input String path;
  input String directory;
  input String database;
  input String mode;
  input String options;
  input String processor;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "exportToFigaro", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(path))), Values.STRING(directory), Values.STRING(database), Values.STRING(mode), Values.STRING(options), Values.STRING(processor)}, dummyMsg);
end exportToFigaro;

function listFile
  input String class_;
  input Boolean nestedClasses;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "listFile", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(class_))), Values.BOOL(nestedClasses)}, dummyMsg);
end listFile;

function stringReplace
  input String str;
  input String source;
  input String target;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "stringReplace", {Values.STRING(str), Values.STRING(source), Values.STRING(target)}, dummyMsg);
end stringReplace;

function stringSplit
  input String string;
  input String token;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "stringSplit", {Values.STRING(string), Values.STRING(token)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end stringSplit;

function strtok
  input String string;
  input String token;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "strtok", {Values.STRING(string), Values.STRING(token)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end strtok;

function listVariables
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "listVariables", {}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end listVariables;

function getDerivedUnits
  input String baseUnit;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getDerivedUnits", {Values.STRING(baseUnit)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getDerivedUnits;

function convertUnits
  input String s1;
  input String s2;
  output Boolean res1;
  output Real res2;
  output Real res3;
algorithm
  (_,Values.TUPLE({Values.BOOL(res1), Values.REAL(res2), Values.REAL(res3)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "convertUnits", {Values.STRING(s1), Values.STRING(s2)}, dummyMsg);
end convertUnits;

function dumpXMLDAE
  input String className;
  input String translationLevel;
  input Boolean addOriginalAdjacencyMatrix;
  input Boolean addSolvingInfo;
  input Boolean addMathMLCode;
  input Boolean dumpResiduals;
  input String fileNamePrefix;
  input String rewriteRulesFile;
  output Boolean res1;
  output String res2;
algorithm
  (_,Values.TUPLE({Values.BOOL(res1), Values.STRING(res2)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "dumpXMLDAE", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.STRING(translationLevel), Values.BOOL(addOriginalAdjacencyMatrix), Values.BOOL(addSolvingInfo), Values.BOOL(addMathMLCode), Values.BOOL(dumpResiduals), Values.STRING(fileNamePrefix), Values.STRING(rewriteRulesFile)}, dummyMsg);
end dumpXMLDAE;

function translateGraphics
  input String className;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "translateGraphics", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end translateGraphics;

function save
  input String className;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "save", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end save;

function saveTotalModelDebug
  input String filename;
  input String className;
  input Boolean stripAnnotations;
  input Boolean stripComments;
  input Boolean obfuscate;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "saveTotalModelDebug", {Values.STRING(filename), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.BOOL(stripAnnotations), Values.BOOL(stripComments), Values.BOOL(obfuscate)}, dummyMsg);
end saveTotalModelDebug;

function saveTotalModel
  input String fileName;
  input String className;
  input Boolean stripAnnotations;
  input Boolean stripComments;
  input Boolean obfuscate;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "saveTotalModel", {Values.STRING(fileName), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.BOOL(stripAnnotations), Values.BOOL(stripComments), Values.BOOL(obfuscate)}, dummyMsg);
end saveTotalModel;

function saveModel
  input String fileName;
  input String className;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "saveModel", {Values.STRING(fileName), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end saveModel;

function deleteFile
  input String fileName;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "deleteFile", {Values.STRING(fileName)}, dummyMsg);
end deleteFile;

function loadModel
  input String className;
  input list<String> priorityVersion;
  input Boolean notify;
  input String languageStandard;
  input Boolean requireExactVersion;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "loadModel", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), ValuesUtil.makeArray(list(Values.STRING(priorityVersion_iter) for priorityVersion_iter in priorityVersion)), Values.BOOL(notify), Values.STRING(languageStandard), Values.BOOL(requireExactVersion)}, dummyMsg);
end loadModel;

function generateCode
  input String className;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "generateCode", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end generateCode;

function instantiateModel
  input String className;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "instantiateModel", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end instantiateModel;

function checkAllModelsRecursive
  input String className;
  input Boolean checkProtected;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "checkAllModelsRecursive", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.BOOL(checkProtected)}, dummyMsg);
end checkAllModelsRecursive;

function checkModel
  input String className;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "checkModel", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className)))}, dummyMsg);
end checkModel;

function remove
  input String path;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "remove", {Values.STRING(path)}, dummyMsg);
end remove;

function copy
  input String source;
  input String destination;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "copy", {Values.STRING(source), Values.STRING(destination)}, dummyMsg);
end copy;

function mkdir
  input String newDirectory;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "mkdir", {Values.STRING(newDirectory)}, dummyMsg);
end mkdir;

function cd
  input String newWorkingDirectory;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "cd", {Values.STRING(newWorkingDirectory)}, dummyMsg);
end cd;

function getAstAsCorbaString
  input String fileName;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAstAsCorbaString", {Values.STRING(fileName)}, dummyMsg);
end getAstAsCorbaString;

function getLanguageStandard
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getLanguageStandard", {}, dummyMsg);
end getLanguageStandard;

function getOrderConnections
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getOrderConnections", {}, dummyMsg);
end getOrderConnections;

function getShowAnnotations
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getShowAnnotations", {}, dummyMsg);
end getShowAnnotations;

function setShowAnnotations
  input Boolean show;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setShowAnnotations", {Values.BOOL(show)}, dummyMsg);
end setShowAnnotations;

function getDefaultOpenCLDevice
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getDefaultOpenCLDevice", {}, dummyMsg);
end getDefaultOpenCLDevice;

function getVectorizationLimit
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getVectorizationLimit", {}, dummyMsg);
end getVectorizationLimit;

function setNoSimplify
  input Boolean noSimplify;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setNoSimplify", {Values.BOOL(noSimplify)}, dummyMsg);
end setNoSimplify;

function getNoSimplify
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getNoSimplify", {}, dummyMsg);
end getNoSimplify;

function getAnnotationVersion
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAnnotationVersion", {}, dummyMsg);
end getAnnotationVersion;

function echo
  input Boolean setEcho;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "echo", {Values.BOOL(setEcho)}, dummyMsg);
end echo;

function runScript
  input String fileName;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "runScript", {Values.STRING(fileName)}, dummyMsg);
end runScript;

function clearMessages
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "clearMessages", {}, dummyMsg);
end clearMessages;

function countMessages
  output Integer res1;
  output Integer res2;
  output Integer res3;
algorithm
  (_,Values.TUPLE({Values.INTEGER(res1), Values.INTEGER(res2), Values.INTEGER(res3)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "countMessages", {}, dummyMsg);
end countMessages;

function getErrorString
  input Boolean warningsAsErrors;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getErrorString", {Values.BOOL(warningsAsErrors)}, dummyMsg);
end getErrorString;

function alarm
  input Integer seconds;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "alarm", {Values.INTEGER(seconds)}, dummyMsg);
end alarm;

function compareFiles
  input String file1;
  input String file2;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "compareFiles", {Values.STRING(file1), Values.STRING(file2)}, dummyMsg);
end compareFiles;

function compareFilesAndMove
  input String newFile;
  input String oldFile;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "compareFilesAndMove", {Values.STRING(newFile), Values.STRING(oldFile)}, dummyMsg);
end compareFilesAndMove;

function writeFile
  input String fileName;
  input String data;
  input Boolean append;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "writeFile", {Values.STRING(fileName), Values.STRING(data), Values.BOOL(append)}, dummyMsg);
end writeFile;

function readFile
  input String fileName;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "readFile", {Values.STRING(fileName)}, dummyMsg);
end readFile;

function stat
  input String fileName;
  output Boolean res1;
  output Real res2;
  output Real res3;
algorithm
  (_,Values.TUPLE({Values.BOOL(res1), Values.REAL(res2), Values.REAL(res3)})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "stat", {Values.STRING(fileName)}, dummyMsg);
end stat;

function directoryExists
  input String dirName;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "directoryExists", {Values.STRING(dirName)}, dummyMsg);
end directoryExists;

function regularFileExists
  input String fileName;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "regularFileExists", {Values.STRING(fileName)}, dummyMsg);
end regularFileExists;

function getVersion
  input String cl;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getVersion", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(cl)))}, dummyMsg);
end getVersion;

function clearCommandLineOptions
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "clearCommandLineOptions", {}, dummyMsg);
end clearCommandLineOptions;

function getConfigFlagValidOptions
  input String flag;
  output list<String> res1;
  output String res2;
  output list<String> res3;
protected
  Values.Value res1_arr;
  Values.Value res3_arr;
algorithm
  (_,Values.TUPLE({res1_arr, Values.STRING(res2), res3_arr})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getConfigFlagValidOptions", {Values.STRING(flag)}, dummyMsg);
  res1 := list(match res1_arr_iter case Values.STRING() then res1_arr_iter.string; end match for res1_arr_iter in ValuesUtil.arrayValues(res1_arr));
  res3 := list(match res3_arr_iter case Values.STRING() then res3_arr_iter.string; end match for res3_arr_iter in ValuesUtil.arrayValues(res3_arr));
end getConfigFlagValidOptions;

function getCommandLineOptions
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getCommandLineOptions", {}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end getCommandLineOptions;

function setCommandLineOptions
  input String options;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setCommandLineOptions", {Values.STRING(options)}, dummyMsg);
end setCommandLineOptions;

function getAvailableTearingMethods
  output list<String> res1;
  output list<String> res2;
protected
  Values.Value res1_arr;
  Values.Value res2_arr;
algorithm
  (_,Values.TUPLE({res1_arr, res2_arr})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAvailableTearingMethods", {}, dummyMsg);
  res1 := list(match res1_arr_iter case Values.STRING() then res1_arr_iter.string; end match for res1_arr_iter in ValuesUtil.arrayValues(res1_arr));
  res2 := list(match res2_arr_iter case Values.STRING() then res2_arr_iter.string; end match for res2_arr_iter in ValuesUtil.arrayValues(res2_arr));
end getAvailableTearingMethods;

function getTearingMethod
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getTearingMethod", {}, dummyMsg);
end getTearingMethod;

function getAvailableIndexReductionMethods
  output list<String> res1;
  output list<String> res2;
protected
  Values.Value res1_arr;
  Values.Value res2_arr;
algorithm
  (_,Values.TUPLE({res1_arr, res2_arr})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAvailableIndexReductionMethods", {}, dummyMsg);
  res1 := list(match res1_arr_iter case Values.STRING() then res1_arr_iter.string; end match for res1_arr_iter in ValuesUtil.arrayValues(res1_arr));
  res2 := list(match res2_arr_iter case Values.STRING() then res2_arr_iter.string; end match for res2_arr_iter in ValuesUtil.arrayValues(res2_arr));
end getAvailableIndexReductionMethods;

function getIndexReductionMethod
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getIndexReductionMethod", {}, dummyMsg);
end getIndexReductionMethod;

function getAvailableMatchingAlgorithms
  output list<String> res1;
  output list<String> res2;
protected
  Values.Value res1_arr;
  Values.Value res2_arr;
algorithm
  (_,Values.TUPLE({res1_arr, res2_arr})) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getAvailableMatchingAlgorithms", {}, dummyMsg);
  res1 := list(match res1_arr_iter case Values.STRING() then res1_arr_iter.string; end match for res1_arr_iter in ValuesUtil.arrayValues(res1_arr));
  res2 := list(match res2_arr_iter case Values.STRING() then res2_arr_iter.string; end match for res2_arr_iter in ValuesUtil.arrayValues(res2_arr));
end getAvailableMatchingAlgorithms;

function getMatchingAlgorithm
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getMatchingAlgorithm", {}, dummyMsg);
end getMatchingAlgorithm;

function clearDebugFlags
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "clearDebugFlags", {}, dummyMsg);
end clearDebugFlags;

function disableNewInstantiation
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "disableNewInstantiation", {}, dummyMsg);
end disableNewInstantiation;

function enableNewInstantiation
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "enableNewInstantiation", {}, dummyMsg);
end enableNewInstantiation;

function setCompilerFlags
  input String compilerFlags;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setCompilerFlags", {Values.STRING(compilerFlags)}, dummyMsg);
end setCompilerFlags;

function getHomeDirectoryPath
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getHomeDirectoryPath", {}, dummyMsg);
end getHomeDirectoryPath;

function getModelicaPath
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getModelicaPath", {}, dummyMsg);
end getModelicaPath;

function setModelicaPath
  input String modelicaPath;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setModelicaPath", {Values.STRING(modelicaPath)}, dummyMsg);
end setModelicaPath;

function getInstallationDirectoryPath
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getInstallationDirectoryPath", {}, dummyMsg);
end getInstallationDirectoryPath;

function setInstallationDirectoryPath
  input String installationDirectoryPath;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setInstallationDirectoryPath", {Values.STRING(installationDirectoryPath)}, dummyMsg);
end setInstallationDirectoryPath;

function setEnvironmentVar
  input String var;
  input String value;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setEnvironmentVar", {Values.STRING(var), Values.STRING(value)}, dummyMsg);
end setEnvironmentVar;

function getEnvironmentVar
  input String var;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getEnvironmentVar", {Values.STRING(var)}, dummyMsg);
end getEnvironmentVar;

function getTempDirectoryPath
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getTempDirectoryPath", {}, dummyMsg);
end getTempDirectoryPath;

function setTempDirectoryPath
  input String tempDirectoryPath;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setTempDirectoryPath", {Values.STRING(tempDirectoryPath)}, dummyMsg);
end setTempDirectoryPath;

function setCXXCompiler
  input String compiler;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setCXXCompiler", {Values.STRING(compiler)}, dummyMsg);
end setCXXCompiler;

function getCXXCompiler
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getCXXCompiler", {}, dummyMsg);
end getCXXCompiler;

function setCFlags
  input String inString;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setCFlags", {Values.STRING(inString)}, dummyMsg);
end setCFlags;

function getCFlags
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getCFlags", {}, dummyMsg);
end getCFlags;

function setCompiler
  input String compiler;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setCompiler", {Values.STRING(compiler)}, dummyMsg);
end setCompiler;

function getCompiler
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getCompiler", {}, dummyMsg);
end getCompiler;

function setLinkerFlags
  input String linkerFlags;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setLinkerFlags", {Values.STRING(linkerFlags)}, dummyMsg);
end setLinkerFlags;

function getLinkerFlags
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getLinkerFlags", {}, dummyMsg);
end getLinkerFlags;

function setLinker
  input String linker;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "setLinker", {Values.STRING(linker)}, dummyMsg);
end setLinker;

function getLinker
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "getLinker", {}, dummyMsg);
end getLinker;

function generateSeparateCodeDependenciesMakefile
  input String filename;
  input String directory;
  input String suffix;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "generateSeparateCodeDependenciesMakefile", {Values.STRING(filename), Values.STRING(directory), Values.STRING(suffix)}, dummyMsg);
end generateSeparateCodeDependenciesMakefile;

function generateSeparateCodeDependencies
  input String stampSuffix;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "generateSeparateCodeDependencies", {Values.STRING(stampSuffix)}, dummyMsg);
  res := list(match res_arr_iter case Values.STRING() then res_arr_iter.string; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end generateSeparateCodeDependencies;

function generateSeparateCode
  input String className;
  input Boolean cleanCache;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "generateSeparateCode", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.BOOL(cleanCache)}, dummyMsg);
end generateSeparateCode;

function generateJuliaHeader
  input String fileName;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "generateJuliaHeader", {Values.STRING(fileName)}, dummyMsg);
end generateJuliaHeader;

function generateHeader
  input String fileName;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "generateHeader", {Values.STRING(fileName)}, dummyMsg);
end generateHeader;

function clearVariables
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "clearVariables", {}, dummyMsg);
end clearVariables;

function clearProgram
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "clearProgram", {}, dummyMsg);
end clearProgram;

function clear
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "clear", {}, dummyMsg);
end clear;

function help
  input String topic;
  output String res;
algorithm
  (_,Values.STRING(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "help", {Values.STRING(topic)}, dummyMsg);
end help;

function saveAll
  input String fileName;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "saveAll", {Values.STRING(fileName)}, dummyMsg);
end saveAll;

function system_parallel
  input list<String> callStr;
  input Integer numThreads;
  output list<Integer> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "system_parallel", {ValuesUtil.makeArray(list(Values.STRING(callStr_iter) for callStr_iter in callStr)), Values.INTEGER(numThreads)}, dummyMsg);
  res := list(match res_arr_iter case Values.INTEGER() then res_arr_iter.integer; end match for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end system_parallel;

function system
  input String callStr;
  input String outputFile;
  output Integer res;
algorithm
  (_,Values.INTEGER(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "system", {Values.STRING(callStr), Values.STRING(outputFile)}, dummyMsg);
end system;

function loadFileInteractive
  input String filename;
  input String encoding;
  input Boolean uses;
  input Boolean notify;
  input Boolean requireExactVersion;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "loadFileInteractive", {Values.STRING(filename), Values.STRING(encoding), Values.BOOL(uses), Values.BOOL(notify), Values.BOOL(requireExactVersion)}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end loadFileInteractive;

function loadFileInteractiveQualified
  input String filename;
  input String encoding;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "loadFileInteractiveQualified", {Values.STRING(filename), Values.STRING(encoding)}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end loadFileInteractiveQualified;

function parseFile
  input String filename;
  input String encoding;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "parseFile", {Values.STRING(filename), Values.STRING(encoding)}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end parseFile;

function parseString
  input String data;
  input String filename;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "parseString", {Values.STRING(data), Values.STRING(filename)}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end parseString;

function loadClassContentString
  input String data;
  input String className;
  input Integer offsetX;
  input Integer offsetY;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "loadClassContentString", {Values.STRING(data), Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(className))), Values.INTEGER(offsetX), Values.INTEGER(offsetY)}, dummyMsg);
end loadClassContentString;

function loadString
  input String data;
  input String filename;
  input String encoding;
  input Boolean merge;
  input Boolean uses;
  input Boolean notify;
  input Boolean requireExactVersion;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "loadString", {Values.STRING(data), Values.STRING(filename), Values.STRING(encoding), Values.BOOL(merge), Values.BOOL(uses), Values.BOOL(notify), Values.BOOL(requireExactVersion)}, dummyMsg);
end loadString;

function reloadClass
  input String name;
  input String encoding;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "reloadClass", {Values.CODE(Absyn.C_TYPENAME(Parser.stringPath(name))), Values.STRING(encoding)}, dummyMsg);
end reloadClass;

function loadEncryptedPackage
  input String fileName;
  input String workdir;
  input Boolean skipUnzip;
  input Boolean uses;
  input Boolean notify;
  input Boolean requireExactVersion;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "loadEncryptedPackage", {Values.STRING(fileName), Values.STRING(workdir), Values.BOOL(skipUnzip), Values.BOOL(uses), Values.BOOL(notify), Values.BOOL(requireExactVersion)}, dummyMsg);
end loadEncryptedPackage;

function parseEncryptedPackage
  input String fileName;
  input String workdir;
  output list<String> res;
protected
  Values.Value res_arr;
algorithm
  (_,res_arr) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "parseEncryptedPackage", {Values.STRING(fileName), Values.STRING(workdir)}, dummyMsg);
  res := list(ValuesUtil.valString(res_arr_iter) for res_arr_iter in ValuesUtil.arrayValues(res_arr));
end parseEncryptedPackage;

function loadFiles
  input list<String> fileNames;
  input String encoding;
  input Integer numThreads;
  input Boolean uses;
  input Boolean notify;
  input Boolean requireExactVersion;
  input Boolean allowWithin;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "loadFiles", {ValuesUtil.makeArray(list(Values.STRING(fileNames_iter) for fileNames_iter in fileNames)), Values.STRING(encoding), Values.INTEGER(numThreads), Values.BOOL(uses), Values.BOOL(notify), Values.BOOL(requireExactVersion), Values.BOOL(allowWithin)}, dummyMsg);
end loadFiles;

function loadFile
  input String fileName;
  input String encoding;
  input Boolean uses;
  input Boolean notify;
  input Boolean requireExactVersion;
  input Boolean allowWithin;
  output Boolean res;
algorithm
  (_,Values.BOOL(res)) := CevalScript.cevalInteractiveFunctions2(FCore.emptyCache(), FGraph.empty(), "loadFile", {Values.STRING(fileName), Values.STRING(encoding), Values.BOOL(uses), Values.BOOL(notify), Values.BOOL(requireExactVersion), Values.BOOL(allowWithin)}, dummyMsg);
end loadFile;

annotation(__OpenModelica_Interface="backend");
end OpenModelicaScriptingAPI;
