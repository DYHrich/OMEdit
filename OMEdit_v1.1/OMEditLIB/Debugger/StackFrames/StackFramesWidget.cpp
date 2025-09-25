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

#include "Debugger/StackFrames/StackFramesWidget.h"
#include <iostream>
#include "Options/OptionsDialog.h"
#include "MainWindow.h"
#include "Modeling/LibraryTreeWidget.h"
#include "Modeling/ItemDelegate.h"
#include "Debugger/GDB/GDBAdapter.h"
#include "Debugger/GDB/CommandFactory.h"
#include "Debugger/Locals/LocalsWidget.h"

#include <QMenu>
#include <QMessageBox>
#include <QHBoxLayout>

StackFrameItem::StackFrameItem(QString level, QString address, QString function, QString line, QString file, QString fullName, StackFramesTreeWidget *pStackFramesTreeWidget)
  : QTreeWidgetItem(pStackFramesTreeWidget)
{
  mpStackFramesTreeWidget = pStackFramesTreeWidget;
  mLevel = level;
  mAddress = address;
  mLine = line;
  mFile = cleanupFileName(file);
  mFullName = cleanupFileName(fullName);
  mFunction = cleanupFunction(function);
  setText(0, mFunction);
  setToolTip(0, mFunction);
  setText(1, mLine);
  setToolTip(1, mLine);
  setText(2, getFileName());
  setToolTip(2, getFileName());
  filterStackFrame();
}

QString StackFrameItem::getFileName() {
    std::cout << "QString StackFrameItem::getFileName()" << std::endl;
    return QString();
}

void StackFrameItem::filterStackFrame() {
    std::cout << "void StackFrameItem::filterStackFrame()" << std::endl;
}

QString StackFrameItem::cleanupFileName(const QString &fileName) {
    std::cout << "QString StackFrameItem::cleanupFileName(const QString &fileName)" << std::endl;
    return QString();
}

QString StackFrameItem::cleanupFunction(const QString &function) {
    std::cout << "QString StackFrameItem::cleanupFunction(const QString &function)" << std::endl;
    return QString();
}

char* StackFrameItem::omcHexToString(const char* str) {
    std::cout << "char* StackFrameItem::omcHexToString(const char* str)" << std::endl;
    return nullptr;
}

/*!
  \class StackFramesTreeWidget
  \brief Shows the list of stack frames as a tree.
  */
/*!
  \param pStackFramesWidget - pointer to StackFramesWidget
  */
StackFramesTreeWidget::StackFramesTreeWidget(StackFramesWidget *pStackFramesWidget)
  : QTreeWidget(pStackFramesWidget)
{
  mpStackFramesWidget = pStackFramesWidget;
  setItemDelegate(new ItemDelegate(this));
  setTextElideMode(Qt::ElideMiddle);
  setIconSize(Helper::iconSize);
  setColumnCount(3);
  QStringList headers;
  headers << tr("Function") << Helper::line << Helper::file;
  setHeaderLabels(headers);
  setIndentation(0);
  setExpandsOnDoubleClick(false);
  setContextMenuPolicy(Qt::CustomContextMenu);
  createActions();
  connect(GDBAdapter::instance(), SIGNAL(stackListFrames(GDBMIValue*)), SLOT(createStackFrames(GDBMIValue*)));
  connect(this, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), mpStackFramesWidget, SLOT(stackCurrentItemChanged(QTreeWidgetItem*)));
  connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
}

StackFramesWidget* StackFramesTreeWidget::getStackFramesWidget() {
    std::cout << "StackFramesWidget* StackFramesTreeWidget::getStackFramesWidget()" << std::endl;
    return nullptr;
}

void StackFramesTreeWidget::clearStackFrames() {
    std::cout << "void StackFramesTreeWidget::clearStackFrames()" << std::endl;
}

void StackFramesTreeWidget::updateStackFrames() {
    std::cout << "void StackFramesTreeWidget::updateStackFrames()" << std::endl;
}

void StackFramesTreeWidget::setCurrentStackFrame(QTreeWidgetItem *pQTreeWidgetItem) {
    std::cout << "void StackFramesTreeWidget::setCurrentStackFrame(QTreeWidgetItem *pQTreeWidgetItem)" << std::endl;
}

void StackFramesTreeWidget::createActions() {
    std::cout << "void StackFramesTreeWidget::createActions()" << std::endl;
}

/*!
  Slot activated when stackListFrames signal of GDBAdapter is raised.
  */
