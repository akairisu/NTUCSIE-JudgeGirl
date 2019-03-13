#include<stdio.h>
#include<assert.h> 
 
int main(void)
{
	char name[200];
	scanf("%s" , name);
	FILE *file;
	file = fopen(name , "rb");
	assert(file != NULL);
	int n;
	int max;
	int maxnumber = 0;
	int count[65536] = {0};
	fread(&n , sizeof(int) , 1 , file);
	short numbers[n];
	for(int i = 0 ; i < n ; i++){
		fread(&numbers[i] , 2 , 1 , file);
		if(numbers[i] < 0){
			count[32767 - numbers[i]]++;
		}
		else count[numbers[i]]++;
		if(numbers[i] > 0 && count[numbers[i]] > maxnumber){
			max = numbers[i];
			maxnumber = count[numbers[i]];
		}
		if(numbers[i] > 0 && count[numbers[i]] == maxnumber && numbers[i] > max){
			max = numbers[i];
		}
		if(numbers[i] < 0 && count[32767 - numbers[i]] > maxnumber){
			max = numbers[i];
			maxnumber = count[32767-numbers[i]];
		}
		if(numbers[i] < 0 && count[32767 - numbers[i]] == maxnumber && numbers[i] > max){
			max = numbers[i];
		}
	}
	fclose(file);
	printf("%d\n" , max);
	printf("%d\n" , maxnumber);
	return 0;
 }

