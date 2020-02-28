#include <QApplication>

#include "ui/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication* app = new QApplication(argc, argv);

    mainWindow* mainWindow = mainWindow::getInstance();
    mainWindow -> show();

    return app -> exec();
}
