#include <iostream>
#include <string>

using namespace std;
struct ans{
	string mainid;
	string majia;
};
int com(struct ans a, struct ans b){
	return a.mainid < b.mainid;
}

int main (){
	string name;
	string names[100];
	string ip;
	string ips[100];
	ans answer[100];
	string temp;
	int count = 0;
	int k;
	int c = 0;
	cin >> k;
	while (k != 0){
		for (int i = 0; i < k ; i++){
			cin >> name;
			cin >> ip;
			if (c == 0){
				ips[0] = ip;
				names[0] = name;
				c++;
			}
			else{
				int flag = 0;
				for (int j = 0; j < c; j++){
					if (ips[j].compare(ip) == 0){
						flag = 1;
						temp = names[j];
					}
				}
				if (flag == 0){
					ips[c] = ip;
					names[c] = name;
					c++;
				}
				else{
					answer[count].mainid = temp;
					answer[count].majia = name;
					count ++;
				}
			}
		}
		sort(answer, answer + count, com);
		for (int i = 0; i < count; i++){
			cout << answer[i].majia << " is the MaJia of " << answer[i].mainid << endl;
		}
		cout << endl;
		cin >> k;
		c = 0;
		count = 0;
	}
	return 0;
}
