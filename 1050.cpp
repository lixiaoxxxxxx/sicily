#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
set<int> myset;
set<int>:: iterator p;


int main(){
	int N, goal;
	int temp[5];
	scanf("%d", &N);
	while (N--){
		for (int i = 0; i < 5; i++){
			scanf("%d", &temp[i]);
			myset.insert(temp[i]);
		}
		scanf("%d", &goal);
		for (p = myset.begin(); p != myset.end(); p++){
			cout << *p << endl;
		}
		if (myset.find(100) != myset.end()){
			cout << "in!" << endl;
		}
	}
	return 0;
}
