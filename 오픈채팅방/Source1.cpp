#include<iostream>
#include<map>
#include <string>
#include <vector>

using namespace std;


vector<string> solution(vector<string> record) {
    vector<string>answer;
    map<string, string>m;
    string id = "";
    string nickname = "";
    int blank = 0;
    for (int i = 0; i < record.size(); i++)
    {
        if (record[i][0] == 'E' || record[i][0] == 'C') //최초입장 또는 닉네임이 바뀔 때
        {
            for (int j = 0; j < record[i].size(); j++) //str안에 id가없으면 id와 닉을 넣음
            {
                if (record[i][j] == ' ') { blank++; }
                if (blank == 1) { id = id + record[i][j]; }
                if (blank == 2) { nickname = nickname + record[i][j]; }
            }
            id.erase(0, 1);
            nickname.erase(0, 1);



            if (m.find(id) == m.end()) //맵에 키(아이디), 밸류(닉네임) 넣어주기
            {
                m.insert({ id, nickname });
            }
            else
            {
                m.find(id)->second = nickname;
            }



        }
        blank = 0; id = ""; nickname = ""; //공백, 닉네임 초기화;

    }


    for (int i = 0; i < record.size(); i++)
    {

        for (int j = 0; j < record[i].size(); j++) // id만 추출
        {
            if (record[i][j] == ' ') { blank++; }
            if (blank == 1) { id = id + record[i][j]; }
        }
        id.erase(0, 1);

        if (record[i][0] == 'E')
        {

            answer.push_back(m.find(id)->second + "님이 들어왔습니다."); //해당 아이디에 맞는 벨류 출력
        }
        if (record[i][0] == 'L')
        {

            answer.push_back(m.find(id)->second + "님이 나갔습니다.");  //해당 아이디에 맞는 벨류 출력
        }
        blank = 0; id = "";//초기화;
    }
    return answer;
}