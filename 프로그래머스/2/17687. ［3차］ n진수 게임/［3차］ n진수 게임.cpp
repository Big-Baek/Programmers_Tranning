#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ChangeVal(int number, int Jin)
{
	if (number == 0) return "0";

	string digits = "0123456789ABCDEF"; //16진수 지원
	string answer;
	while (number > 0)
	{
		answer += digits[number % Jin];
		number /= Jin;
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

string solution(int n, int t, int m, int p)//진수, 구할 숫자길이, 총 멤버, 본인 차례 
{
	string answer = "";
	int num = 0;

	string TotalNum = "";
	for (int i = 0; i <= m*t; i++) //모든 숫자 구함
	{
		TotalNum += ChangeVal(num, n);
		num++;
	}

	int count = p;
	for (int i = 0; i < t; i ++)
	{
		answer += TotalNum[p-1];
		p += m;
	}

	return answer;
}