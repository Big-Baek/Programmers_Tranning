#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
	vector<int> answer;
	vector<int> honor;
	vector<int>::iterator IT;
	for (int i = 0; i < score.size(); i++) {



		if (i < k) {
			honor.push_back(score[i]);
			sort(honor.begin(), honor.end(), greater<int>());
			answer.push_back(honor.back());
		}
		else if (i >= k && score[i] > honor.back()) {
			IT = --honor.end();
			honor.erase(IT);
			honor.push_back(score[i]);
			sort(honor.begin(), honor.end(), greater<int>());
			answer.push_back(honor.back());
		}
		else answer.push_back(honor.back());
		
	}


	return answer;
}