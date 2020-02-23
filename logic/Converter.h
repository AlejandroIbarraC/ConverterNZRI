//
// Created by Alejandro Ibarra on 2/22/20.
//

#ifndef LD_P1_CONVERTER_H
#define LD_P1_CONVERTER_H

#include <iostream>
#include <QString>
#include <unordered_map>

using namespace std;

class Converter {

public:
    static string binaryToHex(string binaryNum);
    static string octalToBinary(string octalNum);

private:
    void static initializeMap(unordered_map<string, char> *um);

};


#endif //LD_P1_CONVERTER_H
