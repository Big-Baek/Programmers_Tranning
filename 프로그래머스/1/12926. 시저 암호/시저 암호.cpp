#include <string>
#include <vector>

using namespace std;


string solution(string s, int n) {
    n %= 26; // 알파벳의 개수로 나머지 연산
    for (size_t i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) { // 알파벳인지 확인
            char base = isupper(s[i]) ? 'A' : 'a';
            s[i] = (s[i] - base + n) % 26 + base;
            	/*원본에서 첫 알파벳 숫자를 빼면 25 이하의 숫자가 나온다
	거기서 밀어버릴 n을 더하면 원본에서 밀 최종 n값이 나온다.
	근데 25이상의 숫자가 나올수도 있기에 %26을 해둔다
	원본 (A든 a든)에서 최종n을 더하면 원하는 값이 나온다.*/
        }
    }
    return s;
}

