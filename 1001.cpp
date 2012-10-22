#include <iostream>
#include <string>
#define MAX 100000
using namespace std;

int main()
{
	string num;
	long long a[MAX];
	int size;
	int n;
	while (cin >> num && num != "0")
	{
		size = num.length();
		a[0] = 1;
		a[1] = 1;

		if (size == 1)
		{
			cout << "1" << endl;
			continue;
		}

		//对第二位处理    
		n = (num[0]-'0')*10 + num[1]- '0';
		if (n <= 26 && num[1] != '0')
			a[1] = 2;

		for (int i = 2; i < size; i++)
		{
			if (num[i] == '0')
				a[i] = a[i-2];
			else
			{
				a[i] = a[i-1];
				n = (num[i-1]-'0')*10 + num[i]-'0';

				if (n <= 26 && num[i-1] != '0')
					a[i] += a[i-2];
			}

		}
		cout << a[size-1] << endl;
	}

	return 0;
}
