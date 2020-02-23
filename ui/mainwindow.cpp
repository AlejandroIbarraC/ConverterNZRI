//
// Created by Alejandro Ibarra on 2/22/20.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
mainWindow* mainWindow::window = nullptr;

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
}

mainWindow::~mainWindow()
{
    delete ui;
}

mainWindow* mainWindow::getInstance() {
    if (!window) {
        window = new mainWindow;
    }
    return window;
}

void mainWindow::on_toConverterButton_clicked() {
    ConverterWindow* window = ConverterWindow::getInstance();
    window->show();
    hide();
}

void mainWindow::on_toHammingButton_clicked() {
    HammingWindow* window = HammingWindow::getInstance();
    window->show();
    hide();
}
