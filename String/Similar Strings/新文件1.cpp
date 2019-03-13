#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	int N;
	scanf("%d" , &N);
	char string1[81];
	char string2[81];
	for(int i = 0 ; i < N ; i++){
		scanf("%s" , string1);
		scanf("%s" , string2);
		int len1 = strlen(string1);
		int len2 = strlen(string2);
		int max , min , longer;
		if(len1 >= len2){
			max = len1;
			min = len2;
			longer = 1;
		}
		else{
			max = len2;
			min = len1;
			longer = 2;
		}
		int sub = max - min;
		if(sub < 0 && sub > 1){
			printf("no\n");
		}
		else{
			if(sub == 0){
				if(strcmp(string1 , string2) == 0){
					printf("yes\n");
				}
				else {
					int diff = 0;
					int diffalpha[2];
					for(int i = 0 ; i < len1 ; i++){
						if(string1[i] != string2[i]){
							diffalpha[diff] = i;
							diff++;
						}
					}
					if(diff > 2){
						printf("no\n");
						continue;
					}
					else{
						if(string1[diffalpha[0]] == string2[diffalpha[1]] && string1[diffalpha[1]] == string2[diffalpha[0]]){
							printf("yes\n");
							continue;
						}
						else{
							printf("no\n");
							continue;
						}
					}
				}
			}
			else{
				for(int i = 0 ; i < max ; i++){
					if(string1[i] != string2[i]){
						if(longer == 1){
							for(int j = i ; j < len1 ; j++){
								string1[j] = string1[j + 1];
							}
						}
						if(longer == 2){
							for(int j = i ; j < len2 ; j++){
								string2[j] = string2[j + 1];
							}
						}
						break;
					}
				}
				if(strcmp(string1 , string2) == 0){
					printf("yes\n");
				}
				else printf("no\n");
			}
		}
	}

	return 0;
 }

