#include "Stack.h"

/* CreateStack: initialize the stack to be empty.
Pre:     None.
Post:   The stack has been initialized to be empty.
 */
void CreateStack(Stack *ps)
{
    ps->top = 0;
}

/* Push: push an item onto the stack.
Pre:     The stack exists and it is not full.
Post:   The argument e has been stored at the top of the stack.
 */
void Push(StackEntry e, Stack *ps)
{
    ps->entry[ps->top ++] = e;
}

/* Pop: pop an item from the stack.
Pre:   The stack exists and it is not empty.
Post: The item at the top of stack has been removed and returned in *e.
 */
void Pop(StackEntry *e, Stack *ps)
{
   *e = ps->entry[-- ps->top];
}

/* StackEmpty: returns non-zero if the stack is empty.
Pre:    The stack exists and it has been initialized.
Post:  Return non-zero if the stack is empty; return zero, otherwise.
 */
int StackEmpty(Stack *ps)
{
    return ps->top == 0;
}

/* StackFull: returns non-zero if the stack is full.
Pre:     The stack exists and it has been initialized.
Post:   Return non-zero if the stack is full; return zero, otherwise.
 */
int StackFull(Stack *ps)
{
    return ps->top == MAXSTACK;
}

//Precondition: The stack is created
void TraverseStack(Stack *ps, void(*pf)(StackEntry)){
   for(int i=ps->top; i>0; i--)
      (*pf)(ps->entry[i-1]);
}                                           


/************************************************************************/
/* Problem 1	Write a function that returns the ﬁrst element in a stack.(implementation level)	*/
/************************************************************************/

//First Element
void FirstElement(StackEntry *e, Stack *ps)
{
	int i=0;
	*e = ps->entry[0];
	ps->top--;

	while (i< ps->top){
		ps->entry[i]=ps->entry[i+1];// Shift the elements down
		i++;
	}
	
}
/************************************************************************/
/* Problem 3 write a function that returns a copy from the last element in a stack.(implementation level) */
/************************************************************************/

 //Copy Last
 void CopyLast(StackEntry *e, Stack *ps)
 {
	 *e = ps->entry[ps->top-1];	
 }

/************************************************************************/
/* Problem 5 Write a function to destroy a stack.(implementation level)	*/
/************************************************************************/
// Destroy Stack
 void DestroyStack(Stack *ps)
 {
	 ps->top = 0;
 }

 
/************************************************************************/
/*	Problem 7 Write a function to copy a stack to another. (implementation level)	*/
/************************************************************************/
 void CopyStack(Stack *ps, Stack *Copy)
 { 
	 for(int count=0; count< ps->top; count++)
	 	Copy->entry[count] = ps->entry[count];

	 Copy->top = ps->top;
 }
/************************************************************************/
/*	Problem 9 Write a function to return the size of a stack (implementation level)	*/
/************************************************************************/
// Stack size

 int StackSize(Stack *ps)
 {
	 return ps->top; 
 }

