/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

double calculate_power(double a, int b)
{
    // Write your code here.
    if (b == 0)
        return 1;

    bool neg = false;

    if (b < 0)
    {
        b = abs(b);
        neg = true;
    }

    a %= 1000000007;
    double temp = calculate_power(a, b / 2);

    temp = (temp * temp);

    if (b % 2 == 1)
        temp = (temp * a);

    if (neg)
    {
        temp = 1 / temp;
    }

    return temp;
}

int main()
{
    long long num{10000000};
    long long power{10000000};

    int result = calculate_power(num, power);

    cout << result << endl;
}