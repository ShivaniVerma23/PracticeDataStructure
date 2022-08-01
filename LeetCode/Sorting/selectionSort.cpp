#include <iostream>
#include <vector>

using namespace std;
/* Time complexity of Selection Sort is O(n2)*/
vector<int> selectionSort(vector<int> &n)
{
    int len = n.size();
    int minIdx{0};
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (n[minIdx] > n[j])
                minIdx = j;
        }
        int temp{0};
        temp = n[i];
        n[i] = n[minIdx];
        n[minIdx] = temp;
    }
    return n;
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

    selectionSort(numbers);

    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << *it << " ";

    return 0;
}