/*
  -stack-list-frames
  ^done,
  stack=[
  frame={level="0",addr="0x00010734",func="callee4",
  file="../../../devo/gdb/testsuite/gdb.mi/basics.c",
  fullname="/home/foo/bar/devo/gdb/testsuite/gdb.mi/basics.c",line="8"},
  frame={level="1",addr="0x0001076c",func="callee3",
  file="../../../devo/gdb/testsuite/gdb.mi/basics.c",
  fullname="/home/foo/bar/devo/gdb/testsuite/gdb.mi/basics.c",line="17"}]
  */
void StackFramesTreeWidget::createStackFrames(GDBMIValue *pGDBMIValue) {
    std::cout << "void StackFramesTreeWidget::createStackFrames(GDBMIValue *pGDBMIValue)" << std::endl;
}

void StackFramesTreeWidget::showContextMenu(QPoint point) {
    std::cout << "void StackFramesTreeWidget::showContextMenu(QPoint point)" << std::endl;
}

void StackFramesTreeWidget::createFullBacktrace() {
    std::cout << "void StackFramesTreeWidget::createFullBacktrace()" << std::endl;
}

/*!
 * \class StackFramesWidget
 * \brief A widget containing debugger manipulation buttons and StackFramesTreeWidget.
 */
/*!
 * \brief StackFramesWidget::StackFramesWidget
 * \param pParent
 */
