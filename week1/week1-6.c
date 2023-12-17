#include <stdio.h>

int *GetMatrix( int *row, int *col ) ;

int main() {
 int *data, m, n ;
 data = GetMatrix( &m, &n ) ;
 return 0 ;
}//end function


*GetMatrix( int *row, int *col ){
	
	int *value;
	printf("How many row,col ? : ");
	scanf("%d %d", row , col);
	
	value = new int [*row * *col];
	for(int i = 0 ; i < *row ; i++){
		for(int j = 0 ; j < *col ; j++){
			printf("value [%d][%d] \n", i , j);
			scanf("%d",&value[i * *col + j]);
		}//end for	
	}//end for
	
	
	printf("\n ==========================\n");
	
	for(int i = 0 ; i < *row ; i++){
		for(int j = 0 ; j < *col ; j++){
			printf("[%d]", value[i * *col + j]);
		}//end for
		printf("\n");	
	}//end for
	
	return value;
}//end function

