/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    unordered_map<int, int> umap;
    set<vector<int>> final;
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++)
        umap[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int k = 0 - (nums[i] + nums[j]);
            auto uit = umap.find(k);
            if (uit != umap.end())
            {
                if (uit->second != i &&
                    uit->second != j)
                    result.push_back({nums[i], nums[j], nums[uit->second]});
            }
        }
    }
    for (auto it = result.begin(); it != result.end(); it++)
    {
        sort(it->begin(), it->end());
    }
    sort(result.begin(), result.end());
    for (auto it = result.begin(); it != result.end(); it++)
    {
        final.insert(*it);
    }

    result.clear();
    for (auto sit = final.begin(); sit != final.end(); sit++)
        result.push_back(*sit);

    return result;
}

int main()
{
    vector<vector<int>> result;
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    result = threeSum(nums);

    for (auto it = result.begin(); it != result.end(); it++)
    {
        for (auto itr = it->begin(); itr != it->end(); itr++)
        {
            cout << *itr << " ";
        }
        cout << endl;
    }
    return 0;
}
