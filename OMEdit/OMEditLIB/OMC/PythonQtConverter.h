#ifndef PYTHON_QT_CONVERTER_H
#define PYTHON_QT_CONVERTER_H

#include <QList>
#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include <QDebug>
#include <stdexcept>
#include "OpenModelicaScriptingAPIQt.h"
#include "../OMSimulator/Types.h"

// 前向声明避免头文件中包含pybind11
namespace pybind11 {
    class object;
}

/**
 * 字符串解析转换器类
 * 将Python返回的字符串解析为对应的Qt和OpenModelica类型
 * 实现toString()方法的逆过程
 */
class PythonQtConverter {
public:
    // 基础类型转换方法
    static QString ToQString(const QString& data);
    static QString ToQString(const pybind11::object& obj);
    static QList<QString> ToQListQString(const QString& data);
    static QList<QString> ToQListQString(const pybind11::object& obj);
    static QList<QList<QString>> ToQListQListQString(const QString& data);
    static QList<QList<QString>> ToQListQListQString(const pybind11::object& obj);
    static QList<modelica_real> ToQListModelicaReal(const QString& data);
    static QList<modelica_boolean> ToQListModelicaBoolean(const QString& data);
    static QList<modelica_boolean> ToQListModelicaBoolean(const pybind11::object& obj);
    static QList<modelica_integer> ToQListModelicaInteger(const QString& data);
    static QList<modelica_integer> ToQListModelicaInteger(const pybind11::object& obj);
    static QList<QList<modelica_real>> ToQListQListModelicaReal(const QString& data);

    // Modelica类型转换方法
    static modelica_boolean ToModelicaBoolean(const QString& data);
    static modelica_boolean ToModelicaBoolean(const pybind11::object& obj);
    static modelica_integer ToModelicaInteger(const QString& data);
    static modelica_integer ToModelicaInteger(const pybind11::object& obj);
    static modelica_real ToModelicaReal(const QString& data);
    static modelica_real ToModelicaReal(const pybind11::object& obj);

    // 结构体转换方法
    static OMCInterface::getConversionsFromVersions_res ToGetConversionsFromVersions_res(const QString& data);
    static OMCInterface::getConversionsFromVersions_res ToGetConversionsFromVersions_res(const pybind11::object& obj);
    static OMCInterface::generateScriptingAPI_res ToGenerateScriptingAPI_res(const QString& data);
    static OMCInterface::generateScriptingAPI_res ToGenerateScriptingAPI_res(const pybind11::object& obj);
    static OMCInterface::getClassInformation_res ToGetClassInformation_res(const QString& data);
    static OMCInterface::getClassInformation_res ToGetClassInformation_res(const pybind11::object& obj);

