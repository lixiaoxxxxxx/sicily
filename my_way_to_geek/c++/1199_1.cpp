/*
 * euler function
 */

#include <iostream>
#include <math.h>
using namespace std;

int euler(int n){
	int r = n;
	for (int i = 2; i * i <= n; i++){
		if (n % i == 0){
			while (n % i == 0)
				n = n / i;
			r = r / i * (i - 1);
		}
	}
	if (n != 1)
		r = r / n * (n - 1);
	return r;
}

int t, n, m, fac[10000000];

int main (){
	cin >> t;
	while (t--){
		cin >> n >> m;
		if (n < m)
			cout << "0" << endl;
		else if(n == m)
			cout << "1" << endl;
		else if (m <= 1)
			cout << n << endl;
		else{
			int tot = 0; 
			for (int i = 2; i * i <= n; i++){
				if (n % i == 0){
					if (i >= m)
						fac[tot++] = i;
					if (n / i >= m && i != floor(sqrt(double(n)) + 0.5))
						fac[tot++] = n / i;
				}
			}
			int s = 1;
			for (int i = 0; i < tot; i++)
				s = s + euler(n / fac[i]);
			cout << s << endl;
		}
	}
	return 0;
}
