#include <iostream>
using namespace std;

struct node {
	node *next;
	int data;
};

class linker{
	private:
	node *head;
	int len;
	public:
	linker(){
		head = new node;
		head->next = NULL;
		head->data = 0;
		len = 0;
		cout << "len is " << len << endl;
	}
	~linker(){
	}
	void insert(int data){
		node *p = new node;
		p->next = head->next;
		p->data = data;
		head->next = p;
		cout << "insert! " << endl;
	}
	void show(){
		node *p = new node;
		p = head->next;
		while (p->next != NULL){
			cout << p->data << endl;
			p = p->next;
		}
		cout << p->next << endl;
	}
};

int main (){
	linker a;
	for (int i = 0;i <= 10; i++){
		int x;
		cin >> x;
		a.insert(x);
	}
	a.show();
	return 0;
}
	
