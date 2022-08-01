#include <iostream>

using namespace std;

int climbStairs(int n)
{
    int arr[3][n + 1];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (int i = 1; i < 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1)
                arr[1][j] = 1;
            else
            {
                if (j < i)
                    arr[i][j] = arr[i - 1][j];
                else if (i == j)
                    arr[i][j] = arr[i][j - 1] + 1;
                else
                    arr[i][j] = arr[i][j - 1] + arr[i][j - 2];
            }
        }
    }
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return arr[2][n];
}

int main()
{
    int numOfStairs{0};
    int ways{0};

    cout << "enter the number of stairs" << endl;
    cin >> numOfStairs;

    ways = climbStairs(numOfStairs);

    cout << ways << endl;

    return 0;
}