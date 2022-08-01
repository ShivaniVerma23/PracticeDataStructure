#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string addStrings(string num1, string num2)
{
    string result;
    int add{0};
    int len1 = num1.length() - 1;
    int len2 = num2.length() - 1;
    int carry{0};

    while (len1 >= 0 || len2 >= 0)
    {
        int total{0};
        int a{0}, b{0};
        if (len1 >= 0)
        {
            a = num1[len1] - '0';
            len1--;
        }
        if (len2 >= 0)
        {
            b = num2[len2] - '0';
            len2--;
        }
        total = a + b + carry;
        add = (a + b) % 10 + carry;
        if (total < 10)
        {
            result.push_back(add + '0');
            carry =0;
        }
        else
        {
            result.push_back((total % 10) + '0');
            carry = total / 10;
        }
    }
    if (carry !=0)
       result.push_back(carry + '0');
    reverse(result.begin(), result.end());
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