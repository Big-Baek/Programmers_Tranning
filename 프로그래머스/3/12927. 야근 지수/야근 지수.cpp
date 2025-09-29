#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>

using namespace std;

long long rr(priority_queue<int> pq)
{
	long long sum = 0;
	while (!pq.empty())
	{
		sum += (long long)pow(pq.top(), 2);
		pq.pop();
	}

	return sum;
}

long long solution(int n, vector<int> works) 
{

	sort(works.begin(), works.end(), greater());

	priority_queue<int> pq;
	for (const int &i : works)
	{
		pq.push(i);
	}

	while (n != 0 && pq.top() != 0)
	{
		pq.push(pq.top()-1);
		pq.pop();
		--n;
	}

	return rr(pq);
}
