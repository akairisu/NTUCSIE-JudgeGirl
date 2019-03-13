#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
#include<sys/stat.h>
 
typedef struct Node{
	char name[65];
	int height;
	int weight;
	double BMI;
	struct Node *left , *right;
}Node;

Node *BuildTree(Node*tree ,char name[] ,int height ,int weight ,double BMI){
	if(tree == NULL){
		Node* current = (Node*)malloc(sizeof(Node));
		strcpy(current->name , name);
		current->height = height;
		current->weight = weight;
		current->BMI = BMI;
		current->left = NULL;
		current->right = NULL;
		return current;
	}
	else{
		if(BMI < tree->BMI){
			tree->left = BuildTree(tree->left , name , height , weight , BMI);
			return tree;
		}
		else if(BMI > tree->BMI){
			tree->right = BuildTree(tree->right , name , height , weight , BMI);
			return tree;
		}
		else{
			if(weight < tree->weight){
				tree->left = BuildTree(tree->left , name , height , weight , BMI);
				return tree;
			}
			if(weight > tree->weight){
				tree->right = BuildTree(tree->right , name , height , weight , BMI);
				return tree;
			}
			else{
				if(strcmp(tree->name , name) > 0){
					tree->left = BuildTree(tree->left , name , height , weight , BMI);
					return tree;
				}
				if(strcmp(tree->name , name) < 0){
					tree->right = BuildTree(tree->right , name , height , weight , BMI);
					return tree;
				}
			}
		}
	}
}

void PrintTree(Node*tree){
	if(tree == NULL){
		return;
	}
	PrintTree(tree->left);
	printf("%s %d %d\n" , tree->name , tree->height , tree->weight);
	PrintTree(tree->right);
}

int main(void)
{
	int N;
	scanf("%d" , &N);
	Node student[N];
	char names[N][65];
	int height[N] , weight[N];
	double BMI[N];  
	for(int i = 0 ; i < N ; i++){
		scanf("%s%d%d" , names[i] , &height[i] , &weight[i]);
		double heightinmeter = (double) height[i] / 100;
		double heightsquare = heightinmeter * heightinmeter;
		BMI[i] = (double) weight[i] / heightsquare;
	}
	Node *tree = (Node*)malloc(sizeof(Node));
	tree = NULL;
	for(int i = 0 ; i < N ; i++){
		tree = BuildTree(tree , names[i] , height[i] , weight[i] , BMI[i]);
	}
	PrintTree(tree); 
	return 0;
 }

