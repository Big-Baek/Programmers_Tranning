#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
	vector<int> answer;

	for (auto ball : balls)
	{
		vector<pair<int, int>> coordinate = { {ball[0], (2*n)-ball[1]}, {ball[0],-ball[1]}, {-ball[0],ball[1]}, {(2*m)-ball[0],ball[1]}};
		vector<int> distance;

		for (int i = 0; i < coordinate.size(); i++)
		{
			int bb = ((coordinate[i].first - startX) * (coordinate[i].first - startX)) + ((coordinate[i].second - startY) * (coordinate[i].second - startY));
			if (i == 0 && ball[1]> startY && ball[0] == startX) continue;
			else if (i == 1 && ball[1] < startY && ball[0] == startX) continue;
			else if (i == 2 && ball[0] < startX && ball[1] == startY)continue;
			else if (i == 3 && ball[0] > startX && ball[1] == startY) continue;
			else
			{
				distance.push_back(bb);
			}
		}

		sort(distance.begin(), distance.end());
		answer.push_back(distance.front());
	}

	return answer;
}