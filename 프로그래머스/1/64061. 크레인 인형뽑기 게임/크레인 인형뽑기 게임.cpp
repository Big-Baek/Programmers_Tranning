#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<deque<int>> arr(board[0].size());
	stack<int> cc;
	for (int i = 0; i < board[0].size(); i++)
	{
		int count = 0;
		for (int j : board[i])
		{
			if (j != 0)
			{
				arr[count].push_front(j);
				count++;
			}
			else
			{
				count++;
				continue;
			}
		}
	}

	for (int i : moves)
	{
		if (arr[i - 1].empty()) continue;

		if (!cc.empty() && cc.top() == arr[i - 1].back())
		{
			cc.pop();
			answer+=2;
		}
		else
		{
			cc.push(arr[i - 1].back());
		}
		arr[i - 1].pop_back();


	}


	return answer;
}