#include<stdio.h>
 
int main(void)
{
    int x , a , b , c ;
    int y , d , e , f ;
    int N;
    int w , k;
    int l = 0;
    scanf("%d %d %d %d %d %d %d %d %d" , &x , &a , &b , &c , &y , &d , &e , &f , &N);
    for(int i = 0 ; i < N ; i++){
        w = -1;
        k = 0;
        while(w < 0){
            if(l != 0){
                 x = (a * x + b ) % c;
                 y = (d * y + e ) % f;
            }
            if(( x % 3 ) == ( y % 3 ) + 1 || (x % 3 == 0 && y % 3 == 2) ){
                w = 0;
                k++;
                l++;
            }
            if((y % 3 ) == (x % 3) + 1 || (y % 3 == 0 && x % 3 == 2)){
                w = 1;
                k ++;
                l++;
            }
            if(x % 3 == y % 3){
                l++;
                k++;
                continue;
            }
        }
    printf("%d %d\n" , w , k);
    }
    return 0;
 }