StackFramesWidget::StackFramesWidget(QWidget *pParent)
  : QWidget(pParent)
{
  /* continue tool button */
  mpResumeToolButton = new QToolButton;
  mpResumeToolButton->setEnabled(false);
  mpResumeToolButton->setText(Helper::resume);
  mpResumeToolButton->setIcon(QIcon(":/Resources/icons/resume.svg"));
  mpResumeToolButton->setToolTip(Helper::resume);
  mpResumeToolButton->setAutoRaise(true);
  connect(mpResumeToolButton, SIGNAL(clicked()), SLOT(resumeButtonClicked()));
  /* continue tool button */
  mpInterruptToolButton = new QToolButton;
  mpInterruptToolButton->setEnabled(false);
  mpInterruptToolButton->setText(Helper::interrupt);
  mpInterruptToolButton->setIcon(QIcon(":/Resources/icons/interrupt.svg"));
  mpInterruptToolButton->setToolTip(Helper::interrupt);
  mpInterruptToolButton->setAutoRaise(true);
  connect(mpInterruptToolButton, SIGNAL(clicked()), SLOT(interruptButtonClicked()));
  /* continue tool button */
  mpExitToolButton = new QToolButton;
  mpExitToolButton->setEnabled(false);
  mpExitToolButton->setText(Helper::exit);
  mpExitToolButton->setIcon(QIcon(":/Resources/icons/exit.svg"));
  mpExitToolButton->setToolTip(Helper::exit);
  mpExitToolButton->setAutoRaise(true);
  connect(mpExitToolButton, SIGNAL(clicked()), SLOT(exitButtonClicked()));
  /* Control buttons frame */
  QFrame *pControlButtonsFrame = new QFrame;
  QHBoxLayout *pControlButtonsHorizontalLayout = new QHBoxLayout;
  pControlButtonsHorizontalLayout->setContentsMargins(0, 0, 0, 0);
  pControlButtonsHorizontalLayout->setSpacing(0);
  pControlButtonsHorizontalLayout->addWidget(mpResumeToolButton);
  pControlButtonsHorizontalLayout->addWidget(mpInterruptToolButton);
  pControlButtonsHorizontalLayout->addWidget(mpExitToolButton);
  pControlButtonsFrame->setLayout(pControlButtonsHorizontalLayout);
  /* step-into tool button */
  mpStepIntoToolButton = new QToolButton;
  mpStepIntoToolButton->setEnabled(false);
  mpStepIntoToolButton->setText(Helper::stepInto);
  mpStepIntoToolButton->setIcon(QIcon(":/Resources/icons/step-into.svg"));
  mpStepIntoToolButton->setToolTip(Helper::stepInto);
  mpStepIntoToolButton->setAutoRaise(true);
  connect(mpStepIntoToolButton, SIGNAL(clicked()), SLOT(stepIntoButtonClicked()));
  /* step-over tool button */
  mpStepOverToolButton = new QToolButton;
  mpStepOverToolButton->setEnabled(false);
  mpStepOverToolButton->setText(Helper::stepOver);
  mpStepOverToolButton->setIcon(QIcon(":/Resources/icons/step-over.svg"));
  mpStepOverToolButton->setToolTip(Helper::stepOver);
  mpStepOverToolButton->setAutoRaise(true);
  connect(mpStepOverToolButton, SIGNAL(clicked()), SLOT(stepOverButtonClicked()));
  /* step-return tool button */
  mpStepReturnToolButton = new QToolButton;
  mpStepReturnToolButton->setEnabled(false);
  mpStepReturnToolButton->setText(Helper::stepReturn);
  mpStepReturnToolButton->setIcon(QIcon(":/Resources/icons/step-return.svg"));
  mpStepReturnToolButton->setToolTip(Helper::stepReturn);
  mpStepReturnToolButton->setAutoRaise(true);
  connect(mpStepReturnToolButton, SIGNAL(clicked()), SLOT(stepReturnButtonClicked()));
  /* Flow buttons frame */
  QFrame *pFlowButtonsFrame = new QFrame;
  QHBoxLayout *pFlowButtonsHorizontalLayout = new QHBoxLayout;
  pFlowButtonsHorizontalLayout->setContentsMargins(0, 0, 0, 0);
  pFlowButtonsHorizontalLayout->setSpacing(0);
  pFlowButtonsHorizontalLayout->addWidget(mpStepIntoToolButton);
  pFlowButtonsHorizontalLayout->addWidget(mpStepOverToolButton);
  pFlowButtonsHorizontalLayout->addWidget(mpStepReturnToolButton);
  pFlowButtonsFrame->setLayout(pFlowButtonsHorizontalLayout);
  /* Threads Label */
  mpThreadsLabel = new Label(tr("Threads:"));
  /* Threads combo box */
  mpThreadsComboBox = new QComboBox;
  mpThreadsComboBox->setEnabled(false);
  connect(mpThreadsComboBox, SIGNAL(currentIndexChanged(int)), SLOT(threadChanged(int)));
  connect(GDBAdapter::instance(), SIGNAL(threadInfo(GDBMIValue*,QString)), SLOT(fillThreadComboBox(GDBMIValue*,QString)));
  /* Thread frame */
  QFrame *pThreadFrame = new QFrame;
  QHBoxLayout *pThreadHorizontalLayout = new QHBoxLayout;
  pThreadHorizontalLayout->setContentsMargins(0, 0, 0, 0);
  pThreadHorizontalLayout->setSpacing(0);
  pThreadHorizontalLayout->addWidget(mpThreadsLabel);
  pThreadHorizontalLayout->addWidget(mpThreadsComboBox);
  pThreadFrame->setLayout(pThreadHorizontalLayout);
  // create project status bar
  mpStatusBar = new QStatusBar;
  mpStatusBar->setObjectName("ModelStatusBar");
  mpStatusBar->setStyleSheet("QStatusBar{border-bottom: none;} QStatusBar::item{margin-bottom: -1px;}");
  mpStatusBar->setSizeGripEnabled(false);
  mpStatusBar->addPermanentWidget(pControlButtonsFrame, 0);
  mpStatusBar->addPermanentWidget(pFlowButtonsFrame, 0);
  mpStatusBar->addPermanentWidget(pThreadFrame, 0);
  /* Message Label */
  mpStatusLabel = new Label;
  mpStatusLabel->setElideMode(Qt::ElideMiddle);
  mpStatusBar->addPermanentWidget(mpStatusLabel, 1);
  /* Stack Frames Tree Widget */
  mpStackFramesTreeWidget = new StackFramesTreeWidget(this);
  setSelectedThread(1);
  setSelectedFrame(0);
  /* set layout */
  QGridLayout *pMainLayout = new QGridLayout;
  pMainLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  pMainLayout->setContentsMargins(0, 0, 0, 0);
  pMainLayout->setSpacing(0);
  pMainLayout->addWidget(mpStatusBar, 0, 0);
  pMainLayout->addWidget(mpStackFramesTreeWidget, 1, 0);
  setLayout(pMainLayout);
  /* Make connections to control the enable/disable of tool buttons */
  connect(GDBAdapter::instance(), SIGNAL(GDBProcessStarted()), SLOT(handleGDBProcessStarted()));
  connect(GDBAdapter::instance(), SIGNAL(GDBProcessFinished()), SLOT(handleGDBProcessFinished()));
  connect(GDBAdapter::instance(), SIGNAL(inferiorSuspended()), SLOT(handleInferiorSuspended()));
  connect(GDBAdapter::instance(), SIGNAL(inferiorResumed()), SLOT(handleInferiorResumed()));
}

void StackFramesWidget::setStatusMessage(QString statusMessage) {
    std::cout << "void StackFramesWidget::setStatusMessage(QString statusMessage)" << std::endl;
}

/*!
  Slot activated when clicked signal of StackFramesWidget::mpResumeToolButton is raised.
  Resumes the GDB inferior process. Sends the -exec-continue command to GDB.
  */
void StackFramesWidget::resumeButtonClicked() {
    std::cout << "void StackFramesWidget::resumeButtonClicked()" << std::endl;
}

/*!
  Slot activated when clicked signal of StackFramesWidget::mpInterruptToolButton is raised.
  Sends the interrupt signal to GDB inferior process. Sends the -exec-interrupt command to GDB.
  */
