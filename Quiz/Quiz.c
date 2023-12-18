#include <stdio.h>

void printresult (char Operator, int A[] , int B[], int Answer[]) ;

int main(){
	int A[ 6 ] ;
	int B[ 6 ] ;
	int Answer[ 7 ] ;
	int i = 0 ; 
	int j = 0 ;
	int k = 5 ;
	int holdA[ 7 ] ;

	char Operator ; 
	
	//==Section 1 
	printf("Enter number A : \n") ;
	do{
		printf("A[%d] : ", i ) ;
		scanf("%d", &A[ i ]) ;
		holdA[ i ] = A[ i ] ;
		//printf("%d",A[ i ]) ; 
		i++ ; 
	} while( i < 6 ) ; //end do while
	
	//==Section 2 
	
	printf("Enter number B : \n") ;
	do{
		printf("A[%d] : ", j ) ;
		scanf("%d", &B[ j ]) ;
		
		//printf("%d",B[ j ]) ; 
		j++ ; 
	} while( j < 6 ) ; //end do while
	
	//==Section 3
	printf("Operator : \n") ;
	scanf(" %c", &Operator) ;
	
	//==Section 4
	Answer[ 0 ] = 0 ;
	
	if(Operator == '+'){
		do{
			//printf("%d",k);
			
			Answer[ k + 1 ] = A[ k ] + B[ k ] ; 
			
			if(Answer[ k + 1 ] >= 10 ){
				A[ k -1 ] +=  1 ;
				Answer[ k + 1 ] -= 10 ;
				if( k == 0 ){
					Answer[ k ] += 1;
				}//end if
			}//end if
			
			k-- ;
		} while( k >= 0 ) ; //end do while
		printresult(Operator, holdA, B, Answer) ; 
	}// end if
	
	
	//==Section 5 
	if(Operator == '-'){
		//diff positive
		do{
				Answer[ k + 1 ] = A[ k ] - B[ k ] ; 
				if(Answer[ k + 1 ] < 0 ){
					A[ k -1 ] -=  1 ;
					if(k >= 0){
						A[ k ] += 10 ;	
					}
					Answer[ k + 1 ] = A[ k ] - B[ k ] ; 
				}//end if
			
			k-- ;
		} while( k >= 0 ) ; //end do while
		printresult(Operator, holdA, B, Answer) ; 
	}// end if
	
}

	//==Section 6
void printresult (char Operator, int A[] , int B[], int Answer[]){

	printf("\n\nindex \t\tx\t0\t1\t2\t3\t4\t5\n\n") ;
	printf("Number A : \t\t%d\t%d\t%d\t%d\t%d\t%d\n", A[ 0 ], A[ 1 ], A[ 2 ], A[ 3 ], A[ 4 ], A[ 5 ]) ;
	printf("Operator : \t\t\t\t\t\t\t\t %c\n", Operator) ;
	printf("Number B : \t\t%d\t%d\t%d\t%d\t%d\t%d\n", B[ 0 ], B[ 1 ], B[ 2 ], B[ 3 ], B[ 4 ], B[ 5 ]) ;
	printf("----------------------------------------------------------------------------------------\n") ; 
	printf("Answer : \t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",Answer[ 0 ], Answer[ 1 ], Answer[ 2 ], Answer[ 3 ], Answer[ 4 ], Answer[ 5 ], Answer[ 6 ]) ; 
	printf("========================================================================================\n") ; 
}//end function





