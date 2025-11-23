#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer(numbers.size(), -1);
	stack<pair<int, int>> arr; //값, 인덱스


	arr.push({ numbers[0],0 });

	for (int i = 1; i < numbers.size(); i++)
	{
		while (!arr.empty() && arr.top().first < numbers[i])
		{
			answer[arr.top().second] = numbers[i];
			arr.pop();
		}
		arr.push({ numbers[i],i });
	}
	return answer;
}