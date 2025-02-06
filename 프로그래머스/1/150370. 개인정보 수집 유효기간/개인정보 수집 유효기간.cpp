#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int del_year, del_month, del_day;
    int today_year, today_month, today_day;
    vector<int> answer;
    map<char, int> term;

    // terms를 map으로 변환
    for (string s : terms) {
        term[s[0]] = stoi(s.substr(2)); 
    }

    // "today" 문자열을 년, 월, 일로 파싱
    today_year = stoi(today.substr(0, 4));
    today_month = stoi(today.substr(5, 2));
    today_day = stoi(today.substr(8, 2));
    
    // privacies를 순회하면서 삭제 날짜 계산
    for (int i = 0; i < privacies.size(); i++) {
        string S = privacies[i];
        del_year = stoi(S.substr(0, 4));
        del_month = stoi(S.substr(5, 2));
        del_day = stoi(S.substr(8, 2));

        // 새로운 만료 날짜 계산
        del_month += term[S[11]]; 
        while (del_month > 12) {
            del_month -= 12;
            del_year++;
        }

        // 만료 날짜와 오늘 날짜 비교
        if (del_year < today_year || 
            (del_year == today_year && del_month < today_month) ||
            (del_year == today_year && del_month == today_month && del_day <= today_day)) {
            answer.push_back(i + 1); 
        }
    }

    return answer;
}
