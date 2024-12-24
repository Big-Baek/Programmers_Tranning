#include <string>
#include <vector>

using namespace std;

#include <string>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer;
    bool isUpper = true; // 대문자로 변환할 차례인지 여부

    for (char c : s) {
        if (c == ' ') {
            // 공백은 그대로 추가하고, 대소문자 플래그 초기화
            answer += c;
            isUpper = true;
        } else {
            // 대소문자 변환 후 플래그 변경
            answer += isUpper ? toupper(c) : tolower(c);
            isUpper = !isUpper;
        }
    }

    return answer;
}

