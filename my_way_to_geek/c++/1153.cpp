#include <iostream>
using namespace std;

int map[8][8];
int cnt = 0;
int visited[8][8];
int step[64];
int way[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}}; 
int way_cnt[8];

void ranking(){
	int temp;
	for (int i = 0; i < 8; i++){
		for (int j = i; j < 8; j++){
			if (way_cnt[j] <= way_cnt[i]){
				temp = way_cnt[j];
				way_cnt[j] = way_cnt[i];
				way_cnt[i] = temp;
				temp = way[j][0];
				way[j][0] = way[i][0];
				way[i][0] = temp;
				temp = way[j][1];
				way[j][1] = way[i][1];
				way[i][1] = temp;
			}
		}
	}
}

int range(int i, int j){
	if ((i >= 0 && i < 8) && (j >= 0 && j < 8) && visited[i][j] == 0)
		return 1;
	return 0;
}

void choose(int x, int y){
	for (int i = 0; i < 8; i++){
		if (range(way[i][0] + x, way[i][1] + y)){
			int tx = way[i][0] + x,ty = way[i][1] + y;
			for (int j = 0; j < 8; j++){
				if (range(way[j][0] + tx, way[j][1] + ty)){
					way_cnt[i] ++;
				}
			}
		}
	}
	ranking();
}


void move (int i, int j){
	int temp = i * 8 + j + 1;
	int tx = i, ty = j;
	step[cnt] = temp;
	cnt ++;
	visited[i][j] = 1;
	for (int k = 0; k < 8; k++){
		way_cnt[k] = 0;
	}
	choose(i, j);
	for (int i = 0; i < 8; i++){
		if (range(way[i][0] + tx, way[i][1] + ty)){
			move(tx + way[i][0], ty + way[i][1]);
		}
	}
	if (cnt != 64){
		visited[tx][ty] = 0;
		cnt --;
		return ;
	}
}

int main (){
	int n;
	int x, y;
	cin >> n;
	while (n != -1){
		for (int i = 0; i < 8; i++){
			if (n - (i + 1) * 8 <= 0){
				x = i;
				y = n - i * 8 - 1;
				break;
			}
		}
		move (x, y);
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				visited[i][j] = 0;
			}
		}
		cnt = 0;
		for (int i = 0;i < 64; i++){
			cout << step[i] << " ";
		}
		cout << endl;
		cin >> n;
	}
	return 0;
}
