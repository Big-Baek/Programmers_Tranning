#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int TransTime(string s)
{
    return (stoi(s.substr(0,2))*60) + stoi(s.substr(3,2));
}

vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;
	// 1440
	//시간순으로 정렬
	sort(plans.begin(), plans.end(), [](const auto& a, const auto& b)
		{
			return (stoi(a[1].substr(0, 2)) * 60) + stoi(a[1].substr(3, 2)) < (stoi(b[1].substr(0, 2)) * 60) + stoi(b[1].substr(3, 2));
		});

	//과목, 남은시간
	stack<pair<string,int>> arr;

	for (int i = 0; i < plans.size() - 1; i++)
	{
        int first = TransTime(plans[i][1]) + stoi(plans[i][2]);
        int second = TransTime(plans[i + 1][1]);
        int havetime = second - first;
		if (first <= second) //재시간안에 공부가 끝날경우
        {    
            answer.push_back(plans[i][0]);
            while(!arr.empty())
            {
                if(arr.top().second <= havetime)
                {
                    answer.push_back(arr.top().first);
                    havetime -= arr.top().second;
                    arr.pop();
                }
                else
                {
                    arr.top().second -= havetime;
                    break;
                }
            } 
        }
		else arr.push({ plans[i][0], first - second}); //재시간안에 못할경우 스택에 푸쉬. 이 경우 havetime은 음수가 됨
	}

	arr.push({plans[plans.size() - 1][0], stoi(plans[plans.size() - 1][2])});

	while (!arr.empty())
	{
		answer.push_back(arr.top().first);
		arr.pop();
	}

	return answer;
}