
#ifndef GLOBAL_H  
#define GLOBAL_H 

struct Customer
{
	int id;
	char name[50];
};

//#define Max 10
#define MAXSTACK 10
#define MAXQUEUE 10

//typedef Customer EntryType;
typedef Customer StackEntry;
typedef Customer QueueEntry;

#endif