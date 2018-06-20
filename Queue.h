/*
#define MAXQUEUE 10
typedef char QueueEntry;
*/

#include"Global.h"


typedef struct queue{
	int count;
	int front;
	int rear;
	QueueEntry entry[MAXQUEUE];
}Queue;

void    CreateQueue   (Queue *);
void    Enqueue       (QueueEntry, Queue *);
void    Dequeue       (QueueEntry *, Queue *);
int		QueueEmpty    (Queue *);
int		QueueFull     (Queue *);
void    TraverseQueue (Queue*, void (*pf)(QueueEntry));
int     QueueSize     (Queue *);
void	CopyQueue     (Queue *, Queue *);
void	DestroyQueue  (Queue *);
void	CopyFirst     (QueueEntry *, Queue *);
void	LastElement   (QueueEntry *, Queue *);

int     QueueSizeUL   (Queue *);
void	CopyQueueUL   (Queue *, Queue *);
void	DestroyQueueUL(Queue *);
void	CopyFirstUL   (QueueEntry *, Queue *);
void	LastElementUL (QueueEntry *, Queue *);
