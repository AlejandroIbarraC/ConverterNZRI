//
// Created by Alejandro Ibarra on 2/22/20.
//

#ifndef HAMMINGWINDOW_H
#define HAMMINGWINDOW_H

#include <QMainWindow>

#include "mainwindow.h"
#include "../logic/Hamming.h"


namespace Ui {
class HammingWindow;
}

class HammingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HammingWindow(QWidget *parent = nullptr);
    ~HammingWindow();

    QString actualInput;
    int* actualParity;
    bool state;

    void forceError(int row, int column);
    static HammingWindow* getInstance();

private:
    Ui::HammingWindow *ui;

    static HammingWindow* window;

    void analyze();

private slots:
    void on_analyzeButton_clicked();
    void on_backButton_clicked();
    void on_inputTable_cellDoubleClicked(int row, int column);

};

#endif // HAMMINGWINDOW_H
