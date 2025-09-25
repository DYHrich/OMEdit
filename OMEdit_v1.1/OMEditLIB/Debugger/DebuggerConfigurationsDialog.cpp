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

#include "DebuggerConfigurationsDialog.h"
#include <iostream>
#include "Modeling/LibraryTreeWidget.h"
#include "Modeling/ItemDelegate.h"
#include "Debugger/GDB/GDBAdapter.h"
#include "Util/Helper.h"
#include "Util/StringHandler.h"
#include "Options/OptionsDialog.h"
#include "MainWindow.h"

#include <QGridLayout>
#include <QMessageBox>

/*!
 * \class DebuggerConfigurationPage
 * \brief Represents one debug configuration.
 */
/*!
 * \brief DebuggerConfigurationPage::DebuggerConfigurationPage
 * \param debuggerConfiguration - DebuggerConfiguration
 * \param pListWidgetItem - pointer to QListWidgetItem
 * \param pDebuggerConfigurationsDialog - pointer to DebuggerConfigurationsDialog
 */
DebuggerConfigurationPage::DebuggerConfigurationPage(DebuggerConfiguration debuggerConfiguration, QListWidgetItem *pListWidgetItem,
                                                     DebuggerConfigurationsDialog *pDebuggerConfigurationsDialog)
  : QWidget(pDebuggerConfigurationsDialog)
{
  mDebuggerConfiguration = debuggerConfiguration;
  mpConfigurationListWidgetItem = pListWidgetItem;
  mpDebuggerConfigurationsDialog = pDebuggerConfigurationsDialog;
  QFrame *pContainerFrame = new QFrame;
  pContainerFrame->setFrameShape(QFrame::StyledPanel);
  // Configuration Name
  mpNameLabel = new Label(Helper::name);
  mpNameTextBox = new QLineEdit(mDebuggerConfiguration.name);
  // Program File
  mpProgramLabel = new Label(tr("Program:"));
  mpProgramTextBox = new QLineEdit(mDebuggerConfiguration.program);
  mpProgramBrowseButton = new QPushButton(Helper::browse);
  connect(mpProgramBrowseButton, SIGNAL(clicked()), SLOT(browseProgramFile()));
  // Working Directory
  mpWorkingDirectoryLabel = new Label(Helper::workingDirectory);
  mpWorkingDirectoryTextBox = new QLineEdit(mDebuggerConfiguration.workingDirectory);
  mpWorkingDirectoryBrowseButton = new QPushButton(Helper::browse);
  connect(mpWorkingDirectoryBrowseButton, SIGNAL(clicked()), SLOT(browseWorkingDirectory()));
  // GDB Path
  mpGDBPathLabel = new Label(tr("GDB Path:"));
  mpGDBPathTextBox = new QLineEdit(mDebuggerConfiguration.GDBPath);
  mpGDBPathTextBox->setPlaceholderText(OptionsDialog::instance()->getDebuggerPage()->getGDBPath());
  mpGDBPathBrowseButton = new QPushButton(Helper::browse);
  connect(mpGDBPathBrowseButton, SIGNAL(clicked()), SLOT(browseGDBPath()));
  // Arguments
  mpArgumentsLabel = new Label(tr("Arguments:"));
  mpArgumentsTextBox = new QPlainTextEdit(mDebuggerConfiguration.arguments);
  // buttons
  mpApplyButton = new QPushButton(Helper::apply);
  mpApplyButton->setToolTip(tr("Saves the debug configuration"));
  connect(mpApplyButton, SIGNAL(clicked()), SLOT(saveDebugConfiguration()));
  mpResetButton = new QPushButton(Helper::reset);
  mpResetButton->setToolTip(tr("Resets the debug configuration"));
  connect(mpResetButton, SIGNAL(clicked()), SLOT(resetDebugConfiguration()));
  mpButtonBox = new QDialogButtonBox(Qt::Horizontal);
  mpButtonBox->addButton(mpApplyButton, QDialogButtonBox::ActionRole);
  mpButtonBox->addButton(mpResetButton, QDialogButtonBox::ActionRole);
  // set the layout
  QGridLayout *pContainerFrameGridLayout = new QGridLayout;
  pContainerFrameGridLayout->setContentsMargins(3, 3, 3, 3);
  pContainerFrameGridLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  pContainerFrameGridLayout->addWidget(mpNameLabel, 1, 0);
  pContainerFrameGridLayout->addWidget(mpNameTextBox, 1, 1, 1, 2);
  pContainerFrameGridLayout->addWidget(mpProgramLabel, 2, 0);
  pContainerFrameGridLayout->addWidget(mpProgramTextBox, 2, 1);
  pContainerFrameGridLayout->addWidget(mpProgramBrowseButton, 2, 2);
  pContainerFrameGridLayout->addWidget(mpWorkingDirectoryLabel, 3, 0);
  pContainerFrameGridLayout->addWidget(mpWorkingDirectoryTextBox, 3, 1);
  pContainerFrameGridLayout->addWidget(mpWorkingDirectoryBrowseButton, 3, 2);
  pContainerFrameGridLayout->addWidget(mpGDBPathLabel, 4, 0);
  pContainerFrameGridLayout->addWidget(mpGDBPathTextBox, 4, 1);
  pContainerFrameGridLayout->addWidget(mpGDBPathBrowseButton, 4, 2);
  pContainerFrameGridLayout->addItem(new QSpacerItem(1, 1), 5, 0);
  pContainerFrameGridLayout->addWidget(new Label(tr("GDB path defined in %1->Debugger is used if above field is empty.")
                                                 .arg(Helper::toolsOptionsPath)), 5, 1, 1, 2);
  pContainerFrameGridLayout->addWidget(mpArgumentsLabel, 6, 0, 1, 3);
  pContainerFrameGridLayout->addWidget(mpArgumentsTextBox, 7, 0, 1, 3);
  pContainerFrameGridLayout->addWidget(mpButtonBox, 8, 0, 1, 3, Qt::AlignRight);
  pContainerFrame->setLayout(pContainerFrameGridLayout);
  // main layout
  QGridLayout *pMainLayout = new QGridLayout;
  pMainLayout->setContentsMargins(0, 0, 0, 0);
  pMainLayout->addWidget(pContainerFrame, 0, 0);
  setLayout(pMainLayout);
}

