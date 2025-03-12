#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	
	unsigned long long pibot0 = 0;
	unsigned long long pibot1 = 1;

	unsigned long long pibot = 0;
   for (int i = 1; i < n; i++) {
     pibot = (pibot0 + pibot1) % 1234567; // 계산 도중 모듈러 연산
        pibot0 = pibot1;
        pibot1 = pibot;
    }

	return pibot1;


}