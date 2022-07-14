#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int totalFruit(vector<int> &fruits)
{
    int maxFruit{0};
    map<int, int> basket1;
    map<int, int> basket2;
    vector<int> totalFruits;
    map<int, int>::iterator it1;
    map<int, int>::iterator it2;
    int size = fruits.size();

    for (int i = 0; i < size; i++)
    {
        for (auto itr = fruits.begin(); itr != fruits.end(); itr++)
        {
            if (basket1.empty() && basket2.empty())
                basket1.insert({*itr, 1});
            else if (!basket1.empty())
            {
                it1 = basket1.find(*itr);
                if (it1 != basket1.end())
                    it1->second++;
                else if (basket2.empty())
                    basket2.insert({*itr, 1});
                else
                {
                    it2 = basket2.find(*itr);
                    if (it2 != basket2.end())
                        it2->second++;
                    else
                    {

                        break;
                    }
                }
            }
        }
        map<int, int>::iterator fit1{basket1.begin()};
        map<int, int>::iterator fit2{basket2.begin()};
        totalFruits.push_back(fit1->second + fit2->second);
        basket1.clear();
        basket2.clear();
        auto it = fruits.begin();
        fruits.erase(it);
    }
    sort(totalFruits.begin(), totalFruits.end(), greater<int>());
    return totalFruits[0];
}

int main()
{
    vector<int> fruitGarden;
    int fruit{0};
    int totalFruitsPicked{0};

    int numOfFruits{0};
    cout << "Enter the total number of fruits you want to pick" << endl;
    cin >> numOfFruits;

    cout << "Enter the fruits now" << endl;

    for (int i = 0; i < numOfFruits; i++)
    {
        cin >> fruit;
        fruitGarden.push_back(fruit);
    }

    totalFruitsPicked = totalFruit(fruitGarden);

    cout << totalFruitsPicked << endl;
}