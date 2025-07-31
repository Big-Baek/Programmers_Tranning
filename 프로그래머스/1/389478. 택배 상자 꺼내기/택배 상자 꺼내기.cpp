#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
	int answer = 0;

	while (num <= n)
	{
		if (num % w != 0)
		{
			num = num + 1 + (2 * (w - (num % w)));
		}
		else
		{
			num = num + 1;
		}
		answer++;
	}

	return answer;
}