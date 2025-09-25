#include "PythonQtConverter.h"
#include <QRegularExpression>
#include <QDebug>

// 处理Qt slots宏与Python.h的冲突
#ifdef slots
#undef slots
#endif
#include <pybind11/pybind11.h>
#define slots Q_SLOTS

// 基础类型转换方法
QString PythonQtConverter::ToQString(const QString& data) {
    // 移除首尾的引号（如果存在）
    QString result = data.trimmed();
    if (result.startsWith('"') && result.endsWith('"')) {
        result = result.mid(1, result.length() - 2);
    }
    return result;
}

// pybind11::object重载版本 - 结构体转换函数
OMCInterface::getConversionsFromVersions_res PythonQtConverter::ToGetConversionsFromVersions_res(const pybind11::object& obj) {
    try {
        return ToGetConversionsFromVersions_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to getConversionsFromVersions_res:" << e.what();
        return OMCInterface::getConversionsFromVersions_res{};
    }
}

OMCInterface::generateScriptingAPI_res PythonQtConverter::ToGenerateScriptingAPI_res(const pybind11::object& obj) {
    try {
        return ToGenerateScriptingAPI_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to generateScriptingAPI_res:" << e.what();
        return OMCInterface::generateScriptingAPI_res{};
    }
}

OMCInterface::getClassInformation_res PythonQtConverter::ToGetClassInformation_res(const pybind11::object& obj) {
    try {
        return ToGetClassInformation_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to getClassInformation_res:" << e.what();
        return OMCInterface::getClassInformation_res{};
    }
}

OMCInterface::oms_loadSnapshot_res PythonQtConverter::ToOms_loadSnapshot_res(const pybind11::object& obj) {
    try {
        return ToOms_loadSnapshot_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_loadSnapshot_res:" << e.what();
        return OMCInterface::oms_loadSnapshot_res{};
    }
}

OMCInterface::oms_listUnconnectedConnectors_res PythonQtConverter::ToOms_listUnconnectedConnectors_res(const pybind11::object& obj) {
    try {
        return ToOms_listUnconnectedConnectors_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_listUnconnectedConnectors_res:" << e.what();
        return OMCInterface::oms_listUnconnectedConnectors_res{};
    }
}

OMCInterface::oms_list_res PythonQtConverter::ToOms_list_res(const pybind11::object& obj) {
    try {
        return ToOms_list_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_list_res:" << e.what();
        return OMCInterface::oms_list_res{};
    }
}

OMCInterface::oms_importFile_res PythonQtConverter::ToOms_importFile_res(const pybind11::object& obj) {
    try {
        return ToOms_importFile_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_importFile_res:" << e.what();
        return OMCInterface::oms_importFile_res{};
    }
}

OMCInterface::oms_getVariableStepSize_res PythonQtConverter::ToOms_getVariableStepSize_res(const pybind11::object& obj) {
    try {
        return ToOms_getVariableStepSize_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_getVariableStepSize_res:" << e.what();
        return OMCInterface::oms_getVariableStepSize_res{};
    }
}

OMCInterface::oms_getTolerance_res PythonQtConverter::ToOms_getTolerance_res(const pybind11::object& obj) {
    try {
        return ToOms_getTolerance_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_getTolerance_res:" << e.what();
        return OMCInterface::oms_getTolerance_res{};
    }
}

OMCInterface::oms_getSystemType_res PythonQtConverter::ToOms_getSystemType_res(const pybind11::object& obj) {
    try {
        return ToOms_getSystemType_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_getSystemType_res:" << e.what();
        return OMCInterface::oms_getSystemType_res{};
    }
}

OMCInterface::oms_getSubModelPath_res PythonQtConverter::ToOms_getSubModelPath_res(const pybind11::object& obj) {
    try {
        return ToOms_getSubModelPath_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_getSubModelPath_res:" << e.what();
        return OMCInterface::oms_getSubModelPath_res{};
    }
}

OMCInterface::oms_getStopTime_res PythonQtConverter::ToOms_getStopTime_res(const pybind11::object& obj) {
    try {
        return ToOms_getStopTime_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_getStopTime_res:" << e.what();
        return OMCInterface::oms_getStopTime_res{};
    }
}

