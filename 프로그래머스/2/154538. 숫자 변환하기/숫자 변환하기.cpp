#include <string>
#include <vector>
#include <queue>

using namespace std;


struct mm_data
{
	int value;
	int deep;

	mm_data(int a, int b)
	{
		value = a;
		deep = b;
	}
};

int solution(int x, int y, int n)
{
	if (x == y) return 0;

	queue<mm_data> m_que;
	m_que.push(mm_data(y, 0));

	while (!m_que.empty())
	{
		mm_data Own = m_que.front();

		if (Own.value == x)
		{
			return Own.deep;
		}

		if (Own.value % 3 == 0)
		{
			m_que.push(mm_data(Own.value/3, Own.deep + 1));
		}
		if (Own.value % 2 == 0)
		{
			m_que.push(mm_data(Own.value/2, Own.deep + 1));
		}
		if (Own.value - n > 0)
		{
			m_que.push(mm_data(Own.value - n, Own.deep + 1));
		}
		m_que.pop();

	}

	return -1;
}