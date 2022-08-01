#include <iostream>
#include <vector>

using namespace std;
/* Time complexity of Selection Sort is O(n2)*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

vector<int> bubbleSort(vector<int> &n)
{
    int len = n.size();

    for (int i = 0; i < len - 2; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (n[j] > n[j + 1])
            {
                swap(&n[j], &n[j + 1]);
            }
        }
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

    bubbleSort(numbers);

    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << *it << " ";

    return 0;
}