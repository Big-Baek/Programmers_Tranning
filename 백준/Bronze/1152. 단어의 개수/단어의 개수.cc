#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);   // 한 줄 전체 입력 받기

    stringstream ss(s);
    string word;
    int count = 0;

    while (ss >> word) { // 공백 기준으로 단어 추출
        count++;
    }

    cout << count;
    return 0;
}