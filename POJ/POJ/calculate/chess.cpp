/****************************************************************************/
/*	 POJ读书笔记2.2 —— 棋盘上的距离	1657		皮皮 2014-7-2				*/
/****************************************************************************/
#include <stdio.h>
#include <math.h>
#define max(a,b) ( (a)>(b)? (a):(b) )	//最好
//#define max(a,b) a>b? a:b				//亦可

void chess(){
	int count;
	scanf("%d",&count);
	int abs_x,abs_y;
	char begin[3], end[3];

	while(count--){
		scanf("%s %s",begin,end);
		abs_x = abs(begin[0] - end[0]);
		abs_y = abs(begin[1] - end[1]);

		if( !abs_x && !abs_y )								//王 后 车 象
			printf("0 0 0 0\n");
		else{			
			printf("%d ",abs_x > abs_y? abs_x:abs_y );		//王
			//printf("%d ", max(abs_x , abs_y) );
			if( !(abs_x) || !(abs_y) || ((abs_x == abs_y)))	//后
				printf("1 ");
			else
				printf("2 ");

			if( !(abs_x) || !(abs_y) )						//车
				printf("1 ");
			else
				printf("2 ");

			if( (abs_x + abs_y) % 2)						//象
				printf("Inf\n");
			else if( (abs_x == abs_y) )
				printf("1\n");
			else
				printf("2\n");
		}
	}
}

int __354main(){
	chess();
	return 0;
}
