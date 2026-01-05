#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    map<int, pair<int, int>> Info; 
    map<pair<int, int>, int> CollisionCheck; 
    map<int, pair<int, int>> robot; 
    vector<int> targetpoint(routes.size(), 1);

    // 포인트 저장
    for (int i = 1; i <= points.size(); i++) {
        Info[i] = { points[i - 1][0], points[i - 1][1] };
    }

    // 로봇 초기 위치
    for (int i = 0; i < routes.size(); i++) {
        robot[i] = Info[routes[i][0]];
        CollisionCheck[robot[i]]++;
    }

    // 초기 충돌 체크
    for (auto &p : CollisionCheck) {
        if (p.second > 1) answer++;
    }

    // 시뮬레이션
    while (!robot.empty()) {
        CollisionCheck.clear();

        for (auto it = robot.begin(); it != robot.end(); ) {
            int id = it->first;
            auto &pos = it->second;

            // 이미 모든 목적지를 다 방문한 경우 → 제거
            if (targetpoint[id] >= routes[id].size()) {
                it = robot.erase(it);
                continue;
            }

            // 현재 목표 좌표
            pair<int,int> target = Info[routes[id][targetpoint[id]]];

            // 목표 도착 → 다음 목표로 이동
            if (pos == target) {
                targetpoint[id]++;

                // 더 이상 갈 곳 없음 → 제거
                if (targetpoint[id] >= routes[id].size()) {
                    it = robot.erase(it);
                    continue;
                }

                // 다음 목표 갱신
                target = Info[routes[id][targetpoint[id]]];
            }

            // 한 칸 이동
            if (pos.first < target.first) pos.first++;
            else if (pos.first > target.first) pos.first--;
            else if (pos.second < target.second) pos.second++;
            else if (pos.second > target.second) pos.second--;

            // 충돌 체크
            CollisionCheck[pos]++;

            ++it;
        }

        // 충돌 검사
        for (auto &p : CollisionCheck) {
            if (p.second > 1) answer++;
        }
    }

    return answer;
}