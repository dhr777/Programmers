#include<iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(int bridge, int weight, vector<int> truck) {
    int answer = 0;
    int p=0;
    int q_weight = 0;
    queue<int>q;

    for (int i = 0; i < bridge-1; i++)
        q.push(0);
    
    while (1) 
    {
        
       answer++; //시간경과
        
        if (p >= truck.size()) //마지막 트럭이 들어오면 종료
        {
            answer += bridge-1;
            break;
        }

        if(q_weight+truck[p]<=weight) // 무게 조건이 충족되면 트럭을다리에 올림
        {
            q.push(truck[p]);
            q_weight += truck[p];
            p++;
        }
        else //트럭을 다리에 올릴 수 없으면 큐에 0을 푸시
            q.push(0);        

            q_weight -= q.front();  
            q.pop(); // 큐의 마지막에 있는 것을 뺌.
  }
    
    return answer++;
}

void main()
{
    int length = 2;
    int weight = 10;
    vector<int> v{ 7,4,5,6 };
    cout<<solution(length,weight,v);
    
   
}