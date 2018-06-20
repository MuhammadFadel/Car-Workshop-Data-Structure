
#include "Queue.h"

/* CreateQueue:  create the queue.
Pre:   None.
Post: The queue q has been initialized to be empty.
 */
void CreateQueue(Queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear  = -1;
}

/* Enqueue:  append an entry to the queue.
Pre:   The queue q has been created and is not full.
Post: The entry x has been stored in the queue as its last entry.
Uses: QueueFull, Error.
*/
void Enqueue(QueueEntry x, Queue *q)
{
        q->rear = (q->rear + 1) % MAXQUEUE;
        q->entry[q->rear] = x;

		q->count++;
}

/* Dequeue:  remove the first entry in the queue.
Pre:   The queue q has been created and is not empty.
Post: The first entry in the queue has been removed and returned as the
    value of x.
 */
void Dequeue(QueueEntry *e, Queue *q)
{
        *e = q->entry[q->front];
        q->front = (q->front + 1) % MAXQUEUE;

		q->count--;
}


/* QueueEmpty: returns non-zero if the queue is empty.
Pre:   The queue q has been created.
Post: The function returns non-zero if the queue q is empty,
    zero otherwise.
 */
int QueueEmpty(Queue *q)
{
    return q->count == 0;
}

 /* QueueFull: returns non-zero if the queue is full.
Pre:   The queue q has been created.
Post: The function returns non-zero if the queue is full,
    zero otherwise.
 */
int QueueFull(Queue *q)
{
    return q->count == MAXQUEUE;
}

void TraverseQueue(Queue* pq, void (*pf)(QueueEntry)){
	int pos=pq->front;

	for(int i=0; i<pq->count; i++){

		(*pf)(pq->entry[ pos ]);

		pos=(pos+1)%MAXQUEUE;
	}
}

/************************************************************************/
/*	Problem 2 Write a function that returns the last element in a queue. (implem entation level)	*/
/************************************************************************/
void LastElement(QueueEntry *qe, Queue *q)
{
	*qe=q->entry[q->rear];

	if (q->rear==0) 
		q->rear=MAXQUEUE-1;
	else
		q->rear--;

	q->count--;
}
/************************************************************************/
/*	Problem 4	write a function that returns a copy from the ﬁrst element in a queue. (implementation level)	*/
/************************************************************************/
void CopyFirst(QueueEntry *qe, Queue *q)
{
	*qe=q->entry[q->front];
}

/************************************************************************/
/*	Problem 6  Write a function to destroy a queue (implementation level) */
/************************************************************************/
void DestroyQueue(Queue *q)
{
	q->count=0;
	q->front=0;
	q->rear=-1;
}

/************************************************************************/
/*	Problem 8	Write a function to copy a queue to another. (implementation level)	*/
/************************************************************************/
void CopyQueue(Queue *q, Queue *Copy)
{
	//x is used to keep tracking of queue indeces
	// I can't use the condition (x<q->count) to stop the loop 
	// because we can't expect that the value of q->front is always 
	// less than the count, so we used the variable y to keep track for the 
	// the number of elements in the queue
	int x=q->front;
	for ( int i=0; i<q->count; i++){
		Copy->entry[x] = q->entry[x];
		x = (x+1) % MAXQUEUE;
	}

	Copy->front=q->front;
	Copy->rear=q->rear;
	Copy->count=q->count;
}

/************************************************************************/
/*	Problem 10 Write a function to return the size of a queue (implementation level) */
/************************************************************************/
 /* QueueSize: return the number of entries in the queue.
Pre:   The queue q has been created.
Post: The function returns the number of entries in the queue q.
 */

int QueueSize(Queue *q)
{
	return q->count;
}
