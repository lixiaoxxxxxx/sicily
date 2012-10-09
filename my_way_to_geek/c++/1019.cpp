#include <iostream>
using namespace std;

int k, n;
int a[101][101];
int weight[101];
int step;
int sum;
int path[201];

void solve(int x){
	cout << "we are in: " << x << endl;
	path[step] = x;
	sum = sum + weight[x];
	for (int i = 1; i <= 100; i++){
		if (a[x][i] == 1){
			step ++;
			if (step <= k){
				solve(i);
			}
			else {
				cout << "sum " << sum << endl;
				step --;
				a[x][i] = 0;
				a[i][x] = 0;
			}

		}
	}
}


int main (){
	int ta, tb;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> weight[i];
	}
	for (int i = 0; i < n - 1; i++){
		cin >> ta >> tb;
		a[ta][tb] = 1;
		a[tb][ta] = 1;
	}
	solve(1);
	return 0;
}

