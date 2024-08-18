#include <QDebug>

#include "generatepasswordlineedit.hpp"

namespace framework { namespace widgets {

GeneratePasswordLineEdit::GeneratePasswordLineEdit(QWidget *parent) 
        : EZLineEdit(parent) {
    setMinimumWidth(365);
}

GeneratePasswordLineEdit::~GeneratePasswordLineEdit() {
    qInfo() << "GeneratePasswordLineEdit::~GeneratePasswordLineEdit()";
}

}}