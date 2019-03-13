#include<stdio.h>

int main(void)
{
	int N , M , P;
	scanf("%d%d%d" , &N , &M , &P);
	unsigned long long code[4];
	for(int i = 0 ; i < M ; i++){
		scanf("%llu" , &code[i]);
	}
	int count = 0;
	unsigned char text[230];
	while(count != P){
		scanf("%hhu" , &text[count]);
		count++;
	}
	unsigned long long int shiftcode;
	unsigned char valid[25];
	count = 0;
	for(int i = 0 ; i < M ; i++){
		for(int j = 0 ; j < 8 ; j++){
			shiftcode = code[i] >> j * 8;
			valid[count] = shiftcode & 255;
			count++;
		}
	}
	for(int i = 0 ; i < P ; i++){
		for(int j = 0 ; j < N ; j++){
			int diff = 0;
			for(int l = 0 ; l < 8 ; l++){
				unsigned char LSBtext = text[i] >> l;
				unsigned char LSBcode = valid[j] >> l;
				if((LSBcode & 1) != (LSBtext & 1)){
					diff++;
				}
			}
			if(diff == 0 || diff == 1){
				printf("%hhu\n" , valid[j]);
				break;
			}
		}
	}
	return 0;
}

