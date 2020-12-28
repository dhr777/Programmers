#include<iostream>
#include <string>

using namespace std;

string solution(string s) {
    
    s[0] = toupper(s[0]);

    for (int i = 1; i <s.size(); i++)
    {
        if (s[i] == ' ')
        {
            s[i + 1] = toupper(s[i + 1]);
        }
        else if (s[i - 1] != ' ' && isupper(s[i]))
        {
            s[i] = tolower(s[i]);
        }

    }

    return s;
}

int main()
{
    
    string s = "3people unFollowed me";
       solution(s);
   
   
   
    return 0;
}