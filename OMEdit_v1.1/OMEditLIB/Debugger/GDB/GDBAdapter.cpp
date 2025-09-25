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

#include "Debugger/GDB/GDBAdapter.h"
#include <iostream>
#include "MainWindow.h"
#include "Modeling/LibraryTreeWidget.h"
#include "Options/OptionsDialog.h"
#include "Debugger/StackFrames/StackFramesWidget.h"
#include "Debugger/Locals/LocalsWidget.h"
#include "Debugger/GDB/CommandFactory.h"
#include "Debugger/Locals/ModelicaValue.h"
#include "Simulation/SimulationOutputWidget.h"
#include "Simulation/SimulationDialog.h"

#include <QDockWidget>
#include <QMessageBox>
#include <QSplitter>

/*!
 * \class GDBLoggerWidget
 * \brief Console for viewing GDB response & sending user commands to GDB.
 */
/*!
 * \brief GDBLoggerWidget::GDBLoggerWidget
 * \param pParent
 */
GDBLoggerWidget::GDBLoggerWidget(QWidget *pParent)
  : QWidget(pParent)
{
  /* GDB commands area */
  mpCommandsTextBox = new OutputPlainTextEdit;
  mpCommandsTextBox->setLineWrapMode(QPlainTextEdit::WidgetWidth);
  mpCommandsTextBox->setFont(QFont(Helper::monospacedFontInfo.family()));
  mpCommandsTextBox->setUseTimer(false);
  /* GDB commands area */
  mpResponseTextBox = new OutputPlainTextEdit;
  mpResponseTextBox->setLineWrapMode(QPlainTextEdit::WidgetWidth);
  mpResponseTextBox->setFont(QFont(Helper::monospacedFontInfo.family()));
  mpResponseTextBox->setUseTimer(false);
  /* user command text box */
  mpCommandTextBox = new QLineEdit;
  mpCommandTextBox->setEnabled(false);
  mpCommandTextBox->setFont(QFont(Helper::monospacedFontInfo.family()));
  connect(mpCommandTextBox, SIGNAL(returnPressed()), SLOT(postCommand()));
  /* send command button */
  mpSendCommandButton = new QPushButton(Helper::send);
  mpSendCommandButton->setEnabled(false);
  connect(mpSendCommandButton, SIGNAL(clicked()), SLOT(postCommand()));
  /* Log Windows Splitter */
  QSplitter *pLogWindowsSplitter = new QSplitter;
  pLogWindowsSplitter->setChildrenCollapsible(false);
  pLogWindowsSplitter->setHandleWidth(4);
  pLogWindowsSplitter->setContentsMargins(0, 0, 0, 0);
  pLogWindowsSplitter->addWidget(mpCommandsTextBox);
  pLogWindowsSplitter->addWidget(mpResponseTextBox);
  pLogWindowsSplitter->setStretchFactor(0, 0);
  pLogWindowsSplitter->setStretchFactor(1, 1);
  /* layout */
  QGridLayout *pGridLayout = new QGridLayout;
  pGridLayout->setAlignment(Qt::AlignLeft);
  pGridLayout->setContentsMargins(1, 1, 1, 1);
  pGridLayout->addWidget(pLogWindowsSplitter, 0, 0, 1, 2);
  pGridLayout->addWidget(mpCommandTextBox, 1, 0);
  pGridLayout->addWidget(mpSendCommandButton, 1, 1);
  setLayout(pGridLayout);
  connect(GDBAdapter::instance(), SIGNAL(GDBProcessStarted()), SLOT(handleGDBProcessStarted()));
  connect(GDBAdapter::instance(), SIGNAL(GDBProcessFinished()), SLOT(handleGDBProcessFinished()));
}

/*!
 * \brief GDBLoggerWidget::logDebuggerCommand
 * Writes Debugger command in Debugger Logger window.
 * \param command
 */
void GDBLoggerWidget::logDebuggerCommand(QString command) {
    std::cout << "void GDBLoggerWidget::logDebuggerCommand(QString command)" << std::endl;
}

/*!
 * \brief GDBLoggerWidget::logDebuggerStandardResponse
 * Writes Debugger standard response in Debugger Logger window.
 * \param response
 */
