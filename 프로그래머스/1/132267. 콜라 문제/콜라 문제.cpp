#include <string>
#include <vector>
int solution(int a, int b, int n) {
    int sum = 0; //받은 콜라 누적
    int when = 0; //그때그떄
    while (n >= a) {


        sum += (n / a) * b; //콜라 받은양
        when = (n / a) * b;
        n -= (n / a) * a; //정수형이기에 나머지가 없어서 가능한 연산
        n += when; //받은거 또 쳐마실거니까 더하고
    }
      
    return sum;
}