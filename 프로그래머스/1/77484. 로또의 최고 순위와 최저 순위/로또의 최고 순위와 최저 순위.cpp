#include <string>
#include <vector>
#include<algorithm>
#include <map>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	map<int, int> rank = { {6,1},{5,2},{4,3},{3,4},{2,5},{1,6},{0,6} };
	vector<int> answer;
	int Lpoint;
	int Spoint = 0;


	for (int L : lottos) {
		vector<int>::iterator IT;
		IT = find(win_nums.begin(), win_nums.end(), L);
		if (IT != win_nums.end()) {
			Spoint += 1;
		} //있는 숫자들로 최소값 설정 끝
	}
	Lpoint = Spoint;

	for (int j : lottos) {
		if (j == 0) {
			Lpoint += 1;
		}
	}


answer.push_back(rank[Lpoint]);
	answer.push_back(rank[Spoint]);
	
	return answer;
}