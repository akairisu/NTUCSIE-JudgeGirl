#include<stdio.h>

int main(void)
{
	int n, m;
	scanf("%d%d" , &n , &m);
	int ready[n];
	int arrive[m];
	int tasknum[m];
	int taskmachine[m][500];
	int tasktime[m][500];
	int nowtask[m];
	int k = 0;
	while(k < n){
		ready[k] = 0;
		k++;
	}
	k = 0;
	while(k < m){
		nowtask[k] = 0;
		k++;
	}
	for (int i = 0; i < m; i++){
		scanf("%d" , & arrive[i]);
		scanf("%d" , & tasknum[i]);
		for(int j = 0 ; j < tasknum[i] ; j++){
			scanf("%d" , & taskmachine[i][j]);
			scanf("%d" , & tasktime[i][j]);
		}
	}
	int totaltask = 0;
	for (int i = 0; i < m; i++){
		totaltask += tasknum[i];
	}
	int exejob;
	int t;
	for (int i = 0; i < totaltask; i++){
		int mintime = 100000;
		for (int j = 0; j < m; j++){
			if (nowtask[j] == tasknum[j]){
				continue;
			}
			t = (arrive[j] >= ready[taskmachine[j][nowtask[j]]]) ? arrive[j] : ready[taskmachine[j][nowtask[j]]];
			if(t + tasktime[j][nowtask[j]] < mintime){
				exejob = j;
				mintime = t + tasktime[j][nowtask[j]];
			}
		}
		arrive[exejob] = mintime;
		ready[taskmachine[exejob][nowtask[exejob]]] = mintime;
		nowtask[exejob]++;
	}
		for(int i = 0 ; i < m ; i++){
			printf("%d\n" , arrive[i]);
		}
	return 0;
}
