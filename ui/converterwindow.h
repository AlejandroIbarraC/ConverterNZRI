//
// Created by Alejandro Ibarra on 2/22/20.
//

#ifndef CONVERTERWINDOW_H
#define CONVERTERWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPainter>

#include "../logic/Converter.h"
#include "mainwindow.h"


namespace Ui {
class ConverterWindow;
}

class ConverterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConverterWindow(QWidget *parent = nullptr);
    ~ConverterWindow();

    static ConverterWindow* getInstance();

    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::ConverterWindow *ui;

    QString bin;
    QLabel* bitArray[12];
    int state = 0;

    static ConverterWindow* window;

    void analyze();

private slots:
    void on_analyzeButton_clicked();
    void on_backButton_clicked();

};

#endif // CONVERTERWINDOW_H