void GDBLoggerWidget::logDebuggerStandardResponse(QString response) {
    std::cout << "void GDBLoggerWidget::logDebuggerStandardResponse(QString response)" << std::endl;
}

/*!
 * \brief GDBLoggerWidget::logDebuggerErrorResponse
 * Writes Debugger error response in Debugger Logger window.
 * \param response
 */
void GDBLoggerWidget::logDebuggerErrorResponse(QString response) {
    std::cout << "void GDBLoggerWidget::logDebuggerErrorResponse(QString response)" << std::endl;
}

/*!
 * \brief GDBLoggerWidget::logDebuggerResponse
 * Writes Debugger response in Debugger Logger window.
 * \param response
 * \param color
 */
void GDBLoggerWidget::logDebuggerResponse(QString response, QColor color) {
    std::cout << "void GDBLoggerWidget::logDebuggerResponse(QString response, QColor color)" << std::endl;
}

/*!
 * \brief GDBLoggerWidget::postCommand
 * Posts the user typed GDB command.
 */
void GDBLoggerWidget::postCommand() {
    std::cout << "void GDBLoggerWidget::postCommand()" << std::endl;
}

/*!
 * \brief GDBLoggerWidget::handleGDBProcessStarted
 * Slot activated when GDBProcessStarted signal of GDBAdapter is raised.
 * Clears the GDB response text box area. Allows to send commands.
 */
void GDBLoggerWidget::handleGDBProcessStarted() {
    std::cout << "void GDBLoggerWidget::handleGDBProcessStarted()" << std::endl;
}

/*!
 * \brief GDBLoggerWidget::handleGDBProcessFinished
 * Slot activated when GDBProcessFinished signal of GDBAdapter is raised.
 * Disables the user commands.
 */
void GDBLoggerWidget::handleGDBProcessFinished() {
    std::cout << "void GDBLoggerWidget::handleGDBProcessFinished()" << std::endl;
}

/*!
 * \class TargetOutputWidget
 * \brief Console for viewing GDB inferior output.
 */
/*!
 * \brief TargetOutputWidget::TargetOutputWidget
 * \param pParent
 */
TargetOutputWidget::TargetOutputWidget(QWidget *pParent)
  : OutputPlainTextEdit(pParent)
{
  setFont(QFont(Helper::monospacedFontInfo.family()));
  connect(GDBAdapter::instance(), SIGNAL(GDBProcessStarted()), SLOT(handleGDBProcessStarted()));
}

/*!
 * \brief TargetOutputWidget::logDebuggerStandardOutput
 * Writes Debugger standard response in Output Browser window.
 * \param output
 */
void TargetOutputWidget::logDebuggerStandardOutput(QString output) {
    std::cout << "void TargetOutputWidget::logDebuggerStandardOutput(QString output)" << std::endl;
}

/*!
 * \brief TargetOutputWidget::logDebuggerErrorOutput
 * Writes Debugger error response in Output Browser window.
 * \param output
 */
void TargetOutputWidget::logDebuggerErrorOutput(QString output) {
    std::cout << "void TargetOutputWidget::logDebuggerErrorOutput(QString output)" << std::endl;
}

/*!
 * \brief TargetOutputWidget::logDebuggerOutput
 * Writes Debugger response in Output Browser window.
 * \param output
 * \param color
 */
void TargetOutputWidget::logDebuggerOutput(QString output, QColor color) {
    std::cout << "void TargetOutputWidget::logDebuggerOutput(QString output, QColor color)" << std::endl;
}

/*!
 * \brief TargetOutputWidget::handleGDBProcessStarted
 * Slot activated when GDBProcessStarted signal of GDBAdapter is raised.
 * Clears the GDB output text box area. Allows to send commands.
 */
void TargetOutputWidget::handleGDBProcessStarted() {
    std::cout << "void TargetOutputWidget::handleGDBProcessStarted()" << std::endl;
}

/*!
 * \class GDBAdapter
 * \brief Interface for communication with GDB.
 */

GDBAdapter *GDBAdapter::mpInstance = 0;

/*!
 * \brief GDBAdapter::create
 */
void GDBAdapter::create() {
    std::cout << "void GDBAdapter::create()" << std::endl;
}

/*!
 * \brief GDBAdapter::destroy
 */
