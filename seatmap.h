/* 
* seatmap.h
* cs149 hw 3
* john kennedy
*
*/

//	seatmap is an array of char*, which hold the id of whoever bought a
//	ticket, or no one. 

#define NUM_OF_ROWS  10			
#define SEATS_PER_ROW 10		

struct Seatmap {
	char seatmap[NUM_OF_ROWS][SEATS_PER_ROW][5]; // records who owns seat
};


// function to get a seat from a particular section H M L
int sell_seat(struct Seatmap* map, char* name);

// function to set a seat as sold, or return error if no more seats
int set_seat(struct Seatmap* map, char* name);


//function to printout the seat map in ascii
void print_seatmap();

// constructor for seatmap 
void initialize_seatmap(struct Seatmap* map);

// end seatmap.h
