#include <QDebug>

#include "controllerpasswordgenerate.hpp"

namespace framework { namespace controller {

/**
 * ControllerPasswordGenerate
 * 
 */

ControllerPasswordGenerate::ControllerPasswordGenerate(QObject* parent)
        : passwordGenerater_(new functional::generate::PasswordGenerater) {
    passwordGenerater_->setParent(this);
    connect(passwordGenerater_,  &functional::generate::PasswordGenerater::passwordGenerated, this, &ControllerPasswordGenerate::setPassword);
}

ControllerPasswordGenerate& ControllerPasswordGenerate::instance() {
    static ControllerPasswordGenerate controller;
    return controller;
}

void ControllerPasswordGenerate::setSizePassword(int size) {
    passwordGenerater_->setSizePassword(size);
}

void ControllerPasswordGenerate::setRequiredChars(const QString &requiredChars) {
    passwordGenerater_->setRequiredChars(requiredChars);
}

void ControllerPasswordGenerate::setContentString(const QString &contentString) {
    passwordGenerater_->setContentString(contentString);
}

void ControllerPasswordGenerate::generatePassword() {
    passwordGenerater_->generatePassword();
}

void ControllerPasswordGenerate::setPassword(const QString& password) {
    qInfo()<<"ControllerPasswordGenerate::setPassword";
    Q_EMIT generatedPassword(password);
}

}}