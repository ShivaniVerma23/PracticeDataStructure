#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int k, int i)
{
    int root = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < k && arr[left] < arr[root])
        root = left;
    if (right < k && arr[right] < arr[root])
        root = right;

    if (root != i)
    {
        swap(arr[i], arr[root]);
        heapify(arr, k, root);
    }
}

int minheap(vector<int> &arr, int n, int k)
{
    for (int i = (k / 2) - 1; i >= 0; i--)
    {
        heapify(arr, k, i);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] > arr[0])
        {
            swap(arr[i], arr[0]);
            heapify(arr, k, 0);
        }
    }
    return arr[0];
}

int kth_largest_in_an_array(vector<int> &numbers, int k)
{
    // Write your code here.
    return minheap(numbers, numbers.size(), k);
}

int main()
{
    vector<int> numbers = {5, 1, 10, 3, 2};
    int k = 2;
    int result{0};

    result = kth_largest_in_an_array(numbers, k);

    cout << result << endl;

    return 0;
}