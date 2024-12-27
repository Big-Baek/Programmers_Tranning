#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> numbers = { "zero","one","two","three","four","five","six","seven","eight","nine" };

    for (int i = 0; i < numbers.size(); i++) { // numbers 배열의 각 문자열을 찾기
        size_t index = s.find(numbers[i]);

        while (index != string::npos) { // 문자열이 존재하는 동안 반복
            s.replace(index, numbers[i].length(), to_string(i));
            index = s.find(numbers[i], index + 1); // 다음 위치 검색
        }
    }

    answer = stoi(s); // 수정된 문자열을 정수로 변환
    return answer;
}
