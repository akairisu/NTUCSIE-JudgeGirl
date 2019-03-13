#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
}employee;

int findboss(employee employee[] , int id , int boss[] , int count , int n){
	if(employee[id].boss_id == employee[id].id){
		return count;
	}
	else{
		boss[count] = employee[id].boss_id;
		int nextid;
		for(int i = 0 ; i < n ; i++){
			if(employee[i].id == employee[id].boss_id){
				nextid = i;
				break;
			}
		}
		findboss(employee , nextid , boss , count + 1 , n);
	}
}

int main(void)
{
	int n;
	scanf("%d" , &n);
	employee employee[32];
	for(int i = 0 ; i < n ; i++){
		scanf("%d %s %s %d" , &employee[i].id , employee[i].first_name , employee[i].last_name , &employee[i].boss_id);
	}
	int m;
	scanf("%d" , &m);
	for(int i = 0 ; i < m ; i++){
		char firstname1[32] , firstname2[32] , lastname1[32] , lastname2[32];
		scanf("%s%s%s%s" , firstname1 , lastname1 , firstname2 , lastname2);
		int id1 , id2 , count;
		count = 0;
		for(int j = 0 ; j < n ; j++){
			if(strcmp(employee[j].first_name , firstname1) == 0 && strcmp(employee[j].last_name , lastname1) == 0){
				id1 = j;
				count++;
			}
			if(strcmp(employee[j].first_name , firstname2) == 0 && strcmp(employee[j].last_name , lastname2) == 0){
				id2 = j;
				count++;
			}
			if(count == 2){
				break;
			}
		}
		int bosslist1[32] = {0};
		int bosslist2[32] = {0};
		int count1 , count2;
		int check = 0;
		count1 = findboss(employee , id1 , bosslist1 , 0 , n); 
		count2 = findboss(employee , id2 , bosslist2 , 0 , n);
		for(int i = 0; i < count1 ; i++){
			if(bosslist1[i] == employee[id2].id){
				printf("subordinate\n");
				check++;
				break;
			}
		}
		if(check == 0){
			for(int i = 0; i < count2 ; i++){
				if(bosslist2[i] == employee[id1].id){
					printf("supervisor\n");
					check++;
					break;
				}
			}
			if(check == 0){
				for(int i = 0; i < count1 ; i++){
					for(int j = 0 ; j < count2 ; j++){
						if(bosslist1[i] == bosslist2[j]){
							printf("colleague\n");
							check++;
							break;
						}
					}
					if(check != 0){
						break;
					}
				}
				if(check == 0){
					printf("unrelated\n");
				}
			}
		}
	}
	return 0;
 }

