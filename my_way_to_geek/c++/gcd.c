#include <stdio.h>
int gcd(int a, int b){
	int temp;
	while (b > 0){
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main (){
	int x, i, j, s = 0, n, m;
	scanf("%d", &x);
	for (i = 1; i <= x; i++){
		s = 0;
		scanf("%d%d", &n, &m);
		for (j = 1; j <=n; j++){
			if (j < m){
				continue;
			}
			if (gcd(j, n) >= m){
				s++;
			}
		}
		printf("%d\n", s);
	}
	return 0;
}
