#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    int size = num_list.size();
    
    for(int i =0; i< size; i++)
    {
        answer.push_back(num_list[size-1-i]);
    }
    
    
    return answer;
}