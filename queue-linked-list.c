//Queue using singly linked list

#include <stdio.h>
#include<stdlib.h>

//creating a self refrential structure
struct node
{
    int info;
    struct node *next;
}*front=NULL,*rear=NULL;//global variable

void insert();//for inserting element in the queue
void del();//for deleting element from queue
void display();//for displaying all the elements of the queue
int countelements();//for counting elements in the queue

int main()
{
    int ch,x;
    printf("\n ********************************************");
    printf("\n    QUEUE IMPLEMENTATION BY LINKED LIST");
    printf("\n ********************************************");
    printf("\n");
    do{
    printf("\n 1. Insert");
    printf("\n 2. Delete");
    printf("\n 3. Display");
    printf("\n 4. Count Elements");
    printf("\n 5. Exit");
    printf("\n Enter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: insert();
                break;
        case 2: del();
                break;
        case 3: display();
                break;
        case 4: x=countelements();
                printf("\n There are %d elements in the Queue.",x);
                break;
        case 5: break;
        default: printf("\n Invalid Input.");
    }
    printf("\n ********************************************");
    }while(ch<=4);

    return 0;
}

void insert()
{
    struct node *t,*n;//creating two pointers
    n=(struct node *)(malloc(sizeof(struct node)));//allocating memory
    if(n==NULL)
        printf("\n Hey! Memory is full, unable to allocate Memory\n");
    else
    {
        printf("\n Enter the element to insert=");
        scanf("%d",&n->info);
        n->next=NULL;
        if(rear==NULL)
        {
            front=n;
            rear=n;
        }
        else
        {
            rear->next=n;
            rear=n;
        }
    }
    printf("\n Succesfully inserted");
}

void del()
{
    struct node *t;
    if(front==NULL)
    {
        printf("\n Sorry! Queue is empty\n");
        return;
    }
    t=front;
    if(front->next==NULL)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        front=front->next;
    }
    printf("\n %d is successfully deleted.",t->info);
    free(t);
}

void display()
{
    struct node *t;
    t=front;
    if(t==NULL)
        printf("\n Hey! Queue is empty\n");
    else
    {
        printf("\n Printing elements of the queue=");
        while(t!=NULL)
        {
        printf("%d ",t->info);
        t=t->next;
        }
    }
}

int countelements()
{
    struct node *t;
    int c=0;
    if(front==NULL)
    {
        return 0;
    }
    else
    {
        t=front;
        while(t!=NULL)
        {
            c++;
            t=t->next;
        }
        return c;
    }
}

