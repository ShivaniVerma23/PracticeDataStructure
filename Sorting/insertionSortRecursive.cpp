#include <iostream>
#include <vector>
/* Time complexity of Insertion Sort is 
Worst and averege case O(n2)
Best case O(n)*/
using namespace std;

void insertionSort(vector<int> &arr, int n)
{
    /*if (n <= 1)
        return;
    insertionSort(arr, n - 1);
    int temp = arr[n - 1];
    int idx = n - 2;*/

    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        int idx = i - 1;
        while (idx >= 0 && temp < arr[idx])
        {
            arr[idx + 1] = arr[idx];
            idx--;
        }
        arr[idx + 1] = temp;
    }
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

    insertionSort(numbers, countOfNum);

    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << *it << " ";

    return 0;
}