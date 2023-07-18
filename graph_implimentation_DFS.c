#include<stdio.h>
#include<stdlib.h>
void DFS(int a[7][7],int u)
{
    int v;
    static int visited[7]={0};
    FILE *fp=fopen("DFS_outputFile.txt","a");
    if(visited[u]==0)
    {
        printf("%d ",u);
        fprintf(fp,"%d ",u);
        visited[u]=1;
        for(v=1;v<7;v++)
        {
            if(a[u][v]==1 && visited[v]==0)
            {
                DFS(a,v);
            }
        }
    }
}
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
  printf("DFS of graph is---\n");
    DFS(a,1);
}

