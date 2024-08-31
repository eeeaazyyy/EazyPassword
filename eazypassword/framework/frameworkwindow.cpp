#include <QDebug>
#include <QSignalBlocker>
#include <QVBoxLayout>

#include "plugins/generate-password/widgets/generatepasswordwidget.hpp"

#include "frameworkwindow.hpp"

namespace framework { namespace window {

EazyPasswordMainWindow::EazyPasswordMainWindow(QWidget* parent)
        : QMainWindow(parent), centralWidget_(new QWidget) {
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

    const QSharedPointer<functional::generate::PasswordGeneraterModel> generaterPassword(new functional::generate::PasswordGeneraterModel);
    auto* GeneratePasswordLabel   = new functional::generate::GeneratePasswordWidget(generaterPassword);

    auto* layout = new QVBoxLayout;
    layout->addWidget(GeneratePasswordLabel);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

}}