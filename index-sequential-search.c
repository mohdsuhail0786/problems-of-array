#include <stdio.h>
#include<stdlib.h>

void indexsearch(int*,int,int);
void lsearch(int*,int,int,int);

void quick_sort(int*,int ,int);
int partition(int*,int ,int);

int main()
{
    int i,*a,n,ele;
    printf("\n Enter the size of the array : ");
    scanf("%d",&n);
    a=(int*)(malloc(n*sizeof(int)));
    printf("\n Enter the elements of the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    quick_sort(a,0,n-1);

    printf("\n Enter the element to be searched : ");
    scanf("%d",&ele);

    indexsearch(a,n,ele);

    return 0;
}

void indexsearch(int* a,int n,int ele)
{
    int i,k=0,*b,*c,s=0;
    b=(int*)(malloc(sizeof(int)));//for decreasing the length of the array
    b[k]=a[0];//storing first element
    c=(int*)(malloc(sizeof(int)));//for storing the original indexes of the elements of the array b
    c[s]=k;
    s++;
    k++;
    for(i=3;i<n-1;i+=3)
    {
        b=realloc(b,sizeof(int));//reallocating the memory for array b
        b[k]=a[i];
        c=realloc(c,sizeof(int));//reallocating the memory for array c
        c[s]=i;
        s++;
        k++;
    }
    b=realloc(b,sizeof(int));
    b[k]=a[n-1];//storing last element
    c=realloc(c,sizeof(int));
    c[s]=n-1;
    s++;
    k++;

    if((ele<b[0])||(ele>b[k-1]))
    {
        printf("\n Didn't find element in the array.");
    }
    else
    {
        for(i=1;i<k;i++)
        {
            if(ele>=b[i-1] && ele<b[i])
            lsearch(a,c[i-1],c[i],ele);
        }
    }
}

void lsearch(int* arr,int l,int h,int ele)
{
    int i,c=0;
    for(i=l;i<=h;i++)
    {
        if(arr[i]==ele)
        {
            printf("\n Your element %d is found at %d position.",ele,i+1);
            c++;
        }
    }
    if(c==0)
    printf("\n Didn't find element in the array.");
}

void quick_sort(int* a,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=partition(a,low,high);
        quick_sort(a,low,mid-1);
        quick_sort(a,mid+1,high);
    }
}

int partition(int* a,int low ,int high)
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
