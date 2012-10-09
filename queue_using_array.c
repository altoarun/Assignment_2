//program to implement a queue. First In First Out(FIFO) implementation using array

#include <stdio.h>

void remove_ele(); //function to remove an element from the tail of queue
void insert(int); //function to insert an element at the head of queue
void traverse(); //traverses the queue from head to tail

int queue[50],head=-1,tail=-1;

void main()
{
    char choice;
    int element;

    while(1)
    {
        printf("\nEnter choice...\n");
        printf("\n1. Insert element to queue");
        printf("\n2. Remove element from queue");
        printf("\n3. Queue traversal");

        choice = getch();

        if(choice == '1')
        {
            printf("\n Enter element to insert : ");
            scanf("%d",&element); //gets the element to be inserted

            insert(element);

        }
        else if(choice=='2')
        {
            remove_ele();
        }
        else if(choice=='3')
        {
            traverse();
        }
        else
        {
            exit(0); //exits from program
        }
    }

}

void remove_ele()
{
    int element,i;

    if(head==0) //checks whether the queue is empty or not
    {
        element = queue[head]; //element to be removed from the queue is at its head

        printf("\nElement removed is %d",element);
        for(i=1;i<=tail;i++)
        {
            queue[i-1] = queue[i];
            /*since we removed 1 element from queue. every element in array has to be shifted 1 postion to the left.
            ensures efficient array space utilization.. important, since we've a static array */
        }
        tail--; //since we've moved all elements, one position to left...tail also moves one position to the left

        if(tail == -1)
           head = -1; //when there is no element in queue...tail=head=-1
    }
    else
    {
        printf("\nQueue is empty !"); //when head not equal to zero(or equal to -1) . queue is empty
    }
}

void insert(int element)
{
    if(head == -1) //checks whether the queue is empty
    {
        head=tail=0;
        queue[head]=element; // first element is being inserted, making head=tail=0
    }
    else if(tail<49)
    {
        tail++;
        queue[tail]=element; //tail is incremented and an element is inserted
    }
    else
    {
        printf("\n Cannot insert....Queue full !"); //queue becomes full, once we've 50 elements
    }
}

void traverse()
{
    int i;

    printf("\nPrinting elements in queue from head to tail...\n");

    if(head == -1) //checks whether the queue is empty
    {
        printf("\n Queue is empty !");
    }
    else
    {
        for(i=head;i<=tail;i++)  // traverse from head to tail
        printf("%d \t",queue[i]);
    }

}
