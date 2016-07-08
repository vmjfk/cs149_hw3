
//#include "buyer.h"
#include <stdlib.h>
#include "buyer_queue.h"
#include <stdio.h>

// initialization function of queue
// mallocs a queue, initialize and returns pointer
// input: an array of buyers, and the array length

struct BuyerQueue* init_BuyerQueue(struct Buyer* buyers[], int count)
{
	// first malloc a BuyerQueue

	struct BuyerQueue* q = (struct BuyerQueue*)malloc(sizeof(struct BuyerQueue));

	// attach buyers
	q->buyers = buyers; 
	 
	// set the count, head and tail 
	q->count = count; 
	q->head = 0; 
	q->tail = count -1; 
	
	//  sort the buyers	
	sort_buyers(q->buyers, count);
	
	// all ready! return the pointer
	
	return q; 
}

// need a function to sort the array upon creation of queue
void sort_buyers(struct Buyer* buyers[], int count)
{
	// one of the dummest but easiest sort routines for arrays
	int sorted = 0; 	// flag to tell me whether or not we are sorted. 

	while(sorted == 0) { 	// while we are still not sorted
		sorted = 1;		// assume we are sorted in the last loop.
		for(int ptr = count -1; ptr > 0;ptr--)
		{
	
		 	if(buyers[ptr]->arrival_time < buyers[ptr-1]->arrival_time) 
			{
				// not sorted properly. swap them. 
				struct Buyer* temp = buyers[ptr];
				buyers[ptr] = buyers[ptr-1]; 	// bump the lower one up 
				buyers[ptr -1] = temp; 			// drop the lower one. 
				sorted = 0; 					// we didn't sort this loop 
			} 
		}
	} 
}


// function to dequeue items. 
// don't need to enqueue, that's done when the array is added. 
struct Buyer* BuyerQueue_dequeue ( struct BuyerQueue* q)
{
	// this routine just moves pointers. no memory is recovered. 
	// input Buyer pointer should be empty, it is used as a return value 
	// return value is remaining number of items in the q, or 
	// -1 if no Buyer can be returned
	
	int count = q->count; 
	

	if(q->count <= 0)
	{
		// nothing left to send
		return NULL; 
	} 
	
	// set the output pointer to the correct buyer
	// since q->buyers is a void*, I need to cast it to a new ptr

	struct Buyer* b = BuyerQueue_peek(q, q->head);

	// move the head up one
	q->head++; 
	
	// set the count 
	q->count = q->tail - q->head + 1; 
	
	// return the count remaining
	
	return b; 
	
}
struct Buyer* BuyerQueue_peek(struct BuyerQueue* q, int position)
{
	// gives a pointer to the Buyer in the array
	// if out of bounds, yields NULL
	struct Buyer* b; 
	
	if(position < q->head || position > q->tail)return NULL;
	b = BuyerArray_peek(q->buyers, position);
	
	
	return b;
}
struct Buyer* BuyerArray_peek(struct Buyer* buyers[], int position)
{
	return buyers[position];
	
	
}
void printBuyerQueue(struct BuyerQueue* q)
{
	
	int start = q->head; 
	int end = q->tail; 
	printf("printing buyer queue\n");
	
	for(int i = start;i<=end;i++)
	{
		struct Buyer* b; 
		b = BuyerQueue_peek(q,i);
		
		printBuyer(b);
	}


}

	
	
