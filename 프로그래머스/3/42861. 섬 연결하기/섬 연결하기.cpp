#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
vector<int> Nodes;

int find(int x) {
	if (Nodes[x] != x)
		Nodes[x] = find(Nodes[x]); // 여기서 압축!
	return Nodes[x];
}

void unite(int a, int b) // 두 집합을 합치는 함수. a < b여야 함
{
	if (find(a) != find(b))
	{
		Nodes[find(b)] = find(a);
	}
}

bool is_connected(int a, int b) //두 노드가 같은 노드인지 확인하는 함수
{
	return find(a) == find(b);
}

int solution(int n, vector<vector<int>> costs) 
{
	int answer = 0;

	Nodes.resize(n);
	for (int i = 0; i < n; i++) // 모든 노드는 본인이 루트노드
	{
		Nodes[i] = i;
	}

	//크루스칼 알고리즘: 간선비용이 적은 순으로 정렬
	sort(costs.begin(), costs.end(), [](const auto& a, const auto& b) {return a[2] < b[2]; });

	int edgeCount = 0;

	for (auto v : costs)
	{
		if (!is_connected(v[0], v[1]))
		{
			unite(v[0], v[1]);
			answer += v[2];
			edgeCount++;

			if (edgeCount == n - 1)
				break; // 모든 노드가 연결됨
		}
	}

	return answer;
}