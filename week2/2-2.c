#include "stdio.h"
#include "string.h"

struct human{
	char name[50];
	int age;
};

void sort(struct human Arr[],int n,int mode);
void showresult (struct human Arr[],int n);
float AVGage(struct human Arr[],int n);
void humanAboveage (struct human Arr[],int n,float AVG);

int main(){
    int n = 8;
    int i, j;
    
    struct human person [8];
	strcpy( person[0].name , "jum" );
	strcpy( person[1].name , "jim" );
	strcpy( person[2].name , "jam" );
	strcpy( person[3].name , "jon" );
	strcpy( person[4].name , "jow" );
	strcpy( person[5].name , "jan" );
	strcpy( person[6].name , "joe" );
	strcpy( person[7].name , "jol" );
	
	
	person[0].age = 16;
	person[1].age = 18;
	person[2].age = 20;
	person[3].age = 21;
	person[4].age = 22;
	person[5].age = 16;
	person[6].age = 19;
	person[7].age = 17;

	printf("\n---------------------MODE 1 (0-9)---------------------\n");
	sort(person,n,1);
	showresult(person,n);
	
	
	printf("\n---------------------MODE 2 (9-0)---------------------\n");
	sort(person,n,2);
	showresult(person,n);
	
	
	float AVG = AVGage(person,n);
	printf("\n\n------------------AVG age : %.2f------------------",AVG);
	
	printf("\n\n---------------------Above age---------------------\n");
	humanAboveage(person,n,AVG);
    return 0;
}

void sort(struct human Arr[],int n,int mode){
	int i =0;
	int j;
	struct human hold;
	
	if(mode == 1){
		for (i = 0; i < n; i++){
        	for (j = i + 1; j < n; j++){  // Corrected the loop variable from i to j
            	if (Arr[i].age > Arr[j].age){
           	     hold = Arr[i];
            	 Arr[i] = Arr[j];
           	     Arr[j] = hold;
           	 	}
        	}   
    	}
	}
	
	else if(mode == 2){
		for (i = 0; i < n; i++){
        	for (j = i + 1; j < n; j++){  // Corrected the loop variable from i to j
            	if (Arr[i].age < Arr[j].age){
           	     hold = Arr[i];
            	 Arr[i] = Arr[j];
           	     Arr[j] = hold;
           	 	}
        	}   
    	}
	}else{
		printf("error");
	}
}

void showresult(struct human Arr[],int n){
	int i = 0;

	for(i = 0 ; i < n; i++){
		printf(" %s (%d)",Arr[i].name,Arr[i].age);
	}
}

float AVGage(struct human Arr[],int n){
	float sum = 0;
	int i = 0;

		for(i = 0 ; i < n; i++){
		//printf(" %s (%d)",Arr[i].name,Arr[i].age);
		sum += Arr[i].age;
		
	}
	return sum/n;
}

void humanAboveage (struct human Arr[],int n,float AVG){
	int i ;
	for(i = 0 ; i < n; i++){
		if(Arr[i].age > AVG){
			printf(" %s (%d)",Arr[i].name,Arr[i].age);
		}
	}
}
