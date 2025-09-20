#include <string>
#include <vector>

using namespace std;

int count_one(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int solution(int n) {
    int target = count_one(n);
    int i = n + 1;
    while (true) {
        if (count_one(i) == target) return i;
        i++;
    }
}