#include <stdio.h>

struct student {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
} ;

struct student upgrade( struct student child ) ;

int main() {
 struct student aboy ;
 aboy.sex = 'M' ;
 aboy.gpa = 3.00 ;
 aboy = upgrade( aboy ) ;
 printf( " %.2f", aboy.gpa ) ;
 return 0 ;
}//end function

struct student upgrade( struct student child ){
	
	printf("=======BEFORE=======\n") ;
	printf(" %c\n", child.sex) ;
	printf(" %.2f\n", child.gpa) ;
	printf("=======AFTER=======\n") ;
	if(child.sex == 'M'){
		child.gpa  += child.gpa * 0.1 ;
	}else if(child.sex == 'F'){
		child.gpa  += child.gpa * 0.2 ;
	}

	return child ; 
}
