#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards)
{
	//박스의 최대갯수
	int max_num = cards.size();
	int box_num = 1;
	int card_num = cards[0];

	vector<vector<int>> all_group;
	vector<int> group;
	vector<bool> visited(max_num, false);

	bool all_true = false;

	while (!all_true)
	{
		while (!visited[box_num-1])
		{
			group.push_back(box_num);
			visited[box_num - 1] = true;
			box_num = card_num;
			card_num = cards[box_num - 1];
		}
		all_group.push_back(group);
		group.clear();
		all_true = all_of(visited.begin(), visited.end(), [](bool v) {return v; });
		box_num = find(visited.begin(), visited.end(), false) - visited.begin()+1;
		if (box_num <= max_num)
		{
			card_num = cards[box_num - 1];
		}
	}
	if (all_group.size() == 1) return 0;

	sort(all_group.begin(), all_group.end(), [](const vector<int>a, const vector<int>b) {return a.size() > b.size(); });
	return all_group[0].size() * all_group[1].size();
}