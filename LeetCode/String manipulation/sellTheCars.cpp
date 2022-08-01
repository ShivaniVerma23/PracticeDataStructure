#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;

int maximumProfit(vector<int> P)
{
    sort(P.begin(),P.end(), greater<int>() );
    int num = P.size();
    int idx{0};
    ll maxProfit{0};

    while(idx< num)
    {
        maxProfit += max(0,P[idx]-idx);
        maxProfit%=mod;
        idx++;
    }
    return maxProfit;
}

int main()
{
    int numofCars{0};
    vector<int> priceOfCars;
    int price{0};
    int profit{0};

    cout << "enter the number of cars" << endl;
    cin >> numofCars;

    cout << "enter the price of cars" << endl;
    for (int i = 0; i < numofCars; i++)
    {
        cin >> price;
        priceOfCars.push_back(price);
    }

    profit = maximumProfit(priceOfCars);
    cout << profit << endl;

    return 0;
}