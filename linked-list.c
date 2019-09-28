// in this program we will study about some linked list functions

#include<stdio.h>
#include<stdlib.h>

//creating a self refrential structure
struct node
{
    int info;
    struct node *next;
}*start=NULL;//global pointer start and initialising it with NULL

void insertend();//for inserting element at end
void insertbeg();//for inserting element at begining
void display();//for displaying all the elements of the list
void deletenposition();//for deleting an element given by the user
void insertnposition();//for inserting element at n position
int countelements();//for counting the no of elements in the list
void deletefront();//for deleting a element from delete
void deleteend();//for deleting a element from end
int maxelement();//for finding max element in the list
void createlist();//for creating a whole list at a time
void swapelement();//for swaping two elements of the list
void swapnodes();//for swapping two nodes of a list

void main()
{
    int ch,x;
    do{
    printf("\n 1. for insert element at end");
    printf("\n 2. for insert element at beg");
    printf("\n 3. for insert element at n'th position");
    printf("\n 4. for creating list");
    printf("\n 5. for display");
    printf("\n 6. for delete from front");
    printf("\n 7. for delete from end");
    printf("\n 8. for deleting a element at n th position");
    printf("\n 9. for count elements");
    printf("\n 10. for max element in the list");
    printf("\n 11. for swapping two elements");
    printf("\n 12. for swapping two nodes");
    printf("\n 13. for exit");
    printf("\n enter your choice=");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: insertend();
                break;
        case 2: insertbeg();
                break;
        case 3: insertnposition();
                break;
        case 4: createlist();
                break;
        case 5: display();
                break;
        case 6: deletefront();
                break;
        case 7: deleteend();
                break;
        case 8: deletenposition();
                break;
        case 9: x=countelements();
                printf("\n no. of elements in the list=%d\n",x);
                break;
        case 10: x=maxelement();
                printf("\n %d is the max element in the list\n",x);
                break;
        case 11: swapelement();
                break;
        case 12: swapnodes();
                break;
        case 13: break;
        default : printf("\n invalid choice\n");
    }
    }while(ch<=12);

}

void insertend()
{
    struct node *t,*n;//creating two pointers
    n=(struct node *)(malloc(sizeof(struct node)));//allocating memory
    if(n==NULL)
        printf("\n Hey! Memory is full, unable to allocate Memory\n");
    else
    {
        printf("\n enter the element to insert=");
        scanf("%d",&n->info);
        if(start==NULL)
        {
            n->next=NULL;
            start=n;
        }
        else
        {
            t=start;
            while(t->next!=NULL)
                t=t->next;
            t->next=n;
            n->next=NULL;
        }
    }
    printf("\n Succesfully inserted\n");
}

void insertbeg()
{
    struct node *t,*n;//creating pointers
    n=(struct node *)(malloc(sizeof(struct node)));//allocating memory
    if(n==NULL)
        printf("\n Hey! Memory is full, unable to allocate Memory\n");
    else
    {
        printf("\n enter the element to insert=");
        scanf("%d",&n->info);
        if(start==NULL)
        {
            n->next=NULL;
            start=n;
        }
        else
        {
            n->next=start;
            start=n;
        }
    }
    printf("\n Succesfully inserted\n");
}

void display()
{
    struct node *t;
    t=start;
    if(t==NULL)
        printf("\n Hey! Now list is empty\n");
    else
    {
        printf("\n printing elements of the list=");
        while(t!=NULL)
        {
        printf("%d ",t->info);
        t=t->next;
        }
    }
    printf("\n");
}

void deletenposition()
{
    struct node *t,*p;
    int info,c=0;

    t=start;
    p=start;
    if(start==NULL)
    {
        printf("\n Hey ! list is empty\n");
        return;
    }
    printf("\n enter the element to be deleted=");
    scanf("%d",&info);

    if(t->info==info && t->next==NULL)
    {
        printf("\n Succesfully deleted.\n");
        //printf("\n %d element is deleted from the list.",t->info);
        start=NULL;
        free(t);
        c++;
    }
    else
    {
        while(t->next!=NULL)
        {
            if(t->info==info)
            {
                while(p->next!=t)
                p=p->next;
                p->next=t->next;
                c++;
                free(t);
                printf("\n Succesfully deleted.\n");
                return;
            }
            else
            t=t->next;
        }
    }
    if(c==0)
    printf("\n Hey! Sorry didn't find the element in the list\n");
}

