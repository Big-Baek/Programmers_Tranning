#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer(1);
	vector<int> man1, man2, man3;
	vector<int>sol_num(3);
	vector<int> cycle = { 3,1,2,4,5 };




	int count1 = 0, count2 = 1, count3 = 0;



	for (int i = 0; i < answers.size(); i++) {

		if (count1 == 5) {
			count1 = 0;
		}
		man1.push_back(1 + count1);
		count1++;

		man2.push_back(2);
		man2.push_back(count2);
		count2++;
		if (count2 == 2)count2++;
		else if (count2 == 6)count2 = 1;

		if (count3 == 5) count3 = 0;
		man3.push_back(cycle[count3]);
		man3.push_back(cycle[count3]);
		count3++;

		if (answers[i] == man1[i]) 	sol_num[0] += 1;
		if (answers[i] == man2[i])  sol_num[1] += 1;
		if (answers[i] == man3[i])	sol_num[2] += 1;
	}
	
	answer[0] = {1};
	int bigger = sol_num[0];

	for (int i = 1; i < 3; i++) {
		if (sol_num[i] > bigger) {
			bigger = sol_num[i];
			answer[0] = i+1;
		}
		else if (sol_num[i] == bigger) {
			answer.push_back(i + 1);
		}
	}

	
	





	return answer;
}