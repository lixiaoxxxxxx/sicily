#include <iostream>
#include <math.h>
using namespace std;
int t;
int m,n,d;
bool done = false;
int visited[1010];
int path[1010];
bool prime[2000000];
void eratosthenes(){
	prime[0] = true;
	prime[1] = true;
	for (int i = 2;i <= sqrt(2000000);i++){
		if (!prime[i]){
			for (int k = (2000000 - 1)/i,j = i * k;k >= i;k--,j-=i){
				if (!prime[k]){
					prime[j] = true;
				}
			}
		}
	}
}
bool check(int len)  
{  
	int sum;  
	if(len <= 1) return true;  
	for(int i = 0;i < len;++i)  
	{  
		sum = 0;  
		if(i <= len - d)  
		{  
			for(int j = i;j - i + 1<= d ;++j)  
			{  
				sum += path[j];  
				if(j-i+1 > 1 && prime[sum] == false)    return false;  
			}  
		}  
		else  
		{  
			for(int j = i;j < len;++j)  
			{  
				sum += path[j];  
				if(j-i+1 > 1 && prime[sum] == false)    return false;  
			}  
		}  
	}  
	return true;  
}
void print(){
	cout << path[0];
	for (int i = 1;i < m - n + 1;i++){
		cout << "," << path[i];
	}
	cout << endl;
}


void dfs(int now){
	t++;
	if (t > 4000){
		return;
	}
	if (done){
		return;
	}
	if (check(now) == false){
		return;
	}
	if (now == m - n + 1){
		done = true;
		return;
	}
	for (int i = n;i <= m && done == false;i++){
		if (visited[i] == 1){
			continue;
		}
		path[now] = i;
		visited[i] = 1;
		dfs(now + 1);
		visited[i] = 0;
	}
	return;
}


int main (){
	eratosthenes();
	cin >> n >> m >> d;
	while (n != 0 || m != 0 || d != 0){
		t = 0;
		memset(visited,0,sizeof(visited));
		dfs(0);
		if (done){
			print();
		}
		else {
			cout << "No anti-prime sequence exists." << endl;
		}
		done = false;
		cin >> n >> m >> d;
	}
	return 0;
}
