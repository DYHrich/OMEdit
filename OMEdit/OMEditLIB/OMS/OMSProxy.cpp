/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE
 * OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3, ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */
/*
 * @author Adeel Asghar <adeel.asghar@liu.se>
 */

#include "OMSProxy.h"
#include <iostream>
#include "Util/Helper.h"
#include "MainWindow.h"
#include "Util/Utilities.h"

#include <QTime>

#define LOG_COMMAND(command,args) \
  QElapsedTimer commandTime; \
  commandTime.start(); \
  command = QString("%1(%2)").arg(command, args.join(",")); \
  logCommand(command);

/*!
 * \brief loggingCallback
 * Callback function to handle the OMSimulator logging.
 * \param type
 * \param message
 */
void loggingCallback(oms_message_type_enu_t type, const char *message) {
    std::cout << "void loggingCallback(oms_message_type_enu_t type, const char *message)" << std::endl;
}

/*!
 * \class OMSProxy
 * \brief Interface for call OMSimulator API.
 */

OMSProxy *OMSProxy::mpInstance = 0;

/*!
 * \brief OMSProxy::create
 */
void OMSProxy::create() {
    std::cout << "void OMSProxy::create()" << std::endl;
}

/*!
 * \brief OMSProxy::destroy
 */
void OMSProxy::destroy() {
    std::cout << "void OMSProxy::destroy()" << std::endl;
}

/*!
 * \brief OMSProxy::OMSProxy
 */
OMSProxy::OMSProxy()
{
  /* create a file to write OMSimulator communication log */
  QString communicationLogFilePath = QString("%1omscommunication.log").arg(Utilities::tempDirectory());
#ifdef Q_OS_WIN
  mpCommunicationLogFile = _wfopen((wchar_t*)communicationLogFilePath.utf16(), L"w");
#else
  mpCommunicationLogFile = fopen(communicationLogFilePath.toUtf8().constData(), "w");
#endif
  mTotalOMSCallsTime = 0.0;
  // OMSimulator global settings
  //setCommandLineOption("--suppressPath=true");
  setLogFile(QString(Utilities::tempDirectory() + "/omslog.txt"));
  setTempDirectory(Utilities::tempDirectory());
  setLoggingCallback();
  qRegisterMetaType<MessageItem>("MessageItem");
  connect(this, SIGNAL(logGUIMessage(MessageItem)), MessagesWidget::instance(), SLOT(addGUIMessage(MessageItem)));
}

OMSProxy::~OMSProxy()
{
  if (mpCommunicationLogFile) {
    fclose(mpCommunicationLogFile);
  }
}

/*!
 * \brief OMSProxy::logCommand
 * Writes the command to the omscommunication.log file.
 * \param command - the command to write
 */
void OMSProxy::logCommand(QString command) {
    std::cout << "void OMSProxy::logCommand(QString command)" << std::endl;
}

/*!
 * \brief OMSProxy::logResponse
 * Writes the response to the omscommunication.log file.
 * \param response - the response to write
 * \param status - execution status of the command
 * \param responseTime - the response end time
 */
void OMSProxy::logResponse(QString command, oms_status_enu_t status, QElapsedTimer *responseTime) {
    std::cout << "void OMSProxy::logResponse(QString command, oms_status_enu_t status, QElapsedTimer *responseTime)" << std::endl;
}

/*!
 * \brief OMSProxy::getSystemTypeString
 * Returns the oms_system_enu_t as string.
 * \param type
 * \return
 */
QString OMSProxy::getSystemTypeString(oms_system_enu_t type) {
    std::cout << "QString OMSProxy::getSystemTypeString(oms_system_enu_t type)" << std::endl;
    return QString();
}

/*!
 * \brief OMSProxy::getSystemTypeShortString
 * Returns the oms_system_enu_t as short string.
 * \param type
 * \return
 */
QString OMSProxy::getSystemTypeShortString(oms_system_enu_t type) {
    std::cout << "QString OMSProxy::getSystemTypeShortString(oms_system_enu_t type)" << std::endl;
    return QString();
}

/*!
 * \brief OMSProxy::getFMUKindString
 * Returns the oms_fmi_kind_enu_t as string.
 * \param kind
 * \return
 */
QString OMSProxy::getFMUKindString(oms_fmi_kind_enu_t kind) {
    std::cout << "QString OMSProxy::getFMUKindString(oms_fmi_kind_enu_t kind)" << std::endl;
    return QString();
}

/*!
 * \brief OMSProxy::getSignalTypeString
 * Returns the oms_signal_type_integer as string.
 * \param type
 * \return
 */
