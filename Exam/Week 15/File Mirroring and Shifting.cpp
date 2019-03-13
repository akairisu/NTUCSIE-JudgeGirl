#include<stdio.h>
#include<assert.h> 

int main(void)
{
	char input[17] , output[17];
	int N;
	scanf("%s %s %d" , input , output , &N);
	FILE *fin = fopen(input , "rb");
	FILE *fout = fopen(output , "wb");
	assert(fin != NULL);
	assert(fout != NULL);
	fseek(fin , 0 , SEEK_END);
	int count = ftell(fin); 
	for(int i = 0 ; i < count ; i++){
		fseek(fin , -(((N+i)%count)+1), SEEK_END);
		char in  , out = 0;
		fread(&in , 1 , 1 , fin);
		for(int j = 0 ; j < 8 ; j++){
			if(in & (1 << j)){
				out |= 1 << (7 - j);
			}
		}
		fwrite(&out , 1 , 1 , fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
 }

