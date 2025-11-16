#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> number, int target, int index, int sum, int& answer)
{
	if (number.size() == index)
	{
		if (sum == target)
		{
			answer++;
		}
		return;
	}

	int minus = sum - number[index];
	int plus = sum + number[index];


	dfs(number, target, index + 1, minus,answer);
	dfs(number, target, index + 1, plus, answer);

}


int solution(vector<int> numbers, int target) {
	int answer = 0;

	dfs(numbers, target, 0, 0,answer);

	return answer;
}