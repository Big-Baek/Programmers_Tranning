#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <queue>
using namespace std;


int main()
{
	string s;

	cin >> s;
	int ii = 0;
	vector<int> alpha(26);

	for (char c : s)
	{
		ii = c - 97;
		alpha[ii]++;
	}


	for (int i : alpha)
	{
		cout << i << " ";
	}

	return 0;
}