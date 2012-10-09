//program to implement doubly linked list

#include <stdio.h>
#include <dos.h>

void insert_start(int); //function inserts an element at the start of the list
void insert_end(int); //function inserts an element at the end of the list
void remove_start(); //removes element from the start
void remove_end(); //removes element from the end
void search_remove(); //searches for an element...if found removes it
void head_to_tail(); //head to tail traversal
void tail_to_head(); //tail to head traversal

struct doubly_linked_list
{
    int data;
    struct doubly_linked_list * next; //points to the next node
    struct doubly_linked_list * prev; //points to the previous node
};

typedef struct doubly_linked_list node;

node *head , *tail, *tp , *tp1,*tp2;

void main()
{
    char choice;
    int element;

    while(1)
    {
        printf("\nEnter your choice....\n");
        printf("\n1. Insert element at start");
        printf("\n2. Insert element at end");
        printf("\n3. Remove element from start");
        printf("\n4. Remove element from end");
        printf("\n5. Search and remove");
        printf("\n6. Traverse from head to tail");
        printf("\n7. Traverse from tail to head");

        choice = getch();

        switch(choice) //determines the action to be performed, based on the choice
        {
            case '1' : printf("\nEnter element to be inserted ?");
                       scanf("%d",&element);
                       insert_start(element);
                       break;

            case '2' : printf("\nEnter element to be inserted ?");
                       scanf("%d",&element);
                       insert_end(element);
                       break;

            case '3' : remove_start();
                       break;

            case '4' : remove_end();
                       break;

            case '5' : search_remove();
                       break;

            case '6' : head_to_tail();
                       break;

            case '7' : tail_to_head();
                       break;

            default  : exit(0);
                       break;
        }
    }



}


void insert_start(int element)
{
    tp=(node*)malloc(sizeof(node)); //allocate memory for the node
    tp->data = element; //element inserted to the newly created node

    if(head==NULL)// checks if list is empty
    {
        tp->next = NULL;
        tp->prev = NULL;
        head=tail=tp; //make head and tail point to the only element
        printf("\nFirst element inserted !");
    }
    else
    {
        tp->next = head; //make next pointer of current element point to head
        tp->prev = NULL;
        head->prev=tp; //head->prev points to the new node
        head = tp; //making new node as the head
        printf("\nInsert success !");
    }
    getch();
}

void insert_end(int element)
{
    tp=(node*)malloc(sizeof(node));
    tp->data = element;

    if(head==NULL)//checks if list is empty
    {
        tp->next = NULL;
        tp->prev = NULL;
        head=tail=tp; //insert node and makes head and tail point to the new node
        printf("\nFirst element inserted !");
    }
    else if(head->next == NULL)//checks if list contain only one element
    {
        tp->prev = head; //prev of new node points to current head
        tp->next = NULL; //next of new node is made NULL
        head->next = tp;
        tail=tp; //make tail point to the last node
        printf("\nInsert success !");
    }
    else
    {
        /*make tail->next point to new element and new node's prev point to tail...
        make new node as tail*/
        tp->prev=tail;
        tail->next=tp;
        tp->next = NULL;
        tail=tp;
        printf("\nInsert Success !");
    }
    getch();
}

void remove_start()
{

    if(head==NULL)//checks if list is empty
    {
        printf("\n List is empty !");
    }
    else if(head->next == NULL)//checks whether list has only one element
    {
        printf("\nSuccessfully removed %d",head->data);
        head=0;
    }
    else
    {
        printf("\nSuccessfully removed %d",head->data);
        head = head->next; //make head point to the next element in the list
        head->prev = NULL;
    }
    getch();
}

void remove_end()
{
    if(head==NULL)//checks whether list is empty
    {
        printf("\nList is empty !");
    }
    else if(head->next == NULL)//checks if list has only one element
    {
        printf("\nSuccessfully removed %d",head->data);
        head=0;
    }
    else
    {
        printf("\nSuccessfully removed %d",tail->data);
        tail = tail->prev; //make tail point to the previous element
        tail->next = NULL;
    }
    getch();
}

void search_remove()
{
    int element,flag=0,last=0;
    tp=head;

    printf("\n Enter element to be removed ?");
    scanf("%d",&element); //gets the element to be searched and removed


    if(head == NULL)//checks to see whether the list is empty
    printf("\n List empty !");
    else
    {
        if(head->data == element)//checks if head contains the searched element
        {
            if(head->next != NULL)//if there are more than 1 element in the list
            {
                head=head->next;
                head->prev = NULL;
            }
            else
            {
                printf("\n Successfully removed %d",element); //if head is the only element
                head = 0;
            }

        }
        else
        {
            while(tp->next != NULL)
            {
                if(tp->data == element)
                {
                    /*loop iterates till we find the element....once the lement is found flag is set to 1
                    and exists from loop*/
                    flag=1;
                    break;
                }
                tp=tp->next; //goto next element
            }

            if(tp->data == element) //if its the last element
            {
                last=1;
                tail=tail->prev;
                tail->next=NULL;
            }

            if((flag==1)&&(last==0))//checks to see whether the element has been found
            {
                printf("\n Successfully removed %d",tp->data);
                tp1=tp->prev;
                tp2=tp->next;
                tp1->next = tp2;
                tp2->prev = tp1;
                /*tp is our element to be removed...tp1 holds the pointer to the previous element of tp...
                tp2 holds the pointer to the next element after tp*/
            }
            else
            {
                if(last==0)
                printf("\n Element not found in list !");
            }

        }

    }
    getch();
}

void head_to_tail()
{
    tp=head;

    if(head==NULL)//checks to see if the list is empty
    {
        printf("\n LIst empty !");
    }
    else if(head->next == NULL)//checks to see whether the list has only one element
    {
        printf("\n Only element in list is %d",head->data);
    }
    else
    {
        printf("\n Printing list...\n");
        while(tp->next != NULL)
        {
            /*loop condition turns false when the last element is encountered...so
            the printf in loop prints only up to the 2nd last element in the list*/
            printf("\t%d",tp->data);
            tp=tp->next;
        }
        printf("\t%d",tp->data);//last element in the list is being printed
    }
    getch();

}

void tail_to_head()
{
    tp=tail;

    if(tp==NULL)//checks to see if the list is empty
    {
        printf("\n List is empty !");
    }
    else if(tp->prev == NULL)
    {
        printf("\n Only element in list is %d",tail->data);//checks to see whether the list has only one element
    }
    else
    {
        printf("\n Printing elements....\n");
        while(tp->prev != NULL)
        {
            /*loop condition turns false when the first element is encountered...so
            the printf in loop prints only up to the 2nd element in the list*/
            printf("\t%d",tp->data);
            tp=tp->prev;
        }
        printf("\t%d",tp->data);//first element in the list gets printed
    }
    getch();
}
