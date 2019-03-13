#include<stdio.h>
 
 int main(void)
{
    int a , b , c , d , e , f , g , h , perimeter , area , temp;
    scanf("%d%d%d%d%d%d%d%d" , &a , &b , &c , &d , &e , &f , &g , &h);
    perimeter = (e - a) * 2 + (f - b) * 2;
    area = (e - a) * (f - b) - (g - a) * (f - h) - (e - c) * (d - b);
    printf("%d\n%d\n" , perimeter , area);
    return 0;
}
