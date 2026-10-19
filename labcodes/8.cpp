#include <iostream>
using namespace std;

int main()
{
	int x = 12;
	int y = 13;
	int z = 14;


//(pointer to constant integer)
const int* pc = &x;
pc=&y;
//ERROR *pc=14; //main.cpp:14:4: error: assignment of read-only location ‘* pc’

//(constant pointer to integer)
int* const cp = &y;
// ERROR cp=&x;   //main.cpp:18:3: error: assignment of read-only variable ‘cp’
*cp=x;

//onstant pointer to constant integer

const int* const cpc=&z;

//ERROR *cpc=x;
//ERROR cpc=&y;
/*
main.cpp:24:5: error: assignment of read-only location ‘*(const int*)cpc’
   24 | *cpc=x;
      | ~~~~^~
main.cpp:25:4: error: assignment of read-only variable ‘cpc’
   25 | cpc=&y;
*/
	return 0;
}