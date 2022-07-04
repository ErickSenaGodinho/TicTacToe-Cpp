#ifndef VALIDATE_INPUT_H
#define VALIDATE_INPUT_H

#include <iostream>

using namespace std;

int input();
int validateInput(string);

/** Converts the input to a number
 *
 * @see validateInput
 *
 * @return the input in number format
 */
int input()
{
    string input;
    cin >> input;
    return validateInput(input);
}

/** Converts the first character of a string to a number
 *
 * @return converted number. -1 if input size is more than one.
 */
int validateInput(string input)
{
    return (input.size() > 1 ? -1 : (int)input[0] - '0');
}

#endif