//CALCULATION OF TIME TAKEN FOR BUBBLE SORT AND GENERATION OF RANDOM NUMBERS.

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

int i;

typedef struct node   //DECLEARING A STRUCTURE

{

    int data;

    struct node *next;

}*NODE;

NODE head,newnode,temp;

NODE head=NULL;

NODE getnode()

{

    newnode=(NODE)malloc(sizeof( struct node));   //DECLERATION OF DYNAMIC MEMORY LOCATION.

    if(newnode==NULL)

    {

        printf("\n Memory not allocated ");

        exit(0);

    }

    return(newnode);

}

NODE insert_end(int a)

{
    newnode=getnode();

    newnode->data=a;

    newnode->next=NULL;

    if(head==NULL)

    {

        head=newnode;

        return(head);

    }
    else

    {
        temp=head;

        while(temp->next!=NULL)   //TRAVERSING THE LINK LIST TILL THE END

        {

            temp=temp->next;

        }

        temp->next=newnode;

        return(head);

    }
}
void display()

{
    temp=NULL;

    if (head == NULL)

    {
        printf("LL is empty \n");

        exit(0);
    }
    else
    {
        temp = head;

        while (temp != NULL)

        {
            printf("%d ", temp->data);

            temp=temp->next;

        }

        printf("\n");

    }

}

void random(FILE *fp)

{

    for(i=0;i<20000;i++)   //GENERATION OF RANDOM NUMBER.

    {

        fprintf(fp,"%d ",rand()%100);

    }
}
void sort()

{

    int t;   //variable to swap number.

    NODE ptr,cur;

    ptr=head;

    while(ptr->next!=NULL)

    {
        cur=ptr->next;

        while(cur!=NULL)

        {
            if(ptr->data>cur->data)   //if ptr data is more than cur data then sort

            {
                t=ptr->data;

                ptr->data=cur->data;

                cur->data=t;
            }

            cur=cur->next;
        }

        ptr=ptr->next;

    }

}

void main()

{

    time_t t1,t2,t;//INITIALISING THE TIME VARIABLES.

    int a,n;

    FILE *fp;

    fp=fopen("file.txt","w");  //OPEN THE FILE FILE.TXT IN WRITE MODE.

    random(fp);

    fclose(fp);

    fp=fopen("file.txt","r");

    for(i=0;i<20000;i++)

    {

        fscanf(fp,"%d",&a);

        insert_end(a);

    }

    fclose(fp);

    t1=time(NULL);

    sort();

    t2=time(NULL);

    t=t2-t1;//CALCULATION OF TIME FOR BUBBLE SORT..

    display();

    printf("\n TIME TAKEN = %d",t);
}
