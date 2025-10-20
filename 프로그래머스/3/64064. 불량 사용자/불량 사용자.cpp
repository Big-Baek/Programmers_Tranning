#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

struct name_type {
    string key;
    vector<string> can_do;
    name_type() {
        key = "";
        can_do.resize(8); // 또는 동적으로 push_back 해도 됨
    }
};

set<set<string>> result;

void dfs(int depth, vector<name_type>& arr, unordered_set<string>& used, vector<string>& path) {
    if (depth == arr.size()) {
        result.insert(set<string>(path.begin(), path.end())); // 중복 제거
        return;
    }

    for (string user : arr[depth].can_do) {
        if (user.empty()) continue;
        if (used.count(user)) continue;

        used.insert(user);
        path.push_back(user);
        dfs(depth + 1, arr, used, path);
        path.pop_back();
        used.erase(user);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<name_type> arr(banned_id.size());

    // banned_id마다 가능한 user_id 매칭
    for (int i = 0; i < banned_id.size(); ++i) {
        string ban = banned_id[i];
        for (string user : user_id) {
            if (ban.size() != user.size()) continue;
            bool match = true;
            for (int j = 0; j < ban.size(); ++j) {
                if (ban[j] != '*' && ban[j] != user[j]) {
                    match = false;
                    break;
                }
            }
            if (match) arr[i].can_do.push_back(user);
        }
    }

    unordered_set<string> used;
    vector<string> path;
    dfs(0, arr, used, path);

    return result.size();
}