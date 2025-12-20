#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer(2);

	vector<pair<int, int>> canindex;
	deque<int> window; // 값

	int total = 0;
	int start = 0;
	int end = 0;
	int target = 0;
	while (start < sequence.size())
	{
		if(end < sequence.size()) target = sequence[end];//값
		if (total == k)
		{
			canindex.push_back({ start,end - 1 });
			total -= window.front();
			window.pop_front();
			start++;
		}
		if (total > k || end >= sequence.size())
		{
			if (window.empty()) break;
			total -= window.front();
			window.pop_front();
			start++;
			continue;
		}
		if (total < k )
		{
			total += target;
			window.push_back(target);
			end++;
			continue;
		}
	
	}

	int last = 10000000;

	for (pair<int, int> p : canindex)
	{
		if (p.second - p.first < last)
		{
			answer[0] = p.first;
			answer[1] = p.second;
			last = p.second - p.first;
		}
	}

	return answer;
}