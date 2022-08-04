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
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if(i>0 && nums[i-1] == nums[i]) continue;
        int l = i + 1;
        int r = nums.size() - 1;

        while (l < r)
        {
            if ((nums[i] + nums[l] + nums[r]) < 0)
                l++;
            else if ((nums[i] + nums[l] + nums[r]) > 0)
                r--;
            else
            {
                result.push_back({nums[i], nums[l], nums[r]});
                l++;
                while(l<r &&nums[l]==nums[l-1])
						l++;
					r--;
					while(l<r &&nums[r]==nums[r+1])
						r--;
            }
        }
    }
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
