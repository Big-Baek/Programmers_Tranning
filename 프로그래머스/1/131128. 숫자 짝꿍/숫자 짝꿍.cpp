#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::string solution(std::string X, std::string Y) {
    std::unordered_map<char, int> char_count;
    for (char c : X) {
        char_count[c]++;
    }
    
    std::string answer = "";
    for (char c : Y) {
        if (char_count[c] > 0) {
            answer += c;
            char_count[c]--;
        }
    }

    if (answer.empty()) {
        return "-1";
    }

    if (std::all_of(answer.begin(), answer.end(), [answer](char c) { return c == answer[0]; })) {
        return std::string(1, answer[0]);
    }

    std::sort(answer.begin(), answer.end(), std::greater<char>());

    return answer;
}

