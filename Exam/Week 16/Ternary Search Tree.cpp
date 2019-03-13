#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAXN 32768

int sequence[MAXN];

typedef struct node{
    int small,large;
    struct node *left,*mid,*right;
} Node;

Node*buildtree(Node*head , int sequence[] , int now){
	if(head == NULL){
		Node* current = (Node*)malloc(sizeof(Node));
		current->large = sequence[now];
		current->small = -1;
		current->left = NULL;
		current->mid = NULL;
		current->right = NULL;
		return current;
	}
	if(head->small == -1){
		if(sequence[now] > head->large){
			head->small = head->large;
			head->large = sequence[now];
			return head;
		}
		head->small = sequence[now];
		return head;
	}
	if(sequence[now] < head->small){
		head->left = buildtree(head->left , sequence , now);
		return head;
	}
	if(sequence[now] > head->small && sequence[now] < head->large){
		head->mid = buildtree(head->mid , sequence , now);
		return head;
	}
	if(sequence[now] > head->large){
		head->right = buildtree(head->right , sequence , now);
		return head;
	}
}

Node*ConstructTree(int sequence[],int N){
	Node*head = buildtree(NULL , sequence , 0);
	for(int i = 1 ; i < N ; i++){
		head = buildtree(head , sequence , i);
	}
	return head;
}

void PrintTree( Node *root ){
    if (root == NULL)
        return;
    printf("%d %d\n", root->small, root->large);
    PrintTree(root->left);
    PrintTree(root->mid);
    PrintTree(root->right);
    return;
}

int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &sequence[i]);
    Node *tree = ConstructTree( sequence, N );
    PrintTree( tree );
    return 0;
}
