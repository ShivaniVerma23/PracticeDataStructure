#include <iostream>
#include <vector>
#include<string>
#include <bits/stdc++.h>

using namespace std;

int divisorSubstrings(int num, int k)
{
    int output{0};
    int  j{0};
    int count{0};
    string subString;

    string str = to_string(num);

    int size = str.length();

    while (j < size)
    {
        subString += str[j];
        j++;
        count++;
        if (count >= k)
        {
            int divisor = atoi(subString.c_str());

            if (divisor != 0 &&
                num % divisor == 0)
                output++;
            subString.erase(0,1);
            count--;
        }
    }
    return output;
}

int main()
{
    int number{0};
    int sizeofSubStr{0};
    int KBeauty;

    cout << "enter the Number" << endl;
    cin >> number;

    cout << "Sizeof Sub String" << endl;
    cin >> sizeofSubStr;

    KBeauty = divisorSubstrings(number, sizeofSubStr);

    cout << " KBeauty of num is :: " << KBeauty << endl;

    return 0;
}