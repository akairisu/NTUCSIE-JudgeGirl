#include<stdio.h>
#include<string.h>
#include<ctype.h>

char word[10000000];
char *secondlevel[16384];
char ** firstlevel[1024];
int numofword[1024];

int main(void)
{
	int N;
	scanf("%d" , &N);
	int wordlength = 1;
	char c;
	int wordcounter = 0;
	int wordnumber = 0;
	int counter;
	for(int i = 0 ; i < N ; i++){
		counter = 0;
		firstlevel[i] = &secondlevel[wordnumber];
		while(scanf("%c", &word[wordcounter]) != '\n'){
			if(wordlength == 1){
				secondlevel[wordnumber] = &word[wordcounter];
				wordnumber++;
				counter++;
			}
			if(word[wordcounter] == ' '){
				wordlength = 1;
			}
			else wordlength++;
			wordcounter++;
		}
		numofword[i] = counter;
		word[wordcounter] = '\0';
	}
	int M;
	scanf("%d" , &M);
	int i1 , w1 , i2 , w2; 
	char *temp;
	for(int i = 0 ; i < M ; i++){
		scanf("%d%d%d%d" , &i1 , &w1 , &i2 , &w2);
		
	}
	counter = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < numofword[i] ; j++){
			printf("%d" , *secondlevel[counter]);
			if(j != numofword[i] - 1){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
 }

