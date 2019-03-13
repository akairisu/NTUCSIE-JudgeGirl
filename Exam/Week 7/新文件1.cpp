#include<stdio.h>

void count(int **p[])
{
	int i = 0;
	int count[512];//count 是指相同level2的pointer數量 
	int used[512];//used 確認該pointer是否有使用過
	for(int j = 0 ; j < 512 ; j++){
		count[j] = 0;
		used[j] = 0;
	} 
	int number = 0;
	int *addrlevel1[512];
	while(p[i] != NULL){
		if(used[i] != 1){
			addrlevel1[number] = *p[i];
			count[number]++;
			int j = 1;
			while(p[i + j] != NULL){
				if(*p[i + j] == *p[i]){
					count[number]++;
					used[i+j] = 1;
				}	
				j++;
			}
			number++;
		}
		i++;
	}
	int temp;
	int tempaddr;
	for(int j = 0 ; j < number ; j++){
		for(int k = j + 1 ; k < number ; k++){
			if(count[j] >= count[k] && *addrlevel1[j] > *addrlevel1[k]){
				temp = count[j];
				count[j] = count[k];
				count[k] = temp;
				tempaddr = *addrlevel1[j];
				*addrlevel1[j] = *addrlevel1[k];
				*addrlevel1[k] = tempaddr;
			}
		}
		printf("%d %d\n" , *addrlevel1[j] , count[j]);
	}
}
