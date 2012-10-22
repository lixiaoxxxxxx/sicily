 #include<iostream>
#include<cmath>
using namespace std;
int p[10] = {11,23,29,37,41,43,47,53,59};    
int main(){
	int k;
	long long n,m,fac[10];
	cin >> k;
	for(int i = 0;i <= 8 && p[i] <= k; ++i){
		n = (long long)pow(2.0, p[i]) - 1;
		m = n;
		int flag = 0,r = 0;
		long long j = 2;
		while(j * j <= n){
			if(n % j != 0)
				j++;
			else{
				flag = 1; 
				n /= j;
				fac[r++] = j;
			}   
		}
		if(flag){
			fac[r++] = n;
			cout << fac[0];
			for(int k = 1; k < r; ++k)
				cout << " * " << fac[k];
			cout << " = " << m << " = ( 2 ^ " << p[i] << " ) - 1\n";
		}
	}
	return 0;
}