void GDBAdapter::destroy() {
    std::cout << "void GDBAdapter::destroy()" << std::endl;
}

/*!
 * \brief GDBAdapter::GDBAdapter
 * \param pParent
 */
GDBAdapter::GDBAdapter(QWidget *pParent)
  : QObject(pParent)
{
  setExecuteCommand(GDBAdapter::ExecNext);
  mAttachToProcessId = "0";
  mIsRunning = false;
  mIsParsingStandardOutput = false;
  mIsInferiorSuspended = false;
  mIsInferiorTerminated = false;
  mIsInferiorRunning = false;
  mToken = 0;
  mCatchOMCBreakpointId = "1";
  mGDBCommandTimer.setSingleShot(true);
  connect(&mGDBCommandTimer, SIGNAL(timeout()), SLOT(GDBcommandTimeout()));
}

/*!
 * \brief GDBAdapter::launch
 * Launches the GDB with the default arguments.
 * \param program - the program to debug with GDB.
 * \param workingDirectory - working directory for GDB.
 * \param arguments - program arguments
 * \param GDBPath - GDB location.
 * \param simulationOptions
 */
void GDBAdapter::launch(QString program, QString workingDirectory, QStringList arguments, QString GDBPath, SimulationOptions simulationOptions) {
    std::cout << "void GDBAdapter::launch(QString program, QString workingDirectory, QStringList arguments, QString GDBPath, SimulationOptions simulationOptions)" << std::endl;
}

/*!
 * \brief GDBAdapter::launch
 * Launches the GDB and attachs it to the processID.
 * \param processID - process ID to attach.
 * \param GDBPath - GDB location.
 */
void GDBAdapter::launch(QString processId, QString GDBPath) {
    std::cout << "void GDBAdapter::launch(QString processId, QString GDBPath)" << std::endl;
}

/*!
 * \brief GDBAdapter::postCommand
 * Sends a command to GDB.
 * \param command - the command to send.
 * \param callback - the command to callback function.
 */
void GDBAdapter::postCommand(QByteArray command, GDBCommandCallback callback) {
    std::cout << "void GDBAdapter::postCommand(QByteArray command, GDBCommandCallback callback)" << std::endl;
}

/*!
 * \brief GDBAdapter::postCommand
 * Sends a command to GDB.
 * \param command - the command to send.
 * \param pCallbackObject - the QObject pointer which is used to call the callback function.
 * \param callback - the command to callback function.
 */
void GDBAdapter::postCommand(QByteArray command, QObject *pCallbackObject, GDBCommandCallback callback) {
    std::cout << "void GDBAdapter::postCommand(QByteArray command, QObject *pCallbackObject, GDBCommandCallback callback)" << std::endl;
}

/*!
 * \brief GDBAdapter::postCommand
 * Sends a command to GDB.
 * \param command - the command to send.
 * \param flags - the command flags.
 * \param callback - the command to callback function.
 */
void GDBAdapter::postCommand(QByteArray command, GDBCommandFlags flags, GDBCommandCallback callback) {
    std::cout << "void GDBAdapter::postCommand(QByteArray command, GDBCommandFlags flags, GDBCommandCallback callback)" << std::endl;
}

/*!
 * \brief GDBAdapter::postCommand
 * Sends a command to GDB.
 * \param command - the command to send.
 * \param flags - the command flags.
 * \param pCallbackObject - the QObject pointer which is used to call the callback function.
 * \param callback - the command to callback function.
 */
void GDBAdapter::postCommand(QByteArray command, GDBCommandFlags flags, QObject *pCallbackObject, GDBCommandCallback callback) {
    std::cout << "void GDBAdapter::postCommand(QByteArray command, GDBCommandFlags flags, QObject *pCallbackObject, GDBCommandCallback callback)" << std::endl;
}

/*!
 * \brief GDBAdapter::commandTimeoutTime
 * Returns the GDB Command timeout.
 * \return
 */
int GDBAdapter::commandTimeoutTime() const {
    std::cout << "int GDBAdapter::commandTimeoutTime() const" << std::endl;
    return 0;
}

/*!
 * \brief GDBAdapter::insertCatchOMCBreakpoint
 * Inserts a breakpoint at Catch.omc:1 to handle MMC_THROW()
 */
