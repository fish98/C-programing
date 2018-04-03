/*
 * File: stack.c
 * -------------
 * This file implements the stack.h abstraction using an array.
 */

#include <stdio.h>

#include "genlib.h"
#include "stack.h"

/*
 * Constants:
 * ----------
 * MaxStackSize -- Maximum number of elements in the queue
 */

#define MaxStackSize 1000

/*
 * Type: stackCDT
 * --------------
 * This type provides the concrete counterpart to the stackADT.
 * The representation used here consists of an array coupled with 
 * with an integer indicating the top element of the stack. 
 */

struct stackCDT {
    void *array[MaxStackSize]; /*stack space -- pointer array*/ 
    int top; /*top position of the stack*/
};

/* Exported entries */

/*
 * Function: NewStack
 * ------------------
 * This function allocates and initializes the storage for a
 * new stack.
 */

stackADT NewStack(void)
{
    stackADT stack;

    stack = New(stackADT);
    stack->top = -1;
    return (stack);
}

/*
 * Function: FreeStack
 * -------------------
 * This function frees the stack storage.
 */

void FreeStack(stackADT stack)
{
    FreeBlock(stack);
}

/*
 * Function: PushStack
 * -----------------
 * This function adds a new element to the top of the stack.
 */

void PushStack(stackADT stack, void *obj)
{
    if (stack->top == MaxStackSize-1) {
        Error("Pushstack called on a full stack");
    }
    stack->array[++stack->top] = obj;
}

/*
 * Function: PopStack
 * -----------------
 * This function removes and returns the data value at the
 * top of the stack.
 */

void *PopStack(stackADT stack)
{
    void *result;

    if (stack->top == -1) {
        Error("Popstack of empty stack");
    }
    result = stack->array[stack->top--];
    return (result);
}

/*
 * Function: IsemptyStack
 * ---------------------
 * This function checks if the stack is empty.
 */

bool IsemptyStack(stackADT stack)
{
    return (stack->top == -1);
}

/*
 * Function: TopStack
 * -----------------
 * This function returns the top element of the stack.Topstack an empty stack is
 * an NULL pointer.
 */

void *TopStack(stackADT stack)
{
    void *result;

    if (stack->top == -1) return (NULL);
    result = stack->array[stack->top];
    return (result);
}
