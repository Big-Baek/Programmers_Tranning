#include <iostream>
#include <vector>
#include <stack>

using namespace std;

enum Hamburger {
    none,
    bread,
    vesi,
    meat
};

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> s;

    for (int item : ingredient) {
        s.push(item);

        // 스택의 상위 4개 요소 확인
        if (s.size() >= 4) {
            int top1 = s.top(); s.pop();
            int top2 = s.top(); s.pop();
            int top3 = s.top(); s.pop();
            int top4 = s.top(); s.pop();

            // 햄버거 패턴이 맞으면 삭제, 틀리면 되돌리기
            if (top4 == bread && top3 == vesi && top2 == meat && top1 == bread) {
                answer++;
            }
            else {
                s.push(top4);
                s.push(top3);
                s.push(top2);
                s.push(top1);
            }
        }
    }

    return answer;
}