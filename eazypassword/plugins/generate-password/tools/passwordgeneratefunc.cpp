#include <QDebug>
#include <QRandomGenerator>

#include "passwordgeneratefunc.hpp"

namespace functional { namespace generate {

/**
 * PasswordGeneraterModelImpl
 * 
 */

PasswordGeneraterModel::PasswordGeneraterModel(QObject* parent)
        : QObject(), impl_(new PasswordGeneraterModelImpl) {
    connect(impl_,  &PasswordGeneraterModelImpl::passwordGenerated, this, &PasswordGeneraterModel::setPassword);
}

PasswordGeneraterModel::~PasswordGeneraterModel() {
    delete impl_; // TODO crete in other thread
    qInfo() << "PasswordGeneraterModel::~PasswordGeneraterModel()";
}

void PasswordGeneraterModel::setSizePassword(int size) {
    QMetaObject::invokeMethod(impl_, "setSizePassword", Q_ARG(int, size), Qt::QueuedConnection);
}

void PasswordGeneraterModel::setRequiredChars(const QString &requiredChars) {
    QMetaObject::invokeMethod(impl_, "setRequiredChars", Q_ARG(QString, requiredChars), Qt::QueuedConnection);
}

void PasswordGeneraterModel::setContentString(const QString &contentString) {
    QMetaObject::invokeMethod(impl_, "setContentString", Q_ARG(QString, contentString), Qt::QueuedConnection);
}

void PasswordGeneraterModel::generatePassword() {
    QMetaObject::invokeMethod(impl_, "generatePassword", Qt::QueuedConnection);
}

void PasswordGeneraterModel::setPassword(const QString& password) {
    qInfo()<<"PasswordGeneraterModel::setPassword";
    Q_EMIT generatedPassword(password);
}


/**
 * PasswordGeneraterModel
 * 
 */

PasswordGeneraterModelImpl::PasswordGeneraterModelImpl(QObject* parent)
        : QObject(),
          charSet_("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890!%$#"),
          sizePassword_(14) {
}

PasswordGeneraterModelImpl::~PasswordGeneraterModelImpl() {
    qInfo() << "PasswordGeneraterModelImpl::~PasswordGeneraterModelImpl()";
}

void PasswordGeneraterModelImpl::setContentString(const QString &regex) {
    charSet_ = regex;
}

QString PasswordGeneraterModelImpl::contentString() const {
    return charSet_;
}

void PasswordGeneraterModelImpl::setRequiredChars(const QString& requiredChars) {
    requiredChars_ = requiredChars;
}

QString PasswordGeneraterModelImpl::requiredChars() const {
    return requiredChars_;
}

void PasswordGeneraterModelImpl::setSizePassword(int size) {
    sizePassword_ = size;
}

int PasswordGeneraterModelImpl::sizePassword() const {
    return sizePassword_;
}

void PasswordGeneraterModelImpl::generatePassword() {
    QString password = "";

    for(int i = 0; i < sizePassword_; ++i)
    {
        int index = QRandomGenerator::global()->bounded(0, charSet_.length());
        QChar nextChar = charSet_.at(index);
        password.append(nextChar);
    }
    
    Q_EMIT passwordGenerated(password);
}

}}