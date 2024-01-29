#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void swap(struct studentNode **walk,char sw1[10],char sw2[10]);
struct studentNode *AddNode(struct studentNode **walk, char name[], int age, char sex, float gpa);
void Gonext(struct studentNode *walk);
void Goback(struct studentNode *walk);

int main() {
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11);
    now = AddNode(&start, "two", 8, 'F', 3.22);
    now = AddNode(&start, "three", 3, 'F', 3.33);
    now = AddNode(&start, "four", 4, 'M', 3.44);
    now = AddNode(&start, "five", 5, 'M', 3.55);
    Gonext(start);
    
    printf("\n========After swap======== ");
    swap(&start,"one","five");
	//printf("%s",start->next->back);
	
	Gonext(start);
	Goback(start);
    return 0;
}
//Show All
void Gonext(struct studentNode *walk) {
	
	printf("Gonext \n");
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}


void Goback(struct studentNode *walk) {
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


//Add node
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

void swap(struct studentNode **walk,char sw1[],char sw2[]){

	if (*walk == NULL || sw1 == NULL || sw2 == NULL) {
        printf("%s\n","Invalid input for swap.") ;
        return;
    }

    if (strcmp(sw1, sw2) == 0) {
    	printf("%s\n","Cannot swap a node with itself.") ;
        return;
    }
	//create a node 
	struct studentNode *prev1 = NULL, *curr1 = *walk;	
	while (curr1 != NULL && strcmp(curr1->name, sw1) != 0) {
		//prev1 save value of curr1
		
        prev1 = curr1;
        //curr1 next node
        curr1 = curr1->next;
        
        //printf("%s ", prev1->name);
        //printf("%s ", curr1->name);
        
    }
    
    printf("\n");
    struct studentNode *prev2 = NULL, *curr2 = *walk;	
	while (curr2 != NULL && strcmp(curr2->name, sw2) != 0) {
		//prev1 save value of curr1
        prev2 = curr2;
        //curr1 next node
        curr2 = curr2->next;
        
        //printf("%s ", prev2->name);
        //printf("%s ", curr2->name);
    }
    
    if (prev1 != NULL) {
        prev1->next = curr2;
        curr2->back = prev1;
    } else {
        *walk = curr2;
        curr2->back = NULL;
    }
    
    if (prev2 != NULL) {
        prev2->next = curr1;
        curr1->back = prev2;
    } else {
        *walk = curr1;
        curr1->back = NULL;
    }
    
    struct studentNode *temp1 = curr1->next;
    struct studentNode *temp2 = curr2->next;
    //set sw1 to sw2
    curr1->next = curr2->next;
    temp2->back = curr1;
    //printf("%s\n",curr2);
    //set sw2 to sw1
    curr2->next = temp1;
  	temp1->back = curr2 ;
    
}
