//
// Created by Alejandro Ibarra on 26/2/2020.
//

#include "Hamming.h"


int Hamming::hammingMatrix[rows][columns] = {};
int Hamming::parity = 0;
QString Hamming::lastParity = "";
QString Hamming::actualParity = "";
int Hamming::error = 0;

/// Compares two parities to check for errors
/// @arg int[] P1 first parity array
/// @arg int[] P2 second parity array
/// @return int[] error array
int *Hamming::compareArray(int *P1, int *P2) {
    int* errorArray = new int[5];
    int c = 0;
    for(int i : parityArray) {
        if (P1[i] != P2[i]) {
            errorArray[c] = 1;
        }
        else {
            errorArray[c] = 0;
        }
        c++;
    }
    return errorArray;
}

/// Compares two parities to check for errors
/// @arg int P1 first parity
/// @arg int P2 second parity
int Hamming::compareParity(int *P1, int* P2) {
    int error = 0;
    int pot = 0;

    for(int i : parityArray) {
        if (P1[i] != P2[i]){
            error += pow(2, pot);
        }
        pot++;
    }

    return error;
}

/// Finds error in Hamming matrix with modified data
void Hamming::findError(QString input) {
    bool bits[17];
    QString internalLastParity;
    QString internalActualParity;

    for (int i : parityArray) {
        if (input.at(i) == '0') {
            bits[i] = 0;
        }
        else if (input.at(i) == '1') {
            bits[i] = 1;
        }
        else {
            return;
        }
        internalLastParity += QString::number(bits[i]);
        internalActualParity += QString::number(hammingMatrix[rows - 1][i]);

    }
    int internalError = 0;
    int pot = 0;

    for(int i : parityArray) {
        if (bits[i] != hammingMatrix[rows - 1][i]){
            internalError += pow(2,pot);
        }
        pot++;
    }

    error = internalError;
    lastParity = internalLastParity;
    actualParity = internalActualParity;
}

int *Hamming::getEvenNumbers() {
    int* parity = new int[5];
    for (int i = 0; i < 5; i++) {
        parity[i] = parityArray[i];
    }
    return parity;
}

int *Hamming::getFinal() {
    int* final = new int[17];
    for(int i = 0; i < 17; i++) {
        final[i] = hammingMatrix[rows - 1][i];
    }
    return final;
}

int *Hamming::getParity() {
    int* parity = new int[17];
    for(int i = 0; i < 17; i++) {
        parity[i] = hammingMatrix[rows - 1][i];
    }
    return parity;
}

/// Initializes hamming code matrix.
/// @arg int p parity 0 or 1
/// @arg int value default is 2 for binary
void Hamming::init(int p, int value) {
    Hamming::parity = p;
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            hammingMatrix[i][j] = value;
        }
    }
}

void Hamming::show() {
    QString line;
    int i, j;

    for (i = 0; i < rows; i++) {
        line = "";

        for (j = 0; j < columns; j++) {
            line += "   " + QString::number(hammingMatrix[i][j]);
        }
    }
}

/// Write initial line in Hamming matrix if entry is valid
/// @arg QString input to analyze
/// @return bool if entry is accepted
bool Hamming::writeFirstLine(QString input) {
    if (input.length() != 12) return false;
    bool bits[12];

    for (int i = 0 ; i < 12 ; i++) {
        if (input.at(i) == '0'){
            bits[i] = 0;
        }
        else if (input.at(i) == '1') {
            bits[i] = 1;
        }
        else {
            return false;
        }
    }
    int c = 0;

    for (int j : digitsArray) {
        hammingMatrix[0][j] = bits[c];
        hammingMatrix[6][j] = bits[c];
        c++;
    }

    return true;
}

/// Write remaning data in Hamming code matrix
void Hamming::writeLines() {
    int begin;
    int jump;

    for (int i = 1; i < rows-1; i++){
        begin = parityArray[i - 1];
        jump = (int)pow(2, (i - 1));
        int col = begin;
        int sum = 0;

        while (col < columns) {
            for (int j = 0; j < jump && col < columns; j++) {
                hammingMatrix[i][col]=hammingMatrix[0][col];
                sum += hammingMatrix[0][col];
                col++;
            }
            col += jump;
        }
        hammingMatrix[6][begin]=(sum + parity) % 2;
        hammingMatrix[i][begin]=(sum + parity) % 2;
    }
}


