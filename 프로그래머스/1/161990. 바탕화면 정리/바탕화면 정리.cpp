#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;
	int under_size = wallpaper.size();
	int r_size = wallpaper[0].size();//가로 몇칸인지
	int count = 0;
	int x = under_size;
	int y = r_size;
	for (int j = 0; j < wallpaper.size(); j++) {
		for (int i = 0; i < r_size; i++) {//우하값 확인
			if (wallpaper[j][i] == '#' && j < x) x = j;
			if (wallpaper[j][i] == '#' && i < y) y = i;


		}
	}
	answer.push_back(x);
	answer.push_back(y);
	x = 0;
	y = 0;
	for (int j = 0; j < wallpaper.size(); j++) {
		for (int i = 0; i < r_size; i++) {//우하값 확인
			if (wallpaper[j][i] == '#' && j > x) x = j;
			if (wallpaper[j][i] == '#' && i > y) y = i;


		}
	}
	answer.push_back(x + 1);
	answer.push_back(y + 1);
	return answer;
}