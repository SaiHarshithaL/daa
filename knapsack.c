#include <stdio.h>
void knapsack(int n,float weight[],float profit[],float max,int k[])
{
    float x[20],p=0,t;
    int i,j,m;
    m=max;
    for(i=0;i<n;i++)
    {
        x[i]=0.0;
    }
    for(i=0;i<n;i++)
    {
        if(weight[i]>m)
        {
            break;
        }
        else
        {
            x[i]=1.0;
            p=p+profit[i];
            m=m-weight[i];
        }
    }
    if(i<n)
    x[i]=m/weight[i];
    p=p+(x[i]*profit[i]);
    printf("the solution array is:");
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++){
            if(k[i]>k[j])
            {
                t=k[i];
                k[i]=k[j];
                k[j]=t;
                t=x[i];
                x[i]=x[j];
                x[j]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
    }
    printf("\nthe amximum profit is:%f",p);
}

int main()
{
    float weight[20],profit[20],ratio[20],t;
    int i,j,n,max,k[20];
    printf("Enter the maximum capacity");
    scanf("%d",&max);
    printf("enter total no of objects");
    scanf("%d",&n);
    printf("eneter the weights of the objects");
    for(i=0;i<n;i++)
    {
        k[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%f",&weight[i]);
    }
    printf("eneter the profits of the objects");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&profit[i]);
    }
    for(int i=0;i<n;i++)
    {
        ratio[i]=profit[i]/weight[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                t=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=t;
                t=weight[i];
                weight[i]=weight[j];
                weight[j]=t;
                t=profit[i];
                profit[i]=profit[j];
                profit[j]=t;
                t=k[i];
                k[i]=k[j];
                k[j]=t;
            }
        }
    }
    knapsack(n,weight,profit,max,k);
    return 0;
}

