#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int pivotIndex(vector<int> &nums)
{
    int size = nums.size();
    int rightSum{0};
    int leftSum{0};
    int pivot{-1};
    int idx{1};

    for (auto it = nums.begin(); it != nums.end(); it++)
        rightSum += (*it);
    
    rightSum-=nums[0];
    while (idx < size)
    {
        if (leftSum == rightSum)
        {
            pivot = idx - 1;
            break;
        }
        else
        {
            leftSum += nums[idx -1];
            rightSum -= nums[idx];
        }
        if (idx == size-1)
           rightSum = 0;

        idx++;
    }
    if (pivot == -1 &&
        (rightSum == leftSum))
        pivot = size-1;

    return pivot;
}

int main()
{
    vector<int> input{1,2,3};
    int result{0};

    result = pivotIndex(input);

    cout << result << endl;
    return 0;
}