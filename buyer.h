/* 
*
* buyer.h
* hw3
* cs149 
* john Kennedy
*/ 

// the buyer structure
struct Buyer {
	char priority; // code for high, med, low cost seat cust
	char name[5]; 	// identified as type code then ordinal id e.g. H001
	int arrival_time;	// when they arrived at ticket seller

} ;


struct Buyer* createBuyer(char priority, int ordinal, int arrival_time);