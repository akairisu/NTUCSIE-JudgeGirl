#include<stdio.h>

int main(void)
{
	int n , m;
	scanf("%d%d" , &n , &m);
	int map[n][n];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			map[i][j] = 0;
		} 
	}
	int x[m] , y[m];
	for(int i = 0 ; i < m ; i++){
		scanf("%d%d" , &y[i] , &x[i]);
		map[y[i]][x[i]] = (i + 1) * 10000;
	}
	int dx[8] ={1 , 2 , 2 , 1 , -1 , -2 , -2 , -1};
	int dy[8] ={-2 , -1 , 1 , 2 , 2 , 1 , -1 , -2};
	int stepcount = 1;
	int k = 0;
	int tempx , tempy;
	int stop[m];
	int stopnumber = 0;
	for(int i = 0 ; i < m ; i++){
		stop[i] = 0;
	}
	while(k == 0){
		for(int i = 0 ; i < m ; i++){
			if(stop[i] == 0){
				int act = -1;
				int stopcount = 0;
				int t = 0;
				int min = -1;
				for(int j = 0 ; j < 8 ; j++){
					tempx = x[i]+dx[j];
					tempy = y[i]+dy[j];
					if(tempx > -1 && tempx < n && tempy> -1 && tempy < n && map[tempy][tempx] == 0){
						int p = 9;
						for(int l = 0 ; l < 8 ; l++){
							if(tempx+dx[l] > -1 && tempx+dx[l] < n && tempy+dy[l] > -1 && tempy+dy[l] < n){
								if(map[tempy+dy[l]][tempx+dx[l]] == 0){
									p--;							
								}
							}
						}
						if(p > min){
							act = j;
							min = p;
						}
					}
					else stopcount++;
				}
				if(stopcount == 8){
					stop[i] = 1;
					stopnumber++;
				}
				else{
					x[i] += dx[act];
					y[i] += dy[act];
					map[y[i]][x[i]] = (i + 1) * 10000 + stepcount;
				}
			}
			else continue;
		}
		stepcount++;
		if(stopnumber == m){
			k = 1;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			printf("%d" , map[i][j]);
			if(j != n-1){
				printf(" ");
			}
		} 
		printf("\n");
	}
	return 0;
 }

