#ifndef __tiuhgcuyieqwlgasldljihu1gl3bdyau
#define __tiuhgcuyieqwlgasldljihu1gl3bdyau

#include <QGroupBox>
#include <QSharedPointer>
#include <QPushButton>
#include <QLabel>

#include "generate-password/tools/passwordgeneratefunc.hpp"

namespace functional { namespace generate {

class GeneratePasswordWidget : public QGroupBox {
Q_OBJECT
public:
    GeneratePasswordWidget(const QSharedPointer<PasswordGeneraterModel> model, QWidget* parent = nullptr);
    ~GeneratePasswordWidget();

private:
    QSharedPointer<PasswordGeneraterModel> model_;
};

}}

#endif // __tiuhgcuyieqwlgasldljihu1gl3bdyau