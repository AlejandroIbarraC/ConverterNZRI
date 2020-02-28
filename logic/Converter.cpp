//
// Created by Alejandro Ibarra on 2/22/20.
//

#include "Converter.h"

#include <cmath>


/// Converts octal notation to binary
/// @arg string binaryNum number in binary notation
/// @return string of hex number
string Converter::binaryToHex(string binaryNum) {
    int l = binaryNum.size();
    int t = binaryNum.find_first_of('.');

    // Length of string before '.'
    int len_left = t != -1 ? t : l;

    // Add 0's before to make left substring length divisible by 4.
    for (int i = 1; i <= (4 - len_left % 4) % 4; i++)
        binaryNum = '0' + binaryNum;

    // Check for decimals.
    if (t != -1) {
        // Length of string after '.'
        int len_right = l - len_left - 1;

        // Add 0's after to make right substring length divisible by 4
        for (int i = 1; i <= (4 - len_right % 4) % 4; i++)
            binaryNum = binaryNum + '0';
    }

    // Initialize map between binary and hex.
    unordered_map<string, char> bin_hex_map;
    initializeMap(&bin_hex_map);

    int i = 0;
    string result = "";

    while (1) {
        // Divide binary substring in groups of 4 and swap equivalent in hexadecimal.
        result += bin_hex_map[binaryNum.substr(i, 4)];
        i += 4;
        if (i == binaryNum.size())
            break;

        // If '.' is present, append it to result.
        if (binaryNum.at(i) == '.') {
            result += '.';
            i++;
        }
    }

    return result;
}

/// Initialize map between binary and hexadecimal.
void Converter::initializeMap(unordered_map<string, char> *um) {
    (*um)["0000"] = '0';
    (*um)["0001"] = '1';
    (*um)["0010"] = '2';
    (*um)["0011"] = '3';
    (*um)["0100"] = '4';
    (*um)["0101"] = '5';
    (*um)["0110"] = '6';
    (*um)["0111"] = '7';
    (*um)["1000"] = '8';
    (*um)["1001"] = '9';
    (*um)["1010"] = 'A';
    (*um)["1011"] = 'B';
    (*um)["1100"] = 'C';
    (*um)["1101"] = 'D';
    (*um)["1110"] = 'E';
    (*um)["1111"] = 'F';
}

/// Converts octal notation to binary
/// @arg octalNum number in octal notation
/// @return string converted number in binary
string Converter::octalToBinary(string octalNum) {
    long int i = 0;
    string binary = "";

    while (octalNum[i]) {
        switch (octalNum[i]) {
        case '0':
            binary += "000";
            break;
        case '1':
            binary += "001";
            break;
        case '2':
            binary += "010";
            break;
        case '3':
            binary += "011";
            break;
        case '4':
            binary += "100";
            break;
        case '5':
            binary += "101";
            break;
        case '6':
            binary += "110";
            break;
        case '7':
            binary += "111";
            break;
        default:
            cout << "\nInvalid Octal Digit "
                 << octalNum[i];
            break;
        }
        i++;
    }

    return binary;
}
