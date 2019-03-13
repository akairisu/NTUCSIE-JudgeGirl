#include<stdio.h>
main()
{
    int s, f, t, a, b, c;
    scanf("%d", &s);
    scanf("%d", &f);
    scanf("%d", &t);
    c = s - t;
    s = s - c;
    f = f - 8 * c;
    a = 0;
    b = s - a;
    for(a = 0 ; 2 * a > f- 4 * b ; a++){
          b = s - a;
          if(2 * a == f- 4 * b)
              break;
    }
    if( a < 0 || b < 0 || c < 0 || a + b > s)
        printf("%d" , 0);
        else printf("%d\n%d\n%d\n" , a , b , c );
    return 0;
 }
