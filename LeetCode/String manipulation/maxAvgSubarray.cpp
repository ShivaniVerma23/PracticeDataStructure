#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int j{0}, i{0},sum{0};
    int size = nums.size();
    double avg{0};
    int count{0};

    vector<int> subarray;

    while (j < size)
    {
        sum += nums[j];
        count++;
        j++;
        if (count >=k)
        {
            if (avg == 0)
               avg = (double)sum/k;
            else if (avg < (double)sum / k)
                avg = (double)sum / k;

            sum -= nums[i];
            i++;
            count--;
        }
    }
    return avg;
}

int main()
{
    int num{0}, integer{0}, lenofSuBArray{0};

    vector<int> array;
    double output;
    cout << "Lengthof SubArray whose averege needs to be find" << endl;
    cin >> lenofSuBArray;

    cout << "Numberof integers in Array" << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> integer;
        array.push_back(integer);
    }

    output = findMaxAverage(array, lenofSuBArray);

    cout << "result is" <<output <<endl;

    return 0;
}