OMCInterface::oms_getStartTime_res PythonQtConverter::ToOms_getStartTime_res(const pybind11::object& obj) {
    try {
        return ToOms_getStartTime_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_getStartTime_res:" << e.what();
        return OMCInterface::oms_getStartTime_res{};
    }
}

OMCInterface::oms_getSolver_res PythonQtConverter::ToOms_getSolver_res(const pybind11::object& obj) {
    try {
        return ToOms_getSolver_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_getSolver_res:" << e.what();
        return OMCInterface::oms_getSolver_res{};
    }
}

OMCInterface::oms_getReal_res PythonQtConverter::ToOms_getReal_res(const pybind11::object& obj) {
    try {
        return ToOms_getReal_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_getReal_res:" << e.what();
        return OMCInterface::oms_getReal_res{};
    }
}

OMCInterface::oms_getModelState_res PythonQtConverter::ToOms_getModelState_res(const pybind11::object& obj) {
    try {
        return ToOms_getModelState_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_getModelState_res:" << e.what();
        return OMCInterface::oms_getModelState_res{};
    }
}

OMCInterface::oms_getFixedStepSize_res PythonQtConverter::ToOms_getFixedStepSize_res(const pybind11::object& obj) {
    try {
        return ToOms_getFixedStepSize_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_getFixedStepSize_res:" << e.what();
        return OMCInterface::oms_getFixedStepSize_res{};
    }
}

OMCInterface::oms_getBoolean_res PythonQtConverter::ToOms_getBoolean_res(const pybind11::object& obj) {
    try {
        return ToOms_getBoolean_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_getBoolean_res:" << e.what();
        return OMCInterface::oms_getBoolean_res{};
    }
}

OMCInterface::oms_extractFMIKind_res PythonQtConverter::ToOms_extractFMIKind_res(const pybind11::object& obj) {
    try {
        return ToOms_extractFMIKind_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_extractFMIKind_res:" << e.what();
        return OMCInterface::oms_extractFMIKind_res{};
    }
}

OMCInterface::oms_exportSnapshot_res PythonQtConverter::ToOms_exportSnapshot_res(const pybind11::object& obj) {
    try {
        return ToOms_exportSnapshot_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to oms_exportSnapshot_res:" << e.what();
        return OMCInterface::oms_exportSnapshot_res{};
    }
}

OMCInterface::getSimulationOptions_res PythonQtConverter::ToGetSimulationOptions_res(const pybind11::object& obj) {
    try {
        return ToGetSimulationOptions_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to getSimulationOptions_res:" << e.what();
        return OMCInterface::getSimulationOptions_res{};
    }
}

OMCInterface::getTimeStamp_res PythonQtConverter::ToGetTimeStamp_res(const pybind11::object& obj) {
    try {
        return ToGetTimeStamp_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to getTimeStamp_res:" << e.what();
        return OMCInterface::getTimeStamp_res{};
    }
}

OMCInterface::getImportedNames_res PythonQtConverter::ToGetImportedNames_res(const pybind11::object& obj) {
    try {
        return ToGetImportedNames_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to getImportedNames_res:" << e.what();
        return OMCInterface::getImportedNames_res{};
    }
}

OMCInterface::diffSimulationResults_res PythonQtConverter::ToDiffSimulationResults_res(const pybind11::object& obj) {
    try {
        return ToDiffSimulationResults_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to diffSimulationResults_res:" << e.what();
        return OMCInterface::diffSimulationResults_res{};
    }
}

OMCInterface::solveLinearSystem_res PythonQtConverter::ToSolveLinearSystem_res(const pybind11::object& obj) {
    try {
        return ToSolveLinearSystem_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to solveLinearSystem_res:" << e.what();
        return OMCInterface::solveLinearSystem_res{};
    }
}

OMCInterface::convertUnits_res PythonQtConverter::ToConvertUnits_res(const pybind11::object& obj) {
    try {
        return ToConvertUnits_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to convertUnits_res:" << e.what();
        return OMCInterface::convertUnits_res{};
    }
}

OMCInterface::dumpXMLDAE_res PythonQtConverter::ToDumpXMLDAE_res(const pybind11::object& obj) {
    try {
        return ToDumpXMLDAE_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to dumpXMLDAE_res:" << e.what();
        return OMCInterface::dumpXMLDAE_res{};
    }
}

