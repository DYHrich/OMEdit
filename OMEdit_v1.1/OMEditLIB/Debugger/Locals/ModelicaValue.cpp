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

#include "Debugger/Locals/ModelicaValue.h"
#include <iostream>
#include "MainWindow.h"
#include "Debugger/GDB/GDBAdapter.h"
#include "Debugger/StackFrames/StackFramesWidget.h"
#include "Debugger/Locals/LocalsWidget.h"
#include "Debugger/GDB/CommandFactory.h"
#include "Util/Helper.h"

ModelicaValue::ModelicaValue(LocalsTreeItem *pLocalsTreeItem)
  : QObject(pLocalsTreeItem)
{
  mpLocalsTreeItem = pLocalsTreeItem;
  mValue = "";
}

ModelicaCoreValue::ModelicaCoreValue(LocalsTreeItem *pLocalsTreeItem)
  : ModelicaValue(pLocalsTreeItem)
{

}

QString ModelicaCoreValue::getValueString() {
    std::cout << "QString ModelicaCoreValue::getValueString()" << std::endl;
    return QString();
}

ModelicaRecordValue::ModelicaRecordValue(LocalsTreeItem *pLocalsTreeItem)
  : ModelicaValue(pLocalsTreeItem)
{
  mRecordElements = 0;
}

void ModelicaRecordValue::retrieveChildrenSize() {
    std::cout << "void ModelicaRecordValue::retrieveChildrenSize()" << std::endl;
}

QString ModelicaRecordValue::getValueString() {
    std::cout << "QString ModelicaRecordValue::getValueString()" << std::endl;
    return QString();
}

void ModelicaRecordValue::setChildrenSize(QString size) {
    std::cout << "void ModelicaRecordValue::setChildrenSize(QString size)" << std::endl;
}

void ModelicaRecordValue::retrieveChildren() {
    std::cout << "void ModelicaRecordValue::retrieveChildren()" << std::endl;
}

ModelicaListValue::ModelicaListValue(LocalsTreeItem *pLocalsTreeItem)
  : ModelicaValue(pLocalsTreeItem)
{
  mListLength = 0;
}

void ModelicaListValue::retrieveChildrenSize() {
    std::cout << "void ModelicaListValue::retrieveChildrenSize()" << std::endl;
}

QString ModelicaListValue::getValueString() {
    std::cout << "QString ModelicaListValue::getValueString()" << std::endl;
    return QString();
}

void ModelicaListValue::setChildrenSize(QString size) {
    std::cout << "void ModelicaListValue::setChildrenSize(QString size)" << std::endl;
}

void ModelicaListValue::retrieveChildren() {
    std::cout << "void ModelicaListValue::retrieveChildren()" << std::endl;
}

ModelicaOptionValue::ModelicaOptionValue(LocalsTreeItem *pLocalsTreeItem)
  : ModelicaValue(pLocalsTreeItem)
{
  mIsOptionNone = true;
}

void ModelicaOptionValue::retrieveChildrenSize() {
    std::cout << "void ModelicaOptionValue::retrieveChildrenSize()" << std::endl;
}

QString ModelicaOptionValue::getValueString() {
    std::cout << "QString ModelicaOptionValue::getValueString()" << std::endl;
    return QString();
}

void ModelicaOptionValue::setChildrenSize(QString size) {
    std::cout << "void ModelicaOptionValue::setChildrenSize(QString size)" << std::endl;
}

void ModelicaOptionValue::retrieveChildren() {
    std::cout << "void ModelicaOptionValue::retrieveChildren()" << std::endl;
}

ModelicaTupleValue::ModelicaTupleValue(LocalsTreeItem *pLocalsTreeItem)
  : ModelicaValue(pLocalsTreeItem)
{
  mTupleElements = 0;
}

void ModelicaTupleValue::retrieveChildrenSize() {
    std::cout << "void ModelicaTupleValue::retrieveChildrenSize()" << std::endl;
}

QString ModelicaTupleValue::getValueString() {
    std::cout << "QString ModelicaTupleValue::getValueString()" << std::endl;
    return QString();
}

void ModelicaTupleValue::setChildrenSize(QString size) {
    std::cout << "void ModelicaTupleValue::setChildrenSize(QString size)" << std::endl;
}

void ModelicaTupleValue::retrieveChildren() {
    std::cout << "void ModelicaTupleValue::retrieveChildren()" << std::endl;
}

MetaModelicaArrayValue::MetaModelicaArrayValue(LocalsTreeItem *pLocalsTreeItem)
  : ModelicaValue(pLocalsTreeItem)
{
  mArrayLength = 0;
}

void MetaModelicaArrayValue::retrieveChildrenSize() {
    std::cout << "void MetaModelicaArrayValue::retrieveChildrenSize()" << std::endl;
}

QString MetaModelicaArrayValue::getValueString() {
    std::cout << "QString MetaModelicaArrayValue::getValueString()" << std::endl;
    return QString();
}

void MetaModelicaArrayValue::setChildrenSize(QString size) {
    std::cout << "void MetaModelicaArrayValue::setChildrenSize(QString size)" << std::endl;
}

void MetaModelicaArrayValue::retrieveChildren() {
    std::cout << "void MetaModelicaArrayValue::retrieveChildren()" << std::endl;
}
