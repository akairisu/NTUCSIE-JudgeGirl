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
        }
        if(type == 1){
            if(strcmp(string , A[i].lastname) != 0){
                check[i] = 1;
            }
        }
    }
}
 
void checkfirstname(int type , int n , char string[] ,int check[] , data A[]){
    for(int i = 0 ; i < n ; i++){
        if(type == 0){
            if(strcmp(string , A[i].firstname) == 0){
                check[i] = 1;
            }
        }
        if(type == 1){
            if(strcmp(string , A[i].firstname) != 0){
                check[i] = 1;
            }
        }
    }
}
 
void checkID(int type ,int n , char string[] ,int check[] , data A[]){
    for(int i = 0 ; i < n ; i++){
        if(type == 0){
            if(strcmp(string , A[i].ID) == 0){
                check[i] = 1;
            }
        }
        if(type == 1){
            if(strcmp(string , A[i].ID) != 0){
                check[i] = 1;
            }
        }
    }
}
 
void checksalary(int type ,int n ,char string[] ,data A[] ,int check[]){
    int len = strlen(string);
    int a = 0;
    for(int i = 0; i < len ; i++){
        a = a * 10;
        a += string[i] - '0';
    }
    for(int i = 0 ; i < n ; i++){
        if(type == 0){
            if(A[i].salary > a){
                check[i] = 1;
            }
        }
        if(type == 1){
            if(A[i].salary == a){
                check[i] = 1;
            }
        }
        if(type == 2){
            if(A[i].salary < a){
                check[i] = 1;
            }
        }
    }
}
 
void checkage(int type ,int n ,char string[] ,data A[] ,int check[]){
    int len = strlen(string);
    int a = 0;
    for(int i = 0; i < len ; i++){
        a = a * 10;
        a += string[i] - '0';
    }
    for(int i = 0 ; i < n ; i++){
        if(type == 0){
            if(A[i].age > a){
                check[i] = 1;
            }
        }
        if(type == 1){
            if(A[i].age == a){
                check[i] = 1;
            }
        }
        if(type == 2){
            if(A[i].age < a){
                check[i] = 1;
            }
        }
    }
}
 
int checksecondconditionchar(char string[]){
    if(strcmp(string , "==") == 0){
        return 0;
    }
    else return 1;
}
 
int checksecondcondition(char string[]){
    if(strcmp(string , ">") == 0){
        return 0;
    }
    if(strcmp(string , "==") == 0){
        return 1;
    }
    if(strcmp(string , "<") == 0){
        return 2;
    }
}
 
void checkcondition(int n ,char condition[3][81],int check[] ,data A[])
{
    if(strcmp(condition[0] , "lastname") == 0){
        switch(checksecondconditionchar(condition[1])){
            case 0:
                checklastname(0 , n , condition[2] , check , A);
                break;
            case 1:
                checklastname(1 , n , condition[2] , check , A);
                break;
        }
    }
    if(strcmp(condition[0] , "firstname") == 0){
        switch(checksecondconditionchar(condition[1])){
            case 0:
                checkfirstname(0 , n , condition[2] , check , A);
                break;
            case 1:
                checkfirstname(1 , n , condition[2] , check , A);
                break;
        }
    }
    if(strcmp(condition[0] , "ID") == 0){
        switch(checksecondconditionchar(condition[1])){
            case 0:
                checkID(0 , n , condition[2] , check , A);
                break;
            case 1:
                checkID(1 , n , condition[2] , check , A);
                break;
        }
    }
    if(strcmp(condition[0] , "salary") == 0){
        switch(checksecondcondition(condition[1])){
            case 0:
                checksalary(0 , n , condition[2] , A , check);
                break;
            case 1:
                checksalary(1 , n , condition[2] , A , check);
                break;
            case 2:
                checksalary(2 , n , condition[2] , A , check);
                break;
        }    
    }
    if(strcmp(condition[0] , "age") == 0){
        switch(checksecondcondition(condition[1])){
            case 0:
                checkage(0 , n , condition[2] , A , check);
                break;
            case 1:
                checkage(1 , n , condition[2] , A , check);
                break;
            case 2:
                checkage(2 , n , condition[2] , A , check);
                break;
        }    
    }
}
 
void printfield(char string[] , data A){
    if(strcmp(string , "lastname") == 0){
        printf("%s" , A.lastname);
    }
    if(strcmp(string , "firstname") == 0){
        printf("%s" , A.firstname);
    }
    if(strcmp(string , "ID") == 0){
        printf("%s" , A.ID);
    }
    if(strcmp(string , "salary") == 0){
        printf("%d" , A.salary);
    }
    if(strcmp(string , "age") == 0){
        printf("%d" , A.age);
    }
}
 
int main(void)
{
    int n;
    scanf("%d" , &n);
    data A[50];
    char lastname[81];
    char firstname[81];
    char ID[81];
    for(int i = 0 ; i < n ; i++){
        scanf("%s%s%s" , lastname , firstname , ID);
        strcpy(A[i].lastname , lastname);
        strcpy(A[i].firstname , firstname);
        strcpy(A[i].ID , ID);
        scanf("%d%d" , &A[i].salary , &A[i].age);
    }
    int commandnum;
    scanf("%d" , &commandnum);
    char command[50];
    char field[8][50];
    for(int i = 0 ; i < commandnum ; i++){
        int count = 0;
        while(scanf("%s" , command) != EOF){
            if(strcmp(command , "select") == 0){
                continue;
            }
            if(strcmp(command , "where") == 0){
                break;
            }
            else strcpy(field[count] , command);
            count++;
        }
        char condition[3][81];
        for(int i = 0 ; i < 3 ; i++){
            scanf("%s" , condition[i]);
        }
        int check[50] = {0};
        checkcondition(n , condition , check , A);
        for(int i = 0 ; i < n ; i++){
            if(check[i] == 1){
                for(int j = 0 ; j < count ; j++){
                    printfield(field[j] , A[i]);
                    if(j != count - 1){
                        printf(" ");
                    }
                    else printf("\n");
                }
            }
        }
    }
    return 0;
 }
