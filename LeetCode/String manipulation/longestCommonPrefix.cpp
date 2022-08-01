#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

map<char, int> shortString(vector<string> &str)
{
    vector<string>::iterator itr;
    int minSize{0};
    string shorStr;
    map<char, int> charCountMap;

    for (itr = str.begin(); itr != str.end(); itr++)
    {
        int size = itr->size();
        if (minSize == 0)
        {
            minSize = size;
            shorStr = *itr;
        }
        else if (minSize != 0 &&
                 minSize > size)
        {
            minSize = size;
            shorStr = *itr;
        }
    }

    for (int i = 0; i < shorStr.length(); i++)
    {
        charCountMap.insert({shorStr[i], 0});
    }

    return charCountMap;
}

string longestCommonPrefix(vector<string> &strs)
{
    map<char, int> shortestStringMap;
    map<char, int>::iterator mapItr;
    vector<string>::iterator vecitr;

    string output;
    int idx{0};

    int size = strs.size();

    shortestStringMap = shortString(strs);

    for (mapItr = shortestStringMap.begin(); mapItr != shortestStringMap.end(); mapItr++)
    {
        for (vecitr = strs.begin(); vecitr != strs.end(); vecitr++)
        {
            string ss = *vecitr;
            for (int i = 0; i < ss.length(); i++)
            {
                if (mapItr->first == ss[i])
                    mapItr->second++;
            }
        }
    }
    for (mapItr = shortestStringMap.begin(); mapItr != shortestStringMap.end(); mapItr++)
    {
        if (mapItr->second == size)
            output += mapItr->first;
        else
           output = {};
    }
    return output;
}

int main()
{
    vector<string> strVec;
    int numOfStrings{0};
    string output;

    string str;

    cout << "Enter the number of strings" << endl;
    cin >> numOfStrings;

    for (int i = 0; i < numOfStrings; i++)
    {
        cin >> str;
        strVec.push_back(str);
    }

    output = longestCommonPrefix(strVec);

    cout << output << endl;

    return 0;
}