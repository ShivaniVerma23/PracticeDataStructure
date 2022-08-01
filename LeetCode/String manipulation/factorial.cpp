#include<iostream>

using namespace std;

int factorial(int num)
{
    if (num==1 || num==0)
       return 1;
    return num*factorial(num-1);
}

int main()
{
    int number{0};
    int fact{0};

    cout<< "enter the number"<<endl;
    cin >> number;

    fact = factorial(number);
    cout << fact<<endl;
}