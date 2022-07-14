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

/*void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (i != minIdx)
            swap(&arr[i], &arr[minIdx]);
    }
}*/

/*void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}*/

/*void insertionSort(vector<int> &arr, int n)
{
    if (n == 1)
        return;
    insertionSort(arr, n - 1);
    int temp = arr[n - 1];
    int idx = n - 2;
    while (idx >= 0 && arr[idx] > temp)
    {
        arr[idx + 1] = arr[idx];
        idx--;
    }
    arr[idx + 1] = temp;
    return;
}*/

/*void merge(vector<int> &arr, int start, int end, int mid)
{
    vector<int> leftArray, rightArray, auxArray;
    int lSize = mid - start + 1;
    int rSize = end - mid;
    int idxL{0};
    int idxR{0};

    for (int i = 0; i < lSize; i++)
        leftArray.push_back(arr[start + i]);

    for (int i = 0; i < rSize; i++)
        rightArray.push_back(arr[mid + 1 + i]);

    while (idxL < lSize && idxR < rSize)
    {
        if (leftArray[idxL] <= rightArray[idxR])
        {
            auxArray.push_back(leftArray[idxL]);
            idxL++;
        }
        else
        {
            auxArray.push_back(rightArray[idxR]);
            idxR++;
        }
    }
    while (idxL < lSize)
    {
        auxArray.push_back(leftArray[idxL]);
        idxL++;
    }
    while (idxR < rSize)
    {
        auxArray.push_back(rightArray[idxR]);
        idxR++;
    }

    auto it = auxArray.begin();
    for (int i = start; i <= end && it != auxArray.end(); i++, it++)
    {
        arr[i] = *it;
    }
    return;
}
void mergeSort(vector<int> &arr, int start, int end)
{
    if (start == end)
        return;

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end, mid);

    return;
}*/

int partition(vector<int> &arr, int start, int end)
{
    int smaller{start};
    for (int bigger = start + 1; bigger <= end; bigger++)
    {
        if (arr[bigger] <= arr[start])
        {
            swap(&arr[bigger], &arr[start]);
            smaller++;
        }
    }
    swap(&arr[smaller], &arr[start]);
    return smaller;
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

    // selectionSort(numbers, countOfNum);
    // bubbleSort(numbers, countOfNum);
    // insertionSort(numbers, countOfNum);
    // mergeSort(numbers, 0, countOfNum - 1);
    quickSort(numbers, 0, countOfNum - 1);

    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << *it << " ";

    return 0;
}