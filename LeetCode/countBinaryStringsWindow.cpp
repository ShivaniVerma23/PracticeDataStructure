#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


int countBinarySubstrings(string s)
{
    int result = 0;
    int prevGroup = 0;
    int currentGroup = 1;
    
    for(int i = 0; i < s.size() - 1; i++){
      if(s[i] == s[i+1]) currentGroup++;
      else {
        result += min(currentGroup, prevGroup);
        prevGroup = currentGroup;
        currentGroup = 1;
      }
    }
    result += min(currentGroup, prevGroup);
    return result;
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