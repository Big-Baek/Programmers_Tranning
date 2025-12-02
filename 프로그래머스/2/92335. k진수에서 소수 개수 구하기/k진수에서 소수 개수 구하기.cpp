#include <string>
#include <vector>
#include <stack>

using namespace std;


bool confirm(const string& a) {
    if (a.empty()) return false; // 빈 문자열 방지
    long long num = stoll(a);

    if (num == 1) return false;
    if (num == 2 || num == 3) return true;
    if ((num & 1LL) == 0 || num % 3 == 0) return false;

    for (long long i = 5; i <= num / i; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    stack<string> k_number;

    while (n >= k) {
        k_number.push(to_string(n % k));
        n /= k;
    }
    k_number.push(to_string(n));

    string Cur = "";
    while (!k_number.empty()) {
        if (k_number.top() != "0") {
            Cur += k_number.top();
        } else {
            if (!Cur.empty() && confirm(Cur)) answer++;
            Cur.clear();
        }
        k_number.pop();
    }
    if (!Cur.empty() && confirm(Cur)) answer++;

    return answer;
}