void GDBAdapter::insertCatchOMCBreakpoint() {
    std::cout << "void GDBAdapter::insertCatchOMCBreakpoint()" << std::endl;
}

/*!
 * \brief GDBAdapter::enableCatchOMCBreakpoint
 * Enables the breakpoint at Catch.omc:1 to handle MMC_THROW()
 */
void GDBAdapter::enableCatchOMCBreakpoint() {
    std::cout << "void GDBAdapter::enableCatchOMCBreakpoint()" << std::endl;
}

/*!
 * \brief GDBAdapter::disableCatchOMCBreakpoint
 * Disables the breakpoint at Catch.omc:1 to handle MMC_THROW()
 */
void GDBAdapter::disableCatchOMCBreakpoint() {
    std::cout << "void GDBAdapter::disableCatchOMCBreakpoint()" << std::endl;
}

/*!
 * \brief GDBAdapter::deleteCatchOMCBreakpoint
 * Deletes the breakpoint at Catch.omc:1
 */
void GDBAdapter::deleteCatchOMCBreakpoint() {
    std::cout << "void GDBAdapter::deleteCatchOMCBreakpoint()" << std::endl;
}

/*!
 * \brief GDBAdapter::stackListFramesCB
 * Callback function for handling the -stack-list-frames command.
 * \param pGDBMIResultRecord - the stack list frames result record.
 */
void GDBAdapter::stackListFramesCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::stackListFramesCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::stackListVariablesCB
 * Callback function for handling the -stack-list-variables command.
 * \param pGDBMIResultRecord - the stack list variables record.
 */
/*
  -stack-list-variables --thread 1 --frame 0 --all-values
  ^done,variables=[{name="x",value="11"},{name="s",value="{a = 1, b = 2}"}]
  */
void GDBAdapter::stackListVariablesCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::stackListVariablesCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * Callback function for handling the "-data-evaluate-expression (char*)getTypeOfAny(expr)" command.
 * \param pGDBMIResultRecord - the variable type result record.
 * \param pGDBMIResultRecord
 */
/*
  935^done,value="0x72e1938 \"String\""
  59^done,value="0x5c012e0 \"record<GlobalScript.SymbolTable.SYMBOLTABLE>\""
  Sometimes the values are optimized out if -O2 is used then we get this,
  14^error,msg="value has been optimized out"
  */
void GDBAdapter::getTypeOfAnyCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::getTypeOfAnyCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::dataEvaluateExpressionCB
 * Callback function for handling the "-data-evaluate-expression expr" command.
 * \param pGDBMIResultRecord - the variable value result record.
 */
/*
  392^done,value="0 '\\000'"
  929^done,value="6"
  */
void GDBAdapter::dataEvaluateExpressionCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::dataEvaluateExpressionCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::anyStringCB
 * Callback function for handling the "-data-evaluate-expression (char*)anyString(expr)" command.
 * \param pGDBMIResultRecord - the variable value result record.
 */
/*
  1302^done,value="0x456c158 \"C:/OpenModelica/trunk/build/\""
  */
void GDBAdapter::anyStringCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::anyStringCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::arrayLengthCB
 * Callback function for handling the "-data-evaluate-expression (int)arrayLength(expr)" command.
 * \param pGDBMIResultRecord - the variable value result record.
 */
/*
  252^done,value="3"
  */
void GDBAdapter::arrayLengthCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::arrayLengthCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::getMetaTypeElementCB
 * Callback function for handling the "-data-evaluate-expression "(char*)getMetaTypeElementCB(expr, index)"" command.
 * \param pGDBMIResultRecord - the meta type element array as result record.
 */
/*
  20^done,value="0x59f7008 \"^omc_element{3411547,name,String,BouncingBall}\""
  21^done,value="0x59f7008 \"^omc_element{21175143,subscripts,list<Any>,{NIL}}\""
  */
void GDBAdapter::getMetaTypeElementCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::getMetaTypeElementCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::isOptionNoneCB
 * Callback function for handling the "-data-evaluate-expression (int)isOptionNone(expr)" command.
 * \param pGDBMIResultRecord - the option none value result record.
 */
/*
  252^done,value="1"
  */
