#ifndef __wertyjnbvfghjl27sdf
#define __wertyjnbvfghjl27sdf

#include <QPushButton>

namespace framework { namespace widgets {

class PasswordButton : public QPushButton {
Q_OBJECT
public:
    explicit PasswordButton(QWidget *parent = nullptr);
    explicit PasswordButton(const QString &text, QWidget *parent = nullptr);
    PasswordButton(const QIcon& icon, const QString &text, QWidget *parent = nullptr);
    ~PasswordButton() = default;
};

}}
#endif //__wertyjnbvfghjl27sdf