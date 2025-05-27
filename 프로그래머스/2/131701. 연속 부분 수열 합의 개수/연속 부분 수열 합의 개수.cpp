#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>

using namespace std;


int solution(vector<int> elements) {

	set<int> setting;
	deque<int> que;
	int answer = 0;
	int count = 1;

	for (int i = 0; i < elements.size(); i++)
	{
		for (int j = 0; j < elements.size() + count - 1; j++)
		{
			que.push_back(elements[j%elements.size()]);
			if ((j + 1) / count > 0)
			{
				int sum = 0;
				for (const auto& val : que) {
					sum += val;
				}
				setting.insert(sum);
				que.pop_front();
			}
		}
		count++;
		que.clear();
	}

	answer = setting.size();
	return answer;
}