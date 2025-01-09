#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;
    int small_num;
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i+1; j < nums.size() - 1; j++) {
            for (int k = j+1; k < nums.size(); k++) {
                sum = nums[i] + nums[j] + nums[k];
                small_num = 0;
                for (int z = 1; z <= sum;z++) {
                    if (sum % z == 0) {
                        small_num += 1;
                    }
                }
                if (small_num <= 2) {
                    answer += 1;
                }
            }
        }
    }







  

    return answer;
}