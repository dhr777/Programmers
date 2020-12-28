#include <iostream>
#include<string>
#include<stack>
using namespace std;


bool solution(string s)
{
    //(())
    //(()(
    stack<char>stack;

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == ')' && stack.empty()) //올바른 괄호가 아닐때 리턴
            return false;

        if (s[i] == '(')
            stack.push('(');

        if (s[i] == ')')  //올바른 괄호가 성립될때 스택을 비워준다 
            stack.pop();


    }
    return stack.empty();

}


int main()
{
    string s = "()()";
    cout << solution(s);
    return 0;
}