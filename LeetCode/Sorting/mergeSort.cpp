#include <iostream>
#include <vector>

/*Time complexity of mergeSort is O(nlogn)*/

using namespace std;

void merge(vector<int> &arr, int start, int end, int mid)
{
    int lSize = mid - start + 1;
    int rSize = end - mid;

    vector<int> leftArray;
    vector<int> rightArray;
    vector<int> auxArray;
    int idx1{0}, idx2{0}, auxIdx{start};

    for (int i = 0; i < lSize; i++)
        leftArray.push_back(arr[start + i]);
    for (int i = 0; i < rSize; i++)
        rightArray.push_back(arr[mid+ 1 + i]);

    while (idx1 < lSize && idx2 < rSize)
    {
        if (leftArray[idx1] <= rightArray[idx2])
        {
            auxArray.push_back(leftArray[idx1]);
            idx1++;
        }
        else
        {
            auxArray.push_back(rightArray[idx2]);
            idx2++;
        }
    }
    if (idx1 != lSize)
    {
        for (idx1; idx1 < lSize; idx1++)
        {
            auxArray.push_back(leftArray[idx1]);
        }
    }
    if (idx2 != rSize)
    {
        for (idx2; idx2 < rSize; idx2++)
        {
            auxArray.push_back(rightArray[idx2]);
        }
    }
    auto it = auxArray.begin();
    for (int i = start ; i<=end && it!= auxArray.end() ;i++,it++)
    {
        arr[i] = *it;
    }
    
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, right, mid);
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

    mergeSort(numbers, 0, countOfNum - 1);

    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << *it << " ";

    return 0;
}