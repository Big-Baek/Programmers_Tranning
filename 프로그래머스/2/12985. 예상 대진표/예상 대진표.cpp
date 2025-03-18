#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 1;
	int abss;
	if (a % 2 == 0)
	{
		abss = a - 1;
	}
	else
	{
		abss = a + 1;
	}


	while (b!= abss)
	{
		if (a % 2 == 0)
		{
			a /= 2;
			if(a%2==0)abss = a - 1;
			else {
				abss = a + 1;
			}
		}
		else
		{
			a++;
			a /= 2;
			if (a % 2 == 0)abss = a - 1;
			else {
				abss = a + 1;
			}
		}
	
		if (b % 2 == 0)
		{
			b /= 2;
		}
		else
		{
			b++;
			b /= 2;
		}
		answer++;

	}


	return answer;
}