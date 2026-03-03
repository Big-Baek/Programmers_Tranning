#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ChangeVal(int number, int Jin)
{
	if (number == 0) return "0";

	string digits = "0123456789ABCDEF"; //16진수까지 지원
	string answer;

	while (number > 0)//나눈값이 0이하가 될때까지 반복
	{
		answer += digits[number % Jin];
		number /= Jin;
	}

	reverse(answer.begin(), answer.end()); //역순으로 변환
	return answer;
}

string solution(int n, int t, int m, int p)
{
	string answer = "";

	int num = 0;
	string TotalNum = "";//구할 전체숫자

	for (int i = 0; i <= m*t; i++) //모든 숫자 구함
	{
		TotalNum += ChangeVal(num, n);//진수변환함수
		num++;
	}

	int count = p;
	for (int i = 0; i < t; i ++)//전체숫자준 쓸 숫자만 뽑기
	{
		answer += TotalNum[p-1];
		p += m;
	}

	return answer;
}