#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int root = i;

    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && arr[root] < arr[left])
        root = left;
    if (right < n && arr[root] < arr[right])
        root = right;
    if (root != i)
    {
        swap(arr[root], arr[i]);
        heapify(arr, n, root);
    }
}

void buildHeap(vector<int> &arr, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void maxHeap(vector<int> &arr, int n, int k)
{
    for (int i = n - 1; i >= n-k; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int kth_largest_in_array(vector<int> &arr, int k)
{
    int num = arr.size();
    buildHeap(arr, num);
    maxHeap(arr, num, k);
    return arr[num-k];
}

int main()
{
    vector<int> numbers = {1, 1, 1, 3, 5, 4, 6};
    int k = 3;
    int result{0};

    result = kth_largest_in_array(numbers, k);

    cout << result << endl;

    return 0;
}