#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> sortLetterLogs(vector<string> &Letterlogs)
{
    vector<pair<string, string>> subStrings;
    vector<string> sortedLetterLogs;

    for (int i = 0; i < Letterlogs.size(); i++)
    {
        string str = Letterlogs[i];
        int size = str.length();
        for (int j = 0; j < size; j++)
        {
            if (isblank(str[j]))
            {
                string ss = str.substr(j + 1, size - j + 1);
                subStrings.push_back({ss, str});
                break;
            }
        }
    }
    sort(subStrings.begin(), subStrings.end());

    for (auto it : subStrings)
        sortedLetterLogs.push_back((string)it.second);

    return sortedLetterLogs;
}

vector<string> reorderLogFiles(vector<string> &logs)
{
    vector<string> letterLogs;
    vector<string> digitLogs;
    vector<string> final;
    string str;

    int size = logs.size();
    int idx{0};

    while (idx < size)
    {
        str = logs[idx];
        int len = str.length();
        char s[len + 1];
        string ss;
        strcpy(s, str.c_str());

        char *token = NULL;
        token = strtok(s, " ");
        if (token != NULL)
            token = strtok(NULL, " ");
        ss.assign(token);
        if (isdigit(ss[0]))
            digitLogs.push_back(logs[idx]);
        else
            letterLogs.push_back(logs[idx]);
        idx++;
    }
    final = sortLetterLogs(letterLogs);

    for (auto itr = digitLogs.begin(); itr != digitLogs.end(); itr++)
    {
        final.push_back(*itr);
    }
    return final;
}

int main()
{
    vector<string> input;
    vector<string> output;
    int number{0};

    string str;

    cout << "NUmber of strings" << endl;
    cin >> number;

    cin.ignore();
    cout << "Enter the strings" << endl;
    for (int i = 0; i < number; i++)
    {
        getline(cin, str);
        input.push_back(str);
    }

    output = reorderLogFiles(input);

    for (auto itr = output.begin(); itr != output.end(); itr++)
        cout << *itr << "  ";

    return 0;
}