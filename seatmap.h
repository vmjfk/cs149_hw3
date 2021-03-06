/* 
* seatmap.h
* cs149 hw 3
* john kennedy
*
*/
#include "buyer_queue.h"
#include <pthread.h>
//	seatmap is an array of char*, which hold the id of whoever bought a
//	ticket, or no one. 

#define NUM_OF_ROWS  10			
#define SEATS_PER_ROW 10		

struct Seatmap {
	struct Buyer* seatmap[NUM_OF_ROWS][SEATS_PER_ROW]; // records who owns seat
	pthread_mutex_t* mutex;							// lock for the seatmap
	pthread_cond_t* cond; 
};


// function to get a seat from a particular section H M L
int sell_seat(struct Seatmap* map, struct Buyer* b);

// function to set a seat as sold, or return error if no more seats
int set_seat(struct Seatmap* map, struct Buyer* b);


//function to printout the seat map in ascii
void print_seatmap(struct Seatmap* map);

// constructor for seatmap 
void initialize_seatmap(struct Seatmap* map);

// end seatmap.h
