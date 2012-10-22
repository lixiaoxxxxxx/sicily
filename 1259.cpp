#include <iostream>
#include <math.h>
using namespace std;

bool prime[2000000];
void eratosthenes(){
	prime[0] = true;
	prime[1] = true;
	for (int i = 2;i <= sqrt(2000000);i++){
		if (!prime[i]){
			for (int k = (2000000 - 1)/i,j = i * k;k >= i;k--,j-=i){
				if (!prime[k]){
					prime[j] = true;
				}
			}
		}
	}
}

int main (){
	int a;
	eratosthenes();
	cin >> a;
	x:int flag = 2,mark = 0,temp;
	int sum = 0,counter = 0;
	while (flag <= a){
	  for (int i = flag; i <= a;i++){
		  if (i == a){
			  if (!prime[i]){
				  counter ++;
				  flag = a + 1;
				  break;
			  }
			  flag = a + 1;
			  break;
		  }
		  if (!prime[i]){
			  if (flag >= a/2){
				  i = a - 1;
				  continue;
			  }
			  mark ++;
			  if (mark == 2){
				  temp = i;
			  }
			  sum = sum + i;
			  if (sum < a){
				  continue;
			  }
			  if (sum > a){
				  sum = 0;
				  flag = temp;
				  mark = 0;
				  break;
			  }
			  if (sum == a){
				  counter ++;
				  flag = temp;
				  mark = 0;
				  sum = 0;
				  break;
			  }
		  }
	  }
  }
  cout << counter << endl;
  cin >> a;
  while (a != 0){
	  goto x;
  }
  return 0;
}
