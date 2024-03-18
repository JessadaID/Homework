#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_csv();
void show_data(int en_off, int en_on,int asia_off,struct order orders[]); 

struct order{
	char Region[50];
	char Country[30];
	char iTem_Type[20];
	char Sales_Channel[10];
	char Order_Priority[2];
	char Order_date[20];
	char Order_ID[10];
	char Ship_Date[10];
	int Units_Sold;
	float Unit_Price;
	float Unit_Cost;
	float Total_Revenue;
	float Total_Cost;
	float Total_Profit;
} ;

typedef struct {
    int value;
    int index;
} ValueIndex;

int main(){
	read_csv();
	return 0;
}

void read_csv(){
	char filename[30] = "5000 Sales Records.csv";
	FILE *fp = fopen(filename,"r");
	char *token;
	int array_size = 5000;
	struct order orders[array_size];
	char row[1024];
	
	int eu_unit_sold_most_online = 0 ;
	int eu_unit_sold_most_offline = 0 ;
	int asia_unit_sold_most_offline = 9999 ;
	int address_en_online = 0 ;
	int address_en_offline = 0 ;
	int address_asia_offline = 0 ;
	//max value

	//titel
	fgets(row, 1024, fp);
	
// Read the content and print it
	int i = 0 ;
	while(fgets(row, 1024, fp)) {
 		 //printf("%s", row);
 			
		  token = strtok(row, ",");
      	  strcpy(orders[i].Region,token);
      	  token = strtok(NULL, ",");
      	  strcpy(orders[i].Country,token);
      	  token = strtok(NULL, ",");
      	  strcpy(orders[i].iTem_Type,token);
      	  token = strtok(NULL, ",");
      	  strcpy(orders[i].Sales_Channel,token);
      	  token = strtok(NULL, ",");
      	  strcpy(orders[i].Order_Priority,token);
      	  token = strtok(NULL, ",");
      	  strcpy(orders[i].Order_date,token);
      	  token = strtok(NULL, ",");
      	  strcpy(orders[i].Order_ID,token);
      	  token = strtok(NULL, ",");
      	  strcpy(orders[i].Ship_Date,token);
      	  token = strtok(NULL, ",");
      	  orders[i].Units_Sold  = atoi(token);
      	  token = strtok(NULL, ",");
      	  orders[i].Unit_Price  = atof(token);
      	  token = strtok(NULL, ",");
      	  orders[i].Unit_Cost  = atof(token);
      	  token = strtok(NULL, ",");
      	  orders[i].Total_Revenue  = atof(token);
      	  token = strtok(NULL, ",");
      	  orders[i].Total_Cost  = atof(token);
      	  token = strtok(NULL, ",");
      	  orders[i].Total_Profit  = atof(token);
      	  
      	  //count eu / offline
      	  if(strcmp(orders[i].Region,"Europe") == 0 and strcmp(orders[i].Sales_Channel,"Offline")== 0 and eu_unit_sold_most_online < orders[i].Units_Sold){
      	  		eu_unit_sold_most_offline = orders[i].Units_Sold;
      	  		address_en_offline = i ;
		  }
		  
		  //count eu / online
		  if(strcmp(orders[i].Region,"Europe") == 0 and strcmp(orders[i].Sales_Channel,"Online")== 0 and eu_unit_sold_most_offline < orders[i].Units_Sold){
      	  		eu_unit_sold_most_online = orders[i].Units_Sold;
      	  		address_en_online = i;
		  }
      	  //Asia offline
      	  if(strcmp(orders[i].Region,"Asia") == 0 and strcmp(orders[i].Sales_Channel,"Offline")== 0 and asia_unit_sold_most_offline > orders[i].Units_Sold){
      	  		asia_unit_sold_most_offline = orders[i].Units_Sold;
      	  		address_asia_offline = i ;
		  }
		  
		  if(strcmp(orders[i].Region,"Central America and the Caribbean") == 0 and strcmp(orders[i].Sales_Channel,"Online")== 0){
      	  		
		  }
      	  
      	 
      	  i++;
	}
	
	
	 /*
	printf("In Europe The most Unit sold in Online is : %d\n",eu_unit_sold_most_online);
	printf("In Europe The most Unit sold in Offline is : %d\n",eu_unit_sold_most_offline);
	printf("In Asia The lowest Unit sold in Offline is : %d\n",asia_unit_sold_most_offline);

	printf("Address en in Online is : %d\n",address_en_online);
	printf("Address en in Offline is : %d\n",address_en_offline);
	printf("Address asia in Offline is : %d\n",address_asia_offline);
	*/
	
    
	show_data(address_en_offline,address_en_online,address_asia_offline,orders);
	
	

	
}

