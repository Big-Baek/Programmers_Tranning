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
#include <bitset>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
  
    int result1 = a + b - c;
    int result2 = stoi(to_string(a) + to_string(b)) - c;

    cout << result1 << endl << result2;

	return 0;
}