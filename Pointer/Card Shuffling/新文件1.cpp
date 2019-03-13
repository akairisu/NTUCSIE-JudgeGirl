#include<stdio.h> 

void shuffle(int *deck[])
{
	int number = 0;
	while(deck[number] != NULL){
		number++;
	}
	int *newdeck[number];
	int *point[2];
	point[0] = deck[0];
	point[1] = deck[number - number / 2];
	for(int i = 0 ; i < number ; i++){
		if(i % 2 == 0){
			newdeck[i] = point[0];
			point[0]++;
		}
		if(i % 2 != 0){
			newdeck[i] = point[1];
			point[1]++;
		}
	}
	for(int i = 0 ; i < number ; i++){
		deck[i] = newdeck[i];
	}
}

void print(int *deck[])
{
	int i = 0;
	while(deck[i] != NULL){
		if(i != 0){
			printf(" ");
		}
		printf("%d" , *deck[i]);
		i++;
	}
}
