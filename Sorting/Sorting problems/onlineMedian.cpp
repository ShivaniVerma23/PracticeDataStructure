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

void heapify_node(vector<int> &arr, int n, int i)
{
    int parent = (i - 1) / 2;

    if (arr[parent] > 0)
    {
        if (arr[parent] < arr[i])
        {
            swap(arr[parent], arr[i]);
            heapify(arr, n, parent);
        }
    }
}

void maxHeap(vector<int> &fs)
{
    int n = fs.size();

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(fs, n, i);
    }
}

void heapSort(vector<int> &fs)
{
    int num = fs.size();
    for (int i = num - 1; i > 0; i--)
    {
        swap(fs[0], fs[i]);
        heapify(fs, i, 0);
    }
}
int return_median(vector<int> arr)
{
    int num = arr.size();
    int q = num / 2;
    if ((num % 2) == 0)
    {
        int avg = (arr[q] + arr[q - 1]) / 2;
        return avg;
    }
    else
    {
        return arr[q];
    }
}

vector<int> median(vector<int> &fs, vector<int> as)
{

    int aSize = as.size();
    vector<int> mid;

    for (int i = 0; i < aSize; i++)
    {
        fs.push_back(as[i]);
        int fSize = fs.size();
        heapify_node(fs, fSize, fSize - 1);
        mid.push_back(return_median(fs));
    }
    return mid;
}

vector<int> online_median(vector<int> &fs, vector<int> as)
{
    maxHeap(fs);
    heapSort(fs);

    return median(fs, as);
}

int main()
{
    vector<int> first_stream = {4, 5, 6, 7};
    vector<int> second_stream = {5, 6, 4};

    vector<int> result1;

    result1 = online_median(first_stream, second_stream);

    for (auto it = result1.begin(); it != result1.end(); it++)
        cout << *it << " ";

    return 0;
}