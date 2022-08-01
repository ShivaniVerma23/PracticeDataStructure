#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int CountGoodSubstrings(string s)
{
    int i{0}, j{0}, count{0};
    int size = s.length();
    int numOfGoodSubStrings{0};

    string substring;

    while (j < size )
    {
        substring += s[j];

        count++;

        if (j != 0 )
        {
            if (substring[i] != substring[i + 1])
            {
                i++;
                if (count == 3 &&
                    substring[0] != substring[2] )
                {
                    numOfGoodSubStrings++;
                    substring.erase(0, 1);
                    count--;
                    i--;
                }
                else if (count==3)
                {
                    substring.erase(0, 1);
                    count--;
                    i--;
                }
            }
            else
            {
                if (substring.length() < 3)
                {
                    substring.erase(0, 1);
                    count--;
                }
                else
                {
                     substring.erase(0, 2);
                    count=1;
                    i = 0;
                }
            }
        }
        j++;
    }
    return numOfGoodSubStrings;
}

int main()
{
    string input;
    int output{0};

    cout << "Enter the String" << endl;
    cin >> input;

    output = CountGoodSubstrings(input);

    cout << "Number of good Substrings" << output << endl;
    return 0;
}