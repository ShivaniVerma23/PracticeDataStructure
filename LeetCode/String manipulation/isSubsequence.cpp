#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool isSubsequence(string s, string t)
{
    int sLen = s.length();
    int tLen = t.length();
    int i{0}, j{0};

    while (i < sLen && j < tLen)
    {
        if (s[i] == t[j])
            j++;
        i++;
    }
    if (j == tLen)
        return true;
    else
        return false;
}

int main()
{
    string comp, substring;
    bool result;

    cout << "Enter complete string" << endl;
    cin >> comp;

    cout << "string to be serached" << endl;
    cin >> substring;

    result = isSubsequence(comp, substring);

    cout << std::boolalpha << result << endl;

    return 0;
}