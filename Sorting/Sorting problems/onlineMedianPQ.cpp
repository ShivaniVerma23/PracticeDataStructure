#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<double> online_median(vector<int> &stream)
{
    // Write your code here.
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median{0};
    vector<double> result;
    for (int i = 0; i < stream.size(); i++)
    {
        if (stream[i] > median)
        {
            minHeap.push(stream[i]);
            if (minHeap.size() - maxHeap.size() == 2)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else
        {
            maxHeap.push(stream[i]);
            if (maxHeap.size() - minHeap.size() == 2)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        if (minHeap.size() == maxHeap.size())
        {
            median = (double)(minHeap.top() + maxHeap.top()) / 2;
            result.push_back(median);
        }
        else if (minHeap.size() > maxHeap.size())
        {
            median = (double)minHeap.top();
            result.push_back(median);
        }
        else
        {
            median = (double) maxHeap.top();
            result.push_back(median);
        }
    }
    return result;
}

int main()
{
    vector<int> first_stream = {6, 10, 2, 6, 5, 0, 6, 3, 1, 0, 0};

    vector<double> result1;

    result1 = online_median(first_stream);

    for (auto it = result1.begin(); it != result1.end(); it++)
        cout << *it << "\t";

    return 0;
}