/****************************************************************************/
/*			POJ����ʼ�4.4 ���� �Ӵ�2744��1226		ƤƤ 2014-7-5			*/
/****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "StrRev.h"

void subStr(){
	int cases;
	scanf("%d", &cases);
	char str[100][101];
	int i;

	while(cases--){
		int strNum;
		scanf("%d", &strNum);
		int minLenIndex, minLen = 101;
		for(i = 0; i < strNum; i++){
			scanf("%s", str[i]);
			if( strlen(str[i]) < minLen ){
				minLen = strlen(str[i]);
				minLenIndex = i;
			}
		}

		int subLen;
		char subStr[101];
		for(subLen = minLen; subLen > 0; subLen--){				//�Ӵ�����
			for(int j = 0; j <= minLen - subLen; j++){			//�Ӵ���ʼ��ַ
				strncpy(subStr, str[minLenIndex] + j, subLen);
				subStr[subLen] = 0;
				int k;
				for(k = 0; k < strNum; k++){					//��strNum���ַ����Ա�
					if( strstr(str[k], subStr)  == NULL && strstr(strReverse(str[k]), subStr) == NULL )//strrev()ms�Լ��Ŀ⺯��
						break;									//��һ���ַ���û���Ͼ�break����һ���Ӵ��Ƚ�
				}
				if(k == strNum){								//�˿̵Ĵ�j��ʼ�ĳ���subLen���Ӵ�����Ҫ��
					printf("%d\n",subLen);
					goto nextCase;
				}
			}
		}

		if(subLen == 0)											//����Ϊ0�˶�û�ҵ�
			printf("0\n");
nextCase:;
	}
}

int __548451main(){
	subStr();
	//char str[] = "ABCD";			//char* str�ھ�̬���������ᵼ��strrev�з���д��λ�ó�ͻ���������޸�
	//printf("%s\n", strrev(str));
	return 0;
}
