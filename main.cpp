

#include "Stack.h"
#include"Queue.h"

#include <stdio.h>
#include <conio.h>
#include <ctime>

void printStackMenu();
void printQueueMenu();
void printCarMenu();

void display(Customer e){
	printf("\n\n\t Customer Info ..");
	printf("\n\t Customer ID : %d", e.id);
	printf("\n\t Customer Name : %s", e.name);
}

void MostRecent(Queue q){
	Stack x;
	CreateStack(& x);
	Customer h;
	while (!QueueEmpty(&q))
	{
		Dequeue(&h, &q);
		Push(h, & x);
	}
	printf("\n\n\tInformation in a 'most-recent 'Order.\n");
	TraverseStack(& x, display  );
}

int main(){
	time_t now = time(0);
	printf("\n\n\t %s", ctime(&now));
	printf("\n\t CS214 - Assignment No.4\n\t_________________________\n");
	char select;
	printf("\n\t Please Select (s) for Stack, (q) for Queue");
	printf("\n\t and (c) for Testing Car Workshop : ");
	scanf("%c", &select);

	if (select == 's' || select == 'S')
	{

			StackEntry  e;
			Stack s;
			CreateStack(& s);        /* Initialize the stack to be empty. */
	
			Stack copy;
			int c;
			printStackMenu();
			scanf("%d", &c);
			while (c != 0)
			{
				switch (c)
				{
				case 1:
					if (! StackFull(& s))
					{
						printf("\n\n\t Enter Customer ID : ");
						scanf("%d" , &e.id);

						printf("\n\t Enter Customer Name : ");
						scanf("%s" , e.name);

						Push(e, & s);         /* Push each item onto the stack.  */
					}
					else
						printf("\n\n\t ADT is Overflow, Insertion Not Allowed ");
					
					break;
				case 2:
					if (! StackEmpty(& s))
					{
						Pop(&e, & s);         /* Pop item from the stack.  */
						display(e);
					}
					else
						printf("\n\n\t ADT is Underflow, Retrievimg Not Allowed ");
					
					break;
				case 3:
					FirstElement(& e ,& s);
					//FirstElementUL(& e,& s);
					printf("\n\n\tThe returned first item \n");
					display(e);
			
					break;
				case 4:
					CopyLast(& e ,& s);
					//CopyLastUL(& e,& s);
					printf("\n\n\tThe last item \n");
					display(e);
			
					break;
				case 5:
					printf("\n\n\tThe stack size is:%d\n",StackSize(& s));
					//printf("\n\n\tThe stack size is:%d\n",StackSizeUL(& s));
			
					break;
				case 6:
					CreateStack(&copy);        /* Initialize the stack to be empty. */
					CopyStack(& s, &copy);
					//CopyStackUL(& s, &copy);
					printf("\n\n\tThe copied stack is:");
					while (!StackEmpty(&copy)) {
						Pop(& e , &copy);         /* Pop an item from the stack.  */
						display( e);
					}

					break;
				case 7:
					printf("\n\n\tThe stack is:");
					TraverseStack(&s, display);
					//PrintStackUL(& s);

					break;
				case 8:
					DestroyStack(& s);
					printf("\n\n\tThe stack size is:%d\n",StackSize(& s));
					//DestroyStackUL(& s);
					//printf("\n\n\tThe stack size is:%d\n",StackSizeUL(& s));

					break;
				default:
					printf("\n\t\t Wrong Choice");
					break;
				}

				printStackMenu();
				scanf("%d", &c);
			}
	}

	
	else if (select == 'q' || select == 'Q')
	{

		    QueueEntry  e;
			Queue q;
			CreateQueue(& q);        /* Initialize the Queue to be empty. */
	
			Queue copy;
			int c;
			printQueueMenu();
			scanf("%d", &c);
			while (c != 0)
			{
				switch (c)
				{
				case 1:
					if (! QueueFull(& q))
					{
						printf("\n\n\t Enter Customer ID : ");
						scanf("%d" , &e.id);

						printf("\n\t Enter Customer Name : ");
						scanf("%s" , e.name);

						Enqueue(e, & q);         /* Enqueue each item onto the Queue.  */
					}
					else
						printf("\n\n\t ADT is Overflow, Insertion Not Allowed ");
					
					break;
				case 2:
					if (! QueueEmpty(& q))
					{
						Dequeue(&e, & q);         /* Dequeue item from the Queue.  */
						display(e);
					}
					else
						printf("\n\n\t ADT is Underflow, Retrievimg Not Allowed ");
					
					break;
				case 3:
					CopyFirst(& e ,& q);
					//CopyFirstUL(& e,& q);
					printf("\n\n\tCopy First item \n");
					display(e);
			
					break;
				case 4:
					LastElement(& e ,& q);
					//LastElementUL(& e,& q);
					printf("\n\n\tReturn The last item \n");
					display(e);
			
					break;
				case 5:
					printf("\n\n\tThe Queue size is:%d\n",QueueSize(& q));
					//printf("\n\n\tThe Queue size is:%d\n",QueueSizeUL(& q));
			
					break;
				case 6:
					CreateQueue(&copy);        /* Initialize the Queue to be empty. */
					CopyQueue(& q, &copy);
					//CopyQueueUL(& q, &copy);
					printf("\n\n\tThe copied Queue is:");
					while (!QueueEmpty(&copy)) {
						Dequeue(& e , &copy);         /* Dequeue an item from the Queue.  */
						display( e);
					}

					break;
				case 7:
					printf("\n\n\tThe Queue is:");
					TraverseQueue(&q, display);

					break;
				case 8:
					DestroyQueue(& q);
					printf("\n\n\tThe Queue size is:%d\n",QueueSize(& q));
					//DestroyQueueUL(& q);
					//printf("\n\n\tThe Queue size is:%d\n",QueueSizeUL(& q));

					break;
				default:
					printf("\n\t\t Wrong Choice");
					break;
				}

				printQueueMenu();
				scanf("%d", &c);
			}
	}


	else if (select == 'c' || select == 'C')
	{

		    QueueEntry  e;
			Queue q;
			CreateQueue(& q);        /* Initialize the Queue to be empty. */

			int c;
			printCarMenu();
			scanf("%d", &c);
			while (c != 0)
			{
				switch (c)
				{
				case 1:
					if (! QueueFull(& q))
					{
						printf("\n\n\t Enter Customer ID : ");
						scanf("%d" , &e.id);

						printf("\n\t Enter Customer Name : ");
						scanf("%s" , e.name);

						Enqueue(e, & q);         /* Enqueue each Customer onto the Queue.  */
					}
					else
						printf("\n\n\t ADT is Overflow, Insertion Not Allowed ");
					
					break;
				case 2:
					if (! QueueEmpty(& q))
					{
						Dequeue(&e, & q);         /* Dequeue Customer from the Queue.  */
						display(e);
					}
					else
						printf("\n\n\t ADT is Underflow, Retrievimg Not Allowed ");
					
					break;
				case 3:
					printf("\n\n\tDisplay All Customers");
					TraverseQueue(&q, display);
			
					break;
				case 4:
					MostRecent(q);	
					break;
				case 5:
					printf("\n\n\tNumbers Of Customers are waiting Is: %d\n\n",QueueSize(& q));
			
					break;
				
				case 6:
					DestroyQueue(& q);
					printf("SYSTEM IS CLEAR\n");

					break;
				default:
					printf("\n\t\t Wrong Choice");
					break;
				}

				printCarMenu();
				scanf("%d", &c);
			}
	}
	getch();
	return 0;
}

