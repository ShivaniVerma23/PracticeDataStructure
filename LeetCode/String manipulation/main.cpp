#include <iostream>
#include <cstring>

using namespace std;

string reverseWords(string s) {
        string result;
         int len = s.length();
         if (len == 0)
          return result;
         char copy[len+1];
         strcpy(copy, s.c_str());

        int idx = 0;
        int start{0};
        int end {0};
        int pos {0};

        char* token = NULL;
        token = strtok(copy," ");
        while(token != NULL)
        {
          for (int i = strlen(token)-1; i >= 0 ; i--)
          {
              result[pos] = token[i];
              pos++;
          }
          token = strtok(NULL, " ");
          if (token!= NULL)
          {
              result[pos] = ' ';
              pos++;
          }
          else{
             result[pos] = '\0';
               return result.c_str(); 
          }
        }
        
        
        /*while (s.length()!= 0)
        {  
            cout <<"S" <<s<<endl;
            idx = s.find(' ');
            cout <<"idx" <<idx <<endl; 
             if (idx <= 0)
            {
                int leng = s.length();
                for (start = leng-1; start >= 0; start--)
               {
                   result[pos] = s[start];
                   pos++;
               }
               result[pos] = '\0';
               cout << "RESULT" <<result.c_str() << endl;
                return result.c_str();
            }

            start = idx-1; 
            for (start = idx-1; start >= end; start--)
            {
                
                result[pos] = s[start];
                pos++;
            }
           
            result[pos] = ' ';
            
            pos++;
            int len = s.length();
            s = s.substr(idx+1, len -idx);
            cout << "substring " << s <<endl;
            cout << "IDX" <<idx <<endl;
        }*/
         result[pos] = '\0';
        return result.c_str();

} 
int main()
{
    string str {"aa.. bb.. cc.. dddd eeee fff!!! @@@rf"};
    string finalstr = reverseWords( str );
    cout << "Smallest number is " << finalstr <<std::endl;
    return 0;
}
