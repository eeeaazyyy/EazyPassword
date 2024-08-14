#include "passwordbutton.hpp"

namespace framework { namespace widgets {

PasswordButton::PasswordButton(QWidget *parent) 
        : QPushButton(parent) {

}
PasswordButton::PasswordButton(const QString &text, QWidget *parent) 
        : QPushButton(text, parent) {

}

PasswordButton::PasswordButton(const QIcon &icon, const QString &text, QWidget *parent) 
        : QPushButton(icon, text, parent) {

}

}}