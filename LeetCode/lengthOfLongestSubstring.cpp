#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int idx{0};
    int size = s.length();
    unordered_map<char, int> umap;
    int maxLen{0};
    int start{0};

    if (s.empty())
        return 0;

    while (idx < size)
    {
        umap[s[idx]]++;
        while (umap[s[idx]]>1)
        {
            umap[s[start]]--;
            start++;
        }
        maxLen =  max(maxLen, idx -start+1);
        idx++;
    }
    return maxLen;
}
int main()
{
    string str;
    int length{0};

    cout << "Enter the string" << endl;
    cin >> str;

    length = lengthOfLongestSubstring(str);
    cout << length << endl;

    return 0;
}