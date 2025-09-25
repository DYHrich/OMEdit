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

#include "BreakpointsWidget.h"
#include <iostream>
#include "Debugger/GDB/GDBAdapter.h"
#include "BreakpointDialog.h"
#include "Debugger/GDB/CommandFactory.h"
#include "Util/Helper.h"
#include "Modeling/ModelWidgetContainer.h"
#include "Modeling/ItemDelegate.h"

#include <QGridLayout>
#include <QMenu>

/*!
 * \class BreakPointsWidget
 * \brief A widget containing BreakpointsTreeView.
 */
/*!
 * \brief BreakpointsWidget::BreakpointsWidget
 * \param pParent
 */
BreakpointsWidget::BreakpointsWidget(QWidget *pParent)
  : QWidget(pParent)
{
  /* Breakpoints Tree view */
  mpBreakpointsTreeView = new BreakpointsTreeView(this);
  mpBreakpointsTreeModel = new BreakpointsTreeModel(mpBreakpointsTreeView);
  mpBreakpointsTreeView->setModel(mpBreakpointsTreeModel);
  /* set layout */
  QGridLayout *pMainLayout = new QGridLayout;
  pMainLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  pMainLayout->setContentsMargins(0, 0, 0, 0);
  pMainLayout->setSpacing(0);
  pMainLayout->addWidget(mpBreakpointsTreeView, 0, 0);
  setLayout(pMainLayout);
}

/*!
  \class BreakpointsTreeView
  \brief A tree view of breakpoints.
  */
/*!
  \param pBreakPointsWidget - pointer to BreakpointsWidget
  */
BreakpointsTreeView::BreakpointsTreeView(BreakpointsWidget *pBreakPointsWidget)
  : QTreeView(pBreakPointsWidget)
{
  mpBreakpointsWidget = pBreakPointsWidget;
  setItemDelegate(new ItemDelegate(this));
  setTextElideMode(Qt::ElideMiddle);
  setIndentation(0);
  setIconSize(QSize(15, 15));
  setExpandsOnDoubleClick(false);
  setContextMenuPolicy(Qt::CustomContextMenu);
  setUniformRowHeights(true);
  createActions();
  connect(this, SIGNAL(customContextMenuRequested(QPoint)), SLOT(showContextMenu(QPoint)));
  connect(this, SIGNAL(doubleClicked(QModelIndex)), SLOT(breakPointDoubleClicked(QModelIndex)));
}

/*!
  Defines the actions used by the BreakpointsTreeView context menu.
  */
void BreakpointsTreeView::createActions() {
    std::cout << "void BreakpointsTreeView::createActions()" << std::endl;
}

/*!
  Returns the list of selecetd breakpoints.
  */
BreakpointTreeItem* BreakpointsTreeView::getSelectedBreakpointTreeItem() {
    std::cout << "BreakpointTreeItem* BreakpointsTreeView::getSelectedBreakpointTreeItem()" << std::endl;
    return nullptr;
}

/*!
  Slot activated when mpDeleteBreakpointAction triggered signal is raised.\n
  Deletes the breakpoint.
  */
void BreakpointsTreeView::deleteBreakpoint(BreakpointTreeItem *pBreakpointTreeItem) {
    std::cout << "void BreakpointsTreeView::deleteBreakpoint(BreakpointTreeItem *pBreakpointTreeItem)" << std::endl;
}

/*!
  Shows the breakpoint location in the editor.
  Slot activated when mpGotoFileAction triggered signal is raised.
  */
void BreakpointsTreeView::gotoFile() {
    std::cout << "void BreakpointsTreeView::gotoFile()" << std::endl;
}

/*!
  Adds a breakpoint.
  Slot activated when mpAddBreakpointAction triggered signal is raised.
  */
void BreakpointsTreeView::addBreakpoint() {
    std::cout << "void BreakpointsTreeView::addBreakpoint()" << std::endl;
}

/*!
  Edits a breakpoint.
  Slot activated when mpEditBreakpointAction triggered signal is raised.
  */
void BreakpointsTreeView::editBreakpoint() {
    std::cout << "void BreakpointsTreeView::editBreakpoint()" << std::endl;
}

/*!
  Deletes a breakpoint.
  Slot activated when mpDeleteBreakpointAction triggered signal is raised.
  */
void BreakpointsTreeView::deleteBreakpoint() {
    std::cout << "void BreakpointsTreeView::deleteBreakpoint()" << std::endl;
}

/*!
  Delete all a breakpoint.
  Slot activated when mpDeleteAllBreakpointsAction triggered signal is raised.
  */
void BreakpointsTreeView::deleteAllBreakpoints() {
    std::cout << "void BreakpointsTreeView::deleteAllBreakpoints()" << std::endl;
}

/*!
  Shows a context menu when user right click on the Breakpoints tree.
  Slot activated when BreakpointsTreeView::customContextMenuRequested() signal is raised.
  */
void BreakpointsTreeView::showContextMenu(QPoint point) {
    std::cout << "void BreakpointsTreeView::showContextMenu(QPoint point)" << std::endl;
}

/*!
  Slot activated when BreakpointsTreeView::doubleClicked() signal is raised.
  */
