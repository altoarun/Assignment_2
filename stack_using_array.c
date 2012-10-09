// program implements a stack using array

#include <stdio.h>
#include <dos.h>

void push(int); //function pushes anelement on to stack
void pop(); //function pops the lement from the top of stack

int stack[50],stack_pnt=-1; //stack pointer points to the top of stack...initially it is set to -1

void main()
{
    char choice;
    int element;

    while(1)
    {
        printf("\nEnter choice...\n");
        printf("\n1. Push onto stack");
        printf("\n2. Pop element from stack");

        choice = getch(); //choice determines the operation to be performed

        if(choice == '1')
        {
            printf("\n Enter element to be pushed : ");
            scanf("%d",&element);
            push(element);
        }
        else if(choice=='2')
        {
            pop();
        }
        else
        {
            exit(0); //terminates program execution
        }
    }

}

void push(int element)
{
    if(stack_pnt < 49) //makes sure that the stack pointer doesn't go beyond 49
    {
        stack_pnt++; //increment stack pointer by one
        stack[stack_pnt]=element; //inserts the new element
        printf("\n%d successfully pushed on to stack !",element);
    }
    else
    {
        printf("\n Cannot insert element...stack full !");
    }

}

void pop()
{
    int element;

    if(stack_pnt > -1) //makes sure that the stack isn't empty
    {
        element = stack[stack_pnt];
        stack_pnt = stack_pnt - 1; //stack pointer is decremented by one
        printf("\nElement popped is %d ",element);
    }
    else
    {
        printf("\n No more elements to pop !...stack empty");
    }

}
