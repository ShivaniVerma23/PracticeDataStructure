#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*void selectionSort(vector<int> &arr, int n)
{
   for (int i=0; i<n; i++)
   {
       int minIdx{i};
       for (int j=i; j<n; j++)
       {
            if (arr[minIdx] > arr[j])
                  minIdx = j;
       }
       if (i!= minIdx)
          swap (&arr[i], &arr[minIdx]);
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
    /*if (n <= 1)
        return;
    insertionSort(arr, n - 1);*/
/*for (int i = 0; i < n; i++)
{
    int idx = i - 2;
    int temp = arr[i - 1];
    while (idx >= 0 && arr[idx] > temp)
    {
        arr[idx + 1] = arr[idx];
        idx--;
    }
    arr[idx + 1] = temp;
}
return;
}*/

/*void merge(vector<int>& arr, int start, int end, int mid)
{
    vector<int> leftArray, rightArray, tempArray;
    int lSize = mid - start + 1;
    int rSize = end - mid;
    int lIdx{0}, rIdx{0}, tempIdx{0};

    for (int i = 0; i < lSize; i++)
    {
        leftArray.push_back(arr[start + i]);
    }
    for (int i = 0; i < rSize; i++)
    {
        rightArray.push_back(arr[mid + 1 + i]);
    }

    while (lIdx < lSize && rIdx < rSize)
    {
        if (leftArray[lIdx] <= rightArray[rIdx])
        {
            tempArray.push_back(leftArray[lIdx]);
            lIdx++;
        }
        else
        {
            tempArray.push_back(rightArray[rIdx]);
            rIdx++;
        }
    }

    while (lIdx != lSize)
    {
        tempArray.push_back(leftArray[lIdx]);
        lIdx++;
    }
    while (rIdx != rSize)
    {
        tempArray.push_back(rightArray[rIdx]);
        rIdx++;
    }

    auto it = tempArray.begin();

    for (int i = start; i <= end && it != tempArray.end(); i++, it++)
    {
        arr[i] = *it;
    }
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
        if (arr[bigger] < arr[start])
        {
            smaller++;
            swap(&arr[smaller], &arr[bigger]);
        }
    }
    swap(&arr[start], &arr[smaller]);
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