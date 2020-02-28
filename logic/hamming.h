//
// Created by Alejandro Ibarra on 26/2/2020.
//

#ifndef LD_P1_HAMMING_H
#define LD_P1_HAMMING_H

#include <QDebug>
#include <stdio.h>
#include <cmath>
#include <QString>


const int columns = 17;
const int digitsArray[]={2,4,5,6,8,9,10,11,12,13,14,16};
const int parityArray[]={0,1,3,7,15};
const int rows = 7;

class Hamming {

public:
    static QString actualParity;
    static int error;
    static int hammingMatrix[rows][columns];
    static QString lastParity;

    static int* compareArray(int* P1, int* P2);
    static int compareParity(int* P1, int* P2);
    static void findError(QString input);
    static int* getEvenNumbers();
    static Hamming& getInstance() {
        static Hamming instance;
        return instance;
    }
    static int* getFinal();
    static int* getParity();
    static void init(int parity, int valor = 2);
    static void show();
    static bool writeFirstLine(QString input);
    static void writeLines();


private:
    static int parity;

};


#endif //LD_P1_HAMMING_H
