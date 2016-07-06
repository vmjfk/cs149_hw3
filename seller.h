/*
*
* seller.h
* hw3
* cs149
* john Kennedy
*
*/ 

struct Seller {
	char* seller_type; // H M or L 
	char* name; 	   // H1, M2, etc. 
	struct Buyer buyers[];	   // buyer queue
} 


// function to sell tickets. input is the buyer struct array of buyers 
void* sell(struct Buyer[] buyers); 




