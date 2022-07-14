#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> prepareVectorOfvector(vector<int> &st, vector<int> &et, vector<int> &p)
{
    vector<vector<int>> timing;
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        timing.push_back({st[i], et[i], p[i]});
    }
    return timing;
}

bool cmp(vector<vector<int>> t1, vector<vector<int>> t2)
{
    return t1[1] < t2[1];
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    vector<vector<int>> timings;
    int maxProfit{0};
    int numOfJobs = startTime.size();
    int profitTill{0};
    int selectP{0};
    int noSelectP{0};

    timings = prepareVectorOfvector(startTime, endTime, profit);

    sort(timings.begin(), timings.end(), cmp);

    for (int i = 0; i < numOfJobs; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (timings[j][0] > timings[i][1])
            {
                selectP += profit[j];
            }
        }
    }

    return maxProfit;
}

int main()
{
    int numOfActivities{0};
    vector<int> startTime;
    vector<int> endTime;
    vector<int> profit;
    int start{0}, end{0}, gain{0};
    int maxProfit{0};

    cout << "enter the number of activities" << endl;
    cin >> numOfActivities;

    for (int i = 0; i < numOfActivities; i++)
    {
        cout << "enter startTime, endTime, profit for activity : " << i + 1 << endl;
        cin >> start >> end >> gain;
        startTime.push_back(start);
        endTime.push_back(end);
        profit.push_back(gain);
    }

    maxProfit = jobScheduling(startTime, endTime, profit);

    cout << maxProfit << endl;
    return 0;
}