void BreakpointsTreeView::breakPointDoubleClicked(const QModelIndex &index) {
    std::cout << "void BreakpointsTreeView::breakPointDoubleClicked(const QModelIndex &index)" << std::endl;
}

/*!
  \class BreakpointsTreeModel
  \brief Contains the list of breakpoints.
  */
/*!
  \param pBreakpointsTreeView - pointer to BreakpointsTreeView
  */
BreakpointsTreeModel::BreakpointsTreeModel(BreakpointsTreeView *pBreakpointsTreeView)
  : QAbstractItemModel(pBreakpointsTreeView)
{
  mpBreakpointsTreeView = pBreakpointsTreeView;
  QVector<QVariant> headers;
  headers << Helper::file << Helper::line;
  mpRootBreakpointTreeItem = new BreakpointTreeItem(headers);
  mpRootBreakpointTreeItem->setIsRootItem(true);
}

/*!
  Deletes the breakpoints.
  */
BreakpointsTreeModel::~BreakpointsTreeModel()
{
  mpRootBreakpointTreeItem->removeChildren();
  delete mpRootBreakpointTreeItem;
}

int BreakpointsTreeModel::columnCount(const QModelIndex &parent) const {
    std::cout << "int BreakpointsTreeModel::columnCount(const QModelIndex &parent) const" << std::endl;
    return 0;
}

int BreakpointsTreeModel::rowCount(const QModelIndex &parent) const {
    std::cout << "int BreakpointsTreeModel::rowCount(const QModelIndex &parent) const" << std::endl;
    return 0;
}

QVariant BreakpointsTreeModel::headerData(int section, Qt::Orientation orientation, int role) const {
    std::cout << "QVariant BreakpointsTreeModel::headerData(int section, Qt::Orientation orientation, int role) const" << std::endl;
    return QVariant();
}

QModelIndex BreakpointsTreeModel::index(int row, int column, const QModelIndex &parent) const {
    std::cout << "QModelIndex BreakpointsTreeModel::index(int row, int column, const QModelIndex &parent) const" << std::endl;
    return QModelIndex();
}

QModelIndex BreakpointsTreeModel::parent(const QModelIndex &index) const {
    std::cout << "QModelIndex BreakpointsTreeModel::parent(const QModelIndex &index) const" << std::endl;
    return QModelIndex();
}

QVariant BreakpointsTreeModel::data(const QModelIndex &index, int role) const {
    std::cout << "QVariant BreakpointsTreeModel::data(const QModelIndex &index, int role) const" << std::endl;
    return QVariant();
}

/*!
  Finds a BreakpointMarker.
  \return BreakpointMarker
  */
BreakpointMarker* BreakpointsTreeModel::findBreakpointMarker(const QString &fileName, int lineNumber) {
    std::cout << "BreakpointMarker* BreakpointsTreeModel::findBreakpointMarker(const QString &fileName, int lineNumber)" << std::endl;
    return nullptr;
}

/*!
  Finds a BreakpointTreeItem
  \param fileName - the breakpoint fileName.
  \param lineNumber - the breakpoint line number.
  \param pRootBreakpointTreeItem - pointer to BreakpointTreeItem.
  */
BreakpointTreeItem* BreakpointsTreeModel::findBreakpointTreeItem(const QString &fileName, int lineNumber, BreakpointTreeItem *pRootBreakpointTreeItem) const {
    std::cout << "BreakpointTreeItem* BreakpointsTreeModel::findBreakpointTreeItem(const QString &fileName, int lineNumber, BreakpointTreeItem *pRootBreakpointTreeItem) const" << std::endl;
    return nullptr;
}

/*!
  Finds the BreakpointTreeItem QModelIndex.
  \return QModelIndex
  */
QModelIndex BreakpointsTreeModel::breakpointTreeItemIndex(const BreakpointTreeItem *pBreakpointTreeItem) const {
    std::cout << "QModelIndex BreakpointsTreeModel::breakpointTreeItemIndex(const BreakpointTreeItem *pBreakpointTreeItem) const" << std::endl;
    return QModelIndex();
}

/*!
  Helper function to find BreakpointTreeItem QModelIndex
  \see BreakpointsTreeModel::breakpointTreeItemIndex
  */
QModelIndex BreakpointsTreeModel::breakpointTreeItemIndexHelper(const BreakpointTreeItem *pBreakpointTreeItem, const BreakpointTreeItem *pParentBreakpointTreeItem, const QModelIndex &parentIndex) const {
    std::cout << "QModelIndex BreakpointsTreeModel::breakpointTreeItemIndexHelper(const BreakpointTreeItem *pBreakpointTreeItem, const BreakpointTreeItem *pParentBreakpointTreeItem, const QModelIndex &parentIndex) const" << std::endl;
    return QModelIndex();
}

/*!
  Inserts a new breakpoint.\n
  Adds the BreakpointMarker to the list.\n
  Inserts the BreakpointTreeItem into BreakpointsTreeView.\n
  If the debugger is running then also inserts the breakpoint in GDB.\n
  \param pBreakpointMarker - pointer to BreakpointMarker
  \param pLibraryTreeItem - pointer LibraryTreeItem
  \param pParentBreakpointTreeItem - pointer BreakpointTreeItem
  */
