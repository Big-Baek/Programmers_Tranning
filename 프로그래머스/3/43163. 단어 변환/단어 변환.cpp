#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string a, string b)
{
	int count = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			count++;
		}
	}
	
	if (count == 1) return true;
	else return false;
}


void dfs(string point, string target, vector<string> words, int counting, vector<int> & answer)
{
	if (check(point, target))
	{
		answer.push_back(counting);
		return;
	}

	//for (string s: words)
	//{
	//	if (s == point) continue;
	//	
	//	int count = 0;
	//	
	//	if (check(point, s))
	//	{
	//		dfs(s, target, words, ++counting, answer);
	//	}

	//}

	for (int i = counting-1; i < words.size(); i++)
	{
		if (words[i] == point) continue;

		int count = 0;

		if (check(point, words[i]))
		{
			dfs(words[i], target, words, ++counting, answer);
		}
	}
	
}

int solution(string begin, string target, vector<string> words) {
	
	vector<int> arr;
	dfs(begin, target, words, 1, arr);

	if (arr.empty()) return 0;
	int answer = *min_element(arr.begin(), arr.end());

	return answer;
}