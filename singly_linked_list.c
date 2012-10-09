//program to implement a singly linked list

#include <stdio.h>
#include <stdlib.h>

void insert(int); //inserts an element to the linked list
void remove_end_ele(); //removes the last element from the linked list
void remove_start_ele(); //removes the head element from the linked list
void search_remove(); //searches for an element and removes it
void traverse(); //traverse the linked list from head

struct linked_list
{ //structure defines the linked list with one data item and the next pointer,which points to the next link
    int data;
    struct node * next; //points to the next node in the list
};

typedef struct linked_list node;

node *head, *tp,*tp1;

void main()
{
    char choice;
    int element;

    while(1)
    {
        printf("\nEnter choice...\n");
        printf("\n1. Insert element to linked list");
        printf("\n2. Remove element from end of linked list");
        printf("\n3. Remove element from start of linked list");
        printf("\n4. Search and remove element");
        printf("\n5. Linked list traversal");

        choice = getch();

        switch(choice)//determines which case to be executed based on the choice
        {
            case '1' : printf("\nEnter element to be inserted ...");
                       scanf("%d",&element);
                       insert(element); //element to be inserted is taken and the function called
                       break;

            case '2' : remove_end_ele();
                       break;

            case '3' : remove_start_ele();
                       break;

            case '4' : search_remove();
                       break;

            case '5' : traverse();
                       break;

            default  : exit(0);
                       break;
        }


    }

}

void insert(int element)
{
    if(head == NULL) //checks whether the linked list is empty or not
    {
        head = (node*)malloc(sizeof(node)); //allocates memory for the head, since list is empty...new node is the head
        head->data = element;
        head->next = NULL;
        printf("\n First element inserted to linked list : %d",element);
    }
    else
    {
        tp=head;

        while(tp->next != NULL) //traverse until we reach the last node in the list
        tp=tp->next;

        tp1=(node*)malloc(sizeof(node)); //allocates memory for the node
        tp1->data = element;
        tp1->next = NULL;
        tp->next = tp1; //new node is added to the end of the linked list
        printf("\nElement inserted to linked list : %d",element);
    }

}

void traverse()
{
    if(head == NULL)
    {
        printf("\nLinked list is empty");
    }
    else
    {
        tp=head;

        printf("\n");

        while(tp->next != NULL) //while loop exits once the last element in the list is reached
        {
            printf("\t%d",tp->data); //prints data of all elements except the last element
            tp=tp->next;
        }

        printf("\t%d",tp->data); //prints data of the last node
    }
}

void remove_end_ele()
{
    if(head==NULL)
    {
        printf("\nLinked list empty !");
    }
    else if(head->next == NULL)
    {
        head = 0; //list has one element...head...when it is removed, list becomes NULL
    }
    else
    {
        tp=head;//points to first node
        tp1=head->next; //points to second node

        while(tp1->next != NULL)
        {
            tp1=tp1->next; //traverses till the last element...tp1 will be the last node
            tp=tp->next; //this will be the second last node
        }

        tp->next = NULL; //making second_last->next as NULL...ensures the removal of the last element
    }
}

void remove_start_ele()
{

    if(head==NULL)
    {
        printf("\nLinked list empty !");
    }
    else if(head->next == NULL)
    {
        printf("\nElement removed is %d",head->data);
        head=0; //only node in the list...head...will get removed
    }
    else
    {
        head = head->next; //head is made to point to the next node
    }

}

void search_remove()
{
    int search_ele,flag=0;

    printf("\nEnter element to be searched and removed ?");
    scanf("%d",&search_ele);

    if(head == 0)
    {
        printf("\n Linked list empty !");
    }
    else
    {
        tp=head->next; //points to second node in the list
        tp1=head; //points to the head node

        if(search_ele == head->data) //checks is element searched is in the head
        {
            printf("\nSuccessfully removed %d",head->data);

            if(head->next == NULL)
            head = 0;
            else
            head = head->next;
        }
        else if(search_ele == tp->data)//checks if element searched is the 2nd node
        {
            printf("\nSuccessfully removed %d",tp->data);

            head->next = tp->next;
        }
        else
        {
            while(tp->next != NULL)
            {
                if(tp->data == search_ele)
                {
                    flag=1;
                    break;
                /*loop iterates till the searched element is found...once found flag is set
                to 1 and breaks from the loop*/
                }

                tp=tp->next;
                tp1=tp1->next;
            /* when loop exitx with flag 1. tp holds the node to be removed, tp1
            points to the node that comes before tp*/
            }

            if(flag==1)
            {
                printf("\nSuccessfully removed %d",tp->data);
                tp1->next = tp->next; //this step essentially removes node tp
            }
        }
    }



}

