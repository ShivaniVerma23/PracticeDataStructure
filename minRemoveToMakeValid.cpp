#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string minRemoveToMakeValid(string s)
{
    int size = s.length();

    int idx{0};
    stack<pair<char, int>> stck;

    while (idx < size)
    {
        if (s[idx] == ')' && stck.empty())
        {
            s.erase(idx, 1);
            size--;
        }
        else if (s[idx] == '(')
        {
            stck.push({s[idx], idx});
            idx++;
        }
        else if (s[idx] == ')')
        {
            stck.pop();
            idx++;
        }
        else
            idx++;
    }
    while(stck.empty()==0)
    {
        auto it =  stck.top();
        s.erase(it.second, 1);
        stck.pop();
    }

        return s;
}

int main()
{
    string str, result;

    cout << "Enter the string" << endl;
    cin >> str;

    result = minRemoveToMakeValid(str);
    cout << result << endl;

    return 0;
}