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

#include "Debugger/Locals/LocalsWidget.h"
#include <iostream>
#include "MainWindow.h"
#include "Modeling/LibraryTreeWidget.h"
#include "Modeling/ItemDelegate.h"
#include "Debugger/GDB/GDBAdapter.h"
#include "Debugger/StackFrames/StackFramesWidget.h"
#include "Debugger/Locals/ModelicaValue.h"
#include "Debugger/GDB/CommandFactory.h"
#include "Util/Helper.h"

#include <QSplitter>
#include <QGridLayout>
#include <QHBoxLayout>

/*!
 * \class LocalsTreeItem
 * \brief Contains the information about the local variable.
 */
/*!
 * \brief LocalsTreeItem::LocalsTreeItem
 * \param localItemData - a list of items.\n
 * 0 -> name\n
 * 1 -> displayName\n
 * 2 -> type\n
 * 3 -> value
 * \param localItemData
 * \param pLocalsTreeModel
 * \param pLocalsTreeItem
 */
LocalsTreeItem::LocalsTreeItem(const QVector<QVariant> &localItemData, LocalsTreeModel *pLocalsTreeModel, LocalsTreeItem *pLocalsTreeItem)
  : QObject(pLocalsTreeModel)
{
  mpLocalsTreeModel = pLocalsTreeModel;
  mpParentLocalsTreeItem = pLocalsTreeItem;
  mpModelicaValue = 0;
  setName(localItemData[0].toString());
  setDisplayName(localItemData[1].toString());
  setNameStructure("");
  setType(localItemData[2].toString());
  /* if the item is a root item then its just a header */
  if (!mpParentLocalsTreeItem) {
    setDisplayName(getName());
    setDisplayType(getType());
    setDisplayValue(localItemData[3].toString());
  } else if (mpParentLocalsTreeItem == mpLocalsTreeModel->getRootLocalsTreeItem()) {
    /* if the item is a top level item then we need to fetch the type and value. */
    setDisplayType("");
    retrieveType();
    setDisplayValue("");
    retrieveValue();
  } else {
    /* child node */
    setDisplayName(getDisplayName());
    setDisplayType(getType());
    setDisplayValue("");
    retrieveValue();
  }
  setValueChanged(false);
  setExpanded(false);
}

LocalsTreeItem::~LocalsTreeItem()
{
  qDeleteAll(mChildren);
  mChildren.clear();
}

/*!
 * \brief LocalsTreeItem::isCoreType
 * Returns true if is core type.
 * \return
 */
bool LocalsTreeItem::isCoreType() {
    std::cout << "bool LocalsTreeItem::isCoreType()" << std::endl;
    return false;
}

/*!
 * \brief LocalsTreeItem::isCoreTypeExceptString
 * Returns true if is core type except STRING.
 * \return
 */
bool LocalsTreeItem::isCoreTypeExceptString() {
    std::cout << "bool LocalsTreeItem::isCoreTypeExceptString()" << std::endl;
    return false;
}

void LocalsTreeItem::insertChild(int position, LocalsTreeItem *pLocalsTreeItem) {
    std::cout << "void LocalsTreeItem::insertChild(int position, LocalsTreeItem *pLocalsTreeItem)" << std::endl;
}

LocalsTreeItem* LocalsTreeItem::child(int row) {
    std::cout << "LocalsTreeItem* LocalsTreeItem::child(int row)" << std::endl;
    return nullptr;
}

void LocalsTreeItem::removeChildren() {
    std::cout << "void LocalsTreeItem::removeChildren()" << std::endl;
}

void LocalsTreeItem::removeChild(LocalsTreeItem *pLocalsTreeItem) {
    std::cout << "void LocalsTreeItem::removeChild(LocalsTreeItem *pLocalsTreeItem)" << std::endl;
}

int LocalsTreeItem::columnCount() const {
    std::cout << "int LocalsTreeItem::columnCount() const" << std::endl;
    return 0;
}

QVariant LocalsTreeItem::data(int column, int role) const {
    std::cout << "QVariant LocalsTreeItem::data(int column, int role) const" << std::endl;
    return QVariant();
}

int LocalsTreeItem::row() const {
    std::cout << "int LocalsTreeItem::row() const" << std::endl;
    return 0;
}

LocalsTreeItem* LocalsTreeItem::parent() {
    std::cout << "LocalsTreeItem* LocalsTreeItem::parent()" << std::endl;
    return nullptr;
}

void LocalsTreeItem::retrieveType() {
    std::cout << "void LocalsTreeItem::retrieveType()" << std::endl;
}

void LocalsTreeItem::retrieveModelicaMetaType() {
    std::cout << "void LocalsTreeItem::retrieveModelicaMetaType()" << std::endl;
}

/*!
 * \brief LocalsTreeItem::retrieveValue
 * Gets the value of the LocalsTreeItem using CommandFactory::anyString
 */
