
#include <stdio.h>
int m,n;
int sol=0,c=0;
int x[10],g[10][10];
void gc(int k);
void nv(int k);
int main()
{
    int i,j;
    printf("enter no of vertices in graph:");
    scanf("%d",&n);
    printf("enter the adj mat:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    printf("the solutions are:");
    for(m=1;m<=n;m++)
    {
    if(c==1)
    {
        break;
    }
        gc(1);
    }
    printf("the chrom num is %d",m-1);
    printf("the total sols poss are:%d",sol);
    return 0;
}
void gc(int k)
{
    int i;
    while(1)
    {
        nv(k);
        if(x[k]==0)
        {
            return;
        }
        if(k==n)
        {
            c=1;
            for(i=1;i<=n;i++)
            {
                printf("%d",x[i]);
            }
            sol++;
            printf("\n");
        }
        else
        {
            gc(k+1);
        }
    }
}
void nv(int k)
{
    int j;
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
        {
            return;
        }
        for(j=1;j<=n;j++)
        {
            if(g[k][j]==1 && x[k]==x[j])
            {
                break;
            }
        }
        if(j==(n+1))
        {
            return;
        }
    }
}
