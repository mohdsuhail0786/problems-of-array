//Program to sort a array using HEAP SORT technique
#include <stdio.h>

int size=0; //global variable for size of the array

void insert(int[]);//to insert in MAX HEAP tree
void heapsort(int[]);//to sort the array
void display(int[]);//to display array
void swap(int *,int *);//to swap to elements

int main()
{
    int arr[50],i,n;

    printf("\n Enter the number of elements of array=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        insert(arr);
    }
    printf("\n Array in max heap=");
    display(arr);

    heapsort(arr);

    printf("\n Array after sorting=");
    display(arr);

    return 0;
}

void insert(int a[])
{
    int par,loc,value;

        printf("\n enter value=");
        scanf("%d",&value);
        size=size+1;
        loc=size;
        par=size/2;

        while(par>0)
        {
            if(value<=a[par])
            break;
            else
            {
                a[loc]=a[par];
                loc=par;
                par=par/2;
            }
        }
        a[loc]=value;
}

void display(int a[])
{
    int i;
    for(i=1;i<=size;i++)
    printf("%d ",a[i]);
}

void heapsort(int a[])
{
    int n,l,r,p;
    n=size;
    while(n>1)
    {
        p=1;
        l=2;
        r=3;
        swap(&a[1],&a[n]);
        n=n-1;
        while(r<=n)
        {
            if(a[l]>a[r])
            {
                swap(&a[l],&a[p]);
                p=l;
            }
            else
            {
                swap(&a[r],&a[p]);
                p=r;
            }
            l=2*p;
            r=l+1;
        }
        if(l==n && a[l]>a[p])
        swap(&a[l],&a[p]);
    }
}

void swap(int *a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
