#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int totalFruit(vector<int> &fruits)
{
    int i{0},j{0},mx{0};
    int n = fruits.size();
    unordered_map <int, int>mp;

    if (n == 1)
       return 1;
    while(j<n)
    {
        mp[fruits[j]]++;
        if (mp.size()<=2)
        {
            mx = max(mx, j-i+1);
            j++;
        }
        else
        {
            mp[fruits[i]]--;
            if (mp[fruits[i]]==0)
               mp.erase(fruits[i]);
            i++;
            j++;

        }

    }
    return mx;
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
    return 0;
}