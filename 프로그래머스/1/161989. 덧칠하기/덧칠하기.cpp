#include <string>
#include <vector>

using namespace std;


int solution(int n, int m, vector<int> section) {
	int answer = 0;
	int index_num = 0;
	for (int han = section[index_num]; han <= section.back();) {

		

	while (section[index_num] < han) {
			index_num += 1;
		}
	han = section[index_num] + m;


		answer += 1;
	}

	return answer;
}