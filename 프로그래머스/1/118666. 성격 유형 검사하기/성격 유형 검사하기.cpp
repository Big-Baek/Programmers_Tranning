#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;

void cal(vector<string> survey, vector<int> choices, char a, char b, map<char, int>& kaka, int count) {
    if (choices[count] == 4) return;
    else if (choices[count] < 4) {
        kaka[a] += 4 - choices[count]; // 선택에 따라 누적
    }
    else {
        kaka[b] += choices[count] - 4; // 선택에 따라 누적
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer;
    int count = 0;
    map<char, int> kaka;

    for (string S : survey) {
        if (S[0] == 'R' || S[0] == 'T') {
            cal(survey, choices, S[0], S[1], kaka, count);
        } else if (S[0] == 'C' || S[0] == 'F') {
            cal(survey, choices, S[0], S[1], kaka, count);
        } else if (S[0] == 'J' || S[0] == 'M') {
            cal(survey, choices, S[0], S[1], kaka, count);
        } else {
            cal(survey, choices, S[0], S[1], kaka, count);
        }
        count++;
    }

    if (kaka['R'] >= kaka['T']) answer.append("R");
    else answer.append("T");
    if (kaka['C'] >= kaka['F']) answer.append("C");
    else answer.append("F");
    if (kaka['J'] >= kaka['M']) answer.append("J");
    else answer.append("M");
    if (kaka['A'] >= kaka['N']) answer.append("A");
    else answer.append("N");

    return answer;
}

int main() {
    vector<string> survey = { "AN","CF","MJ","RT","NA" };
    vector<int> choices = { 5,3,2,7,5 };

    cout << solution(survey, choices);

    return 0;
}
