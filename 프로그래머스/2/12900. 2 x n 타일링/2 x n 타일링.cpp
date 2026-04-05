#include <string>
#include <vector>

using namespace std;

int dfs(int n, vector<int>& memo)
{
	if (memo[n] != 0)return memo[n];
	memo[n] = (dfs(n - 1, memo) + dfs(n - 2, memo)) %1000000007;
	return memo[n];
}

int solution(int n) {
	int answer = 0;

	vector<int> memo(n + 1, 0);
	memo[1] = 1;
	memo[2] = 2;
	answer = dfs(n, memo);

	return answer;
}