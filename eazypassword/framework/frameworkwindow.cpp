#include <QDebug>
#include <QSignalBlocker>

#include "generatepasswordbutton.hpp"
#include "generatepasswordlineedit.hpp"
#include "framelabel.hpp"
#include "controllerpasswordgenerate.hpp"

#include "frameworkwindow.hpp"

namespace framework { namespace window {

EazyPasswordMainWindow::EazyPasswordMainWindow(QWidget* parent)
        : QMainWindow(parent), centralWidget_(new QWidget), layout_(new QGridLayout) {
    setWindowTitle("EazyPassword24");
    setMinimumSize(600, 220);

    centralWidget_->setParent(this);

    fillForm(centralWidget_);
}

EazyPasswordMainWindow::~EazyPasswordMainWindow() {
    qInfo() << "EazyPasswordMainWindow::~EazyPasswordMainWindow()";
}

void EazyPasswordMainWindow::fillForm(QWidget* centralWidget) {
    Q_ASSERT(centralWidget);

    QSignalBlocker blocker(this);

    auto const& controller = controller::ControllerPasswordGenerate::instance();

    auto* GeneratePasswordLabel   = new widgets::FrameLabel(tr("Password: "), centralWidget);
    auto* GenerateLineEdit        = new widgets::GeneratePasswordLineEdit(centralWidget);
    auto* GenerateButton          = new widgets::GeneratePasswordButton(centralWidget);

    layout_->addWidget(GeneratePasswordLabel, 0, 0, Qt::AlignLeft);
    layout_->addWidget(GenerateLineEdit, 0, 1, Qt::AlignLeft);
    layout_->addWidget(GenerateButton, 0, 2, Qt::AlignLeft);

    centralWidget->setLayout(layout_);
    
    setCentralWidget(centralWidget);

    connect(GenerateButton, &widgets::GeneratePasswordButton::clicked, 
            &controller, &controller::ControllerPasswordGenerate::generatePassword);

    connect(&controller, &controller::ControllerPasswordGenerate::generatedPassword, 
            GenerateLineEdit, &QLineEdit::setText);
}

}}