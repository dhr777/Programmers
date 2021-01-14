#include<iostream>
#include <string>
#include <vector>

using namespace std;
string sk;
int check(string v)
{
    int idx = 0;
    int arr[26] = { 100 };
    


    for (int i = 0; i < sk.size(); i++) //겹치는 스킬이 있으면 몇번째 자리에 있는지 기록한다.
    {
        int j = 0;
        for (j; j < v.size(); j++)
        {
            if (sk[i] == v[j]) 
            {
                arr[i] = j;
                break;
            }
        }
        if (j == v.size())
            arr[i] = 100;
    }
    

        int cnt = 0;
        for (int i = 0; i < sk.size(); i++) //아무것도 겹치지 않으면 참이다
            if (arr[i] == 100)
                cnt++;       

        if (cnt == sk.size())return 1;
    
    for (int i = 0; i < sk.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])  // 스킬 트리 순서가 맞지않으면 0을 리턴
            return 0;
    }
    return 1;

}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    sk = skill;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        answer += check(skill_trees[i]);  //스킬트리가 참이면 1을 리턴 
    }

    return answer;
}

void main()
{
    vector<string>v = { "C","D","CB","BDA" };
    
    string s = "CBD";

    cout << solution(s, v);
}