#include<iostream>
#include <string>
#include <vector>

using namespace std;

int arr[101][101] ;

int solution(int m, int n, vector<vector<int>> puddles) {

   
    arr[1][1] = 0;

    for (int i = 0; i < puddles.size(); i++) //물에 잠긴지역 넣기 
        arr[puddles[i][1]][puddles[i][0]] = -1;
    
    

    int num = 0;                  
    for (int i = 1; i <= m; i++) {      //첫번째 행 또는 열이 물에 잠기면 그 다음 길은 갈 수 없음
        if (arr[1][i] == -1)num = 1;
        if (num)arr[1][i] = 0;
        else arr[1][i] = 1;
    }
    num = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i][1] == -1)num = 1;
        if (num)arr[i][1] = 0;
        else arr[i][1] = 1;
    }



    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (arr[i][j] == -1) //물에 잠겼으면 현재 길에 0대입
                arr[i][j] = 0;
            else
            arr[i][j] = (arr[i][j - 1] + arr[i - 1][j])%1000000007; // 왼쪽 경로 개수 + 윗경로 개수   
        }
        
    }

    return arr[n][m];
}

int main()
{


    int m = 4, n = 3;

    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    v1.push_back(2);
    v1.push_back(2);
   
    v.push_back(v1);



    
    cout<<solution(4, 3, v);

    return 0;
}