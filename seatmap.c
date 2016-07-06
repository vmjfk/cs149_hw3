/* 
*
* seatmap.c
* hw3 cs149
* john kennedy
*
*/ 

#include "seatmap.h"
#include <stdio.h>
#include <string.h>

// function sell_seat()
// function to return the next available seat
// inputs: customer name 
// output: a seat number, or -1 if none available
int sell_seat(struct Seatmap* map, char* name)
{
	// seller threads will execute this function to get seats
	// only one seller at a time can execute 
	
	// get the mutex
		// if mutex not available, wait. 
		
	//entered critical region
	
	// place customer name on map at next available seat for the 
	// priority
	int seat_num = set_seat(map, name);

	// if seat_num = -1, no more seats available
	// release mutex
	
	return seat_num; 
}

// a routine to print the seat map 
void print_seatmap(struct Seatmap* map)
{
	// go through the seats and print them. 
	for(int row =0; row < NUM_OF_ROWS; row++)
	{
		printf("ROW: %d\t", row); 
		for(int seat = 0; seat < SEATS_PER_ROW; seat++)
		{
			printf("%s\t", map->seatmap[row][seat]);
		}
		printf("\n");
	}
}

// a routine to set all the seat owners to ----
void initialize_seatmap(struct Seatmap* map)
{
	for(int row =0; row < NUM_OF_ROWS; row++)
	{ 
		for(int seat = 0; seat < SEATS_PER_ROW; seat++)
		{
			strcpy(map->seatmap[row][seat],"----");
		}
	}
}
// a routine to manage the seat sales
// uses pointers to determine where the remaining seats are 
// return -1 if no seats left, 0 if seat set
int set_seat(struct Seatmap* map, char* name)
{
	// figure out the section by stripping the buyer name first char
	char section = name[0]; 
	
	int seat_ptr, end_ptr, jump; 
	switch(section) { 
		case 'H': 
			seat_ptr = 0; 	
			end_ptr = 100; // the first seat this ptr can't go to . 
			jump = 1;		// this pointer increments 
			break; 
		case 'M':
			seat_ptr = 40; 
			end_ptr = 100;
			jump = 1;
			break;
		case 'L': 
			seat_ptr = 99;
			end_ptr = 69; 
			jump = -1; 	// this one goes backwards.  
			
	}
	
	// start iterating through the seats to find an available one. 
	
	int row = (int) seat_ptr / 10; 
	int seat = seat_ptr - row; 
	int eq = strcmp(map->seatmap[row][seat],"----");
	
	while(eq == 0) // seat is taken and more are left
	{
		seat_ptr += jump; // inc or dec the seat ptr as necessary
		if(seat_ptr == end_ptr) return -1; // ran out of seats to check. 
		row = (int) seat_ptr /10; 
		seat = seat_ptr - row; 
		eq = strcmp(map->seatmap[row][seat],"----");
	}
	
	// if we got hear, we set the seat
	return 0; 
}
 
