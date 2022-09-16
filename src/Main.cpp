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

int main()
{
    int decimal, octal;
    string binary, hexadecimal;

    decimal = 345345;
    binary = convertDecimalToBinary(decimal);
    cout << "Decimal(source): " << decimal << endl;
    cout << "Binary: " << binary << endl;

    return 0;
}