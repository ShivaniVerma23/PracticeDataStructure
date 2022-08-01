#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool wordPattern(string ptrn, string s)
{
    char *token = NULL;
    const char delim[] = " ";
    int tokenCount{1};
    map<char, string> wordPtrnMap;
    map<char, string>::iterator itrP;
    map<char, string>::iterator itrW;

    int stringlen = s.length();
    int patternlen = ptrn.length();

    char copy[stringlen + 1];
    strcpy(copy, s.c_str());

    for (int i = 0; i < stringlen; i++)
    {
        if (isblank(s[i]))
            tokenCount++;
    }

    if (tokenCount != patternlen)
        return false;

    token = strtok(copy, delim);

    wordPtrnMap.insert({ptrn[0], token});

    for (int i = 1; i < patternlen && token != NULL; i++)
    {
        token = strtok(NULL, delim);
        if (token != NULL)
        {
            itrP = wordPtrnMap.find(ptrn[i]);
            if (itrP == wordPtrnMap.end())
            {
                for (itrW = wordPtrnMap.begin(); itrW != wordPtrnMap.end(); itrW++)
                {
                    if ((itrW->second == token))
                       return false;

                    else 
                    {
                        wordPtrnMap.insert({ptrn[i], token});
                        break;
                    }
                }
            }    
            else if (itrP->second != token)
              return false;
        }
    }

    return true;
}

int main()
{
    string pattern;
    string str;
    bool output;

    cout << "Enter the pattern" << endl;
    cin >> pattern;
    cin.ignore();
    cout << " Enter the string" << endl;
    getline(cin, str);

    output = wordPattern(pattern, str);

    cout << boolalpha << output << endl;

    return 0;
}