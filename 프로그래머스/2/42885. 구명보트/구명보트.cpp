#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#include <vector>
#include <algorithm>

int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end());

	int i = 0;
	int j = people.size() - 1;

	while (i<=j)
	{
		if (people[i] + people[j] <= limit)
		{
			i++;
		}
		j--;
		answer++;
	}

	return answer;
}