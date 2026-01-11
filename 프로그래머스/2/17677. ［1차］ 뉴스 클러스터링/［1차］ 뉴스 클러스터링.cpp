#include <string>
#include <map>

using namespace std;


int solution(string str1, string str2) {
	double answer = 1;
	map<string, int> Info1, Info2;
	map<string, int> U;
	double samecount = 0;


	//1. 모든 문자를 대문자로 변환
	for (char& c : str1)
	{
		c = toupper(c);
	}
	for (char& c : str2)
	{
		c = toupper(c);
	}

	//map에 데이터 저장
	for (int i = 0; i < str1.size() - 1; i++)
	{
		if (isalpha(str1[i]) && isalpha(str1[i + 1]))
		{
			string imsi = str1.substr(i, 2);
			Info1[imsi]++;
		}
	}
	for (int i = 0; i < str2.size()-1; i++)
	{
		if (isalpha(str2[i]) && isalpha(str2[i + 1]))
		{
			string imsi = str2.substr(i, 2);
			Info2[imsi]++;
		}
	}

	//저장한 데이터 비교후 합집합 생성
	for (auto p : Info1)
	{
		U[p.first] = p.second;
	}
	for (auto p : Info2)
	{
		U[p.first] = max(U[p.first], p.second);
	}

	// 교집합 추리기
	for (auto& pair : Info1)
	{
		if (Info2.count(pair.first))
			samecount += min(pair.second, Info2[pair.first]);
	}
	double Uin = 0;

	//합집합 크기
	for (auto p : U)
	{
		Uin += p.second;
	}
	if (Info1.empty() && Info2.empty()) {
		return 65536;
	}

	answer = samecount / Uin;
	answer *= 65536;

	return (int)answer;
}