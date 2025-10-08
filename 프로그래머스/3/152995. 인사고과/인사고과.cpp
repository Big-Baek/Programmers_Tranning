#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> scores) {
    int wanhoSum = scores[0][0] + scores[0][1];
    int wanhoAtt = scores[0][0];
    int wanhoPeer = scores[0][1];

    // 정렬: 근무 태도 내림차순, 동료 평가 오름차순
    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });

    int maxPeer = 0;
    int answer = 1;

    for (const auto& s : scores) {
        int att = s[0], peer = s[1];
        if (peer < maxPeer) {
            // 탈락자
            if (att == wanhoAtt && peer == wanhoPeer) return -1;
        } else {
            // 인센티브 대상자
            if (att + peer > wanhoSum) answer++;
            maxPeer = max(maxPeer, peer);
        }
    }

    return answer;
}