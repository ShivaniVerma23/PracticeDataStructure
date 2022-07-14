#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    vector<int> sortedPrices = prices;
    int len = prices.size();
    int profit{0};

    sort(sortedPrices.begin(), sortedPrices.end());

    for (auto it = sortedPrices.begin(); it != sortedPrices.end(); it++)
    {
        int flag{false};
        int buyingPrice{0};
        for (int i = 0; i < len; i++)
        {
            if (prices[i] == *it)
            {
                flag = true;
                buyingPrice = prices[i];
            }
            if (flag == true)
            {
                profit = max(profit, prices[i] - buyingPrice);
            }
        }
    }
    return profit;
}

int main()
{
    int numOfDays{0};
    vector<int> stockPrices;
    int price{0};
    int Profit{0};

    cout << "Enter the num of days" << endl;
    cin >> numOfDays;

    cout << "Enter the stock price on each day" << endl;

    for (int i = 0; i < numOfDays; i++)
    {
        cin >> price;
        stockPrices.push_back(price);
    }

    Profit = maxProfit(stockPrices);

    cout << Profit << endl;
}