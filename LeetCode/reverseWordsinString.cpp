#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string removeLeadingTrailingspaces(string str)
{
    string out;
    int len = str.length();
    int firstCharIdx{0};
    int lastCharIdx{0};
    bool firstIdxset{false};
    for (int i = 0; i < len; i++)
    {
        if (!firstIdxset &&
            !isblank(str[i]))
            {
                firstIdxset = true;
            }
        if (isblank(str[i]) && 
            lastCharIdx == 0 &&
            !firstIdxset)
            firstCharIdx = i+1;
        else if (!isblank(str[i]))
                lastCharIdx = i;
    }
    out = str.substr(firstCharIdx, lastCharIdx-firstCharIdx +1);
    return out;
}

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
}
string reverseWordsInString(string ss, vector<int> &SpaceIndex)
{
    string result;
    int len = ss.length();
    vector<int> :: reverse_iterator revit;
    int prevSpaceIdx{len};
    for (revit = SpaceIndex.rbegin(); revit != SpaceIndex.rend(); revit++)
    {
           string str1 = ss.substr(*revit+1, prevSpaceIdx - (*revit+1));

           result.append(str1);
           result.append(" ");
           prevSpaceIdx = *revit;
    }
    string lastWord = ss.substr(0, prevSpaceIdx-0 );

    result.append(lastWord);
    return result;
}
string removeExtraSpaces(string str)
{
    string out;
    int len = str.length();
    bool spacefound {false};
    int pos{0};
    for (int i = 0 ; i < len; i++ )
    {
        if (!isblank(str[i]))
        {
            out[pos] = str[i];
            pos++;
            spacefound = false;
        }
        else if (!spacefound)
        {
            out[pos] = str[i];
            pos++;
            spacefound = true;;
        }   
    }
    out[pos]  = '\0';
    return out.c_str();


}

string reverseString(string str)
{
    string finalStr;
    string withoutLTSpace;
    string finalStrwithonespace;
    withoutLTSpace = removeLeadingTrailingspaces(str);
    vector<int> spaceIndex;
    spaceIndices(withoutLTSpace, spaceIndex);
    finalStr = reverseWordsInString(withoutLTSpace, spaceIndex);
    finalStrwithonespace = removeExtraSpaces (finalStr);
    return finalStrwithonespace.c_str();
}

int main()
{
    string s = "Alice does not even like bob";
    cout << s << endl;
    cout << reverseString(s) << endl;
    return 0;
}