/*!
 * \brief DebuggerConfigurationPage::configurationExists
 * Checks if the debugger configuration exists or not.
 * \param configurationKeyToCheck
 * \return
 */
bool DebuggerConfigurationPage::configurationExists(QString configurationKeyToCheck) {
    std::cout << "bool DebuggerConfigurationPage::configurationExists(QString configurationKeyToCheck)" << std::endl;
    return false;
}

/*!
 * \brief DebuggerConfigurationPage::browseProgramFile
 * Slot activated when mProgramBrowseButton clicked signal is raised.\n
 * Allows user to select program File.
 */
void DebuggerConfigurationPage::browseProgramFile() {
    std::cout << "void DebuggerConfigurationPage::browseProgramFile()" << std::endl;
}

/*!
 * \brief DebuggerConfigurationPage::browseWorkingDirectory
 * Slot activated when mpWorkingDirectoryBrowseButton clicked signal is raised.\n
 * Allows user to select the working directory.
 */
void DebuggerConfigurationPage::browseWorkingDirectory() {
    std::cout << "void DebuggerConfigurationPage::browseWorkingDirectory()" << std::endl;
}

/*!
 * \brief DebuggerConfigurationPage::browseGDBPath
 * Slot activated when mpGDBPathBrowseButton clicked signal is raised.\n
 * Allows user to select the GDB path.
 */
void DebuggerConfigurationPage::browseGDBPath() {
    std::cout << "void DebuggerConfigurationPage::browseGDBPath()" << std::endl;
}

/*!
 * \brief DebuggerConfigurationPage::saveDebugConfiguration
 * Slot activated when mpApplyButton clicked signal is raised.\n
 * Saves the debug configuration.
 * \return
 */
bool DebuggerConfigurationPage::saveDebugConfiguration() {
    std::cout << "bool DebuggerConfigurationPage::saveDebugConfiguration()" << std::endl;
    return false;
}

/*!
 * \brief DebuggerConfigurationPage::resetDebugConfiguration
 * Slot activated when mpResetButton clicked signal is raised.\n
 * Resets the debug configuration state back to original.
 */
void DebuggerConfigurationPage::resetDebugConfiguration() {
    std::cout << "void DebuggerConfigurationPage::resetDebugConfiguration()" << std::endl;
}

/*!
 * \class DebuggerConfigurationsDialog
 * \brief Provides interface for creating and managing the debug configurations.
 */
