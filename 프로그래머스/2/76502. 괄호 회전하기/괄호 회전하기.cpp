#include <stack>
#include <algorithm>
#include <string>

int solution(std::string s) {
    int answer = 0;

    auto isValid = [](const std::string& str) -> bool {
        std::stack<char> source;
        for (char c : str) {
            if (c == '(' || c == '{' || c == '[') {
                source.push(c);
            } else {
                if (source.empty() || 
                   (c == ')' && source.top() != '(') ||
                   (c == '}' && source.top() != '{') ||
                   (c == ']' && source.top() != '[')) {
                    return false;
                }
                source.pop();
            }
        }
        return source.empty();
    };

    for (size_t i = 0; i < s.size(); i++) {
        if (isValid(s)) {
            answer++;
        }
        std::rotate(s.begin(), s.begin() + 1, s.end()); // 문자열 회전
    }

    return answer;
}