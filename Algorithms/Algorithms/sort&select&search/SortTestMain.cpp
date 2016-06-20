//*	���������main����	*/
const int LEN  = 50;	//����Ҫ���������Ĵ�С
const int LOWER= 1;	//����Ҫ������������Сֵ
const int UPPER= 10000;	//����Ҫ�������������ֵ

#include "mySortDefine.h"
#include "InsertionSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "CountingSort.h"
#include "RadixSort.h"
#include "RandomizedSelect.h"

void showDatagenerateMode();
void showSortMode();
int dataGenerate(int* A);
short sortData(int* A,int* B,int A_length);
void saveAndPrint(int* A,int* B,int A_length,short sortDataSelectFlag);

int __151514main(){
	int A[LEN],B[LEN];

	int A_length = dataGenerate(A);	//������������ĳ���
	system("cls");
	short sortDataSelectFlag = sortData(A,B,A_length);	//���ر�־�ж�ѡ���ΪconntingSort����randomizedSelect��������
	if(sortDataSelectFlag != 2)saveAndPrint(A,B,A_length,sortDataSelectFlag);
	return 0;
}

void showDatagenerateMode(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);	//system("color 2");system("color F");
	printf("please input the Generation methods that the array need to sort:\n\n");
	printf("1 Randomly generate and save into file in.txt\n");
	printf("2 use the privious data in file in.txt that generate randomly\n");
	printf("3 manually generate and save into file in.txt\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
}

void showSortMode(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("\nplease input the way of sort :\n\n");
	printf(" 1 for insertionsort          \t   2 for heapsort\n"           );
	printf(" 3 for quickSort              \t   4 for randomizedQuickSort\n");
	printf(" 5 for midRandomizedQuickSort \t   6 for hoareQuickSort\n"     );
	printf(" 7 for countingSort           \t   8 for radixSort\n"        );
	printf(" 9 for RandomizedSelect       \t   others for input again\n\n" );
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
}

int dataGenerate(int* A){
	int A_length;
	FILE* fp;
	bool input_flag;	//���������жϱ�־
	do{
		showDatagenerateMode();
		input_flag=0;
		int casechoice;
		//scanf("%d",&casechoice);
		while(scanf("%d",&casechoice) == 0){
			fflush(stdin);	//�������ķǷ����ݣ�
			printf("input illegal,please input again ......\n");
		}
		switch(casechoice){
		case 1:{//�������������in.txt
			if((fp=fopen("in.txt","w"))==NULL){
				printf("can't open the file in.txt !!!\n");system("pause");exit(0);}
			printf("the data generates randomly is saving into in.txt ...... ");
			srand((unsigned)time(0));
			for(int k=0;k<LEN;k++){
				//srand(getpid());	//��ͬԪ�����������
				A[k]=random(LOWER,UPPER);
				fprintf(fp,"%d ",A[k]);
				//printf("%d ",A[k]);
			}
			A_length = LEN;
			printf("\n");break;}

		case 2:{//��in.txt��ȡ�������
			if((fp=fopen("in.txt","r"))==NULL){
				printf("can't open the file in.txt !!!\n");system("pause");exit(0);}
			printf("the data gets from in.txt is assign to array A ...... ");
			int k=0;
			while(!feof(fp)){										//A_length��֪����ʱ���أ�����
				fscanf(fp,"%d ",&A[k++]);
				//printf("%d ",A[k]);
			}
			A_length = k;
			printf("\n\n");break;}

		case 3:{//�ֶ�����
			if((fp=fopen("in.txt","w"))==NULL){
				printf("can't open the file in.txt !!!\n");system("pause");exit(0);}
			printf("please input the data you want to sort(end when the data input is illegal) :\n");
			int k=0;
			while(scanf("%d ",&A[k])){		//������һ���Ƿ����ݽ���������
				//printf("A[%d] = %d  ",k,A[k]);
				fprintf(fp,"%d ",A[k++]);
			}
			fflush(stdin);	//���stdin�еķǷ�����
			A_length = k;
			printf("the data input is saving into in.txt ...... \n");
			Sleep(1000);break;}

		default :
			//fflush(stdin);	//�������ķǷ��ַ���
			printf("input wrong num,please input again ......\n");
			Sleep(1000);
			input_flag=1;
			system("cls");break;
		}
	}while(input_flag);

	fclose(fp);
	return A_length;
}