void printStackMenu(){

	printf( "\n\n\n\t$ \t    Main Menu (Stack)       $\n\t_|_________________________________|_\n");

			printf("\t |\t                           |\n");
			printf("\t |\t1: Push a New Element.     |\n");
			printf("\t |\t2: Pop Last Element.       |\n");
			printf("\t |\t3: Return First Element.   |\n");
			printf("\t |\t4: Copy Last Element.      |\n");
			printf("\t |\t5: Stack Size.             |\n");
			printf("\t |\t6: Copy Stack.             |\n");
			printf("\t |\t7: Print Stack.            |\n");
			printf("\t |\t8: distroy Stack.          |\n");
			printf("\t |\t0: to Exit                 |\n");

			printf("\t_|_________________________________|_\n");
			printf("\t$|\t                           |$\n");
			printf("\n\t");

}

void printQueueMenu(){
	printf( "\n\n\n\t$ \t    Main Menu (Queue)       $\n\t_|_________________________________|_\n");

			printf("\t |\t                           |\n");
			printf("\t |\t1: Enqueue a New Element.  |\n");
			printf("\t |\t2: Dequeue an Element.     |\n");
			printf("\t |\t3: Copy First Element.     |\n");
			printf("\t |\t4: Return Last Element.    |\n");
			printf("\t |\t5: Queue Size.             |\n");
			printf("\t |\t6: Copy Queue.             |\n");
			printf("\t |\t7: Print Queue.            |\n");
			printf("\t |\t8: distroy Queue.          |\n");
			printf("\t |\t0: to Exit                 |\n");

			printf("\t_|_________________________________|_\n");
			printf("\t$|\t                           |$\n");
			printf("\n\t");

}

