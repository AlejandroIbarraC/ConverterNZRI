//
// Created by Alejandro Ibarra on 2/22/20.
//

#include "converterwindow.h"
#include "ui_converterwindow.h"

using namespace std;
ConverterWindow* ConverterWindow::window = nullptr;

ConverterWindow::ConverterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConverterWindow)
{
    ui->setupUi(this);

    // Set up bit array in UI
    bitArray[0] = ui->bit1;
    bitArray[1] = ui->bit2;
    bitArray[2] = ui->bit3;
    bitArray[3] = ui->bit4;
    bitArray[4] = ui->bit5;
    bitArray[5] = ui->bit6;
    bitArray[6] = ui->bit7;
    bitArray[7] = ui->bit8;
    bitArray[8] = ui->bit9;
    bitArray[9] = ui->bit10;
    bitArray[10] = ui->bit11;
    bitArray[11] = ui->bit12;
}

ConverterWindow::~ConverterWindow()
{
    delete ui;
}

void ConverterWindow::analyze() {
    QString entryData = ui->numEntry->displayText();
    if (entryData.length() != 4) {
        // Error. Entry isn't 4 digit long.
        ui->errorLabel->setText("Error. Introduzca un dato de 4 dígitos.");
    } else {
        // Entry is 4 digit long.
        ui->numEntry->clear();

        // Verify if entry is an octal number.
        if (entryData.toInt() && !entryData.contains("8") && !entryData.contains("9")) {
            // Entry is octal number. Convert and display.
            string dataStr = entryData.toStdString();

            string binaryConverted = Converter::octalToBinary(dataStr);
            string hexConverted = Converter::binaryToHex(binaryConverted);

            QString binaryResult = QString::fromStdString(binaryConverted);
            bin = binaryResult;
            state = 1;
            update();
            QString hexResult = QString::fromStdString(hexConverted);

            ui->binaryConversionResultLabel->setText(binaryResult);
            ui->hexConversionResultLabel->setText(hexResult);
        } else {
            // Error. Entry isn't an octal number.
            ui->errorLabel->setText("Error. Introduzca un número octal.");
        }


    }
}

ConverterWindow* ConverterWindow::getInstance() {
    if (!window) {
        window = new ConverterWindow;
    }
    return window;
}

void ConverterWindow::on_analyzeButton_clicked() {
    analyze();
}

void ConverterWindow::on_backButton_clicked() {
    mainWindow* window = mainWindow::getInstance();
    window->show();
    hide();
}

void ConverterWindow::paintEvent(QPaintEvent* event) {
    int x1 = 100;
    int x2 = 90;
    int y1 = 90;
    int y2 = 230;
    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(5);

    painter.setPen(pen);
    painter.drawLine(100, 90, 100, 230);
    painter.drawLine(70, 160, 720, 160);

    pen.setWidth(1);
    painter.setPen(pen);
    for (int i = 0; i < 12; i++){
        painter.drawLine(x1, y1, x1, y2);
        x1 += 50;
    }

    if (state == 1) {
        QPen pen2(Qt::red);
        pen2.setWidth(5);
        painter.setPen(pen2);
        x1 = 100;
        x2 = 100;
        y1 = 122;
        y2 = 122;
        bool high = true;

        for (int i = 0; i < 12; i++) {
            if (bin[i] == '0') {
                bitArray[i]->setText("0");
                y2 = y1;
                x1 = x2;
                x2 += 50;
                painter.drawLine(x1, y1, x2, y2);
                x1 = x2;
            } else {
                bitArray[i]->setText("1");
                x2 = x1;
                y2 = y1;
                if (high) {
                    y2 += 75;
                    painter.drawLine(x1, y1, x2, y2);
                    y1 = y2;
                    x1 = x2;
                    x2 += 50;
                    painter.drawLine(x1, y1, x2, y2);
                    x1 = x2;
                    high = false;
                } else {
                    y2 -= 75;
                    painter.drawLine(x1, y1, x2, y2);
                    y1 = y2;
                    x1 = x2;
                    x2 += 50;
                    painter.drawLine(x1, y1, x2, y2);
                    x1 = x2;
                    high = true;
                }
            }
        }
    }
}
