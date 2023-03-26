#include<stdio.h>
int set[20],d,count=0,n,s[10];
int f=0;
void display(int);
void main()
{
    int subset(int,int);
    printf("enter the total set values:");
    scanf("%d",&n);
    printf("enter the values of set:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    printf("enter the sum:");
    scanf("%d",&d);
    subset(0,0);
    if(f==0)
    {
        printf("no solution");
    }
}
int subset(int sum,int i)
{
    if(sum==d)
    {
        f=1;
        display(count);
        return 0;
    }
    if(sum>d || i>=n)
    return 0;
    else
    {
        set[count]=s[i];
        count++;
        subset(sum+s[i],i+1);
        count--;
        subset(sum,i+1);
    }
}
void display(int count)
{
    int i;
    printf("{");
    for(i=0;i<count;i++)
        printf("%d",set[i]);
    printf("}");
}
