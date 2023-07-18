#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int s;
    int f,r;
    int Q[7];
};


int main()
{
   FILE *fp=fopen("graph_Inputfile.txt","r");
   int i,j,a[7][7]={0};
   int u,v;
   while(!feof(fp))
   {
       fscanf(fp,"%d %d",&u,&v);
       a[u][v]=1;
   }
   fclose(fp);
  printf("BFS of graph is---\n");
    BFS(a,4);
}


void BFS(int a[][7],int i)
{
      struct Queue *q;
      int visited[7]={0},u,v;
      create(q,7);
      FILE *fp=fopen("BFS_outputFile.txt","w");
      printf("%d ",i);
      fprintf(fp,"%d ",i);
      enqueue(q,i);
      visited[i]=1;
      while(!isEmpty(q))
      {
        u=dequeue(q);
      for(v=1;v<7;v++)
      {
      if(a[u][v]==1 && visited[v]==0)
      {
          visited[v]=1;
          printf("%d ",v);
          fprintf(fp,"%d ",v);
          enqueue(q,v);
      }
      }
      }
      fclose(fp);
}
void create(struct Queue *q,int s)
{
    q->s=s;
    q->f=q->r=0;
}

void enqueue(struct Queue *q,int x)
{
    if(q->r==q->s-1)
    {
        printf("queue is full\n");
    }
    else
    {
        q->r++;
        q->Q[q->r]=x;
    }
}
int dequeue(struct Queue *q)
{
    int x;
    if(q->f==q->r)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->f++;
        x=q->Q[q->f];
    }
    return x;
}

int isEmpty(struct Queue *q)
{
    return q->f==q->r;
}
