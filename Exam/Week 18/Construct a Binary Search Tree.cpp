#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define MAXN 1024

char name[MAXN][16];
int height[MAXN];
int weight[MAXN];

typedef struct Node{
    char name[16];
    int height;
    int weight;
    struct Node *left, *right;
} Node;
#ifdef HEIGHT
Node*BuildTree(Node *root , char name[16] , int height , int weight){
	if(root == NULL){
		Node* current = (Node*)malloc(sizeof(Node));
		strcpy(current->name , name);
		current->height = height;
		current->weight = weight;
		current->left = NULL;
		current->right = NULL;
		return current;
	}
	else{
		if(height < root->height){
			root->left = BuildTree(root->left , name , height , weight);
			return root;
		}
		if(height > root->height){
			root->right = BuildTree(root->right , name , height , weight);
			return root;
		}
	}	
}
Node*ConstructBSTree(int N, char name[][16], int height[], int weight[]){
	Node *root = (Node*)malloc(sizeof(Node));
	root = NULL;
	for(int i = 0 ; i < N ; i++){
		root = BuildTree(root , name[i] , height[i] , weight[i]);
	}
	return root;
} 
#endif
#ifdef WEIGHT 
Node*BuildTree(Node *root , char name[16] , int height , int weight){
	if(root == NULL){
		Node* current = (Node*)malloc(sizeof(Node));
		strcpy(current->name , name);
		current->height = height;
		current->weight = weight;
		current->left = NULL;
		current->right = NULL;
		return current;
	}
	else if(weight < root->weight){
		root->left = BuildTree(root->left , name , height , weight);
		return root;
	}
	else if(weight > root->weight){
		root->right = BuildTree(root->right , name , height , weight);
		return root;
	}
}

Node*ConstructBSTree(int N, char name[][16], int height[], int weight[]){
	Node *root = (Node*)malloc(sizeof(Node));
	root = NULL;
	for(int i = 0 ; i < N ; i++){
		root = BuildTree(root , name[i] , height[i] , weight[i]);
	}
	return root;
} 
#endif 
void PrintBSTree( Node *root ){
    if (root == NULL)
        return;
    printf("%s\n", root->name);
    PrintBSTree(root->left);
    PrintBSTree(root->right);
    return;
}
 
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%s %d %d", name[i], &height[i], &weight[i]);
 
    Node *tree = ConstructBSTree( N, name, height, weight );
 
    PrintBSTree( tree );
    return 0;
}
