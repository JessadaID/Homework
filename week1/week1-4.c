
#include <stdio.h>

int *GetSet( int *arr[] ) ;

int main() {
 int *data, *num ;
 num = GetSet( &data ) ;
 return 0 ;
}//end function

int *GetSet( int *arr[] ){
	int i,num;
	printf("\ninput your number of member : ");
	scanf("%d",&num);
	int set[num];
	for (i = 0;i < num ; i++){
		printf("\ninput your value of member : ");
		scanf("%d",&arr[i]);
	}
	
	for (i = 0;i < num ; i++){
		printf("\n%d <== from GetSet",arr[i]);
	}
}
