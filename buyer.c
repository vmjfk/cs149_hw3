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

struct Buyer* createBuyer(char priority, int ordinal, int arrival_time)
{
	struct Buyer* ret = (struct Buyer*)malloc(sizeof(struct Buyer)); 

	ret->priority = priority; 
	
	char pri[2]; 
	pri[0] = priority;
	pri[1] = '\0';
	strcat(ret->name,pri);

	char cord[4];
	sprintf(cord,"%03d",ordinal);
	strcat(ret->name,cord);
	
	ret->arrival_time = arrival_time;
	
	return ret; 
}
// should move the routine that fills the buyer queues to here from main()
		 
