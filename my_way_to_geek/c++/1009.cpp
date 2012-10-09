#include <iostream>
using namespace std;
int n;
int s = 0;
int a[2000];
int main (){
	while (1){
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++){
			s = s + a[i] * (i + 1);
		}
		cout << s << endl;
		s = 0;
	}
	return 0;
}
				

