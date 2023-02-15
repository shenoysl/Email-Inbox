//Add program description, author name, last edit date as in the project1
/////////////////////////////////////////////////////////////////////////
// Author Name: Satya Shenoy
// Program Description: A menu driven email client that will be able to display the inbox and emails, search the emails by a keyword, sort the emails by sender and ID, and delete emails by an ID
// Las Edit Date: 11/06/2021
////////////////////////////////////////////////////////////////////////


//Do not modify anything below this line


#include <stdio.h>
#include <stdlib.h>
#include "p2-support.h"


int main(){

struct Mailbox* ib;
ib = (struct Mailbox*) malloc(sizeof(struct Mailbox));
initialize(ib);
display_inbox_menu(ib);
free(ib);
return 0;




}
