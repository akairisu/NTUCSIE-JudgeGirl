#include<stdio.h>
#include<string.h>

typedef struct data{
	char lastname[80];
	char firstname[80];
	char ID[80];
	int salary;
	int age;
}data;

void checklastname(int type , int n , char string[] ,int check[] , data A[]){
	for(int i = 0 ; i < n ; i++){
		if(type == 0){
			if(strcmp(string , A[i].lastname) == 0){
				check[i] = 1;
			}
			continue;
		}
		if(strcmp(string , A[i].lastname) != 0){
			check[i] = 1;
		}
	}
}

void checkfirstname(int type , int n , char string[] ,int check[] , data A[]){
	for(int i = 0 ; i < n ; i++){
		if(type == 0){
			if(strcmp(string , A[i].firstname) == 0){
				check[i] = 1;
			}
			continue;
		}
		if(strcmp(string , A[i].firstname) != 0){
			check[i] = 1;
		}
	}
}

void checkID(int type , int n , char string[] , int check[] , data A[]){
	for(int i = 0 ; i < n ; i++){
		if(type == 0){
			if(strcmp(string , A[i].ID) == 0){
				check[i] = 1;
			}
			continue;
		}
		if(strcmp(string , A[i].ID) != 0){
			check[i] = 1;
		}
	}
}

void checksalary(int type , int n , char string[] , data A[] , int check[]){
	int len = strlen(string);
	int a = 0;
	for(int i = 0; i < len ; i++){
		a = a * 10;
		a += string[i] - '0';
	}
	for(int i = 0 ; i < n ; i++){
		switch(type){
			case 0:
				if(A[i].salary > a){
					check[i] = 1;
				}
				break;
			case 1:
				if(A[i].salary == a){
					check[i] = 1;
				}
				break;
			case 2:
				if(A[i].salary < a){
					check[i] = 1;
				}
				break;
		}
	}
}

void checkage(int type , int n , char string[] , data A[] , int check[]){
	int len = strlen(string);
	int a = 0;
	for(int i = 0; i < len ; i++){
		a = a * 10;
		a += string[i] - '0';
	}
	for(int i = 0 ; i < n ; i++){
		switch(type){
			case 0:
				if(A[i].age > a){
					check[i] = 1;
				}
				break;
			case 1:
				if(A[i].age == a){
					check[i] = 1;
				}
				break;
			case 2:
				if(A[i].age < a){
					check[i] = 1;
				}
				break;
		}
	}
}

int checksecondconditionchar(char string[]){
	if(string[0] == '='){
		return 0;
	}
	return 1;
}

void checkcondition(int n ,char condition[3][81],int check[] ,data A[])
{
	if(condition[0][0] == 'l'){
		checklastname(checksecondconditionchar(condition[1]) , n , condition[2] , check , A);
	}
	if(condition[0][0] == 'f'){
		checkfirstname(checksecondconditionchar(condition[1]) , n , condition[2] , check , A);
	}
	if(condition[0][0] == 'I'){
		checkID(checksecondconditionchar(condition[1]) , n , condition[2] , check , A);
	}
	if(condition[0][0] == 's'){
		checksalary('>' - condition[1][0] , n , condition[2] , A , check);	
	}
	if(condition[0][0] == 'a'){
		checkage('>' - condition[1][0] , n , condition[2] , A , check);
	}
}

void printfield(char string[] , data A){
	if(string[0] == 'l'){
		printf("%s" , A.lastname);
	}
	if(string[0] == 'f'){
		printf("%s" , A.firstname);
	}
	if(string[0] == 'I'){
		printf("%s" , A.ID);
	}
	if(string[0] == 's'){
		printf("%d" , A.salary);
	}
	if(string[0] == 'a'){
		printf("%d" , A.age);
	}
}

int main(void)
{
	int n;
	scanf("%d" , &n);
	data A[50];
	for(int i = 0 ; i < n ; i++){
		scanf("%s%s%s" , A[i].lastname , A[i].firstname , A[i].ID);
		scanf("%d%d" , &A[i].salary , &A[i].age);
	}
	int commandnum;
	scanf("%d" , &commandnum);
	char command[50];
	char field[8][50];
	for(int i = 0 ; i < commandnum ; i++){
		int count = 0;
		scanf("%s" , command);
		while(scanf("%s" , command) != EOF){
			if(strcmp(command , "where") == 0){
				break;
			}
			strcpy(field[count] , command);
			count++;
		}
		char condition[3][81];
		for(int i = 0 ; i < 3 ; i++){
			scanf("%s" , condition[i]);
		}
		int check[50] = {0};
		checkcondition(n , condition , check , A);
		for(int i = 0 ; i < n ; i++){
			if(check[i]){
				for(int j = 0 ; j < count - 1 ; j++){
					printfield(field[j] , A[i]);
					printf(" ");
				}
				printfield(field[count - 1] , A[i]);
				printf("\n");
			}
		}
	}
	return 0;
 }

