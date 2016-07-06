/* 
* 
* hw3.c
* hw3
* cs149
* john kennedy
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hw3.h"



int main(int argc, char* argv[])
{
	// create the seatmap
	struct Seatmap map;

	// initialize the seatmap 
	initialize_seatmap(&map);
	
	// create the buyers 
	time_t t;
	const int NUM_BUYERS = atoi(argv[1]); 
   	srand((unsigned) time(&t)); // set up the random number generator
	
	// create  10 buyer queues. these are for the sellers.  

	struct Buyer* buyers[10][NUM_BUYERS];
	struct BuyerQueue* bqs[10]; 
	
	// probably should move this out of main, for clarity
	// also sorting the array on input would be needed.  
	for(int i = 0; i < 10;i++)
	{
		char priority;
		// set the priority of the buyer
		switch(i){
			case 0: priority = 'H';
				break;
			case 1:
			case 2: 
			case 3: priority = 'M';
				break;
			default: priority = 'L'; 
		}
		
		for(int j=0;j<NUM_BUYERS;j++)
		{
		
			int arrival_time = (int) rand() % 60;
			buyers[i][j] = createBuyer(priority, j, arrival_time);
			// printf("%c\t%s\t%d\n",buyers[i][j]->priority,buyers[i][j]->name,buyers[i][j]->arrival_time);
			
		}
		// here we create a BuyerQueue and put it in the list of BuyerQueues. 
		// these will be handed to the seller as the seller is started. 
		void* curr = buyers[i];
		
		bqs[i] = init_BuyerQueue(curr, NUM_BUYERS); 
		
	}	
			
	// start the sellers
	// 		pass in the buyer array for each one. 
	//		hold the sellers from running until they are all created.
	 
	// loop while there are still threads
		// update the clock 
		// check for running threads 
			// if none, exit loop
		//check for clock expired
			// if so, exit loop 
		// sleep for a clock tick
	// end loop 

	// no more threads exit
	return(0);
}

