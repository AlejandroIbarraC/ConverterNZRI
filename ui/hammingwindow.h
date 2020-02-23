//
// Created by Alejandro Ibarra on 2/22/20.
//

#ifndef HAMMINGWINDOW_H
#define HAMMINGWINDOW_H

#include <QMainWindow>

#include "mainwindow.h"

namespace Ui {
class HammingWindow;
}

class HammingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HammingWindow(QWidget *parent = nullptr);
    ~HammingWindow();

    static HammingWindow* getInstance();

private:
    Ui::HammingWindow *ui;

    static HammingWindow* window;

private slots:
    void on_backButton_clicked();

};

#endif // HAMMINGWINDOW_H
