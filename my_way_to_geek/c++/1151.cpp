#include <iostream>
using namespace std;
int k;
int state[8];
int goal[8];
char ans[10];
int len = 0;
char last;
bool found = false;

void game_init(){
	for (int i = 0; i < 8; i++)
		state[i] = i + 1;
}

void C(){
	int temp[8];
	for (int i = 0; i < 8; i++)
		temp[i] = state[i];
	state[1] = temp[6];
	state[2] = temp[1];
	state[5] = temp[2];
	state[6] = temp[5];
}

void B(){
	int temp[8];
	for (int i = 0; i < 8; i++)
		temp[i] = state[i];
	state[0] = temp[3];
	state[1] = temp[0];
	state[2] = temp[1];
	state[3] = temp[2];
	state[4] = temp[5];
	state[5] = temp[6];
	state[6] = temp[7];
	state[7] = temp[4];
}

void A(){
	int temp[8];
	for (int i = 0; i < 8; i++)
		temp[i] = state[i];
	for (int i = 0; i < 8; i++)
		state[i] = temp[8 - i - 1];
}

bool check(){
	for (int i = 0; i < 8; i++){
		if (state[i] != goal[i])
			return false;
	}
	return true;
}

void bfs

int main (){
	while (cin >> k, k != -1){
		for (int i = 0; i < 8; i++){
			if (i < 4)
				cin >> goal[i];
			else
				cin >> goal[11 - i];
		}
		game_init();
	}
	return 0;
}
