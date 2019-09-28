#include<stdio.h>
#include<stdlib.h>

//creating a self refrential structure
struct node
{
    int info;
    struct node *next;
}*start=NULL;//global variable

void insertend();//for inserting element at end
void insertbeg();//for inserting element at begining
void display();//for displaying all the elements of the list
void delete_a_element();//for deleting an element given by the user
void insertnposition();//for inserting element at n position
int countelements();//for counting the no of elements in the list
void deletefront();//for deleting a element from delete
void deleteend();//for deleting a element from end
int maxelement();//for finding max element in the list
void createlist();//for creating a whole list at a time

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
    printf("\n 8. for deleting a particular element");
    printf("\n 9. for count elements");
    printf("\n 10. for max element in the list");
    printf("\n 11. for exit");
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
        case 8: delete_a_element();
                break;
        case 9: x=countelements();
                printf("\n no. of elements in the list=%d\n",x);
                break;
        case 10: x=maxelement();
                printf("\n %d is the max element in the list\n",x);
                break;
        case 11: break;
        default : printf("\n invalid choice\n");
    }
    }while(ch<=10);

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

void delete_a_element()
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



