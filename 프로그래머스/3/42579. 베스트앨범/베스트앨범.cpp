#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> arr; // 장르별 (재생 수, 고유 번호)
    map<string, int> genreTotal; // 장르별 총 재생 수

    for (int i = 0; i < genres.size(); i++) {
        arr[genres[i]].push_back({plays[i], i});
        genreTotal[genres[i]] += plays[i];
    }

    // 장르별 총 재생 수 기준 정렬
    vector<pair<string, int>> sortedGenres(genreTotal.begin(), genreTotal.end());
    sort(sortedGenres.begin(), sortedGenres.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    for (auto& genre : sortedGenres) {
        auto& songs = arr[genre.first];
        sort(songs.begin(), songs.end(), [](auto& a, auto& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });

        for (int i = 0; i < songs.size() && i < 2; i++) {
            answer.push_back(songs[i].second);
        }
    }

    return answer;
}