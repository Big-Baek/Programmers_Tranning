#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <numeric>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer(id_list.size());
	set<string> gilty;
	map<string, int> criminal;
	multimap<string, string>New_Report;
	pair<string, string> imsi;



	for (string s : report) {
		int end = 0;
		for (int i = 0; s[i] != ' '; i++) {
			end++;
		}
		string reporter = s.substr(0, end); // 신고인 저장
		string reported = s.substr(end + 1, s.size() - end - 1); // 피신고인 저장
		imsi = make_pair(reported, reporter);

		if (New_Report.find(reported) == New_Report.end() ||
			find_if(New_Report.equal_range(reported).first, New_Report.equal_range(reported).second,
				[&reporter](const pair<string, string>& p) { return p.second == reporter; }) == New_Report.equal_range(reported).second) {
			New_Report.insert(imsi);
		}
	}





	for (auto sp : New_Report) {//사람당 신고횟수 저장
		criminal[sp.first]++;
		if (criminal[sp.first] >= k)//신고횟수 1이상이면
		{
			gilty.insert(sp.first);//gilty에 정지인 저장
		}
	}

	for (string ss : gilty)//정지인을 신고한 사람 찾기
	{
		auto range = New_Report.equal_range(ss);
		for (auto it = range.first; it != range.second; ++it)
		{
			auto IT = find(id_list.begin(), id_list.end(), it->second);
			int index = distance(id_list.begin(), IT);
            			answer[index] += 1;

		}
	}
	return answer;
}