void GDBAdapter::isOptionNoneCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::isOptionNoneCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::createFullBacktraceCB
 * Callback function for handling the "-interpreter-exec console "thread apply all bt full"" command.
 * \param pGDBMIResultRecord - the backtrace result record.
 */
void GDBAdapter::createFullBacktraceCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::createFullBacktraceCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::insertBreakpointCB
 * Callback function for handling the "-insert-break" command.
 * \param pGDBMIResultRecord - the breakpoint ID result record.
 */
/*
  6^done,bkpt={number="1",type="breakpoint",disp="keep",enabled="y",addr="0x00c397f1",func="omc_Interactive_getComponents2",
  file="c:/OpenModelica/trunk/Compiler/Script/Interactive.mo",fullname="c:\\openmodelica\\trunk\\compiler\\script\\interactive.mo",
  line="10806",times="0",original-location="C:/OpenModelica/trunk/Compiler/Script/Interactive.mo:10806"}
  */
void GDBAdapter::insertBreakpointCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::insertBreakpointCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::getGDBMIResult
 * Finds the GDBMIResult from GDBMIResultList.
 * \param variable -  the name of GDBMIResult to find.
 * \param resultsList - GDBMIResultList
 * \return GDBMIResult
 */
GDBMIResult* GDBAdapter::getGDBMIResult(const char *variable, GDBMIResultList resultsList) {
    std::cout << "GDBMIResult* GDBAdapter::getGDBMIResult(const char *variable, GDBMIResultList resultsList)" << std::endl;
    return nullptr;
}

/*!
 * \brief GDBAdapter::getGDBMIConstantValue
 * Finds the constant value from GDBMIResult
 * \param pGDBMIResult - pointer to GDBMIResult
 * \return the constant value.
 */
QString GDBAdapter::getGDBMIConstantValue(GDBMIResult *pGDBMIResult) {
    std::cout << "QString GDBAdapter::getGDBMIConstantValue(GDBMIResult *pGDBMIResult)" << std::endl;
    return QString();
}

/*!
 * \brief GDBAdapter::insertBreakpoint
 * Sends the -break-insert command to GDB.
 * \param pBreakpointTreeItem - pointer to BreakpointTreeItem
 */
void GDBAdapter::insertBreakpoint(BreakpointTreeItem *pBreakpointTreeItem) {
    std::cout << "void GDBAdapter::insertBreakpoint(BreakpointTreeItem *pBreakpointTreeItem)" << std::endl;
}

/*!
 * \brief GDBAdapter::suspendDebugger
 * Sets the debugger suspended.\n
 * Sends the notification to StackFramesWidget and LocalsWidget by emitting the signal inferiorSuspended
 */
void GDBAdapter::suspendDebugger() {
    std::cout << "void GDBAdapter::suspendDebugger()" << std::endl;
}

/*!
 * \brief GDBAdapter::resumeDebugger
 * Sets the debugger resumed.\n
 * Sends the notification to StackFramesWidget and LocalsWidget by emitting the signal inferiorResumed
 */
void GDBAdapter::resumeDebugger() {
    std::cout << "void GDBAdapter::resumeDebugger()" << std::endl;
}

/*!
 * \brief GDBAdapter::handleGDBProcessStartedHelper
 * Helper function for handling the GDB process start up.
 * \see GDBAdapter::handleGDBProcessStarted
 * \see GDBAdapter::handleGDBProcessStartedForAttach
 */
void GDBAdapter::handleGDBProcessStartedHelper() {
    std::cout << "void GDBAdapter::handleGDBProcessStartedHelper()" << std::endl;
}

/*!
 * \brief GDBAdapter::writeDebuggerCommandLog
 * Writes the debugger command to the omeditdebugger.log file.
 * \param command - the command to write
 * \param command
 */
void GDBAdapter::writeDebuggerCommandLog(QByteArray command) {
    std::cout << "void GDBAdapter::writeDebuggerCommandLog(QByteArray command)" << std::endl;
}

/*!
 * \brief GDBAdapter::writeDebuggerResponseLog
 * Writes the debugger response to the omeditdebugger.log file.
 * \param response - the response to write
 * \param response
 */
