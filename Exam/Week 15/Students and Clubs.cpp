#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include<assert.h>
#define DEBUG 0
typedef struct club{
	char name[40];
	struct club *left , *right; 
	struct member *list;
}club;

typedef struct member{
	char name[40];
	struct member *left , *right;
}member;
#if DEBUG
void printroot(club *clubs){
	if(clubs == NULL){
		return;
	}
	printf("%s\n" , clubs->name);
	printroot(clubs->left);
	printroot(clubs->right);
}
#endif
member *plusmember(member *list , char *name){
	member *current;
	if(list == NULL){
		current = (member*)malloc(sizeof(member));
		assert(current != NULL);
		current->left = NULL;
		current->right = NULL;
		strcpy(current->name , name);
		return (current);
	}
	if(strcmp(list->name , name) > 0){
		list->left = plusmember(list -> left , name);
	}
	else
		list->right = plusmember(list -> right , name);
	return (list);
}

club *createclub(club *clubs ,char *name ,char *clubname){
	struct club *current;
	if(clubs == NULL){
		current = (club*)malloc(sizeof(club));
		assert(current != NULL);
		current->left = NULL;
		current->right = NULL;
		current->list = plusmember(NULL , name);
		strcpy(current->name , clubname);
		return (current);
	}
	if(strcmp(clubs->name , clubname) > 0){
		clubs->left = createclub(clubs->left , name , clubname);
	}else
		clubs->right = createclub(clubs ->right , name , clubname); 
	return (clubs);
}

club *findclub(club *clubs , char *clubname){
	if(clubs == NULL){
		return NULL;
	}
	if(strcmp(clubs->name , clubname) == 0){
		return (clubs);
	}
	if(strcmp(clubs->name , clubname) > 0){
		return findclub(clubs->left , clubname);
	}
	else return findclub(clubs->right , clubname);
}

member *findmember(member *list , char *name){
	if(list == NULL){
		return NULL;
	}
	if(strcmp(list->name , name) == 0){
		return (list);
	}
	if(strcmp(list->name , name) > 0){
		return findmember(list->left , name);
	}
	else return findmember(list->right , name);
}

int main(void)
{
	int k;
	scanf("%d" , &k);
	club *clubs = NULL;
	for(int i = 0 ; i < k ; i++){
		int create;
		scanf("%d" , &create);
		char name[40], clubname[40];
		switch(create){
			case 0:
				scanf("%s%s" , name , clubname);
				clubs = createclub(clubs , name , clubname);
				break;
			case 1:
				scanf("%s%s" , name , clubname);
				club *current;
				current = findclub(clubs , clubname);
				plusmember(current->list , name);
				break;
		}
	}
#if DEBUG
	printf("root = %s\n" , clubs->name);
	printroot(clubs);
#endif
	int Q;
	scanf("%d" , &Q);
	for(int i = 0 ; i < Q ; i++){
		int instruction;
		scanf("%d" , &instruction);
		char name[40] , clubname[40];
		switch(instruction){
			case 0:
				scanf("%s" , clubname);
				club *current;
				current = findclub(clubs , clubname);
				if(current != NULL){
					printf("%s\n" , current->list->name);
				}
				else printf("None\n");
				break;
			case 1:
				scanf("%s%s" , name , clubname);
				current = findclub(clubs , clubname);
				if(current == NULL){
					printf("-1\n");
				}
				else {
					member *nowmember = findmember(current->list , name);
					if(nowmember != NULL){
						printf("1\n");
					}
					else printf("0\n");
				}
				break;
		}
	}
	return 0;
 }

