#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int a;
    int b;
    cin >> a >> b;

    string sa = to_string(a);
    string sb = to_string(b);
    stack<int> sst;
    for (char c : sb)
    {
        int a1 = a * (c - '0');
        sst.push(a1);
    }
    while (!sst.empty())
    {
        cout << sst.top() << endl;
        sst.pop();
    }

    cout << a * b;


	return 0;
}