OMCInterface::countMessages_res PythonQtConverter::ToCountMessages_res(const pybind11::object& obj) {
    try {
        return ToCountMessages_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to countMessages_res:" << e.what();
        return OMCInterface::countMessages_res{};
    }
}

OMCInterface::stat_res PythonQtConverter::ToStat_res(const pybind11::object& obj) {
    try {
        return ToStat_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to stat_res:" << e.what();
        return OMCInterface::stat_res{};
    }
}

OMCInterface::getConfigFlagValidOptions_res PythonQtConverter::ToGetConfigFlagValidOptions_res(const pybind11::object& obj) {
    try {
        return ToGetConfigFlagValidOptions_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to getConfigFlagValidOptions_res:" << e.what();
        return OMCInterface::getConfigFlagValidOptions_res{};
    }
}

OMCInterface::getAvailableTearingMethods_res PythonQtConverter::ToGetAvailableTearingMethods_res(const pybind11::object& obj) {
    try {
        return ToGetAvailableTearingMethods_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to getAvailableTearingMethods_res:" << e.what();
        return OMCInterface::getAvailableTearingMethods_res{};
    }
}

OMCInterface::getAvailableIndexReductionMethods_res PythonQtConverter::ToGetAvailableIndexReductionMethods_res(const pybind11::object& obj) {
    try {
        return ToGetAvailableIndexReductionMethods_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to getAvailableIndexReductionMethods_res:" << e.what();
        return OMCInterface::getAvailableIndexReductionMethods_res{};
    }
}

OMCInterface::getAvailableMatchingAlgorithms_res PythonQtConverter::ToGetAvailableMatchingAlgorithms_res(const pybind11::object& obj) {
    try {
        return ToGetAvailableMatchingAlgorithms_res(ToQString(obj));
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to getAvailableMatchingAlgorithms_res:" << e.what();
        return OMCInterface::getAvailableMatchingAlgorithms_res{};
    }
}

