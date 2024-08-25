#include <QDebug>
#include <QRandomGenerator>

#include "generate-password/passwordgeneratefunc.hpp"

//#include "passwordgeneratefunc.hpp"

namespace functional { namespace generate {

/**
 * PasswordGenerater
 * 
 */
PasswordGenerater::PasswordGenerater(QObject* parent)
        : QObject(parent), 
          charSet_("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890!%$#"),
          sizePassword_(14) {
}

PasswordGenerater::~PasswordGenerater() {
    qInfo() << "PasswordGenerater::~PasswordGenerater()";
}

void PasswordGenerater::setContentString(const QString &regex) {
    charSet_ = regex;
}

QString PasswordGenerater::contentString() const {
    return charSet_;
}

void PasswordGenerater::setRequiredChars(const QString& requiredChars) {
    requiredChars_ = requiredChars;
}

QString PasswordGenerater::requiredChars() const {
    return requiredChars_;
}

void PasswordGenerater::setSizePassword(int size) {
    sizePassword_ = size;
}

int PasswordGenerater::sizePassword() const {
    return sizePassword_;
}

void PasswordGenerater::generatePassword() {
    QString password = "";

    for(int i = 0; i < sizePassword_; ++i)
    {
        int index = QRandomGenerator::global()->bounded(0, charSet_.length());
        QChar nextChar = charSet_.at(index); // Используйте charSet_, а не password
        password.append(nextChar);
    }
    
    Q_EMIT passwordGenerated(password);
}

}}