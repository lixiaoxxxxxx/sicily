#include <iostream>
using namespace std;

int a[102][102],dp[102][102];

int max (int x, int y){
	if (x > y){
		return x;
	}
	return y;
}

int main (){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++){:
		for (int j = 1;j <= i;j++){
			cin >> a[i][j];
		}
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= i;j++){
			dp[i][j] = max(dp[i - 1][j - 1] + a[i][j],dp[i - 1][j] + a[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n;i++){
		if (dp[n][i] > ans){
			ans = dp[n][i];
		}
	}
	cout << ans << endl;
	return 0;
}