QString OMSProxy::getSignalTypeString(oms_signal_type_enu_t type) {
    std::cout << "QString OMSProxy::getSignalTypeString(oms_signal_type_enu_t type)" << std::endl;
    return QString();
}

/*!
 * \brief OMSProxy::getCausalityString
 * Returns the oms_causality_enu_t as string.
 * \param causality
 * \return
 */
QString OMSProxy::getCausalityString(oms_causality_enu_t causality) {
    std::cout << "QString OMSProxy::getCausalityString(oms_causality_enu_t causality)" << std::endl;
    return QString();
}

/*!
 * \brief OMSProxy::statusToBool
 * Converts the oms_status_enu_t to bool.
 * \param status
 * \return
 */
bool OMSProxy::statusToBool(oms_status_enu_t status) {
    std::cout << "bool OMSProxy::statusToBool(oms_status_enu_t status)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::addBus
 * Adds a bus.
 * \param cref
 * \return
 */
bool OMSProxy::addBus(QString cref) {
    std::cout << "bool OMSProxy::addBus(QString cref)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::addConnection
 * Adds the connection
 * \param crefA
 * \param crefB
 * \return
 */
bool OMSProxy::addConnection(QString crefA, QString crefB, bool suppressUnitConversion) {
    std::cout << "bool OMSProxy::addConnection(QString crefA, QString crefB, bool suppressUnitConversion)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::addConnector
 * Adds the connector.
 * \param cref
 * \param causality
 * \param type
 * \return
 */
bool OMSProxy::addConnector(QString cref, oms_causality_enu_t causality, oms_signal_type_enu_t type) {
    std::cout << "bool OMSProxy::addConnector(QString cref, oms_causality_enu_t causality, oms_signal_type_enu_t type)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::addConnectorToBus
 * Adds a connector to a bus.
 * \param busCref
 * \param connectorCref
 * \return
 */
bool OMSProxy::addConnectorToBus(QString busCref, QString connectorCref) {
    std::cout << "bool OMSProxy::addConnectorToBus(QString busCref, QString connectorCref)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::addSubModel
 * Adds the submodel to the system
 * \param busCref
 * \param connectorCref
 * \param type
 * \return
 */
bool OMSProxy::addSubModel(QString cref, QString fmuPath) {
    std::cout << "bool OMSProxy::addSubModel(QString cref, QString fmuPath)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::replaceSubModel
 * \Adds the submodel to the system
 * \param cref
 * \param fmupath
 * \param dryCount
 * \param count
 * \return
 */
bool OMSProxy::replaceSubModel(QString cref, QString fmuPath, bool dryCount, int *count) {
    std::cout << "bool OMSProxy::replaceSubModel(QString cref, QString fmuPath, bool dryCount, int *count)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::createElementGeometryUsingPosition
 * Creates the element geometry using position.
 * \param cref
 * \param position
 */
void OMSProxy::createElementGeometryUsingPosition(const QString &cref, QPointF position) {
    std::cout << "void OMSProxy::createElementGeometryUsingPosition(const QString &cref, QPointF position)" << std::endl;
}

/*!
 * \brief OMSProxy::addSystem
 * Adds a system to a model.
 * \param cref
 * \param type
 * \return
 */
bool OMSProxy::addSystem(QString cref, oms_system_enu_t type) {
    std::cout << "bool OMSProxy::addSystem(QString cref, oms_system_enu_t type)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::deleteConnection
 * Deletes the connection
 * \param crefA
 * \param crefB
 * \return
 */
bool OMSProxy::deleteConnection(QString crefA, QString crefB) {
    std::cout << "bool OMSProxy::deleteConnection(QString crefA, QString crefB)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::deleteConnectorFromBus
 * Deletes a connector from a bus.
 * \param busCref
 * \param connectorCref
 * \return
 */
bool OMSProxy::deleteConnectorFromBus(QString busCref, QString connectorCref) {
    std::cout << "bool OMSProxy::deleteConnectorFromBus(QString busCref, QString connectorCref)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getBoolean
 * Gets the boolean variable value.
 * \param cref
 * \param value
 * \return
 */
bool OMSProxy::getBoolean(QString cref, bool *value) {
    std::cout << "bool OMSProxy::getBoolean(QString cref, bool *value)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getBus
 * Gets the bus.
 * \param cref
 * \param pBusConnector
 * \return
 */
bool OMSProxy::getBus(QString cref, oms_busconnector_t **pBusConnector) {
    std::cout << "bool OMSProxy::getBus(QString cref, oms_busconnector_t **pBusConnector)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getComponentType
 * Get the component type.
 * \param cref
 * \param pType
 * \return
 */
bool OMSProxy::getComponentType(QString cref, oms_component_enu_t *pType) {
    std::cout << "bool OMSProxy::getComponentType(QString cref, oms_component_enu_t *pType)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getConnections
 * Get the model connections
 * \param cref
 * \param pConnections
 * \return
 */
bool OMSProxy::getConnections(QString cref, oms_connection_t*** pConnections) {
    std::cout << "bool OMSProxy::getConnections(QString cref, oms_connection_t*** pConnections)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getConnector
 * Gets the connector.
 * \param cref
 * \param pConnector
 * \return
 */
bool OMSProxy::getConnector(QString cref, oms_connector_t **pConnector) {
    std::cout << "bool OMSProxy::getConnector(QString cref, oms_connector_t **pConnector)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getElement
 * Gets the model element
 * \param cref
 * \param pElement
 * \return
 */
bool OMSProxy::getElement(QString cref, oms_element_t** pElement) {
    std::cout << "bool OMSProxy::getElement(QString cref, oms_element_t** pElement)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getElements
 * Get the model elements
 * \param cref
 * \param pElements
 * \return
 */
bool OMSProxy::getElements(QString cref, oms_element_t*** pElements) {
    std::cout << "bool OMSProxy::getElements(QString cref, oms_element_t*** pElements)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getFixedStepSize
 * Gets the fixed step size.
 * \param cref
 * \param stepSize
 * \return
 */
bool OMSProxy::getFixedStepSize(QString cref, double *stepSize) {
    std::cout << "bool OMSProxy::getFixedStepSize(QString cref, double *stepSize)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getFMUInfo
 * Gets the FMU info.
 * \param cref
 * \param pFmuInfo
 * \return
 */
bool OMSProxy::getFMUInfo(QString cref, const oms_fmu_info_t** pFmuInfo) {
    std::cout << "bool OMSProxy::getFMUInfo(QString cref, const oms_fmu_info_t** pFmuInfo)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getInteger
 * Gets the integer variable value.
 * \param cref
 * \param value
 * \return
 */
bool OMSProxy::getInteger(QString cref, int *value) {
    std::cout << "bool OMSProxy::getInteger(QString cref, int *value)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getModelState
 * Gets the model state.
 * \param cref
 * \param modelState
 * \return
 */
bool OMSProxy::getModelState(const QString &cref, oms_modelState_enu_t *modelState) {
    std::cout << "bool OMSProxy::getModelState(const QString &cref, oms_modelState_enu_t *modelState)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getReal
 * Gets the real variable value.
 * \param cref
 * \param value
 * \return
 */
bool OMSProxy::getReal(QString cref, double *value) {
    std::cout << "bool OMSProxy::getReal(QString cref, double *value)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getSolver
 * Gets the solver.
 * \param cref
 * \param solver
 * \return
 */
bool OMSProxy::getSolver(QString cref, oms_solver_enu_t *solver) {
    std::cout << "bool OMSProxy::getSolver(QString cref, oms_solver_enu_t *solver)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setStartTime
 * Get the start time from the model.
 * \param cref
 * \param startTime
 * \return
 */
bool OMSProxy::getStartTime(QString cref, double* startTime) {
    std::cout << "bool OMSProxy::getStartTime(QString cref, double* startTime)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setStopTime
 * Get the stop time from the model.
 * \param cref
 * \param stopTime
 * \return
 */
bool OMSProxy::getStopTime(QString cref, double* stopTime) {
    std::cout << "bool OMSProxy::getStopTime(QString cref, double* stopTime)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getFMUPath
 * Returns the submodel path.
 * \param cref
 * \param pPath
 * \return
 */
bool OMSProxy::getSubModelPath(QString cref, QString* pPath) {
    std::cout << "bool OMSProxy::getSubModelPath(QString cref, QString* pPath)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getSystemType
 * Get the system type.
 * \param cref
 * \param pType
 * \return
 */
bool OMSProxy::getSystemType(QString cref, oms_system_enu_t *pType) {
    std::cout << "bool OMSProxy::getSystemType(QString cref, oms_system_enu_t *pType)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getTolerance
 * Gets the tolerance.
 * \param cref
 * \param absoluteTolerance
 * \param relativeTolerance
 * \return
 */
bool OMSProxy::getTolerance(QString cref, double *absoluteTolerance, double *relativeTolerance) {
    std::cout << "bool OMSProxy::getTolerance(QString cref, double *absoluteTolerance, double *relativeTolerance)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::getVariableStepSize
 * Gets the variable step size.
 * \param cref
 * \param initialStepSize
 * \param minimumStepSize
 * \param maximumStepSize
 * \return
 */
bool OMSProxy::getVariableStepSize(QString cref, double *initialStepSize, double *minimumStepSize, double *maximumStepSize) {
    std::cout << "bool OMSProxy::getVariableStepSize(QString cref, double *initialStepSize, double *minimumStepSize, double *maximumStepSize)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::instantiate
 * Instantiates the model and enter the instantiated state.
 * \param cref
 * \return
 */
bool OMSProxy::instantiate(QString cref) {
    std::cout << "bool OMSProxy::instantiate(QString cref)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::initialize
 * Initializes a model.
 * \param cref
 * \return
 */
bool OMSProxy::initialize(QString cref) {
    std::cout << "bool OMSProxy::initialize(QString cref)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::exportSnapshot
 * Lists the contents of a model.
 * Since memory is allocated so we need to call free.
 * \param cref
 * \param pContents
 * \return
 */
bool OMSProxy::exportSnapshot(QString cref, QString *pContents) {
    std::cout << "bool OMSProxy::exportSnapshot(QString cref, QString *pContents)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::loadModel
 * Loads the model.
 * \param filename
 * \param pModelName
 * \return
 */
bool OMSProxy::loadModel(QString filename, QString* pModelName) {
    std::cout << "bool OMSProxy::loadModel(QString filename, QString* pModelName)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::importSnapshot
 * Loads the snapshot of the model.
 * \param cref
 * \param snapshot
 * \param pNewCref
 * \return
 */
bool OMSProxy::importSnapshot(QString cref, QString snapshot, QString* pNewCref) {
    std::cout << "bool OMSProxy::importSnapshot(QString cref, QString snapshot, QString* pNewCref)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::newModel
 * \param cref
 * \return
 */
bool OMSProxy::newModel(QString cref) {
    std::cout << "bool OMSProxy::newModel(QString cref)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::rename
 * Renames the OMSimulator model/elements.
 * \param cref
 * \param newCref
 * \return
 */
bool OMSProxy::rename(const QString &cref, const QString &newCref) {
    std::cout << "bool OMSProxy::rename(const QString &cref, const QString &newCref)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::omsDelete
 * \param cref
 * \return
 */
bool OMSProxy::omsDelete(QString cref) {
    std::cout << "bool OMSProxy::omsDelete(QString cref)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::saveModel
 * Saves the model.
 * \param cref
 * \param filename
 * \return
 */
bool OMSProxy::saveModel(QString cref, QString filename) {
    std::cout << "bool OMSProxy::saveModel(QString cref, QString filename)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setBoolean
 * Sets the boolean variable value.
 * \param cref
 * \param value
 * \return
 */
bool OMSProxy::setBoolean(QString cref, bool value) {
    std::cout << "bool OMSProxy::setBoolean(QString cref, bool value)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setBusGeometry
 * Sets the bus geometry.
 * \param cref
 * \param pGeometry
 * \return
 */
bool OMSProxy::setBusGeometry(QString cref, const ssd_connector_geometry_t* pGeometry) {
    std::cout << "bool OMSProxy::setBusGeometry(QString cref, const ssd_connector_geometry_t* pGeometry)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setCommandLineOption
 * Sets the command line option.
 * \param cmd
 * \return
 */
bool OMSProxy::setCommandLineOption(QString cmd) {
    std::cout << "bool OMSProxy::setCommandLineOption(QString cmd)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setConnectionGeometry
 * Sets the connection geometry.
 * \param crefA
 * \param crefB
 * \param pGeometry
 * \return
 */
bool OMSProxy::setConnectionGeometry(QString crefA, QString crefB, const ssd_connection_geometry_t *pGeometry) {
    std::cout << "bool OMSProxy::setConnectionGeometry(QString crefA, QString crefB, const ssd_connection_geometry_t *pGeometry)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setConnectorGeometry
 * Sets the connector geometry.
 * \param cref
 * \param pGeometry
 * \return
 */
bool OMSProxy::setConnectorGeometry(QString cref, const ssd_connector_geometry_t* pGeometry) {
    std::cout << "bool OMSProxy::setConnectorGeometry(QString cref, const ssd_connector_geometry_t* pGeometry)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setElementGeometry
 * Sets the element geometry
 * \param cref
 * \param pGeometry
 * \return
 */
bool OMSProxy::setElementGeometry(QString cref, const ssd_element_geometry_t* pGeometry) {
    std::cout << "bool OMSProxy::setElementGeometry(QString cref, const ssd_element_geometry_t* pGeometry)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setCommunicationInterval
 * Set the fixed step size for the simulation.
 * \param cref
 * \param stepSize
 * \return
 */
bool OMSProxy::setFixedStepSize(QString cref, double stepSize) {
    std::cout << "bool OMSProxy::setFixedStepSize(QString cref, double stepSize)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setLogFile
 * Sets the log file.
 * \param filename
 */
void OMSProxy::setLogFile(QString filename) {
    std::cout << "void OMSProxy::setLogFile(QString filename)" << std::endl;
}

/*!
 * \brief OMSProxy::setLoggingCallback
 * Sets the logging callback.
 */
void OMSProxy::setLoggingCallback() {
    std::cout << "void OMSProxy::setLoggingCallback()" << std::endl;
}

/*!
 * \brief OMSProxy::setLoggingInterval
 * Sets the logging interval.
 * \param cref
 * \param loggingInterval
 * \return
 */
bool OMSProxy::setLoggingInterval(QString cref, double loggingInterval) {
    std::cout << "bool OMSProxy::setLoggingInterval(QString cref, double loggingInterval)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setDebugLogging
 * Sets the logging level.
 * \param logLevel
 */
void OMSProxy::setLoggingLevel(int logLevel) {
    std::cout << "void OMSProxy::setLoggingLevel(int logLevel)" << std::endl;
}

/*!
 * \brief OMSProxy::setInteger
 * Sets the integer variable value.
 * \param cref
 * \param value
 * \return
 */
bool OMSProxy::setInteger(QString cref, int value) {
    std::cout << "bool OMSProxy::setInteger(QString cref, int value)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setReal
 * Sets the real variable value.
 * \param cref
 * \param value
 * \return
 */
bool OMSProxy::setReal(QString cref, double value) {
    std::cout << "bool OMSProxy::setReal(QString cref, double value)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setResultFile
 * Set the result file for the simulation.
 * \param cref
 * \param filename
 * \param bufferSize
 * \return
 */
bool OMSProxy::setResultFile(QString cref, QString filename, int bufferSize) {
    std::cout << "bool OMSProxy::setResultFile(QString cref, QString filename, int bufferSize)" << std::endl;
    return false;
}

bool OMSProxy::getResultFile(QString cref, char **pFilename, int *pBufferSize) {
    std::cout << "bool OMSProxy::getResultFile(QString cref, char **pFilename, int *pBufferSize)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setSolver
 * Sets the solver.
 * \param cref
 * \param solver
 * \return
 */
bool OMSProxy::setSolver(QString cref, oms_solver_enu_t solver) {
    std::cout << "bool OMSProxy::setSolver(QString cref, oms_solver_enu_t solver)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setStartTime
 * Set the start time of the simulation.
 * \param cref
 * \param startTime
 * \return
 */
bool OMSProxy::setStartTime(QString cref, double startTime) {
    std::cout << "bool OMSProxy::setStartTime(QString cref, double startTime)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setStopTime
 * Set the stop time of the simulation.
 * \param cref
 * \param stopTime
 * \return
 */
bool OMSProxy::setStopTime(QString cref, double stopTime) {
    std::cout << "bool OMSProxy::setStopTime(QString cref, double stopTime)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setTempDirectory
 * Sets the temp directory.
 * \param path
 */
void OMSProxy::setTempDirectory(QString path) {
    std::cout << "void OMSProxy::setTempDirectory(QString path)" << std::endl;
}

/*!
 * \brief OMSProxy::setTolerance
 * Sets the tolerance.
 * \param cref
 * \param tolerance
 * \return
 */
bool OMSProxy::setTolerance(QString cref, double absoluteTolerance, double relativeTolerance) {
    std::cout << "bool OMSProxy::setTolerance(QString cref, double absoluteTolerance, double relativeTolerance)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setVariableStepSize
 * Sets the variable step size.
 * \param cref
 * \param initialStepSize
 * \param minimumStepSize
 * \param maximumStepSize
 * \return
 */
bool OMSProxy::setVariableStepSize(QString cref, double initialStepSize, double minimumStepSize, double maximumStepSize) {
    std::cout << "bool OMSProxy::setVariableStepSize(QString cref, double initialStepSize, double minimumStepSize, double maximumStepSize)" << std::endl;
    return false;
}

/*!
 * \brief OMSProxy::setWorkingDirectory
 * Sets the working directory.
 * \param path
 */
void OMSProxy::setWorkingDirectory(QString path) {
    std::cout << "void OMSProxy::setWorkingDirectory(QString path)" << std::endl;
}

/*!
 * \brief OMSProxy::terminate
 * Terminates the model.
 * \param cref
 * \return
 */
bool OMSProxy::terminate(QString cref) {
    std::cout << "bool OMSProxy::terminate(QString cref)" << std::endl;
    return false;
}
