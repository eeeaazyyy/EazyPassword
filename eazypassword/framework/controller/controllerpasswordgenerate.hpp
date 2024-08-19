#ifndef ___jdhauyioqewhcvbnlk1u23fidusvi31ijmbv
#define ___jdhauyioqewhcvbnlk1u23fidusvi31ijmbv

#include <QObject>
#include <QSharedPointer>

#include <generate-password/passwordgeneratefunc.hpp>

namespace framework { namespace controller {

/**
 * ControllerPasswordGenerate
 * 
 */

class ControllerPasswordGenerate : public QObject {
Q_OBJECT
public:
    static ControllerPasswordGenerate& instance();

public slots:
    void setSizePassword(int size);
    void setRequiredChars(const QString& requiredChars);
    void setContentString(const QString& contentString);

    void generatePassword();

    void setPassword(const QString& password);

signals:
    void generatedPassword(const QString& password);

private:
    explicit ControllerPasswordGenerate(QObject * parent = nullptr);
    ~ControllerPasswordGenerate() = default;

private:
    QSharedPointer<functional::generate::PasswordGenerater> passwordGenerater_;
};

}}

#endif //___jdhauyioqewhcvbnlk1u23fidusvi31ijmbv