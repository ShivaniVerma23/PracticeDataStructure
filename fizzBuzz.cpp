#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> result;
    int div3{0}, div5{0};
    char buf[2];

    for (int i = 1; i <= n; i++)
    {
        div3 = i % 3;
        div5 = i % 5;
        if (div3 == 0 && div5 == 0)
           result.push_back("FizzBuzz");
        else if(div3==0)
           result.push_back("Fizz");
         else if(div5==0)
           result.push_back("Buzz");  
        else
           result.push_back(to_string(i));
    }
    return result;
}

int main()
{
    vector<string> output;
    int input;

    cout << "Enter the number" << endl;
    cin >> input;

    output = fizzBuzz(input);

    for (auto itr = output.begin(); itr != output.end(); itr++)
    {
        cout << *itr << "\t";
    }
    return 0;
}