/*!
 * \brief DebuggerConfigurationsDialog::DebuggerConfigurationsDialog
 * \param pParent
 */
DebuggerConfigurationsDialog::DebuggerConfigurationsDialog(QWidget *pParent)
  : QDialog(pParent)
{
  setWindowTitle(QString(Helper::applicationName).append(" - ").append(Helper::debugConfigurations));
  setAttribute(Qt::WA_DeleteOnClose);
  // create tool buttons
  mpNewToolButton = new QToolButton;
  mpNewToolButton->setIcon( QIcon(":/Resources/icons/new.svg"));
  mpNewToolButton->setToolTip(tr("New Configuration"));
  mpNewToolButton->setAutoRaise(true);
  connect(mpNewToolButton, SIGNAL(clicked()), SLOT(newConfiguration()));
  mpDeleteToolButton = new QToolButton;
  mpDeleteToolButton->setIcon( QIcon(":/Resources/icons/delete.svg"));
  mpDeleteToolButton->setToolTip(tr("Delete Configuration"));
  mpDeleteToolButton->setAutoRaise(true);
  connect(mpDeleteToolButton, SIGNAL(clicked()), SLOT(removeConfiguration()));
  // create status bar
  mpStatusBar = new QStatusBar;
  mpStatusBar->setObjectName("ModelStatusBar");
  mpStatusBar->setSizeGripEnabled(false);
  mpStatusBar->addPermanentWidget(mpNewToolButton, 0);
  mpStatusBar->addPermanentWidget(mpDeleteToolButton, 0);
  mpStatusBar->addPermanentWidget(new QLabel, 1);
  // configurations list
  mpConfigurationsListWidget = new QListWidget;
  mpConfigurationsListWidget->setItemDelegate(new ItemDelegate(mpConfigurationsListWidget));
  mpConfigurationsListWidget->setTextElideMode(Qt::ElideMiddle);
  connect(mpConfigurationsListWidget, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
          SLOT(changeConfigurationPage(QListWidgetItem*,QListWidgetItem*)));
  // configuration pages
  mpConfigurationPagesWidget = new QStackedWidget;
  /* Configuration settings Page Splitter */
  mpConfigurationsSplitter = new QSplitter;
  mpConfigurationsSplitter->setVisible(false);
  mpConfigurationsSplitter->setChildrenCollapsible(false);
  mpConfigurationsSplitter->setHandleWidth(4);
  mpConfigurationsSplitter->setContentsMargins(0, 0, 0, 0);
  mpConfigurationsSplitter->setOrientation(Qt::Horizontal);
  mpConfigurationsSplitter->addWidget(mpConfigurationsListWidget);
  mpConfigurationsSplitter->addWidget(mpConfigurationPagesWidget);
  mpConfigurationsSplitter->setStretchFactor(0, 1);
  mpConfigurationsSplitter->setStretchFactor(1, 2);
  // buttons
  mpSaveButton = new QPushButton(Helper::save);
  mpSaveButton->setToolTip(tr("Saves all the debug configurations"));
  connect(mpSaveButton, SIGNAL(clicked()), this, SLOT(saveAllConfigurations()));
  mpSaveAndDebugButton = new QPushButton(tr("Save && Debug"));
  mpSaveAndDebugButton->setToolTip(tr("Saves all the debug configurations and starts debugging the active debug configuration"));
  connect(mpSaveAndDebugButton, SIGNAL(clicked()), this, SLOT(saveAllConfigurationsAndDebugConfiguration()));
  mpCancelButton = new QPushButton(Helper::cancel);
  connect(mpCancelButton, SIGNAL(clicked()), SLOT(reject()));
  // adds debugger buttons to the button box
  mpConfigurationsButtonBox = new QDialogButtonBox(Qt::Horizontal);
  mpConfigurationsButtonBox->setVisible(false);
  mpConfigurationsButtonBox->addButton(mpSaveButton, QDialogButtonBox::ActionRole);
  mpConfigurationsButtonBox->addButton(mpSaveAndDebugButton, QDialogButtonBox::ActionRole);
  mpConfigurationsButtonBox->addButton(mpCancelButton, QDialogButtonBox::ActionRole);
  // set the layout
  QGridLayout *pMainLayout = new QGridLayout;
  pMainLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  pMainLayout->setContentsMargins(0, 0, 0, 2);
  pMainLayout->addWidget(mpStatusBar, 0, 0);
  pMainLayout->addWidget(mpConfigurationsSplitter, 1, 0);
  pMainLayout->addWidget(mpConfigurationsButtonBox, 2, 0, 1, 1, Qt::AlignRight);
  setLayout(pMainLayout);
  // read the saved debug configurations
  readConfigurations();
}

