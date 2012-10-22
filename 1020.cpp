#include <iostream>
#include <string.h>
using namespace std;

int solve(int a[], int n, int len){
	int remainder;
	int left = 0;
	for (int i = 0; i < len; i++){
		remainder = left * 10 + a[i];
		if (remainder >= n){
			left = remainder % n;
		}
		else{
			left = remainder;
		}
	}
	return left;
}

int main (){
	int k;
	int length;
	int div[100];
	int digis[400];
	cin >> k;
	for (int i = 0; i < k; i++){
		char input[400];
		cin >> length;
		for (int j = 0; j < length; j++){
			cin >> div[j];
		}
		cin >> input;
		for (int j = 0; j < strlen(input); j++){
			digis[j] = (int)input[j] - 48;
		}
		cout << "(";
		for (int j = 0; j < length; j++){
			cout << solve(digis, div[j], strlen(input));
			if (j != length - 1)
				cout << ",";
		}
		cout << ")" << endl;
	}
	return 0;
}
