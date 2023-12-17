
#include <stdio.h>
int *GetSet( int *num ) ;

int main() {
 int *data, num,i ;
 data = GetSet( &num ) ;

 return 0 ;
}//end function

int *GetSet( int *num ){
	int i ;
	printf("\ninput your size set : ") ;
	scanf("%d",num) ;
	int set[ *num ] ;
	for (i = 0;i < *num ; i++){
		printf("\ninput your value of set : ") ;
		scanf("%d", &set[ i ]) ;
	}//end for
	
	for (i = 0;i < *num ; i++){
		printf("\n%d <== from getset", set[ i ]) ;
	}//end for
	return set ;
}//end function
