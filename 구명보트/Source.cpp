#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> p, int limit) {
    int answer = 0;
    
    sort(p.begin(), p.end());

    int left = 0;
    int right = p.size() - 1;
    while (right>left) 
    {

        if (right == left) { return ++answer; }

        if (p[left] > limit - p[right])
            right--;
        else
        {
            left++;
            right--;
        }

        answer++;
    }

    return answer;
}

void main()
{
    vector<int> v = { 160, 150, 140, 60, 50, 40 };
    int limit=200;

    cout << solution(v, limit);
}