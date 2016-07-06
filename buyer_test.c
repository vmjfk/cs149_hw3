

#include <stdio.h>
#include "buyer.h"


int main(int argc, char* argv[])
{
	struct Buyer b;
	
	new_buyer(&b,"H", 0, 1);
	printf("returned from new_buyer()\n");
	printf("%s,%s,%d\n", b.buyer_type,b.name,b.arrival_time);
	

}
/*
#include <stdio.h>

int main ()
{
  char buffer [50];
  int n, a=5, b=3;
  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
  printf ("[%s] is a string %d chars long\n",buffer,n);
  return 0;
}
*/
