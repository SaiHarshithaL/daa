#include<stdio.h>
#include<stdlib.h>
struct node
{
    int weight;
    struct node *left,*right;
};
struct heapn
{
    int size;
    int capacity;
    struct node **array;
};
struct node *newnode(int weight)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->left=temp->right=NULL;
    temp->weight=weight;
    return temp;
}
struct heapn *createminheap(int capacity)
{
    struct heapn *minheap=(struct heapn*)malloc(sizeof(struct heapn));
    minheap->size=0;
    minheap->capacity=capacity;
    minheap->array=(struct node**)malloc(minheap->capacity*sizeof(struct node*));
    return minheap;
}
void swapnode(struct node **n1,struct node **n2)
{
    struct node *t=*n1;
    *n1=*n2;
    *n2=t;
}
void heapify(struct heapn *minheap,int idx)
{
    int min=idx;
    int left=2*idx+1;
    int right=2*idx+2;
    if(left<minheap->size && minheap->array[left]->weight< minheap->array[min]->weight)
        min=left;
    if(right<minheap->size && minheap->array[right]->weight< minheap->array[min]->weight)
        min=right;
    if(min!=idx)
    {
        swapnode(&minheap->array[min],&minheap->array[idx]);
        heapify(minheap,min);
    }
}
struct node *extractmin(struct heapn *minheap)
{
    struct node *temp=minheap->array[0];
    minheap->array[0]=minheap->array[minheap->size-1];
    --minheap->size;
    heapify(minheap,0);
    return temp;
}
void insertnew(struct heapn *minheap,struct node *minh)
{
    ++minheap->size;
    int i=minheap->size-1;
    if(i&&minh->weight<minheap->array[(i-1)/2]->weight)
    {
        minheap->array[i]=minheap->array[(i-1)/2];
        i=(i-1)/2;
    }
    minheap->array[i]=minh;
}
void buildheap(struct heapn *minheap)
{
    int n=minheap->size-1;
    int i;
    for(i=(n-1)/2;i>=0;--i)
        heapify(minheap,i);
}
struct heapn *create(int d[],int size)
{
    struct heapn *minheap=createminheap(size);
    for(int i=0;i<size;++i)
        minheap->array[i]=newnode(d[i]);
    minheap->size=size;
    buildheap(minheap);
    return minheap;
}
struct node *optt(int d[],int size)
{
    struct heapn *minheap=create(d,size);
    struct node *left,*right,*top;
    int i=0,tot=0,t;
    while(!(minheap->size==1))
    {
    left=extractmin(minheap);
    right=extractmin(minheap);
    t=left->weight+right->weight;
    tot=tot+t;
    printf("%d and %d = %d",left->weight,right->weight,t);
    top=newnode(left->weight+right->weight);
    top->left=left;
    top->right=right;
    insertnew(minheap,top);
    }
    printf("total merge cost: %d",tot);
    return extractmin(minheap);
}
int main()
{
    int fr[10],n,i;
    printf("enter the no of files:");
    scanf("%d",&n);
    printf("enter the records of files:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&fr[i]);
    }
    struct node *root=optt(fr,n);
    
}
