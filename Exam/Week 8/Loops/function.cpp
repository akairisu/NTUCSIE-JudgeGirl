#include <stdio.h>
 
int visited[1000000];
int count[1000000];
int Bpoint[1000000];
 
void loops(int N, int *A, int *B[], int ans[4]){
    int check = 0;
    int start;
    int counter = 0;
    int maxlength = 0;
    int maxnumber = 0;
    int minlength = N + 1;
    int minnumber = 2147483647;
    for(int i = 0 ; i < N ; i++){
        visited[i] = 0;
        count[i] = 0;
    }
    for(int i = 0 ; i < N ; i++){
        Bpoint[i] = B[i] - A;
    }
	int nowstart = 0;
    while(check != 1){
        check = 1;
        for(int i = nowstart ; i < N ; i++){
            if(visited[i] != 1){
                start = i;
                nowstart = i + 1;
                check = 0;
                break;
            }
        }
        if(check == 1){
            continue;
        }
        int check2 = 0;
        int mymax = 0;
        int mymin = 2147483647;
        while(check2 != 1){
            check2 = 1;
            if(visited[Bpoint[start]] != 1){
                check2 = 0;
                count[counter]++;
                if(A[Bpoint[start]] > mymax){
                    mymax = A[Bpoint[start]];
                }
                if(A[Bpoint[start]] < mymin){
                    mymin = A[Bpoint[start]];
                }
                visited[Bpoint[start]] = 1;
                start = Bpoint[start];
            }
            if(visited[Bpoint[start]] == 1){
                if(count[counter] > maxlength){
                    maxlength = count[counter];
                    maxnumber = mymax;
                }
                if(count[counter] == maxlength){
                    if(mymax > maxnumber){
                        maxnumber = mymax;
                    }
                }
                if(count[counter] < minlength){
                    minlength = count[counter];
                    minnumber = mymin;
                }
                if(count[counter] == minlength){
                    if(mymin < minnumber){
                       minnumber = mymin;
                    }
                }
                check2 = 1;
                counter++;
                break;
            }
        }
    }
    ans[0] = maxlength;
    ans[1] = minlength;
    ans[2] = maxnumber;
    ans[3] = minnumber;
}