void BreakpointsTreeModel::insertBreakpoint(BreakpointMarker *pBreakpointMarker, LibraryTreeItem *pLibraryTreeItem, BreakpointTreeItem *pParentBreakpointTreeItem) {
    std::cout << "void BreakpointsTreeModel::insertBreakpoint(BreakpointMarker *pBreakpointMarker, LibraryTreeItem *pLibraryTreeItem, BreakpointTreeItem *pParentBreakpointTreeItem)" << std::endl;
}

/*!
  Updates a breakpoint.
  \param pBreakpointMarker - pointer to BreakpointMarker
  \param lineNumber - new line number for breakpoint.
  */
void BreakpointsTreeModel::updateBreakpoint(BreakpointMarker *pBreakpointMarker, int lineNumber) {
    std::cout << "void BreakpointsTreeModel::updateBreakpoint(BreakpointMarker *pBreakpointMarker, int lineNumber)" << std::endl;
}

/*!
  Updates the breakpoint.\n
  If the debugger is running then enable or disable the breakpoint in GDB.\n
  \param pBreakpointTreeItem - pointer to BreakpointTreeItem
  \param filePath - the breakpoint file location.
  \param lineNumber - the breakpoint line number.
  \param enabled - the breakpoint enabled state.
  */
void BreakpointsTreeModel::updateBreakpoint(BreakpointTreeItem *pBreakpointTreeItem, QString filePath, int lineNumber, bool enabled,
                                            int ignoreCount, QString condition) {
    std::cout << "void BreakpointsTreeModel::updateBreakpoint()" << std::endl;
}

/*!
  Removes the breakpoint.\n
  Removes the BreakpointMarker from the list.\n
  \param pBreakpointMarker - pointer to BreakpointMarker
  */
void BreakpointsTreeModel::removeBreakpoint(BreakpointMarker *pBreakpointMarker) {
    std::cout << "void BreakpointsTreeModel::removeBreakpoint(BreakpointMarker *pBreakpointMarker)" << std::endl;
}

/*!
  Removes the breakpoint from the BreakpointsTreeView.\n
  If the debugger is running then deletes the breakpoint from GDB.\n
  \param pBreakpointTreeItem - pointer to BreakpointTreeItem
  */
void BreakpointsTreeModel::removeBreakpoint(BreakpointTreeItem *pBreakpointTreeItem) {
    std::cout << "void BreakpointsTreeModel::removeBreakpoint(BreakpointTreeItem *pBreakpointTreeItem)" << std::endl;
}

/*!
  \class BreakpointTreeItem
  \brief Contains the information about the breakpoint.
  */
/*!
  \param breakpointItemData - a list of items.\n
  0 -> filePath\n
  1 -> lineNumber
  */
BreakpointTreeItem::BreakpointTreeItem(const QVector<QVariant> &breakpointItemData, LibraryTreeItem *pLibraryTreeItem,
                                       BreakpointTreeItem *pParent)
  : mIsRootItem(false)
{
  mpLibraryTreeItem = pLibraryTreeItem;
  mpParentBreakpointTreeItem = pParent;
  mFilePath = breakpointItemData[0].toString();
  mLineNumber = breakpointItemData[1].toString();
  mBreakpointId = "";
  mEnabled = true;
  mIgnoreCount = 0;
  mCondition = "";
}

/*!
  Deletes the breakpoint and its children.
  */
BreakpointTreeItem::~BreakpointTreeItem()
{
  qDeleteAll(mChildren);
  mChildren.clear();
}

/*!
  Returns the enable or disable icon for breakpoint.
  */
QIcon BreakpointTreeItem::getBreakpointTreeItemIcon() const {
    std::cout << "QIcon BreakpointTreeItem::getBreakpointTreeItemIcon() const" << std::endl;
    return QIcon();
}

void BreakpointTreeItem::insertChild(int position, BreakpointTreeItem *pBreakpointTreeItem) {
    std::cout << "void BreakpointTreeItem::insertChild(int position, BreakpointTreeItem *pBreakpointTreeItem)" << std::endl;
}

BreakpointTreeItem* BreakpointTreeItem::child(int row) {
    std::cout << "BreakpointTreeItem* BreakpointTreeItem::child(int row)" << std::endl;
    return nullptr;
}

void BreakpointTreeItem::removeChildren() {
    std::cout << "void BreakpointTreeItem::removeChildren()" << std::endl;
}

void BreakpointTreeItem::removeChild(BreakpointTreeItem *pBreakpointTreeItem) {
    std::cout << "void BreakpointTreeItem::removeChild(BreakpointTreeItem *pBreakpointTreeItem)" << std::endl;
}

QVariant BreakpointTreeItem::data(int column, int role) const {
    std::cout << "QVariant BreakpointTreeItem::data(int column, int role) const" << std::endl;
    return QVariant();
}

int BreakpointTreeItem::row() const {
    std::cout << "int BreakpointTreeItem::row() const" << std::endl;
    return 0;
}
