#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	unordered_map<string, int> dict; //문자열 -> 색인번호

	char c = 'A'-1;
	int dic_num = 26;

	for (int i = 1; i <= 26; i++) //사전 초기화
	{
		dict[string(1, c + i)] = i;
	}

	for (int i = 0; i < msg.size();)
	{
		int count = i;

		string s = string(1,msg[count]); //사전에 등록할 문자열
		string num_s;//색인번호를 불러올 문자열
		while (dict.find(s) != dict.end())
		{
			num_s = s;
			s.append(string(1,msg[++count]));
			++i;
		}
		dict.insert({ s,++dic_num });
		answer.push_back(dict[num_s]);

		count = 0;
	}


	return answer;
}