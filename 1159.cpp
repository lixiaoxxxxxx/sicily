#include <iostream>
using namespace std;
int main (){
	int n;
	while (cin >> n, n != EOF){
		int temp[100];
		int ans[100];
		for (int i = 0; i < 100; i++)
			ans[i] = 0;
		int len = 0;
		for (int i = 0; i < n; i++){
			char input[100];
			int carry = 0;
			cin >> input;
			if (strlen(input) > len)
				len = strlen(input);
			int k, c;
			for (k = 0; k < 100; k++)
				temp[k] = 0;
			for (k = strlen(input) - 1, c = 0; k >= 0; k--, c++)
				temp[c] = (int)input[k] - 48;
			for (k = 0; k < 100; k++){
				int t1 = ans[k];
				ans[k] = (carry + ans[k] + temp[k]) % 10;
				carry = (carry + t1 + temp[k]) / 10;
				if (carry && k + 1 > len)
					len = k + 1;
			}
		}
		int flag = 0;
		for (int i = 99; i >= 0; i --){
			if (ans[i] != 0)
				flag = 1;
			if (flag)
				cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
