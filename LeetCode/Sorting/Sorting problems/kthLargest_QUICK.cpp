#include <iostream>
#include <vector>

using namespace std;

int rearrange(vector<int> &arr, int start, int end)
{
    if (start == end)
        return start;
    int temp = start;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] < arr[start])
        {
            temp++;
            swap(arr[temp], arr[i]);
        }
    }
    swap(arr[start], arr[temp]);
    return temp;
}

int partition(vector<int> &arr, int start, int end)
{
    return rearrange(arr, start, end);
}

int quickSelect(vector<int> &arr, int start, int end, int k)
{
    int pi = partition(arr, start, end);

    if (pi == arr.size() - k)
        return arr[pi];
    if (arr.size() - k < pi)
        return quickSelect(arr, start, pi - 1, k);
    else
        return quickSelect(arr, pi + 1, end, k);
}

int find_Kth(vector<int> arr, int k)
{
    return quickSelect(arr, 0, arr.size() - 1, k);
}

vector<int> kth_largest(int k, vector<int> &initial_stream, vector<int> &append_stream)
{
    // Write your code here.
    vector<int> result;

    for (int i = 0; i < append_stream.size(); i++)
    {
        int kth = 0;
        initial_stream.push_back(append_stream[i]);
        //append_stream.erase(append_stream.begin());
        kth = find_Kth(initial_stream, k);
        result.push_back(kth);
    }
    return result;
}

int main()
{
    vector<int> first_stream = {4, 6, 25};
    vector<int> append_stream = {5, 2, 20, 33, 0};
    int k = 1;
    vector<int> result;

    result = kth_largest(k, first_stream, append_stream);

    for (auto i = result.begin(); i!= result.end(); i++)
        cout << *i << " ";

    return 0;
}