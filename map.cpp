#include <iostream>
#include <map>
using namespace std;
map<string, char>:: iterator p;
map<string, char> map1;

bool inmap (const string& key){
	return (map1.find(key) != map1.end());
}
int main (){
	string a;
	cin >> a;
	map1.insert(pair<string, char>(a, 'a'));
	cout << map1.find(a)->second << endl;
	if (inmap("fgg")){
		cout << "found!" << endl;
	}
	cout << map1.size();
	for (p = map1.begin(); p != map1.end(); p++)
		cout << p->first << endl;
	return 0;
}
