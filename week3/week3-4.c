#include <stdio.h>
struct student{
	char children [ 20 ][ 10 ] ;
};

void GetStudent( struct student child[][ 10 ], int *room ) ;

int main() {
 struct student children[ 20 ][ 10 ] ;
 int group ;
 GetStudent( children, &group ) ;
 return 0 ;
}//end function

void GetStudent( struct student child[][ 10 ], int *room ){
	printf("Number of room : ") ;
	scanf("%d", room ) ;
	//printf("%d", *room ) ;
	
	for (int i = 0 ; i < *room ; i++ ){
		//printf("%d ",i);
		printf("Room [%d] : \n", i+1 ) ;
		//scanf("%s", child[ i ] ) ;
			for (int j = 0 ; j < 10 ; j++ ){
				//printf("%d ",i);
				printf("Enter student [%d] : ", j+1 ) ;
				scanf("%s", child[ i ][ j ] ) ;
			}
	}//end for
}
