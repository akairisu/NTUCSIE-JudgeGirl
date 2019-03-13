void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384])
{
	int count = 0;
	switch(method){
		case 0:
			while(count < M){
				int check = 0;
				for(int i = 0 ; i < N ; i++){
					if(bucket[i] >= ball[count]){
						result[count] = i;
						bucket[i] -= ball[count];
						check = 1;
						break;
					}
				}
				if(check == 0){
					result[count] = -1;
				}
				count++;
			}
			break;
		case 1:
			while(count < M){
				int min = 2147483647;
				int minbucket = -1;
				for(int i = 0 ; i < N ; i++){
					if(bucket[i] >= ball[count] && bucket[i] < min){
						minbucket = i;
						min = bucket[i];
					}
				}
				if(minbucket == -1){
					result[count] = -1;
				} 
				else {
					result[count] = minbucket;
					bucket[minbucket] -= ball[count]; 
				}
				count++;
			}
			break;
		case 2:
			while(count < M){
				int max = -2147483648;
				int maxbucket = -1;
				for(int i = 0 ; i < N ; i++){
					if(bucket[i] >= ball[count] && bucket[i] >= max){
						maxbucket = i;
						max = bucket[i];
					}
				}
				if(maxbucket == -1){
					result[count] = -1;
				} 
				else {
					result[count] = maxbucket;
					bucket[maxbucket] -= ball[count]; 
				}
				count++;
			}
			break;
	}
} 
