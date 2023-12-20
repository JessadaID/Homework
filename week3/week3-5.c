#include <stdio.h>

struct student{
	char children [ 20 ][ 10 ] ;
};

struct student (*GetStudent( int *room ) )[ 10 ] ;

int main() {
 struct student ( *children )[ 10 ] ;
 int group ;
 children = GetStudent( &group ) ;
 return 0 ;
}//end function

struct student (*GetStudent( int *room ) )[ 10 ]{
	printf("Enter the number of room : ");
    scanf("%d", room);
    
    struct student children[10];

	for (int i = 0; i < *room; ++i) {
		printf("Room [%d] : ", i+1 ) ;
		scanf("%s",&children[ i ]);
	}
	printf("\n=====Result=====\n") ;
	for (int i = 0; i < *room; ++i) {
		printf("Room [%d] is : %s \n", i+1 , children[ i ]) ;
		
	}
};
