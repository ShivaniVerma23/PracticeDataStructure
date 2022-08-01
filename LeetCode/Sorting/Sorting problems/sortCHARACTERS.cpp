#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<char> &arr, int n, int i)
{
    int root = i;

    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n &&
        (int)arr[left] > (int)arr[root])
        root = left;
    if (right < n &&
        (int)arr[right] > (int)arr[root])
        root = right;
    if (root != i)
    {
        swap(arr[root], arr[i]);
        heapify(arr, n, root);
    }
    return;
}

void maxHeap(vector<char> &arr, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return;
}

void heapSort(vector<char> &arr, int n)
{
    for (int i = n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    return;
}

vector<char> sort_array(vector<char> &arr)
{
    maxHeap(arr, arr.size());
    heapSort(arr, arr.size());
    return arr;
}

int main()
{
    vector<char> first_stream = {'a', 's', 'd', 'f', 'g', '*', '&', '!', 'z', 'y'};

    vector<char> result1;

    result1 = sort_array(first_stream);

    for (auto it = result1.begin(); it != result1.end(); it++)
        cout << *it << " ";

    return 0;
}