#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> pairOfSums(vector<int> numbers, int target)
{
    vector<pair<int, int>> numIndices;
    unordered_map<int, int> umap;
    unordered_map<int, int>::iterator itr;
    vector<int> result;

    for (int i = 0; i < numbers.size(); i++)
        numIndices.push_back(make_pair(numbers[i], i));

    for (auto it = numIndices.begin(); it != numIndices.end(); it++)
    {
        int num1 = it->first;
        int num2 = target - num1;

        itr = umap.find(num2);
        if (itr != umap.end())
        {
            result.push_back(it->second);
            result.push_back(itr->second);
            break;
        }
        else
        {
            umap[it->first] = it->second;
        }
    }
    if (result.empty())
    {
        result.push_back(-1);
        result.push_back(-1);
    }
    return result;
}

int main()
{
    int num{0};
    int countOfNum{0};
    int target{0};
    vector<int> numbers;
    vector<int> result;

    cout << "Enter the target" << endl;
    cin >> target;

    cout << "enter the numbers of integers in array" << endl;
    cin >> countOfNum;

    cout << "Enter the numbers now" << endl;
    for (int i = 0; i < countOfNum; i++)
    {
        cin >> num;
        numbers.push_back(num);
    }

    result = pairOfSums(numbers, target);

    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << " ";

    return 0;
}