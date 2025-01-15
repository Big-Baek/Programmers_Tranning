#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> basic = { "aya", "ye", "woo", "ma" };

    for (string c : babbling) {
        vector<string> test;
        bool valid = true;

        while (!c.empty()) {
            bool found = false;
            for (string word : basic) {
                if (c.find(word) == 0) { // 시작 부분에서 찾음
                    if (!test.empty() && test.back() == word) {
                        valid = false;
                    } else {
                        test.push_back(word);
                        c.erase(0, word.size()); // 해당 부분 제거
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                valid = false;
                break;
            }
        }
        if (valid && c.empty()) {
            answer += 1;
        }
    }

    return answer;
}
