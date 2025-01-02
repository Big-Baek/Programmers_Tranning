#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
   

    for (int i = 1; i < food.size(); i++) {
        for (int j = 0; j < food[i] / 2; j++) {
            string number = to_string(i); //문자열 정수 i
            answer.append(number); //2로 나눈값만큼 반복해서 추가
        }
    }
    answer.append("0");
    //뒤를 붙이는 방법은 2개.
    //앞을 붙인 로직을 복붙하기 or 만들어진 앞에걸 반대로 붙이기


    for (int i = food.size()-1; i > 0; i--) {
        for (int j = 0; j < food[i] / 2; j++) {
            string number = to_string(i); //문자열 정수 i
            answer.append(number); //2로 나눈값만큼 반복해서 추가
        }
    }


    return answer;
}