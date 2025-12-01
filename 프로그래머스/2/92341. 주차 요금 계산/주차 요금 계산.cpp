#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int cal(string intime, string outtime)
{
	int in = (stoi(intime.substr(0, 2)) * 60) + stoi(intime.substr(3, 2));
	int out = (stoi(outtime.substr(0, 2)) * 60) + stoi(outtime.substr(3, 2));

	return out - in;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	unordered_map<string, string> data; //차량 번호, 입차시간
	map<string, int> total; //차량번호, 총 시간
	for (string s : records)
	{
		if (s.substr(11, 3) == "IN")
		{
			data[s.substr(6, 4)] = s.substr(0, 5); //차량번호에 입차시간 삽입
			cout << s.substr(6, 4) << " 입차" << endl;
		}
		else //총 시간에 저장
		{
			total[s.substr(6, 4)] += cal(data[s.substr(6, 4)], s.substr(0, 5));
			data.erase(s.substr(6, 4));
		}
	}
	for (auto& it : data)
	{
		total[it.first] += cal(it.second, "23:59");
	}

	for (pair<const string, int>& pair : total) //차량번호, 총 주차 시간
	{
		int pay = 0;
		if (pair.second <= fees[0])
		{
			pay = fees[1];
		}
		else
		{
			pay = fees[1] + (((pair.second - fees[0]) / fees[2]) * fees[3]);
			if ((pair.second - fees[0]) % fees[2] != 0) pay += fees[3];
		}


		answer.push_back(pay);
	}


	return answer;
}