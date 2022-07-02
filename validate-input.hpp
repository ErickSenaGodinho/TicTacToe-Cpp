#ifndef VALIDATE_INPUT_H
#define VALIDATE_INPUT_H

#include <iostream>

using namespace std;

int input();
int validateInput(string);

/** Converts a string to a number
 *
 * @see validateInput
 * 
 * @return converted number
 */
int input()
{
    string input;
    cin >> input;
    return validateInput(input);
}

/** Converts the first character of a string to a number
 *
 * @see input
 * 
 * @return converted number
 */
int validateInput(string input)
{
    return (int)input[0] - '0';
}

#endif