#include <iostream>
using namespace std;
int circle[1000000];
int k;
bool test(int key){
	int temp = key % (2 * k);
	if (temp > 0 && temp <= k){
		test(key + k - temp + 1);
	}
	
int main (){
	cin >> k;
	while (k){

