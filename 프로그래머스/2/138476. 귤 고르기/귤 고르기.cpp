#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	int minus = tangerine.size() - k;
	map<int, int> tan_size;

	for (int i : tangerine)
	{
		tan_size[i]++;
	}

	vector<pair<int, int>> v(tan_size.begin(), tan_size.end());

	sort(v.begin(), v.end(), [](const auto& a, const auto& b)
		{return a.second < b.second; });

	auto start = v.begin();
	while (minus != 0)
	{
		if (start->second <= minus)
		{
			minus -= start->second;
			start = v.erase(start);
		}
		else
		{
			minus--;
			start->second--;
			if (start->second == 0)
			{
				start = v.erase(start);
			}
		}
	}

	return v.size();
}