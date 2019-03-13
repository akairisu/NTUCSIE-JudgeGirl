#include<stdio.h> 

int main(void)
{
	int N , M , R , W ;
	scanf("%d%d%d", &N , &M , &R);
	switch(R){
		case 0:
			while(scanf("%d", &W) != EOF){
					if(N >= W){
						N = N - W;
						printf("%d %d\n" , N , M);
					}
					else if(N < W && M>=W){
						M = M - W;
						printf("%d %d\n" , N , M);
					}
					else printf("%d %d\n" , N , M);
			}
			break;
		case 1:
			while(scanf("%d" , &W) != EOF){
				if(N <= M && N >= W){
					N = N - W;
					printf("%d %d\n" , N , M);			
				}
				else if(N < M && N < W && M >= W){
					M = M - W;
					printf("%d %d\n" , N , M);
				}
				else if(M < N && M >= W){
					M = M - W;
					printf("%d %d\n" , N , M);
				}
				else if(M < N && M < W && N >= W){
					N = N - W;
					printf("%d %d\n" , N , M); 
				}
				else printf("%d %d\n" , N , M);
			}
			break;
	}
	return 0;
}
