#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<char> arr;
    unordered_map<char, int> mymap;

    for (char c : X)
    {
        mymap[c]++;
    }
    for (char c : Y)
    {
        if (mymap[c] <= 0 )continue;

            arr.push_back(c);
            mymap[c]--;
    }

    sort(arr.begin(), arr.end(), greater<char>());

    for (char c : arr)
    {
        answer += c;
    }

    if (arr.empty()) return "-1";
    if (answer[0] == '0') return "0";
    return answer;
}