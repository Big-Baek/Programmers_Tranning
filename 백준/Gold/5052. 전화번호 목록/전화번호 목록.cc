#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkPrefix(vector<string>& arr) {
    sort(arr.begin(), arr.end()); // 사전순 정렬

    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i].find(arr[i - 1]) == 0) { // 이전 문자열이 현재 문자열의 접두사인지 검사
            return true;
        }
    }
    return false;
}

int main() {
    int TestCase;
    cin >> TestCase;

    while (TestCase--) {
        int N;
        cin >> N;

        vector<string> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        cout << (checkPrefix(arr) ? "NO" : "YES") << endl;
    }

    return 0;
}