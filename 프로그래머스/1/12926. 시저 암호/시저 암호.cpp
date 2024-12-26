#include <string>
#include <vector>

using namespace std;


string solution(string s, int n) {
    n %= 26; // 알파벳의 개수로 나머지 연산
    for (size_t i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) { // 알파벳인지 확인
            char base = isupper(s[i]) ? 'A' : 'a';
            s[i] = (s[i] - base + n) % 26 + base;
        }
    }
    return s;
}

