#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median;
    MedianFinder()
    {
        median = 0;
    }

    void addNum(int num)
    {
        if (num > median)
        {
            minHeap.push(num);
            if (minHeap.size() - maxHeap.size() == 2)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else
        {
            maxHeap.push(num);
            if (maxHeap.size() - minHeap.size() == 2)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }

    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
        {
            median = (double)(minHeap.top() + maxHeap.top()) / 2;
            return median;
        }
        else if (maxHeap.size() > minHeap.size())
        {
            median = maxHeap.top();
            return median;
        }
        else
        {
            median = minHeap.top();
            return median;
        }
    }
};

int main()
{
    MedianFinder *obj = new MedianFinder();
    double param_2;
    obj->addNum(6);
    param_2 = obj->findMedian();
    cout << param_2 << "\t";

    obj->addNum(10);
    param_2 = obj->findMedian();
    cout << param_2 << "\t";

    obj->addNum(2);
    param_2 = obj->findMedian();
    cout << param_2 << "\t";

    obj->addNum(6);
    param_2 = obj->findMedian();
    cout << param_2 << "\t";

    obj->addNum(5);
    param_2 = obj->findMedian();
    cout << param_2 << "\t";

    obj->addNum(0);
    param_2 = obj->findMedian();
    cout << param_2 << "\t";

    obj->addNum(6);
    param_2 = obj->findMedian();
    cout << param_2 << "\t";

    return 0;
}