/*!
 * \brief DebuggerConfigurationsDialog::getUniqueName
 * Returns a unique name for debugger configuration.
 * \param name
 * \param number
 * \return
 */
QString DebuggerConfigurationsDialog::getUniqueName(QString name, int number) {
    std::cout << "QString DebuggerConfigurationsDialog::getUniqueName(QString name, int number)" << std::endl;
    return QString();
}

/*!
 * \brief DebuggerConfigurationsDialog::readConfigurations
 * Reads the list of debugger configurations setting from the settings file.
 */
void DebuggerConfigurationsDialog::readConfigurations() {
    std::cout << "void DebuggerConfigurationsDialog::readConfigurations()" << std::endl;
}

/*!
 * \brief DebuggerConfigurationsDialog::getDebuggerConfigurationPage
 * Returns the DebuggerConfigurationPage
 * \param configurationName
 * \return
 */
DebuggerConfigurationPage* DebuggerConfigurationsDialog::getDebuggerConfigurationPage(QString configurationName) {
    std::cout << "DebuggerConfigurationPage* DebuggerConfigurationsDialog::getDebuggerConfigurationPage(QString configurationName)" << std::endl;
    return nullptr;
}

/*!
 * \brief DebuggerConfigurationsDialog::runConfiguration
 * Runs the debug configuration.
 * \param pDebuggerConfigurationPage
 */
void DebuggerConfigurationsDialog::runConfiguration(DebuggerConfigurationPage *pDebuggerConfigurationPage) {
    std::cout << "void DebuggerConfigurationsDialog::runConfiguration(DebuggerConfigurationPage *pDebuggerConfigurationPage)" << std::endl;
}

/*!
 * \brief DebuggerConfigurationsDialog::saveAllConfigurationsHelper
 * Saves all the debug configurations to the settings file.
 * \return true if all debug configurations are saved successfully.
 */
bool DebuggerConfigurationsDialog::saveAllConfigurationsHelper() {
    std::cout << "bool DebuggerConfigurationsDialog::saveAllConfigurationsHelper()" << std::endl;
    return false;
}

/*!
 * \brief DebuggerConfigurationsDialog::newConfiguration
 * Creates a new debugger configuration.
 */
void DebuggerConfigurationsDialog::newConfiguration() {
    std::cout << "void DebuggerConfigurationsDialog::newConfiguration()" << std::endl;
}

/*!
 * \brief DebuggerConfigurationsDialog::removeConfiguration
 * Removes the debugger configuration.
 */
void DebuggerConfigurationsDialog::removeConfiguration() {
    std::cout << "void DebuggerConfigurationsDialog::removeConfiguration()" << std::endl;
}

/*!
 * \brief DebuggerConfigurationsDialog::changeConfigurationPage
 * Change the page in DebuggerConfigurationsDialogt when the mpConfigurationsListWidget currentItemChanged Signal is raised.
 * \param current
 * \param previous
 */
void DebuggerConfigurationsDialog::changeConfigurationPage(QListWidgetItem *current, QListWidgetItem *previous) {
    std::cout << "void DebuggerConfigurationsDialog::changeConfigurationPage(QListWidgetItem *current, QListWidgetItem *previous)" << std::endl;
}

/*!
 * \brief DebuggerConfigurationsDialog::saveAllConfigurations
 * Saves all the debug configurations to the settings file.
 */
void DebuggerConfigurationsDialog::saveAllConfigurations() {
    std::cout << "void DebuggerConfigurationsDialog::saveAllConfigurations()" << std::endl;
}

/*!
 * \brief DebuggerConfigurationsDialog::saveAllConfigurationsAndDebugConfiguration
 * Saves all the debug configurations to the settings file.
 * Starts the Algorithmic debugger for the active configuration.
 */
void DebuggerConfigurationsDialog::saveAllConfigurationsAndDebugConfiguration() {
    std::cout << "void DebuggerConfigurationsDialog::saveAllConfigurationsAndDebugConfiguration()" << std::endl;
}
