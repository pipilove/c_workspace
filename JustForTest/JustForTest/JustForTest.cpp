#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int k = 0;
char * s="3";

class a{
public:
	void compute(){
		int64_t value = atoi(s);
		if(value >=k)
			printf("good good good!!!");
		system("pause");
	}
};

void main(){
	a a1;
	a1.compute();
}