void LocalsTreeItem::retrieveValue() {
    std::cout << "void LocalsTreeItem::retrieveValue()" << std::endl;
}

/*!
 * \brief LocalsTreeItem::setModelicaMetaType
 * Sets the type of the LocalsTreeItem and sends the command to retireve value.
 * \param type
 */
void LocalsTreeItem::setModelicaMetaType(QString type) {
    std::cout << "void LocalsTreeItem::setModelicaMetaType(QString type)" << std::endl;
}

void LocalsTreeItem::setValue(QString value) {
    std::cout << "void LocalsTreeItem::setValue(QString value)" << std::endl;
}

void LocalsTreeItem::retrieveLocalChildren() {
    std::cout << "void LocalsTreeItem::retrieveLocalChildren()" << std::endl;
}

LocalsTreeModel::LocalsTreeModel(LocalsWidget *pLocalsWidget)
  : QAbstractItemModel(pLocalsWidget)
{
  mpLocalsWidget = pLocalsWidget;
  QVector<QVariant> headers;
  headers << tr("Name") << "" << tr("Type") << tr("Value");
  mpRootLocalsTreeItem = new LocalsTreeItem(headers, this, 0);
}

int LocalsTreeModel::columnCount(const QModelIndex &parent) const {
    std::cout << "int LocalsTreeModel::columnCount(const QModelIndex &parent) const" << std::endl;
    return 0;
}

int LocalsTreeModel::rowCount(const QModelIndex &parent) const {
    std::cout << "int LocalsTreeModel::rowCount(const QModelIndex &parent) const" << std::endl;
    return 0;
}

bool LocalsTreeModel::hasChildren(const QModelIndex &parent) const {
    std::cout << "bool LocalsTreeModel::hasChildren(const QModelIndex &parent) const" << std::endl;
    return false;
}

bool LocalsTreeModel::canFetchMore(const QModelIndex &parent) const {
    std::cout << "bool LocalsTreeModel::canFetchMore(const QModelIndex &parent) const" << std::endl;
    return false;
}

QVariant LocalsTreeModel::headerData(int section, Qt::Orientation orientation, int role) const {
    std::cout << "QVariant LocalsTreeModel::headerData(int section, Qt::Orientation orientation, int role) const" << std::endl;
    return QVariant();
}

QModelIndex LocalsTreeModel::index(int row, int column, const QModelIndex &parent) const {
    std::cout << "QModelIndex LocalsTreeModel::index(int row, int column, const QModelIndex &parent) const" << std::endl;
    return QModelIndex();
}

QModelIndex LocalsTreeModel::parent(const QModelIndex &index) const {
    std::cout << "QModelIndex LocalsTreeModel::parent(const QModelIndex &index) const" << std::endl;
    return QModelIndex();
}

QVariant LocalsTreeModel::data(const QModelIndex &index, int role) const {
    std::cout << "QVariant LocalsTreeModel::data(const QModelIndex &index, int role) const" << std::endl;
    return QVariant();
}

LocalsTreeItem* LocalsTreeModel::findLocalsTreeItem(const QString &name, LocalsTreeItem *root) const {
    std::cout << "LocalsTreeItem* LocalsTreeModel::findLocalsTreeItem(const QString &name, LocalsTreeItem *root) const" << std::endl;
    return nullptr;
}

QModelIndex LocalsTreeModel::localsTreeItemIndex(const LocalsTreeItem *pLocalsTreeItem) const {
    std::cout << "QModelIndex LocalsTreeModel::localsTreeItemIndex(const LocalsTreeItem *pLocalsTreeItem) const" << std::endl;
    return QModelIndex();
}

QModelIndex LocalsTreeModel::localsTreeItemIndexHelper(const LocalsTreeItem *pLocalsTreeItem, const LocalsTreeItem *pParentLocalsTreeItem,
                                                       const QModelIndex &parentIndex) const {
    std::cout << "QModelIndex LocalsTreeModel::localsTreeItemIndexHelper() const" << std::endl;
    return QModelIndex();
}

void LocalsTreeModel::insertLocalItemData(const QVector<QVariant> &localItemData, LocalsTreeItem *pParentLocalsTreeItem) {
    std::cout << "void LocalsTreeModel::insertLocalItemData(const QVector<QVariant> &localItemData, LocalsTreeItem *pParentLocalsTreeItem)" << std::endl;
}

void LocalsTreeModel::insertLocalsList(const QList<QVector<QVariant> > &locals) {
    std::cout << "void LocalsTreeModel::insertLocalsList(const QList<QVector<QVariant> > &locals)" << std::endl;
}

void LocalsTreeModel::removeLocalItem(LocalsTreeItem *pLocalsTreeItem) {
    std::cout << "void LocalsTreeModel::removeLocalItem(LocalsTreeItem *pLocalsTreeItem)" << std::endl;
}

