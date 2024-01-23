#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void swap(struct studentNode **walk,char sw1[10],char sw2[10]);
struct studentNode *AddNode(struct studentNode **walk, char name[], int age, char sex, float gpa);
void ShowAll(struct studentNode *walk);

int main() {
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11);
    now = AddNode(&start, "two", 8, 'F', 3.22);
    now = AddNode(&start, "three", 3, 'F', 3.33);
    now = AddNode(&start, "four", 4, 'M', 3.44);
    now = AddNode(&start, "five", 5, 'M', 3.55);
    ShowAll(start);
    
    swap(&start,"one","four");
    ShowAll(start);
    return 0;
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

struct studentNode *AddNode(struct studentNode **walk, char name[], int age, char sex, float gpa) {
    while (*walk != NULL) {
        walk = &(*walk)->next;
    }

    *walk = new struct studentNode;
    strcpy((*walk)->name, name);
    (*walk)->age = age;
    (*walk)->sex = sex;
    (*walk)->gpa = gpa;
    (*walk)->next = NULL;

    return *walk;
}

void swap(struct studentNode **walk,char sw1[],char sw2[]){


	if (*walk == NULL || sw1 == NULL || sw2 == NULL) {
        printf("%s","Invalid input for swap.") ;
        return;
    }

    // Check if both nodes are the same
    if (strcmp(sw1, sw2) == 0) {
    	printf("%s","Cannot swap a node with itself.") ;
        return;
    }

	
	

	struct studentNode *prev1 = NULL, *curr1 = *walk;	
	while (curr1 != NULL && strcmp(curr1->name, sw1) != 0) {
        prev1 = curr1;
        curr1 = curr1->next;
    }
    
     struct studentNode *prev2 = NULL, *curr2 = *walk;
    while (curr2 != NULL && strcmp(curr2->name, sw2) != 0) {
        prev2 = curr2;
        curr2 = curr2->next;
    }
    
    if (curr1 == NULL || curr2 == NULL) {
    	printf("%s","One or both of the nodes not found.") ;
        return;
    }

    // Swap nodes
    if (prev1 != NULL) {
        prev1->next = curr2;
    } else {
        *walk = curr2;
    }

    if (prev2 != NULL) {
        prev2->next = curr1;
    } else {
        *walk = curr1;
    }

    struct studentNode *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
/*
	while (*walk != NULL) {

		
        if(strcmp((*walk)->name, sw1) == 0 ){
        	//printf("%s\n",(*walk)->name);
        	temp1 = *walk ;
        	//printf("%s===\n",temp1);
		}
		
		if(strcmp((*walk)->name, sw2) == 0 ){
        	//printf("%s\n",(*walk)->name);
        	temp2 = *walk ;
        	//printf("%s===\n",temp2);
        	
		}
		
		walk = &(*walk)->next;
		
    }
	
	*walk = temp1 ;
	*/

}
