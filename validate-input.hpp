#ifndef VALIDATE_INPUT_H
#define VALIDATE_INPUT_H

#include <iostream>

using namespace std;

int input();
int validateInput(string);

int input()
{
    string input;
    cin >> input;
    return validateInput(input);
}

int validateInput(string input)
{
    return (int)input[0] - '0';
}

#endif