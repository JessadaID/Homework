#include <stdio.h>

void GetMatrix( int *value[], int *row, int *col ) ;

int main() {
 int *data, m, n ;
 GetMatrix( &data, &m, &n ) ;
 return 0 ;
}//end function

void GetMatrix( int *value[], int *row, int *col ){
	printf("How many row,col ? : ");
	scanf("%d %d", row , col);
	
	*value = new int [*row * *col];
	
	//printf("%d", value);
	
	
	for(int i = 0 ; i < *row ; i++){
		for(int j = 0 ; j < *col ; j++){
			printf("value [%d][%d] \n", i , j);
			scanf("%d", &(*value)[i * *col + j]);
		}	
	}
	
	printf("\n ==========================\n");
	
	for(int i = 0 ; i < *row ; i++){
		for(int j = 0 ; j < *col ; j++){
			printf("[%d]", (*value)[i * *col + j]);
		}
		printf("\n");	
	}
	
}
