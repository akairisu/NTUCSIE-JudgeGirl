#include <stdio.h>
 
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
 
void count(int **p[])
{
	int i = 0;
	int count[512];//count 是指相同level2的pointer數量 
	int used[512];//used 確認該pointer是否有使用過
	for(int j = 0 ; j < 512 ; j++){
		count[j] = 1;
		used[j] = 0;
	} 
	int number = 0;
	int **point[512];//point是p指的level2的位置
	while(p[i] != NULL){
		if(used[i] != 1){
			printf("p[%d] = %p\n" , i , p[i]);
			point[number] = p[i]; 
			int j = 1;
			while(p[i + j] != NULL){
				if(p[i + j] == p[i]){
					printf("p[%d] = %p\n" , i + j , p[i+j]);
					count[number]++;
					used[i+j] = 1;
				}	
				j++;
			}
			printf("count = %d\n" , count[number]);
			printf("point[%d] = %p\n" , number , point[number]);
			number++;
		}
		i++;
	}
}
	
int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 6;
  intVar[2] = 2;
  intVar[3] = 9;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[3];
  ptrArray[4] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[3];
 
  count(ptrArray);
 
  return 0;
}

