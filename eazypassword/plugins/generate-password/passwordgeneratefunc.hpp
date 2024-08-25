#ifndef __dasdsaeqixcghijn_121231_rtyuiolnbvcfghjde1
#define __dasdsaeqixcghijn_121231_rtyuiolnbvcfghjde1

#include <QObject>
#include <QString>

namespace functional { namespace generate {

/**
 * PasswordGenerater
 * 
 */

class PasswordGenerater : public QObject {
Q_OBJECT
public:
    explicit PasswordGenerater(QObject* parent = nullptr);
    ~PasswordGenerater();

public:
    void setContentString(const QString &regex);
    QString contentString() const;

    void setRequiredChars(const QString& requiredChars);
    QString requiredChars() const;

    void setSizePassword(int size);
    int sizePassword() const;

signals:
    void passwordGenerated(const QString& password);

public slots:
    void generatePassword();

private:
    QString charSet_;
    QString requiredChars_;
    int sizePassword_;
};

}}
#endif //__dasdsaeqixcghijn_121231_rtyuiolnbvcfghj