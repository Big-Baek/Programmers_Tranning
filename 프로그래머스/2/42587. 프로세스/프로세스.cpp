#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {

	int answer = 0;
	queue<pair<int, int>> m_que;//인덱스, 우선순위 저장
	vector<int> copy = priorities; //우선순위 복사
	sort(copy.begin(), copy.end(), greater());

	int first_work = copy.front();
	copy.erase(copy.begin());

	for (int i = 0; i < priorities.size(); i++)
	{
		m_que.push({ i, priorities[i] });
	}


	//priority_queue <pair<int, int>, vector<pair<int, int>>, compare> m_que;

	//for (int i = 0; i < priorities.size(); i++)
	//{
	//	m_que.push({ i, priorities[i] }); //번호와 우선순위순으로 삽입
	//}


	while (!m_que.empty())
	{
		if (m_que.front().second < first_work)//우선순위가 낮다면
		{
			pair<int, int> imsi = m_que.front();
			m_que.pop();
			m_que.push(imsi);
		}
		else if (m_que.front().second == first_work && m_que.front().first == location)
		{
			answer++;
			return answer;
		}
		else//우선순위가 높다면 최고순위를 변경하고 처리
		{
			first_work = copy.front();
			copy.erase(copy.begin());
			m_que.pop();
			answer++;
			
		}
	}
}