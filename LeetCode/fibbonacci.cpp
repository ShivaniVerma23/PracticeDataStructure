#include <iostream>

using namespace std;

int fib(int n)
{
    if (n==0||n==1)
      return n;
    return fib(n-1)+fib(n-2);
}
int main()
{
    int num{0};
    int output{0};
    cout << "Enter the number" << endl;
    cin >> num;

    output = fib(num);

    cout << output << endl;
    return 0;
}