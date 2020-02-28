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

    // Setup initial header and row names of tables
    QStringList columnHeaders = { "p1", "p2", "d1", "p3", "d2", "d3", "d4", "p4", "d5", "d6", "d7", "d8", "d9", "d10", "d11", "p5", "d12", ""};
    QStringList columnHeadersModified = { "p1", "p2", "d1", "p3", "d2", "d3", "d4", "p4", "d5", "d6", "d7", "d8", "d9", "d10", "d11", "p5", "d12", "Error" };
    QStringList rowHeaders = { "Original", "p1", "p2", "p3", "p4", "p5" , "Final"};
    ui->inputTable->setHorizontalHeaderLabels(columnHeaders);
    ui->inputTable->setVerticalHeaderLabels(rowHeaders);
    ui->inputTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->modifiedTable->setHorizontalHeaderLabels(columnHeadersModified);
    ui->modifiedTable->setVerticalHeaderLabels(rowHeaders);

    // Set initial state as 1: not active, 0: active
    state = 1;
}

HammingWindow::~HammingWindow()
{
    delete ui;
}

void HammingWindow::analyze() {
    // Check if parity is selected. Initialize hamming code matrix
    if (ui->parityCheckBox->isChecked()) {
        Hamming::init(1);
    }
    else {
        Hamming::init(0);
    }

    // Check if 12 digit binary code is written on entry. Write first lines of Hamming code
    if (!Hamming::writeFirstLine(ui->numberEntry->text())) {
        ui->errorLabel->setText("Please enter 12 digit binary code");
        return;
    }

    // Complete Hamming code
    Hamming::writeLines();
    Hamming::show();

    ui->errorLabel->setText("Generation successful. To force an error, double click square in row \"Final\"");

    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            QTableWidgetItem *newItem;
            if (Hamming::hammingMatrix[i][j]==1) {
                newItem= new QTableWidgetItem("1");
            }
            else if (Hamming::hammingMatrix[i][j]==0) {
                newItem= new QTableWidgetItem("0");
            }
            else {
                continue;
            }
            ui->inputTable->setItem(i, j, newItem);
        }
    }

    actualParity = Hamming::getParity();
    actualInput = ui->numberEntry->text();
    state = 0;
}

/// Forces error in specific row and column of Hamming code matrix
/// @arg int row
/// @arg int column
void HammingWindow::forceError(int row, int column) {
    if (row != 6 || state == 1){
            return;
    }

    QString nInput;
    QString nInputHamming;
    int* evenNumbers = Hamming::getEvenNumbers();
    int c = 0;
    int preError =- 1;

    for (int i = 0; i < 17; i++) {
        if (i == column){
            if (i == evenNumbers[c]) {
                //ui->errorLabel->setText("Error is in position " + QString::number(i));
                preError = i;
                c++;
            }
            else if (actualInput.at(i-c) == '1') {
                // Next input is 0
                nInput += '0';
            }
            else {
                // Next input is 1
                nInput += '1';
            }
            continue;
        }
        else if (i == evenNumbers[c]) {
            c++;
        }
        else {
            nInput += actualInput.at(i-c);
        }
    }

    for (int i = 0; i < 17; i++) {
        if (i == column) {
            if (Hamming::hammingMatrix[6][i] == 1) {
                nInputHamming += '0';
            }
            else {
                nInputHamming += '1';
            }
        }
        else if (Hamming::hammingMatrix[6][i] == 0){
                nInputHamming += '0';
            }
            else{
                nInputHamming += '1';
            }
    }

    // Generate Hamming code again
    Hamming::writeFirstLine(nInput);
    Hamming::writeLines();
    Hamming::show();

    int i, j;
    for (i = 0; i < rows - 1; i++) {
        for (j = 0; j < columns; j++) {
          QTableWidgetItem *newItem;

          if (Hamming::hammingMatrix[i][j]==1) {
            newItem = new QTableWidgetItem("1");
          }
          else if (Hamming::hammingMatrix[i][j]==0) {
            newItem = new QTableWidgetItem("0");
          }
          else {
            continue;
          }
         ui->modifiedTable->setItem(i, j, newItem);
        }
    }

    for (j = 0; j < columns; j++) {
         QTableWidgetItem *newItem;
         newItem = new QTableWidgetItem(nInputHamming.at(j));
         ui->modifiedTable->setItem(i, j, newItem);
    }
    Hamming::findError(nInputHamming);

    for (int i = 1; i < 6; i++) {
        QTableWidgetItem *newItem;
        if (Hamming::lastParity.at(i-1)==Hamming::actualParity.at(i-1)) {
            newItem = new QTableWidgetItem("0");
        }
        else {
            newItem = new QTableWidgetItem("1");
        }
        ui->modifiedTable->setItem(i, 17, newItem);
    }
    int errorPos = Hamming::error;
    ui->errorLabel->setText("Initial Parity: " + Hamming::lastParity +
                            ". Modified Parity: " + Hamming::actualParity +
                            ". Error is in position " + QString::number(errorPos));

    ui->modifiedTable->item(6, errorPos - 1)->setBackground(Qt::red);
    state = 1;
}

HammingWindow* HammingWindow::getInstance() {
    if (!window) {
        window = new HammingWindow;
    }
    return window;
}

void HammingWindow::on_analyzeButton_clicked() {
    analyze();
}

void HammingWindow::on_backButton_clicked() {
    mainWindow* window = mainWindow::getInstance();
    window->show();
    hide();
}

void HammingWindow::on_inputTable_cellDoubleClicked(int row, int column) {
    forceError(row, column);
}
