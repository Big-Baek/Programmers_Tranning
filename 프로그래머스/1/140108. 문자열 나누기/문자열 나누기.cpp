#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;

	while (!s.empty()) {
		int xcount = 0;
		int ycount = 0;
		char x = s[0];
		for (char c : s) {
			if (c == x) xcount++;
			else ycount++;
			if (xcount == ycount) break;
		}
		s.erase(0, xcount + ycount);
		answer++;
	}

	return answer;
}