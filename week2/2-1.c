#include "stdio.h";

int main(){
	int n;
    int i;
    char mode,sort,runagain;
    
    while(1){
    
        //==Section 1
        printf("input your highest number : ");
        scanf("%d",&n);
        
        for ( i = 0;i<n;i++){
            printf("%d  ",i+1);
        }
        
        //==Section 2
        while(1){
        
            printf("\n odd (o) / even (e) / normal (n)\n");
            scanf( " %c",&mode);
            if(mode == 'e'){
                for ( i = 1;i<n;i++){
                    if(i %2 == 0){
                         printf("%d  ",i);   
                    }
                }
                break;
            }
            
            if(mode == 'o'){
                for ( i = 1;i<n;i++){
                    if(i %2 != 0){
                         printf("%d  ",i);   
                    }
                }
                break;
            }
            
            if(mode == 'n'){
                for ( i = 0;i<n;i++){
                         printf("%d  ",i+1);       
                }
                break;
            }
        }//end while
         
        //==Section 3
        while(1){
              
            	printf("\ninput your sort (a) less to most / (z) most to less\n");
            	scanf( " %c",&sort);
            	
            	if(sort == 'a'){
                
        			while(1){
                    
            			printf("\n odd (o) / even (e) / normal (n)\n");
           				 scanf( " %c",&mode);
            			if(mode == 'e'){
             			   for ( i = 0;i<n;i++){
             			       if(i %2 != 0){
              			           printf("%d  ",i+1);   
              			      }
             			   }
            			break;
            			}
                    
           			 	if(mode == 'o'){
            			    for ( i = 0;i<n;i++){
           			         	if(i %2 == 0){
           			              	printf("%d  ",i+1);   
           			         	}
           			     	}
          			    break;
          			  	}
                    
           			 	if(mode == 'n'){
            			    for ( i = 0;i<n;i++){
            			        printf("%d  ",i+1);       
            			    }
           				break;
           			 	}
                    
    				}//end while
            	break;   
      			}
            
            	if (sort == 'z'){
                
        	        while(1){
                    
                        printf("\n odd (o) / even (e) / normal (n)\n");
                        scanf( " %c",&mode);
                        if(mode == 'e'){
                            for ( i = n-1;i>=0;i--){
                                if(i %2 != 0){
                                printf("%d  ",i+1);   
                                }
                            }
                        break;
                        }
                    
                        if(mode == 'o'){
                            for ( i = n-1;i>=0;i--){
                                if(i %2 == 0){
                                printf("%d  ",i+1);   
                                }
                            }
                        break;
                        }
                    
                        if(mode == 'n'){
                            for ( i = n-1;i>=0;i--){
                                    printf("%d  ",i+1);       
                            }
                        break;
                        }
                    
                    }//end while 
            	break;
            	}   
        }//end while
     	printf("\nDo you want run program again? (y/n)? : ");
    	scanf( " %c",&runagain);
    	
    	if(runagain == 'n'){
    		break;
		}
	}
}//end main
