#include <QApplication>

#include "frameworkwindow.hpp"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
    framework::window::EazyPasswordMainWindow EazyPassword;
    EazyPassword.show();
	return app.exec();
}
