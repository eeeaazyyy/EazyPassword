#include <QApplication>

#include "frameworkwindow.hpp"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
    EazyPasswordMainWindow w;
    w.show();
	return app.exec();
}
