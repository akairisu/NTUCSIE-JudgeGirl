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
	unsigned char text[250];
	unsigned long long int shiftcode;
	unsigned char valid[50];
	for(int i = 0 ; i < M ; i++){
		for(int j = 7 ; j >= 0 ; j--){
			shiftcode = code[i] >> (j * 8);
			valid[count] = (shiftcode & 255);
			count++;
			if(count == N){
				break;
			}
		}
		if(count == N){
			break;
		}
	}
	unsigned char LSBtext;
	unsigned char LSBcode;
	for(int i = 0 ; i < P ; i++){
		scanf("%hhu" , &text[i]);
		for(int j = 0 ; j < N ; j++){
			int diff = 0;
			for(int l = 0 ; l < 8 ; l++){
				LSBtext = text[i] >> l;
				LSBcode = valid[j] >> l;
				if((LSBcode & 1) != (LSBtext & 1)){
					diff++;
				}
			}
			//printf("%hhu %hhu %d\n" , text[i] , valid[j] , diff);
			if(diff == 0 || diff == 1){
				printf("%hhu\n" , valid[j]);
				break;
			}
		}
	}
	return 0;
}

