#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find_intersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
{
    vector<int> intersect;
    int size1 = arr1.size();
    int size2 = arr2.size();
    int size3 = arr3.size();

    int i{0}, j{0}, k{0};

    while (i < size1 && j < size2 && k < size3)
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            intersect.push_back(arr1[i]);
            i++;
            j++;
            k++;
        }
        else
        {
            int val = min({arr1[i], arr2[j], arr3[k]});
            if (arr1[i] <= val)
                i++;
            if (arr2[j] <= val)
                j++;
            if (arr3[k] <= val)
                k++;
        }
    }
    if (intersect.empty())
        intersect.push_back(-1);
    return intersect;
}

int main()
{
    vector<int> arr1 = {1, 5, 10};
    vector<int> arr2 = {2, 3, 4, 10};
    vector<int> arr3 = {2, 4, 10};
    vector<int> result;

    result = find_intersection(arr1, arr2, arr3);

    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << "\t";

    return 0;
}