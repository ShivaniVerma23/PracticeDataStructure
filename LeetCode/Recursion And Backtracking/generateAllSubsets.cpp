/*Generate ALL possible subsets of a given set. The set is given in the form of a string s containing distinct lowercase characters 'a' - 'z'.*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void subsets(string &s, int i, vector<char> &ch, vector<string> &result)
{
    if (i == s.size())
    {
        if (!ch.empty())
        {
            string str(ch.begin(), ch.end());
            result.push_back(str);
        }
        else
          result.push_back(" "); 
    }
    else
    {
        ch.push_back(s[i]); // inclusion
        subsets(s, i + 1, ch, result);
        ch.pop_back();
        subsets(s, i + 1, ch, result);
    }
}
vector<string> generate_all_subsets(string &s)
{
    // Write your code here.

    vector<string> result;
    vector<char> array;

    subsets(s, 0, array, result);
    return result;
}

int main()
{
    string s = "a1b2";
    vector<string> result;

    result = generate_all_subsets(s);

    for (auto it = result.begin(); it != result.end(); it++)
    {
        cout << *it << "\t";
    }
    return 0;
}