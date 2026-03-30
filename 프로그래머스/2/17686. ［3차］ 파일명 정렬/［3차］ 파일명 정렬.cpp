#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
    string f_name = "";
    string s_name = "";
    int s_number = 0;
    string t_name = "";
    string origin = "";
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<Data> arr;

    for (string s : files)
    {
        Data data;
        data.origin = s;
        int index = 0;

        // HEAD
        while (index < s.size() && !isdigit(s[index])) {
            data.f_name += toupper(s[index]);
            index++;
        }

        // NUMBER (최대 5자리)
        int count = 0;
        while (index < s.size() && isdigit(s[index]) && count < 5) {
            data.s_name += s[index];
            index++;
            count++;
        }

        data.s_number = stoi(data.s_name);

        // TAIL
        while (index < s.size()) {
            data.t_name += s[index];
            index++;
        }

        arr.push_back(data);
    }

    stable_sort(arr.begin(), arr.end(), [](const Data& a, const Data& b)
    {
        if (a.f_name != b.f_name)
            return a.f_name < b.f_name;

        if (a.s_number != b.s_number)
            return a.s_number < b.s_number;

        return false;
    });

    for (Data dd : arr)
        answer.push_back(dd.origin);

    return answer;
}