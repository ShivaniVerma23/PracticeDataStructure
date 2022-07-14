#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    int size = s.length();
    bool check = true;
    int left{0}, right{0};
    int idx{0};

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    while (idx <= size)
    {
        if (!isalnum(s[idx]))
        {
            s.erase(idx, 1);
            size--;
        }
        else
            idx++;
    }
    if (s.empty())
        return check;

    right = s.length() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
        {
            check = false;
            break;
        }
        left++;
        right--;
    }

    return check;
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