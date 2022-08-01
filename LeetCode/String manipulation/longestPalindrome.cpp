#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int longestPalindrome(string s)
{
    unordered_map<char, int> mp;
    int len{0};
    bool flag{false};

    for (auto i : s)
        mp[i]++;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second % 2 == 0)
        {
            len += it->second;
        }
        else
        {

            len += (it->second - (it->second % 2));
            flag = true;
        }
    }
    if (flag)
        len++;
    return len;
}

int main()
{
    string str;
    int maxPalindLen{0};

    cout << "enter the string" << endl;
    cin >> str;

    maxPalindLen = longestPalindrome(str);

    cout << maxPalindLen << endl;
    return 0;
}
