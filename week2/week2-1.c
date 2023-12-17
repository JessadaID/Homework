#include "stdio.h"
#include "string.h"

void reverse( char str1[], char str2[] ) ;

int main() {
 char text[ 50 ] = "Hello World" ;
 char out[ 50 ] ;
 reverse( text, out ) ;
}//end function

void reverse( char str1[], char str2[] ){
	printf("%s\n", str1);
	for(int i = strlen( str1 ) , j = 0 ; i >= 0 ; i-- , j++){
		str2[ j ] = str1[ i - 1 ];
	}//end for
	printf("%s", str2);
}//end function
