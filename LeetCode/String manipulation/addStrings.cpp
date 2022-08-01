#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int convertStringtoInt(string s)
{
    int len = s.length();
    int size = len;
    int idx{0};
    int number{0};

    while (idx < size)
    {
        int digit = s[idx] - '0';
        int power = pow(10, --len);
        number += (digit * pow(10, --len));
        idx++;
    }

    return number;
}

string addStrings(string num1, string num2)
{
    int n1{0}, n2{0};
    string result;

    n1 = convertStringtoInt(num1);
    n2 = convertStringtoInt(num2);

    long int add = n1 + n2;

    result = to_string(add);
    return result;
}

int main()
{
    string n1, n2, output;

    cout << "Enter two strings" << endl;
    cin >> n1;
    cin >> n2;

    output = addStrings(n1, n2);

    cout << output << endl;
    return 0;
}