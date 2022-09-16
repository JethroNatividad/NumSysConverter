#include <iostream>
#include <string>
#include <map>

using namespace std;

string reverse(string str)
{
    string reversed = "";

    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversed += str[i];
    }

    return reversed;
}

string convertDecimalToBinary(int decimal)
{
    string binary = "";
    int quotient = decimal;

    while (quotient > 0)
    {
        binary += to_string(quotient % 2);
        quotient = quotient / 2;
    }

    return reverse(binary);
}

int convertDecimalToOctal(int decimal)
{
    string octal = "";
    int quotient = decimal;

    while (quotient > 0)
    {
        octal += to_string(quotient % 8);
        quotient = quotient / 8;
    }

    return stoi(reverse(octal));
}

string convertDecimalToHexadecimal(int decimal)
{
    map<int, string> extra;
    extra[10] = "A";
    extra[11] = "B";
    extra[12] = "C";
    extra[13] = "D";
    extra[14] = "E";
    extra[15] = "F";

    string hexadecimal = "";
    int quotient, remainder;
    quotient = decimal;

    while (quotient > 0)
    {
        remainder = quotient % 16;
        if (extra.count(remainder))
        {
            hexadecimal += extra[remainder];
        }
        else
        {
            hexadecimal += to_string(remainder);
        }

        quotient = quotient / 16;
    }

    return reverse(hexadecimal);
}

int main()
{
    int decimal, octal;
    string binary, hexadecimal;

    decimal = 345345;
    binary = convertDecimalToBinary(decimal);
    octal = convertDecimalToOctal(decimal);
    hexadecimal = convertDecimalToHexadecimal(decimal);
    cout << "Decimal(source): " << decimal << endl;
    cout << "Binary: " << binary << endl;
    cout << "Octal: " << octal << endl;
    cout << "Hexadecimal: " << hexadecimal << endl;

    return 0;
}