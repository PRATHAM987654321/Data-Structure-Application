#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node*left;
    int data;
    struct Node*right;
}*node;

node root,newnode,head,temp;
node getnode(int);
node InsertNode(node ,node);
int main()
{
    int n,ch,item,y,x,i,j;
    root=NULL;
    printf("Enter the number\n");
    scanf("%d",&n);
    printf("Enter the range of random numbers\n");
    scanf("%d %d",&y,&x);
    FILE *fp=fopen("random.txt","w");
    for(i=0;i<n;i++)
    {
        item=rand()%(y-x);
        fprintf(fp,"%d ",item);
    }
    fclose(fp);
    FILE *fp1=fopen("random.txt","r");
    while(1)
    {
        printf("Choose the option\n");
        printf("1:Insert node\n 2:Preorder\n 3:Postorder\n 4:Inorder\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: fscanf(fp1,"%d",&j);
                newnode=getnode(j);
                root=InsertNode(root,newnode);
            break;
            case 2: preorder(root);
            break;
            case 3: postorder(root);
            break;
            case 4: inorder(root);
            break;
        }
    }
   return 0;
}

node getnode(int x)
{
    newnode=(node) malloc(sizeof(struct Node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=x;
    return newnode;
}

node InsertNode(node root,node newnode)
{
    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        if(newnode->data<root->data)
        {
           root->left=InsertNode(root->left,newnode);
        }
        else if(newnode->data>root->data)
        {
            root->right=InsertNode(root->right,newnode);
        }
    }
    return root;
}

void preorder(node root)
{
    if(root!=NULL)
    {
    printf("%d--->",root->data);
    preorderfile(root->data);
    preorder(root->left);
    preorder(root->right);
    }
}
void inorder(node root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d--->",root->data);
    inorderfile(root->data);
    inorder(root->right);
    }
}
void postorder(node root)
{
    if(root!=NULL)
    {
     postorder(root->left);
     postorder(root->right);
     printf("%d--->",root->data);
     postorderfile(root->data);
    }
}
void preorderfile(int x)
{
    FILE *fp2=fopen("preorder.txt","a");
    fprintf(fp2,"%d-->",x);
    fclose(fp2);
}
void inorderfile(int x)
{
    FILE *fp3=fopen("inorder.txt","a");
    fprintf(fp3,"%d-->",x);
    fclose(fp3);
}

void postorderfile(int x)
{
    FILE *fp4=fopen("postorder.txt","a");
    fprintf(fp4,"%d-->",x);
    fclose(fp4);
}