void StackFramesWidget::interruptButtonClicked() {
    std::cout << "void StackFramesWidget::interruptButtonClicked()" << std::endl;
}

/*!
  Slot activated when clicked signal of StackFramesWidget::mpExitToolButton is raised.
  Stops the GDB inferior process. Sends the -gdb-exit command to GDB.
  */
void StackFramesWidget::exitButtonClicked() {
    std::cout << "void StackFramesWidget::exitButtonClicked()" << std::endl;
}

/*!
  Slot activated when clicked signal of StackFramesWidget::mpStepOverToolButton is raised.
  Sends the -exec-next command to GDB.
  */
void StackFramesWidget::stepOverButtonClicked() {
    std::cout << "void StackFramesWidget::stepOverButtonClicked()" << std::endl;
}

/*!
  Slot activated when clicked signal of StackFramesWidget::mpStepIntoToolButton is raised.
  Sends the -exec-step command to GDB.
  */
void StackFramesWidget::stepIntoButtonClicked() {
    std::cout << "void StackFramesWidget::stepIntoButtonClicked()" << std::endl;
}

/*!
  Slot activated when clicked signal of StackFramesWidget::mpStepReturnToolButton is raised.
  Sends the -exec-finish command to GDB.
  */
void StackFramesWidget::stepReturnButtonClicked() {
    std::cout << "void StackFramesWidget::stepReturnButtonClicked()" << std::endl;
}

/*!
  Slot activated when GDBProcessStarted signal of GDBAdapter is raised.
  Enables the GDB exit button.
  */
void StackFramesWidget::handleGDBProcessStarted() {
    std::cout << "void StackFramesWidget::handleGDBProcessStarted()" << std::endl;
}

/*!
  Slot activated when GDBProcessFinished signal of GDBAdapter is raised.
  Disables the program manipulation buttons.
  */
void StackFramesWidget::handleGDBProcessFinished() {
    std::cout << "void StackFramesWidget::handleGDBProcessFinished()" << std::endl;
}

/*!
  Slot activated when inferiorSuspended signal of GDBAdapter is raised.
  Enables the program stepping buttons.
  */
void StackFramesWidget::handleInferiorSuspended() {
    std::cout << "void StackFramesWidget::handleInferiorSuspended()" << std::endl;
}

/*!
  Slot activated when inferiorResumed signal of GDBAdapter is raised.
  Disables the program stepping buttons.
  */
void StackFramesWidget::handleInferiorResumed() {
    std::cout << "void StackFramesWidget::handleInferiorResumed()" << std::endl;
}

/*!
 * \brief StackFramesWidget::threadChanged
 * Slot activated when currentIndexChanged signal of mpThreadsComboBox is raised.
 * Requests the new list of stacks for the current thread.
 * \param threadIndex
 */
void StackFramesWidget::threadChanged(int threadIndex) {
    std::cout << "void StackFramesWidget::threadChanged(int threadIndex)" << std::endl;
}

/*!
 * \brief StackFramesWidget::fillThreadComboBox
 * Slot activated when threadInfo signal of GDBAdapter is raised.
 * Populates the mpThreadsComboBox with the number of threads.
 * \param pThreadsGDBMIValue
 * \param currentThreadId
 */
/*
-thread-info
 ^done,threads=[
 {id="2",target-id="Thread 0xb7e14b90 (LWP 21257)",
    frame={level="0",addr="0xffffe410",func="__kernel_vsyscall",
            args=[]},state="running"},
 {id="1",target-id="Thread 0xb7e156b0 (LWP 21254)",
    frame={level="0",addr="0x0804891f",func="foo",
            args=[{name="i",value="10"}],
            file="/tmp/a.c",fullname="/tmp/a.c",line="158"},
            state="running"}],
 current-thread-id="1"
*/
void StackFramesWidget::fillThreadComboBox(GDBMIValue *pThreadsGDBMIValue, QString currentThreadId) {
    std::cout << "void StackFramesWidget::fillThreadComboBox(GDBMIValue *pThreadsGDBMIValue, QString currentThreadId)" << std::endl;
}

/*!
 * \brief StackFramesWidget::stackCurrentItemChanged
 * Slot activated when currentItemChanged signal of StackFramesTreeWidget is raised.
 * Sends the -stack-list-variables command.
 * \param pQTreeWidgetItem
 * \return
 */
void StackFramesWidget::stackCurrentItemChanged(QTreeWidgetItem *pTreeWidgetItem) {
    std::cout << "void StackFramesWidget::stackCurrentItemChanged(QTreeWidgetItem *pTreeWidgetItem)" << std::endl;
}
