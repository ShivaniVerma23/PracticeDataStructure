#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

void merge_arrays(vector<int>&fs, vector<int>&ss)
{
    int fSize = fs.size() -1; //5
    int sSize = ss.size() -1; //2

    int leftSize = fSize - sSize -1; 

    while(leftSize >= 0 && sSize >= 0)
    {
        if (ss[sSize] > fs[leftSize])
        {
            fs[fSize] = ss[sSize];
            sSize--;
        }
        else
        {
            fs[fSize] = fs[leftSize];
            leftSize--;   
        }
        fSize--;
    }
    while (sSize >= 0)
    {
        fs[fSize] = ss[sSize];
        fSize--;
        sSize--;
    }

}

int main()
{
    vector<int> nums1 = {4, 5, 6, 0, 0, 0};
    vector <int> nums2 = {1, 2, 3};

    merge_arrays(nums1, nums2);

    for (auto it = nums1.begin(); it!= nums1.end(); it++)
        cout << *it <<"\t";

    return 0;
}