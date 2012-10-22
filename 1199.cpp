#include <iostream>
#include <memory.h>
using namespace std;
int t, n, m, x;
int sum = 0;
int ok[10000000];
int cnt = 0;


int gcd(int a, int b){
	return (b > 0) ? gcd(b, a % b) : a; 
}

void record(int x){
	ok[cnt] = x;
	cnt ++;
}

int checked(int x){
	for (int i = 0; i < cnt; i++){
		if (x % ok[i] == 0){
			return 1;
		}
	}
	return 0;
}

int main (){
	cin >> t;
	for (int j = 0; j < t; j++){
		cin >> n >> m;
		for (int i = m; i <= n; i++){
			if (checked(i)){
				sum ++;
			}
			else{
				if (gcd(i, n) >= m){
					sum ++;
					record(i);
				}
			}
		}
		cout << sum << endl;
		sum = 0;
		cnt = 0;
	}
	return 0;
}

