// tower of hanoi problem

#include<stdio.h>

void toh(int ,char, char, char);

void main()
{
    int n,s=1,i;
    printf("\n enter no. of plates/disk =");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        s=s*2;
    }
    printf("\n total no. of steps =%d",s-1);
    toh(n,'A','B','C');

}

void toh(int n,char s, char t, char d)
{
    if(n<1)
    return;
    else
    {
        toh(n-1,s,d,t);
        printf("\n the disk no. %d moves from %c-->%c",n,s,d);
        toh(n-1,t,s,d);
    }
}
