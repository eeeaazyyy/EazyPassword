#include <QDebug>
#include <QGridLayout>

#include "passwordbutton.hpp"
#include "passwordlineedit.hpp"

#include "passwordcentralwidget.hpp"

namespace framework { namespace widgets {

PasswordCentralWidget::PasswordCentralWidget(QWidget* parent) 
    : QWidget(parent), passwordEdit_(new PasswordLineEdit), 
        passwordButton_(new PasswordButton), layout_(nullptr) {
    setLayoutWidgets(new QGridLayout);
}

PasswordCentralWidget::~PasswordCentralWidget() {
    qInfo() << "PasswordCentralWidget::~PasswordCentralWidget()";
}

void PasswordCentralWidget::setLayoutWidgets(QLayout* layout) {
    if (layout_ != layout) { layout_ = dynamic_cast<QGridLayout*>(layout); }

    passwordButton_->setText("Generate");

    layout_->addWidget(passwordEdit_, 0, 0, 1, 2);
    layout_->addWidget(passwordButton_, 1, 0, 1, 1);
    
    setLayout(layout_);
}

}}