// 在顶层分割字符串，考虑嵌套结构
QStringList PythonQtConverter::splitAtTopLevel(const QString& input, QChar separator) {
    QStringList result;
    QString current;
    int level = 0;
    bool inQuotes = false;

    for (int i = 0; i < input.length(); ++i) {
        QChar ch = input[i];

        if (ch == '"' && (i == 0 || input[i-1] != '\\')) {
            inQuotes = !inQuotes;
            current.append(ch);
        } else if (!inQuotes) {
            if (ch == '(' || ch == '{' || ch == '[') {
                level++;
                current.append(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                level--;
                current.append(ch);
            } else if (ch == separator && level == 0) {
                result.append(current.trimmed());
                current.clear();
            } else {
                current.append(ch);
            }
        } else {
            current.append(ch);
        }
    }

    if (!current.isEmpty()) {
        result.append(current.trimmed());
    }

    return result;
}

QString PythonQtConverter::ToQString(const pybind11::object& obj) {
    // 将pybind11::object转换为QString
    try {
        std::string str = pybind11::str(obj);
        return QString::fromStdString(str);
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to QString:" << e.what();
        return QString();
    }
}

QList<QString> PythonQtConverter::ToQListQString(const QString& data) {
    QList<QString> result;
    QString trimmed = data.trimmed();

    // 移除外层的大括号
    if (trimmed.startsWith('{') && trimmed.endsWith('}')) {
        trimmed = trimmed.mid(1, trimmed.length() - 2);
    }

    if (trimmed.isEmpty()) {
        return result;
    }

    // 使用正则表达式分割字符串，考虑引号内的逗号
    QRegularExpression regex("(?:^|,)(?:\\s*\"([^\"]*)\"\\s*|([^,]+))");
    QRegularExpressionMatchIterator iterator = regex.globalMatch(trimmed);

    while (iterator.hasNext()) {
        QRegularExpressionMatch match = iterator.next();
        QString item;
        if (!match.captured(1).isEmpty()) {
            item = match.captured(1); // 引号内的内容
        } else {
            item = match.captured(2).trimmed(); // 非引号内容
        }
        if (!item.isEmpty()) {
            result.append(item);
        }
    }

    return result;
}

QList<QString> PythonQtConverter::ToQListQString(const pybind11::object& obj) {
    try {
        // 尝试直接转换为QList<QString>
        if (pybind11::isinstance<pybind11::list>(obj)) {
            QList<QString> result;
            pybind11::list py_list = obj.cast<pybind11::list>();
            for (auto item : py_list) {
                result.append(QString::fromStdString(item.cast<std::string>()));
            }
            return result;
        }
        
        // 如果不是列表，尝试转换为字符串后调用原函数
        QString str = QString::fromStdString(obj.cast<std::string>());
        return ToQListQString(str);
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to QList<QString>:" << e.what();
        return QList<QString>();
    }
}

QList<QList<QString>> PythonQtConverter::ToQListQListQString(const QString& data) {
    QList<QList<QString>> result;
    QString trimmed = data.trimmed();

    // 移除外层的大括号
    if (trimmed.startsWith('{') && trimmed.endsWith('}')) {
        trimmed = trimmed.mid(1, trimmed.length() - 2);
    }

    if (trimmed.isEmpty()) {
        return result;
    }

    // 解析嵌套的列表结构
    int braceLevel = 0;
    QString currentList;

    for (int i = 0; i < trimmed.length(); ++i) {
        QChar ch = trimmed[i];

        if (ch == '{') {
            braceLevel++;
            if (braceLevel == 1) {
                currentList.clear();
                continue;
            }
        } else if (ch == '}') {
            braceLevel--;
            if (braceLevel == 0) {
                result.append(ToQListQString(currentList));
                currentList.clear();
                continue;
            }
        }

        if (braceLevel > 0) {
            currentList.append(ch);
        }
    }

    return result;
}

QList<QList<QString>> PythonQtConverter::ToQListQListQString(const pybind11::object& obj) {
    try {
        // 尝试直接转换为QList<QList<QString>>
        if (pybind11::isinstance<pybind11::list>(obj)) {
            QList<QList<QString>> result;
            pybind11::list py_list = obj.cast<pybind11::list>();
            for (auto item : py_list) {
                if (pybind11::isinstance<pybind11::list>(item)) {
                    QList<QString> inner_list;
                    pybind11::list py_inner_list = item.cast<pybind11::list>();
                    for (auto inner_item : py_inner_list) {
                        inner_list.append(QString::fromStdString(inner_item.cast<std::string>()));
                    }
                    result.append(inner_list);
                }
            }
            return result;
        }
        
        // 如果不是列表，尝试转换为字符串后调用原函数
        QString str = QString::fromStdString(obj.cast<std::string>());
        return ToQListQListQString(str);
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to QList<QList<QString>>:" << e.what();
        return QList<QList<QString>>();
    }
}

// Modelica类型转换方法
modelica_boolean PythonQtConverter::ToModelicaBoolean(const QString& data) {
    QString trimmed = data.trimmed().toLower();
    return (trimmed == "true" || trimmed == "1") ? 1 : 0;
}

modelica_integer PythonQtConverter::ToModelicaInteger(const QString& data) {
    bool ok;
    modelica_integer result = data.trimmed().toLongLong(&ok);
    if (!ok) {
        qWarning() << "Failed to convert string to modelica_integer:" << data;
        return 0;
    }
    return result;
}

modelica_real PythonQtConverter::ToModelicaReal(const QString& data) {
    bool ok;
    modelica_real result = data.trimmed().toDouble(&ok);
    if (!ok) {
        qWarning() << "Failed to convert string to modelica_real:" << data;
        return 0.0;
    }
    return result;
}

modelica_boolean PythonQtConverter::ToModelicaBoolean(const pybind11::object& obj) {
    try {
        // 尝试直接转换为bool
        if (pybind11::isinstance<pybind11::bool_>(obj)) {
            return obj.cast<bool>() ? 1 : 0;
        }
        // 尝试转换为字符串然后解析
        std::string str = pybind11::str(obj);
        QString qstr = QString::fromStdString(str);
        return ToModelicaBoolean(qstr);
    } catch (const std::exception& e) {
        qWarning() << "Failed to convert pybind11::object to modelica_boolean:" << e.what();
        return 0;
    }
}

modelica_integer PythonQtConverter::ToModelicaInteger(const pybind11::object& obj) {
    try {
        // 尝试直接转换为整数
        if (pybind11::isinstance<pybind11::int_>(obj)) {
            return obj.cast<long long>();
        }
        // 尝试转换为字符串然后解析
        std::string str = pybind11::str(obj);
        QString qstr = QString::fromStdString(str);
        return ToModelicaInteger(qstr);
    } catch (const std::exception& e) {
        qWarning() << "Failed to convert pybind11::object to modelica_integer:" << e.what();
        return 0;
    }
}

modelica_real PythonQtConverter::ToModelicaReal(const pybind11::object& obj) {
    try {
        // 尝试直接转换为浮点数
        if (pybind11::isinstance<pybind11::float_>(obj)) {
            return obj.cast<double>();
        }
        // 尝试转换为整数然后转为浮点数
        if (pybind11::isinstance<pybind11::int_>(obj)) {
            return static_cast<double>(obj.cast<long long>());
        }
        // 尝试转换为字符串然后解析
        std::string str = pybind11::str(obj);
        QString qstr = QString::fromStdString(str);
        return ToModelicaReal(qstr);
    } catch (const std::exception& e) {
        qWarning() << "Failed to convert pybind11::object to modelica_real:" << e.what();
        return 0.0;
    }
}

QList<modelica_boolean> PythonQtConverter::ToQListModelicaBoolean(const QString& data) {
    QList<modelica_boolean> result;
    QList<QString> stringList = ToQListQString(data);

    for (const QString& str : stringList) {
        result.append(ToModelicaBoolean(str));
    }

    return result;
}

QList<modelica_boolean> PythonQtConverter::ToQListModelicaBoolean(const pybind11::object& obj) {
    try {
        // Try to convert directly to QList<modelica_boolean>
        return obj.cast<QList<modelica_boolean>>();
    } catch (const pybind11::cast_error&) {
        // If direct conversion fails, try to convert to string first
        try {
            QString str = ToQString(obj);
            return ToQListModelicaBoolean(str);
        } catch (const std::exception& e) {
            qDebug() << "Error converting pybind11::object to QList<modelica_boolean>:" << e.what();
            return QList<modelica_boolean>();
        }
    }
}

QList<modelica_integer> PythonQtConverter::ToQListModelicaInteger(const QString& data) {
    QList<modelica_integer> result;
    QList<QString> stringList = ToQListQString(data);

    for (const QString& str : stringList) {
        result.append(ToModelicaInteger(str));
    }

    return result;
}

QList<modelica_integer> PythonQtConverter::ToQListModelicaInteger(const pybind11::object& obj) {
    try {
        // 尝试直接转换为QList<modelica_integer>
        if (pybind11::isinstance<pybind11::list>(obj)) {
            QList<modelica_integer> result;
            pybind11::list py_list = obj.cast<pybind11::list>();
            for (auto item : py_list) {
                result.append(ToModelicaInteger(pybind11::reinterpret_borrow<pybind11::object>(item)));
            }
            return result;
        }
        
        // 如果不是列表，尝试转换为字符串后调用原函数
        QString str = QString::fromStdString(obj.cast<std::string>());
        return ToQListModelicaInteger(str);
    } catch (const std::exception& e) {
        qDebug() << "Error converting pybind11::object to QList<modelica_integer>:" << e.what();
        return QList<modelica_integer>();
    }
}

QList<modelica_real> PythonQtConverter::ToQListModelicaReal(const QString& data) {
    QList<modelica_real> result;
    QString cleanData = data.trimmed();

    // 移除外层的大括号或方括号
    if ((cleanData.startsWith('{') && cleanData.endsWith('}')) ||
        (cleanData.startsWith('[') && cleanData.endsWith(']'))) {
        cleanData = cleanData.mid(1, cleanData.length() - 2);
    }

    if (cleanData.isEmpty()) {
        return result;
    }

    QStringList parts = splitAtTopLevel(cleanData, ',');
    for (const QString& part : parts) {
        result.append(ToModelicaReal(part.trimmed()));
    }

    return result;
}

QList<QList<modelica_real>> PythonQtConverter::ToQListQListModelicaReal(const QString& data) {
    QList<QList<modelica_real>> result;
    QList<QList<QString>> stringListList = ToQListQListQString(data);

    for (const QList<QString>& stringList : stringListList) {
        QList<modelica_real> realList;
        for (const QString& str : stringList) {
            realList.append(ToModelicaReal(str));
        }
        result.append(realList);
    }

    return result;
}

// 结构体转换方法实现
OMCInterface::getConversionsFromVersions_res PythonQtConverter::ToGetConversionsFromVersions_res(const QString& data) {
    OMCInterface::getConversionsFromVersions_res result;

    // 解析格式: ({list1},{list2})
    QString trimmed = data.trimmed();
    if (trimmed.startsWith('(') && trimmed.endsWith(')')) {
        trimmed = trimmed.mid(1, trimmed.length() - 2);
    }

    // 找到两个列表的分界点
    int braceLevel = 0;
    int commaPos = -1;

    for (int i = 0; i < trimmed.length(); ++i) {
        QChar ch = trimmed[i];
        if (ch == '{') {
            braceLevel++;
        } else if (ch == '}') {
            braceLevel--;
        } else if (ch == ',' && braceLevel == 0) {
            commaPos = i;
            break;
        }
    }

    if (commaPos != -1) {
        QString firstList = trimmed.left(commaPos).trimmed();
        QString secondList = trimmed.mid(commaPos + 1).trimmed();

        result.withoutConversion = ToQListQString(firstList);
        result.withConversion = ToQListQString(secondList);
    }

    return result;
}

OMCInterface::generateScriptingAPI_res PythonQtConverter::ToGenerateScriptingAPI_res(const QString& data) {
    OMCInterface::generateScriptingAPI_res result;

    // 解析格式: (success,"moFile","qtFile","qtHeader")
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 4) {
        result.success = ToModelicaBoolean(parts[0]);
        result.moFile = ToQString(parts[1]);
        result.qtFile = ToQString(parts[2]);
        result.qtHeader = ToQString(parts[3]);
    }

    return result;
}

