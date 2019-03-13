#include <stdio.h>
#include<string.h>
#define MAXP 1024

typedef struct {
    char journalName[64];
    int numCitedPaper;
    int citedPaperIndex[1024];
} paper;

typedef struct ImpactFactor{
	char journalname[64];
	int papernumber;
	int citednum;
}IF;

void checkpapernum(char string , IF journal[], int *count){
	for(int i = 0 ; i < *count ; i++){
		if(strcmp(string , journal[i].journalname) == 0){
			journal[i].papernumber++;
			return;
		}
	}
	strcpy(journal[*count].journalname , string);
	*count++;
	return;
}

void compute(paper P[], int N){
	IF papernumber[N];
	int *count;
	*count = 0;
	for(int i = 0 ; i < N ; i++){
		checkpapernum(P[i].journalName , papernumber, count);
	}
	
}

int main() {
    int N;
    paper P[MAXP] = {};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s%d", P[i].journalName, &P[i].numCitedPaper);
        for (int j = 0; j < P[i].numCitedPaper; j++)
            scanf("%d", &P[i].citedPaperIndex[j]);
    }
    compute(P, N);
    return 0;
}
