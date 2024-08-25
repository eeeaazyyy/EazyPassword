#include <QDebug>

#include "generatepasswordbutton.hpp"
#include "generatepasswordlineedit.hpp"
#include "framelabel.hpp"
#include "controllerpasswordgenerate.hpp"


#include "frameworkwindow.hpp"

EazyPasswordMainWindow::EazyPasswordMainWindow(QWidget* parent)
        : QMainWindow(parent), centralWidget_(new QWidget), layout_(new QGridLayout) {
    setWindowTitle("EazyPassword24");
    setMinimumSize(600, 220);

    centralWidget_->setParent(this);

    auto const& controller = framework::controller::ControllerPasswordGenerate::instance();

    auto* GeneratePasswordLabel   = new framework::widgets::FrameLabel(tr("Password: "), centralWidget_);
    auto* GenerateLineEdit        = new framework::widgets::GeneratePasswordLineEdit(centralWidget_);
    auto* GenerateButton          = new framework::widgets::GeneratePasswordButton(centralWidget_);

    layout_->addWidget(GeneratePasswordLabel, 0, 0, Qt::AlignLeft);
    layout_->addWidget(GenerateLineEdit, 0, 1, Qt::AlignLeft);
    layout_->addWidget(GenerateButton, 0, 2, Qt::AlignLeft);

    centralWidget_->setLayout(layout_);
    
    setCentralWidget(centralWidget_);

    connect(GenerateButton, &framework::widgets::GeneratePasswordButton::clicked, 
            &controller, &framework::controller::ControllerPasswordGenerate::generatePassword);

    connect(&controller, &framework::controller::ControllerPasswordGenerate::generatedPassword, 
            GenerateLineEdit, &QLineEdit::setText);
}

EazyPasswordMainWindow::~EazyPasswordMainWindow() {
    qInfo() << "EazyPasswordMainWindow::~EazyPasswordMainWindow()";
}