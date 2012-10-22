#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
int k;
int cur = 0;
bool found = false;
int len = 0;
string temp;
string strstate = "12345678";
string goal = "12345678";
string ans;
map<string, string>:: iterator p;
map<string, string> mymap;
string poss[50000];
string path[50000];

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


bool inmap(const string& key){
	return (mymap.find(key) != mymap.end());
}

void bfs(){
	while (cur != len + 1){
		temp = poss[cur];
		strstate = temp;
		A();
		if(!inmap(strstate)){
			len++;
			poss[len] = strstate;
			path[len] = path[cur] + "A";
			mymap.insert(pair<string, string>(strstate, path[len]));
		}
		strstate = temp;
		B();
		if(!inmap(strstate)){
			len++;
			poss[len] = strstate;
			path[len] = path[cur] + "B";
			mymap.insert(pair<string, string>(strstate, path[len]));
		}
		strstate = temp;
		C();
		if(!inmap(strstate)){
			len++;
			poss[len] = strstate;
			path[len] = path[cur] + "C";
			mymap.insert(pair<string, string>(strstate, path[len]));
		}
		cur++;
	}
}

int main (){
	char tchar;
	poss[0] = strstate;
	path[0] = "";
	mymap.insert(pair<string, string>(strstate, ""));
	bfs();
	while (cin >> k, k != -1){
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
		p = mymap.find(goal);
		if (p == mymap.end() || p->second.length() > k)
			cout << "-1" << endl;
		else
			cout << p->second.length() << " " << p->second << endl;

	}
	return 0;
}
