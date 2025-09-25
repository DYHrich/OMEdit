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

#include <QLibrary>
#include <iostream>
#include <QDebug>

#include "ProcessListModel.h"

#ifdef Q_OS_WIN
// Enable Win API of XP SP1 and later
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0502
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>

/*!
  Resolve QueryFullProcessImageNameW out of kernel32.dll due to incomplete MinGW import libs and it not being present on Windows XP.
  */
static BOOL queryFullProcessImageName(HANDLE h, DWORD flags, LPWSTR buffer, DWORD *size) {
    std::cout << "static BOOL queryFullProcessImageName(HANDLE h, DWORD flags, LPWSTR buffer, DWORD *size)" << std::endl;
    return BOOL();
}

/*!
  Reads the process name.
  \param processId - the process to read.
  \return the process name.
  */
static QString imageName(DWORD processId) {
    std::cout << "static QString imageName(DWORD processId)" << std::endl;
    return QString();
}

/*!
  \class ProcessListModel
  \brief Contains the list of processes.
  */
/*!
  \param pParent -  the pointer to QObject
  */
ProcessListModel::ProcessListModel(QObject *pParent)
  : QAbstractItemModel(pParent), mSelfProcessId(GetCurrentProcessId())
{

}

/*!
  Returns the list of local processes.
  */
QList<ProcessItem> ProcessListModel::getLocalProcesses() {
    std::cout << "QList<ProcessItem> ProcessListModel::getLocalProcesses()" << std::endl;
    return QList<ProcessItem>();
}
#endif //Q_OS_WIN

#ifdef Q_OS_UNIX
#include <QProcess>
#include <QDir>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*!
  \class ProcessListModel
  \brief Contains the list of processes.
  */
/*!
  \param omcProcessId - the process Id of OMEdit's OMC instance.
  \param pParent -  the pointer to QObject
  */
ProcessListModel::ProcessListModel(QObject *pParent)
  : QAbstractItemModel(pParent), mSelfProcessId(getpid())
{

}

static bool isUnixProcessId(const QString &procname) {
    std::cout << "static bool isUnixProcessId(const QString &procname)" << std::endl;
    return false;
}

/*!
  Get the  UNIX processes by reading "/proc". Default to ps if it does not exist.
  */
static const char procDirC[] = "/proc/";

static QList<ProcessItem> getLocalProcessesUsingProc(const QDir &procDir) {
    std::cout << "static QList<ProcessItem> getLocalProcessesUsingProc(const QDir &procDir)" << std::endl;
    return QList<ProcessItem>();
}

/*!
  Get the UNIX processes by running ps
  */
static QList<ProcessItem> getLocalProcessesUsingPs() {
    std::cout << "static QList<ProcessItem> getLocalProcessesUsingPs()" << std::endl;
    return QList<ProcessItem>();
}

QList<ProcessItem> ProcessListModel::getLocalProcesses() {
    std::cout << "QList<ProcessItem> ProcessListModel::getLocalProcesses()" << std::endl;
    return QList<ProcessItem>();
}
#endif // Q_OS_UNIX

QString ProcessListModel::processIdAt(const QModelIndex &index) const {
    std::cout << "QString ProcessListModel::processIdAt(const QModelIndex &index) const" << std::endl;
    return QString();
}

/*!
  Refreshes the list of processes.
  */
void ProcessListModel::updateProcessList() {
    std::cout << "void ProcessListModel::updateProcessList()" << std::endl;
}

QModelIndex ProcessListModel::index(int row, int column, const QModelIndex &parent) const {
    std::cout << "QModelIndex ProcessListModel::index(int row, int column, const QModelIndex &parent) const" << std::endl;
    return QModelIndex();
}

int ProcessListModel::rowCount(const QModelIndex &parent) const {
    std::cout << "int ProcessListModel::rowCount(const QModelIndex &parent) const" << std::endl;
    return 0;
}

int ProcessListModel::columnCount(const QModelIndex &parent) const {
    std::cout << "int ProcessListModel::columnCount(const QModelIndex &parent) const" << std::endl;
    return 0;
}

QVariant ProcessListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    std::cout << "QVariant ProcessListModel::headerData(int section, Qt::Orientation orientation, int role) const" << std::endl;
    return QVariant();
}

QVariant ProcessListModel::data(const QModelIndex &index, int role) const {
    std::cout << "QVariant ProcessListModel::data(const QModelIndex &index, int role) const" << std::endl;
    return QVariant();
}

Qt::ItemFlags ProcessListModel::flags(const QModelIndex &index) const {
    std::cout << "ItemFlags ProcessListModel::flags(const QModelIndex &index) const" << std::endl;
    return Qt::ItemFlags();
}

QModelIndex ProcessListModel::parent(const QModelIndex &) const {
    std::cout << "QModelIndex ProcessListModel::parent(const QModelIndex &) const" << std::endl;
    return QModelIndex();
}

bool ProcessListModel::hasChildren(const QModelIndex &parent) const {
    std::cout << "bool ProcessListModel::hasChildren(const QModelIndex &parent) const" << std::endl;
    return false;
}

/*!
  \class ProcessListFilterModel
  \brief Interface for sorting and filtering the processes.
  */
ProcessListFilterModel::ProcessListFilterModel()
  : QSortFilterProxyModel(0)
{
  setFilterCaseSensitivity(Qt::CaseInsensitive);
  setDynamicSortFilter(true);
  setFilterKeyColumn(-1);
}

bool ProcessListFilterModel::lessThan(const QModelIndex &left, const QModelIndex &right) const {
    std::cout << "bool ProcessListFilterModel::lessThan(const QModelIndex &left, const QModelIndex &right) const" << std::endl;
    return false;
}
