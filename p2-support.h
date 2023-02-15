/////////////////////////////
// Author Name:	Satya Shenoy
// Program Description: A menu driven email client which can display inbox, display email, search the emails by a keyword, sort the emails in inbox by sender and ID, and delete the emails by an ID 
// Last Edit Date: 11/6/2021
/////////////////////////////

#define MAILBOX_SIZE 2000
#define ADRESS_SIZE 50
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
//CHANGE the email below to your vcu email
#define user_email "shenoysl@mail.com"
//add other define Macros as needed



struct Email
{
	char sender[ADRESS_SIZE];
	char receiver[ADRESS_SIZE];
	//add other struct members as needed
	
	char subject[SUBJECT_SIZE];
	char body [BODY_SIZE];

	struct date {
	
	int month;
	int day;
	int year;
}sent_date;

	int ID;

	// consider adding a nested struct here
	

};

struct Mailbox
{

	int size;
	struct Email *emails;
	//add other struct members as needed
}; 


////////////////////////////////////////////////////////////////////////////////
// This is a sample comment for the initialize function
// You should include a similar comment for each fucntino declared within the .h file 
//
// Function	: initialize
// Description	: Initializes the database for CMSC257 project #2 by manually entering the record using the create_mail function
// Inputs	: struct Mailbox* - pointer to the databse
// Outputs	: void
//////////////////////////////////////////////////////////////////////////////
void initialize (struct Mailbox *ib);

//add other function declarations as needed

/////////////////////////////////////////////////////////////////////////////
// Function	: show_inbox
// Description	: Prints out the emails in the inbox
// Inputs	: struct Mailbox* - pointer to the database
// Outputs	: void
////////////////////////////////////////////////////////////////////////////
void show_inbox (struct Mailbox *ib);

///////////////////////////////////////////////////////////////////////////
// Function	: show_id
// Description	: given an email ID, prints out the email with the corresponding ID.
// Inputs	: integer id to find email with that id, and struct Mailbox*- pointer to the database
// Outputs	: void
// ///////////////////////////////////////////////////////////////////////
void show_id (int id, struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////
// Function	: sort_sender
// Description	: uses qsort to sort the email's in inbox lexicographically by the senders email address
// Inputs	: struct Mailbox* - pointer to the database
// Outputs	: void
////////////////////////////////////////////////////////////////////////
void sort_sender(struct Mailbox *ib);

////////////////////////////////////////////////////////////////////////
// Function	: compare_sender
// Description	: the comparator function that will be used in qsort to compare the sender email addresses to put them in lexicographic order
// Inputs	: two const void * variables which will be compared
// Outputs	: -1 0 or 1 depending on the string's position in the alphabet
///////////////////////////////////////////////////////////////////////
int compare_sender(const void *x, const void *y);

///////////////////////////////////////////////////////////////////////
// Function	: sort_ID
// Description	: sorts the emails in the inbox by their ID numbers lowest to highest
// Inputs	: struct Mailbox* - pointer to the database
// Outputs	: void
/////////////////////////////////////////////////////////////////////
void sort_ID (struct Mailbox *ib);

//////////////////////////////////////////////////////////////////////
// Function	: display_inbox_menu
// Description	: displays the interactive menu to navigate the email client
// Inputs	: struct Mailbox* - pointer to the database
// Outputs	: void
/////////////////////////////////////////////////////////////////////
void display_inbox_menu(struct Mailbox *ib);

////////////////////////////////////////////////////////////////////
// Function	: create_email
// Description	: allows user to create an email 
// Inputs	: char *'s to sender, receiver, subject, body, and ints for day, month, year and struct Mailbox* - pointer to the database
// Outputs	: void
//////////////////////////////////////////////////////////////////
void create_email(char *sender, char *receiver, char *subject, char *body, int month, int day, int year, struct Mailbox *ib);

/////////////////////////////////////////////////////////////////
// Function	: delete_email
// Description	: given an email ID, this function deletes the email corresponding to that ID
// Inputs	: integer ID to find the email corresponding with that, and struct Mailbox* - pointer to database
// Outputs	: void
/////////////////////////////////////////////////////////////////
void delete_email(int id, struct Mailbox *ib);

////////////////////////////////////////////////////////////////
// Function	: quit
// Description	: exits the program and prints an exit message
// Inputs	: struct Mailbox* - pointer to the database
// Ouputs	: void
///////////////////////////////////////////////////////////////
void quit(struct Mailbox *ib);

//////////////////////////////////////////////////////////////
// Function	: search_keyword
// Description	: searches the emails in the inbox to find a user given string and displays any email including that
// Inputs	: struct Mailbox* - pointer to the databse, and a string pointer to search and find
// Outputs	: void
void search_keyword(char *s, struct Mailbox *ib);


