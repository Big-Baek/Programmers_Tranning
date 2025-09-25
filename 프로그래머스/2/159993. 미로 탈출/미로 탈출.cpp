#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <tuple>

using namespace std;

int solution(vector<string> maps) {
    int n = maps.size(), m = maps[0].size();
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    deque<tuple<int, int, int, bool>> q; // x, y, distance, 레버 통과 여부

    // 시작점 찾기
    for (int i = 0; i < n; ++i) {
        size_t pos = maps[i].find('S');
        if (pos != string::npos) {
            q.push_back({i, (int)pos, 0, false});
            visited[i][pos][0] = true;
            break;
        }
    }

    int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

    while (!q.empty()) {
        auto [x, y, dist, passedL] = q.front(); q.pop_front();

        if (maps[x][y] == 'E' && passedL) return dist;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 'X') continue;

            bool nextPassedL = passedL || maps[nx][ny] == 'L';
            int state = nextPassedL ? 1 : 0;

            if (!visited[nx][ny][state]) {
                visited[nx][ny][state] = true;
                q.push_back({nx, ny, dist + 1, nextPassedL});
            }
        }
    }

    return -1; // 도달 불가
}