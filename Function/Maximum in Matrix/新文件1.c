int max(int array[5][5])
{
	int max = -2147483648;
	for(int i = 0 ; i < 5 ; i++){
		for(int j = 0 ; j < 5 ; j++){
			if(max < array[i][j]){
				max = array[i][j];
			}
		}
	}
	return max;
}


