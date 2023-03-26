#include <stdio.h>
int min,max;
int a[100];
void minmax(int i,int j)
{
   int min1,max1,mid;
   if(i==j)
   {
       max=a[i];
       min=a[i];
   }
   else if(i==j-1)
   {
       if(a[i]<a[j])
       {
           max=a[j];
           min=a[i];
       }
       else
       {
           max=a[i];
           min=a[j];
       }
   }
   else
   {
       mid=(i+j)/2;
       minmax(1,mid);
       max1=max;
       min1=min;
       minmax(mid+1,j);
       if(max<max1)
       {
           max=max1;
       }
       if(min>min1)
       {
           min=min1;
       }
   }
}
int main()
{
    int i,n;
    printf("Enter the size of array");
    scanf("%d",&n);
    printf("Enter the array elements");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);        
    }
    max=-1;
    min=9999;
    minmax(1,n);
    printf("\nmaximum element is: %d",max);
    printf("\nminimum element is: %d",min);
    return 0;
}

