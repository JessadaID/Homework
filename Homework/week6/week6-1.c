#include <stdio.h>
#include <string.h>

struct studentNode {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
 struct studentNode *back ;
} ;
void InsNode(struct studentNode *walk,char name[],int age,char sex,float gpa);
struct studentNode *AddNode( struct studentNode **walk,char name[],int age,char sex,float gpa ) ;
void ShowAll( struct studentNode *walk ) ;
void GoBack(struct studentNode *walk);
void DelNode(struct studentNode **walk);

int main() {
 struct studentNode *start, *now ;
 start = NULL ;
 now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
 now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
 InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
 InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
 GoBack( now ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 return 0 ;
}//end function

void ShowAll( struct studentNode *walk ) {
 while( walk != NULL ) {
  printf( "%s ", walk->name ) ;
  walk = walk->next ;
 }//end while
 printf( "\n" ) ;
}//end function

struct studentNode *AddNode(struct studentNode **walk, char name[], int age, char sex, float gpa) {
	
	struct studentNode  *temp = NULL ;
    while (*walk != NULL) {
    	temp = *walk ;
        walk = &(*walk)->next;
    }

    *walk = new struct studentNode;
    strcpy((*walk)->name, name);
    (*walk)->age = age;
    (*walk)->sex = sex;
    (*walk)->gpa = gpa;
    
    (*walk)->next = NULL;
    (*walk)->back = temp;

    return *walk;
}

void InsNode(struct studentNode *walk,char name[],int age,char sex,float gpa){
	
	walk->back->next = new struct studentNode;
	strcpy(walk->back->next->name, name);
	walk->back->next->next = walk;
	walk->back->next->back = walk->back;
	walk->back = walk->back->next;
	
}

void GoBack(struct studentNode *walk) {
    // Move to the end of the list
    while (walk != NULL && walk->next != NULL) {
        walk = walk->next;
    }
    //printf("%s ", walk->back->back->back->back->name);

    printf("Goback \n");
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->back;
    }
    printf("\n");
}

void DelNode(struct studentNode **walk){
	struct studentNode *temp;
	
		(*walk)->back->next = (*walk)->next;
		(*walk)->next->back = (*walk)->back;
		
		temp = (*walk)->next;
		
		delete *walk;
		*walk = temp;
}
