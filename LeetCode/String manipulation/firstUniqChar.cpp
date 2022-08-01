#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int firstUniqChar(string s)
{
 unordered_map<char, int>umap;

    int size = s.length();
    char c;
    int idx{0};

    while(idx<size)
    {
        umap[s[idx]]++;
        idx++;
    }
    idx = 0;
    while(idx<size)
    {
        auto it = umap.find(s[idx]);
        if (it->second == 1 )
        {
            return idx;
        }
        idx++;
    }
    return -1;
}

int main()
{
    string n1;
    int output{0};

    cout << "Enter a string" << endl;
    cin >> n1;

    output = firstUniqChar(n1);

    cout << output << endl;
    return 0;
}