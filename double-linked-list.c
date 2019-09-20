#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next,*prev;
}*start=NULL;

void dinsertbeg();//for inserting element in begining of the doubly list
void dinsertend();//for inserting element in end of the doubly list
void dinsertnposition();//for inserting element in between of the doubly list
void display();//for displaying all the elements of the list
void ddeletebeg();//for deleting element from begining of the doubly list
void ddeleteend();//for deleting element from end of the doubly list
void ddeletenposition();//for deleting element from any position of the doubly list
int countelements();//for counting number of elements in the list
int maxelement();//for computing the max element in the list
void createlist();//for creating more than one node at a time
void reverselist();//for printing the list in revrse order

void main()
{
    int ch,x;
    do{
    printf("\n Menu...");
    printf("\n 1.  for insert in beg");
    printf("\n 2.  for insert in end");
    printf("\n 3.  for insert at n position");
    printf("\n 4.  for create list");
    printf("\n 5.  for display");
    printf("\n 6.  for delete from beg");
    printf("\n 7.  for delete from end");
    printf("\n 8.  for delete at a position");
    printf("\n 9.  for count no of elements");
    printf("\n 10. for find max element");
    printf("\n 11. for print reverse of the list");
    printf("\n 12. for exit");
    printf("\n enter your choice=");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: dinsertbeg();
                break;
        case 2: dinsertend();
                break;
        case 3: dinsertnposition();
                break;
        case 4: createlist();
                break;
        case 5: display();
                break;
        case 6: ddeletebeg();
                break;
        case 7: ddeleteend();
                break;
        case 8: ddeletenposition();
                break;
        case 9: x=countelements();
                printf("\n total elements in the list=%d\n",x);
                break;
        case 10:x=maxelement();
                 printf("\n max element in the list=%d\n",x);
                 break;
        case 11:reverselist();
                break;
        case 12:break;
        default: printf("\n Wrong input. Please input right one.");
    }
    }while(ch<=11);
}

void dinsertbeg()
{
    struct node *n;
    n=(struct node*)(malloc(sizeof(struct node)));
    if(n==NULL)
    {
        printf("\n Memory is full.Unable to allocate memory");
        return;
    }
    printf("\n enter the element=");
    scanf("%d",&n->info);
    n->prev=NULL;
    n->next=start;
    start=n;
    printf("\n Succesfully inserted.\n");
}

void dinsertend()
{
    struct node *t,*n;
    n=(struct node*)(malloc(sizeof(struct node)));
    if(n==NULL)
    {
        printf("\n Memory is full.Unable to allocate memory");
        return;
    }
    printf("\n enter the element=");
    scanf("%d",&n->info);
    n->next=NULL;
    if(start==NULL)
    {
        n->prev=NULL;
        start=n;
    }
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
        n->prev=t;
    }
    printf("\n Succesfully inserted.\n");
}

void dinsertnposition()
{
    int i=1,pos,count;
    struct node *n,*temp,*t;
    n=(struct node*)(malloc(sizeof(struct node)));
    if(n==NULL)
    {
        printf("\n Memory is full.Unable to allocate memory");
        return;
    }

    if(start==NULL)
    {
        printf("\n enter the element=");
        scanf("%d",&n->info);
        n->next=NULL;
        n->prev=NULL;
        start=n;
        printf("\n Succesfully inserted.\n");
        return;
    }
    printf("\n enter the position of the element=");
    scanf("%d",&pos);
    count=countelements();
    if(pos==count+1)
    {
        dinsertend();
    }
    else if(pos==1)
    {
        dinsertbeg();
    }
    else
    {
        printf("\n enter the element=");
        scanf("%d",&n->info);
        t=start;
        for(i=1;i<=pos-2;i++)
            t=t->next;
        temp=t->next;
        n->next=temp;
        temp->prev=n;
        t->next=n;
        n->prev=t;
    }

}

void display()
{
    struct node *t;
    t=start;
    if(start==NULL)
    {
        printf("\n Hey! list is empty.\n");
        return;
    }
    else
    {
        printf("\n printing the elements of the list=");
        while(t!=NULL)
        {
            printf("%d ",t->info);
            t=t->next;
        }
    }
    printf("\n");
}

void ddeletebeg()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("\n Sorry! List is empty.\n");
        return;
    }
    else
    {
        temp=start;
        start=start->next;
        if(start!=NULL)
        start->prev=NULL;
        free(temp);
        printf("\n Succesfully deleted.\n");
    }
}

void ddeleteend()
{
    struct node *t,*p;
    if(start==NULL)
    {
        printf("\n Sorry! List is empty.\n");
        return;
    }
    else if(start->next==NULL)
    {
        t=start;
        start=NULL;
        free(t);
        printf("\n Succesfully deleted.\n");
    }
    else
    {
        t=start;
        while(t->next!=NULL)
        {
            p=t;
            t=t->next;
        }
        p->next=NULL;
        free(t);
        printf("\n Succesfully deleted.\n");
    }
}

void ddeletenposition()
{
    struct node *t,*p,*temp;
    int pos,i,count;
    if(start==NULL)
    {
        printf("\n Sorry! list is empty.\n");
        return;
    }
    count=countelements();
    printf("\n enter the position you want to delete=");
    scanf("%d",&pos);
    if(pos==1)
    {

        ddeletebeg();
    }
    else if(pos==count)
    {
        ddeleteend();
    }
    else
    {
        temp=start;
        for(i=1;i<=pos-1;i++)
            {
                temp=temp->next;
                if(temp==NULL)
                {
                    printf("\n Sorry! this position does not exist.\n");
                    return;
                }
            }
        p=temp->prev;
        t=temp->next;
        p->next=t;
        t->prev=p;
        free(temp);
        printf("\n Succesfully deleted.\n");
    }
}

int countelements()
{
    struct node *t;
    int c=0;
    if(start==NULL)
    return 0;
    else
    {
        t=start;
        while(t!=NULL)
        {
            c++;
            t=t->next;
        }
        return c;
    }
}

int maxelement()
{
    struct node *t;
    int max;
    if(start==NULL)
    {
        printf("\n Hey! list is empty.\n");
        return;
    }
    else
    {
        t=start;
        max=start->info;
        while(t!=NULL)
        {
            if(t->info>max)
                max=t->info;
            t=t->next;
        }
        return max;
    }
}

void createlist()
{
    int n,i;
    printf("\n enter the no of the elements=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        dinsertend();
    }
}

void reverselist()
{
    struct node *t,*p;
    t=start;
    if(start==NULL)
    {
        printf("\n Sorry! list is empty.\n");
        return;
    }
    while(t->next!=NULL)
        t=t->next;
    p=t;
    printf("\n printing the list in reverse order=");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->prev;
    }
}
