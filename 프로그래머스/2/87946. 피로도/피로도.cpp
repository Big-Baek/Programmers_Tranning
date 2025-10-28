#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;

	vector<int>score;
	int hp = k;
	sort(dungeons.begin(), dungeons.end(), [](const auto& a, const auto& b)
		{
			return a[1] < b[1];
		});

	do
	{
	int imsi = 0;
	hp = k;
		for (auto vec : dungeons)
		{
			if (vec[0] <= hp)
			{
				hp -= vec[1];
				imsi++;
			}
		}

		score.push_back(imsi);

	} while (next_permutation(dungeons.begin(), dungeons.end()));

	answer = *max_element(score.begin(),score.end());

	return answer;
}
