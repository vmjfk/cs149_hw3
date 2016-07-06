/*
*
* seller.c
* hw3
* cs149
* john Kennedy
*
*/ 

// thread entrant function that all threads will start with. 
void* sell(struct Buyer[] buyers)
{
	// check if clock expired
		// if so, exit thread
	
	// get the next buyer in the array
		// if none left, exit thread
		
	// if buyer arrival time > clock, sleep for arrival time - clock seconds
	
	// it's time to get a seat. 
	int seat = sell_seat(name);
	
}

// a function to get the next buyer from the buyer array
// returns null is no buyers available. 
struct Buyer* get_next_buyer(struct Buyer[] buyers)
{
	// assume array is sorted. 
	// take the buyer off of the head ( [0] ) and 
	struct Buyer* = buyers[0];
	
	// move all the others up. 
	for(int i = 0;i < NUM_BUYERS -1;i++)
	{
		buyers[i] = buyers[i+1]; 
	}
	free(buyers[NUM_BUYERS -1]); 
	
		
	// uses the global variable to know how many buyers and 
	// therefor how long the array is. 
	
}

