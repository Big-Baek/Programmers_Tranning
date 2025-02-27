#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int start = 0;
	int end = 0;
	vector<string> arr;
	vector<int> ancole;
	while (1)
	{
		if (s[end] == ' ' || end == s.size())
		{
			arr.push_back(s.substr(start, end - start));
			start = end + 1;
		}
		if (end >= s.size())
		{
			break;
		}
		end++;
	}

	for (string s : arr)
	{
		int i = stoi(s);
		ancole.push_back(i);
	}
	int min = ancole[0];
	int max = ancole[0];
	for (int i : ancole)
	{
		if (i > max)
		{
			max = i;
		}
		else if (i < min)
		{
			min = i;
		}
	}
	answer.append(to_string(min));
	answer.append(" ");
	answer.append(to_string(max));


	return answer;
}