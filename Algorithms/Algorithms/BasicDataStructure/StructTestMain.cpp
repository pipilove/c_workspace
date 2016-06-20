///*	���Ի������ݽṹ��main����	2013.12.19	ƤƤ		*/
const int LEN  = 6;		//����Ҫ���Ե�����Ĵ�С
const int LOWER= 1  ;	//����Ҫ���Ե��������Сֵ
const int UPPER= 30;	//����Ҫ���Ե���������ֵ
using namespace std;			//string

#include "myDataStructDefine.h"
#include "BST.h"
#include "HashTable.h"

static void showDatagenerateMode();
static vector<ITEMTYPE> dataGenerate();
static int dataGenerate(int* A);
template <class T>
static void printfArray(vector<T> A);
static void printfArray(ITEMTYPE* A,int A_length);
static void testHashTable(vector<ITEMTYPE> V);

int __1511main(){
	//int A[LEN];
	//int A_length = dataGenerate(A);	//������������ĳ���
	//printfArray(A,A_length);
	//printf("\n");

	vector<ITEMTYPE> V = dataGenerate();
	printf("Array V is :\n");
	printfArray(V);
	testHashTable(V);

	//bstnode *bst = buildBST(A,A_length);
	//MakeDot(bst);	//����.gv�ļ�
	//bstTest(bst,A);

	printf("\n");
	system("pause");
	return 0;
}

void showDatagenerateMode(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("please input the Generation methods that the array need to sort:\n\n");
	printf("1 Randomly generate and save into file in.txt\n");
	printf("2 use the privious data in file in.txt that generate randomly\n");
	printf("3 manually generate and save into file in.txt\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
}
vector<ITEMTYPE> dataGenerate(){
	vector<ITEMTYPE> A;
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
		cin.sync();			//���cin������δ����Ϣ("\n")
		switch(casechoice){
		case 1:{//�������������in.txt
			if((fp=fopen("in.txt","w"))==NULL){
				printf("can't open the file in.txt !!!\n");system("pause");exit(0);}
			printf("the data generates randomly is saving into in.txt ...... ");
			srand((unsigned)time(0));
			int data;
			for(int k=0;k<LEN;k++){
				//srand(getpid());	//��ͬԪ�����������
				data = random(LOWER,UPPER);
				A.push_back(data);
				fprintf(fp,"%d ",data);
				//printf("%d ",data);
			}
			printf("\n");break;}

		case 2:{//��in.txt��ȡ�������
			if((fp=fopen("in.txt","r"))==NULL){
				printf("can't open the file in.txt !!!\n");system("pause");exit(0);}
			printf("the data gets from in.txt is assign to array A ...... ");
			int data;
			while(!feof(fp)){
				fscanf(fp,"%d ",&data);
				A.push_back(data);
				//printf("%d ",data);
			}
			printf("\n");break;}

		case 3:{//�ֶ�����
			if((fp=fopen("in.txt","w"))==NULL){
				printf("can't open the file in.txt !!!\n");system("pause");exit(0);}
			printf("please input the data you want to sort(end when the data input is illegal) :\n");
			ITEMTYPE data;
			//while(scanf("%d ",&data)){
			while((data = cin.get()) != '\n'){		//input any format data,end with ctl+z and return false 2 cin
				cin.unget();
				cin>>data;
				A.push_back(data);
				//printf("data = %d  ",data);
				//cout<<data<<" ";
				fprintf(fp,"%d ",data);
			}
			fflush(stdin);	//���stdin�еķǷ�����
			cin.clear();	//set the state of stream as good
			printf("the data input is saving into in.txt ...... \n");
			Sleep(1000);break;}

		default :
			//fflush(stdin);
			printf("input wrong num,please input again ......\n");
			Sleep(1000);
			input_flag=1;
			system("cls");break;
		}
	}while(input_flag);

	fclose(fp);
	return A;
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
			printf("\n");break;}

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

template <class T>
void printfArray(vector<T> A){		//û��&���޸�iterator?
	vector<T>::const_iterator i;
	for(i = A.begin();i != A.end();i++)	//!=A.end() or vector itrator not dereferencable
		cout<<*i<<" ";
	cout<<endl;
}
void printfArray(ITEMTYPE* A,int A_length){
	printf("array A is :\n");
	for(int i = 0;i<= A_length-1;i++)
		printf("%d ",A[i]);
	printf("\n");
}

void testHashTable(vector<ITEMTYPE> V){	
	//test derect addressing
	//hashTable *ht = new hashTable(*max_element(V.begin(),V.end())+1);	//max_element(vec)����vec�����ֵiterator
	//for(int i = 0;i <= V.size()-1;i++){
	//	hashnode *a = new hashnode;
	//	a->key = V[i];
	//	ht->directAddressInsert(*a);
	//}

	//test open addressing	input:79 69 72 98 14 50
	int hashTableSize = 13;
	hashTable *ht = new hashTable(hashTableSize);
	for(int i = 0;i <= V.size()-1;i++){
		hashnode *a = new hashnode;
		a->key = V[i];
		ht->hashInsert(*a);	//!!!*a
	}


	cout<<"the sorted keys in vector are : "<<endl;
	sort(V.begin(),V.end());
	printfArray(V);
	cout<<endl;

	ht->display();


	////manually manipulate
	////search in hashTable
	//cout<<"input the key you want to search : "<<endl;
	//int sKey;
	//for(int i = 0;i <= V.size() - 1;i ++){
	//	cin>>sKey;
	//	hashnode hn = ht->hashSearch(sKey);
	//	if(equ(hn,ht->nil))
	//		cout<<"the key of "<<sKey<<" isn't exit , search fail ... "<<endl;
	//	else
	//		cout<<"search success , the "<<sKey<<"'s position(start from 0) is : "<<hn.position<<endl;
	//}

	////delete hashnode in hashTable
	//int dkey;
	//for(int i = 0;i <= V.size() - 1;i ++){
	//	cin>>dkey;
	//	if(ht->hashDelete(dkey))
	//		cout<<"delete key "<<dkey<<" success "<<endl;
	//	else
	//		cout<<"delete fail , "<<dkey<<"isn't exit "<<endl;
	//}
	//ht->display();


	//automatically complete!
	//search in hashTable	
	for(int i = 0;i <= V.size() - 1;i ++){
		hashnode hn = ht->hashSearch(V[i]);
		if(equ(hn,ht->nil))
			cout<<"the key of "<<V[i]<<" isn't exit , search fail ... "<<endl;
		else
			cout<<"search success , the "<<V[i]<<"'s position(start from 0) is : "<<hn.position<<endl;
	}
	//delete hashnode in hashTable
	for(int i = 0;i <= V.size() - 1;i ++){
		if(ht->hashDelete(V[i]))
			cout<<"delete key "<<V[i]<<" success "<<endl;
		else
			cout<<"delete fail , "<<V[i]<<"isn't exit "<<endl;
	}
	ht->display();
}
