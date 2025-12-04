#include <string>
#include <vector>

using namespace std;

int cantime(int a)
{
	string time = to_string(a);
	int hour = 0;
	int minuate = 0;


	if (time.size() == 3)
	{
		hour = time[0] - '0';
		minuate = stoi(time.substr(1, 2));//00
	}
	else
	{
		hour = stoi(time.substr(0, 2));
		minuate = stoi(time.substr(2, 2));
	}

	minuate += 10;
	if (minuate >= 60)
	{
		hour++;
		if (hour == 24) hour = 0;
		minuate %= 60;
	}



	return (hour * 100) + minuate;
}


int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
	int answer = schedules.size();

	for (int i = 0; i < timelogs.size(); i++)
	{
		int count = startday;
		for (int j = 0; j < 7; j++)
		{
	if (count == 6 || count == 7)
	{
		count++;
if (count == 8)count = 1;

		continue;
	}			
            if (timelogs[i][j] > cantime(schedules[i]))
			{
				answer--;
				break;
			}
			count++;
			if (count == 8)count = 1;
		}
	}

	return answer;
}