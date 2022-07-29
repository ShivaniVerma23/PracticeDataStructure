#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kth_largest_in_an_array(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        if (pq.size() < k)
        {
            pq.push(arr[i]);
        }
        else if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main()
{
    vector<int> numbers = {1, 1, 1, 3, 5, 4, 6};
    int k = 3;
    int result{0};

    result = kth_largest_in_an_array(numbers, k);

    cout << result << endl;

    return 0;
}