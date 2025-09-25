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

#include "BreakpointMarker.h"
#include <iostream>
#include "BreakpointsWidget.h"
#include "Editors/BaseEditor.h"

BreakpointMarker::BreakpointMarker(const QString &fileName, int lineNumber, BreakpointsTreeModel *pBreakpointsTreeModel)
    : ITextMark()
    , mpBreakpointsTreeModel(pBreakpointsTreeModel)
    , mpFileName(fileName)
    , mpLineNumber(lineNumber)
    , mEnabled(true)
    , mIgnoreCount(0)
    , mCondition("")
{

}

QIcon BreakpointMarker::icon() const {
    std::cout << "QIcon BreakpointMarker::icon() const" << std::endl;
    return QIcon();
}

void BreakpointMarker::updateLineNumber(int lineNumber) {
    std::cout << "void BreakpointMarker::updateLineNumber(int lineNumber)" << std::endl;
}

void BreakpointMarker::updateBlock(const QTextBlock &block) {
    std::cout << "void BreakpointMarker::updateBlock(const QTextBlock &block)" << std::endl;
}

void BreakpointMarker::removeFromEditor() {
    std::cout << "void BreakpointMarker::removeFromEditor()" << std::endl;
}

void BreakpointMarker::documentClosing() {
    std::cout << "void BreakpointMarker::documentClosing()" << std::endl;
}

//! @class DocumentMarker
DocumentMarker::DocumentMarker(QTextDocument *doc, int lineStartNumber)
  : ITextMarkable(doc) , mpTextDocument(doc), mLineStartNumber(lineStartNumber)
{

}

bool DocumentMarker::addMark(ITextMark *mark, int line) {
    std::cout << "bool DocumentMarker::addMark(ITextMark *mark, int line)" << std::endl;
    return false;
}

TextMarks DocumentMarker::marksAt(int line) const {
    std::cout << "TextMarks DocumentMarker::marksAt(int line) const" << std::endl;
    return TextMarks();
}

void DocumentMarker::removeMark(ITextMark *mark) {
    std::cout << "void DocumentMarker::removeMark(ITextMark *mark)" << std::endl;
}

bool DocumentMarker::hasMark(ITextMark *mark) const {
    std::cout << "bool DocumentMarker::hasMark(ITextMark *mark) const" << std::endl;
    return false;
}

void DocumentMarker::updateMark(ITextMark *mark) {
    std::cout << "void DocumentMarker::updateMark(ITextMark *mark)" << std::endl;
}

void DocumentMarker::updateBreakpointsLineNumber() {
    std::cout << "void DocumentMarker::updateBreakpointsLineNumber()" << std::endl;
}

void DocumentMarker::updateBreakpointsBlock(const QTextBlock &block) {
    std::cout << "void DocumentMarker::updateBreakpointsBlock(const QTextBlock &block)" << std::endl;
}
