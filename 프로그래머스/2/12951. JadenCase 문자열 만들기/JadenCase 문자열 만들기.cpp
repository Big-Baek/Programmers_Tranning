#include <string>
#include <vector>

using namespace std;

string solution(string s) {

	for (int i = 0; i < s.size(); i++)
	{

		if (i == 0 && isalpha(s[i]))
		{

			s[i] = toupper(s[i]);

		}
		else if (s[i] == ' ' && s[i + 1] != ' ' && isalpha(s[i + 1]))
		{



			s[i + 1] = toupper(s[i + 1]);

			i++;

		}
		else
		{
			if (isalpha(s[i]))
			{
				s[i] = tolower(s[i]);
			}
		}

	}





	return s;
}