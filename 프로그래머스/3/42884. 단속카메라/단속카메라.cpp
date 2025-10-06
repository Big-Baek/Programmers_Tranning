#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

int solution(vector<vector<int>> routes) {
	sort(routes.begin(), routes.end(), [](const auto& a, const auto& b) {
		return a[1] < b[1]; // 진출 시점 기준 정렬
		});

	int answer = 0;
	int last_camera = -30001;

	for (const auto& r : routes) {
		if (r[0] > last_camera) {
			last_camera = r[1];
			answer++;
		}
	}

	return answer;
}