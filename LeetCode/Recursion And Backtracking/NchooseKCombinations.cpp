/*Given two integers n and k, find all the possible unique combinations of k numbers in range 1 to n.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void all_combinations(vector<int>&arr, int k, int i, vector<int>& slate, vector<vector<int>> &result)
{
    if (slate.size() == k)
    {
        result.push_back(slate);
    }
    else
    {
        for (int j = i; j < arr.size(); j++)
        {
            slate.push_back(arr[j]);
            all_combinations(arr, k, j+1,slate, result);
            slate.pop_back();
        }
    }
}

vector<vector<int>> find_combinations(int n, int k)
{
    // Write your code here.
    vector<vector<int>> result;
    vector<int> perCombination;
    vector<int>arr;

    for (int i=1; i<=n; i++)
      arr.push_back(i);
    all_combinations(arr, k, 0, perCombination, result);
    return result;
}

int main()
{
    int range = 3;
    int combination_size = 2;

    vector<vector<int>> result;

    result = find_combinations(range, combination_size);

    for (auto it = result.begin(); it != result.end(); it++)
    {
        for (auto itr = it->begin(); itr != it->end(); itr++)
        {
            cout << *itr << "\t";
        }
        cout << endl;
    }
    return 0;
}