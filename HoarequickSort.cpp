#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &arr, int start, int end)
{
    int smaller{start + 1}, bigger{end};

    while (smaller <= bigger)
    {
        if (arr[smaller] <= arr[start])
            smaller++;
        else if (arr[bigger] > arr[start])
            bigger--;
        else
        {
            swap(&arr[smaller], &arr[bigger]);
            smaller++;
            bigger--;
        }
    }
    swap(&arr[start], &arr[bigger]);
    return bigger;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int pi = partition(arr, start, end);
    quickSort(arr, start, pi - 1);
    quickSort(arr, pi + 1, end);

    return;
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

    quickSort(numbers, 0, countOfNum - 1);

    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << *it << " ";

    return 0;
}