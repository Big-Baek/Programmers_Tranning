#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct Data
{
	int A_t;
	int B_t;
	int depth;

	Data(int a, int b, int c)
	{
		A_t = a;
		B_t = b;
		depth = c;
	}
};

unordered_set <long long> bitset64;

long long encode(int depth, int a, int b)
{
	return (((long long)depth << 40) | ((long long)a << 20) | (long long)b);
}

int min_nn = 130;

//추가될 데이터, A 최소값,
void dfs(Data data, const vector<vector<int>>& info, int n, int m)
{	
	//data의 조건 검사
	if (data.A_t >= min_nn) return;
	if (data.A_t >= n || data.B_t >= m) return;

	//set에 추가
	long long key = encode(data.depth, data.A_t, data.B_t);
	if (bitset64.count(key)) return;
	bitset64.insert(key);

	//끝에 도달했다면
	if (data.depth == info.size())
	{
		min_nn = min_nn >= data.A_t ? data.A_t : min_nn;
		return;
	}

	//새 데이터 생성
	Data A_data(data.A_t + info[data.depth][0], data.B_t, data.depth + 1);
	Data B_data(data.A_t, data.B_t + info[data.depth][1], data.depth + 1);

	dfs(A_data, info, n, m);
	dfs(B_data, info, n, m);
}

int solution(vector<vector<int>> info, int n, int m)
{
	Data nnew(0, 0, 0);

	dfs(nnew, info, n, m);


	return min_nn == 130 ? -1 : min_nn;
}