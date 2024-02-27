#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
} ;

class LinkedList {
 protected :
  struct studentNode *start, **now ;
 public :

  void InsNode( char n[], int a, char s, float g ) ;
  void DelNode() ;
  void GoNext() ;
  void GoFirst() ;
  void GoLast() ;
  void ShowAll() ;
  int FindNode( char n[] ) ;
  struct studentNode *NowNode() ;
  void EditNode( char n[], int a, char s, float g ) ;
} ; //end class

void EditData( LinkedList *ll ) ;
void AddData( LinkedList *ll ) ;
void FindData( LinkedList *ll ) ;
void readfile( LinkedList *ll ) ;
void writefile( LinkedList *ll ) ;

int main() {
 LinkedList listA ;
 int menu ;
 readfile( &listA ) ;
 printf( "  Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : " ) ;
 scanf( "%d", &menu ) ;
 while( menu != 0 ) {
  switch( menu ) {
   case 1 : AddData( &listA ) ; break ;
   case 2 : EditData( &listA ) ; break ;
   case 3 : listA.DelNode() ; break ;
   case 4 : FindData( &listA ) ; break ;
   case 5 : listA.ShowAll() ; break ;
  }//end switch
  printf( "  Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : " ) ;
  scanf( "%d", &menu ) ;
 }//end while
 writefile( &listA ) ;
 return 0 ;
}//end function

void EditData( LinkedList *ll ){
	FILE *fp;
	fp = fopen("D:/student.txt","a");
	if(fp == NULL){
		printf("Can't open file!");
		exit(0);
	}
	char name[20],sex;
	int age,i;
	float gpa;
	
	printf("Enter Name , Sex , Age and GPA : ");
	scanf("%s %c %d %f",name, &sex,&age,&gpa);
	fprintf(fp,"%s %c %d %f \r\n",name,sex,age,gpa);
	
	fclose(fp);
}
void AddData( LinkedList *ll ){
	FILE *fp;
	fp = fopen("D:/student.txt","w");
	if(fp == NULL){
		printf("Can't open file!");
		exit(0);
	}
	char name[20],sex;
	int age,i;
	float gpa;
	for(i = 0;i<2;i++){
		printf("Enter Name , Sex , Age and GPA : ");
		scanf("%s %c %d %f",name, &sex,&age,&gpa);
		fprintf(fp,"%s %c %d %f \r\n",name,sex,age,gpa);
	}
	fclose(fp);
}
void FindData( LinkedList *ll ){
	FILE *fp;
	fp = fopen("D:/student.txt","r");
	if(fp == NULL){
		printf("Can't open file!");
		exit(0);
	}
	char name[20],sex;
	int age,i;
	float gpa;
	
	fscanf(fp,"%s %c %d %f",name, &sex,&age,&gpa);
	printf("%10s %2c %2d %4.2f\n",name,sex,age,gpa);
	fclose(fp);
}
void readfile( LinkedList *ll ){
}
void writefile( LinkedList *ll ){
}
void LinkedList::DelNode(){
	if (remove("student.txt") == 0)
        printf("Deleted successfully");
    else
        printf("Unable to delete the file");
    return 0;
}
void LinkedList::ShowAll(){
	FILE *fp;
	fp = fopen("D:/student.txt","r");
	if(fp == NULL){
		printf("Can't open file!");
		exit(0);
	}
	char name[20],sex;
	int age,i;
	float gpa;
	for(i = 0;i<4;i++){
		fscanf(fp,"%s %c %d %f",name, &sex,&age,&gpa);
		printf("%d: %10s %2c %2d %4.2f\n",i,name,sex,age,gpa);
	}
	fclose(fp);
}
