#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool isomorphicStrings(string s, string t)
{
    map<char, char> characterMap;
    map<char, char>::iterator itrS;
    map<char, char>::iterator itrT;
    int slen = s.length();
    int tlen = t.length();

    if (slen != tlen)
        return false;

    characterMap.insert({s[0], t[0]});

    for (int i = 1; i < slen; i++)
    {
        itrS = characterMap.find(s[i]);
        if (itrS == characterMap.end())
        {
            for (itrT = characterMap.begin(); itrT != characterMap.end(); itrT++)
            {
                if (itrT->second == t[i])
                    return false;
            }
            characterMap.insert({s[i], t[i]});
        }
        else if (itrS->second != t[i])
            return false;
    }
    return true;
}

int main()
{
    string str1;
    string str2;
    bool result;

    cout << "Enter two strings in two lines" << endl;
    cin >> str1;
    cin >> str2;

    result = isomorphicStrings(str1, str2);
    cout << std::boolalpha << result << endl;

    return 0;
}