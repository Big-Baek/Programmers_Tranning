#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> student(n, 1); //인덱스+1을 n번째 학생으로 취급

	for (int i : lost) {
		student[i - 1]--;
	}
	for (int i : reserve) {
		student[i - 1]++;
	}
	for (int i = 0; i < n; i++) {
		if (student[i] == 0 && student[i - 1] == 2) {
			student[i - 1]--;
			student[i]++;
		}
		else if (student[i] == 0 && student[i + 1] == 2) {
			student[i + 1]--;
			student[i] ++;
		}
		
	}
	for (int i : student) {
		if (i > 0)answer++;
	}


	return answer;
}