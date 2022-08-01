/*Given an array of unique numbers, return in any order all its permutations.*/

#include <iostream>
#include <vector>

using namespace std;

void permute(vector<int> array, int i, vector<vector<int>> &final)
{
    if (i == array.size())
    {
        final.push_back(array);
    }
    else
    {
        for (int j = i; j < array.size(); j++)
        {
            swap(array[i], array[j]);
            permute(array, i + 1, final);
            swap(array[i], array[j]);
        }
    }
}

vector<vector<int>> get_permutations(vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> result;
    permute(arr, 0, result);

    return result;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> result;

    result = get_permutations(arr);

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