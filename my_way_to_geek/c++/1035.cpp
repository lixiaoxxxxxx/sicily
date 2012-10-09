#include <iostream>
using namespace std;

int solve(string a, string b){
	if (a.length() != b.length())
		return 0;
	else{
		for (int i = 0; i < a.length(); i++){
			if(a[i] == 'A' && b[i] != 'T')
				return 0;
			if(a[i] == 'T' && b[i] != 'A')
				return 0;
			if(a[i] == 'G' && b[i] != 'C')
				return 0;
			if(a[i] == 'C' && b[i] != 'G')
				return 0;
		}
		return 1;
	}
}
			

int main (){
	int k;
	cin >> k;
	for (int j = 0; j < k; j++){
		int n;
		int ans = 0;
		int c = 0;
		string temp;
		string input[100];
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> temp;
			if (c == 0){
				input[c] = temp; 
				c++;
			}
			else{
				int flag = 0;
				for (int l = 0; l < c; l++){
					if (solve(temp, input[l]) == 1){
						flag = 1;
						input[l] = "none";
						ans++;
						break;
					}
				}
				if (!flag){
					input[c] = temp;
					c++;
				}
			}
		}
		cout << ans << endl;
	}
	return 9;
}

