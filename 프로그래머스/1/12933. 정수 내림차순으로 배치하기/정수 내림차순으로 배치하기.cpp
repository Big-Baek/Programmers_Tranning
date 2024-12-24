#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    string input = to_string(n);
    int size = input.size();

   
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (input[j] < input[j + 1]) { 
               
                char temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }

    return stoll(input); 
}
