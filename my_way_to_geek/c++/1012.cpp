#include <iostream>
#include <memory.h>
using namespace std;
int main (){
	int in;
	int circle[50];
	memset(circle,0,sizeof(circle));
	cin >> in;
	while (in){
		int count = 0;
		int step_count = 0;
		int test = 30;
		for (int i = 0;i <= in * 2;i++){
			if (i == in * 2){
				i = 0;
			}
			if (circle[i]){
				continue;
			}
			if (!circle[i]){
				step_count ++;
			}
			if (step_count == test){
				/*if (i < in){
					memset(circle,0,sizeof(circle));
					count = 0;
					step_count = 0;
					test++;
					while (test % (2 * in) > 0 && test % (2 * in) <= in){
						test++;
					}
					goto x;
				}*/
				cout << i + 1 << endl;
				count ++;
				circle[i] = 1;
				step_count = 0;
			}
			
			if (count == in * 2){
				cout << test << endl;
				break;
			}
		}
		cin >> in;
		memset(circle,0,sizeof(circle));
	}
	return 0;
}


