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

void dfs(int depth){
	if (found == true)
		return;
	int temp = depth;
	int tstate[8];
	for (int i = 0; i < 8; i++)
		tstate[i] = state[i];
	//cout << "current state :" << endl;
	if (check()){
		found = true;
		len = temp;
		return;
	}
	else{
		while (temp < k && found == false){
			temp++;
			A();
			ans[temp - 1] = 'A';
			//cout << "A depth " << temp << endl;
			dfs(temp);
			for (int i = 0; i < 8; i++)
				state[i] = tstate[i];
			if (found)
				return;
			B();
			ans[temp - 1] = 'B';
			//cout << "B depth " << temp << endl;
			dfs(temp);
			for (int i = 0; i < 8; i++)
				state[i] = tstate[i];
			if (found)
				return;
			C();
			ans[temp - 1] = 'C';
			//cout << "C depth " << temp << endl;
			dfs(temp);
			for (int i = 0; i < 8; i++)
				state[i] = tstate[i];
			return;
		}
		/*	temp = depth;
			for (int i = 0; i < 8; i++)
			state[i] = tstate[i];
			*/
		return;
	}
}


int main (){
	while (cin >> k, k != -1){
		for (int i = 0; i < 8; i++){
			if (i < 4)
				cin >> goal[i];
			else
				cin >> goal[11 - i];
		}
		game_init();
		dfs(0);
		if (!found){
			cout << "-1" << endl;
			for (int i = 0; i < 8; i++)
				ans[i] = 'D';
			found = false;
			len = 0;
		}
		else{
			int step = len;
			for (int i = 0; i < len; i++){
				if (ans[i] == 'A' && ans[i + 1] == 'A'){
					step = step - 2;
					i++;
					continue;
				}
			}
			cout << step << " ";
			for (int i = 0; i < len; i++){
				if (ans[i] == 'A' && ans[i + 1] == 'A'){
					i++;
					continue;
				}
				cout << ans[i];
			}
			cout << endl;
			for (int i = 0; i < 8; i++)
				ans[i] = 'D';
			found = false;
			len = 0;
		}
	}
	return 0;
}
