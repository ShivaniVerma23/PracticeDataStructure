#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    int size = s.length();
    int right{size - 1}, left{0};
    int count{0};

    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            count++;
            left++;
        }
    }
    if (count <= 1)
        return true;

    count = 0;
    left = 0;
    right = s.length() - 1;

    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            count++;
            right--;
        }
    }
    if (count > 1)
        return false;
    else
        return true;
}

int main()
{
    string input;
    bool output;

    cout << "Enter the String" << endl;
    getline(cin, input);

    output = isPalindrome(input);
    cout << std::boolalpha << output << endl;

    return 0;
}