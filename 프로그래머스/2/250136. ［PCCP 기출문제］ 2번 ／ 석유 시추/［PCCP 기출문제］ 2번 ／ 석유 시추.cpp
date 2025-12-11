#include <bits/stdc++.h>
using namespace std;

// BFS로 하나의 덩어리를 탐색하고, 덩어리 ID와 크기를 기록
int BFS(int sx, int sy,
        vector<vector<int>>& land,
        vector<vector<bool>>& visited,
        int id,
        vector<int>& sizes) {
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    queue<pair<int,int>> q;
    vector<pair<int,int>> cells;

    q.push({sx,sy});
    visited[sx][sy] = true;
    cells.push_back({sx,sy});

    int oilsize = 1;

    while(!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for(int d=0; d<4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx<0 || ny<0 || nx>=land.size() || ny>=land[0].size()) continue;
            if(visited[nx][ny]) continue;
            if(land[nx][ny]==0) continue;

            visited[nx][ny] = true;
            q.push({nx,ny});
            cells.push_back({nx,ny});
            oilsize++;
        }
    }

    // 덩어리 ID 기록
    sizes[id] = oilsize;
    for(auto [x,y] : cells) {
        land[x][y] = id;
    }
    return oilsize;
}

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m,false));
    vector<int> sizes; sizes.push_back(0); // id=0 dummy

    int id = 0;
    // 모든 덩어리 탐색
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(land[i][j]==1 && !visited[i][j]) {
                id++;
                sizes.push_back(0);
                BFS(i,j,land,visited,id,sizes);
            }
        }
    }

    int total=0, answer=0;
    // 열마다 덩어리 합산
    for(int j=0;j<m;j++) {
        unordered_set<int> seen;
        int sum=0;
        for(int i=0;i<n;i++) {
            if(land[i][j]>0) {
                int cid = land[i][j];
                if(!seen.count(cid)) {
                    sum += sizes[cid];
                    seen.insert(cid);
                }
            }
        }
        if(sum>total) {
            total=sum;
            answer=j;
        }
    }
    return total;
}