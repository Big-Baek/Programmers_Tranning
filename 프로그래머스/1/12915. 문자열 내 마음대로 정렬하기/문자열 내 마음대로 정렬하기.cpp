

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b, int n) {
    if (a[n] == b[n]) {
        return a < b; // n번째 문자가 동일한 경우 사전 순으로 정렬
    }
    return a[n] < b[n]; // n번째 문자를 기준으로 정렬
}

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](const string& a, const string& b) {
        return compare(a, b, n);
    });
    return strings;
}

int main() {
    vector<string> strings = {"sun", "bed", "car"};
    int n = 1;
    vector<string> sortedStrings = solution(strings, n);

    for (const string& str : sortedStrings) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}


