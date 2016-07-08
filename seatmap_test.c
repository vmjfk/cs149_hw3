/* 
*
* seatmap_test.c
* hw3 cs149
* john kennedy
*
*/ 
#include "seatmap.h"
#include <stdio.h>


/*

int sell_seat(struct Seatmap* map, struct Buyer* b);

// function to set a seat as sold, or return error if no more seats
int set_seat(struct Seatmap* map, struct Buyer* b);


//function to printout the seat map in ascii
void print_seatmap(struct Seatmap* map);

// constructor for seatmap 
void initialize_seatmap(struct Seatmap* map);

*/


int main(int argc, char* argv[])
{
	// make a seatmap 
	struct Seatmap smap; 
	struct Seatmap* map = &smap; 
	initialize_seatmap(map);

	// fill it up
	char priority;  
	for(int i = 0; i < 100; i++)
	{
		if(i < 10)
		{
			priority = 'H';
		}else if(i>=10 && i < 40){
			priority = 'M';
		}else{
			priority = 'L';
		}
		char seller_name[10]; 
		seller_name[0] = priority;
		
		struct Buyer* b =  createBuyer(priority,seller_name,i, i);	
		int isSeated = sell_seat(map,b);
		if(isSeated == 0)
		{
			printf("Sold seat %d to buyer %s\n",isSeated, b->name);
		}else{
			printf("No Sold seat to buyer %s\n",b->name);
		}
	}

	//print it out. 

	print_seatmap(map);

	printf("end of main()\n");

}
