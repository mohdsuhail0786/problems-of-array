#include<stdio.h>

void quick_sort(int [],int ,int);
int partition(int [],int ,int);

void main()
{
    int a[50],n,i;
    printf("\n enter the no. of elements=");
    scanf("%d",&n);
    printf("\n enter elements=");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n array before sorting=");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);

    quick_sort(a,0,n-1);

    printf("\n array after sorting=");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}

void quick_sort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=partition(a,low,high);
        quick_sort(a,low,mid-1);
        quick_sort(a,mid+1,high);
    }
}

int partition(int a[],int low ,int high)
{
    int x,i,j,temp;
    i=low-1;
    x=a[high];
    for(j=low;j<high;j++)
    {
        if(a[j]<=x)
        {
            i=i+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return i+1;
}
