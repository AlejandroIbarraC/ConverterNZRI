//
// Created by Alejandro Ibarra on 2/22/20.
//

#include "hammingwindow.h"
#include "ui_hammingwindow.h"

using namespace std;
HammingWindow* HammingWindow::window = nullptr;

HammingWindow::HammingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HammingWindow)
{
    ui->setupUi(this);
}

HammingWindow::~HammingWindow()
{
    delete ui;
}

HammingWindow* HammingWindow::getInstance() {
    if (!window) {
        window = new HammingWindow;
    }
    return window;
}

void HammingWindow::on_backButton_clicked() {
    mainWindow* window = mainWindow::getInstance();
    window->show();
    hide();
}
