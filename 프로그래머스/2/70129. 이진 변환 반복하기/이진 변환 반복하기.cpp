#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer; // 최종 결과 저장
    int Delete_Zero_Count = 0; // 제거된 0의 개수
    int Transform_Count = 0;   // 변환 횟수

    while (s != "1") {
        // 문자열에서 '0' 제거하고 제거 개수 세기
        Delete_Zero_Count += count(s.begin(), s.end(), '0');
        s.erase(remove(s.begin(), s.end(), '0'), s.end());

        // 문자열 길이를 2진수로 변환
        int length = s.size();
        string New_Num;
        while (length > 0) {
            New_Num = (char)(length % 2 + '0') + New_Num;
            length /= 2;
        }

        s = New_Num; // 새 2진수 문자열로 갱신
        Transform_Count++; // 변환 횟수 증가
    }

    // 변환 횟수와 제거된 0의 개수를 결과에 추가
    answer.push_back(Transform_Count);
    answer.push_back(Delete_Zero_Count);

    return answer;
}