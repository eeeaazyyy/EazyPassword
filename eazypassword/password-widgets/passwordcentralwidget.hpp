#ifndef __dasd2eommaweqjdfas12g
#define __dasd2eommaweqjdfas12g

#include <QWidget>

class QGridLayout;

class PasswordLineEdit;
class PasswordButton;


namespace framework { namespace widgets {

class PasswordCentralWidget : public QWidget {
Q_OBJECT
public:
   explicit PasswordCentralWidget(QWidget* parent = nullptr);
   virtual ~PasswordCentralWidget();

    void setLayoutWidgets(QLayout*);
private:
    QGridLayout* layout_;
    PasswordLineEdit* passwordEdit_;
    PasswordButton* passwordButton_;
};

}}


#endif //__dasd2eommaweqjdfas12g


