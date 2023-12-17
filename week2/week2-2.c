#include "stdio.h"
#include "string.h"

char* reverse( char str1[]) ;

int main() {
 char text[ 50 ] = "I Love You" ;
 char *out ;
 out = reverse( text ) ;
}//end function

char* reverse( char str1[]){
	printf("%s\n", str1) ;
	char str2[strlen( str1 )] ;
	for(int i = strlen( str1 ) , j = 0 ; i >= 0; i-- , j++){
		str2[ j ] = str1[ i - 1 ] ;
	}
	printf("%s", str2) ;
	
	return str2 ;
}
