#include <iostream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector <int> lengthOfStrings(vector <string>&stringArray)
{
      vector<int>lengths;
      vector <string> :: iterator it;
      for ( it = stringArray.begin(); it != stringArray.end(); it++ )
      {
          int size = (*it).length();
          lengths.push_back(size);
      }
      sort(lengths.begin(), lengths.end());
      
      return lengths;
}

vector <string>sortingStrings(vector<string>&ss , vector<int>&len)
{
    vector<string>output;
    vector<int> :: iterator it;
    vector <string> :: iterator strit;

    for ( it = len.begin(); it != len.end() ; it++)
    {
        for ( strit = ss.begin(); strit != ss.end(); strit++)
        {
            if ((*it) == (*strit).size())
            {
                output.push_back(*strit);
                ss.erase(strit);
                break;
            }
        }
    }
    return output;
}

vector<string>sortStringArray(vector<string>&ssArray)
{
    vector<int> strlengths = lengthOfStrings (ssArray);
    vector <string> result = sortingStrings(ssArray, strlengths);

    return result;
}

vector<string>convertArrayToVector(string strarr[], int size)
{  
    vector <string> strVect;
    for (int i=0 ; i< size ; i++)
    {
        strVect.push_back(strarr[i]);
    }

    return strVect;
}

int main()
{
   string arr[] = {"GeeksforGeeks", "I", "from", "am"};
   int len = sizeof(arr)/sizeof(arr[0]);
   vector<string>strArray = convertArrayToVector(arr, len);
   vector<string>result = sortStringArray(strArray);
   vector<string> :: iterator it;

   for ( it = result.begin(); it != result.end(); it++ )
   {
       cout << *it << " ";   
   }
}