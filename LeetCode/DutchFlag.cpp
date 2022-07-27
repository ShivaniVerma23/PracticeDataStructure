#include <iostream>
#include <vector>

using namespace std;

void arrange(vector<char> &balls, int left, char c)
{
    while (left > 0 && balls[(left)-1] == 'G')
    {
        balls[(left)] = balls[(left)-1];
        (left)--;
    }
    balls[(left)] = c;
    return;
}

vector<char> dutch_flag_sort(vector<char> &balls)
{
    // Write your code here.
    int num = balls.size();
    int left{0};
    int right{num - 1};

    while (left <= right)
    {
        if (balls[left] == 'R' || balls[left] == 'G')
        {
            if (balls[left] == 'R')
            {
                arrange(balls, left, balls[left]);
            }
            else
                left++;
        }
        else if (balls[right] == 'B')
        {
            right--;
        }
        else
        {
            char c = balls[right];
            char c1 = balls[left];
            balls[right] = c1;
            right--;
            if (c == 'R')
                arrange(balls, left, c);
            else
                balls[left] = c;
            left++;
        }
    }
    return balls;
}

int main()
{
    vector<char> numbers = {'G', 'B', 'G', 'G', 'R', 'B', 'R', 'G'};
    vector<char> result;

    result = dutch_flag_sort(numbers);

    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << " ";

    return 0;
}