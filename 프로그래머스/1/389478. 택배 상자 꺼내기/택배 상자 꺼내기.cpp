#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
	int answer = 0;
	int next = num;

	while (next <= n)
	{
		if (next % w != 0)
		{
			next = next + 1 + (2 * (w - (next % w)));
		}
		else
		{
			next = next + 1;
		}
		answer++;
	}

	return answer;
}