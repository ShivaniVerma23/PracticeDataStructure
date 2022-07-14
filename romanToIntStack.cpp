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
    stack<char> stck;

    for (int i = 0; i < len; i++)
    {
        if (!stck.empty())
        {
            if (s[i] == 'V' && stck.top() == 'I')
            {
                num += 4;
                stck.pop();
            }
            else if (s[i] == 'X' && stck.top() == 'I')
            {
                num += 9;
                stck.pop();
            }
            else if (s[i] == 'L' && stck.top() == 'X')
            {
                num += 40;
                stck.pop();
            }
            else if (s[i] == 'C' && stck.top() == 'X')
            {
                num += 90;
                stck.pop();
            }
            else if (s[i] == 'D' && stck.top() == 'C')
            {
                num += 400;
                stck.pop();
            }
            else if (s[i] == 'M' && stck.top() == 'C')
            {
                num += 900;
                stck.pop();
            }
            else
                stck.push(s[i]);
        }
        else
            stck.push(s[i]);
        
    }
    while (!stck.empty())
    {
        itr = RomanIntMap.find(stck.top());
        if (itr != RomanIntMap.end())
            num += itr->second;
        stck.pop();
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
