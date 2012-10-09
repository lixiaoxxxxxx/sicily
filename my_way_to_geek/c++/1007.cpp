#include <iostream>
using namespace std;
int main (){
	int k;
	while (cin >> k, k != 0){
		char input[200];
		cin >> input;
		int c = 0;
		int c1 = c;
		int c2 = 0;
		int loop = 0;
		while (c < k){
			while (c1 < strlen(input)){
				if (c2 != 1){
					c2++;
					cout << input[c1];
					c1 = c1 + (2 * k - (2 * loop + 1));
				}
				else{
					c2 = 0;
					cout << input[c1];
					c1 = c1 + (2 * loop + 1);
				}
			}
			c++;
			loop++;
			c1 = c;
			c2 = 0;
		}
		cout << endl;
	}
	return 0;
}
