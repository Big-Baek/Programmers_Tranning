#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long interior = 0; // x>0, y>0 (1사분면 내부만)
    for (int x = 1; x <= r2; x++) {
        long long inner = 1LL * r1 * r1 - 1LL * x * x;
        long long outer = 1LL * r2 * r2 - 1LL * x * x;

        // y 범위: y_min..y_max (양의 정수만)
        int y_min = 1; // 양의 축 제외 -> 최소 1
        if (inner > 0) {
            y_min = max(y_min, (int)ceil(sqrt((long double)inner)));
        }
        if (outer < 0) continue; // 바깥 원에서 탈락
        int y_max = (int)floor(sqrt((long double)outer));

        if (y_min <= y_max) {
            interior += (y_max - y_min + 1);
        }
    }

    // 축 위 점들 (정확히 별도 계산)
    // x=0, y>0: r1 <= y <= r2
    long long axisY = 0;
    if (r2 >= 1) {
        int y_start = max(1, (int)ceil((long double)r1));
        int y_end   = (int)floor((long double)r2);
        if (y_start <= y_end) axisY = (y_end - y_start + 1);
    }

    // y=0, x>0: r1 <= x <= r2
    long long axisX = 0;
    if (r2 >= 1) {
        int x_start = max(1, (int)ceil((long double)r1));
        int x_end   = (int)floor((long double)r2);
        if (x_start <= x_end) axisX = (x_end - x_start + 1);
    }

    // 원점
    long long origin = (r1 == 0 ? 1 : 0);

    // 전체 합산
    // 내부 점은 4배, 축 위 점은 각 2배(상하/좌우), 원점은 1배
    long long total = interior * 4 + axisY * 2 + axisX * 2 + origin;
    return total;
}

