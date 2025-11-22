#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <list>
#include <cmath>
#include <limits>
#include <string>
#include <numeric>
#include <utility>
#include <ranges>
#include <array>
#include <unordered_set>

using namespace std;

#define INF INT_MAX




int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <=9; i++)
	{
		cout << n << " * " << i << " = " << n * i << endl;
	}


	return 0;
}