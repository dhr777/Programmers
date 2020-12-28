#include <iostream>
#include<string>
#include<stack>

using namespace std;

int solution(string s)
{
    stack<char>stk;

    for (int i = 0; i < s.size(); i++)
    {
        if (stk.empty()) //스택이 비어있으면 글자 하나를 푸시
            stk.push(s[i]);
        else
        {
            if (stk.top() == s[i]) //스택의 top과 현재 글자를 비교
                stk.pop(); //짝이 이루어지면 스택에서 꺼낸다
            else
                stk.push(s[i]); //짝이 이루어 지지않으면 현재글자를 푸시
        }
    }
    return stk.empty(); //스택이 비어 있으면 모두 제거 됐으므로 1 아니면 0을 반환 
   
}

int main()
{

    string s = "cdcd";
     cout<<solution(s);
 
    return 1;
}