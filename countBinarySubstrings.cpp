#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool checkValidBinaryString(string ss)
{
    bool f = false;
    int count1{0};
    int count0{0};
    for (int i = 0; i < ss.length(); i++)
    {
        if (ss[i] == '0')
        {
            if (count0 != 0 && i != 0 &&
                ss[i] != ss[i - 1])
                return f;
            count0++;
        }
        else
        {
            if (count1 != 0 && i != 0 &&
                ss[i] != ss[i - 1])
                return f;
            count1++;
        }
    }
    if (count0 == count1)
        f = true;

    return f;
}

int countBinarySubstrings(string s)
{
    int count{0};
    int len = s.length();
    string subString;
    bool check;

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 2; j <= len-i; j++)
        {
            subString = s.substr(i, j);
            check = checkValidBinaryString (subString);
            if (check)
              count++;
        }
    }

    return count;
}
int main()
{
    string input;
    cout << "Enter the string" << endl;
    cin >> input;
    int output{0};

    output = countBinarySubstrings(input);

    cout << output << endl;
    return 0;
}