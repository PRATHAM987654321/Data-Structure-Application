#include<stdio.h>
#define SIZE 10

int search(int H[],int key)
{
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=key)
    {
        i++;
    }
    return (index+i)%SIZE;
}
int hash(int key)
{
    return key%SIZE;
}

int probe(int H[],int key)
{
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
    {
        i++;
    }
    return (index+i)%SIZE;
}
void insert(int H[],int key)
{
  int index=hash(key);
  if(H[index]!=0)
  index=probe(H,key);
  H[index]=key;
}
int main()
{
    int H[10]={0},n,x;
    for(int i=0;i<SIZE;i++)
    {
        printf("%d ",H[i]);
    }
   printf("No of elements\n");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       printf("Enter the element\n");
       scanf("%d",&x);
       insert(H,x);
   }
    for(int i=0;i<SIZE;i++)
    {
        printf("%d ",H[i]);
    }
    printf("\nKey found at %d\n",abs(search(H,23)));
}
