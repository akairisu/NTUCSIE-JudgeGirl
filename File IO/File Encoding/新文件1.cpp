#include<stdio.h>
#include<assert.h> 

int main(void)
{
	FILE *ftest = fopen("test" , "rb");
	assert(ftest != NULL);
	FILE *ftestenc = fopen("test.enc" , "wb");
	assert(ftestenc != NULL);
	char result[65536];
	int key;
	scanf("%d" , &key);
	char c;
	c = fgetc(ftest);
	int count = 0;
	while(!feof(ftest))
	{
		result[count] = c ^ key;
		count++;
		c = fgetc(ftest);
	} 
	fwrite(result , sizeof(char) , count , ftestenc);
	fclose(ftest);
	fclose(ftestenc);
	return 0;
 }

