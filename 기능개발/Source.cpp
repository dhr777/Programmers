#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int p = 0; // 배포될 곳을 가리킴
    int count = 0;
    while (1)
    {
        for(int i=0;i<progresses.size();i++) // 하루 개발된 양을 대입
        progresses[i] += speeds[i];

        for (p; p < progresses.size(); p++)
        {
            if (progresses[p] >= 100) 
                count++;
                else break;          
        }

        if(count!=0)
        answer.push_back(count);
        
        count = 0;

        if (p == progresses.size()) //모두 배포되었을 때 종료 
            break;
    }

    return answer;
}

int main()
{
    
   
    vector<int>v1 = { 95,90,99,99,80,99 };
    vector<int>v2 = { 1,1,1,1,1,1 };
   
    vector<int>v3;
    v3=solution(v1,v2);
   
    for (auto v : v3)
        cout << v;
   
    return 0;
}