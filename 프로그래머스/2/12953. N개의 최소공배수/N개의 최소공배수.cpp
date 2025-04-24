#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
using namespace std;

int GCD(int a, int b) 
{ // 4, 16 이라 가정
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int solution(vector<int> arr) 
{
	int result = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		result = (result * arr[i]) / GCD(result, arr[i]);
	}

	return result;
}