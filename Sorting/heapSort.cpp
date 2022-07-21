#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

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
        swap(&arr[i], &arr[root]);

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

void maxHeap(vector<int>&arr, int n)
{
   for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    } 
}

void heapSort(vector<int> &arr, int n)
{
    buildHeap(arr, n);
    maxHeap(arr, n);
}

int main()
{
    int num{0};
    int countOfNum{0};
    vector<int> numbers;
    vector<int> result;

    cout << "enter the numbers of integers in array" << endl;
    cin >> countOfNum;

    cout << "Enter the numbers now" << endl;
    for (int i = 0; i < countOfNum; i++)
    {
        cin >> num;
        numbers.push_back(num);
    }

    heapSort(numbers, countOfNum);

    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << *it << " ";

    return 0;
}