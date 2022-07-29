#include <iostream>
#include <vector>

using namespace std;

vector<char> dutch_flag_sort(vector<char> &balls)
{
    // Write your code here.
    int num = balls.size();
    int red{0};
    int blue{num - 1};
    int green = (red + blue) / 2;
    int mid = green;

    while (red < mid || green <= blue)
    {
        if (balls[red] == 'R')
        {
            red++;
        }
        else if (balls[green] == 'G')
        {
            green++;
        }
        else if (balls[blue] == 'B')
        {
            blue++;
        }
        else if (balls[red] == 'B' || balls[green] == 'B')
        {
            if (balls[blue] == 'R')
            {
                swap(balls[red], balls[blue]);
                red++;
            }
            else
            {
                swap(balls[green], balls[blue]);
                green++;
            }
            blue--;
        }
        else if (balls[red] == 'G' && balls[green] == 'R')
        {
            swap(balls[red], balls[green]);
            red++;
            green++;
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