//Add program description, author name, last edit date as in project1
//////////////////////////////////////////////////////////////////////
//Author Name:	Satya Shenoy
//Program Description: Create a menu driven email client which will display the inbox, emails, search the emails by a keyword, sort the emails by sender and ID, and delete emails by ID.
//Last Edit Date: 11/6/2021
/////////////////////////////////////////////////////////////////////
//Add necessary include statements
#include "p2-support.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//initializes the emails dynamic array, size and creates 10 emails to put into the inbox
void initialize(struct Mailbox *ib)
{


//allocate memory for 2000 emails


ib->emails= malloc(sizeof (struct Email) * MAILBOX_SIZE);
ib->size=0;



create_email ("asonmez@mail.com", user_email, "Welcome to your inbox.", "Welcome to your inbox, just wanted to say hi. Here's hoping you get all your codedone.", 11,20,2020, ib);

create_email ("mmartinez@mail.com", user_email, "Padding out your inbox.", "Yet another email just to pad out your inbox, have fun!", 11,30,2020, ib);


create_email ("dboyle@mail.com", user_email, "3rd email!",
                "Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!",
                 12,2,2020, ib);


 create_email ("cbluer@mail.com", user_email, "4th email!",
                "Content of fourth email. More coding, more fun!",
                 12,8,2020, ib);

create_email ("cboyle@mail.com", user_email, "5th email!",
                "Content of fifth email. Coding is fun-tastic!",
                 12,18,2020, ib);

create_email ("sblack@mail.com", user_email, "6th email!",
                "Content of fifth email. Coding is fun-tastic!",
                 1,1,2021, ib);

create_email ("sblack@mail.com", user_email, "7th email!",
                "Body of sixth email. Coding is fun-tastic!",
                 1,5,2021, ib);

 create_email ("sblack@mail.com", user_email, "8th email!",
                "Body of eighth email. Coding is fun-tastic!",
                 2,15,2021, ib);

 create_email ("sblack@mail.com", user_email, "9th email!",
                "Body of ninth email. Coding is fun-tastic!",
                 2,25,2021, ib);

create_email ("dboyle@mail.com", user_email, "Last email!",
                "Body of tentth email. Coding is fun-tastic!",
                 3,15,2021, ib);
}


// void method to display interactive menu to navigate the email client
void display_inbox_menu(struct Mailbox *ib)
{

int i,num;

char keyword[11];

int end_loop=1;





while(end_loop==1) {

printf("*************** SHENOYSL INBOX *************\n");
printf("*************** Total Inbox %.04d ***************\n", ib->size);
printf("1. Show Inbox\n");
printf("2. Show Email by ID\n");
printf("3. Sort Inbox by Sender\n");
printf("4. Sort Inbox by ID\n");
printf("5. Search Inbox by Keyword\n");
printf("6. Delete\n");
printf("7. Exit Inbox\n");
printf("\n");


scanf("%d", &i);

printf("\n");

switch(i)

{

case 1: show_inbox(ib);
break;

case 2: printf("Enter the ID of the email you want to read: \n");
	scanf("%d", &num);
	printf("\n");
	show_id(num,ib);
	break;

case 3: sort_sender(ib);
	printf("\n");
	break;

case 4: sort_ID(ib);
	printf("\n");
	break;

case 5: printf("Enter the keyword you are searching for: \n");
	scanf("%9s", keyword);
	printf("\n");
	search_keyword(keyword,ib);
	break;

case 6: printf("Enter the ID of the e-mail you want to delete: \n");
	scanf("%d", &num);
	printf("\n");
	delete_email(num,ib);
	printf("Email with ID = %d is deleted\n", num);
	printf("\n");
	break;

case 7: printf("Exiting the e-mail client - Good Bye!\n");
	printf("\n");
	quit(ib);
	end_loop=0;
}

}
}


// void method to allow user to create an email, passing in sender, receiver, subject, body, date and a struct pointer
void create_email(char *sender, char *receiver, char *subject, char *body, int month, int day, int year, struct Mailbox *ib){

static int ID=0;

struct date e;

e.day = day;

e.month = month;

e.year = year;

ib->emails[ib->size].sent_date = e;

 
strcpy(ib->emails[ib->size].sender, sender);



strcpy(ib->emails[ib->size].receiver, receiver);


strcpy(ib->emails[ib->size].subject, subject);


strcpy(ib->emails[ib->size].body, body);

ib->emails[ib->size].ID = ib->size; 

ib->size++;
}


// void method to display contents of the email inbox
void show_inbox(struct Mailbox *ib){

printf("ID   SENDER--------------    MM/DD/YYYY    SUBJECT--------\n");
printf("--   --------------------    --/--/----    ---------------\n");

int i;

for(i=0;i<ib->size;i++){

printf("%02d - %-20.20s  - %02d/%02d/%d -  %-15.15s \n", ib->emails[i].ID, ib->emails[i].sender, ib->emails[i].sent_date.month, ib->emails[i].sent_date.day, ib->emails[i].sent_date.year, ib->emails[i].subject); 






}
printf("\n");

}

// void method to display email that corresponds to a given ID number
void show_id(int id, struct Mailbox *ib){


int i;

for(i=0;i<ib->size;i++){


if(id==ib->emails[i].ID){

printf("%s - %s \nEmail Received on: %02d/%02d/%d\n\n%s \n\n", ib->emails[i].sender, ib->emails[i].subject, ib->emails[i].sent_date.month, ib->emails[i].sent_date.day, ib->emails[i].sent_date.year, ib->emails[i].body);




}

}

}

// void method to sort the inbox lexicographically by sender name using qsort
void sort_sender(struct Mailbox *ib){



qsort(ib->emails,ib->size,sizeof(struct Email), compare_sender);

}

// compare function to use in qsort for sorting by sender
int compare_sender(const void  *x, const void *y){

return strcmp(x,y);





}


// void method to  sort the inbox by their corresponding ID number 0-9
void sort_ID(struct Mailbox *ib){

struct Email e;

int i;
int j;

for(i=1;i<ib->size;i++){

e = ib->emails[i];
j = i-1;

while(j>=0 && ib->emails[j].ID > e.ID){

ib->emails[j+1] = ib->emails[j];
j=j-1;

}

ib->emails[j+1] = e;

}


}

// void method to search the sender, subject, and body of all the emails to find a user inputted keyword
void search_keyword (char *s, struct Mailbox *ib){


int i;



printf("ID   SENDER-------------         MM/DD/YYYY   SUBJECT\n");
printf("--   -------------------         --/--/----\n");

for(i=0;i<ib->size;i++){

if((strstr(ib->emails[i].sender, s) != NULL) || (strstr(ib->emails[i].subject, s) != NULL) || (strstr(ib->emails[i].body, s) !=NULL)){


printf("%02d - %-20.20s      - %02d/%02d/%d - %-10.15s \n", ib->emails[i].ID, ib->emails[i].sender, ib->emails[i].sent_date.month, ib->emails[i].sent_date.day, ib->emails[i].sent_date.year, ib->emails[i].subject);                                                                                                                                  


}




}


printf("\n");

} 

// void method to delete the email at a specified ID number
void delete_email (int id, struct Mailbox *ib) {

int i;

for(i=ib->emails[id].ID; i<ib->size-1; i++){

ib->emails[i] = ib->emails[i+1];




}

ib->size--;


printf("\n");

}
// void method to quit the program and free the struct and array
void quit(struct Mailbox *ib){


free(ib->emails);





}
