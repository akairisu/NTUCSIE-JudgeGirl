#include <stdio.h>
#define MAXN 501
#define MAXO 250000

typedef struct Player{
	int x;
	int y;
	int energy;
}Player;

void pushstone(int map[MAXN][MAXN] , Player *player , int dx , int dy , int N , int M){
	int sum , check , count;
	sum = 0;
	check = 0;
	count = 1;
	while(check == 0){
		if(map[player->y + dy * count][player->x + dx * count] != 0){
			sum += map[player->y + dy * count][player->x + dx * count];
			if(((player->x + dx * (count + 1)) == M)||((player->x + dx * (count + 1)) < 0)||((player->y + dy * (count + 1)) == N)||((player->y + dy * (count + 1)) < 0)){
				check = 2;
			}
		}
		else {
			check = 1;
		}
		count++;
	}
	if(check == 1){
		if(player->energy >= sum){
			int lastweight = 0;
			int nowweight;
			for(int i = 1 ; i < count ; i++){
				nowweight = map[player->y + dy * i][player->x + dx * i];
				map[player->y + dy * i][player->x + dx * i] = lastweight;
				lastweight = nowweight;
			}
			player->x += dx;
			player->y += dy;
			player->energy -= sum;
		}
	}
}

void move(int instruction , int dx[] , int dy[] , int map[MAXN][MAXN] , Player *player , int N , int M){
	if((player->x + dx[instruction] >= 0)&&(player->x + dx[instruction] < M)&&(player->y + dy[instruction] >= 0)&&(player->y + dy[instruction] < N)){
		if(map[player->y + dy[instruction]][player->x + dx[instruction]] == 0){
			map[player->y][player->x] = 0;
			player->x += dx[instruction];
			player->y += dy[instruction];
			map[player->y][player->x] = player->energy;
		}
		else{
			map[player->y][player->x] = 0;
			pushstone(map , player , dx[instruction] , dy[instruction] , N , M);
			map[player->y][player->x] = player->energy;
		}
	}
}

int main(void){
	int N , M;
	scanf("%d%d" , &N , &M);

	int map[MAXN][MAXN];
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			map[i][j] = 0;
		}
	}

	Player player;
	scanf("%d%d%d" , &player.y , &player.x , &player.energy);
	map[player.y][player.x] = player.energy;
	int O;
	scanf("%d" , &O);
	int x , y , weight;
	for(int i = 0 ; i < O ; i++){
		scanf("%d%d%d" , &y , &x , &weight);
		map[y][x] = weight;
	}

	int instruction;
	int dx[5] = {0 , 1 , 0 , -1 , 0};
	int dy[5] = {0 , 0 , 1 , 0 , -1};
	while(scanf("%d" , &instruction) != EOF){
		if(instruction == 0){
			for(int i = 0 ; i < N ; i++){
				for(int j = 0 ; j < M ; j++){
					printf("%d" , map[i][j]);
					if(j != M - 1){
						printf(" ");
					}
					else printf("\n");
				}
			}
		}
		else{
			move(instruction , dx , dy , map , &player , N , M);
		}
	}

	return 0;
}