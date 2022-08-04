/*Find all palindromic decompositions of a given string s.

A palindromic decomposition of string is a decomposition of the string into substrings, such that all those substrings are valid palindromes.*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

bool check_palindrome(string &s, int left, int right)
{
    bool check = true;
    if (s.empty())
        return false;

    while (left <= right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
            return false;
    }
    return check;
}

void generate_palindrome_string_subsets(string &s, int i, string &temp, vector<string> &result)
{
    if (i == s.size())
    {
        result.push_back(temp);
        return;
    }
    else
    {
        for (int j = i; j < s.size(); j++)
        {
            cout << "I {" <<i<<"}" << " and J {" <<j<<"}" <<endl;

            if (check_palindrome(s, i, j))
            {
                cout << "Palindrome" <<endl;
                if (!temp.empty())
                    temp.push_back('|');
                temp += s.substr(i, j - i + 1);
                cout <<temp <<endl;
                generate_palindrome_string_subsets(s, i + 1, temp, result);

cout << "Before popping I {" <<i<<"}" << " and J {" <<j<<"}" <<endl;

                for (int k = 0; k < j - i + 1; k++)
                    temp.pop_back();
                if (!temp.empty())
                    temp.pop_back();
            }

            cout <<" -------------------------- "<<endl;
        }
    }
    return;
}
vector<string> generate_palindromic_decompositions(string &s)
{
    // Write your code here.
    vector<string> final;
    string temp;

    generate_palindrome_string_subsets(s, 0, temp, final);

    return final;
}

int main()
{
    string ip = "cac";
    vector<string> output;

    output = generate_palindromic_decompositions(ip);

    for (auto it = output.begin(); it != output.end(); it++)
        cout << *it << "--------";

    cout << endl;

    return 0;
}