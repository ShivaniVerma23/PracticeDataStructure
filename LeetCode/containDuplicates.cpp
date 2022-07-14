#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    int i{0}, j{0}, size = nums.size();

    bool result{false};

    unordered_map<int, int> mp;

    while (j < size)
    {
        mp[nums[j]]++;
        if (mp[nums[j]] >= 2)
            return true;
        if (mp.size() >= k + 1)
        {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);
            i++;
        }
        j++;
    }

    return result;
}

int main()
{
    int num{0};
    int input{0};
    vector<int> array;
    int sizeofIndex{0};
    bool output{false};

    cout << "Enter the indixes length to be looked for Duplicates" << endl;
    cin >> sizeofIndex;

    cout << "Enter the number of integers you want to enter in Array" << endl;
    cin >> num;

    cin.ignore();
    cout << "Enter the Integers now" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> input;
        array.push_back(input);
    }

    output = containsNearbyDuplicate(array, sizeofIndex);

    cout << std::boolalpha << output << endl;

    return 0;
}