short sortData(int* A,int* B,int A_length){
	bool input_flag;	//���������жϱ�־
	short sortDataSelectFlag=0;
	int startTime;
	do{
		showSortMode();
		input_flag=0;

		int casechoice;
		scanf("%d",&casechoice);
		startTime=clock();
		switch(casechoice){
		case 1://��������
			insertionSort(A,A_length);break;

		case 2://��������ԣ�
			heapSort(A,A_length);break;

		case 3://quickSort���Ų��ԣ�
			quickSort(A,0,A_length-1);break;
		case 4://randomizedQuickSort
			randomizedQuickSort(A,0,A_length-1);break;
		case 5://midRandomizedQuickSort
			midRandomizedQuickSort(A,0,A_length-1);break;
		case 6://hoareQuickSort
			hoareQuickSort(A,0,A_length-1);break;

		case 7:{//��������
			countingSort(A,B,LOWER,UPPER,A_length);
			sortDataSelectFlag=1;}break;

		case 8:{//��������
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			if(LOWER<0){printf("the array must be positive number ...\n ");system("pause");exit(0);};	//����������Ϊ��
			printf("please input the value of radix ... \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			int radix;
			scanf("%d",&radix);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			int keynum = 0;
			int maxNum = randomizedSelect(A,0,A_length-1,A_length);	//printf("maxNum is %d\n",maxNum);
			while(maxNum){	//ͨ��radix�����ÿ�����Ĺؼ�������λ����
				maxNum /= radix;
				keynum++;
			}printf("\nthe keynum of the array is %d\n",keynum);
			startTime=clock();	//��ȥ����radix and keynum��ʱ��
			radixSort(A,A_length,radix,keynum);}break;
			/*initialization of 'radix''keynum' is skipped by 'default'
			You cannot jump past a declaration with an initializer unless the declaration is enclosed in a block. 
			(Unless it is declared within a block, the variable is within scope until the end of the switch statement.) */

		case 9:{//ѡ���pos�������1��С��
			int pos = A_length;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			printf("please input the posth max indix pos (1-%d):\n",A_length);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			do{
				scanf("%d",&pos);
				if(pos<=A_length&&pos>=1)break;
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
					printf("input error , please input again ... \n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
				}
			}while(1);
			startTime=clock();
			int selectNum = randomizedSelect(A,0,A_length-1,pos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			printf("the %dth max num in A is : %d\n",pos,selectNum);
			sortDataSelectFlag = 2;
			   }break;

		default:
			fflush(stdin);
			printf("input error,please input again ......\n");
			Sleep(1000);
			input_flag=1;
			system("cls");break;
		}
	}while(input_flag);	
	int endTime=clock();
	printf("\nthe running time is: %d\n\n",endTime-startTime);
	system("pause");
	system("cls");
	return sortDataSelectFlag;
}

void saveAndPrint(int* A,int* B,int A_length,short sortDataSelectFlag){
	//���ź�����������out.txt
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
	FILE* fp;
	if((fp=fopen("out.txt","w"))==NULL){
		printf("can't open the file!!!\n");system("pause");exit(0);}
	printf("\nthe sorted array is :\n");
	if(!sortDataSelectFlag)	//for��������
		for(int k=0;k<A_length;k++){
			fprintf(fp,"%d ",A[k]);
			printf("%d ",A[k]);
		}
	else{
		for(int k=0;k<A_length;k++){
			fprintf(fp,"%d ",B[k]);
			printf("%d   ",B[k]);
		}}
	printf("\n\nthe data sorted is saving into out.txt ...... \n\n");
	fclose(fp);	
	system("pause");
}
