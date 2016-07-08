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
#include <unistd.h>
#include <pthread.h>
#include "hw3.h"

#define NUM_SELLERS 10


pthread_cond_t cond = PTHREAD_COND_INITIALIZER; 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// create the seatmap

int main(int argc, char* argv[])
{

	struct Seatmap* map = (struct Seatmap*)malloc(sizeof(struct Seatmap));

	// initialize the seatmap 
	initialize_seatmap(map);
	map->mutex = &mutex; 
	map->cond = &cond; 

	
	
	// create the buyers 
	time_t t;
	const int NUM_BUYERS = atoi(argv[1]); 
   	srand((unsigned) time(&t)); // set up the random number generator
	
	// create   buyer queues. these are for the sellers.  

	struct Buyer* buyers[NUM_SELLERS][NUM_BUYERS];
	struct BuyerQueue* bqs[NUM_SELLERS]; 
	struct Seller* sellers[NUM_SELLERS]; 
	

	
	// probably should move this out of main, for clarity
	// also sorting the array on input would be nice.  
	for(int i = 0; i < NUM_SELLERS;i++)
	{
		int ordinal; 	// number for sellers. 
		
		char priority;
		// set the priority of the seller and buyer
		if(i == 0) 
		{
			priority = 'H';
			ordinal = 1;
		}else if(i < 4)
		{
			priority = 'M';
			ordinal = i;
		}else{
			priority = 'L'; 
			ordinal = i -3;
		}
	
		char seller_name[4] = ""; 
		seller_name[0] = priority;
		
		char cord[2];
		sprintf(cord,"%d",ordinal);
	
		strcat(seller_name,cord); 
		
		
		for(int j=0;j<NUM_BUYERS;j++)
		{
		
			int arrival_time = (int) rand() % 60;

			buyers[i][j] = createBuyer(priority, seller_name, j, arrival_time);

			
			
		}
		// here we create a BuyerQueue and put it in the list of BuyerQueues. 
		// these will be handed to the seller as the seller is started. 
		void* curr = buyers[i];
		
		bqs[i] = init_BuyerQueue(curr, NUM_BUYERS); 

		printBuyerQueue(bqs[i]);
		
		// creating seller struct
		sellers[i] = createSeller(priority, ordinal, bqs[i], map);
		
	};

	print_seatmap(map);
			
	// start the sellers
	// 		pass in the seller struct. 
	//		hold the sellers from running until they are all created.
	pthread_t tids[NUM_SELLERS];
	// spawn threads
	

	for(int i = 0; i < NUM_SELLERS; i++)
	{
		struct Seller* next = sellers[i];

		pthread_t cur; 
		pthread_create(&cur, NULL, sell, next);
		tids[i] = cur;

	} 

	sleep(2); 
	wakeup_all_seller_threads();
		// wait for all seller threads to exit     
	for (int i = 0 ; i < NUM_SELLERS ; i++)
	{
		pthread_t cur = tids[i];
		pthread_join(cur, NULL);
	
	}
	
	// all threads are dead. printf report
	print_seatmap(map);
	
	for(int i = 0;i < NUM_SELLERS;i++)
	{
		// for each seller, print the customers who did not get tickets. 
		struct Seller* s = sellers[i];
		printf("Report for seller %s:\n", s->name);
		printf("Seller %s has %d customers who did not get tickets.\n",s->name, s->q->count);
		printf("Seller %s has %d customers who got tickets.\n",s->name, s->q->head);

	}
		 
	printf("exiting\n");
	fflush(stdout);


	// no more threads exit
	return(0);
}

void wakeup_all_seller_threads() {    
	printf("waking up seller threads\n"); 
	fflush(stdout);
	pthread_mutex_lock(&mutex);
	pthread_cond_broadcast(&cond);     
    pthread_mutex_unlock(&mutex); 
}


