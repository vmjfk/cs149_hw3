/*
*
* seller.h
* hw3
* cs149
* john Kennedy
*
*/ 
#include "seatmap.h"
#include <time.h>

struct Seller {
	char priority; // H M or L 
	int ordinal; 	   // 1, 2, etc. 
	char name[5];			// combines priority and name
	struct BuyerQueue* q;	   // buyer queue
	struct Seatmap* map; 		// pointer to the one seatmap
};


// function to sell tickets. input is the buyer struct array of buyers 
void* sell(void * seller);

struct Seller* createSeller(char priority, int ordinal, struct BuyerQueue* bqs, struct Seatmap* map);
time_t get_time(time_t from);
void end_thread(struct Seller* s, time_t end_time);


