#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool check(pair<int, int> Dog, vector<string> park, pair<char, int> o) {
    int n = park.size();
    int m = park[0].size();
    
    switch (o.first) {
    case 'N':
        for (int i = 0; i < o.second; i++) {
            if (Dog.first - i - 1 < 0 || park[Dog.first - i - 1][Dog.second] == 'X') return false;
        }
        break;
    case 'E':
        for (int i = 0; i < o.second; i++) {
            if (Dog.second + i + 1 >= m || park[Dog.first][Dog.second + i + 1] == 'X') return false;
        }
        break;
    case 'S':
        for (int i = 0; i < o.second; i++) {
            if (Dog.first + i + 1 >= n || park[Dog.first + i + 1][Dog.second] == 'X') return false;
        }
        break;
    case 'W':
        for (int i = 0; i < o.second; i++) {
            if (Dog.second - i - 1 < 0 || park[Dog.first][Dog.second - i - 1] == 'X') return false;
        }
        break;
    }
    
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    pair<int, int> Dog;
    vector<pair<char, int>> order;
    pair<int, int> map_size = { park.size(), park[0].size() };

    for (int i = 0; i < park.size(); i++) {
        string s = park[i];
        size_t pos = s.find('S');
        if (pos != string::npos) {
            Dog = { i, pos };
            break;
        }
    }

    for (string s : routes) {
        order.push_back({ s[0], s[2] - '0' });
    }

    for (auto o : order) {
        switch (o.first) {
        case 'N':
            if (Dog.first - o.second < 0 || check(Dog, park, o) == false) cout << "error" << endl;
            else Dog.first -= o.second;
            break;
        case 'E':
            if (Dog.second + o.second >= map_size.second || check(Dog, park, o) == false) cout << "error" << endl;
            else Dog.second += o.second;
            break;
        case 'S':
            if (Dog.first + o.second >= map_size.first || check(Dog, park, o) == false) cout << "error" << endl;
            else Dog.first += o.second;
            break;
        case 'W':
            if (Dog.second - o.second < 0 || check(Dog, park, o) == false) cout << "error" << endl;
            else Dog.second -= o.second;
            break;
        }
    }
    answer.push_back(Dog.first);
    answer.push_back(Dog.second);
    return answer;
}

