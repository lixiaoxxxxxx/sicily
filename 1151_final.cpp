#include <map>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
int k;
string temp;
string strstate, goal = "12345678";
map<string, string> mymap;

void C(){
	temp = strstate;
	strstate[1] = temp[6];
	strstate[2] = temp[1];
	strstate[5] = temp[2];
	strstate[6] = temp[5];
}

void B(){
	temp = strstate;
	strstate[0] = temp[3];
	strstate[1] = temp[0];
	strstate[2] = temp[1];
	strstate[3] = temp[2];
	strstate[4] = temp[5];
	strstate[5] = temp[6];
	strstate[6] = temp[7];
	strstate[7] = temp[4];
}

void A(){
	temp = strstate;
	for (int i = 0; i < 8; i++)
		strstate[i] = temp[8 - i - 1];
}

int main (){
	mymap[goal].clear();
	queue<string> q;
	q.push(goal);
	while (!q.empty()){
		strstate = q.front();
		temp = strstate;
		A();
		if (mymap.find(strstate) == mymap.end()){
			mymap[strstate] = mymap[temp] + 'A';
			q.push(strstate);
		}
		strstate = temp;
		B();
		if (mymap.find(strstate) == mymap.end()){
			mymap[strstate] = mymap[temp] + 'B';
			q.push(strstate);
		}
		strstate = temp;
		C();
		if (mymap.find(strstate) == mymap.end()){
			mymap[strstate] = mymap[temp] + 'C';
			q.push(strstate);
		}
		strstate = temp;
		q.pop();
	}
	char tchar;
	while (scanf("%d", &k) && k != -1){
		for (int i = 0; i < 8; i++){
			if (i < 4){
				cin >> tchar;
				goal[i] = tchar;
			}
			else{
				cin >> tchar;
				goal[11 - i] = tchar;
			}
		}
		if (mymap.find(goal) == mymap.end() || mymap[goal].size() > k)
			printf("-1\n");
		else
			printf("%d %s\n", mymap[goal].size(), mymap[goal].c_str());
	}
	return 0;
}
