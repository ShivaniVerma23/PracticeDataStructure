#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

bool isStringPalindrome(string s)
{
    int len = s.length();
    int start{0};
    int end{len - 1};
    bool palindrome{true};
    if (len == 1)
        return palindrome;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            palindrome = false;
            break;
        }
        start++;
        end--;
    }

    return palindrome;
}

bool rotationOfString(string str)
{
    int len = str.length();
    bool check{false};
    int idx{0};
    string temp = str;
    while (idx < len)
    {
        char c = str[idx];
        temp = temp.substr(1, len - 1);
        temp += c;

        check = isStringPalindrome(temp);
        if (check)
            return check;
        idx++;
    }

    return check;
}

bool stringRotationPalindrome(string str)
{
    bool result = rotationOfString(str);
    return result;
}

int main()
{
    string input;
    cout << "Enter the String" << endl;
    getline(cin, input);

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    bool inputCheck = isStringPalindrome(input);

    if (!inputCheck)
    {
        bool output = stringRotationPalindrome(input);
        cout << std::boolalpha << output;
    }
    else
    {
        cout << std::boolalpha << inputCheck;
    }

    return 0;
}