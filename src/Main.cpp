#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <list>
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

class Decimal
{
public:
    int value;
    Decimal(int val)
    {
        value = val;
    }

    string toBinary()
    {
        string binary = "";
        int quotient = value;

        while (quotient > 0)
        {
            binary += to_string(quotient % 2);
            quotient = quotient / 2;
        }

        return reverse(binary);
    }

    int toOctal()
    {
        string octal = "";
        int quotient = value;

        while (quotient > 0)
        {
            octal += to_string(quotient % 8);
            quotient = quotient / 8;
        }

        return stoi(reverse(octal));
    }

    string toHexadecimal()
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
        quotient = value;

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
};

void showlist(list<string> g)
{
    list<string>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

class Binary
{
public:
    string value;
    Binary(string val)
    {
        value = val;
    }
    int toDecimal()
    {
        int decimal = 0;
        string reversedValue = reverse(value);
        for (int i = 0; i < reversedValue.length(); i++)
        {
            if (reversedValue[i] == '1')
            {
                decimal += pow(2, i);
            }
        }
        return decimal;
    }

    int toOctal()
    {
        list<string> chunks;
        int group = 3;
        string reversedValue = reverse(value);
        for (int i = 0; i < reversedValue.length(); i += group)
        {
            string chunk = "";
            for (int j = 0; j < group; j++)
            {
                if (i + j < reversedValue.length())
                {
                    chunk += reversedValue[i + j];
                }
            }
            chunks.push_front(chunk);
        }

        string octal = "";
        for (string chunk : chunks)
        {
            octal += to_string(Binary(reverse(chunk)).toDecimal());
        }

        return stoi(octal);
    }

    string toHexadecimal()
    {
        map<int, string> extra;
        extra[10] = "A";
        extra[11] = "B";
        extra[12] = "C";
        extra[13] = "D";
        extra[14] = "E";
        extra[15] = "F";

        list<string> chunks;
        int group = 4;
        string reversedValue = reverse(value);
        for (int i = 0; i < reversedValue.length(); i += group)
        {
            string chunk = "";
            for (int j = 0; j < group; j++)
            {
                if (i + j < reversedValue.length())
                {
                    chunk += reversedValue[i + j];
                }
            }
            chunks.push_front(chunk);
        }

        string hexadecimal = "";
        for (string chunk : chunks)
        {
            int result = Binary(reverse(chunk)).toDecimal();
            if (extra.count(result))
            {
                hexadecimal += extra[result];
            }
            else
            {
                hexadecimal += to_string(result);
            }
        }

        return hexadecimal;
    }
};

int main()
{
    int octal;
    string binary, hexadecimal;

    Binary b = Binary("101011110101");
    cout << b.toHexadecimal();

    // Decimal decimal = Decimal(345345);
    // binary = decimal.toBinary();
    // octal = decimal.toOctal();
    // hexadecimal = decimal.toHexadecimal();
    // cout << "Decimal(source): " << decimal.value << endl;
    // cout << "Binary: " << binary << endl;
    // cout << "Octal: " << octal << endl;
    // cout << "Hexadecimal: " << hexadecimal << endl;

    return 0;
}