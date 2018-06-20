/*
#define MAXSTACK 10
typedef char StackEntry;
*/

#include"Global.h"

typedef struct stack {
    int  top;
    StackEntry entry[MAXSTACK];
} Stack;

void	CreateStack		(Stack *);
void	Push			(StackEntry, Stack *);
void	Pop				(StackEntry *, Stack *);
int		StackEmpty		(Stack *);
int		StackFull		(Stack *);
void    TraverseStack   (Stack *, void(*pf)(StackEntry));
void	FirstElement	(StackEntry *, Stack *);
void	CopyLast		(StackEntry *, Stack *);
void	CopyStack		(Stack *, Stack *);
void	DestroyStack	(Stack *);
int		StackSize		(Stack *);

void	FirstElementUL	(StackEntry *, Stack *);
void	CopyLastUL		(StackEntry *, Stack *);
void	CopyStackUL		(Stack *, Stack *);
void	DestroyStackUL	(Stack *);
int		StackSizeUL		(Stack *);
void	PrintStackUL	(Stack *sp);
