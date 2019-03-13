void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[])
{
	int trail[N][M];
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			trail[i][j] = 0;
		}
	}
	int dx[8] = {1 , -1 , 0 , 0 , 1 , -1 , 1 , -1};
	int dy[8] = {0 , 0 , 1 , -1 , 1 , -1 , -1 , 1};
	int stepcount = 0;
	int tempA = 1 , tempB = 1; 
	while(tempA != 0 || tempB != 0){
		if(A_r == B_r && A_c == B_c){
			directionA[stepcount] = -1;
			directionB[stepcount] = -1;
			tempA = 0;
			tempB = 0;
		}
		else {
			if(tempA != 0){
				tempA = 0;
				int max = -2147483648;
				int direction = -1;
				if(trail[A_r][A_c] != 1){
					for(int i = 0 ; i < 8 ; i++){
						if(A_r + dy[i] == N || A_r + dy[i] == -1 || A_c + dx[i] == M || A_c + dx[i] == -1){
							continue;
					}
						else if(map[A_r + dy[i]][A_c + dx[i]] > map[A_r][A_c] && map[A_r + dy[i]][A_c + dx[i]] > max){
							max = map[A_r + dy[i]][A_c + dx[i]];
							direction = i;
							tempA = 1;
						}
					}
				}
				directionA[stepcount] = direction;
				trail[A_r][A_c] = 1;
				if(direction != -1){
					A_r += dy[direction];
					A_c += dx[direction];
				} 
			}
			if(tempB != 0){
				int min = 2147483647;
				int direction = -1;
				tempB = 0;
				if(trail[B_r][B_c] != 1){
					for(int i = 0 ; i < 8 ; i++){
						if(B_r + dy[i] == N || B_r + dy[i] == -1 || B_c + dx[i] == M || B_c + dx[i] == -1){
							continue;
						}
						else if(map[B_r + dy[i]][B_c + dx[i]] < map[B_r][B_c] && map[B_r + dy[i]][B_c + dx[i]] < min){
							min = map[B_r + dy[i]][B_c + dx[i]];
							direction = i;
							tempB = 1;
						}
					}
				}
				directionB[stepcount] = direction;
				trail[B_r][B_c] = 1;
				if(direction != -1){
					B_r += dy[direction];
					B_c += dx[direction];
				} 
			}
		}
		stepcount++;
	}
}

