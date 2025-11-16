#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer(2);

	vector<int> v;
	string type;

	for (string s : operations)
	{
		if (s[0] == 'I')
		{
			string number = s.substr(2, s.size() - 1);
			v.push_back(stoi(number));
		}
		else if (s[0] == 'D')
		{
			if (v.empty()) continue;
			sort(v.begin(), v.end());
			if (s[2] == '-')
			{
				v.erase(v.begin());
			}
			else
			{
				v.erase(v.end() - 1);
			}
		}
	}

	if (v.empty())
	{
		return { 0,0 };
	}
	sort(v.begin(), v.end());

	answer[0] = v.back();
	answer[1] = v.front();



	return answer;
}