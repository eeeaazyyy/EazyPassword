#ifndef __dasdsaeqixcghijn_121231_rtyuiolnbvcfghjde1
#define __dasdsaeqixcghijn_121231_rtyuiolnbvcfghjde1

#include <QObject>
#include <QString>

namespace functional { namespace generate {

class PasswordGeneraterModelImpl;

/**
 * PasswordGeneraterModelImpl
 * 
 */

class PasswordGeneraterModel : public QObject {
Q_OBJECT
public:
    explicit PasswordGeneraterModel(QObject * parent = nullptr);
    ~PasswordGeneraterModel();

public slots:
    void setSizePassword(int size);
    void setRequiredChars(const QString& requiredChars);
    void setContentString(const QString& contentString);

    void generatePassword();

    void setPassword(const QString& password);

signals:
    void generatedPassword(const QString& password);

private:
    PasswordGeneraterModelImpl* impl_;
    QString charSet_;
    QString requiredChars_;
    int sizePassword_;
};


/**
 * PasswordGeneraterModel
 * 
 */

class PasswordGeneraterModelImpl : public QObject {
Q_OBJECT
public:
    explicit PasswordGeneraterModelImpl(QObject* parent = nullptr);
    ~PasswordGeneraterModelImpl();

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