#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> prepare2darray(int r)
{
    int num;
    int c;
    vector<vector<int>> matrix;
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;

    for (int i = 0; i < r; i++)
    {
        cout << "Enter the number of integers in array " << i + 1 << endl;
        cin >> c;
        vector<int> p;
        for (int j = 0; j < c; j++)
        {
            cin >> num;
            p.push_back(num);
        }
        matrix.push_back(p);
    }

    for (row = matrix.begin(); row != matrix.end(); row++)
    {
        cout << "{ ";
        for (col = row->begin(); col != row->end(); col++)
        {
            cout << *col << " ";
        }
        cout << " }\t ";
    }
    cout << "--------------------" << endl;
    return matrix;
}

map<int, int> minVecLen(vector<vector<int>> &vec)
{
    int minLen{0};
    vector<vector<int>>::iterator minitr;
    vector<vector<int>>::iterator itr;
    map<int, int> countMap;

    for (itr = vec.begin(); itr != vec.end(); itr++)
    {
        int size = itr->size();
        if (minLen != 0 &&
            minLen > size)
        {
            minLen = size;
            minitr = itr;
        }
        else if (minLen == 0)
        {
            minLen = size;
            minitr = itr;
        }
    }
    for (auto Itr = minitr->begin(); Itr != minitr->end(); Itr++)
        countMap.insert({*Itr, 0});

    return countMap;
}

vector<int> intersection(vector<vector<int>> &nums)
{
    vector<int> output;
    int minimumSizeArray{0};
    map<int, int> CountMap;
    map<int, int>::iterator it;
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    int rows{0};

    int numofArrays = nums.size();

    CountMap = minVecLen(nums);

    for (it = CountMap.begin(); it != CountMap.end(); it++)
    {
        for (row = nums.begin(); row != nums.end(); row++)
        {
            for (col = row->begin(); col != row->end(); col++)
            {
                if (it->first == *col)
                    it->second++;
            }
        }
    }

    for (auto mapItr = CountMap.begin(); mapItr != CountMap.end(); mapItr++)
    {
        if (mapItr->second == numofArrays)
            output.push_back(mapItr->first);
    }

    return output;
}

int main()
{
    vector<int> result;
    vector<int>::iterator itr;
    int rows{0};
    int num;

    vector<vector<int>> twoDArray;

    cout << "Enter the number of arrays" << endl;
    cin >> rows;

    twoDArray = prepare2darray(rows);

    result = intersection(twoDArray);

    for (itr = result.begin(); itr != result.end(); itr++)
        cout << *itr << "\t";

    return 0;
}
