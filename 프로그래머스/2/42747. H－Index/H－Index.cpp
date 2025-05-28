#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<>());  // 내림차순 정렬
    int hIndex = 0;

    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {  // 현재 논문의 인용 횟수가 남은 논문 개수보다 많다면
            hIndex = i + 1;
        }
        else {
            break;  // 조건을 만족하지 않으면 종료
        }
    }

    return hIndex;
}