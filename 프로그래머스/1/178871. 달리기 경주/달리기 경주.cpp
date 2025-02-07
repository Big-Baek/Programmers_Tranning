#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> player_indices;
    for (int i = 0; i < players.size(); ++i) {
        player_indices[players[i]] = i;
    }

    for (const string& S : callings) {
        int idx = player_indices[S];
        if (idx > 0) {
            swap(players[idx], players[idx - 1]);
            // Update the indices after the swap
            player_indices[players[idx]] = idx;
            player_indices[players[idx - 1]] = idx - 1;
        }
    }

    return players;
}
