#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;
	

	for (int i = 0; i < sizes.size();i++) { //큰수가 앞으로 오게 정렬
		if (sizes[i][0] < sizes[i][1]) {
			int imsi = sizes[i][0];
			sizes[i][0] = sizes[i][1];
			sizes[i][1] = imsi;
		}
	}
	int big1 = sizes[0][0];
	int big2 = sizes[0][1];
	for (int j = 1; j < sizes.size(); j++) {
		if (sizes[j][0] > big1) {
			big1 = sizes[j][0];
		}
	}
	for (int j = 1; j < sizes.size(); j++) {
		if (sizes[j][1] > big2) {
			big2 = sizes[j][1];
		}
	}
	answer = big1 * big2;

	return answer;
}