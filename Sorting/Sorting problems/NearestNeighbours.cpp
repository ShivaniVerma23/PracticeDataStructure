#include <iostream>
#include <queue>
#include <vector>

using namespace std;

float calculate(int x, int y, int x1, int y1)
{
    return sqrt(((x - x1) * (x - x1)) + ((y - y1) * (y - y1)));
}

vector<vector<int>> nearest_neighbours(int p_x, int p_y, int k, vector<vector<int>> &n_points)
{
    // Write your code here.
    priority_queue<pair<float, int>, vector<pair<float, int>>> pq;
    float distance{0};
    vector<vector<int>> result;
    for (int i = 0; i < n_points.size(); i++)
    {

        distance = calculate(p_x, p_y, n_points[i][0], n_points[i][1]);
        if (pq.size() < k)
        {

            pq.push(make_pair(distance, i));
        }
        else
        {
            if (pq.top().first > distance)
            {
                pq.pop();
                pq.push(make_pair(distance, i));
            }
        }
    }
    for (int i = pq.size() - 1; i >= 0; i--)
    {
        result.push_back (n_points[pq.top().second]);
        pq.pop();
    }

    return result;
}

int main()
{
    vector<vector<int>> points{{-1000000000, -1000000000}, {0, 0},{-1000000000, 1000000000}, {1000000000, -1000000000}};
    int p_x = 1000000000;
    int p_y = 1000000000;
    int k = 3;

    vector<vector<int>> result;

    result = nearest_neighbours(p_x, p_y, k, points);

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ " << result[i][0] << " " << result[i][1] << " ]" << endl;
    }
}