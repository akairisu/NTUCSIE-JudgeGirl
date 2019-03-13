#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	char string[1024];
	scanf("%s" , string);
	char command[1024];
	char c;
	int counter = 0;
	char A[1000];
	char B[1000];
	while(scanf("%s" , command) != EOF){
			if(command[0] == 'p'){
				printf("%s\n" , string);
				continue;
			}
			if(command[0] == 's'){
				char delimiter[2];
				strncpy(delimiter , &command[1] , 1);
				delimiter[1] = '\0';
				char *start ;
				start = strtok(&command[1] , delimiter);
				int ABcount = 0;
				while(start != NULL){
					if(ABcount == 0){
						strcpy(A , start);
						ABcount++;
					}
					if(ABcount == 1){
						strcpy(B , start);
					}
					start = strtok(NULL , delimiter);
				}
				char *change;
				change = strstr(string , A);
				if (change != NULL){
					if(strlen(B) == strlen(A)){
						strncpy(change , B , strlen(B));
					}
					else{
						strcat(B + strlen(B) , change + strlen(A));
						strcpy(change , B); 
					}
				}
				else continue;
			}
		}
	return 0;
 }

