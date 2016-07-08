/*
* buyer.c
* hw3 
* cs149
* john Kennedy
*/ 

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "buyer.h"

// this module holds the functions that apply to buyer

struct Buyer* createBuyer(char priority, char * seller_name, int ordinal, int arrival_time)
{
	struct Buyer* ret = (struct Buyer*)malloc(sizeof(struct Buyer)); 

	ret->priority = priority; 
	
	strcat(ret->name,seller_name);
	
	char cord[3];
	sprintf(cord,"%02d",ordinal);
	strcat(ret->name,cord);
	
	ret->arrival_time = arrival_time;
	
	return ret; 
}
// should move the routine that fills the buyer queues to here from main()
		
void printBuyer(struct Buyer* b)
{
	printf("name=%s,arrival_time=%d\n",b->name,b->arrival_time);
}

