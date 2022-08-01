#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int minimumDifference(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    int i{0}, j{0}, size = nums.size();
    int count{0};
    int minDif{0};
    int diff{0};

    if (size == 1)
        return 0;

    while (j < size)
    {
        count++;

        if (count >= k)
        {
            diff = nums[j] - nums[j - k + 1];
            if (minDif == 0)
                minDif = diff;
            else
                minDif = min(minDif, diff);
            count--;
        }
        j++;
    }
    return minDif;
}

int main()
{
    int marks{0}, numofStudents{0};
    int marksDiff{0};
    vector<int> marksArray;
    int minDiff{0};

    cout << "Enter the number of Students" << endl;
    cin >> numofStudents;

    cout << "Enter the marks od each student" << endl;
    for (int i = 0; i < numofStudents; i++)
    {
        cin >> marks;
        marksArray.push_back(marks);
    }

    cout << "No.of student whose marks Difference needs to be find" << endl;
    cin >> marksDiff;

    minDiff = minimumDifference(marksArray, marksDiff);

    cout << minDiff << endl;

    return 0;
}