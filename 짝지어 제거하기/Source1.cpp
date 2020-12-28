#include <iostream>
#include<string>

using namespace std;

int del(string& s)
{
    for (int i = 0; i < s.size()-1; i++)
    {
        if(s[i] == s[i + 1])
        {
            s.erase(i, 2);
            return s.size();
        }
    }
    return -1;
}
int solution(string s)
{
    int n; //baabaa 

    while (1)
    {
        n = del(s); //짝을 찾아 제거하는 함수
        if (n == 0) //반환값이 0일 경우 모두 제거되었으므로 1을 반환
            return 1;
        if (n == -1)//짝이 성립이 안돼서 -1반환 
            return 0;
    } 
      
    return 0;
}

int main()
{
    //baabaa//
    string s = "cdcd";
     cout<<solution(s);

  
     
     
    return 1;
}