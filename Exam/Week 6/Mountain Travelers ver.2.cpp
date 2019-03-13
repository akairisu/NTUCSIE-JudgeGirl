void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[])
{
	int positionAx[1024];
	int positionAy[1024];
	int dx[8] = { 1 , -1 , 0 , 0 , 1 , -1 , -1 , 1};
	int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1};
	int n = 0;
	int tempA = 1;
	while(n == 0 || tempA == 1){
		int max = -2147483648;
		int direction = -1;
		tempA = 0;
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
		directionA[n] = direction;
		positionAx[n] = A_r;
		positionAy[n] = A_c;
		if(direction != -1){
			A_r += dy[direction];
			A_c += dx[direction];
		} 
		n++;
	}
	int m = 0;
	int tempB = 1;
	while(m == 0 || tempB == 1){
		int min = 2147483647;
		int direction = -1;
		tempB = 0;
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
		for(int i = 0 ; i < n ; i++){
			if(B_r == positionAy[i] && B_c == positionAx[i]){
				if(m > i){
					direction = -1;
					tempB = 0;
					break;
				}
				if(m == i){
					direction = -1;
					tempB = 0;
					directionA[i + 1] = -1;
					break;
				}
				if(m < i){
					directionA[i + 1] = -1;
					for(int j = i + 1 ; j < n ; j++){
						positionAy[j] = -1;
						positionAx[j] = -1;
					}
					break;
				}
			}
		}
		directionB[m] = direction;
		if(direction != -1){
			B_r += dy[direction];
			B_c += dx[direction];
		} 
		m++;
	}
}
