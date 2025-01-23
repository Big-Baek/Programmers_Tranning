#include <string>
#include <vector>
#include<set>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    set<char> skipSet(skip.begin(), skip.end()); // skip 문자열 중복 제거

    for (char c : s) {
        int count = 0;
        while (count < index) {
            c = (c == 'z') ? 'a' : c + 1;
            if (skipSet.find(c) == skipSet.end()) { // skip에 포함되지 않는 경우만 증가
                count++;
            }
        }
        answer += c;
    }

    return answer;
}


