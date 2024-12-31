#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	



	for (int i = 0; i < commands.size(); i++) {
		vector<int> cutting(0);
		int first = commands[i][0];
		int last = commands[i][1];
		int checking = commands[i][2];
		for (int j = first-1; j < last; j++) {
			cutting.push_back(array[j]); //자른 값 추가
		}
		sort(cutting.begin(), cutting.end(),less<int>()); //오름차순 정렬
		answer.push_back(cutting[checking-1]);
	}
	
	return answer;
}