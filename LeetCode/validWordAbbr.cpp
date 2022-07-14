#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool validWordAbbreviation(string word, string abbr)
{
    int wordSize = word.length();
    int abbrSize = abbr.length();
    int num{0};

    int j{0}, i{0};

    while (j < abbrSize && i < wordSize)
    {
        if (isdigit(abbr[j]))
        {
            if (abbr[j] == '0' && num == 0)
                return false;
            else
            {
                num = num * 10 + (abbr[j] - '0');
                j++;
            }
        }
        else
        {
            if (num==0)
            {
                if (abbr[j] != word[i])
                  return false;
                else
                {
                    i++;
                    j++;
                }
            }
            else
            {
                i+=num;
                num=0;
            }
        }
        
    }
    if (num!=0)
       i+=num;
    return i == wordSize && j == abbrSize;
}
int main()
{
    string input;
    string abbreviation;

    bool result;

    cout << "Enter the word" << endl;
    cin >> input;

    cout << "Enter the abbreviation" << endl;
    cin >> abbreviation;

    result = validWordAbbreviation(input, abbreviation);

    cout << std::boolalpha << result << endl;

    return 0;
}