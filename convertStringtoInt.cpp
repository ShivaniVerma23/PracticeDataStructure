#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void convertStringToInt()
{
    string input {"5239"};

    int output{0};

    int size = input.length();

    int idx {size};

    int d {0};

    int i {0};

    while( idx > 0)
    {
          cout << input[i] <<endl;
          d = input[i] - '0';
          cout << "int is" <<d <<endl;
          output += (d*(pow(10, (idx-1))));
          cout <<output <<endl;
          i++;
        idx--;
    }
    cout << output << endl;



}

int main()
{
    
convertStringToInt();

}