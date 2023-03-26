#include<stdio.h>
int min(int,int);
void floyds(int c[10][10],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j)
                    c[i][j]=0;
                else
                    c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
}
int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void main()
{
    int c[10][10],e,u,v,n,w,i,j;
    printf("enter the no of vertices:");
    scanf("%d",&n);
    printf("enter the no of edges:");
    scanf("%d",&e);
    printf("enter the edges and their weights:");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            c[i][j]=999;
    }
     for(i=1;i<=e;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        c[u][v]=w;
    }
    printf("\nthe original matrix is:");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d\t",c[i][j]);
        printf("\n");
    }
    floyds(c,n);
    printf("\nafter matrix is:");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d\t",c[i][j]);
        printf("\n");
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
                printf("\n the shortest paths from %d to %d is %d",i,j,c[i][j]);
        }
}
