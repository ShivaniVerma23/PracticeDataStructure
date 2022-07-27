#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int root = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && arr[left] > arr[root])
        root = left;
    if (right < n && arr[right] > arr[root])
        root = right;

    if (root != i)
    {
        swap(arr[root], arr[i]);
        heapify(arr, n, root);
    }
}

vector<int> buildMaxHeap(vector<int> arr1, vector<int> arr2, int k)
{
    vector<int> auxArray, result;
    int size1 = arr1.size();
    int size2 = arr2.size();

    for (int i = (size1 / 2) - 1; i >= 0; i--)
    {
        heapify(arr1, size1, i);
    }
    auto it = auxArray.begin();
    for (int j = size1 - 1; j >= size1 - k; j--)
    {
        auxArray.push_back(arr1[0]);
        swap(arr1[0], arr1[j]);
        heapify(arr1, j, 0);
    }

    sort(auxArray.begin(), auxArray.end());

    for (int i = 0; i < size2; i++)
    {
        if (auxArray[0] < arr2[i])
        {
            auxArray[0] = arr2[i];
        }
        sort(auxArray.begin(), auxArray.end());
        result.push_back(auxArray[0]);
    }
    return result;
}

vector<int> kth_largest(int k, vector<int> &initial_stream, vector<int> &append_stream)
{
    return buildMaxHeap(initial_stream, append_stream, k);
}

int main()
{
    vector<int> first_stream = {5};
    vector<int> second_stream = {5};
    int k = 2;
    vector<int> result1;

    result1 = kth_largest(k, first_stream, second_stream);

    for (auto it = result1.begin(); it != result1.end(); it++)
        cout << *it << " ";

    return 0;
}