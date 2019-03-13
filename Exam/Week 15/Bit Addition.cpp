#include<stdio.h>
#include<assert.h>

int main(void)
{
	char input1[32] , input2[32] , output[32]; 
	scanf("%s%s%s" , input1 , input2 , output);
	FILE *fin1 , *fin2 , *out;
	fin1 = fopen(input1 , "rb");
	fin2 = fopen(input2 , "rb");
	out = fopen(output , "wb"); 
	assert(fin1 != NULL);
	assert(fin2 != NULL);
	assert(out != NULL);
	int sum , carry = 0;
	int digits1 , digits2;
	fseek(fin1 , 0 , SEEK_END);
	fseek(fin2 , 0 , SEEK_END);
	digits1 = ftell(fin1);
	digits2 = ftell(fin2);
	max = (digits1 >= digits2) ? digits1 : digits2;
	min = (digits1 < digits2) ? digits1 ; digits2;
	int out[max];
	for(int i = 0 ; i < min ; i++){
		int readin1 , readin2;
		fread(&readin1 , 1 , 1 , fin1);
		fread(&readin2 , 1 , 1 , fin2);
		sum = readin1 + readin2 + carry;
		carry = 0;
		if(sum > 255){
			sum -= 256;
			carry = 1;
		}
		fwrite(&out[i] , 1 , 1 ,)
	}
	return 0;
 }

