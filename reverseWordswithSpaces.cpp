#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void spaceIndices(string s, vector<int> &spaceIndex)
{
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (isblank(s[i]))
        {
            spaceIndex.push_back(i);
        }
    }
    for (int j = 0; j< spaceIndex.size() ;j++)
      cout << spaceIndex[j] <<"  ";
    cout <<endl;
}
string reverseCharInString(string ss, vector<int> &SpaceIndex)
{
    
    int idx{0};
    size_t  len =ss.length();
    string result(len, ' ');
    vector<char> copy;
    for (int i = 0; i<len;i++)
        copy.push_back(ss[i]);

    vector <char> :: const_reverse_iterator  it;
    int pos{0};
    
    cout << "len " <<len <<endl;
    for (it = copy.rbegin(); it != copy.rend();it++)
    {
        if (idx < SpaceIndex.size() && pos == SpaceIndex[idx])
        {
            result[pos] = ' ';
            pos++;
            idx++;
            it--;
        }
        else if (!isblank(*it))
        {
            result[pos] = *it;
            pos++;
        }
    }
    result[pos] = '\0';
    return result.c_str();
}

string reverseString(string str)
{
    string finalStr;
    vector<int> spaceIndex;
    spaceIndices(str, spaceIndex);
    finalStr = reverseCharInString(str, spaceIndex);
    return finalStr.c_str();
}

int main()
{
    string s = "aa.. bb.. cc.. dddd eeee fff!!! @@ vv qaq wesd redf olo oo fdr the";
    cout << reverseString(s) << endl;
    return 0;
}