void GDBAdapter::writeDebuggerResponseLog(QString response) {
    std::cout << "void GDBAdapter::writeDebuggerResponseLog(QString response)" << std::endl;
}

/*!
 * \brief GDBAdapter::insertBreakpoints
 * Reads the list of breakpoints from BreakpointsTreeModel and inserts them in GDB.\n
 */
void GDBAdapter::insertBreakpoints() {
    std::cout << "void GDBAdapter::insertBreakpoints()" << std::endl;
}

/*!
 * \brief GDBAdapter::startDebugger
 * Starts the debugger.\n
 * Sends the -exec-run command.\n
 * Sends the -data-evaluate-expression changeStdStreamBuffer() command.\n
 * Sends the notification to StackFramesWidget and LocalsWidget by emitting the signal inferiorResumed
 */
void GDBAdapter::startDebugger() {
    std::cout << "void GDBAdapter::startDebugger()" << std::endl;
}

/*!
 * \brief GDBAdapter::processGDBMIResponse
 * Process the GDB output.
 * \param response
 */
void GDBAdapter::processGDBMIResponse(QString response) {
    std::cout << "void GDBAdapter::processGDBMIResponse(QString response)" << std::endl;
}

/*!
 * \brief GDBAdapter::processGDBMIOutOfBandRecord
 * Process the GDBMIOutOfBandRecord.
 * \param pGDBMIOutOfBandRecord
 */
