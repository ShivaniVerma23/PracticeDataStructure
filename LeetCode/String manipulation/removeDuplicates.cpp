#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string removeDuplicates(string s)
{
    int len = s.length();
    int idx{1};

    while (idx < len)
    {
        if (s[idx] == s[idx - 1])
        {
            s.erase(idx - 1, 2);
            len -= 2;
            idx -= 2;
            if (idx <=0)
               idx=1;
        }
        else
            idx++;
    }
    return s;
}

int main()
{
    string input, output;

    cout << "Enter the string";
    cin >> input;
    output = removeDuplicates(input);
    cout << output << endl;
    return 0;
}