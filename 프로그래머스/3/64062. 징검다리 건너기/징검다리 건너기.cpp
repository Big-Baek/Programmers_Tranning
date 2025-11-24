#include <vector>
#include <algorithm>
using namespace std;

bool canCross(const vector<int>& stones, int k, int people) {
    int contin = 0;
    for (int s : stones) {
        if (s - people < 0) { // 돌이 버티지 못함
            contin++;
            if (contin >= k) return false; // 연속 k개 돌이 무너짐
        } else {
            contin = 0; // 끊기면 초기화
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int st = 1;
    int en = *max_element(stones.begin(), stones.end());
    int answer = 0;

    while (st <= en) {
        int mid = (st + en) / 2;
        if (canCross(stones, k, mid)) {
            // mid명이 건널 수 있다면 더 많은 인원도 가능할 수 있음
            answer = mid;
            st = mid + 1;
        } else {
            // mid명이 건널 수 없다면 인원을 줄여야 함
            en = mid - 1;
        }
    }

    return answer;
}