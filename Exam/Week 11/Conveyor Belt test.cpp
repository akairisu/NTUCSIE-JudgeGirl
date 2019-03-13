#include<stdio.h>
#define MAXSIZE 1048576

long long int save[MAXSIZE];
long long int MSB[MAXSIZE];

void transmission(long long int belt[],int N,int T)
{
	for(int i = 0 ; i < N ; i++){
		save[i] = belt[i];
	}
	for(int i = 0 ; i < N ; i++){
		belt[i] = save[(i + (T / 64) % N) % N];
	}
	T = T % 64;
	for(int i = 0 ; i < T ; i++){
		for(int j = 0 ; j < N ; j++){
			MSB[j] = (belt[j] >> 63) & 1;
			belt[j] = belt[j] << 1;
		}
		for(int j = 0 ; j < N ; j++){
			belt[j] |= MSB[(j + 1) % N];
		}
	}
}

long long int belt[MAXSIZE];
int main(){
    int N,T;
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++)
        scanf("%lld",&belt[i]);
    transmission(belt,N,T);
    for(int i=0;i<N;i++)
        printf("%lld%s",belt[i],i==N-1?"":" ");
    return 0;
}

