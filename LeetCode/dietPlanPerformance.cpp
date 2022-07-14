#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dietPlanPerformance(vector<int> &calories, int k, int lower, int upper)
{
    int totalPoints{0};
    int sumOfCalories{0};
    int i{0}, j{0}, countofDays{0};
    int size = calories.size();

    while (j < size)
    {
        sumOfCalories += calories[j];
        j++;
        countofDays++;

        if (countofDays >= k)
        {
            if (sumOfCalories < lower)
                totalPoints--;
            else if (sumOfCalories > upper)
                totalPoints++;

            sumOfCalories -= calories[i];
            i++;
            countofDays--;
        }
    }
    return totalPoints;
}

int main()
{
    vector<int> Calorie;
    int numOfDays{0};
    int maxCalorie{0};
    int minCalorie{0};
    int consecutiveDays{0};
    int caloriePerDay{0};
    int points{0};

    cout << "Enter the consecutive days for Calorie count" << endl;
    cin >> consecutiveDays;

    cout << " Atmost Calorie consumption" << endl;
    cin >> maxCalorie;

    cout << " Atleast Calorie consumption" << endl;
    cin >> minCalorie;

    cout << "total no. of days for DietPlan Performance" << endl;
    cin >> numOfDays;

    cout << "enter calorie consumption for each day" << endl;
    for (int i = 0; i < numOfDays; i++)
    {
        cin >> caloriePerDay;
        Calorie.push_back(caloriePerDay);
    }

    points = dietPlanPerformance(Calorie, consecutiveDays, minCalorie, maxCalorie);

    cout << "Total points acquired ::" << points << endl;

    return 0;
}