void printCarMenu(){
	printf( "\n\n\n\t$ \t    Main Menu (Car)         $\n\t_|_________________________________|_\n");

			printf("\t |\t                           |\n");
			printf("\t |\t1: Add a New Customer.     |\n");
			printf("\t |\t2: Serve a Customer.       |\n");
			printf("\t |\t3: Display All Customers.  |\n");
			printf("\t |\t4: Display in Most Recent. |\n");
			printf("\t |\t5: Waiting Customers?.     |\n");
			printf("\t |\t6: Clear All Data.         |\n");
			printf("\t |\t0: to Exit                 |\n");

			printf("\t_|_________________________________|_\n");
			printf("\t$|\t                           |$\n");
			printf("\n\t");

}


/************************************************************************/
///
/*			Stack	USER LEVEL SOLUTION        								*/
///

/************************************************************************/
/* Problem 1	Write a function that returns the ﬁrst element in a stack.(User level)	*/
/************************************************************************/

//First Element
  void FirstElementUL(StackEntry *pe, Stack *ps)
{
	StackEntry e;

	Stack temp;
	CreateStack(&temp);

	while (!StackEmpty(ps))
	{
		Pop(&e , ps);
		Push( e , &temp);
	}

	Pop(pe,&temp);

	while(!StackEmpty(&temp))
	{
		Pop(&e , &temp);
		Push( e , ps);
	}
	
}
/************************************************************************/
/* Problem 3 write a function that returns a copy from the last element in a stack.(User level) */
/************************************************************************/

 //Copy Last
 void CopyLastUL(StackEntry *e, Stack *ps)
 { 
	 Pop(e , ps);
	 Push(*e , ps);

 }

/************************************************************************/
/* Problem 5 Write a function to destroy a stack.(User level)	*/
/************************************************************************/
// Destroy Stack
 void DestroyStackUL(Stack *ps)
 {  StackEntry e;
	while (!StackEmpty(ps))
	{
		Pop(&e, ps);
	}
 }

 
/************************************************************************/
/*	Problem 7 Write a function to copy a stack to another. (User level)	*/
/************************************************************************/
 void CopyStackUL(Stack *ps, Stack *Copy)
 { 
	 StackEntry e;
	 Stack temp;
	CreateStack(&temp);
	while (!StackEmpty(ps))
	{
		Pop(&e ,ps);
		Push(e ,&temp);
	}
	while(!StackEmpty(&temp))
	{
		Pop(&e ,&temp);
		Push(e ,ps);
		Push(e ,Copy);
	}
 }
