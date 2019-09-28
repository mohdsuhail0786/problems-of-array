//Stack implementation using singly linked list

#include <stdio.h>
#include<stdlib.h>

//creating a self refrential structure
struct node
{
    int info;
    struct node *next;
}*top=NULL;//global variable

void push();//for inserting element in the stack
void pop();//for deleting element from the stack
void display();//for displaying the elements of the stack

int main()
{
    int ch,x;
    printf("\n *******************************************************");
    printf("\n \tSTACK IMPLEMENTATION BY USING LINKED LIST");
    printf("\n *******************************************************");
    printf("\n");
    do{
    printf("\n 1. Push");
    printf("\n 2. Pop");
    printf("\n 3. Display");
    printf("\n 4. Exit");
    printf("\n Enter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        case 4: break;
        default: printf("\n Invalid choice");
    }
    printf("\n *******************************************************");
    }while(ch<=3);

    return 0;
}

void push()
{
    struct node *n;//creating pointers
    n=(struct node *)(malloc(sizeof(struct node)));//allocating memory
    if(n==NULL)
        printf("\n Hey! Memory is full, unable to allocate Memory\n");
    else
    {
        printf("\n Enter the value to push=");
        scanf("%d",&n->info);
        n->next=top;
        top=n;
    }
    printf("\n Succesfully inserted\n");
}

void pop()
{
    struct node *t;
    if(top==NULL)
    {
        printf("\n Sorry! Stack is empty\n");
        return;
    }
    t=top;
    top=top->next;
    printf("\n %d is successfully popped from the stack.\n",t->info);
    free(t);
}

void display()
{
    struct node *t;
    t=top;
    if(t==NULL)
        printf("\n Hey! Stack is empty\n");
    else
    {
        printf("\n printing elements of the stack=");
        while(t!=NULL)
        {
        printf("%d ",t->info);
        t=t->next;
        }
    }
}
