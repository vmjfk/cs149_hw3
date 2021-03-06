#include "buyer.h" 

// priority queue to hold the buyers. 
struct BuyerQueue {
	void * buyers;			// array to hold the buyers
	int head;				// pointer to lowest
	int tail; 				// pointer to tail 
	int count; 				// tail - head. 	
};


// need a function to sort the array upon creation of queue
void sort_buyers(struct Buyer* buyers[], int count);

// initialization function of queue
struct BuyerQueue* init_BuyerQueue(struct Buyer* buyers[], int count);

// function to dequeue a buyer struct
struct Buyer* BuyerQueue_dequeue (struct BuyerQueue* q);
struct Buyer* BuyerQueue_peek(struct BuyerQueue* q, int position);
struct Buyer* BuyerArray_peek(struct Buyer* buyers[], int position);
void printBuyerQueue(struct BuyerQueue* q);


