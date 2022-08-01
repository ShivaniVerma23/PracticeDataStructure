#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int calculateMats(vector<pair<int, int>> hall, int matB, int matL)
{
    int total{0};
    int matsHo{0}, matsVer{0};

    vector<pair<int, int>>::iterator it;

    for (it = hall.begin(); it != hall.end(); it++)
    {
        matsHo = floor(it->first / matB) * floor(it->second / matL);
        matsVer = floor(it->first / matL) * floor(it->second / matB);
        if (matsHo > matsVer)
            total += matsHo;
        else
            total += matsVer;
    }
    return total;
}

int main()
{
    int matLen{0}, matBreadth{0};
    int hallLen{0}, hallBreadth{0};
    int numofHalls{0};
    int totalMats{0};

    vector<pair<int, int>> hallDimension;

    cout << "Enter length of mat" << endl;
    cin >> matLen;

    cout << "Enter Breadth of mat" << endl;
    cin >> matBreadth;

    cin.ignore();

    cout << "Enter numberof Halls" << endl;
    cin >> numofHalls;

    for (int i = 0; i < numofHalls; i++)
    {
        cout << "Enter length of Hall" << endl;
        cin >> hallLen;

        cout << "Enter Breadth of Hall" << endl;
        cin >> hallBreadth;

        hallDimension.push_back({hallLen, hallBreadth});
    }

    totalMats = calculateMats(hallDimension, matBreadth, matLen);

    cout << totalMats << endl;
}