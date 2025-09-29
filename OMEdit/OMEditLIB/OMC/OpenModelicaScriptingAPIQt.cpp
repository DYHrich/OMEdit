#include <iostream>
#include <stdexcept>
#include "OpenModelicaScriptingAPIQt.h"
#ifdef slots
#undef slots
#endif
#include "PythonEnv.h"
#include "PythonQtConverter.h"
#include "Util/StringHandler.h"
#ifdef Q_MOC_RUN
#define slots Q_SLOTS
#endif

// OMCInterface::OMCInterface(threadData_t *td)
//   : threadData(td)
// {
// }

OMCInterface::OMCInterface(threadData_t *td)
  : QObject(nullptr), threadData(td)
{
  // 添加调试信息
  if (!td) {
    qDebug() << "Warning: OMCInterface initialized with NULL threadData";
  }
}


QString OMCInterface::oms_getVersion()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("oms__getVersion()");

  QString result;
  void *result_mm = NULL;

  try {

    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getVersion()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));
  
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getVersion failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getVersion()", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_terminate(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__terminate("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__terminate("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__terminate failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__terminate("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_stepUntil(QString cref, modelica_real stopTime)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(stopTime));
  emit logCommand("oms__stepUntil("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__stepUntil("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__stepUntil failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__stepUntil("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_simulate(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__simulate("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__simulate("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__simulate failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__simulate("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setWorkingDirectory(QString newWorkingDir)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + newWorkingDir + "\"");
  emit logCommand("oms__setWorkingDirectory("+commandLog+")");

  QByteArray newWorkingDir_utf8 = newWorkingDir.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setWorkingDirectory("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setWorkingDirectory failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setWorkingDirectory("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setVariableStepSize(QString cref, modelica_real initialStepSize, modelica_real minimumStepSize, modelica_real maximumStepSize)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(initialStepSize));
  commandLog.append(",");
  commandLog.append(QString::number(minimumStepSize));
  commandLog.append(",");
  commandLog.append(QString::number(maximumStepSize));
  emit logCommand("oms__setVariableStepSize("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setVariableStepSize("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setVariableStepSize failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setVariableStepSize("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setTolerance(QString cref, modelica_real absoluteTolerance, modelica_real relativeTolerance)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(absoluteTolerance));
  commandLog.append(",");
  commandLog.append(QString::number(relativeTolerance));
  emit logCommand("oms__setTolerance("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setTolerance("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setTolerance failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setTolerance("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setTLMSocketData(QString cref, QString address, modelica_integer managerPort, modelica_integer monitorPort)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + address + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(managerPort));
  commandLog.append(",");
  commandLog.append(QString::number(monitorPort));
  emit logCommand("oms__setTLMSocketData("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray address_utf8 = address.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setTLMSocketData("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setTLMSocketData failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setTLMSocketData("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setTLMPositionAndOrientation(QString cref, modelica_real x1, modelica_real x2, modelica_real x3, modelica_real A11, modelica_real A12, modelica_real A13, modelica_real A21, modelica_real A22, modelica_real A23, modelica_real A31, modelica_real A32, modelica_real A33)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(x1));
  commandLog.append(",");
  commandLog.append(QString::number(x2));
  commandLog.append(",");
  commandLog.append(QString::number(x3));
  commandLog.append(",");
  commandLog.append(QString::number(A11));
  commandLog.append(",");
  commandLog.append(QString::number(A12));
  commandLog.append(",");
  commandLog.append(QString::number(A13));
  commandLog.append(",");
  commandLog.append(QString::number(A21));
  commandLog.append(",");
  commandLog.append(QString::number(A22));
  commandLog.append(",");
  commandLog.append(QString::number(A23));
  commandLog.append(",");
  commandLog.append(QString::number(A31));
  commandLog.append(",");
  commandLog.append(QString::number(A32));
  commandLog.append(",");
  commandLog.append(QString::number(A33));
  emit logCommand("oms__setTLMPositionAndOrientation("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setTLMPositionAndOrientation("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setTLMPositionAndOrientation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setTLMPositionAndOrientation("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setTempDirectory(QString newTempDir)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + newTempDir + "\"");
  emit logCommand("oms__setTempDirectory("+commandLog+")");

  QByteArray newTempDir_utf8 = newTempDir.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setTempDirectory("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setTempDirectory failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setTempDirectory("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setStopTime(QString cref, modelica_real stopTime)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(stopTime));
  emit logCommand("oms__setStopTime("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setStopTime("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setStopTime failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setStopTime("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setStartTime(QString cref, modelica_real startTime)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(startTime));
  emit logCommand("oms__setStartTime("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setStartTime("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setStartTime failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setStartTime("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setSignalFilter(QString cref, QString regex)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + regex + "\"");
  emit logCommand("oms__setSignalFilter("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray regex_utf8 = regex.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setSignalFilter("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setSignalFilter failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setSignalFilter("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setResultFile(QString cref, QString filename, modelica_integer bufferSize)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(bufferSize));
  emit logCommand("oms__setResultFile("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray filename_utf8 = filename.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setResultFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setResultFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setResultFile("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setRealInputDerivative(QString cref, modelica_real value)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(value));
  emit logCommand("oms__setRealInputDerivative("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setRealInputDerivative("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setRealInputDerivative failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setRealInputDerivative("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setReal(QString cref, modelica_real value)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(value));
  emit logCommand("oms__setReal("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setReal("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setReal failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setReal("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setLoggingLevel(modelica_integer logLevel)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(QString::number(logLevel));
  emit logCommand("oms__setLoggingLevel("+commandLog+")");

  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setLoggingLevel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setLoggingLevel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setLoggingLevel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setLoggingInterval(QString cref, modelica_real loggingInterval)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(loggingInterval));
  emit logCommand("oms__setLoggingInterval("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setLoggingInterval("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setLoggingInterval failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setLoggingInterval("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setLogFile(QString filename)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  emit logCommand("oms__setLogFile("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setLogFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setLogFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setLogFile("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setInteger(QString cref, modelica_integer value)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(value));
  emit logCommand("oms__setInteger("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setInteger("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setInteger failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setInteger("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setFixedStepSize(QString cref, modelica_real stepSize)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(stepSize));
  emit logCommand("oms__setFixedStepSize("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setFixedStepSize("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setFixedStepSize failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setFixedStepSize("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setCommandLineOption(QString cmd)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cmd + "\"");
  emit logCommand("oms__setCommandLineOption("+commandLog+")");

  QByteArray cmd_utf8 = cmd.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setCommandLineOption("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setCommandLineOption failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setCommandLineOption("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_setBoolean(QString cref, modelica_boolean value)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(value ? "true" : "false");
  emit logCommand("oms__setBoolean("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__setBoolean("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__setBoolean failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__setBoolean("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_RunFile(QString filename)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  emit logCommand("oms__RunFile("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__RunFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__RunFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__RunFile("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_reset(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__reset("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__reset("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__reset failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__reset("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_rename(QString cref, QString newCref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + newCref + "\"");
  emit logCommand("oms__rename("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray newCref_utf8 = newCref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__rename("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__rename failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__rename("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_removeSignalsFromResults(QString cref, QString regex)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + regex + "\"");
  emit logCommand("oms__removeSignalsFromResults("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray regex_utf8 = regex.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__removeSignalsFromResults("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__removeSignalsFromResults failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__removeSignalsFromResults("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_newModel(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__newModel("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__newModel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__newModel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__newModel("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_loadSnapshot_res OMCInterface::oms_loadSnapshot(QString cref, QString snapshot)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + snapshot + "\"");
  emit logCommand("oms__loadSnapshot("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray snapshot_utf8 = snapshot.toUtf8();
  oms_loadSnapshot_res result;
  void *out1_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__loadSnapshot("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_loadSnapshot_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__loadSnapshot failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__loadSnapshot("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_listUnconnectedConnectors_res OMCInterface::oms_listUnconnectedConnectors(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__listUnconnectedConnectors("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_listUnconnectedConnectors_res result;
  void *out1_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__listUnconnectedConnectors("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_listUnconnectedConnectors_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__listUnconnectedConnectors failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__listUnconnectedConnectors("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_list_res OMCInterface::oms_list(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__list("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_list_res result;
  void *out1_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__list("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_list_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__list failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__list("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_instantiate(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__instantiate("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__instantiate("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__instantiate failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__instantiate("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_initialize(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__initialize("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__initialize("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__initialize failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__initialize("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_importSnapshot(QString cref, QString snapshot)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + snapshot + "\"");
  emit logCommand("oms__importSnapshot("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray snapshot_utf8 = snapshot.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__importSnapshot("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__importSnapshot failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__importSnapshot("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_importFile_res OMCInterface::oms_importFile(QString filename)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  emit logCommand("oms__importFile("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  oms_importFile_res result;
  void *out1_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__importFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_importFile_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__importFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__importFile("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_getVariableStepSize_res OMCInterface::oms_getVariableStepSize(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__getVariableStepSize("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_getVariableStepSize_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getVariableStepSize("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_getVariableStepSize_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getVariableStepSize failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getVariableStepSize("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_getTolerance_res OMCInterface::oms_getTolerance(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__getTolerance("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_getTolerance_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getTolerance("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_getTolerance_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getTolerance failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getTolerance("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_getSystemType_res OMCInterface::oms_getSystemType(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__getSystemType("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_getSystemType_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getSystemType("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_getSystemType_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getSystemType failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getSystemType("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_getSubModelPath_res OMCInterface::oms_getSubModelPath(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__getSubModelPath("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_getSubModelPath_res result;
  void *out1_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getSubModelPath("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_getSubModelPath_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getSubModelPath failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getSubModelPath("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_getStopTime_res OMCInterface::oms_getStopTime(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__getStopTime("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_getStopTime_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getStopTime("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_getStopTime_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getStopTime failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getStopTime("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_getStartTime_res OMCInterface::oms_getStartTime(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__getStartTime("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_getStartTime_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getStartTime("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_getStartTime_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getStartTime failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getStartTime("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_getSolver_res OMCInterface::oms_getSolver(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__getSolver("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_getSolver_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getSolver("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_getSolver_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getSolver failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getSolver("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_getReal_res OMCInterface::oms_getReal(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__getReal("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_getReal_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getReal("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_getReal_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getReal failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getReal("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_getModelState_res OMCInterface::oms_getModelState(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__getModelState("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_getModelState_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getModelState("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_getModelState_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getModelState failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getModelState("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_getInteger(QString cref, modelica_integer value)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(value));
  emit logCommand("oms__getInteger("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getInteger("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getInteger failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getInteger("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_getFixedStepSize_res OMCInterface::oms_getFixedStepSize(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__getFixedStepSize("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_getFixedStepSize_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getFixedStepSize("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_getFixedStepSize_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getFixedStepSize failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getFixedStepSize("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_getBoolean_res OMCInterface::oms_getBoolean(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__getBoolean("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_getBoolean_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__getBoolean("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_getBoolean_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__getBoolean failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__getBoolean("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_extractFMIKind_res OMCInterface::oms_extractFMIKind(QString filename)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  emit logCommand("oms__extractFMIKind("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  oms_extractFMIKind_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__extractFMIKind("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_extractFMIKind_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__extractFMIKind failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__extractFMIKind("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::oms_exportSnapshot_res OMCInterface::oms_exportSnapshot(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__exportSnapshot("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  oms_exportSnapshot_res result;
  void *out1_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__exportSnapshot("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToOms_exportSnapshot_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__exportSnapshot failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__exportSnapshot("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_exportDependencyGraphs(QString cref, QString initialization, QString event, QString simulation)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + initialization + "\"");
  commandLog.append(",");
  commandLog.append("\"" + event + "\"");
  commandLog.append(",");
  commandLog.append("\"" + simulation + "\"");
  emit logCommand("oms__exportDependencyGraphs("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray initialization_utf8 = initialization.toUtf8();
  QByteArray event_utf8 = event.toUtf8();
  QByteArray simulation_utf8 = simulation.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__exportDependencyGraphs("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__exportDependencyGraphs failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__exportDependencyGraphs("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_export(QString cref, QString filename)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + filename + "\"");
  emit logCommand("oms__export("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray filename_utf8 = filename.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__export("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__export failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__export("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_deleteConnectorFromTLMBus(QString busCref, QString connectorCref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + busCref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + connectorCref + "\"");
  emit logCommand("oms__deleteConnectorFromTLMBus("+commandLog+")");

  QByteArray busCref_utf8 = busCref.toUtf8();
  QByteArray connectorCref_utf8 = connectorCref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__deleteConnectorFromTLMBus("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__deleteConnectorFromTLMBus failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__deleteConnectorFromTLMBus("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_deleteConnectorFromBus(QString busCref, QString connectorCref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + busCref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + connectorCref + "\"");
  emit logCommand("oms__deleteConnectorFromBus("+commandLog+")");

  QByteArray busCref_utf8 = busCref.toUtf8();
  QByteArray connectorCref_utf8 = connectorCref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__deleteConnectorFromBus("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__deleteConnectorFromBus failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__deleteConnectorFromBus("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_deleteConnection(QString crefA, QString crefB)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + crefA + "\"");
  commandLog.append(",");
  commandLog.append("\"" + crefB + "\"");
  emit logCommand("oms__deleteConnection("+commandLog+")");

  QByteArray crefA_utf8 = crefA.toUtf8();
  QByteArray crefB_utf8 = crefB.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__deleteConnection("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__deleteConnection failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__deleteConnection("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_delete(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__delete("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__delete("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__delete failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__delete("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_copySystem(QString source, QString target)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + source + "\"");
  commandLog.append(",");
  commandLog.append("\"" + target + "\"");
  emit logCommand("oms__copySystem("+commandLog+")");

  QByteArray source_utf8 = source.toUtf8();
  QByteArray target_utf8 = target.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__copySystem("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__copySystem failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__copySystem("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_compareSimulationResults(QString filenameA, QString filenameB, QString var, modelica_real relTol, modelica_real absTol)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filenameA + "\"");
  commandLog.append(",");
  commandLog.append("\"" + filenameB + "\"");
  commandLog.append(",");
  commandLog.append("\"" + var + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(relTol));
  commandLog.append(",");
  commandLog.append(QString::number(absTol));
  emit logCommand("oms__compareSimulationResults("+commandLog+")");

  QByteArray filenameA_utf8 = filenameA.toUtf8();
  QByteArray filenameB_utf8 = filenameB.toUtf8();
  QByteArray var_utf8 = var.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__compareSimulationResults("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__compareSimulationResults failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__compareSimulationResults("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addTLMConnection(QString crefA, QString crefB, modelica_real delay, modelica_real alpha, modelica_real linearimpedance, modelica_real angularimpedance)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + crefA + "\"");
  commandLog.append(",");
  commandLog.append("\"" + crefB + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(delay));
  commandLog.append(",");
  commandLog.append(QString::number(alpha));
  commandLog.append(",");
  commandLog.append(QString::number(linearimpedance));
  commandLog.append(",");
  commandLog.append(QString::number(angularimpedance));
  emit logCommand("oms__addTLMConnection("+commandLog+")");

  QByteArray crefA_utf8 = crefA.toUtf8();
  QByteArray crefB_utf8 = crefB.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addTLMConnection("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addTLMConnection failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addTLMConnection("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addTimeIndicator(QString signal)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + signal + "\"");
  emit logCommand("oms__addTimeIndicator("+commandLog+")");

  QByteArray signal_utf8 = signal.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addTimeIndicator("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addTimeIndicator failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addTimeIndicator("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addSubModel(QString cref, QString fmuPath)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + fmuPath + "\"");
  emit logCommand("oms__addSubModel("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray fmuPath_utf8 = fmuPath.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addSubModel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addSubModel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addSubModel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addStaticValueIndicator(QString signal, modelica_real lower, modelica_real upper, modelica_real stepSize)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + signal + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(lower));
  commandLog.append(",");
  commandLog.append(QString::number(upper));
  commandLog.append(",");
  commandLog.append(QString::number(stepSize));
  emit logCommand("oms__addStaticValueIndicator("+commandLog+")");

  QByteArray signal_utf8 = signal.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addStaticValueIndicator("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addStaticValueIndicator failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addStaticValueIndicator("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addSignalsToResults(QString cref, QString regex)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + regex + "\"");
  emit logCommand("oms__addSignalsToResults("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray regex_utf8 = regex.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addSignalsToResults("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addSignalsToResults failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addSignalsToResults("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addExternalModel(QString cref, QString path, QString startscript)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + path + "\"");
  commandLog.append(",");
  commandLog.append("\"" + startscript + "\"");
  emit logCommand("oms__addExternalModel("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  QByteArray path_utf8 = path.toUtf8();
  QByteArray startscript_utf8 = startscript.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addExternalModel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addExternalModel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addExternalModel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addEventIndicator(QString signal)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + signal + "\"");
  emit logCommand("oms__addEventIndicator("+commandLog+")");

  QByteArray signal_utf8 = signal.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addEventIndicator("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addEventIndicator failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addEventIndicator("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addDynamicValueIndicator(QString signal, QString lower, QString upper, modelica_real stepSize)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + signal + "\"");
  commandLog.append(",");
  commandLog.append("\"" + lower + "\"");
  commandLog.append(",");
  commandLog.append("\"" + upper + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(stepSize));
  emit logCommand("oms__addDynamicValueIndicator("+commandLog+")");

  QByteArray signal_utf8 = signal.toUtf8();
  QByteArray lower_utf8 = lower.toUtf8();
  QByteArray upper_utf8 = upper.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addDynamicValueIndicator("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addDynamicValueIndicator failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addDynamicValueIndicator("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addConnectorToTLMBus(QString busCref, QString connectorCref, QString type_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + busCref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + connectorCref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + type_ + "\"");
  emit logCommand("oms__addConnectorToTLMBus("+commandLog+")");

  QByteArray busCref_utf8 = busCref.toUtf8();
  QByteArray connectorCref_utf8 = connectorCref.toUtf8();
  QByteArray type__utf8 = type_.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addConnectorToTLMBus("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addConnectorToTLMBus failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addConnectorToTLMBus("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addConnectorToBus(QString busCref, QString connectorCref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + busCref + "\"");
  commandLog.append(",");
  commandLog.append("\"" + connectorCref + "\"");
  emit logCommand("oms__addConnectorToBus("+commandLog+")");

  QByteArray busCref_utf8 = busCref.toUtf8();
  QByteArray connectorCref_utf8 = connectorCref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addConnectorToBus("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addConnectorToBus failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addConnectorToBus("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addConnection(QString crefA, QString crefB)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + crefA + "\"");
  commandLog.append(",");
  commandLog.append("\"" + crefB + "\"");
  emit logCommand("oms__addConnection("+commandLog+")");

  QByteArray crefA_utf8 = crefA.toUtf8();
  QByteArray crefB_utf8 = crefB.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addConnection("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addConnection failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addConnection("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::oms_addBus(QString cref)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + cref + "\"");
  emit logCommand("oms__addBus("+commandLog+")");

  QByteArray cref_utf8 = cref.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "oms__addBus("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("oms__addBus failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("oms__addBus("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::unloadOMSimulator()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("unloadOMSimulator()");

  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "unloadOMSimulator()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("unloadOMSimulator failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("unloadOMSimulator()", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::loadOMSimulator()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("loadOMSimulator()");

  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "loadOMSimulator()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("loadOMSimulator failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("loadOMSimulator()", responseLog, elapsed);

  return result;
}
QString OMCInterface::getDefinitions(modelica_boolean addFunctions)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(addFunctions ? "true" : "false");
  emit logCommand("getDefinitions("+commandLog+")");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getDefinitions("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getDefinitions failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getDefinitions("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::qualifyPath(QString classPath, QString path)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(classPath);
  commandLog.append(",");
  commandLog.append(path);
  emit logCommand("qualifyPath("+commandLog+")");

  QByteArray classPath_utf8 = classPath.toUtf8();
  QByteArray path_utf8 = path.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "qualifyPath("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("qualifyPath failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result);
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("qualifyPath("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::restoreAST(modelica_integer id)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(QString::number(id));
  emit logCommand("restoreAST("+commandLog+")");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "restoreAST("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("restoreAST failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("restoreAST("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::storeAST()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("storeAST()");

  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "storeAST()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("storeAST failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("storeAST()", responseLog, elapsed);

  return result;
}
QString OMCInterface::modifierToJSON(QString modifier, modelica_boolean prettyPrint)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + modifier + "\"");
  commandLog.append(",");
  commandLog.append(prettyPrint ? "true" : "false");
  emit logCommand("modifierToJSON("+commandLog+")");

  QByteArray modifier_utf8 = modifier.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "modifierToJSON("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("modifierToJSON failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("modifierToJSON("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getModelInstanceAnnotation(QString className, QList<QString > filter, modelica_boolean prettyPrint)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("{");
  int filter_i = 0;
  foreach(QString filter_elt, filter) {
    if (filter_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + filter_elt + "\"");
    filter_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append(prettyPrint ? "true" : "false");
  emit logCommand("getModelInstanceAnnotation("+commandLog+")");

  // QByteArray className_utf8 = className.toUtf8();
  // void *filter_lst = mmc_mk_nil();
  // for (int filter_i = filter.size()-1; filter_i>=0; filter_i--) {
  //   QString filter_elt = filter[filter_i];
  //   QByteArray filter_elt_utf8 = filter_elt.toUtf8();
  //   filter_lst = mmc_mk_cons(mmc_mk_scon(filter_elt_utf8.constData()), filter_lst);
  // }
  QString result;
  // void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getModelInstanceAnnotation("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getModelInstanceAnnotation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getModelInstanceAnnotation("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getModelInstance(QString className, QString modifier, modelica_boolean prettyPrint)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("\"" + modifier + "\"");
  commandLog.append(",");
  commandLog.append(prettyPrint ? "true" : "false");
  emit logCommand("getModelInstance("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray modifier_utf8 = modifier.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getModelInstance("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));
    // std::cout << result.toStdString() << std::endl;



    
  } catch(std::exception &exception) {
    emit throwException(QString("getModelInstance failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getModelInstance("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::convertPackageToLibrary(QString packageToConvert, QString library, QString libraryVersion)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(packageToConvert);
  commandLog.append(",");
  commandLog.append(library);
  commandLog.append(",");
  commandLog.append("\"" + libraryVersion + "\"");
  emit logCommand("convertPackageToLibrary("+commandLog+")");

  QByteArray packageToConvert_utf8 = packageToConvert.toUtf8();
  QByteArray library_utf8 = library.toUtf8();
  QByteArray libraryVersion_utf8 = libraryVersion.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "convertPackageToLibrary("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("convertPackageToLibrary failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("convertPackageToLibrary("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::runConversionScript(QString packageToConvert, QString scriptFile)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(packageToConvert);
  commandLog.append(",");
  commandLog.append("\"" + scriptFile + "\"");
  emit logCommand("runConversionScript("+commandLog+")");

  QByteArray packageToConvert_utf8 = packageToConvert.toUtf8();
  QByteArray scriptFile_utf8 = scriptFile.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "runConversionScript("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("runConversionScript failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("runConversionScript("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::generateScriptingAPI_res OMCInterface::generateScriptingAPI(QString cl, QString name)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  commandLog.append(",");
  commandLog.append("\"" + name + "\"");
  emit logCommand("generateScriptingAPI("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QByteArray name_utf8 = name.toUtf8();
  generateScriptingAPI_res result;
  void *out2_mm = NULL;
  void *out3_mm = NULL;
  void *out4_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "generateScriptingAPI("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToGenerateScriptingAPI_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("generateScriptingAPI failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("generateScriptingAPI("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::deleteInitialState(QString cl, QString state)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  commandLog.append(",");
  commandLog.append("\"" + state + "\"");
  emit logCommand("deleteInitialState("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QByteArray state_utf8 = state.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "deleteInitialState("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("deleteInitialState failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("deleteInitialState("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QList<QString > > OMCInterface::getInitialStates(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("getInitialStates("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QList<QList<QString > > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getInitialStates("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getInitialStates failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QList<QString > result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("{");
    int result_elt_i = 0;
    foreach(QString result_elt_elt, result_elt) {
      if (result_elt_i) {
        responseLog.append(",");
      }
      responseLog.append("\"" + result_elt_elt + "\"");
      result_elt_i++;
    }
    responseLog.append("}");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getInitialStates("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::deleteTransition(QString cl, QString from, QString to, QString condition, modelica_boolean immediate, modelica_boolean reset, modelica_boolean synchronize, modelica_integer priority)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  commandLog.append(",");
  commandLog.append("\"" + from + "\"");
  commandLog.append(",");
  commandLog.append("\"" + to + "\"");
  commandLog.append(",");
  commandLog.append("\"" + condition + "\"");
  commandLog.append(",");
  commandLog.append(immediate ? "true" : "false");
  commandLog.append(",");
  commandLog.append(reset ? "true" : "false");
  commandLog.append(",");
  commandLog.append(synchronize ? "true" : "false");
  commandLog.append(",");
  commandLog.append(QString::number(priority));
  emit logCommand("deleteTransition("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QByteArray from_utf8 = from.toUtf8();
  QByteArray to_utf8 = to.toUtf8();
  QByteArray condition_utf8 = condition.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "deleteTransition("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("deleteTransition failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("deleteTransition("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QList<QString > > OMCInterface::getTransitions(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("getTransitions("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QList<QList<QString > > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getTransitions("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getTransitions failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QList<QString > result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("{");
    int result_elt_i = 0;
    foreach(QString result_elt_elt, result_elt) {
      if (result_elt_i) {
        responseLog.append(",");
      }
      responseLog.append("\"" + result_elt_elt + "\"");
      result_elt_i++;
    }
    responseLog.append("}");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getTransitions("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getEnumerationLiterals(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("getEnumerationLiterals("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getEnumerationLiterals("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getEnumerationLiterals failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getEnumerationLiterals("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getDefaultComponentPrefixes(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("getDefaultComponentPrefixes("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getDefaultComponentPrefixes("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getDefaultComponentPrefixes failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getDefaultComponentPrefixes("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getDefaultComponentName(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("getDefaultComponentName("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getDefaultComponentName("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getDefaultComponentName failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getDefaultComponentName("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::getClassInformation_res OMCInterface::getClassInformation(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("getClassInformation("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  getClassInformation_res result;
  void *out1_mm = NULL;
  void *out2_mm = NULL;
  void *out6_mm = NULL;
  void *out12_mm = NULL;
  void *out15_mm = NULL;
  void *out16_mm = NULL;
  void *out18_mm = NULL;
  void *out19_mm = NULL;
  void *out20_mm = NULL;
  void *out21_mm = NULL;
  void *out22_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getClassInformation("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToGetClassInformation_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getClassInformation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getClassInformation("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::sortStrings(QList<QString > arr)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("{");
  int arr_i = 0;
  foreach(QString arr_elt, arr) {
    if (arr_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + arr_elt + "\"");
    arr_i++;
  }
  commandLog.append("}");
  emit logCommand("sortStrings("+commandLog+")");

  // void *arr_lst = mmc_mk_nil();
  // for (int arr_i = arr.size()-1; arr_i>=0; arr_i--) {
  //   QString arr_elt = arr[arr_i];
  //   QByteArray arr_elt_utf8 = arr_elt.toUtf8();
  //   arr_lst = mmc_mk_cons(mmc_mk_scon(arr_elt_utf8.constData()), arr_lst);
  // }
  QList<QString > result;
  // void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "sortStrings("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("sortStrings failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("sortStrings("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::checkInterfaceOfPackages(QString cl, QList<QList<QString > > dependencyMatrix)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  commandLog.append(",");
  commandLog.append("{");
  int dependencyMatrix_i = 0;
  foreach(QList<QString > dependencyMatrix_elt, dependencyMatrix) {
    if (dependencyMatrix_i) {
      commandLog.append(",");
    }
    commandLog.append("{");
    int dependencyMatrix_elt_i = 0;
    foreach(QString dependencyMatrix_elt_elt, dependencyMatrix_elt) {
      if (dependencyMatrix_elt_i) {
        commandLog.append(",");
      }
      commandLog.append("\"" + dependencyMatrix_elt_elt + "\"");
      dependencyMatrix_elt_i++;
    }
    commandLog.append("}");
    dependencyMatrix_i++;
  }
  commandLog.append("}");
  emit logCommand("checkInterfaceOfPackages("+commandLog+")");

  // QByteArray cl_utf8 = cl.toUtf8();
  // void *dependencyMatrix_lst = mmc_mk_nil();
  // for (int dependencyMatrix_i = dependencyMatrix.size()-1; dependencyMatrix_i>=0; dependencyMatrix_i--) {
  //   QList<QString > dependencyMatrix_elt = dependencyMatrix[dependencyMatrix_i];
  //   void *dependencyMatrix_elt_lst = mmc_mk_nil();
  //   for (int dependencyMatrix_elt_i = dependencyMatrix_elt.size()-1; dependencyMatrix_elt_i>=0; dependencyMatrix_elt_i--) {
  //     QString dependencyMatrix_elt_elt = dependencyMatrix_elt[dependencyMatrix_elt_i];
  //     QByteArray dependencyMatrix_elt_elt_utf8 = dependencyMatrix_elt_elt.toUtf8();
  //     dependencyMatrix_elt_lst = mmc_mk_cons(mmc_mk_scon(dependencyMatrix_elt_elt_utf8.constData()), dependencyMatrix_elt_lst);
  //   }
  //   dependencyMatrix_lst = mmc_mk_cons(dependencyMatrix_elt_lst, dependencyMatrix_lst);
  // }
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "checkInterfaceOfPackages("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("checkInterfaceOfPackages failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("checkInterfaceOfPackages("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::GC_set_max_heap_size(modelica_integer size)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(QString::number(size));
  emit logCommand("GC__set__max__heap__size("+commandLog+")");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "GC__set__max__heap__size("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("GC__set__max__heap__size failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("GC__set__max__heap__size("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::GC_expand_hp(modelica_integer size)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(QString::number(size));
  emit logCommand("GC__expand__hp("+commandLog+")");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "GC__expand__hp("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("GC__expand__hp failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("GC__expand__hp("+commandLog+")", responseLog, elapsed);

  return result;
}
void OMCInterface::GC_gcollect_and_unmap()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("GC__gcollect__and__unmap()");


  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "GC__gcollect__and__unmap()";
    python_env.send_expression_object(command, false);



    
  } catch(std::exception &exception) {
    emit throwException(QString("GC__gcollect__and__unmap failed. %1").arg(exception.what()));
  }

  QString responseLog;
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("GC__gcollect__and__unmap()", responseLog, elapsed);

}
modelica_real OMCInterface::getMemorySize()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getMemorySize()");

  modelica_real result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getMemorySize()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaReal(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getMemorySize failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getMemorySize()", responseLog, elapsed);

  return result;
}
void OMCInterface::threadWorkFailed()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("threadWorkFailed()");


  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "threadWorkFailed()";
    python_env.send_expression_object(command, false);



    
  } catch(std::exception &exception) {
    emit throwException(QString("threadWorkFailed failed. %1").arg(exception.what()));
  }

  QString responseLog;
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("threadWorkFailed()", responseLog, elapsed);

}
void OMCInterface::exit(modelica_integer status)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(QString::number(status));
  emit logCommand("exit("+commandLog+")");


  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "exit("+commandLog.toStdString()+")";
    python_env.send_expression_object(command, false);



    
  } catch(std::exception &exception) {
    emit throwException(QString("exit failed. %1").arg(exception.what()));
  }

  QString responseLog;
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("exit("+commandLog+")", responseLog, elapsed);

}
QList<modelica_boolean > OMCInterface::runScriptParallel(QList<QString > scripts, modelica_integer numThreads, modelica_boolean useThreads)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("{");
  int scripts_i = 0;
  foreach(QString scripts_elt, scripts) {
    if (scripts_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + scripts_elt + "\"");
    scripts_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append(QString::number(numThreads));
  commandLog.append(",");
  commandLog.append(useThreads ? "true" : "false");
  emit logCommand("runScriptParallel("+commandLog+")");

  // void *scripts_lst = mmc_mk_nil();
  // for (int scripts_i = scripts.size()-1; scripts_i>=0; scripts_i--) {
  //   QString scripts_elt = scripts[scripts_i];
  //   QByteArray scripts_elt_utf8 = scripts_elt.toUtf8();
  //   scripts_lst = mmc_mk_cons(mmc_mk_scon(scripts_elt_utf8.constData()), scripts_lst);
  // }
  QList<modelica_boolean > result;
  // void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "runScriptParallel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("runScriptParallel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(modelica_boolean result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt ? "true" : "false");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("runScriptParallel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::numProcessors()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("numProcessors()");

  modelica_integer result;

  try {

    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "numProcessors()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);

    
  } catch(std::exception &exception) {
    emit throwException(QString("numProcessors failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("numProcessors()", responseLog, elapsed);

  return result;
}
void OMCInterface::generateEntryPoint(QString fileName, QString entryPoint, QString url)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  commandLog.append(",");
  commandLog.append(entryPoint);
  commandLog.append(",");
  commandLog.append("\"" + url + "\"");
  emit logCommand("generateEntryPoint("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  QByteArray entryPoint_utf8 = entryPoint.toUtf8();
  QByteArray url_utf8 = url.toUtf8();

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "generateEntryPoint("+commandLog.toStdString()+")";
    python_env.send_expression_object(command, false);



    
  } catch(std::exception &exception) {
    emit throwException(QString("generateEntryPoint failed. %1").arg(exception.what()));
  }

  QString responseLog;
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("generateEntryPoint("+commandLog+")", responseLog, elapsed);

}
QString OMCInterface::getDerivedClassModifierValue(QString className, QString modifierName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(modifierName);
  emit logCommand("getDerivedClassModifierValue("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray modifierName_utf8 = modifierName.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getDerivedClassModifierValue("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getDerivedClassModifierValue failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getDerivedClassModifierValue("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getDerivedClassModifierNames(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("getDerivedClassModifierNames("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getDerivedClassModifierNames("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getDerivedClassModifierNames failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getDerivedClassModifierNames("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::getConversionsFromVersions_res OMCInterface::getConversionsFromVersions(QString pack)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(pack);
  emit logCommand("getConversionsFromVersions("+commandLog+")");

  QByteArray pack_utf8 = pack.toUtf8();
  getConversionsFromVersions_res result;
  void *out1_mm = NULL;
  void *out2_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getConversionsFromVersions("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToGetConversionsFromVersions_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getConversionsFromVersions failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getConversionsFromVersions("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QList<QString > > OMCInterface::getUses(QString pack)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(pack);
  emit logCommand("getUses("+commandLog+")");

  QByteArray pack_utf8 = pack.toUtf8();
  QList<QList<QString > > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getUses("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getUses failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QList<QString > result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("{");
    int result_elt_i = 0;
    foreach(QString result_elt_elt, result_elt) {
      if (result_elt_i) {
        responseLog.append(",");
      }
      responseLog.append("\"" + result_elt_elt + "\"");
      result_elt_i++;
    }
    responseLog.append("}");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getUses("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::upgradeInstalledPackages(modelica_boolean installNewestVersions)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(installNewestVersions ? "true" : "false");
  emit logCommand("upgradeInstalledPackages("+commandLog+")");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "upgradeInstalledPackages("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("upgradeInstalledPackages failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("upgradeInstalledPackages("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getAvailablePackageConversionsFrom(QString pkg, QString version)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(pkg);
  commandLog.append(",");
  commandLog.append("\"" + version + "\"");
  emit logCommand("getAvailablePackageConversionsFrom("+commandLog+")");

  QByteArray pkg_utf8 = pkg.toUtf8();
  QByteArray version_utf8 = version.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAvailablePackageConversionsFrom("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAvailablePackageConversionsFrom failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAvailablePackageConversionsFrom("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getAvailablePackageConversionsTo(QString pkg, QString version)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(pkg);
  commandLog.append(",");
  commandLog.append("\"" + version + "\"");
  emit logCommand("getAvailablePackageConversionsTo("+commandLog+")");

  QByteArray pkg_utf8 = pkg.toUtf8();
  QByteArray version_utf8 = version.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAvailablePackageConversionsTo("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAvailablePackageConversionsTo failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAvailablePackageConversionsTo("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getAvailablePackageVersions(QString pkg, QString version)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(pkg);
  commandLog.append(",");
  commandLog.append("\"" + version + "\"");
  emit logCommand("getAvailablePackageVersions("+commandLog+")");

  QByteArray pkg_utf8 = pkg.toUtf8();
  QByteArray version_utf8 = version.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAvailablePackageVersions("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAvailablePackageVersions failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAvailablePackageVersions("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::updatePackageIndex()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("updatePackageIndex()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "updatePackageIndex()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("updatePackageIndex failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("updatePackageIndex()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::installPackage(QString pkg, QString version, modelica_boolean exactMatch)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(pkg);
  commandLog.append(",");
  commandLog.append("\"" + version + "\"");
  commandLog.append(",");
  commandLog.append(exactMatch ? "true" : "false");
  emit logCommand("installPackage("+commandLog+")");

  QByteArray pkg_utf8 = pkg.toUtf8();
  QByteArray version_utf8 = version.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "installPackage("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("installPackage failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("installPackage("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getAvailableLibraryVersions(QString libraryName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(libraryName);
  emit logCommand("getAvailableLibraryVersions("+commandLog+")");

  QByteArray libraryName_utf8 = libraryName.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAvailableLibraryVersions("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAvailableLibraryVersions failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAvailableLibraryVersions("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getAvailableLibraries()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getAvailableLibraries()");

  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAvailableLibraries()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAvailableLibraries failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAvailableLibraries()", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::searchClassNames(QString searchText, modelica_boolean findInText)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + searchText + "\"");
  commandLog.append(",");
  commandLog.append(findInText ? "true" : "false");
  emit logCommand("searchClassNames("+commandLog+")");

  QByteArray searchText_utf8 = searchText.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "searchClassNames("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("searchClassNames failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("searchClassNames("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::extendsFrom(QString className, QString baseClassName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(baseClassName);
  emit logCommand("extendsFrom("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray baseClassName_utf8 = baseClassName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "extendsFrom("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("extendsFrom failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("extendsFrom("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::getBooleanClassAnnotation(QString className, QString annotationName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(annotationName);
  emit logCommand("getBooleanClassAnnotation("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray annotationName_utf8 = annotationName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getBooleanClassAnnotation("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getBooleanClassAnnotation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getBooleanClassAnnotation("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::classAnnotationExists(QString className, QString annotationName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(annotationName);
  emit logCommand("classAnnotationExists("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray annotationName_utf8 = annotationName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "classAnnotationExists("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("classAnnotationExists failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("classAnnotationExists("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getAnnotationModifierValue(QString className, QString annotationName, QString modifierName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("\"" + annotationName + "\"");
  commandLog.append(",");
  commandLog.append("\"" + modifierName + "\"");
  emit logCommand("getAnnotationModifierValue("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray annotationName_utf8 = annotationName.toUtf8();
  QByteArray modifierName_utf8 = modifierName.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAnnotationModifierValue("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAnnotationModifierValue failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAnnotationModifierValue("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getAnnotationNamedModifiers(QString className, QString annotationName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("\"" + annotationName + "\"");
  emit logCommand("getAnnotationNamedModifiers("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray annotationName_utf8 = annotationName.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAnnotationNamedModifiers("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAnnotationNamedModifiers failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAnnotationNamedModifiers("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::getSimulationOptions_res OMCInterface::getSimulationOptions(QString name, modelica_real defaultStartTime, modelica_real defaultStopTime, modelica_real defaultTolerance, modelica_integer defaultNumberOfIntervals, modelica_real defaultInterval)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(name);
  commandLog.append(",");
  commandLog.append(QString::number(defaultStartTime));
  commandLog.append(",");
  commandLog.append(QString::number(defaultStopTime));
  commandLog.append(",");
  commandLog.append(QString::number(defaultTolerance));
  commandLog.append(",");
  commandLog.append(QString::number(defaultNumberOfIntervals));
  commandLog.append(",");
  commandLog.append(QString::number(defaultInterval));
  emit logCommand("getSimulationOptions("+commandLog+")");

  QByteArray name_utf8 = name.toUtf8();
  getSimulationOptions_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getSimulationOptions("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToGetSimulationOptions_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getSimulationOptions failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getSimulationOptions("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isExperiment(QString name)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(name);
  emit logCommand("isExperiment("+commandLog+")");

  QByteArray name_utf8 = name.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isExperiment("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isExperiment failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isExperiment("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getNthInheritedClass(QString className, modelica_integer n)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(QString::number(n));
  emit logCommand("getNthInheritedClass("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthInheritedClass("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthInheritedClass failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result);
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthInheritedClass("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getInheritedClasses(QString name)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(name);
  emit logCommand("getInheritedClasses("+commandLog+")");

  QByteArray name_utf8 = name.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getInheritedClasses("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getInheritedClasses failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getInheritedClasses("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getInheritanceCount(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("getInheritanceCount("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getInheritanceCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getInheritanceCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getInheritanceCount("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isProtected(QString componentName, QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(componentName);
  commandLog.append(",");
  commandLog.append(className);
  emit logCommand("isProtected("+commandLog+")");

  QByteArray componentName_utf8 = componentName.toUtf8();
  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isProtected("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isProtected failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isProtected("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isConstant(QString componentName, QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(componentName);
  commandLog.append(",");
  commandLog.append(className);
  emit logCommand("isConstant("+commandLog+")");

  QByteArray componentName_utf8 = componentName.toUtf8();
  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isConstant("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isConstant failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isConstant("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isParameter(QString componentName, QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(componentName);
  commandLog.append(",");
  commandLog.append(className);
  emit logCommand("isParameter("+commandLog+")");

  QByteArray componentName_utf8 = componentName.toUtf8();
  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isParameter("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isParameter failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isParameter("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isPrimitive(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("isPrimitive("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isPrimitive("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isPrimitive failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isPrimitive("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getBuiltinType(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("getBuiltinType("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getBuiltinType("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getBuiltinType failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getBuiltinType("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isProtectedClass(QString cl, QString c2)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  commandLog.append(",");
  commandLog.append("\"" + c2 + "\"");
  emit logCommand("isProtectedClass("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QByteArray c2_utf8 = c2.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isProtectedClass("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isProtectedClass failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isProtectedClass("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isOperatorFunction(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isOperatorFunction("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isOperatorFunction("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isOperatorFunction failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isOperatorFunction("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isOperatorRecord(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isOperatorRecord("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isOperatorRecord("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isOperatorRecord failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isOperatorRecord("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isOperator(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isOperator("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isOperator("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isOperator failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isOperator("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isEnumeration(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isEnumeration("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isEnumeration("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isEnumeration failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isEnumeration("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isOptimization(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isOptimization("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isOptimization("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isOptimization failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isOptimization("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isConnector(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isConnector("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isConnector("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isConnector failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isConnector("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isModel(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isModel("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isModel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isModel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isModel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isRedeclare(QString element)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(element);
  emit logCommand("isRedeclare("+commandLog+")");

  QByteArray element_utf8 = element.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isRedeclare("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isRedeclare failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isRedeclare("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isReplaceable(QString element)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(element);
  emit logCommand("isReplaceable("+commandLog+")");

  QByteArray element_utf8 = element.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isReplaceable("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isReplaceable failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isReplaceable("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isPartial(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isPartial("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isPartial("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isPartial failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isPartial("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isFunction(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isFunction("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isFunction("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isFunction failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isFunction("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isBlock(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isBlock("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isBlock("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isBlock failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isBlock("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isRecord(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isRecord("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isRecord("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isRecord failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isRecord("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isClass(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isClass("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isClass("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isClass failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isClass("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isPackage(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isPackage("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isPackage("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isPackage failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isPackage("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isType(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("isType("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isType("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isType failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isType("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getClassRestriction(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("getClassRestriction("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getClassRestriction("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getClassRestriction failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getClassRestriction("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::existClass(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("existClass("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "existClass("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("existClass failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("existClass("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::basename(QString path)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + path + "\"");
  emit logCommand("basename("+commandLog+")");

  QByteArray path_utf8 = path.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "basename("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("basename failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("basename("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::dirname(QString path)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + path + "\"");
  emit logCommand("dirname("+commandLog+")");

  QByteArray path_utf8 = path.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "dirname("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("dirname failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("dirname("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getClassComment(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("getClassComment("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getClassComment("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getClassComment failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getClassComment("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::typeNameStrings(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("typeNameStrings("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "typeNameStrings("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("typeNameStrings failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("typeNameStrings("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::typeNameString(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("typeNameString("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "typeNameString("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("typeNameString failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("typeNameString("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::stringTypeName(QString str)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + str + "\"");
  emit logCommand("stringTypeName("+commandLog+")");

  QByteArray str_utf8 = str.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "stringTypeName("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("stringTypeName failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result);
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("stringTypeName("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::getTimeStamp_res OMCInterface::getTimeStamp(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("getTimeStamp("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  getTimeStamp_res result;
  void *out2_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getTimeStamp("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToGetTimeStamp_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getTimeStamp failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getTimeStamp("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setDocumentationAnnotation(QString class_, QString info, QString revisions)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append("\"" + info + "\"");
  commandLog.append(",");
  commandLog.append("\"" + revisions + "\"");
  emit logCommand("setDocumentationAnnotation("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QByteArray info_utf8 = info.toUtf8();
  QByteArray revisions_utf8 = revisions.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setDocumentationAnnotation("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setDocumentationAnnotation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setDocumentationAnnotation("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getDocumentationAnnotation(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("getDocumentationAnnotation("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getDocumentationAnnotation("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getDocumentationAnnotation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getDocumentationAnnotation("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::iconv(QString string, QString from, QString to)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + string + "\"");
  commandLog.append(",");
  commandLog.append("\"" + from + "\"");
  commandLog.append(",");
  commandLog.append("\"" + to + "\"");
  emit logCommand("iconv("+commandLog+")");

  QByteArray string_utf8 = string.toUtf8();
  QByteArray from_utf8 = from.toUtf8();
  QByteArray to_utf8 = to.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "iconv("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("iconv failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("iconv("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getNthImport(QString class_, modelica_integer index)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(QString::number(index));
  emit logCommand("getNthImport("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthImport("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthImport failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthImport("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::getImportedNames_res OMCInterface::getImportedNames(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getImportedNames("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  getImportedNames_res result;
  void *out1_mm = NULL;
  void *out2_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getImportedNames("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToGetImportedNames_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getImportedNames failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getImportedNames("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getMMfileTotalDependencies(QString in_package_name, QString public_imports_dir)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + in_package_name + "\"");
  commandLog.append(",");
  commandLog.append("\"" + public_imports_dir + "\"");
  emit logCommand("getMMfileTotalDependencies("+commandLog+")");

  QByteArray in_package_name_utf8 = in_package_name.toUtf8();
  QByteArray public_imports_dir_utf8 = public_imports_dir.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getMMfileTotalDependencies("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getMMfileTotalDependencies failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getMMfileTotalDependencies("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getImportCount(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getImportCount("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getImportCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getImportCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getImportCount("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getNthAnnotationString(QString class_, modelica_integer index)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(QString::number(index));
  emit logCommand("getNthAnnotationString("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthAnnotationString("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthAnnotationString failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthAnnotationString("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getAnnotationCount(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getAnnotationCount("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAnnotationCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAnnotationCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAnnotationCount("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getNthInitialEquationItem(QString class_, modelica_integer index)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(QString::number(index));
  emit logCommand("getNthInitialEquationItem("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthInitialEquationItem("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthInitialEquationItem failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthInitialEquationItem("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getInitialEquationItemsCount(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getInitialEquationItemsCount("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getInitialEquationItemsCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getInitialEquationItemsCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getInitialEquationItemsCount("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getNthEquationItem(QString class_, modelica_integer index)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(QString::number(index));
  emit logCommand("getNthEquationItem("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthEquationItem("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthEquationItem failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthEquationItem("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getEquationItemsCount(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getEquationItemsCount("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getEquationItemsCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getEquationItemsCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getEquationItemsCount("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getNthInitialEquation(QString class_, modelica_integer index)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(QString::number(index));
  emit logCommand("getNthInitialEquation("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthInitialEquation("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthInitialEquation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthInitialEquation("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getInitialEquationCount(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getInitialEquationCount("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getInitialEquationCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getInitialEquationCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getInitialEquationCount("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getNthEquation(QString class_, modelica_integer index)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(QString::number(index));
  emit logCommand("getNthEquation("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthEquation("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthEquation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthEquation("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getEquationCount(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getEquationCount("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getEquationCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getEquationCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getEquationCount("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getNthInitialAlgorithmItem(QString class_, modelica_integer index)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(QString::number(index));
  emit logCommand("getNthInitialAlgorithmItem("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthInitialAlgorithmItem("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthInitialAlgorithmItem failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthInitialAlgorithmItem("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getInitialAlgorithmItemsCount(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getInitialAlgorithmItemsCount("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getInitialAlgorithmItemsCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getInitialAlgorithmItemsCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getInitialAlgorithmItemsCount("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getNthAlgorithmItem(QString class_, modelica_integer index)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(QString::number(index));
  emit logCommand("getNthAlgorithmItem("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthAlgorithmItem("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthAlgorithmItem failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthAlgorithmItem("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getAlgorithmItemsCount(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getAlgorithmItemsCount("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAlgorithmItemsCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAlgorithmItemsCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAlgorithmItemsCount("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getNthInitialAlgorithm(QString class_, modelica_integer index)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(QString::number(index));
  emit logCommand("getNthInitialAlgorithm("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthInitialAlgorithm("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthInitialAlgorithm failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthInitialAlgorithm("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getInitialAlgorithmCount(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getInitialAlgorithmCount("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getInitialAlgorithmCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getInitialAlgorithmCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getInitialAlgorithmCount("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getNthAlgorithm(QString class_, modelica_integer index)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(QString::number(index));
  emit logCommand("getNthAlgorithm("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthAlgorithm("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthAlgorithm failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthAlgorithm("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getAlgorithmCount(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getAlgorithmCount("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAlgorithmCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAlgorithmCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAlgorithmCount("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QList<QString > > OMCInterface::getConnectionList(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("getConnectionList("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QList<QList<QString > > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getConnectionList("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getConnectionList failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QList<QString > result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("{");
    int result_elt_i = 0;
    foreach(QString result_elt_elt, result_elt) {
      if (result_elt_i) {
        responseLog.append(",");
      }
      responseLog.append("\"" + result_elt_elt + "\"");
      result_elt_i++;
    }
    responseLog.append("}");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getConnectionList("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getNthConnection(QString className, modelica_integer index)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(QString::number(index));
  emit logCommand("getNthConnection("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthConnection("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthConnection failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthConnection("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getConnectionCount(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("getConnectionCount("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getConnectionCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getConnectionCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getConnectionCount("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::updateConnectionNames(QString className, QString from, QString to, QString fromNew, QString toNew)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("\"" + from + "\"");
  commandLog.append(",");
  commandLog.append("\"" + to + "\"");
  commandLog.append(",");
  commandLog.append("\"" + fromNew + "\"");
  commandLog.append(",");
  commandLog.append("\"" + toNew + "\"");
  emit logCommand("updateConnectionNames("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray from_utf8 = from.toUtf8();
  QByteArray to_utf8 = to.toUtf8();
  QByteArray fromNew_utf8 = fromNew.toUtf8();
  QByteArray toNew_utf8 = toNew.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "updateConnectionNames("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("updateConnectionNames failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("updateConnectionNames("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::updateConnectionAnnotation(QString className, QString from, QString to, QString annotate)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("\"" + from + "\"");
  commandLog.append(",");
  commandLog.append("\"" + to + "\"");
  commandLog.append(",");
  commandLog.append("\"" + annotate + "\"");
  emit logCommand("updateConnectionAnnotation("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray from_utf8 = from.toUtf8();
  QByteArray to_utf8 = to.toUtf8();
  QByteArray annotate_utf8 = annotate.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "updateConnectionAnnotation("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("updateConnectionAnnotation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("updateConnectionAnnotation("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getConnectorCount(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("getConnectorCount("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getConnectorCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getConnectorCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getConnectorCount("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setComponentProperties(QString className, QString componentName, QList<modelica_boolean > prefixArray, QList<QString > variability, QList<modelica_boolean > innerOuter, QList<QString > direction)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(componentName);
  commandLog.append(",");
  commandLog.append("{");
  int prefixArray_i = 0;
  foreach(modelica_boolean prefixArray_elt, prefixArray) {
    if (prefixArray_i) {
      commandLog.append(",");
    }
    commandLog.append(prefixArray_elt ? "true" : "false");
    prefixArray_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append("{");
  int variability_i = 0;
  foreach(QString variability_elt, variability) {
    if (variability_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + variability_elt + "\"");
    variability_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append("{");
  int innerOuter_i = 0;
  foreach(modelica_boolean innerOuter_elt, innerOuter) {
    if (innerOuter_i) {
      commandLog.append(",");
    }
    commandLog.append(innerOuter_elt ? "true" : "false");
    innerOuter_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append("{");
  int direction_i = 0;
  foreach(QString direction_elt, direction) {
    if (direction_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + direction_elt + "\"");
    direction_i++;
  }
  commandLog.append("}");
  emit logCommand("setComponentProperties("+commandLog+")");

  // QByteArray className_utf8 = className.toUtf8();
  // QByteArray componentName_utf8 = componentName.toUtf8();
  // void *prefixArray_lst = mmc_mk_nil();
  // for (int prefixArray_i = prefixArray.size()-1; prefixArray_i>=0; prefixArray_i--) {
  //   modelica_boolean prefixArray_elt = prefixArray[prefixArray_i];
  //   prefixArray_lst = mmc_mk_cons(mmc_mk_icon(prefixArray_elt), prefixArray_lst);
  // }
  // void *variability_lst = mmc_mk_nil();
  // for (int variability_i = variability.size()-1; variability_i>=0; variability_i--) {
  //   QString variability_elt = variability[variability_i];
  //   QByteArray variability_elt_utf8 = variability_elt.toUtf8();
  //   variability_lst = mmc_mk_cons(mmc_mk_scon(variability_elt_utf8.constData()), variability_lst);
  // }
  // void *innerOuter_lst = mmc_mk_nil();
  // for (int innerOuter_i = innerOuter.size()-1; innerOuter_i>=0; innerOuter_i--) {
  //   modelica_boolean innerOuter_elt = innerOuter[innerOuter_i];
  //   innerOuter_lst = mmc_mk_cons(mmc_mk_icon(innerOuter_elt), innerOuter_lst);
  // }
  // void *direction_lst = mmc_mk_nil();
  // for (int direction_i = direction.size()-1; direction_i>=0; direction_i--) {
  //   QString direction_elt = direction[direction_i];
  //   QByteArray direction_elt_utf8 = direction_elt.toUtf8();
  //   direction_lst = mmc_mk_cons(mmc_mk_scon(direction_elt_utf8.constData()), direction_lst);
  // }
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setComponentProperties("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setComponentProperties failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setComponentProperties("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setComponentComment(QString className, QString componentName, QString comment)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(componentName);
  commandLog.append(",");
  commandLog.append("\"" + comment + "\"");
  emit logCommand("setComponentComment("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray componentName_utf8 = componentName.toUtf8();
  QByteArray comment_utf8 = comment.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setComponentComment("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setComponentComment failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setComponentComment("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getComponentComment(QString className, QString componentName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(componentName);
  emit logCommand("getComponentComment("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray componentName_utf8 = componentName.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getComponentComment("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getComponentComment failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getComponentComment("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::removeExtendsModifiers(QString className, QString baseClassName, modelica_boolean keepRedeclares)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(baseClassName);
  commandLog.append(",");
  commandLog.append(keepRedeclares ? "true" : "false");
  emit logCommand("removeExtendsModifiers("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray baseClassName_utf8 = baseClassName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "removeExtendsModifiers("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("removeExtendsModifiers failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("removeExtendsModifiers("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getInstantiatedParametersAndValues(QString cls)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cls);
  emit logCommand("getInstantiatedParametersAndValues("+commandLog+")");

  QByteArray cls_utf8 = cls.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getInstantiatedParametersAndValues("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getInstantiatedParametersAndValues failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getInstantiatedParametersAndValues("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getElementAnnotation(QString elementName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(elementName);
  emit logCommand("getElementAnnotation("+commandLog+")");

  QByteArray elementName_utf8 = elementName.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getElementAnnotation("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getElementAnnotation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getElementAnnotation("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getNthComponentCondition(QString className, modelica_integer n)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(QString::number(n));
  emit logCommand("getNthComponentCondition("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNthComponentCondition("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNthComponentCondition failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNthComponentCondition("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getComponentCount(QString classPath)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(classPath);
  emit logCommand("getComponentCount("+commandLog+")");

  QByteArray classPath_utf8 = classPath.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getComponentCount("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getComponentCount failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getComponentCount("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isExtendsModifierFinal(QString className, QString extendsName, QString modifierName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(extendsName);
  commandLog.append(",");
  commandLog.append(modifierName);
  emit logCommand("isExtendsModifierFinal("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray extendsName_utf8 = extendsName.toUtf8();
  QByteArray modifierName_utf8 = modifierName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isExtendsModifierFinal("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isExtendsModifierFinal failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isExtendsModifierFinal("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::removeElementModifiers(QString className, QString componentName, modelica_boolean keepRedeclares)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("\"" + componentName + "\"");
  commandLog.append(",");
  commandLog.append(keepRedeclares ? "true" : "false");
  emit logCommand("removeElementModifiers("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray componentName_utf8 = componentName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "removeElementModifiers("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("removeElementModifiers failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("removeElementModifiers("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getElementModifierValues(QString className, QString modifier)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(modifier);
  emit logCommand("getElementModifierValues("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray modifier_utf8 = modifier.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getElementModifierValues("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getElementModifierValues failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getElementModifierValues("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getElementModifierValue(QString className, QString modifier)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(modifier);
  emit logCommand("getElementModifierValue("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray modifier_utf8 = modifier.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getElementModifierValue("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getElementModifierValue failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getElementModifierValue("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getExtendsModifierNames(QString className, QString extendsName, modelica_boolean useQuotes)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(extendsName);
  commandLog.append(",");
  commandLog.append(useQuotes ? "true" : "false");
  emit logCommand("getExtendsModifierNames("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray extendsName_utf8 = extendsName.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getExtendsModifierNames("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getExtendsModifierNames failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getExtendsModifierNames("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getElementModifierNames(QString className, QString elementName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("\"" + elementName + "\"");
  emit logCommand("getElementModifierNames("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray elementName_utf8 = elementName.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getElementModifierNames("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getElementModifierNames failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getElementModifierNames("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::removeComponentModifiers(QString class_, QString componentName, modelica_boolean keepRedeclares)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append("\"" + componentName + "\"");
  commandLog.append(",");
  commandLog.append(keepRedeclares ? "true" : "false");
  emit logCommand("removeComponentModifiers("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QByteArray componentName_utf8 = componentName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "removeComponentModifiers("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("removeComponentModifiers failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("removeComponentModifiers("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getComponentModifierValues(QString class_, QString modifier)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(modifier);
  emit logCommand("getComponentModifierValues("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QByteArray modifier_utf8 = modifier.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getComponentModifierValues("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getComponentModifierValues failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getComponentModifierValues("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getComponentModifierValue(QString class_, QString modifier)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(modifier);
  emit logCommand("getComponentModifierValue("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QByteArray modifier_utf8 = modifier.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getComponentModifierValue("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getComponentModifierValue failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getComponentModifierValue("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getComponentModifierNames(QString class_, QString componentName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append("\"" + componentName + "\"");
  emit logCommand("getComponentModifierNames("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QByteArray componentName_utf8 = componentName.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getComponentModifierNames("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getComponentModifierNames failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getComponentModifierNames("+commandLog+")", responseLog, elapsed);

  return result;
}
void OMCInterface::getElements(QString className, modelica_boolean useQuotes)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(useQuotes ? "true" : "false");
  emit logCommand("getElements("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getElements("+commandLog.toStdString()+")";
    python_env.send_expression_object(command, false);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getElements failed. %1").arg(exception.what()));
  }

  QString responseLog;
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getElements("+commandLog+")", responseLog, elapsed);

}
void OMCInterface::getComponents(QString className, modelica_boolean useQuotes)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(useQuotes ? "true" : "false");
  emit logCommand("getComponents("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getComponents("+commandLog.toStdString()+")";
    python_env.send_expression_object(command, false);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getComponents failed. %1").arg(exception.what()));
  }

  QString responseLog;
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getComponents("+commandLog+")", responseLog, elapsed);

}
QString OMCInterface::getParameterValue(QString class_, QString parameterName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append("\"" + parameterName + "\"");
  emit logCommand("getParameterValue("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QByteArray parameterName_utf8 = parameterName.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getParameterValue("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getParameterValue failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getParameterValue("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getParameterNames(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getParameterNames("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getParameterNames("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getParameterNames failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getParameterNames("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::deleteComponent(QString componentName, QString classPath)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(componentName);
  commandLog.append(",");
  commandLog.append(classPath);
  emit logCommand("deleteComponent("+commandLog+")");

  QByteArray componentName_utf8 = componentName.toUtf8();
  QByteArray classPath_utf8 = classPath.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "deleteComponent("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("deleteComponent failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("deleteComponent("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::closeSimulationResultFile()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("closeSimulationResultFile()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "closeSimulationResultFile()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("closeSimulationResultFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("closeSimulationResultFile()", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::checkCodeGraph(QString graphfile, QString codefile)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + graphfile + "\"");
  commandLog.append(",");
  commandLog.append("\"" + codefile + "\"");
  emit logCommand("checkCodeGraph("+commandLog+")");

  QByteArray graphfile_utf8 = graphfile.toUtf8();
  QByteArray codefile_utf8 = codefile.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "checkCodeGraph("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("checkCodeGraph failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("checkCodeGraph("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::checkTaskGraph(QString filename, QString reffilename)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + reffilename + "\"");
  emit logCommand("checkTaskGraph("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  QByteArray reffilename_utf8 = reffilename.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "checkTaskGraph("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("checkTaskGraph failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("checkTaskGraph("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::diffSimulationResultsHtml(QString var, QString actualFile, QString expectedFile, modelica_real relTol, modelica_real relTolDiffMinMax, modelica_real rangeDelta)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + var + "\"");
  commandLog.append(",");
  commandLog.append("\"" + actualFile + "\"");
  commandLog.append(",");
  commandLog.append("\"" + expectedFile + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(relTol));
  commandLog.append(",");
  commandLog.append(QString::number(relTolDiffMinMax));
  commandLog.append(",");
  commandLog.append(QString::number(rangeDelta));
  emit logCommand("diffSimulationResultsHtml("+commandLog+")");

  QByteArray var_utf8 = var.toUtf8();
  QByteArray actualFile_utf8 = actualFile.toUtf8();
  QByteArray expectedFile_utf8 = expectedFile.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "diffSimulationResultsHtml("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("diffSimulationResultsHtml failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("diffSimulationResultsHtml("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::diffSimulationResults_res OMCInterface::diffSimulationResults(QString actualFile, QString expectedFile, QString diffPrefix, modelica_real relTol, modelica_real relTolDiffMinMax, modelica_real rangeDelta, QList<QString > vars, modelica_boolean keepEqualResults)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + actualFile + "\"");
  commandLog.append(",");
  commandLog.append("\"" + expectedFile + "\"");
  commandLog.append(",");
  commandLog.append("\"" + diffPrefix + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(relTol));
  commandLog.append(",");
  commandLog.append(QString::number(relTolDiffMinMax));
  commandLog.append(",");
  commandLog.append(QString::number(rangeDelta));
  commandLog.append(",");
  commandLog.append("{");
  int vars_i = 0;
  foreach(QString vars_elt, vars) {
    if (vars_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + vars_elt + "\"");
    vars_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append(keepEqualResults ? "true" : "false");
  emit logCommand("diffSimulationResults("+commandLog+")");

  // QByteArray actualFile_utf8 = actualFile.toUtf8();
  // QByteArray expectedFile_utf8 = expectedFile.toUtf8();
  // QByteArray diffPrefix_utf8 = diffPrefix.toUtf8();
  // void *vars_lst = mmc_mk_nil();
  // for (int vars_i = vars.size()-1; vars_i>=0; vars_i--) {
  //   QString vars_elt = vars[vars_i];
  //   QByteArray vars_elt_utf8 = vars_elt.toUtf8();
  //   vars_lst = mmc_mk_cons(mmc_mk_scon(vars_elt_utf8.constData()), vars_lst);
  // }
  diffSimulationResults_res result;
  // void *out2_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "diffSimulationResults("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToDiffSimulationResults_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("diffSimulationResults failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("diffSimulationResults("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_real OMCInterface::deltaSimulationResults(QString filename, QString reffilename, QString method, QList<QString > vars)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + reffilename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + method + "\"");
  commandLog.append(",");
  commandLog.append("{");
  int vars_i = 0;
  foreach(QString vars_elt, vars) {
    if (vars_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + vars_elt + "\"");
    vars_i++;
  }
  commandLog.append("}");
  emit logCommand("deltaSimulationResults("+commandLog+")");

  // QByteArray filename_utf8 = filename.toUtf8();
  // QByteArray reffilename_utf8 = reffilename.toUtf8();
  // QByteArray method_utf8 = method.toUtf8();
  // void *vars_lst = mmc_mk_nil();
  // for (int vars_i = vars.size()-1; vars_i>=0; vars_i--) {
  //   QString vars_elt = vars[vars_i];
  //   QByteArray vars_elt_utf8 = vars_elt.toUtf8();
  //   vars_lst = mmc_mk_cons(mmc_mk_scon(vars_elt_utf8.constData()), vars_lst);
  // }
  modelica_real result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "deltaSimulationResults("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaReal(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("deltaSimulationResults failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("deltaSimulationResults("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::compareSimulationResults(QString filename, QString reffilename, QString logfilename, modelica_real relTol, modelica_real absTol, QList<QString > vars)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + reffilename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + logfilename + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(relTol));
  commandLog.append(",");
  commandLog.append(QString::number(absTol));
  commandLog.append(",");
  commandLog.append("{");
  int vars_i = 0;
  foreach(QString vars_elt, vars) {
    if (vars_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + vars_elt + "\"");
    vars_i++;
  }
  commandLog.append("}");
  emit logCommand("compareSimulationResults("+commandLog+")");

  // QByteArray filename_utf8 = filename.toUtf8();
  // QByteArray reffilename_utf8 = reffilename.toUtf8();
  // QByteArray logfilename_utf8 = logfilename.toUtf8();
  // void *vars_lst = mmc_mk_nil();
  // for (int vars_i = vars.size()-1; vars_i>=0; vars_i--) {
  //   QString vars_elt = vars[vars_i];
  //   QByteArray vars_elt_utf8 = vars_elt.toUtf8();
  //   vars_lst = mmc_mk_cons(mmc_mk_scon(vars_elt_utf8.constData()), vars_lst);
  // }
  QList<QString > result;
  // void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "compareSimulationResults("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("compareSimulationResults failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("compareSimulationResults("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::filterSimulationResults(QString inFile, QString outFile, QList<QString > vars, modelica_integer numberOfIntervals, modelica_boolean removeDescription, modelica_boolean hintReadAllVars)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + inFile + "\"");
  commandLog.append(",");
  commandLog.append("\"" + outFile + "\"");
  commandLog.append(",");
  commandLog.append("{");
  int vars_i = 0;
  foreach(QString vars_elt, vars) {
    if (vars_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + vars_elt + "\"");
    vars_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append(QString::number(numberOfIntervals));
  commandLog.append(",");
  commandLog.append(removeDescription ? "true" : "false");
  commandLog.append(",");
  commandLog.append(hintReadAllVars ? "true" : "false");
  emit logCommand("filterSimulationResults("+commandLog+")");

  // QByteArray inFile_utf8 = inFile.toUtf8();
  // QByteArray outFile_utf8 = outFile.toUtf8();
  // void *vars_lst = mmc_mk_nil();
  // for (int vars_i = vars.size()-1; vars_i>=0; vars_i--) {
  //   QString vars_elt = vars[vars_i];
  //   QByteArray vars_elt_utf8 = vars_elt.toUtf8();
  //   vars_lst = mmc_mk_cons(mmc_mk_scon(vars_elt_utf8.constData()), vars_lst);
  // }
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "filterSimulationResults("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("filterSimulationResults failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("filterSimulationResults("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::readSimulationResultVars(QString fileName, modelica_boolean readParameters, modelica_boolean openmodelicaStyle)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  commandLog.append(",");
  commandLog.append(readParameters ? "true" : "false");
  commandLog.append(",");
  commandLog.append(openmodelicaStyle ? "true" : "false");
  emit logCommand("readSimulationResultVars("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "readSimulationResultVars("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("readSimulationResultVars failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("readSimulationResultVars("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::readSimulationResultSize(QString fileName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  emit logCommand("readSimulationResultSize("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "readSimulationResultSize("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("readSimulationResultSize failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("readSimulationResultSize("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::plotAll(modelica_boolean externalWindow, QString fileName, QString title, QString grid, modelica_boolean logX, modelica_boolean logY, QString xLabel, QString yLabel, QList<modelica_real > xRange, QList<modelica_real > yRange, modelica_real curveWidth, modelica_integer curveStyle, QString legendPosition, QString footer, modelica_boolean autoScale, modelica_boolean forceOMPlot)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(externalWindow ? "true" : "false");
  commandLog.append(",");
  commandLog.append("\"" + fileName + "\"");
  commandLog.append(",");
  commandLog.append("\"" + title + "\"");
  commandLog.append(",");
  commandLog.append("\"" + grid + "\"");
  commandLog.append(",");
  commandLog.append(logX ? "true" : "false");
  commandLog.append(",");
  commandLog.append(logY ? "true" : "false");
  commandLog.append(",");
  commandLog.append("\"" + xLabel + "\"");
  commandLog.append(",");
  commandLog.append("\"" + yLabel + "\"");
  commandLog.append(",");
  commandLog.append("{");
  int xRange_i = 0;
  foreach(modelica_real xRange_elt, xRange) {
    if (xRange_i) {
      commandLog.append(",");
    }
    commandLog.append(QString::number(xRange_elt));
    xRange_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append("{");
  int yRange_i = 0;
  foreach(modelica_real yRange_elt, yRange) {
    if (yRange_i) {
      commandLog.append(",");
    }
    commandLog.append(QString::number(yRange_elt));
    yRange_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append(QString::number(curveWidth));
  commandLog.append(",");
  commandLog.append(QString::number(curveStyle));
  commandLog.append(",");
  commandLog.append("\"" + legendPosition + "\"");
  commandLog.append(",");
  commandLog.append("\"" + footer + "\"");
  commandLog.append(",");
  commandLog.append(autoScale ? "true" : "false");
  commandLog.append(",");
  commandLog.append(forceOMPlot ? "true" : "false");
  emit logCommand("plotAll("+commandLog+")");

  // QByteArray fileName_utf8 = fileName.toUtf8();
  // QByteArray title_utf8 = title.toUtf8();
  // QByteArray grid_utf8 = grid.toUtf8();
  // QByteArray xLabel_utf8 = xLabel.toUtf8();
  // QByteArray yLabel_utf8 = yLabel.toUtf8();
  // void *xRange_lst = mmc_mk_nil();
  // for (int xRange_i = xRange.size()-1; xRange_i>=0; xRange_i--) {
  //   modelica_real xRange_elt = xRange[xRange_i];
  //   xRange_lst = mmc_mk_cons(mmc_mk_rcon(xRange_elt), xRange_lst);
  // }
  // void *yRange_lst = mmc_mk_nil();
  // for (int yRange_i = yRange.size()-1; yRange_i>=0; yRange_i--) {
  //   modelica_real yRange_elt = yRange[yRange_i];
  //   yRange_lst = mmc_mk_cons(mmc_mk_rcon(yRange_elt), yRange_lst);
  // }
  // QByteArray legendPosition_utf8 = legendPosition.toUtf8();
  // QByteArray footer_utf8 = footer.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "plotAll("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("plotAll failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("plotAll("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getAllSubtypeOf(QString className, QString parentClass, modelica_boolean qualified, modelica_boolean includePartial, modelica_boolean sort)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(parentClass);
  commandLog.append(",");
  commandLog.append(qualified ? "true" : "false");
  commandLog.append(",");
  commandLog.append(includePartial ? "true" : "false");
  commandLog.append(",");
  commandLog.append(sort ? "true" : "false");
  emit logCommand("getAllSubtypeOf("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray parentClass_utf8 = parentClass.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAllSubtypeOf("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAllSubtypeOf failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAllSubtypeOf("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getPackages(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getPackages("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getPackages("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getPackages failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getPackages("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getUsedClassNames(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("getUsedClassNames("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getUsedClassNames("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getUsedClassNames failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getUsedClassNames("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getClassNames(QString class_, modelica_boolean recursive, modelica_boolean qualified, modelica_boolean sort, modelica_boolean builtin, modelica_boolean showProtected, modelica_boolean includeConstants)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(recursive ? "true" : "false");
  commandLog.append(",");
  commandLog.append(qualified ? "true" : "false");
  commandLog.append(",");
  commandLog.append(sort ? "true" : "false");
  commandLog.append(",");
  commandLog.append(builtin ? "true" : "false");
  commandLog.append(",");
  commandLog.append(showProtected ? "true" : "false");
  commandLog.append(",");
  commandLog.append(includeConstants ? "true" : "false");
  emit logCommand("getClassNames("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getClassNames("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getClassNames failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getClassNames("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setClassComment(QString class_, QString filename)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append("\"" + filename + "\"");
  emit logCommand("setClassComment("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QByteArray filename_utf8 = filename.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setClassComment("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setClassComment failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setClassComment("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::isShortDefinition(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("isShortDefinition("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "isShortDefinition("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("isShortDefinition failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("isShortDefinition("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setSourceFile(QString class_, QString filename)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append("\"" + filename + "\"");
  emit logCommand("setSourceFile("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QByteArray filename_utf8 = filename.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setSourceFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setSourceFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setSourceFile("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getSourceFile(QString class_)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  emit logCommand("getSourceFile("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getSourceFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getSourceFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getSourceFile("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::refactorClass(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("refactorClass("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "refactorClass("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("refactorClass failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("refactorClass("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::deleteClass(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("deleteClass("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "deleteClass("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("deleteClass failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("deleteClass("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::renameClass(QString oldName, QString newName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(oldName);
  commandLog.append(",");
  commandLog.append(newName);
  emit logCommand("renameClass("+commandLog+")");

  QByteArray oldName_utf8 = oldName.toUtf8();
  QByteArray newName_utf8 = newName.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "renameClass("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("renameClass failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("renameClass("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::copyClass(QString className, QString newClassName, QString withIn)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("\"" + newClassName + "\"");
  commandLog.append(",");
  commandLog.append(withIn);
  emit logCommand("copyClass("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray newClassName_utf8 = newClassName.toUtf8();
  QByteArray withIn_utf8 = withIn.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "copyClass("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("copyClass failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("copyClass("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::moveClassToBottom(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("moveClassToBottom("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "moveClassToBottom("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("moveClassToBottom failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("moveClassToBottom("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::moveClassToTop(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("moveClassToTop("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "moveClassToTop("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("moveClassToTop failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("moveClassToTop("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::moveClass(QString className, modelica_integer offset)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(QString::number(offset));
  emit logCommand("moveClass("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "moveClass("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("moveClass failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("moveClass("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::newModel(QString className, QString withinPath)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(withinPath);
  emit logCommand("newModel("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray withinPath_utf8 = withinPath.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "newModel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("newModel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("newModel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::createModel(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("createModel("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "createModel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("createModel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("createModel("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::reduceTerms(QString className, modelica_real startTime, modelica_real stopTime, modelica_integer numberOfIntervals, modelica_real tolerance, QString method, QString fileNamePrefix, QString options, QString outputFormat, QString variableFilter, QString cflags, QString simflags, QString labelstoCancel)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(QString::number(startTime));
  commandLog.append(",");
  commandLog.append(QString::number(stopTime));
  commandLog.append(",");
  commandLog.append(QString::number(numberOfIntervals));
  commandLog.append(",");
  commandLog.append(QString::number(tolerance));
  commandLog.append(",");
  commandLog.append("\"" + method + "\"");
  commandLog.append(",");
  commandLog.append("\"" + fileNamePrefix + "\"");
  commandLog.append(",");
  commandLog.append("\"" + options + "\"");
  commandLog.append(",");
  commandLog.append("\"" + outputFormat + "\"");
  commandLog.append(",");
  commandLog.append("\"" + variableFilter + "\"");
  commandLog.append(",");
  commandLog.append("\"" + cflags + "\"");
  commandLog.append(",");
  commandLog.append("\"" + simflags + "\"");
  commandLog.append(",");
  commandLog.append("\"" + labelstoCancel + "\"");
  emit logCommand("reduceTerms("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray method_utf8 = method.toUtf8();
  QByteArray fileNamePrefix_utf8 = fileNamePrefix.toUtf8();
  QByteArray options_utf8 = options.toUtf8();
  QByteArray outputFormat_utf8 = outputFormat.toUtf8();
  QByteArray variableFilter_utf8 = variableFilter.toUtf8();
  QByteArray cflags_utf8 = cflags.toUtf8();
  QByteArray simflags_utf8 = simflags.toUtf8();
  QByteArray labelstoCancel_utf8 = labelstoCancel.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "reduceTerms("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("reduceTerms failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("reduceTerms("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::buildLabel(QString className, modelica_real startTime, modelica_real stopTime, modelica_integer numberOfIntervals, modelica_real tolerance, QString method, QString fileNamePrefix, QString options, QString outputFormat, QString variableFilter, QString cflags, QString simflags)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(QString::number(startTime));
  commandLog.append(",");
  commandLog.append(QString::number(stopTime));
  commandLog.append(",");
  commandLog.append(QString::number(numberOfIntervals));
  commandLog.append(",");
  commandLog.append(QString::number(tolerance));
  commandLog.append(",");
  commandLog.append("\"" + method + "\"");
  commandLog.append(",");
  commandLog.append("\"" + fileNamePrefix + "\"");
  commandLog.append(",");
  commandLog.append("\"" + options + "\"");
  commandLog.append(",");
  commandLog.append("\"" + outputFormat + "\"");
  commandLog.append(",");
  commandLog.append("\"" + variableFilter + "\"");
  commandLog.append(",");
  commandLog.append("\"" + cflags + "\"");
  commandLog.append(",");
  commandLog.append("\"" + simflags + "\"");
  emit logCommand("buildLabel("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray method_utf8 = method.toUtf8();
  QByteArray fileNamePrefix_utf8 = fileNamePrefix.toUtf8();
  QByteArray options_utf8 = options.toUtf8();
  QByteArray outputFormat_utf8 = outputFormat.toUtf8();
  QByteArray variableFilter_utf8 = variableFilter.toUtf8();
  QByteArray cflags_utf8 = cflags.toUtf8();
  QByteArray simflags_utf8 = simflags.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "buildLabel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("buildLabel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("buildLabel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::buildEncryptedPackage(QString className, modelica_boolean encrypt)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(encrypt ? "true" : "false");
  emit logCommand("buildEncryptedPackage("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "buildEncryptedPackage("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("buildEncryptedPackage failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("buildEncryptedPackage("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::buildModelFMU(QString className, QString version, QString fmuType, QString fileNamePrefix, QList<QString > platforms, modelica_boolean includeResources)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("\"" + version + "\"");
  commandLog.append(",");
  commandLog.append("\"" + fmuType + "\"");
  commandLog.append(",");
  commandLog.append("\"" + fileNamePrefix + "\"");
  commandLog.append(",");
  commandLog.append("{");
  int platforms_i = 0;
  foreach(QString platforms_elt, platforms) {
    if (platforms_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + platforms_elt + "\"");
    platforms_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append(includeResources ? "true" : "false");
  emit logCommand("buildModelFMU("+commandLog+")");

  // QByteArray className_utf8 = className.toUtf8();
  // QByteArray version_utf8 = version.toUtf8();
  // QByteArray fmuType_utf8 = fmuType.toUtf8();
  // QByteArray fileNamePrefix_utf8 = fileNamePrefix.toUtf8();
  // void *platforms_lst = mmc_mk_nil();
  // for (int platforms_i = platforms.size()-1; platforms_i>=0; platforms_i--) {
  //   QString platforms_elt = platforms[platforms_i];
  //   QByteArray platforms_elt_utf8 = platforms_elt.toUtf8();
  //   platforms_lst = mmc_mk_cons(mmc_mk_scon(platforms_elt_utf8.constData()), platforms_lst);
  // }
  QString result;
  // void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "buildModelFMU("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("buildModelFMU failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("buildModelFMU("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::translateModelFMU(QString className, QString version, QString fmuType, QString fileNamePrefix, QList<QString > platforms, modelica_boolean includeResources)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("\"" + version + "\"");
  commandLog.append(",");
  commandLog.append("\"" + fmuType + "\"");
  commandLog.append(",");
  commandLog.append("\"" + fileNamePrefix + "\"");
  commandLog.append(",");
  commandLog.append("{");
  int platforms_i = 0;
  foreach(QString platforms_elt, platforms) {
    if (platforms_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + platforms_elt + "\"");
    platforms_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append(includeResources ? "true" : "false");
  emit logCommand("translateModelFMU("+commandLog+")");

  // QByteArray className_utf8 = className.toUtf8();
  // QByteArray version_utf8 = version.toUtf8();
  // QByteArray fmuType_utf8 = fmuType.toUtf8();
  // QByteArray fileNamePrefix_utf8 = fileNamePrefix.toUtf8();
  // void *platforms_lst = mmc_mk_nil();
  // for (int platforms_i = platforms.size()-1; platforms_i>=0; platforms_i--) {
  //   QString platforms_elt = platforms[platforms_i];
  //   QByteArray platforms_elt_utf8 = platforms_elt.toUtf8();
  //   platforms_lst = mmc_mk_cons(mmc_mk_scon(platforms_elt_utf8.constData()), platforms_lst);
  // }
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "translateModelFMU("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("translateModelFMU failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("translateModelFMU("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::importFMUModelDescription(QString filename, QString workdir, modelica_integer loglevel, modelica_boolean fullPath, modelica_boolean debugLogging, modelica_boolean generateInputConnectors, modelica_boolean generateOutputConnectors)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + workdir + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(loglevel));
  commandLog.append(",");
  commandLog.append(fullPath ? "true" : "false");
  commandLog.append(",");
  commandLog.append(debugLogging ? "true" : "false");
  commandLog.append(",");
  commandLog.append(generateInputConnectors ? "true" : "false");
  commandLog.append(",");
  commandLog.append(generateOutputConnectors ? "true" : "false");
  emit logCommand("importFMUModelDescription("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  QByteArray workdir_utf8 = workdir.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "importFMUModelDescription("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("importFMUModelDescription failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("importFMUModelDescription("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::importFMU(QString filename, QString workdir, modelica_integer loglevel, modelica_boolean fullPath, modelica_boolean debugLogging, modelica_boolean generateInputConnectors, modelica_boolean generateOutputConnectors, QString modelName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + workdir + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(loglevel));
  commandLog.append(",");
  commandLog.append(fullPath ? "true" : "false");
  commandLog.append(",");
  commandLog.append(debugLogging ? "true" : "false");
  commandLog.append(",");
  commandLog.append(generateInputConnectors ? "true" : "false");
  commandLog.append(",");
  commandLog.append(generateOutputConnectors ? "true" : "false");
  commandLog.append(",");
  commandLog.append(modelName);
  emit logCommand("importFMU("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  QByteArray workdir_utf8 = workdir.toUtf8();
  QByteArray modelName_utf8 = modelName.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "importFMU("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("importFMU failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("importFMU("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::solveLinearSystem_res OMCInterface::solveLinearSystem(QList<QList<modelica_real > > A, QList<modelica_real > B)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("{");
  int A_i = 0;
  foreach(QList<modelica_real > A_elt, A) {
    if (A_i) {
      commandLog.append(",");
    }
    commandLog.append("{");
    int A_elt_i = 0;
    foreach(modelica_real A_elt_elt, A_elt) {
      if (A_elt_i) {
        commandLog.append(",");
      }
      commandLog.append(QString::number(A_elt_elt));
      A_elt_i++;
    }
    commandLog.append("}");
    A_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append("{");
  int B_i = 0;
  foreach(modelica_real B_elt, B) {
    if (B_i) {
      commandLog.append(",");
    }
    commandLog.append(QString::number(B_elt));
    B_i++;
  }
  commandLog.append("}");
  emit logCommand("solveLinearSystem("+commandLog+")");

  // void *A_lst = mmc_mk_nil();
  // for (int A_i = A.size()-1; A_i>=0; A_i--) {
  //   QList<modelica_real > A_elt = A[A_i];
  //   void *A_elt_lst = mmc_mk_nil();
  //   for (int A_elt_i = A_elt.size()-1; A_elt_i>=0; A_elt_i--) {
  //     modelica_real A_elt_elt = A_elt[A_elt_i];
  //     A_elt_lst = mmc_mk_cons(mmc_mk_rcon(A_elt_elt), A_elt_lst);
  //   }
  //   A_lst = mmc_mk_cons(A_elt_lst, A_lst);
  // }
  // void *B_lst = mmc_mk_nil();
  // for (int B_i = B.size()-1; B_i>=0; B_i--) {
  //   modelica_real B_elt = B[B_i];
  //   B_lst = mmc_mk_cons(mmc_mk_rcon(B_elt), B_lst);
  // }
  solveLinearSystem_res result;
  // void *out1_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "solveLinearSystem("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToSolveLinearSystem_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("solveLinearSystem failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("solveLinearSystem("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QList<QString > > OMCInterface::getLoadedLibraries()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getLoadedLibraries()");

  QList<QList<QString > > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getLoadedLibraries()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getLoadedLibraries failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QList<QString > result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("{");
    int result_elt_i = 0;
    foreach(QString result_elt_elt, result_elt) {
      if (result_elt_i) {
        responseLog.append(",");
      }
      responseLog.append("\"" + result_elt_elt + "\"");
      result_elt_i++;
    }
    responseLog.append("}");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getLoadedLibraries()", responseLog, elapsed);

  return result;
}
QString OMCInterface::uriToFilename(QString uri)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + uri + "\"");
  emit logCommand("uriToFilename("+commandLog+")");

  QByteArray uri_utf8 = uri.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "uriToFilename("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("uriToFilename failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("uriToFilename("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::realpath(QString name)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + name + "\"");
  emit logCommand("realpath("+commandLog+")");

  QByteArray name_utf8 = name.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "realpath("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("realpath failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("realpath("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::rewriteBlockCall(QString className, QString inDefs)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(inDefs);
  emit logCommand("rewriteBlockCall("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray inDefs_utf8 = inDefs.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "rewriteBlockCall("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("rewriteBlockCall failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("rewriteBlockCall("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::generateVerificationScenarios(QString path)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(path);
  emit logCommand("generateVerificationScenarios("+commandLog+")");

  QByteArray path_utf8 = path.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "generateVerificationScenarios("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("generateVerificationScenarios failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("generateVerificationScenarios("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::inferBindings(QString path)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(path);
  emit logCommand("inferBindings("+commandLog+")");

  QByteArray path_utf8 = path.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "inferBindings("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("inferBindings failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("inferBindings("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::exportToFigaro(QString path, QString directory, QString database, QString mode, QString options, QString processor)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(path);
  commandLog.append(",");
  commandLog.append("\"" + directory + "\"");
  commandLog.append(",");
  commandLog.append("\"" + database + "\"");
  commandLog.append(",");
  commandLog.append("\"" + mode + "\"");
  commandLog.append(",");
  commandLog.append("\"" + options + "\"");
  commandLog.append(",");
  commandLog.append("\"" + processor + "\"");
  emit logCommand("exportToFigaro("+commandLog+")");

  QByteArray path_utf8 = path.toUtf8();
  QByteArray directory_utf8 = directory.toUtf8();
  QByteArray database_utf8 = database.toUtf8();
  QByteArray mode_utf8 = mode.toUtf8();
  QByteArray options_utf8 = options.toUtf8();
  QByteArray processor_utf8 = processor.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "exportToFigaro("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("exportToFigaro failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("exportToFigaro("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::listFile(QString class_, modelica_boolean nestedClasses)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(class_);
  commandLog.append(",");
  commandLog.append(nestedClasses ? "true" : "false");
  emit logCommand("listFile("+commandLog+")");

  QByteArray class__utf8 = class_.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "listFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("listFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("listFile("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::stringReplace(QString str, QString source, QString target)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + str + "\"");
  commandLog.append(",");
  commandLog.append("\"" + source + "\"");
  commandLog.append(",");
  commandLog.append("\"" + target + "\"");
  emit logCommand("stringReplace("+commandLog+")");

  QByteArray str_utf8 = str.toUtf8();
  QByteArray source_utf8 = source.toUtf8();
  QByteArray target_utf8 = target.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "stringReplace("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("stringReplace failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("stringReplace("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::stringSplit(QString string, QString token)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + string + "\"");
  commandLog.append(",");
  commandLog.append("\"" + token + "\"");
  emit logCommand("stringSplit("+commandLog+")");

  QByteArray string_utf8 = string.toUtf8();
  QByteArray token_utf8 = token.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "stringSplit("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("stringSplit failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("stringSplit("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::strtok(QString string, QString token)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + string + "\"");
  commandLog.append(",");
  commandLog.append("\"" + token + "\"");
  emit logCommand("strtok("+commandLog+")");

  QByteArray string_utf8 = string.toUtf8();
  QByteArray token_utf8 = token.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "strtok("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("strtok failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("strtok("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::listVariables()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("listVariables()");

  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "listVariables()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("listVariables failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("listVariables()", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getDerivedUnits(QString baseUnit)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + baseUnit + "\"");
  emit logCommand("getDerivedUnits("+commandLog+")");

  QByteArray baseUnit_utf8 = baseUnit.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getDerivedUnits("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getDerivedUnits failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getDerivedUnits("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::convertUnits_res OMCInterface::convertUnits(QString s1, QString s2)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + s1 + "\"");
  commandLog.append(",");
  commandLog.append("\"" + s2 + "\"");
  emit logCommand("convertUnits("+commandLog+")");

  QByteArray s1_utf8 = s1.toUtf8();
  QByteArray s2_utf8 = s2.toUtf8();
  convertUnits_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "convertUnits("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToConvertUnits_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("convertUnits failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("convertUnits("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::dumpXMLDAE_res OMCInterface::dumpXMLDAE(QString className, QString translationLevel, modelica_boolean addOriginalAdjacencyMatrix, modelica_boolean addSolvingInfo, modelica_boolean addMathMLCode, modelica_boolean dumpResiduals, QString fileNamePrefix, QString rewriteRulesFile)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("\"" + translationLevel + "\"");
  commandLog.append(",");
  commandLog.append(addOriginalAdjacencyMatrix ? "true" : "false");
  commandLog.append(",");
  commandLog.append(addSolvingInfo ? "true" : "false");
  commandLog.append(",");
  commandLog.append(addMathMLCode ? "true" : "false");
  commandLog.append(",");
  commandLog.append(dumpResiduals ? "true" : "false");
  commandLog.append(",");
  commandLog.append("\"" + fileNamePrefix + "\"");
  commandLog.append(",");
  commandLog.append("\"" + rewriteRulesFile + "\"");
  emit logCommand("dumpXMLDAE("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QByteArray translationLevel_utf8 = translationLevel.toUtf8();
  QByteArray fileNamePrefix_utf8 = fileNamePrefix.toUtf8();
  QByteArray rewriteRulesFile_utf8 = rewriteRulesFile.toUtf8();
  dumpXMLDAE_res result;
  void *out2_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "dumpXMLDAE("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToDumpXMLDAE_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("dumpXMLDAE failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("dumpXMLDAE("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::translateGraphics(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("translateGraphics("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "translateGraphics("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("translateGraphics failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("translateGraphics("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::save(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("save("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "save("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("save failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("save("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::saveTotalModelDebug(QString filename, QString className, modelica_boolean stripAnnotations, modelica_boolean stripComments, modelica_boolean obfuscate)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(stripAnnotations ? "true" : "false");
  commandLog.append(",");
  commandLog.append(stripComments ? "true" : "false");
  commandLog.append(",");
  commandLog.append(obfuscate ? "true" : "false");
  emit logCommand("saveTotalModelDebug("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "saveTotalModelDebug("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("saveTotalModelDebug failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("saveTotalModelDebug("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::saveTotalModel(QString fileName, QString className, modelica_boolean stripAnnotations, modelica_boolean stripComments, modelica_boolean obfuscate)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  commandLog.append(",");
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(stripAnnotations ? "true" : "false");
  commandLog.append(",");
  commandLog.append(stripComments ? "true" : "false");
  commandLog.append(",");
  commandLog.append(obfuscate ? "true" : "false");
  emit logCommand("saveTotalModel("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "saveTotalModel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("saveTotalModel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("saveTotalModel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::saveModel(QString fileName, QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  commandLog.append(",");
  commandLog.append(className);
  emit logCommand("saveModel("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "saveModel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("saveModel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("saveModel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::deleteFile(QString fileName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  emit logCommand("deleteFile("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "deleteFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("deleteFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("deleteFile("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::loadModel(QString className, QList<QString > priorityVersion, modelica_boolean notify, QString languageStandard, modelica_boolean requireExactVersion)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append("{");
  int priorityVersion_i = 0;
  foreach(QString priorityVersion_elt, priorityVersion) {
    if (priorityVersion_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + priorityVersion_elt + "\"");
    priorityVersion_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append(notify ? "true" : "false");
  commandLog.append(",");
  commandLog.append("\"" + languageStandard + "\"");
  commandLog.append(",");
  commandLog.append(requireExactVersion ? "true" : "false");
  emit logCommand("loadModel("+commandLog+")");

  // QByteArray className_utf8 = className.toUtf8();
  // void *priorityVersion_lst = mmc_mk_nil();
  // for (int priorityVersion_i = priorityVersion.size()-1; priorityVersion_i>=0; priorityVersion_i--) {
  //   QString priorityVersion_elt = priorityVersion[priorityVersion_i];
  //   QByteArray priorityVersion_elt_utf8 = priorityVersion_elt.toUtf8();
  //   priorityVersion_lst = mmc_mk_cons(mmc_mk_scon(priorityVersion_elt_utf8.constData()), priorityVersion_lst);
  // }
  // QByteArray languageStandard_utf8 = languageStandard.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "loadModel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("loadModel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("loadModel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::generateCode(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("generateCode("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "generateCode("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("generateCode failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("generateCode("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::instantiateModel(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("instantiateModel("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "instantiateModel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("instantiateModel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("instantiateModel("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::checkAllModelsRecursive(QString className, modelica_boolean checkProtected)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(checkProtected ? "true" : "false");
  emit logCommand("checkAllModelsRecursive("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "checkAllModelsRecursive("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("checkAllModelsRecursive failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("checkAllModelsRecursive("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::checkModel(QString className)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  emit logCommand("checkModel("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "checkModel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("checkModel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("checkModel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::remove(QString path)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + path + "\"");
  emit logCommand("remove("+commandLog+")");

  QByteArray path_utf8 = path.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "remove("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("remove failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("remove("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::copy(QString source, QString destination)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + source + "\"");
  commandLog.append(",");
  commandLog.append("\"" + destination + "\"");
  emit logCommand("copy("+commandLog+")");

  QByteArray source_utf8 = source.toUtf8();
  QByteArray destination_utf8 = destination.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "copy("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("copy failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("copy("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::mkdir(QString newDirectory)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + newDirectory + "\"");
  emit logCommand("mkdir("+commandLog+")");

  QByteArray newDirectory_utf8 = newDirectory.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "mkdir("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("mkdir failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("mkdir("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::cd(QString newWorkingDirectory)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + newWorkingDirectory + "\"");
  emit logCommand("cd("+commandLog+")");

  // QByteArray newWorkingDirectory_utf8 = newWorkingDirectory.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "cd("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("cd failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("cd("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getAstAsCorbaString(QString fileName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  emit logCommand("getAstAsCorbaString("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAstAsCorbaString("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAstAsCorbaString failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAstAsCorbaString("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getLanguageStandard()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getLanguageStandard()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getLanguageStandard()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getLanguageStandard failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getLanguageStandard()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::getOrderConnections()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getOrderConnections()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getOrderConnections()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getOrderConnections failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getOrderConnections()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::getShowAnnotations()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getShowAnnotations()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getShowAnnotations()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getShowAnnotations failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getShowAnnotations()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setShowAnnotations(modelica_boolean show)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(show ? "true" : "false");
  emit logCommand("setShowAnnotations("+commandLog+")");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setShowAnnotations("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setShowAnnotations failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setShowAnnotations("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getDefaultOpenCLDevice()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getDefaultOpenCLDevice()");

  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getDefaultOpenCLDevice()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getDefaultOpenCLDevice failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getDefaultOpenCLDevice()", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::getVectorizationLimit()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getVectorizationLimit()");

  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getVectorizationLimit()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getVectorizationLimit failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getVectorizationLimit()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setNoSimplify(modelica_boolean noSimplify)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(noSimplify ? "true" : "false");
  emit logCommand("setNoSimplify("+commandLog+")");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setNoSimplify("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setNoSimplify failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setNoSimplify("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::getNoSimplify()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getNoSimplify()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getNoSimplify()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getNoSimplify failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getNoSimplify()", responseLog, elapsed);

  return result;
}
QString OMCInterface::getAnnotationVersion()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getAnnotationVersion()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAnnotationVersion()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAnnotationVersion failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAnnotationVersion()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::echo(modelica_boolean setEcho)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(setEcho ? "true" : "false");
  emit logCommand("echo("+commandLog+")");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "echo("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("echo failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("echo("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::runScript(QString fileName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  emit logCommand("runScript("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "runScript("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("runScript failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("runScript("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::clearMessages()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("clearMessages()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "clearMessages()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("clearMessages failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("clearMessages()", responseLog, elapsed);

  return result;
}
OMCInterface::countMessages_res OMCInterface::countMessages()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("countMessages()");

  countMessages_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "countMessages()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToCountMessages_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("countMessages failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("countMessages()", responseLog, elapsed);

  return result;
}
QString OMCInterface::getErrorString(modelica_boolean warningsAsErrors)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(warningsAsErrors ? "true" : "false");
  emit logCommand("getErrorString("+commandLog+")");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getErrorString("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getErrorString failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getErrorString("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::alarm(modelica_integer seconds)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(QString::number(seconds));
  emit logCommand("alarm("+commandLog+")");

  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "alarm("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("alarm failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("alarm("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::compareFiles(QString file1, QString file2)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + file1 + "\"");
  commandLog.append(",");
  commandLog.append("\"" + file2 + "\"");
  emit logCommand("compareFiles("+commandLog+")");

  QByteArray file1_utf8 = file1.toUtf8();
  QByteArray file2_utf8 = file2.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "compareFiles("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("compareFiles failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("compareFiles("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::compareFilesAndMove(QString newFile, QString oldFile)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + newFile + "\"");
  commandLog.append(",");
  commandLog.append("\"" + oldFile + "\"");
  emit logCommand("compareFilesAndMove("+commandLog+")");

  QByteArray newFile_utf8 = newFile.toUtf8();
  QByteArray oldFile_utf8 = oldFile.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "compareFilesAndMove("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("compareFilesAndMove failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("compareFilesAndMove("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::writeFile(QString fileName, QString data, modelica_boolean append)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  commandLog.append(",");
  commandLog.append("\"" + data + "\"");
  commandLog.append(",");
  commandLog.append(append ? "true" : "false");
  emit logCommand("writeFile("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  QByteArray data_utf8 = data.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "writeFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("writeFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("writeFile("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::readFile(QString fileName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  emit logCommand("readFile("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "readFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("readFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("readFile("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::stat_res OMCInterface::stat(QString fileName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  emit logCommand("stat("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  stat_res result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "stat("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToStat_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("stat failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("stat("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::directoryExists(QString dirName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + dirName + "\"");
  emit logCommand("directoryExists("+commandLog+")");

  QByteArray dirName_utf8 = dirName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "directoryExists("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("directoryExists failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("directoryExists("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::regularFileExists(QString fileName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  emit logCommand("regularFileExists("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "regularFileExists("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("regularFileExists failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("regularFileExists("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getVersion(QString cl)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(cl);
  emit logCommand("getVersion("+commandLog+")");

  QByteArray cl_utf8 = cl.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getVersion("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getVersion failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getVersion("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::clearCommandLineOptions()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("clearCommandLineOptions()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "clearCommandLineOptions()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("clearCommandLineOptions failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("clearCommandLineOptions()", responseLog, elapsed);

  return result;
}
OMCInterface::getConfigFlagValidOptions_res OMCInterface::getConfigFlagValidOptions(QString flag)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + flag + "\"");
  emit logCommand("getConfigFlagValidOptions("+commandLog+")");

  QByteArray flag_utf8 = flag.toUtf8();
  getConfigFlagValidOptions_res result;
  void *out1_mm = NULL;
  void *out2_mm = NULL;
  void *out3_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getConfigFlagValidOptions("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToGetConfigFlagValidOptions_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getConfigFlagValidOptions failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getConfigFlagValidOptions("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::getCommandLineOptions()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getCommandLineOptions()");

  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getCommandLineOptions()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getCommandLineOptions failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getCommandLineOptions()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setCommandLineOptions(QString options)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + options + "\"");
  emit logCommand("setCommandLineOptions("+commandLog+")");

  QByteArray options_utf8 = options.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setCommandLineOptions("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setCommandLineOptions failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setCommandLineOptions("+commandLog+")", responseLog, elapsed);

  return result;
}
OMCInterface::getAvailableTearingMethods_res OMCInterface::getAvailableTearingMethods()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getAvailableTearingMethods()");

  getAvailableTearingMethods_res result;
  void *out1_mm = NULL;
  void *out2_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAvailableTearingMethods()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToGetAvailableTearingMethods_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAvailableTearingMethods failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAvailableTearingMethods()", responseLog, elapsed);

  return result;
}
QString OMCInterface::getTearingMethod()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getTearingMethod()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getTearingMethod()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getTearingMethod failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getTearingMethod()", responseLog, elapsed);

  return result;
}
OMCInterface::getAvailableIndexReductionMethods_res OMCInterface::getAvailableIndexReductionMethods()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getAvailableIndexReductionMethods()");

  getAvailableIndexReductionMethods_res result;
  void *out1_mm = NULL;
  void *out2_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAvailableIndexReductionMethods()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToGetAvailableIndexReductionMethods_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAvailableIndexReductionMethods failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAvailableIndexReductionMethods()", responseLog, elapsed);

  return result;
}
QString OMCInterface::getIndexReductionMethod()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getIndexReductionMethod()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getIndexReductionMethod()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getIndexReductionMethod failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getIndexReductionMethod()", responseLog, elapsed);

  return result;
}
OMCInterface::getAvailableMatchingAlgorithms_res OMCInterface::getAvailableMatchingAlgorithms()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getAvailableMatchingAlgorithms()");

  getAvailableMatchingAlgorithms_res result;
  void *out1_mm = NULL;
  void *out2_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getAvailableMatchingAlgorithms()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToGetAvailableMatchingAlgorithms_res(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("getAvailableMatchingAlgorithms failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result.toString());
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getAvailableMatchingAlgorithms()", responseLog, elapsed);

  return result;
}
QString OMCInterface::getMatchingAlgorithm()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getMatchingAlgorithm()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getMatchingAlgorithm()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getMatchingAlgorithm failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getMatchingAlgorithm()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::clearDebugFlags()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("clearDebugFlags()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "clearDebugFlags()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("clearDebugFlags failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("clearDebugFlags()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::disableNewInstantiation()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("disableNewInstantiation()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "disableNewInstantiation()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("disableNewInstantiation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("disableNewInstantiation()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::enableNewInstantiation()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("enableNewInstantiation()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "enableNewInstantiation()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("enableNewInstantiation failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("enableNewInstantiation()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setCompilerFlags(QString compilerFlags)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + compilerFlags + "\"");
  emit logCommand("setCompilerFlags("+commandLog+")");

  QByteArray compilerFlags_utf8 = compilerFlags.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setCompilerFlags("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setCompilerFlags failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setCompilerFlags("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getHomeDirectoryPath()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getHomeDirectoryPath()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getHomeDirectoryPath()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getHomeDirectoryPath failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getHomeDirectoryPath()", responseLog, elapsed);

  return result;
}
QString OMCInterface::getModelicaPath()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getModelicaPath()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getModelicaPath()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getModelicaPath failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getModelicaPath()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setModelicaPath(QString modelicaPath)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + modelicaPath + "\"");
  emit logCommand("setModelicaPath("+commandLog+")");

  QByteArray modelicaPath_utf8 = modelicaPath.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setModelicaPath("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setModelicaPath failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setModelicaPath("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getInstallationDirectoryPath()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getInstallationDirectoryPath()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getInstallationDirectoryPath()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getInstallationDirectoryPath failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getInstallationDirectoryPath()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setInstallationDirectoryPath(QString installationDirectoryPath)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + installationDirectoryPath + "\"");
  emit logCommand("setInstallationDirectoryPath("+commandLog+")");

  QByteArray installationDirectoryPath_utf8 = installationDirectoryPath.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setInstallationDirectoryPath("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setInstallationDirectoryPath failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setInstallationDirectoryPath("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setEnvironmentVar(QString var, QString value)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + var + "\"");
  commandLog.append(",");
  commandLog.append("\"" + value + "\"");
  emit logCommand("setEnvironmentVar("+commandLog+")");

  QByteArray var_utf8 = var.toUtf8();
  QByteArray value_utf8 = value.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setEnvironmentVar("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setEnvironmentVar failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setEnvironmentVar("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getEnvironmentVar(QString var)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + var + "\"");
  emit logCommand("getEnvironmentVar("+commandLog+")");

  QByteArray var_utf8 = var.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getEnvironmentVar("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getEnvironmentVar failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getEnvironmentVar("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getTempDirectoryPath()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getTempDirectoryPath()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getTempDirectoryPath()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getTempDirectoryPath failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getTempDirectoryPath()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setTempDirectoryPath(QString tempDirectoryPath)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + tempDirectoryPath + "\"");
  emit logCommand("setTempDirectoryPath("+commandLog+")");

  QByteArray tempDirectoryPath_utf8 = tempDirectoryPath.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setTempDirectoryPath("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setTempDirectoryPath failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setTempDirectoryPath("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setCXXCompiler(QString compiler)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + compiler + "\"");
  emit logCommand("setCXXCompiler("+commandLog+")");

  QByteArray compiler_utf8 = compiler.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setCXXCompiler("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setCXXCompiler failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setCXXCompiler("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getCXXCompiler()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getCXXCompiler()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getCXXCompiler()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getCXXCompiler failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getCXXCompiler()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setCFlags(QString inString)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + inString + "\"");
  emit logCommand("setCFlags("+commandLog+")");

  QByteArray inString_utf8 = inString.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setCFlags("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setCFlags failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setCFlags("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getCFlags()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getCFlags()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getCFlags()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getCFlags failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getCFlags()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setCompiler(QString compiler)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + compiler + "\"");
  emit logCommand("setCompiler("+commandLog+")");

  QByteArray compiler_utf8 = compiler.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setCompiler("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setCompiler failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setCompiler("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getCompiler()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getCompiler()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getCompiler()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getCompiler failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getCompiler()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setLinkerFlags(QString linkerFlags)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + linkerFlags + "\"");
  emit logCommand("setLinkerFlags("+commandLog+")");

  QByteArray linkerFlags_utf8 = linkerFlags.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setLinkerFlags("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setLinkerFlags failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setLinkerFlags("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getLinkerFlags()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getLinkerFlags()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getLinkerFlags()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getLinkerFlags failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getLinkerFlags()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::setLinker(QString linker)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + linker + "\"");
  emit logCommand("setLinker("+commandLog+")");

  QByteArray linker_utf8 = linker.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "setLinker("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("setLinker failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("setLinker("+commandLog+")", responseLog, elapsed);

  return result;
}
QString OMCInterface::getLinker()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("getLinker()");

  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "getLinker()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("getLinker failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("getLinker()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::generateSeparateCodeDependenciesMakefile(QString filename, QString directory, QString suffix)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + directory + "\"");
  commandLog.append(",");
  commandLog.append("\"" + suffix + "\"");
  emit logCommand("generateSeparateCodeDependenciesMakefile("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  QByteArray directory_utf8 = directory.toUtf8();
  QByteArray suffix_utf8 = suffix.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "generateSeparateCodeDependenciesMakefile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("generateSeparateCodeDependenciesMakefile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("generateSeparateCodeDependenciesMakefile("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::generateSeparateCodeDependencies(QString stampSuffix)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + stampSuffix + "\"");
  emit logCommand("generateSeparateCodeDependencies("+commandLog+")");

  QByteArray stampSuffix_utf8 = stampSuffix.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "generateSeparateCodeDependencies("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("generateSeparateCodeDependencies failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append("\"" + result_elt + "\"");
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("generateSeparateCodeDependencies("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::generateSeparateCode(QString className, modelica_boolean cleanCache)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(cleanCache ? "true" : "false");
  emit logCommand("generateSeparateCode("+commandLog+")");

  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "generateSeparateCode("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("generateSeparateCode failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("generateSeparateCode("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::generateJuliaHeader(QString fileName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  emit logCommand("generateJuliaHeader("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "generateJuliaHeader("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("generateJuliaHeader failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("generateJuliaHeader("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::generateHeader(QString fileName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  emit logCommand("generateHeader("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "generateHeader("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("generateHeader failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("generateHeader("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::clearVariables()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("clearVariables()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "clearVariables()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("clearVariables failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("clearVariables()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::clearProgram()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("clearProgram()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "clearProgram()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("clearProgram failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("clearProgram()", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::clear()
{
  QElapsedTimer commandTime;
  commandTime.start();
  emit logCommand("clear()");

  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "clear()";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("clear failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("clear()", responseLog, elapsed);

  return result;
}
QString OMCInterface::help(QString topic)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + topic + "\"");
  emit logCommand("help("+commandLog+")");

  QByteArray topic_utf8 = topic.toUtf8();
  QString result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "help("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = StringHandler::unparse(PythonQtConverter::ToQString(python_result));



    
  } catch(std::exception &exception) {
    emit throwException(QString("help failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("\"" + result + "\"");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("help("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::saveAll(QString fileName)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  emit logCommand("saveAll("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "saveAll("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("saveAll failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("saveAll("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<modelica_integer > OMCInterface::system_parallel(QList<QString > callStr, modelica_integer numThreads)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("{");
  int callStr_i = 0;
  foreach(QString callStr_elt, callStr) {
    if (callStr_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + callStr_elt + "\"");
    callStr_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append(QString::number(numThreads));
  emit logCommand("system__parallel("+commandLog+")");

  // void *callStr_lst = mmc_mk_nil();
  // for (int callStr_i = callStr.size()-1; callStr_i>=0; callStr_i--) {
  //   QString callStr_elt = callStr[callStr_i];
  //   QByteArray callStr_elt_utf8 = callStr_elt.toUtf8();
  //   callStr_lst = mmc_mk_cons(mmc_mk_scon(callStr_elt_utf8.constData()), callStr_lst);
  // }
  QList<modelica_integer > result;
  // void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "system__parallel("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("system__parallel failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(modelica_integer result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(QString::number(result_elt));
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("system__parallel("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_integer OMCInterface::system(QString callStr, QString outputFile)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + callStr + "\"");
  commandLog.append(",");
  commandLog.append("\"" + outputFile + "\"");
  emit logCommand("system("+commandLog+")");

  QByteArray callStr_utf8 = callStr.toUtf8();
  QByteArray outputFile_utf8 = outputFile.toUtf8();
  modelica_integer result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "system("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaInteger(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("system failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(QString::number(result));
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("system("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::loadFileInteractive(QString filename, QString encoding, modelica_boolean uses, modelica_boolean notify, modelica_boolean requireExactVersion)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + encoding + "\"");
  commandLog.append(",");
  commandLog.append(uses ? "true" : "false");
  commandLog.append(",");
  commandLog.append(notify ? "true" : "false");
  commandLog.append(",");
  commandLog.append(requireExactVersion ? "true" : "false");
  emit logCommand("loadFileInteractive("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  QByteArray encoding_utf8 = encoding.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "loadFileInteractive("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("loadFileInteractive failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("loadFileInteractive("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::loadFileInteractiveQualified(QString filename, QString encoding)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + encoding + "\"");
  emit logCommand("loadFileInteractiveQualified("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  QByteArray encoding_utf8 = encoding.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "loadFileInteractiveQualified("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("loadFileInteractiveQualified failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("loadFileInteractiveQualified("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::parseFile(QString filename, QString encoding)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + encoding + "\"");
  emit logCommand("parseFile("+commandLog+")");

  QByteArray filename_utf8 = filename.toUtf8();
  QByteArray encoding_utf8 = encoding.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "parseFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("parseFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("parseFile("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::parseString(QString data, QString filename)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + data + "\"");
  commandLog.append(",");
  commandLog.append("\"" + filename + "\"");
  emit logCommand("parseString("+commandLog+")");

  QByteArray data_utf8 = data.toUtf8();
  QByteArray filename_utf8 = filename.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {

    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "parseString("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);

  } catch(std::exception &exception) {
    emit throwException(QString("parseString failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("parseString("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::loadClassContentString(QString data, QString className, modelica_integer offsetX, modelica_integer offsetY)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + data + "\"");
  commandLog.append(",");
  commandLog.append(className);
  commandLog.append(",");
  commandLog.append(QString::number(offsetX));
  commandLog.append(",");
  commandLog.append(QString::number(offsetY));
  emit logCommand("loadClassContentString("+commandLog+")");

  QByteArray data_utf8 = data.toUtf8();
  QByteArray className_utf8 = className.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "loadClassContentString("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("loadClassContentString failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("loadClassContentString("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::loadString(QString data, QString filename, QString encoding, modelica_boolean merge, modelica_boolean uses, modelica_boolean notify, modelica_boolean requireExactVersion)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + data + "\"");
  commandLog.append(",");
  commandLog.append("\"" + filename + "\"");
  commandLog.append(",");
  commandLog.append("\"" + encoding + "\"");
  commandLog.append(",");
  commandLog.append(merge ? "true" : "false");
  commandLog.append(",");
  commandLog.append(uses ? "true" : "false");
  commandLog.append(",");
  commandLog.append(notify ? "true" : "false");
  commandLog.append(",");
  commandLog.append(requireExactVersion ? "true" : "false");
  emit logCommand("loadString("+commandLog+")");

  QByteArray data_utf8 = data.toUtf8();
  QByteArray filename_utf8 = filename.toUtf8();
  QByteArray encoding_utf8 = encoding.toUtf8();
  modelica_boolean result;
  modelica_boolean result1;


  // try {
  //   MMC_TRY_TOP_INTERNAL()
  
  //   result1 = omc_OpenModelicaScriptingAPI_loadString(threadData, mmc_mk_scon(data_utf8.constData()), mmc_mk_scon(filename_utf8.constData()), mmc_mk_scon(encoding_utf8.constData()), merge, uses, notify, requireExactVersion);
  //   std::cout << "Dai Yuhang loadString result origin: " << result << std::endl;
  //   MMC_CATCH_TOP()
  // } catch(std::exception &exception) {
  //   emit throwException(QString("loadString failed. %1").arg(exception.what()));
  // }

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "loadString("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);
    // std::cout << "Dai Yuhang loadString result python: " << result << std::endl;



    
  } catch(std::exception &exception) {
    emit throwException(QString("loadString failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("loadString("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::reloadClass(QString name, QString encoding)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append(name);
  commandLog.append(",");
  commandLog.append("\"" + encoding + "\"");
  emit logCommand("reloadClass("+commandLog+")");

  QByteArray name_utf8 = name.toUtf8();
  QByteArray encoding_utf8 = encoding.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "reloadClass("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("reloadClass failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("reloadClass("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::loadEncryptedPackage(QString fileName, QString workdir, modelica_boolean skipUnzip, modelica_boolean uses, modelica_boolean notify, modelica_boolean requireExactVersion)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  commandLog.append(",");
  commandLog.append("\"" + workdir + "\"");
  commandLog.append(",");
  commandLog.append(skipUnzip ? "true" : "false");
  commandLog.append(",");
  commandLog.append(uses ? "true" : "false");
  commandLog.append(",");
  commandLog.append(notify ? "true" : "false");
  commandLog.append(",");
  commandLog.append(requireExactVersion ? "true" : "false");
  emit logCommand("loadEncryptedPackage("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  QByteArray workdir_utf8 = workdir.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "loadEncryptedPackage("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("loadEncryptedPackage failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("loadEncryptedPackage("+commandLog+")", responseLog, elapsed);

  return result;
}
QList<QString > OMCInterface::parseEncryptedPackage(QString fileName, QString workdir)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  commandLog.append(",");
  commandLog.append("\"" + workdir + "\"");
  emit logCommand("parseEncryptedPackage("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  QByteArray workdir_utf8 = workdir.toUtf8();
  QList<QString > result;
  void *result_mm = NULL;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "parseEncryptedPackage("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToQListQString(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("parseEncryptedPackage failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append("{");
  int result_i = 0;
  foreach(QString result_elt, result) {
    if (result_i) {
      responseLog.append(",");
    }
    responseLog.append(result_elt);
    result_i++;
  }
  responseLog.append("}");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("parseEncryptedPackage("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::loadFiles(QList<QString > fileNames, QString encoding, modelica_integer numThreads, modelica_boolean uses, modelica_boolean notify, modelica_boolean requireExactVersion, modelica_boolean allowWithin)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("{");
  int fileNames_i = 0;
  foreach(QString fileNames_elt, fileNames) {
    if (fileNames_i) {
      commandLog.append(",");
    }
    commandLog.append("\"" + fileNames_elt + "\"");
    fileNames_i++;
  }
  commandLog.append("}");commandLog.append(",");
  commandLog.append("\"" + encoding + "\"");
  commandLog.append(",");
  commandLog.append(QString::number(numThreads));
  commandLog.append(",");
  commandLog.append(uses ? "true" : "false");
  commandLog.append(",");
  commandLog.append(notify ? "true" : "false");
  commandLog.append(",");
  commandLog.append(requireExactVersion ? "true" : "false");
  commandLog.append(",");
  commandLog.append(allowWithin ? "true" : "false");
  emit logCommand("loadFiles("+commandLog+")");

  // void *fileNames_lst = mmc_mk_nil();
  // for (int fileNames_i = fileNames.size()-1; fileNames_i>=0; fileNames_i--) {
  //   QString fileNames_elt = fileNames[fileNames_i];
  //   QByteArray fileNames_elt_utf8 = fileNames_elt.toUtf8();
  //   fileNames_lst = mmc_mk_cons(mmc_mk_scon(fileNames_elt_utf8.constData()), fileNames_lst);
  // }
  // QByteArray encoding_utf8 = encoding.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "loadFiles("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("loadFiles failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("loadFiles("+commandLog+")", responseLog, elapsed);

  return result;
}
modelica_boolean OMCInterface::loadFile(QString fileName, QString encoding, modelica_boolean uses, modelica_boolean notify, modelica_boolean requireExactVersion, modelica_boolean allowWithin)
{
  QElapsedTimer commandTime;
  commandTime.start();
  QString commandLog;
  commandLog.append("\"" + fileName + "\"");
  commandLog.append(",");
  commandLog.append("\"" + encoding + "\"");
  commandLog.append(",");
  commandLog.append(uses ? "true" : "false");
  commandLog.append(",");
  commandLog.append(notify ? "true" : "false");
  commandLog.append(",");
  commandLog.append(requireExactVersion ? "true" : "false");
  commandLog.append(",");
  commandLog.append(allowWithin ? "true" : "false");
  emit logCommand("loadFile("+commandLog+")");

  QByteArray fileName_utf8 = fileName.toUtf8();
  QByteArray encoding_utf8 = encoding.toUtf8();
  modelica_boolean result;

  try {
    



    // 使用python接口替换原有的omc_OpenModelicaScriptingAPI接口
    PythonEnv& python_env = PythonEnv::get_instance();
    std::string command = "loadFile("+commandLog.toStdString()+")";
    py::object python_result = python_env.send_expression_object(command, false);
    result = PythonQtConverter::ToModelicaBoolean(python_result);



    
  } catch(std::exception &exception) {
    emit throwException(QString("loadFile failed. %1").arg(exception.what()));
  }

  QString responseLog;
  responseLog.append(result ? "true" : "false");
  double elapsed = (double)commandTime.elapsed() / 1000.0;
  emit logResponse("loadFile("+commandLog+")", responseLog, elapsed);

  return result;
}
