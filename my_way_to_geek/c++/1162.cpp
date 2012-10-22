#include <iostream>
#include <stdio.h>
using namespace std;
int depth;
int sudoku[9][9];

bool rowcheck(int row){
	int check[9];
	for (int i = 0; i < 9; i++){
		check[sudoku[row][i] - 1] = 1;
	}
	for (int i = 0; i < 9; i++)
		if (check[i] == 0)
			return false;
	return true;
}

bool colcheck(int col){
	int check[9];
	for (int i = 0; i < 9; i++){
		check[sudoku[i][col] - 1] = 1;
	}
	for (int i = 0; i < 9; i++)
		if (check[i] == 0)
			return false;
	return true;
}

bool blockscheck(int row, int col){


void dfs(){


int main(){
	int row[9][9];
	int col[9][9];
	int k;
	char tempchar;
	cin >> k;
	while (k--){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				cin >> tempchar;
				sudoku[i][j] = tempchar - '0';
			}
		}
	}
	return 0;
}
