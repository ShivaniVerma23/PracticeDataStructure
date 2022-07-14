#include <iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nn, int low, int high, int target)
{
    
    int index{-1};
    
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (target == nn[mid])
        return mid;

        if (target < nn[mid])
        {
            high = mid - 1;
        }
        if (target > nn[mid])
        {
            low = mid + 1;
        }
        return binarySearch(nn, low, high, target);
    }

    return index;
}

int search(vector<int> nums, int target)
{
    int result{0};
    int lo{0};
    int len = nums.size();
    int hi{len - 1};

    result = binarySearch(nums, lo, hi, target);

    return result;
}

int main()
{
    int countOfNums{0};
    vector<int> Nums;
    int number{0};
    int index{0};
    int target{0};

    cout << "Enter the count" << endl;
    cin >> countOfNums;

    cout << "enter the target" << endl;
    cin >> target;

    cout <<"Enter the numbers" <<endl;
    for (int i = 0; i < countOfNums; i++)
    {
        cin >> number;
        Nums.push_back(number);
    }

    index = search(Nums, target);

    cout << index << endl;

    return 0;
}