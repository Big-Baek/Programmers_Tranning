#include <iostream>
using namespace std;

int solution(int n) {
	int answer = 1;

	while (n!=1)
	{
		if (n & 1)
		{
			answer += 1;
		}
		n /= 2;
	}

	return answer;
}