#include <QHBoxLayout>

#include "inputlineedit/inputlineedit.hpp"

#include "generatepasswordwidget.hpp"

namespace functional { namespace generate {

using namespace ezpass::widgets;

GeneratePasswordWidget::GeneratePasswordWidget(const QSharedPointer<PasswordGeneraterModel> model, QWidget *parent) 
        : model_(model), QGroupBox(parent) {
    setTitle(tr("Generate Password"));

    auto layout = new QHBoxLayout;

    InputLineEdit* lineEdit = new InputLineEdit("Password");
    QPushButton* btnGenerate = new QPushButton("Generate");
    
    layout->addWidget(lineEdit);
    layout->addWidget(btnGenerate);

    connect(btnGenerate, &QPushButton::clicked, model_.data(), &PasswordGeneraterModel::generatePassword);
    connect(model_.data(), &PasswordGeneraterModel::generatedPassword, lineEdit, &InputLineEdit::setLineEditText);

    setLayout(layout);
}

GeneratePasswordWidget::~GeneratePasswordWidget() {

}

}}




