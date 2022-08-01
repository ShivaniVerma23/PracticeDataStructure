#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int>& arr, int start, int end)
{
    int smaller{start}, bigger;

    for (bigger = start + 1; bigger <= end; bigger++)
    {
        if (arr[bigger] < arr[start])
        {
            smaller++;
            swap(&arr[smaller], &arr[bigger]);
        }
    }
    swap(&arr[start], &arr[smaller]);
    return smaller;
}

void quickSort(vector<int> &numbers, int start, int end)
{
    if (start >= end)
        return;

    int pi = partition(numbers, start, end);
    quickSort(numbers, start, pi - 1);
    quickSort(numbers, pi + 1, end);
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