#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int maxCoins(vector<int> &A, vector<int> &B, int T, int N)
{
    int idx{0};
    int count

    while (idx < N)
    {

    }
}

int main()
{
    int numOfBoxes{0};
    vector<int> numofPlatesinEachBox{0};
    vector<int> numOfGoldCoinsOnEachPlate{0};
    int plates{0};
    int coins{0};
    int maxPlatesLift{0};
    int maxCoinsSteal{0};

    cout << "Enter the number of Boxes" << endl;
    cin >> numOfBoxes;

    cout << "enter the number of plates he can choose" << endl;
    cin >> maxPlatesLift;

    cout << "enter the number of plates in each box" << endl;
    for (int i = 0; i < numOfBoxes; i++)
    {
        cin >> plates;
        numofPlatesinEachBox.push_back(plates);
    }

    cout << "GOld coins on each platein each box" << endl;
    for (int i = 0; i < numOfBoxes; i++)
    {
        cin >> coins;
        numOfGoldCoinsOnEachPlate.push_back(coins);
    }

    maxCoinsSteal = maxCoins(numofPlatesinEachBox, numOfGoldCoinsOnEachPlate, maxPlatesLift, numOfBoxes);

    cout << maxCoins << endl;
}