void LocalsTreeModel::removeLocalItems() {
    std::cout << "void LocalsTreeModel::removeLocalItems()" << std::endl;
}

/*!
 * \brief LocalsTreeModel::updateLocalsTreeItem
 * Triggers a view update for the LocalsTreeItem in the Locals Browser.
 * \param pLocalsTreeItem
 */
void LocalsTreeModel::updateLocalsTreeItem(LocalsTreeItem *pLocalsTreeItem) {
    std::cout << "void LocalsTreeModel::updateLocalsTreeItem(LocalsTreeItem *pLocalsTreeItem)" << std::endl;
}

/*!
 * \class LocalsTreeProxyModel
 * \brief A sort filter proxy model for Locals Browser.
 */
/*!
 * \brief LocalsTreeProxyModel::LocalsTreeProxyModel
 * \param parent
 */
LocalsTreeProxyModel::LocalsTreeProxyModel(QObject *parent)
  : QSortFilterProxyModel(parent)
{
}

/*!
 * \brief LocalsTreeProxyModel::lessThan
 * Sorts the LocalsTreeItems except for members of a record type.
 * \param left
 * \param right
 * \return
 */
bool LocalsTreeProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const {
    std::cout << "bool LocalsTreeProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const" << std::endl;
    return false;
}

LocalsTreeView::LocalsTreeView(LocalsWidget *pLocalsWidget)
  : QTreeView(pLocalsWidget)
{
  mpLocalsWidget = pLocalsWidget;
  setItemDelegate(new ItemDelegate(this));
  setTextElideMode(Qt::ElideMiddle);
  setIndentation(Helper::treeIndentation);
  setContextMenuPolicy(Qt::CustomContextMenu);
  setExpandsOnDoubleClick(false);
  setSortingEnabled(true);
  sortByColumn(0, Qt::AscendingOrder);
  setUniformRowHeights(true);
}

/*!
 * \class LocalsWidget
 * \brief A widget containing local variables with type and values while debugging.
 */
/*!
 * \brief LocalsWidget::LocalsWidget
 * \param pParent
 */
LocalsWidget::LocalsWidget(QWidget *pParent)
  : QWidget(pParent)
{
  /* Locals Tree View */
  mpLocalsTreeView = new LocalsTreeView(this);
  mpLocalsTreeModel = new LocalsTreeModel(this);
  mpLocalsTreeProxyModel = new LocalsTreeProxyModel;
  mpLocalsTreeProxyModel->setDynamicSortFilter(true);
  mpLocalsTreeProxyModel->setSourceModel(mpLocalsTreeModel);
  mpLocalsTreeView->setModel(mpLocalsTreeProxyModel);
  connect(mpLocalsTreeView, SIGNAL(expanded(QModelIndex)), SLOT(localsTreeItemExpanded(QModelIndex)));
  /* Local value viewer */
  mpLocalValueViewer = new QPlainTextEdit;
  connect(mpLocalsTreeView->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), SLOT(showLocalValue(QModelIndex,QModelIndex)));
  QSplitter *pLocalsSplitter = new QSplitter;
  pLocalsSplitter->setOrientation(Qt::Vertical);
  pLocalsSplitter->setChildrenCollapsible(false);
  pLocalsSplitter->setHandleWidth(4);
  pLocalsSplitter->addWidget(mpLocalsTreeView);
  pLocalsSplitter->addWidget(mpLocalValueViewer);
  pLocalsSplitter->setStretchFactor(0, 1);
  pLocalsSplitter->setStretchFactor(1, 0);
  /* set layout */
  QGridLayout *pMainLayout = new QGridLayout;
  pMainLayout->setAlignment(Qt::AlignTop);
  pMainLayout->setContentsMargins(0, 0, 1, 0);
  pMainLayout->addWidget(pLocalsSplitter, 0, 0);
  setLayout(pMainLayout);
  connect(GDBAdapter::instance(), SIGNAL(GDBProcessFinished()), SLOT(handleGDBProcessFinished()));
}

void LocalsWidget::localsTreeItemExpanded(QModelIndex index) {
    std::cout << "void LocalsWidget::localsTreeItemExpanded(QModelIndex index)" << std::endl;
}

void LocalsWidget::showLocalValue(QModelIndex currentIndex, QModelIndex previousIndex) {
    std::cout << "void LocalsWidget::showLocalValue(QModelIndex currentIndex, QModelIndex previousIndex)" << std::endl;
}

/*!
 * \brief LocalsWidget::handleGDBProcessFinished
 * Slot activated when GDBProcessFinished signal of GDBAdapter is raised.
 * Clears the LocalsTreeView by removing all the items.
 */
void LocalsWidget::handleGDBProcessFinished() {
    std::cout << "void LocalsWidget::handleGDBProcessFinished()" << std::endl;
}
