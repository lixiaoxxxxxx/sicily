#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int sudoku[9][9];
	int k;
	char tempchar;
	cin >> k;
	while (k--){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				cin >> tempchar;
				sudoku[i][j] = tempchar - '0';
				cout << sudoku[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
