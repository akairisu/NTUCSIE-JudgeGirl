#include<stdio.h>
#include<string.h>
#define _COMPONENTPART_H
#define MAXLENGTH 16
#define MAXCOMPONENT 64
typedef struct{
    char name[MAXLENGTH];
    int numComponent;
    int componentPartList[MAXCOMPONENT];
    int price;
}ComponentPart;

int findcomponentprize(int i , ComponentPart list[]){
	if(list[i].price){
		return list[i].price;
	}
	else {
		for(int j = 0 ; j < list[i].numComponent ; j++){
			list[i].price += findcomponentprize(list[i].componentPartList[j] , list);
		}
		return list[i].price;
	}
}

void sort(int n , ComponentPart *list[])
{
	for(int i = n - 1 ; i > 0 ; i--){
		for(int j = i - 1 ; j >= 0 ; j--){
			if(strcmp(list[i]->name , list[j]->name) < 0){
				ComponentPart *temp;
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}

void findPrice(int N,ComponentPart list[]){
	for(int i = 0 ; i < N ; i++){
		if(list[i].numComponent && list[i].price == 0){
			for(int j = 0 ; j < list[i].numComponent ; j++){
				list[i].price += findcomponentprize(list[i].componentPartList[j] , list);
			}
		}
	}
	ComponentPart *ptr[N];
	for(int i = 0 ; i < N ; i++){
		ptr[i] = &list[i];
	}
	sort(N , ptr);
	for(int i = 0 ; i < N ; i++){
		printf("%s %d\n" , ptr[i]->name , ptr[i]->price);
	}
}

int main(){
    int N;
    scanf("%d",&N);
    ComponentPart list[N];
    for(int i=0;i<N;i++){
        scanf("%s%d",list[i].name,&list[i].numComponent);
        if(list[i].numComponent){
            for(int j=0;j<list[i].numComponent;j++)
                scanf("%d",&list[i].componentPartList[j]);
            list[i].price=0;
        }
        else
            scanf("%d",&list[i].price);
    }
    findPrice(N,list);
    return 0;
}