     // 更多结构体转换方法
     static OMCInterface::oms_loadSnapshot_res ToOms_loadSnapshot_res(const QString& data);
     static OMCInterface::oms_loadSnapshot_res ToOms_loadSnapshot_res(const pybind11::object& obj);
     static OMCInterface::oms_listUnconnectedConnectors_res ToOms_listUnconnectedConnectors_res(const QString& data);
     static OMCInterface::oms_listUnconnectedConnectors_res ToOms_listUnconnectedConnectors_res(const pybind11::object& obj);
     static OMCInterface::oms_list_res ToOms_list_res(const QString& data);
     static OMCInterface::oms_list_res ToOms_list_res(const pybind11::object& obj);
     static OMCInterface::oms_importFile_res ToOms_importFile_res(const QString& data);
     static OMCInterface::oms_importFile_res ToOms_importFile_res(const pybind11::object& obj);
     static OMCInterface::oms_getVariableStepSize_res ToOms_getVariableStepSize_res(const QString& data);
     static OMCInterface::oms_getVariableStepSize_res ToOms_getVariableStepSize_res(const pybind11::object& obj);
     static OMCInterface::oms_getTolerance_res ToOms_getTolerance_res(const QString& data);
     static OMCInterface::oms_getTolerance_res ToOms_getTolerance_res(const pybind11::object& obj);
     static OMCInterface::oms_getSystemType_res ToOms_getSystemType_res(const QString& data);
     static OMCInterface::oms_getSystemType_res ToOms_getSystemType_res(const pybind11::object& obj);
     static OMCInterface::oms_getSubModelPath_res ToOms_getSubModelPath_res(const QString& data);
     static OMCInterface::oms_getSubModelPath_res ToOms_getSubModelPath_res(const pybind11::object& obj);
     static OMCInterface::oms_getStopTime_res ToOms_getStopTime_res(const QString& data);
     static OMCInterface::oms_getStopTime_res ToOms_getStopTime_res(const pybind11::object& obj);
     static OMCInterface::oms_getStartTime_res ToOms_getStartTime_res(const QString& data);
     static OMCInterface::oms_getStartTime_res ToOms_getStartTime_res(const pybind11::object& obj);
     static OMCInterface::oms_getSolver_res ToOms_getSolver_res(const QString& data);
     static OMCInterface::oms_getSolver_res ToOms_getSolver_res(const pybind11::object& obj);
     static OMCInterface::oms_getReal_res ToOms_getReal_res(const QString& data);
     static OMCInterface::oms_getReal_res ToOms_getReal_res(const pybind11::object& obj);
     static OMCInterface::oms_getModelState_res ToOms_getModelState_res(const QString& data);
     static OMCInterface::oms_getModelState_res ToOms_getModelState_res(const pybind11::object& obj);
     static OMCInterface::oms_getFixedStepSize_res ToOms_getFixedStepSize_res(const QString& data);
     static OMCInterface::oms_getFixedStepSize_res ToOms_getFixedStepSize_res(const pybind11::object& obj);
     static OMCInterface::oms_getBoolean_res ToOms_getBoolean_res(const QString& data);
     static OMCInterface::oms_getBoolean_res ToOms_getBoolean_res(const pybind11::object& obj);
     static OMCInterface::oms_extractFMIKind_res ToOms_extractFMIKind_res(const QString& data);
     static OMCInterface::oms_extractFMIKind_res ToOms_extractFMIKind_res(const pybind11::object& obj);
     static OMCInterface::oms_exportSnapshot_res ToOms_exportSnapshot_res(const QString& data);
     static OMCInterface::oms_exportSnapshot_res ToOms_exportSnapshot_res(const pybind11::object& obj);
     static OMCInterface::getSimulationOptions_res ToGetSimulationOptions_res(const QString& data);
     static OMCInterface::getSimulationOptions_res ToGetSimulationOptions_res(const pybind11::object& obj);
     static OMCInterface::getTimeStamp_res ToGetTimeStamp_res(const QString& data);
     static OMCInterface::getTimeStamp_res ToGetTimeStamp_res(const pybind11::object& obj);
     static OMCInterface::getImportedNames_res ToGetImportedNames_res(const QString& data);
     static OMCInterface::getImportedNames_res ToGetImportedNames_res(const pybind11::object& obj);
     static OMCInterface::diffSimulationResults_res ToDiffSimulationResults_res(const QString& data);
     static OMCInterface::diffSimulationResults_res ToDiffSimulationResults_res(const pybind11::object& obj);
     static OMCInterface::solveLinearSystem_res ToSolveLinearSystem_res(const QString& data);
     static OMCInterface::solveLinearSystem_res ToSolveLinearSystem_res(const pybind11::object& obj);
     static OMCInterface::convertUnits_res ToConvertUnits_res(const QString& data);
     static OMCInterface::convertUnits_res ToConvertUnits_res(const pybind11::object& obj);
     static OMCInterface::dumpXMLDAE_res ToDumpXMLDAE_res(const QString& data);
     static OMCInterface::dumpXMLDAE_res ToDumpXMLDAE_res(const pybind11::object& obj);
     static OMCInterface::countMessages_res ToCountMessages_res(const QString& data);
     static OMCInterface::countMessages_res ToCountMessages_res(const pybind11::object& obj);
     static OMCInterface::stat_res ToStat_res(const QString& data);
     static OMCInterface::stat_res ToStat_res(const pybind11::object& obj);
     static OMCInterface::getConfigFlagValidOptions_res ToGetConfigFlagValidOptions_res(const QString& data);
     static OMCInterface::getConfigFlagValidOptions_res ToGetConfigFlagValidOptions_res(const pybind11::object& obj);
     static OMCInterface::getAvailableTearingMethods_res ToGetAvailableTearingMethods_res(const QString& data);
     static OMCInterface::getAvailableTearingMethods_res ToGetAvailableTearingMethods_res(const pybind11::object& obj);
     static OMCInterface::getAvailableIndexReductionMethods_res ToGetAvailableIndexReductionMethods_res(const QString& data);
     static OMCInterface::getAvailableIndexReductionMethods_res ToGetAvailableIndexReductionMethods_res(const pybind11::object& obj);
     static OMCInterface::getAvailableMatchingAlgorithms_res ToGetAvailableMatchingAlgorithms_res(const QString& data);
     static OMCInterface::getAvailableMatchingAlgorithms_res ToGetAvailableMatchingAlgorithms_res(const pybind11::object& obj);

     // 工具方法
    static QString ExtractStringFromQuotes(const QString& input);
    static QStringList ParseArray(const QString& input);
    static QStringList ParseTuple(const QString& input);
    static QString RemoveOuterParentheses(const QString& input);
    static QString RemoveOuterBraces(const QString& input);
    static QString UnescapeString(const QString& input);

    // OMSimulator_Types部分转换
    static oms_message_type_enu_t To_oms_message_type_enu_t(const pybind11::object& obj);
    static oms_status_enu_t To_oms_status_enu_t(const pybind11::object& obj);
    static oms_modelState_enu_t To_oms_modelState_enu_t(const pybind11::object& obj);
    static oms_causality_enu_t To_oms_causality_enu_t(const pybind11::object& obj);
    static oms_tlm_interpolation_t To_oms_tlm_interpolation_t(const pybind11::object& obj);
    static oms_fault_type_enu_t To_oms_fault_type_enu_t(const pybind11::object& obj);
    static oms_tlm_domain_t To_oms_tlm_domain_t(const pybind11::object& obj);
    static oms_solver_enu_t To_oms_solver_enu_t(const pybind11::object& obj);
    static oms_alg_solver_enu_t To_oms_alg_solver_enu_t(const pybind11::object& obj);
    static oms_element_enu_t To_oms_element_enu_t(const pybind11::object& obj);
    static oms_system_enu_t To_oms_system_enu_t(const pybind11::object& obj);
    static oms_component_enu_t To_oms_component_enu_t(const pybind11::object& obj);
    static oms_signal_type_enu_t To_oms_signal_type_enu_t(const pybind11::object& obj);
    static oms_connection_type_enu_t To_oms_connection_type_enu_t(const pybind11::object& obj);
    static oms_fmi_kind_enu_t To_oms_fmi_kind_enu_t(const pybind11::object& obj);

private:
    // 私有辅助方法
    static QStringList ParseTupleString(const QString& input);
    static int findMatchingBrace(const QString& input, int start, QChar openChar, QChar closeChar);
    static QStringList splitAtTopLevel(const QString& input, QChar separator);
};

#endif // PYTHON_QT_CONVERTER_H
