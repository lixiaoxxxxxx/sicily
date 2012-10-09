#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main (){
	int k;
	int i;
	char temp[1000];
	int cnt = 0;
	scanf("%d", &k);
	while (k--){
		scanf("%s", temp);
		char t1 = temp[0];
		for (i = 0; i < strlen(temp); i++){
			if (t1 == temp[i]){
				cnt++;
				if (i == strlen(temp) - 1)
					printf("%d%c", cnt, t1);
			}
			else{
				printf("%d%c", cnt, t1);
				t1 = temp[i];
				cnt = 1;
				if (i == strlen(temp) - 1)
					printf("%d%c", cnt, t1);
			}
		}
		printf("\n");
		cnt = 0;
	}
	return 0;
}
				
