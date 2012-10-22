#include <iostream>
#include <map>
using namespace std;
struct node{
	int n;
	int count;
	void add(){
		count++;
	}
	node (int num){
		n = num;
		count = 1;
	}
};

/*
   int comp(struct node a, struct node b){
   return a.n < b.n;
   }
   */

int main (){
	int k;
	int s1, s2;
	int temp;
	map<int, node>:: iterator p;
	map<int, node> map1;
	while (cin >> k, k != EOF){
		while (k --){
			cin >> temp;
			s1 = map1.size();
			map1.insert(pair<int, node>(temp, node(temp)));
			s2 = map1.size();
			if (s1 == s2){
				p = map1.find(temp);
				p->second.add();
			}
		}
		for (p = map1.begin(); p != map1.end(); p++){
			cout << p->first << " " << p->second.count << endl;
		}
		map1.clear();
		cout << endl;
	}
	return 0;
}