OMCInterface::getClassInformation_res PythonQtConverter::ToGetClassInformation_res(const QString& data) {
    OMCInterface::getClassInformation_res result;

    QStringList elements = ParseTupleString(data);
    if (elements.size() >= 17) {
        result.restriction = ToQString(elements[0]);
        result.comment = ToQString(elements[1]);
        result.partialPrefix = ToModelicaBoolean(elements[2]);
        result.finalPrefix = ToModelicaBoolean(elements[3]);
        result.encapsulatedPrefix = ToModelicaBoolean(elements[4]);
        result.fileName = ToQString(elements[5]);
        result.fileReadOnly = ToModelicaBoolean(elements[6]);
        result.lineNumberStart = ToModelicaInteger(elements[7]);
        result.columnNumberStart = ToModelicaInteger(elements[8]);
        result.lineNumberEnd = ToModelicaInteger(elements[9]);
        result.columnNumberEnd = ToModelicaInteger(elements[10]);
        result.dimensions = ToQListQString(elements[11]);
        result.isProtectedClass = ToModelicaBoolean(elements[12]);
        result.isDocumentationClass = ToModelicaBoolean(elements[13]);
        result.version = ToQString(elements[14]);
        result.preferredView = ToQString(elements[15]);
        result.state = ToModelicaBoolean(elements[16]);
        if (elements.size() >= 21) {
            result.access = ToQString(elements[17]);
            result.versionDate = ToQString(elements[18]);
            result.versionBuild = ToQString(elements[19]);
            result.dateModified = ToQString(elements[20]);
            if (elements.size() >= 22) {
                result.revisionId = ToQString(elements[21]);
            }
        }
    }

    return result;
}

