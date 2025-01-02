#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool find(vector<int> input, int ff) {
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ff) {
            return true;
        }
    }
    return false;
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size()-1; i++) {
        for (int j = i; j < numbers.size()-1; j++) {
            int se = numbers[i] + numbers[j + 1];
            if (find(answer, se) == true) {}
               
    
            else {
                answer.push_back(se);
            }
        }
    }
         sort(answer.begin(), answer.end());
    return answer;
}
int main() {

    vector<int>ss = { 2,1,3,4,1 };
    solution(ss);


    return 0;
}