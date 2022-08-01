#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

map<char, int> romanInT()
{
    map<char, int> romanIntmap;
    romanIntmap.insert({'I', 1});
    romanIntmap.insert({'V', 5});
    romanIntmap.insert({'X', 10});
    romanIntmap.insert({'L', 50});
    romanIntmap.insert({'C', 100});
    romanIntmap.insert({'D', 500});
    romanIntmap.insert({'M', 1000});
    return romanIntmap;
}

int convertRomanToInt(string s, map<char, int> RomanIntMap)
{
    map<char, int>::iterator itr;
    int len = s.length();
    int idx{0};
    int num{0};

    while (idx < len)
    {
        itr = RomanIntMap.find(s[idx]);
        if (itr != RomanIntMap.end())
        {
            if (itr->first == 'I')
            {
                if (idx < len - 1 && s[idx + 1] == 'V')
                {
                    num += 4;
                    idx += 2;
                }
                else if (idx < len - 1 && s[idx + 1] == 'X')
                {
                    num += 9;
                    idx += 2;
                }
                else
                {
                    num += 1;
                    idx++;
                }
            }
            if (itr->first == 'X')
            {
                if (idx < len - 1 && s[idx + 1] == 'L')
                {
                    num += 40;
                    idx += 2;
                }
                else if (idx < len - 1 && s[idx + 1] == 'C')
                {
                    num += 90;
                    idx += 2;
                }
                else
                {
                    num += 10;
                    idx++;
                }
            }
            if (itr->first == 'C')
            {
                if (idx < len - 1 && s[idx + 1] == 'D')
                {
                    num += 400;
                    idx += 2;
                }
                else if (idx < len - 1 && s[idx + 1] == 'M')
                {
                    num += 900;
                    idx += 2;
                }
                else
                {
                    num += 100;
                    idx++;
                }
            }
            if (itr->first == 'V')
            {
              num+=itr->second;
              idx++;
            }
            else if(itr->first == 'L')
            {
              num+=itr->second;
              idx++;
            }
            else if(itr->first == 'D')
            {
              num+=itr->second;
              idx++;
            }
            else if(itr->first == 'M')
            {
              num+=itr->second;
              idx++;
            }
        }
    }
    return num;
}

int main()
{
    map<char, int> romanIntMap;
    string roman;
    int number{0};

    cout << "Enter the string" << endl;
    cin >> roman;

    romanIntMap = romanInT();
    number = convertRomanToInt(roman, romanIntMap);

    cout << number << endl;

    return 0;
}
