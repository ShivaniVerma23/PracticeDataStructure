#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int maximumProduct(vector<int> &nums)
{
    cout << "Size " << nums.size() << endl;
    int result{0};
    bool firstMultiply{true};
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                // cout << nums[i] << "  " << nums[j] << "  " << nums[k];
                int value = nums[i] * nums[j] * nums[k];
                // cout << " " << value << endl;
                if (result == 0 &&
                    firstMultiply)
                {
                    result = value;
                    firstMultiply = false;
                }
                else if (result < 0 && value < 0 &&
                         value > result)
                    result = value;
                else if (result > 0 && value > 0 &&
                         value > result)
                    result = value;
                else if (value > result)
                    result = value;
            }
        }
    }

    return result;
}

int main()
{
    int num{0};
    int totalNumbers{0};
    vector<int> numbers;

    int product{0};

    /*  cout << "Enter the total numbers to be entered" << endl;
      cin >> totalNumbers;

      for (auto i = 0; i < totalNumbers; i++)
      {
          cin >> num;
          numbers.push_back(num);
      }*/

    product = maximumProduct(numbers);

    cout << product << endl;
}