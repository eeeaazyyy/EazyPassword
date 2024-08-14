#include <QDebug>

#include "password-widgets/passwordcentralwidget.hpp"

#include "frameworkwindow.hpp"

using namespace framework;

EazyPasswordMainWindow::EazyPasswordMainWindow(QWidget* parent)
        : QMainWindow(parent) {
    setWindowTitle("EazyPasswordManager");
    setMinimumSize(550, 350);

    auto *ButtonLineWidget = new widgets::PasswordCentralWidget(this);
    setCentralWidget(ButtonLineWidget);
}

EazyPasswordMainWindow::~EazyPasswordMainWindow(){

}