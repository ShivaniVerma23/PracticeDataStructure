#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

map<string, int> stringEachWord(string s)
{
    map<string, int> countWordMap;
    map<string, int>::iterator itr;
    int len = s.length();

    char copy[len + 1];
    strcpy(copy, s.c_str());

    char *token = NULL;
    token = strtok(copy, " ");

    countWordMap.insert({token, 1});

    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (token != NULL)
        {
            itr = countWordMap.find(token);
            if (itr != countWordMap.end())
            {
                itr->second++;
            }
            else
            {
                countWordMap.insert({token, 1});
            }
        }
    }
    cout << endl;
    return countWordMap;
}

int main()
{
    string str;
    map<string, int> countEachWordMap;
    map<string, int>::iterator it;

    cout << "Enter the string" << endl;
    getline(cin, str);

    countEachWordMap = stringEachWord(str);

    for (auto itr = countEachWordMap.begin(); itr != countEachWordMap.end(); itr++)
        cout << itr->first << "\t" << itr->second << endl;

    return 0;
}