void show_data(int en_off, int en_on,int asia_off,struct order orders[]){
	//printf("%d %d %d",en_off,en_on,asia_off);
	int count = 0;
	int array_size = 5000;
	printf("\nIn Europe The most Unit sold in Online is : \n Region : %s \n Country : %s \n iTem_Type : %s \n Sales_Channel : %s \n Order_Priority : %s \n Order_date : %s \n Order_ID : %s \n Ship_Date : %s \n Units_Sold : %d \n Units_Price : %.2f \n Unit_Cost : %.2f \n Total_Revenue : %.2f \n Total_Cost : %.2f \n Total_Profit : %.2f \n",
	orders[en_on].Region,
	orders[en_on].Country,
	orders[en_on].iTem_Type,
	orders[en_on].Sales_Channel,
	orders[en_on].Order_Priority,
	orders[en_on].Order_date,
	orders[en_on].Order_ID,
	orders[en_on].Ship_Date,
	orders[en_on].Units_Sold,
	orders[en_on].Unit_Price,
	orders[en_on].Unit_Cost,
	orders[en_on].Total_Revenue,
	orders[en_on].Total_Cost,
	orders[en_on].Total_Profit
	);
	
	printf("\n=======================================\n");
	
	printf("\nIn Europe The most Unit sold in Offline is : \n Region : %s \n Country : %s \n iTem_Type : %s \n Sales_Channel : %s \n Order_Priority : %s \n Order_date : %s \n Order_ID : %s \n Ship_Date : %s \n Units_Sold : %d \n Units_Price : %.2f \n Unit_Cost : %.2f \n Total_Revenue : %.2f \n Total_Cost : %.2f \n Total_Profit : %.2f \n",
	orders[en_off].Region,
	orders[en_off].Country,
	orders[en_off].iTem_Type,
	orders[en_off].Sales_Channel,
	orders[en_off].Order_Priority,
	orders[en_off].Order_date,
	orders[en_off].Order_ID,
	orders[en_off].Ship_Date,
	orders[en_off].Units_Sold,
	orders[en_off].Unit_Price,
	orders[en_off].Unit_Cost,
	orders[en_off].Total_Revenue,
	orders[en_off].Total_Cost,
	orders[en_off].Total_Profit
	);
	
	printf("\n=======================================\n");
	
	printf("\nIn Asia The lowest Unit sold in Offline is : \n Region : %s \n Country : %s \n iTem_Type : %s \n Sales_Channel : %s \n Order_Priority : %s \n Order_date : %s \n Order_ID : %s \n Ship_Date : %s \n Units_Sold : %d \n Units_Price : %.2f \n Unit_Cost : %.2f \n Total_Revenue : %.2f \n Total_Cost : %.2f \n Total_Profit : %.2f \n",
	orders[asia_off].Region,
	orders[asia_off].Country,
	orders[asia_off].iTem_Type,
	orders[asia_off].Sales_Channel,
	orders[asia_off].Order_Priority,
	orders[asia_off].Order_date,
	orders[asia_off].Order_ID,
	orders[asia_off].Ship_Date,
	orders[asia_off].Units_Sold,
	orders[asia_off].Unit_Price,
	orders[asia_off].Unit_Cost,
	orders[asia_off].Total_Revenue,
	orders[asia_off].Total_Cost,
	orders[asia_off].Total_Profit
	);
	
	// top ten amea
	int g, h;
	struct order temp;
	  for (g = 0; g < array_size - 1; g++) {
	    for (h = 0; h < array_size - g - 1; h++) {
	      if (orders[h].Unit_Cost < orders[h+1].Unit_Cost) {
	        temp = orders[h];
	        orders[h] = orders[h + 1];
	        orders[h + 1] = temp;
	      }
	    }
	  }
	
	printf("\n==============TOP 10 MOST Unit Cost of Central America and the Caribbean in Online==============\n");
	for(int i = 0 ; i < array_size ; i++){
		if(strcmp(orders[i].Region,"Central America and the Caribbean") == 0 and strcmp(orders[i].Sales_Channel,"Online")== 0 ){
			printf("\nIn Central America and the Caribbean The most Unit Cost in Online is : \n Region : %s \n Country : %s \n iTem_Type : %s \n Sales_Channel : %s \n Order_Priority : %s \n Order_date : %s \n Order_ID : %s \n Ship_Date : %s \n Units_Sold : %d \n Units_Price : %.2f \n Unit_Cost : %.2f \n Total_Revenue : %.2f \n Total_Cost : %.2f \n Total_Profit : %.2f \n",
				orders[i].Region,
				orders[i].Country,
				orders[i].iTem_Type,
				orders[i].Sales_Channel,
				orders[i].Order_Priority,
				orders[i].Order_date,
				orders[i].Order_ID,
				orders[i].Ship_Date,
				orders[i].Units_Sold,
				orders[i].Unit_Price,
				orders[i].Unit_Cost,
				orders[i].Total_Revenue,
				orders[i].Total_Cost,
				orders[i].Total_Profit
	
	);
			count++;
		}
		if(count == 10){
			break;
		}
		
	}
	printf("\n=================================================================\n");
	
}

