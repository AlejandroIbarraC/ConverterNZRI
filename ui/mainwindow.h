//
// Created by Alejandro Ibarra on 2/22/20.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "converterwindow.h"
#include "hammingwindow.h"

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

    static mainWindow* getInstance();

private:
    Ui::mainWindow *ui;

    static mainWindow* window;

public slots:
    void on_toConverterButton_clicked();
    void on_toHammingButton_clicked();

};

#endif // MAINWINDOW_H
