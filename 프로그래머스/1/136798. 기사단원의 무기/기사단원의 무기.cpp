#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
using namespace std;

int solution(int number, int limit, int power) {

	int answer = 0;
	int sum = 0;

	for (int Knight = 1; Knight <= number; Knight++) {
		sum = 0;
		int m_sq = sqrt(Knight);

		for (int i = 1; i <= m_sq; i++) {
			if (Knight % i == 0) {
				sum += 2;
			}
			double same = (double)Knight / (double)i;
			if (same == i)
			{
				sum -= 1;
				cout << Knight << "번째 기사의" << i << endl;
			}
		}

		if (sum > limit) {
			answer += power;
		}
		else answer += sum;
	}

	return answer;
}