/*#include <iostream>
#include <cstring>

using namespace std;

bool IsWhile(const char* s, int i)
{
	cout << "hello IsWhile" << endl;
	return s[i] == 'w' &&
		s[i + 1] == 'h' &&
		s[i + 2] == 'i' &&
		s[i + 3] == 'l' &&
		s[i + 4] == 'e';
}

int Count(const char* s)
{
	int k = 0;
	cout << "hello Count" << endl;
	for (int i = 0; s[i + 1] != 0; i++)
		if (IsWhile(s,i))
		{
			k++;
			i += 4;
			//s[2] = 'q';
		}
	cout << "k=" << k << endl;
	return k;
}

char* Change(char* s)
{
	char s2[101];
	int m;
	int i=0;
	cout << "hello Change " << s <<  endl;
	
	
	
	
	for (i = 0; s[i] != 0; i++)
	{
		if (IsWhile(s, i))
		{


			cout << "i=" << i << endl;


			if (i > 0)
			{
				for (m = 0; m < i; m++)
				{
					s2[m] = s[m];
				}
				//strcpy_s(s2, i, s);
			}
			s2[i] = '*';
			s2[i + 1] = '*';
			s2[i + 2] = '*';
			for (m = i + 3; s[m + 2] != 0; m++)
			{
				s2[m] = s[m + 2];
			}
			s2[m] = '\0';

			for (m = 0; s2[m] != 0; m++)
			{
				s[m] = s2[m];
			}
			s[m] = '\0';
			//strcpy_s(s, m, s2);
		}
	}
	return s;
}

int main()
{
	char s[101];

	//s = "ffffff";

	cout << "Enter string:" << endl;
	cin.getline(s, 100);

	//cout << "Groups of 'while': " << Count(s) << endl;
	cout << s << s << s << endl;

	cout << "Modified string:  " << Change(s) << endl;
}*/