/*Given a base a and an exponent b. Your task is to find ab. The value could be large enough. So, calculate ab % 1000000007.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calculate_power(long long a, long long b)
{
    // Write your code here.
    if (b == 0)
        return 1;

    a %= 1000000007;
    long long temp = calculate_power(a, b / 2);

    temp = (temp * temp) % 1000000007;

    if (b % 2 == 1)
        temp = (temp * a) % 1000000007;

    return (int)temp;
}

int main()
{
    long long num{10000000};
    long long power{10000000};

    int result = calculate_power(num, power);

    cout << result << endl;
}