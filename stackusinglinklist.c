# include<stdio.h>
# include<conio.h>

typedef struct NODE
{
    int data;
    struct NODE *next;

}*node;

node top;
node top1;
node temp;
int count;

int main()

{
    int item,k,h,op;

FILE  *fp1=fopen("randomnumberLL.txt","w");

    for(int i=0;i<10;i++)
    {
        item=rand()%100;
        fprintf(fp1,"%d ",item);
    }
    fclose(fp1);

    FILE *fp2=fopen("randomnumberLL.txt","r");
    while(1)
   {

    printf("Enter the option\n");
    printf(" 1: push into stack\n 2:pop\n 3:display \n");
    scanf("%d",&op);
    operdis(op);
    switch(op)
    {
        case 1:fscanf(fp2,"%d",&k);
               push(k);
               pushed(k);
               break;
        case 2:
               h= pop();
               poped(h);
               break;
        case 3:
            display();
               break;
    }

   }
   fclose(fp2);

}

void push(int data)
 {
     if (top == NULL)
    {
        top =malloc(sizeof(struct NODE));
        top->next = NULL;
        top->data = data;
    }
    else
    {
        temp =malloc(sizeof(struct NODE));
        temp->next = top;
        temp->data = data;
        top = temp;
    }
    count++;
    printf("Node is Inserted\n\n");
}

int pop()
{
     top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        top1 = top1->next;
    int popped = top->data;
    free(top);
    top = top1;
    count--;
    return popped;
}

void display()
{
    // Display the elements of the stack
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }

    printf("The stack is \n");
    while (top1 != NULL)
    {
        printf("%d--->", top1->data);
        top1 = top1->next;
    }
    printf("NULL\n\n");

}
void operdis(int op)
{
  FILE *fp5=fopen("operationLL.txt","a");
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
    FILE *fp2=fopen("pushedLL.txt","a");
    fprintf(fp2,"%d ",k);
    fclose(fp2);
}
void poped(int item)
{
      FILE *fp4=fopen("popedLL.txt","a");
      fprintf(fp4,"%d ",item);
     fclose(fp4);
}
