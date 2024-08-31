#include <QHBoxLayout>

#include "inputlineedit.hpp"

namespace ezpass { namespace widgets {

InputLineEdit::InputLineEdit(const QString &title, QWidget *parent)
        : title_(new QLabel(title)), QWidget(parent), lineEdit_(new QLineEdit) {
    auto layout = new QHBoxLayout;
    layout->setContentsMargins(4, 4, 4, 4);

    layout->addWidget(title_);
    layout->addWidget(lineEdit_);

    setLayout(layout);
}

InputLineEdit::InputLineEdit(QWidget *parent)
        : title_(nullptr), QWidget(parent), lineEdit_(new QLineEdit) {
    auto layout = new QHBoxLayout;
    layout->setContentsMargins(4, 4, 4, 4);

    layout->addWidget(lineEdit_);

    setLayout(layout);
}

InputLineEdit::~InputLineEdit() {

}

void InputLineEdit::setTextTitle(const QString &title) {
    if (!title_) { return; }

    title_->setText(title);
}

QString InputLineEdit::textTitle() const {
    if (!title_) { return QString(); }

    return title_->text();
}

void InputLineEdit::setLineEditText(const QString &title) {
    lineEdit_->setText(title);
}

QString InputLineEdit::lineEditText() const {
    return lineEdit_->text();
}

void InputLineEdit::clear() {
    lineEdit_->clear();
}

}}