void insertnposition()
{
    int pos,i=1,count;
    struct node *t,*n;
    n=(struct node *)(malloc(sizeof(struct node)));//allocating memory
    if(n==NULL)
    {
        printf("\n Hey! Memory is full, unable to allocate Memory\n");
        return;
    }

    //checking if there is no element in the list
    if(start==NULL)
    {
        printf("\n enter the element to insert=");
        scanf("%d",&n->info);//taking element

        n->next=NULL;
        start=n;
        printf("\n Successfully inserted\n");
        return;
    }
    printf("\n enter the position you want to insert =");
    scanf("%d",&pos);//taking position

    count=countelements();//calling count element for no. of elements
    if(pos==count+1)
    {
        insertend();
        return;
    }

    if(pos==1)//checking if want to insert at the begining
    {
            printf("\n running");
            insertbeg();
            return;
    }
    else
    {
        t=start;
        while(i<pos-1)
        {
            t=t->next;
            i++;
            if(t==NULL)
            {
                printf("\n Hey! are you mad , no such position is exists\n");
                return;
            }
        }

        printf("\n enter the element to insert=");
        scanf("%d",&n->info);//taking element
        n->next=t->next;
        t->next=n;
        printf("\n Successfully inserted\n");
    }

}

int countelements()
{
    struct node *t;
    int c=0;
    if(start==NULL)
    {
        return 0;
    }
    else
    {
        t=start;
        while(t!=NULL)
        {
            c++;
            t=t->next;
        }
        return (c);
    }
}

void deletefront()
{
    struct node *t;
    if(start==NULL)
    {
        printf("\n Sorry! list is empty\n");
        return;
    }
    t=start;
    start=start->next;
    free(t);
    printf("\n Successfully deleted\n");
}

void deleteend()
{
    struct node *t,*p;
    if(start==NULL)
    {
        printf("\n Sorry! list is empty\n");
        return;
    }
    t=start;
    while(t->next!=NULL)
    {
        p=t;
        t=t->next;
    }
    p->next=NULL;
    free(t);
    printf("\n Successfully deleted\n");
}

int maxelement()
{
    int max;
    struct node *t;
    if(start==NULL)
    {
        printf("\n Sorry! list is empty\n");
        return;
    }
    t=start;
    max=t->info;
    while(t!=NULL)
    {
        if(t->info>max)
            max=t->info;
        t=t->next;
    }
    return max;
}

void createlist()
{
    int i,n;
    printf("\n enter the no of elements=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        insertend();
    }
}

void swapelement()
{
    struct node *f,*l;
    int i,temp,count,p1,p2;

    count=countelements();
    if(count<2)
    {
        printf("\n list is too short for swapping");
        return;
    }
    printf("\n enter the position of first and second node respectively=");
    scanf("%d %d",&p1,&p2);
    if(p1<=count && p1>0 && p2<=count && p2>0)
    {
        f=start;
        l=start;
        for(i=1;i<p1;i++)
            f=f->next;
        for(i=1;i<p2;i++)
            l=l->next;
        temp=f->info;
        f->info=l->info;
        l->info=temp;

        printf("\n Successfully swaped.\n");
    }
    else
    {
        printf("\n Sorry! no such position exits in the list.\n");
    }

}

void swapnodes()
{
    /*struct node *t,*p,*t1,*p1;
    int pos1,pos2,temp1,temp2,i;
    printf("\n enter the first and second position=");
    scanf("%d %d",&pos1,&pos2);
    t=start;
    p=start;
    for(i=1;i<pos1;i++)
    {
        t1=t;
        t=t->next;
    }
    for(i=1;i<pos2;i++)
    {
        p1=p;
        p=p->next;
    }
    temp1=t->next;
    t1->next=p;
    temp2=p->next;
    p->next=t->next;
    p1->next=temp1;
    t->next=temp2;*/
}
