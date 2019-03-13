void prepare_array(int buffer[], int *array[], int row, int column[])
{
	int i = 0;
	for(int j = 0 ; j < row ; j++){
			array[j] = &buffer[i];
			i += column[j];  
		}
} 
