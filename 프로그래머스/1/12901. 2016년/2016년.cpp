#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	int max_day = 0;
	vector<string>weeks = { "THU","FRI","SAT","SUN","MON","TUE","WED" };


	for (int aa = 1; aa < a; aa++) {

		if (aa == 1 || aa == 3 || aa == 5 || aa == 7 || aa == 8 || aa == 10 || aa == 12) {//31일
			max_day = 31;
		}
		else if (aa == 4 || aa == 6 || aa == 9 || aa == 11) {//30일
			max_day = 30;
		}
		else  max_day = 29; //2월

		int mka = max_day % 7;
		for (int k = 0; k < mka; k++) {
			string imsi = weeks[0];
			for (int j = 0; j < weeks.size() - 1; j++) {
				weeks[j] = weeks[j + 1];
			}
			weeks[weeks.size() - 1] = imsi;
		}
	}

	answer = weeks[(b % 7)];

	return answer;
}