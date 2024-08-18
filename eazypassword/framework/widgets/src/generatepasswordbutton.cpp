#include <QDebug>

#include "generatepasswordbutton.hpp"

namespace framework { namespace widgets {
GeneratePasswordButton::GeneratePasswordButton(QWidget *parent)
        : EZButton(parent) {
    setMinimumSize(90, 25);
    setText(tr("Generate"));
}

GeneratePasswordButton::~GeneratePasswordButton() {
    qInfo() << "GeneratePasswordButton::~GeneratePasswordButton()";
}

}}

