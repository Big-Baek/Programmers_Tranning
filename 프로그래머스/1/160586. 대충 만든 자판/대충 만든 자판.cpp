#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size(), 0);
    unordered_map<char, int> keyPressCount;
    vector<unordered_map<char, int>> keymaps;

    for (const string& s : keymap) {
        int count = 0;
        unordered_map<char, int> keys;
        for (char c : s) {
            if (keys.count(c) == 0) {
                keys[c] = ++count;
            } else {
                count++;
            }
        }
        keymaps.push_back(keys);
    }

    for (int i = 0; i < targets.size(); ++i) {
        const string& target = targets[i];
        int totalPresses = 0;
        bool isPossible = true;

        for (char c : target) {
            int minPresses = INT_MAX;
            for (const auto& keys : keymaps) {
                if (keys.count(c) != 0) {
                    minPresses = min(minPresses, keys.at(c));
                }
            }
            if (minPresses == INT_MAX) {
                isPossible = false;
                break;
            } else {
                totalPresses += minPresses;
            }
        }

        if (isPossible) {
            answer[i] = totalPresses;
        } else {
            answer[i] = -1;
        }
    }

    return answer;
}
