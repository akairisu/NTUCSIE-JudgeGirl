#include <stdio.h>
 
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
 
void count(int **p[])
{
	int i = 0;
	int count[512] = {1};//count 是指相同level2的pointer數量 
	int used[512] = {0};//used 確認該pointer是否有使用過 
	int number = 0;
	int **point[512];//point是p指的level2的位置
	while(p[i] != NULL){
		if(used[i] != 1){
			point[number] = p[i]; 
			int j = 1;
			while(p[i+j] != NULL){
				if(p[i+j] == p[i]){
					count[number]++;
					used[i+j] = 1;
				}	
				j++;
			}
			number++;
		}
		i++;
	}
	point[number] = NULL;
	int usedpoint[512] = {0};
	int sum[number]; //sum 是指相同level3的數量 
	int *pointto1[number];// pointto1 是指的 level1 的位置 
	number = 0;
	i = 0;
	while(point[i] != NULL){
		if(usedpoint[i] != 1){
			pointto1[number] = *point[i];
			int j = 1;
			sum[number] = count[i];
			while(*point[i + j] == *point[i]){
				usedpoint[i + j] = 1;
				sum[number] += count[i + j];
			}
			number++;
		} 
		i++;
	}
	int temp;
	for(int j = 0 ; j < number ; j++){
		for(int k = j + 1 ; k < number ; k++){
			if(sum[j] <= sum[k] && *pointto1[j] < *pointto1[k]){
				temp = *pointto1[j];
				*pointto1[j] = *pointto1[k];
				*pointto1[k] = temp;
				temp = sum[j];
				sum[j] = sum[k];
				sum[k] = temp;
			}
		}
	}
	for(int j = 0 ; j < number ; j++){
		printf("%d %d\n" , *pointto1[j] , sum[j]);
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