void GDBAdapter::processGDBMIOutOfBandRecord(GDBMIOutOfBandRecord *pGDBMIOutOfBandRecord) {
    std::cout << "void GDBAdapter::processGDBMIOutOfBandRecord(GDBMIOutOfBandRecord *pGDBMIOutOfBandRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::processGDBMIResultRecord
 * Process the GDBMIResultRecord.
 * \param pGDBMIResultRecord
 */
void GDBAdapter::processGDBMIResultRecord(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::processGDBMIResultRecord(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::handleGDBMIStreamRecord
 * Handles the GDBMIStreamRecord.
 * \param pGDBMIStreamRecord
 */
void GDBAdapter::handleGDBMIStreamRecord(GDBMIStreamRecord *pGDBMIStreamRecord) {
    std::cout << "void GDBAdapter::handleGDBMIStreamRecord(GDBMIStreamRecord *pGDBMIStreamRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::handleGDBMIConsoleStream
 * Handles the GDBMIStreamRecord.
 * \param pGDBMIStreamRecord
 */
void GDBAdapter::handleGDBMIConsoleStream(GDBMIStreamRecord *pGDBMIStreamRecord) {
    std::cout << "void GDBAdapter::handleGDBMIConsoleStream(GDBMIStreamRecord *pGDBMIStreamRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::handleGDBMILogStream
 * Handles the GDBMIStreamRecord.\n
 * log-stream-output is output text coming from gdb's internals, for instance messages that should be displayed as part of an error log.\n
 * All the log output is prefixed by ‘&’.
 * \param pGDBMIStreamRecord
 */
void GDBAdapter::handleGDBMILogStream(GDBMIStreamRecord *pGDBMIStreamRecord) {
    std::cout << "void GDBAdapter::handleGDBMILogStream(GDBMIStreamRecord *pGDBMIStreamRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::skipSteppedInFrames
 * Checks if debugger is stopped on a non-modelica file.
 * Performs silent -exec-next or -exec-step until we reach a valid modelica file.
 * \param pGDBMIResultRecord
 * \return
 */
bool GDBAdapter::skipSteppedInFrames(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "bool GDBAdapter::skipSteppedInFrames(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
    return false;
}

/*!
 * \brief GDBAdapter::handleStoppedEvent
 * Handles the GDB stopped event.
 * \param reason
 * \param pGDBMIResultRecord
 */
void GDBAdapter::handleStoppedEvent(std::string reason, GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::handleStoppedEvent(std::string reason, GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::handleBreakpointHit
 * Handles the GDB breakpoint hit event.
 * \param pGDBMIResultRecord
 */
void GDBAdapter::handleBreakpointHit(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::handleBreakpointHit(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::handleSteppingRange
 * Handles the GDB end stepping range event.
 * \param pGDBMIResultRecord
 */
void GDBAdapter::handleSteppingRange(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::handleSteppingRange(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::handleFunctionFinished
 * Handles the GDB function finished event.
 * \param pGDBMIResultRecord
 */
void GDBAdapter::handleFunctionFinished(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::handleFunctionFinished(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::handleSignalReceived
 * Handles the GDB signal received event.
 * \param pGDBMIResultRecord
 */
void GDBAdapter::handleSignalReceived(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::handleSignalReceived(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::threadInfoCB
 * Callback function for handling the -thread-info command.
 * \param pGDBMIResultRecord - the threads list result record.
 */
void GDBAdapter::threadInfoCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::threadInfoCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::attachCB
 * Callback function for handling the "attach pid" command.
 * \param pGDBMIResultRecord - the attach command result record.
 * \param pGDBMIResultRecord
 */
void GDBAdapter::attachCB(GDBMIResultRecord *pGDBMIResultRecord) {
    std::cout << "void GDBAdapter::attachCB(GDBMIResultRecord *pGDBMIResultRecord)" << std::endl;
}

/*!
 * \brief GDBAdapter::handleGDBProcessStarted
 * Slot activated when started signal of GDB process is raised.
 * Sets the GDB running state flag to true.
 */
void GDBAdapter::handleGDBProcessStarted() {
    std::cout << "void GDBAdapter::handleGDBProcessStarted()" << std::endl;
}

/*!
 * \brief GDBAdapter::handleGDBProcessStartedForSimulation
 * Slot activated when started signal of GDB process is raised for the simulation.\n
 * Saves the result file last modified time.
 */
void GDBAdapter::handleGDBProcessStartedForSimulation() {
    std::cout << "void GDBAdapter::handleGDBProcessStartedForSimulation()" << std::endl;
}

/*!
 * \brief GDBAdapter::handleGDBProcessStartedForAttach
 * Slot activated when started signal of GDB process is raised.\n
 * Sets the GDB running state flag to true. Posts the attach to process command.
 */
void GDBAdapter::handleGDBProcessStartedForAttach() {
    std::cout << "void GDBAdapter::handleGDBProcessStartedForAttach()" << std::endl;
}

/*!
 * \brief GDBAdapter::readGDBStandardOutput
 * Slot activated when readyReadStandardOutput signal of GDB process is raised.
 * Reads the output stream of GDB, parses the result and generates the events.
 */
void GDBAdapter::readGDBStandardOutput() {
    std::cout << "void GDBAdapter::readGDBStandardOutput()" << std::endl;
}

/*!
 * \brief GDBAdapter::readGDBErrorOutput
 * Slot activated when readyReadStandardError signal of GDB process is raised.
 * Reads the error stream of GDB.
 */
void GDBAdapter::readGDBErrorOutput() {
    std::cout << "void GDBAdapter::readGDBErrorOutput()" << std::endl;
}

/*!
 * \brief GDBAdapter::handleGDBProcessError
 * Slot activated when error signal of GDB Process is raised.
 * Sets the GDB running state flag to false.
 * \param error
 */
void GDBAdapter::handleGDBProcessError(QProcess::ProcessError error) {
    std::cout << "void GDBAdapter::handleGDBProcessError(QProcess::ProcessError error)" << std::endl;
}

/*!
 * \brief GDBAdapter::handleGDBProcessFinished
 * Slot activated when finished signal of GDB Process is raised.
 * Sets the GDB running state flag to false.
 * \param exitCode
 */
void GDBAdapter::handleGDBProcessFinished(int exitCode) {
    std::cout << "void GDBAdapter::handleGDBProcessFinished(int exitCode)" << std::endl;
}

/*!
 * \brief GDBAdapter::handleGDBProcessFinishedForSimulation
 * Slot activated when finished signal of GDB Process is raised.
 * \param exitCode
 */
void GDBAdapter::handleGDBProcessFinishedForSimulation(int exitCode) {
    std::cout << "void GDBAdapter::handleGDBProcessFinishedForSimulation(int exitCode)" << std::endl;
}

/*!
 * \brief GDBAdapter::GDBcommandTimeout
 * Slot activated when timeout signal of mGDBCommandTimer is raised.
 */
void GDBAdapter::GDBcommandTimeout() {
    std::cout << "void GDBAdapter::GDBcommandTimeout()" << std::endl;
}
