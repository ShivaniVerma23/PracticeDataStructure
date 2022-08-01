#include <iostream>
#include <string>
#include <map>
#include <bits/stdc++.h>

using namespace std;

map<string, int> prepareWordsCountMap(vector<string> &wordsArr, int numWords)
{
    map<string, int> wordCountMap;

    for (int i = 0; i < numWords; i++)
    {
        wordCountMap.insert({wordsArr[i], 0});
    }

    return wordCountMap;
}

map<string, int> countWordsInString(string s, map<string, int> &wordsCountMap)
{
    map<string, int>::iterator it;
    int sizeOfString = s.length();

    char copy[sizeOfString + 1];
    strcpy(copy, s.c_str());

    char *token = NULL;
    token = strtok(copy, " ");

    while (token != NULL)
    {
        it = wordsCountMap.find(token);
        if (it != wordsCountMap.end())
        {
            int count = it->second;
            count += 1;
            it->second = count;
        }
        token = strtok(NULL, " ");
    }

    return wordsCountMap;
}

int main()
{
    vector<string> arr;
    string individualString;
    string str;
    map<string, int> wordCount;
    map<string, int>::iterator itr;
    int numberofWords;
    int count{0};

    cout << "Enter the number of words :" << endl;
    cin >> numberofWords;

    cout << "Enter the Words" << endl;
    for (int i = 0; i < numberofWords; i++)
    {
        cin >> individualString;
        arr.push_back(individualString);
    }

    cin.ignore();
    cout << "Enter the String to be searched for Words" << endl;
    getline(cin, str);

    wordCount = prepareWordsCountMap(arr, numberofWords);

    wordCount = countWordsInString(str, wordCount);

    for (auto itr = wordCount.begin(); itr != wordCount.end(); itr++)
    {
        cout << itr->first << '\t' << itr->second << '\n';
        if (itr->second != 0)
        {
            count++;
        }
    }
    cout << "No. of words found in string : " << count <<endl;

    return 0;
}