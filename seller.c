/*
*
* seller.c
* hw3
* cs149
* john Kennedy
*
*/ 
#include "seller.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

struct Seller* createSeller(char priority, int ordinal, struct BuyerQueue* bqs, struct Seatmap* map)
{
	
	struct Seller* s = (struct Seller*)malloc(sizeof(struct Seller));
	s->priority = priority;
	s->ordinal = ordinal; 
	s->q = bqs;
	
	strcat(s->name, &s->priority);
	char cord[2];

	sprintf(cord,"%d",ordinal);
	strcat(s->name, cord);
	s->map = map;
	return s; 
}



// thread entrant function that all threads will start with. 
void* sell(void * seller)
{	

	// set the start time so we can tell when to do stuff
	
	struct Seller* s = (struct Seller*)seller; 
	
	char* name = s->name;

	struct Seatmap* map = s->map; 			// pointer to the one map 

	pthread_mutex_t* mutex = map->mutex;	// lock for the seatmap
	pthread_cond_t* cond = map->cond;


	
	pthread_mutex_lock(mutex);
	pthread_cond_wait(cond, mutex);      
	pthread_mutex_unlock(mutex);
	// now we can start 
	
	
	time_t start_time = time(NULL);
	

	int do_work = 1; 			// assume there is work to do

	struct BuyerQueue* q = s->q;

	struct Buyer* b = BuyerQueue_dequeue (s->q);  // get the next buyer

	int next_op = b->arrival_time; 	// my time to execute

	while(do_work == 1)			// while there is still something to do. 
	{
	
		// check if clock expired
		if(get_time(start_time) > 60)
		{
			end_thread(s,get_time(start_time));
			return NULL; 
		}
		// if so, exit thread
		
		if(next_op <= get_time(start_time))	// time to do some work;
		{
						// get the mutex. block until you get it. 
/***********************************************************************************
*
*			critical region start
*
************************************************************************************/
			pthread_mutex_lock(mutex);

			// it's time to get a seat. 
			int seat = sell_seat(map, b);

			// wait for the appropriate amount of time 
			int wait_time = 0; 
			
			switch(b->priority){
				case 'H': wait_time = (rand() % 2) + 1;
					break;
				case 'M': wait_time = (rand() % 3) + 2;
					break;
				default:  wait_time = (rand() % 4) + 4;
			}
			sleep(wait_time); 
			
			
			if(seat == -1)
			{
				printf("00:%02d Customer %s didn't get a seat. no more seats for seller %s\n",(int)get_time(start_time), b->name, name);
			}else{
				printf("00:%02d Customer %s got seat %d\n",(int)get_time(start_time), b->name,seat);
			}
			
			// print the seatmap 
			print_seatmap(map); 
			
			// release the mutex
			pthread_mutex_unlock(mutex);
/***********************************************************************************
*
*			critical region end
*
************************************************************************************/
			
			// get the next buyer
			b = BuyerQueue_dequeue ( s->q); 
			if(b == NULL) 
			{
				do_work = 0;	// no more buyers to process
				end_thread(seller,get_time(start_time));
			}else{
				next_op = b->arrival_time; 
			}
		}
	}
	
	
	return NULL;
}

time_t get_time(time_t from)
{
	// gets number of seconds after from time
	return time(NULL) - from;
}
void end_thread(struct Seller* s, time_t end_time)
{
	// thread is closing out

	// print closeout message
	printf("00:%02d Seller %s closing out\n",(int) end_time, s->name);
	 
}



