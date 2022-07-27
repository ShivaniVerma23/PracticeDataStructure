#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int root = i;

    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && arr[left] < arr[root])
        root = left;
    if (right < n && arr[right] < arr[root])
        root = right;
    if (root != i)
    {
        swap(arr[root], arr[i]);
        heapify(arr, n, root);
    }
}

void minHeap_K(int k, vector<int> &fs)
{
    int fsSize = fs.size();

    for (int i = (k / 2) - 1; i >= 0; i--)
    {
        heapify(fs, k, i);
    }
}

vector<int> kStream(int k, vector<int> &fs, vector<int> as)
{
    int remainFS = fs.size();
    int asSize = as.size();

    vector<int> result;

    for (int i = k; i < remainFS; i++)
    {
        if (fs[i] > fs[0])
        {
            swap(fs[i], fs[0]);
            heapify(fs, k, 0);
        }
    }

    for (int j = 0; j < asSize; j++)
    {
        if (fs[0] < as[j])
        {
            swap(as[j], fs[0]);
            heapify(fs, k, 0);
            result.push_back(fs[0]);
        }
        else
            result.push_back(fs[0]);
    }

    return result;
}

vector<int> kth_largest(int k, vector<int> &initial_stream, vector<int> &append_stream)
{
    minHeap_K(k, initial_stream);

    return kStream(k, initial_stream, append_stream);
}

int main()
{
    vector<int> first_stream = {4, 5, 6, 7};
    vector<int> second_stream = {5, 6, 4};
    int k = 3;
    vector<int> result1;

    result1 = kth_largest(k, first_stream, second_stream);

    for (auto it = result1.begin(); it != result1.end(); it++)
        cout << *it << " ";

    return 0;
}