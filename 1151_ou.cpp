#include <iostream>
#include <map>
#include <math.h>

#define MAX 100000
using namespace std;

long target;
int step;

char op[MAX];
long queue[MAX];
int begin, end;
map<long, int>nodes;
char result[MAX];

bool check_end(long sum)
{
	if(sum == target)
	{
		/* cout << "check_end " << sum << endl; */
		return true; 
	}
	return false;
}

void check_visited(long sum, int pre,char op1)
{
	if(nodes.count(sum) != 0)
		;
	else
	{

		nodes.insert(pair<long,int>(sum,pre));
		/* cout <<"pre: " << pre << endl; */
		queue[end]= sum;
		/* cout <<"op: " <<op1<<endl; */
		op[end++] = op1; 
	}

}
long OPA(long temp_sum)
{
	long x = temp_sum/10000;
	long y = temp_sum%10000;
	return y*10000+x;
}


long OPB(long temp_sum)
{
	long x = temp_sum/10000;
	long y = temp_sum%10000;
	int a = x/1000;
	int b = (x-a*1000)/100;
	int c = (x-a*1000-b*100)/10;
	int d = (x-a*1000-b*100-c*10);
	x = d*1000+a*100+b*10+c;

	a = y/1000;
	b = (y-a*1000)/100;
	c = (y-a*1000-b*100)/10;
	d = (y-a*1000-b*100-c*10);
	y = d*1000+a*100+b*10+c;
	return x*10000+y;
}

long OPC(long temp_sum)
{
	long x = temp_sum/10000;
	long y = temp_sum%10000;
	int a = x/1000;
	int b = (x-a*1000)/100;
	int c = (x-a*1000-b*100)/10;
	int d = (x-a*1000-b*100-c*10);

	int e = y/1000;
	int f = (y-e*1000)/100;
	int g = (y-e*1000-f*100)/10;
	int h = (y-e*1000-f*100-g*10);

	x = a*1000+f*100+b*10+d;
	y = e*1000+g*100+c*10+h;


	return x*10000+y;
}
void print_result(long sum)
{
	// for(int i = 0; i < end; i++)
	//  cout << op[i];
	// cout << endl;
	int n = 0;
	while(nodes[sum] != -1)
	{
		int index = nodes[sum];
		result[n++] = op[index+1];
		sum = queue[index];
		// 
		//      cout <<"index: " << index << endl;
		//      cout <<"op[index] " << op[index] << endl;
		//      cout <<"sum" << sum << endl;
		//      cout <<"***************" << endl;
		//      
	}
	if(n > step)
		cout << -1 << endl;
	else
	{
		cout << n <<" ";
		for(int i = n-1; i>=0; i--)
			cout <<result[i];
		cout << endl;
	}
}

void bfs(long sum)
{
	begin = 0, end = 0;
	nodes.insert(pair<long,int>(sum, -1));
	queue[end++] = sum;
	while(begin <= end)
	{
		long temp_sum = queue[begin++];
		long temp; 

		temp = OPA(temp_sum);
		check_visited(temp, begin-1,'A');
		if(check_end(temp))
		{
			print_result(temp);
			break;
		}

		temp = OPB(temp_sum);
		check_visited(temp, begin-1,'B');
		if(check_end(temp))
		{
			print_result(temp);
			break;
		}

		temp = OPC(temp_sum);
		check_visited(temp, begin-1,'C');
		if(check_end(temp))
		{
			print_result(temp);
			break;
		}
	}

}

int main()
{
	int x = 1234;
	int y = 8765;
	while(cin >> step && step != -1)
	{
		nodes.clear();
		target = 0;
		int temp[8];
		for(int i = 0; i < 8; i++)
		{
			cin >> temp[i];
			target+=temp[i]*pow(10,7-i);
		}
		bfs(12348765);
	}
}  
