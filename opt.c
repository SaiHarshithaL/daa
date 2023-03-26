#include<stdio.h>
void sort(int f[100],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(f[i]>f[j]){
            temp=f[i];
            f[i]=f[j];
            f[j]=temp;
            }
        }
    }
}
void optimalmerge(int f[100],int n)
{
    int minimum=0,k;
    while(n>1)
    {
        sort(f,n);
        printf("\nmerge %d and %d, cost is %d",f[0],f[1],f[0]+f[1]);
        minimum+=f[0]+f[1];
        k=f[0]+f[1];
        f[1]=f[1]+f[0];
        for(int i=0; i<n-1; i++)
            f[i] = f[i + 1];
        n--;
        
    }
    printf("\nOptimal cost is:%d",minimum);
}
int main()
{
    int n;
    printf("Enter number of records:");
    scanf("%d",&n);
    int f[n];
    printf("Enter number of files in each record");
    for(int i=0;i<n;i++)
        scanf("%d",&f[i]);
    optimalmerge(f,n);
}
