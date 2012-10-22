/*
 * here we aim at finding the opposite board
 *			 
 *	*		*		*		*
 *	*		**		****	***
 *	*		 *		   *	  *
 *
 */

#include <iostream>
using namespace std;

char state[10][10];

void check1check(int i, int j){
	int ti, tj;
	int flag;
	for (int k = i - 3; k <= i + 3; k++){
		if (state[k][j + 2] == 'r'){
			int a = min(i, k);
			int b = max(i, k);
			for (int l = a; l <= b; l++){
				if (state[

bool solve(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (state[i][j] == 'r')
				check1check(i, j);
			else
				cout << ' ';
		}
		cout << endl;
	}
}

int main (){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cin >> state[i][j];
		}
	}
	solve();
	return 0;
}
