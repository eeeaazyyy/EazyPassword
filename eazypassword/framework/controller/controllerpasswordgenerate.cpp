#include <QDebug>

#include "controllerpasswordgenerate.hpp"

namespace framework { namespace controller {

/**
 * ControllerPasswordGenerate
 * 
 */

ControllerPasswordGenerate::ControllerPasswordGenerate(QObject* parent) {
    connect(passwordGenerater_.data(),  &functional::generate::PasswordGenerater::passwordGenerated,
            this,                       &ControllerPasswordGenerate::setPassword);
}

ControllerPasswordGenerate& ControllerPasswordGenerate::instance() {
    static ControllerPasswordGenerate controller;
    return controller;
}

void ControllerPasswordGenerate::setSizePassword(int size) {
    passwordGenerater_.get()->setSizePassword(size);
}

void ControllerPasswordGenerate::setRequiredChars(const QString &requiredChars) {
    passwordGenerater_.get()->setRequiredChars(requiredChars);
}

void ControllerPasswordGenerate::setContentString(const QString &contentString) {
    passwordGenerater_.get()->setContentString(contentString);
}

void ControllerPasswordGenerate::generatePassword() {
    passwordGenerater_.get()->generatePassword();
}

void ControllerPasswordGenerate::setPassword(const QString& password) {
    qInfo()<<"ControllerPasswordGenerate::setPassword";
}

}}