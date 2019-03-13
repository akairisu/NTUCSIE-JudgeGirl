#include<stdio.h>
#include<stdlib.h>
#include<assert.h> 
#define DEBUG 0
typedef struct Node{
    int n;
    struct Node *left, *right;
} Node;
 
Node *FlipTree(Node *root){
	Node *temp = (Node*)malloc(sizeof(Node));
	assert(temp != NULL);
	if(root == NULL){
		return NULL;
	}
	temp->n = root->n;
	temp->right = FlipTree(root->left);
	temp->left = FlipTree(root->right);
	return temp;
}

int isIdentical(Node *tree1, Node *tree2){
	if(tree1 == NULL && tree2 == NULL){
		return 1;
	}
	if(tree1->n == tree2->n){
		return (isIdentical(tree1->left , tree2->left) && isIdentical(tree1->right , tree2->right));
	}
	return 0;
}

int countleaves(Node *root){
	if(root == NULL){
		return 0;
	}
	if(root->left == NULL && root->right == NULL){
		return 1;
	}
	return (countleaves(root->left) + countleaves(root->right));
}

int countsum(int count , Node *root){
	if(root == NULL){
		return 0;
	}
	if(root->left == NULL && root->right == NULL){
		return count;
	}
	return (countsum(count + 1 , root->left) + countsum(count + 1 , root->right));
}

void depthAvg(Node *root){
	int leafnum = countleaves(root);
	int leafsum = countsum(0 ,root);
	printf("%d/%d\n" , leafsum , leafnum);
} 

void printTree(Node *root) {
  if (root == NULL) {
    printf("NULL\n");
    return;
  }
  printf("%d\n", root->n);
  if (root->left == NULL && root->right == NULL) return;
  printTree(root->left);
  printTree(root->right);
}
 
int main() {
  Node tree1[9];
 
  for(int i = 0; i < 9; i++){
    tree1[i].n = i;
    tree1[i].left = tree1[i].right = NULL;
  }
 
  tree1[0].left = &tree1[1];
  tree1[0].right = &tree1[2];
  tree1[1].left = &tree1[3];
  tree1[1].right = &tree1[4];
  tree1[2].left = &tree1[5];
  tree1[2].right = &tree1[8];
  tree1[4].left = &tree1[6];
  tree1[6].right = &tree1[7];
 
  depthAvg(&tree1[0]);
 
  return 0;
}
