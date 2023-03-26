
#include <stdio.h>
int m,n;
int sol=0,c=0;
int x[10],g[10][10];
void dc();
void nv(int k);
void hamil(int k)
{
    int i;
    while(1)
    {
        nv(k);
        if(x[k]==0)
            return;
        if(k==n)
        {
            c=c+1;
            dc();
        }
        else
        {
            hamil(k+1);
        }
    }
}
void nv(int k)
{
    int j;
    while(1)
    {
        x[k]=(x[k]+1)%(n+1);
        if(x[k]==0)
            return;
        if(g[x[k-1]][x[k]]!=0)
        {
            for(j=1;j<=n;j++)
            {
                if(x[j]==x[k])
                {
                    break;
                }
            }
            if(j==k)
            {
                if(k<n ||(k==n) && (g[x[n]][x[1]]!=0))
                {
                    return;
                }
            }
        }
    }
}
void dc()
{
    int i;
    for(int i=1;i<=n;i++)
        printf("%d",x[i]);
    printf("%d",x[1]);
    printf("\n");
}
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
    for(i=1;i<=n;i++)
    {
        x[i]=0;
    }
    x[1]=1;
    printf("the pos cyc are");
    hamil(2);
    printf("tot sol are:%d",c);
    if(c==0)
    {
        printf("no sol possiblr");
    }
}

