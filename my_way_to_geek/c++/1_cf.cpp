#include <iostream>
using namespace std;
int main (){
	long long n,m,a;
	cin >> n >> m >> a;
	long long  temp = a;
	long long  x = 1,y = 1;
	while (temp < n){
		x++;
		temp += a;
	}
	temp = a;
	while (temp < m){
		y++;
		temp += a;
	}
	cout << x * y << endl;
}

