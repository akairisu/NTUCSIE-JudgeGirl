void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[])
{
	int n = 0;
	while(n == 0 || directionA[n - 1] != -1){
		int max = -2147483648;
		int direction = -1;
		for(int i = 0 ; i < 8 ; i++){
			switch(i){
				case 0:
					if(A_c + 1 = M){
						continue;
					}
					else if(map[A_r][A_c + 1] > map[A_r][A_c] && map[A_r][A_c + 1] > max){
						max = map[A_r][A_c + 1] ;
						direction = 0;
					}
					break;
				case 1:
					if(A_c - 1 = -1){
						continue;
					}
					else if(map[A_r][A_c - 1] > map[A_r][A_c] && map[A_r][A_c - 1] > max){
						max = map[A_r][A_c - 1] ;
						direction = 1;
					}
					break;
				case 2:
					if(A_r + 1 = N){
						continue;
					}
					else if(map[A_r + 1][A_c] > map[A_r][A_c] && map[A_r + 1][A_c] > max){
						max = map[A_r + 1][A_c] ;
						direction = 2;
					}
				case 3:
					if(A_r - 1 = -1){
						continue;
					}
					else if(map[A_r - 1][A_c] > map[A_r][A_c] && map[A_r - 1][A_c] > max){
						max = map[A_r - 1][A_c] ;
						direction = 3;
					}
				case 4:
					if(A_r + 1 = N || A_c + 1 = M){
						continue;
					}
					else if(map[A_r + 1][A_c + 1] > map[A_r][A_c] && map[A_r + 1][A_c + 1] > max){
						max = map[A_r + 1][A_c + 1];
						direction = 4;
					}
				case 5:
					if(A_r - 1 = -1 || A_c - 1 = -1){
						continue;
					}
					else if(map[A_r - 1][A_c - 1] > map[A_r][A_c] && map[A_r - 1][A_c - 1] > max){
						max = map[A_r - 1][A_c - 1];
						direction = 5;
					}
				case 6:
					if(A_r - 1 = -1 || A_c + 1 = M){
						continue;
					}
					else if(map[A_r - 1][A_c + 1] > map[A_r][A_c] && map[A_r - 1][A_c + 1] > max){
						max = map[A_r - 1][A_c + 1];
						direction = 6;
					}
				case 7:
					if(A_r + 1 = N || A_c - 1 = -1){
						continue;
					}
					else if(map[A_r + 1][A_c - 1] > map[A_r][A_c] && map[A_r + 1][A_c - 1] > max){
						max = map[A_r + 1][A_c - 1];
						direction = 7;
					}
			}
		}
		directionA[n] = direction;
		n++;
	}
	int n = 0;
	while(n == 0 || directionB[n - 1] != -1){
		int min = 2147483647;
		int direction = -1;
		for(int i = 0 ; i < 8 ; i++){
			switch(i){
				case 0:
					if(A_c + 1 = M){
						continue;
					}
					else if(map[A_r][A_c + 1] < map[A_r][A_c] && map[A_r][A_c + 1] < min){
						min = map[A_r][A_c + 1] ;
						direction = 0;
					}
					break;
				case 1:
					if(A_c - 1 = -1){
						continue;
					}
					else if(map[A_r][A_c - 1] < map[A_r][A_c] && map[A_r][A_c - 1] < min){
						min = map[A_r][A_c - 1];
						direction = 1;
					}
					break;
				case 2:
					if(A_r + 1 = N){
						continue;
					}
					else if(map[A_r + 1][A_c] < map[A_r][A_c] && map[A_r + 1][A_c] < min){
						min = map[A_r + 1][A_c] ;
						direction = 2;
					}
				case 3:
					if(A_r - 1 = -1){
						continue;
					}
					else if(map[A_r - 1][A_c] < map[A_r][A_c] && map[A_r - 1][A_c] < min){
						min = map[A_r - 1][A_c] ;
						direction = 3;
					}
				case 4:
					if(A_r + 1 = N || A_c + 1 = M){
						continue;
					}
					else if(map[A_r + 1][A_c + 1] < map[A_r][A_c] && map[A_r + 1][A_c + 1] < min){
						min = map[A_r + 1][A_c + 1];
						direction = 4;
					}
				case 5:
					if(A_r - 1 = -1 || A_c - 1 = -1){
						continue;
					}
					else if(map[A_r - 1][A_c - 1] < map[A_r][A_c] && map[A_r - 1][A_c - 1] < min){
						min = map[A_r - 1][A_c - 1];
						direction = 5;
					}
				case 6:
					if(A_r - 1 = -1 || A_c + 1 = M){
						continue;
					}
					else if(map[A_r - 1][A_c + 1] < map[A_r][A_c] && map[A_r - 1][A_c + 1] < min){
						min = map[A_r - 1][A_c + 1];
						direction = 6;
					}
				case 7:
					if(A_r + 1 = N || A_c - 1 = -1){
						continue;
					}
					else if(map[A_r + 1][A_c - 1] < map[A_r][A_c] && map[A_r + 1][A_c - 1] < min){
						min = map[A_r + 1][A_c - 1];
						direction = 7;
					}
			}
		}
		directionA[n] = direction;
		n++;
	}
}
