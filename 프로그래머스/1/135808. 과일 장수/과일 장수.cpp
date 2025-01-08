#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
	int answer = 0;
	int count = 0;
	int fail = score.size() % m; //포장하고 남을 사과
	int smaller;
	sort(score.begin(), score.end(), less<int>()); //오름차순 정렬하고
	
	vector<int>::iterator it = score.begin();
	for (int i = 0; i < fail; i++) {
		it = score.erase(it++); //작은숫자 없애기
	}
	smaller = score[0];

	for (int i = 0; i < score.size(); i++) {

			if (score[i] < smaller) {
				smaller = score[i]; //최저값 갱신
			}
			count++;
			if (count == m) {
				answer += (smaller * m);
				count = 0;
				smaller = score[i+1];
			}
		
	}

	return answer;
}