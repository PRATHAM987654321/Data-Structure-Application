#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define n 10

struct stack
{
    int data[n];
    int top;
};

int main()
{
    struct stack p[10],*sp;
    sp=&p;
    int top;
    int op,item;
    sp->top=-1;
    FILE  *fp1=fopen("randomNo.txt","w");

    for(int i=0;i<n;i++)
    {
        item=rand()%100;
        fprintf(fp1,"%d ",item);
    }
    fclose(fp1);
    int k;
    FILE *fp2=fopen("randomNo.txt","r");
    while(1)
   {

    printf("Enter the option\n");
    printf(" 1: push into stack\n 2:pop\n 3:display \n");
    scanf("%d",&op);
    operdis(op);
    switch(op)
    {
        case 1:fscanf(fp2,"%d",&k);
               push(sp,k);
               pushed(k);
               break;
        case 2:
                pop(sp);
               break;
        case 3:
            display(sp);
               break;
    }

   }
   fclose(fp2);

}
void operdis(int op)
{
  FILE *fp5=fopen("operation.txt","a");
    char str1[]="push()";
    char str2[]="pop()";
    if(op==1)
    {
        fprintf(fp5,"%s\n",str1);
    }
    else if(op==2)
    {
        fprintf(fp5,"%s\n",str2);
    }
    fclose(fp5);
}

void pushed(int k)
{
    FILE *fp2=fopen("pushed.txt","a");
    fprintf(fp2,"%d ",k);
    fclose(fp2);
}
void poped(int item)
{
      FILE *fp4=fopen("poped.txt","a");
      fprintf(fp4,"%d ",item);
     fclose(fp4);
}
void push(struct stack *sp,int item)
{
    if(sp->top==n-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        sp->top++;
        sp->data[sp->top]=item;
    }

}

void pop(struct stack *sp)
{
    int item;
    if(sp->top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        item=sp->data[sp->top];
        sp->top--;
        printf("%d\n",item);
        poped(item);
    }

}
void display(struct stack *sp)
{
    if(sp->top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        while(sp->top!=-1)
        {
            printf("%d\n",sp->data[sp->top]);
            sp->top--;
        }
    }
}
