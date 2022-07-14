#include <iostream>
#include<stack>
#include <cstring>

using namespace std;

bool isPar(string str)
{
     stack<char>stck;
    int len = str.length();
    if (len%2 !=0)
       return false;
   
     for ( int i =  0; i < len; i++)
     {
        if (str[i] == '{'||
            str[i] == '('||
            str[i] == '[')
          stck.push(str[i]);
        else if (!stck.empty() && ((stck.top()== '{' && str[i] == '}')||
                (stck.top() == '(' && str[i] == ')') ||
                (stck.top() == '['&&  str[i] == ']')))
                stck.pop();
        else
            stck.push(str[i]);
          
        
     }
     if (stck.size() != 0 )
       return false;
     else
       return true;
}
int main()
{
    string s{"{}(){}"};
    bool ans =  isPar(s);
    cout << std::boolalpha << ans<<endl;

}