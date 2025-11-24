#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int ap = 0;
	int bp = 0;

	while (bp < B.size())
	{
		if (B[bp] > A[ap])
		{
			bp++;
			ap++;
			answer++;
		}
		else
		{
			bp++;
		}
	}




	return answer;
}