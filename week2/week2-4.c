#include <stdio.h>
#include <string.h>
void explode( char str1[], char splitter, char str2[][10]) ;

int main() {
 char out[ 20 ][ 10 ] ;
 int num ;
 explode( "I/Love/You", '/' , out ) ;
 

    
 return 0 ;
}//end function

void explode( char str1[], char splitter, char str2[][10]){
	int k = 0, j = 0;
	//printf(" %c",splitter); 
	for(int i = 0 ; i < strlen(str1) ; i++){
		if(str1[ i ] == splitter){
			str2[ j ][ k ] = '\0' ;
			j++ ;
			k = 0 ;
		}else{
			//printf(" %c", str1[ i ]) ;
			str2[ j ][ k ] = str1[ i ] ;
			k++ ;
		}
	}
	
	for(int i = 0 ; i <= j ; i++){
		printf("str2[%d] : %s \n",i , str2[ i ]) ;
	}
	
	printf("\ncount = %d", j + 1  ) ;
}