// 工具方法实现
QStringList PythonQtConverter::ParseTupleString(const QString& data) {
    QStringList result;
    QString trimmed = data.trimmed();

    // 移除外层括号
    if (trimmed.startsWith('(') && trimmed.endsWith(')')) {
        trimmed = trimmed.mid(1, trimmed.length() - 2);
    }

    if (trimmed.isEmpty()) {
        return result;
    }

    // 解析元组中的元素，考虑嵌套结构
    int level = 0;
    QString current;
    bool inQuotes = false;

    for (int i = 0; i < trimmed.length(); ++i) {
        QChar ch = trimmed[i];

        if (ch == '"' && (i == 0 || trimmed[i-1] != '\\')) {
            inQuotes = !inQuotes;
            current.append(ch);
        } else if (!inQuotes) {
            if (ch == '(' || ch == '{' || ch == '[') {
                level++;
                current.append(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                level--;
                current.append(ch);
            } else if (ch == ',' && level == 0) {
                result.append(current.trimmed());
                current.clear();
            } else {
                current.append(ch);
            }
        } else {
            current.append(ch);
        }
    }

    if (!current.isEmpty()) {
        result.append(current.trimmed());
    }

    return result;
}

QString PythonQtConverter::UnescapeString(const QString& str) {
    QString result = str;
    result.replace("\\\"", "\"");
    result.replace("\\\\", "\\");
    result.replace("\\n", "\n");
    result.replace("\\t", "\t");
    result.replace("\\r", "\r");
    return result;
}

// 添加更多结构体转换方法
OMCInterface::oms_loadSnapshot_res PythonQtConverter::ToOms_loadSnapshot_res(const QString& data) {
    OMCInterface::oms_loadSnapshot_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.newCref = ToQString(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_listUnconnectedConnectors_res PythonQtConverter::ToOms_listUnconnectedConnectors_res(const QString& data) {
    OMCInterface::oms_listUnconnectedConnectors_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.contents = ToQString(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_list_res PythonQtConverter::ToOms_list_res(const QString& data) {
    OMCInterface::oms_list_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.contents = ToQString(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_importFile_res PythonQtConverter::ToOms_importFile_res(const QString& data) {
    OMCInterface::oms_importFile_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.cref = ToQString(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_getVariableStepSize_res PythonQtConverter::ToOms_getVariableStepSize_res(const QString& data) {
    OMCInterface::oms_getVariableStepSize_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 4) {
        result.initialStepSize = ToModelicaReal(parts[0]);
        result.minimumStepSize = ToModelicaReal(parts[1]);
        result.maximumStepSize = ToModelicaReal(parts[2]);
        result.status = ToModelicaInteger(parts[3]);
    }

    return result;
}

OMCInterface::oms_getTolerance_res PythonQtConverter::ToOms_getTolerance_res(const QString& data) {
    OMCInterface::oms_getTolerance_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 3) {
        result.absoluteTolerance = ToModelicaReal(parts[0]);
        result.relativeTolerance = ToModelicaReal(parts[1]);
        result.status = ToModelicaInteger(parts[2]);
    }

    return result;
}

OMCInterface::oms_getSystemType_res PythonQtConverter::ToOms_getSystemType_res(const QString& data) {
    OMCInterface::oms_getSystemType_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.type_ = ToModelicaInteger(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_getSubModelPath_res PythonQtConverter::ToOms_getSubModelPath_res(const QString& data) {
    OMCInterface::oms_getSubModelPath_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.path = ToQString(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_getStopTime_res PythonQtConverter::ToOms_getStopTime_res(const QString& data) {
    OMCInterface::oms_getStopTime_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.stopTime = ToModelicaReal(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_getStartTime_res PythonQtConverter::ToOms_getStartTime_res(const QString& data) {
    OMCInterface::oms_getStartTime_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.startTime = ToModelicaReal(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_getSolver_res PythonQtConverter::ToOms_getSolver_res(const QString& data) {
    OMCInterface::oms_getSolver_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.solver = ToModelicaInteger(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_getReal_res PythonQtConverter::ToOms_getReal_res(const QString& data) {
    OMCInterface::oms_getReal_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.value = ToModelicaReal(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_getModelState_res PythonQtConverter::ToOms_getModelState_res(const QString& data) {
    OMCInterface::oms_getModelState_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.modelState = ToModelicaInteger(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_getFixedStepSize_res PythonQtConverter::ToOms_getFixedStepSize_res(const QString& data) {
    OMCInterface::oms_getFixedStepSize_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.stepSize = ToModelicaReal(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_getBoolean_res PythonQtConverter::ToOms_getBoolean_res(const QString& data) {
    OMCInterface::oms_getBoolean_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.value = ToModelicaBoolean(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_extractFMIKind_res PythonQtConverter::ToOms_extractFMIKind_res(const QString& data) {
    OMCInterface::oms_extractFMIKind_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.kind = ToModelicaInteger(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::oms_exportSnapshot_res PythonQtConverter::ToOms_exportSnapshot_res(const QString& data) {
    OMCInterface::oms_exportSnapshot_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.contents = ToQString(parts[0]);
        result.status = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::getSimulationOptions_res PythonQtConverter::ToGetSimulationOptions_res(const QString& data) {
    OMCInterface::getSimulationOptions_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 5) {
        result.startTime = ToModelicaReal(parts[0]);
        result.stopTime = ToModelicaReal(parts[1]);
        result.tolerance = ToModelicaReal(parts[2]);
        result.numberOfIntervals = ToModelicaInteger(parts[3]);
        result.interval = ToModelicaReal(parts[4]);
    }

    return result;
}

OMCInterface::getTimeStamp_res PythonQtConverter::ToGetTimeStamp_res(const QString& data) {
    OMCInterface::getTimeStamp_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.timeStamp = ToModelicaReal(parts[0]);
        result.timeStampAsString = ToQString(parts[1]);
    }

    return result;
}

OMCInterface::getImportedNames_res PythonQtConverter::ToGetImportedNames_res(const QString& data) {
    OMCInterface::getImportedNames_res result;
    QList<QString> parts = ParseTupleString(data);
    if (parts.size() >= 2) {
        result.out_public = ToQListQString(parts[0]);
        result.out_protected = ToQListQString(parts[1]);
    }
    return result;
}

OMCInterface::diffSimulationResults_res PythonQtConverter::ToDiffSimulationResults_res(const QString& data) {
    OMCInterface::diffSimulationResults_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.success = ToModelicaBoolean(parts[0]);
        result.failVars = ToQListQString(parts[1]);
    }

    return result;
}

OMCInterface::solveLinearSystem_res PythonQtConverter::ToSolveLinearSystem_res(const QString& data) {
    OMCInterface::solveLinearSystem_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.X = ToQListModelicaReal(parts[0]);
        result.info = ToModelicaInteger(parts[1]);
    }

    return result;
}

OMCInterface::convertUnits_res PythonQtConverter::ToConvertUnits_res(const QString& data) {
    OMCInterface::convertUnits_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 3) {
        result.unitsCompatible = ToModelicaBoolean(parts[0]);
        result.scaleFactor = ToModelicaReal(parts[1]);
        result.offset = ToModelicaReal(parts[2]);
    }

    return result;
}

OMCInterface::dumpXMLDAE_res PythonQtConverter::ToDumpXMLDAE_res(const QString& data) {
    OMCInterface::dumpXMLDAE_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.success = ToModelicaBoolean(parts[0]);
        result.xmlfileName = ToQString(parts[1]);
    }

    return result;
}

OMCInterface::countMessages_res PythonQtConverter::ToCountMessages_res(const QString& data) {
    OMCInterface::countMessages_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 3) {
        result.numMessages = ToModelicaInteger(parts[0]);
        result.numErrors = ToModelicaInteger(parts[1]);
        result.numWarnings = ToModelicaInteger(parts[2]);
    }

    return result;
}

OMCInterface::stat_res PythonQtConverter::ToStat_res(const QString& data) {
    OMCInterface::stat_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 3) {
        result.success = ToModelicaBoolean(parts[0]);
        result.fileSize = ToModelicaReal(parts[1]);
        result.mtime = ToModelicaReal(parts[2]);
    }

    return result;
}

OMCInterface::getConfigFlagValidOptions_res PythonQtConverter::ToGetConfigFlagValidOptions_res(const QString& data) {
    OMCInterface::getConfigFlagValidOptions_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 3) {
        result.validOptions = ToQListQString(parts[0]);
        result.mainDescription = ToQString(parts[1]);
        result.descriptions = ToQListQString(parts[2]);
    }

    return result;
}

OMCInterface::getAvailableTearingMethods_res PythonQtConverter::ToGetAvailableTearingMethods_res(const QString& data) {
    OMCInterface::getAvailableTearingMethods_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.allChoices = ToQListQString(parts[0]);
        result.allComments = ToQListQString(parts[1]);
    }

    return result;
}

OMCInterface::getAvailableIndexReductionMethods_res PythonQtConverter::ToGetAvailableIndexReductionMethods_res(const QString& data) {
    OMCInterface::getAvailableIndexReductionMethods_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.allChoices = ToQListQString(parts[0]);
        result.allComments = ToQListQString(parts[1]);
    }

    return result;
}

OMCInterface::getAvailableMatchingAlgorithms_res PythonQtConverter::ToGetAvailableMatchingAlgorithms_res(const QString& data) {
    OMCInterface::getAvailableMatchingAlgorithms_res result;
    QStringList parts = ParseTupleString(data);

    if (parts.size() >= 2) {
        result.allChoices = ToQListQString(parts[0]);
        result.allComments = ToQListQString(parts[1]);
    }

    return result;
}
