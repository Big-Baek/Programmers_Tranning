#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (char &c : s)
    {
        if (isupper(c))
        {
            c = tolower(c);
        }
        else
        {
            c = toupper(c);
        }
    }
    cout << s;

	return 0;
}