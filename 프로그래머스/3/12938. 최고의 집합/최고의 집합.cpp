#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;

	int teaser = s / n;
	int other = s % n;

	if (n > s)
	{
		answer.push_back(-1);
		return answer;
	}

	for (int i = 0; i < n; i++)
	{
		answer.push_back(teaser);
	}
	if (other != 0)
	{
		for (int i = 0; i < other; i++)
		{
			answer[i] += 1;
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}