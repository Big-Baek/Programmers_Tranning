#include <iostream>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }

    return dp[n];
}

int main() {
    int n = 4;
    cout << "멀리 뛰기 방법 수: " << solution(n) << endl;
    return 0;
}