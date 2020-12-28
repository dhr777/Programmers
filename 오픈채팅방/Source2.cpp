#include<iostream>
#include <string>
#include <vector>
#include<map>
#include<sstream>

using namespace std;
map<string, string>m;

void push_to_map(string& s) //맵에 아이디, 닉 넣기
{
    stringstream ss(s);
    string message, id, nickname;

    ss >> message;
    if (message == "Leave")return;

    ss >> id >> nickname;

    m[id] = nickname;
}


vector<string> solution(vector<string> record) {
    vector<string> answer;
    string str, id;


    for (string& s : record) //맵에 아이디, 닉네임 저장하기
        push_to_map(s);

    for (string& s : record) //출력하기 
    {
        stringstream ss(s);
        ss >> str >> id;

        if (str != "Change")
        {
            if (str == "Enter")str = "님이 들어왔습니다.";
            if (str == "Leave")str = "님이 나갔습니다.";
            
            answer.push_back((m.find(id)->second) + str);
        }
    }

    return answer;
}