/************************************************************************/
/*	Problem 9 Write a function to return the size of a stack (User level)	*/
/************************************************************************/
// Stack size

 int StackSizeUL(Stack *ps)
 {
	int count=0;
	Stack temp;
	StackEntry e;
	CreateStack(&temp);
	while (!StackEmpty(ps))
	{
		Pop(&e ,ps);
		Push(e ,&temp);
		count++;
	}
	
	while(!StackEmpty(&temp))
	{
		Pop(&e ,&temp);
		Push(e ,ps);
	}
	return count;

 }

/************************************************************************/
/*	Problem 13 Write a function to print on the screen the contents of a stack without changing the stack (User level).
Why this function shouldnot be written in the implementation level?										*/
/************************************************************************/
// PrintStack

 void PrintStackUL (Stack *ps)
 {
	StackEntry e;
	Stack temp;
	CreateStack(&temp);
	while (!StackEmpty(ps))
	{
		Pop(&e ,ps);
		display(e);		
		Push(e ,&temp);
	}
	
	while(!StackEmpty(&temp))
	{
		Pop(&e ,&temp);
		Push(e ,ps);
	}

 }


 /************************************************************************/
///
/*				Queue USER LEVEL SOLUTION        								*/
///

/************************************************************************/
/*	Problem 2 Write a function that returns the last element in a queue. (User level)	*/
/************************************************************************/
void LastElementUL(QueueEntry *qe, Queue *q)
{
	int count=0;
	Queue temp;
	QueueEntry item;
	CreateQueue(&temp);
	while (!QueueEmpty(q))
	{
		Dequeue(&item,q);
		Enqueue(item,&temp);
		count++;
	}
	*qe=item;
	for(int x=1;x<count;x++)
	{
		Dequeue(&item,&temp);
		Enqueue(item,q);
	}
	
}
/************************************************************************/
/*	Problem 4	write a function that returns a copy from the ﬁrst element in a queue. (User level)	*/
/************************************************************************/
void CopyFirstUL(QueueEntry *qe, Queue *q)
{
	Queue temp;
	QueueEntry item;
	CreateQueue(&temp);
	while (!QueueEmpty(q))
	{
		Dequeue(&item,q);
		Enqueue(item,&temp);
	}
	Dequeue(qe,&temp);
	Enqueue(*qe,q);
	while(!QueueEmpty(&temp))
	{
		Dequeue(&item,&temp);
		Enqueue(item,q);
	}
}

/************************************************************************/
/*	Problem 6  Write a function to destroy a queue (User level) */
/************************************************************************/
void DestroyQueueUL(Queue *q)
{
	QueueEntry item;
	while (!QueueEmpty(q))
	{
		Dequeue(&item,q);
	}
}

/************************************************************************/
/*	Problem 8	Write a function to copy a queue to another. (User level)	*/
/************************************************************************/
void CopyQueueUL(Queue *q, Queue *Copy)
{	
	Queue temp;
	QueueEntry item;
	CreateQueue(&temp);
	while (!QueueEmpty(q))
	{
		Dequeue(&item,q);
		Enqueue(item,&temp);
	}
	
	while(!QueueEmpty(&temp))
	{
		Dequeue(&item,&temp);
		Enqueue(item,q);
		Enqueue(item,Copy);
	}

}

/************************************************************************/
/*	Problem 10 Write a function to return the size of a queue (User level) */
/************************************************************************/
int QueueSizeUL(Queue *q)
{
	int count=0;
	Queue temp;
	QueueEntry item;
	CreateQueue(&temp);
	while (!QueueEmpty(q))
	{
		Dequeue(&item,q);
		Enqueue(item,&temp);
		count++;
	}
	
	while(!QueueEmpty(&temp))
	{
		Dequeue(&item,&temp);
		Enqueue(item,q);
	}
	return count;
}
