#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node*left;
    char data;
    struct Node*right;
}*node;

node root,newnode,head,temp;
node getnode(char);
node InsertNode(node ,node);
int main()
{
    int n,ch,i,item;
    char j;
    root=NULL;
    printf("Enter the number\n");
    scanf("%d",&n);
    FILE *fp=fopen("randomChar.txt","w");
    for(i=0;i<n;i++)
    {
        item=rand()%52;
        if(item<26)
        {
            item='A'+item;
        fprintf(fp,"%c ",item);
        }
        else
        {
            item='a'+(item-26);
            fprintf(fp,"%c ",item);
        }

    }
    fclose(fp);
    FILE *fp1=fopen("randomChar.txt","r");
    while(1)
    {
        printf("Choose the option\n");
        printf("1:Insert node\n 2:Preorder\n 3:Postorder\n 4:Inorder\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: fscanf(fp1," %c",&j);
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

node getnode(char x)
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
    printf("%c--->",root->data);
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
    printf("%c--->",root->data);
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
     printf("%c--->",root->data);
     postorderfile(root->data);
    }
}
void preorderfile(char x)
{
    FILE *fp2=fopen("preorderChar.txt","a");
    fprintf(fp2,"%c-->",x);
    fclose(fp2);
}
void inorderfile(char x)
{
    FILE *fp3=fopen("inorderChar.txt","a");
    fprintf(fp3,"%c-->",x);
    fclose(fp3);
}

void postorderfile(char x)
{
    FILE *fp4=fopen("postorderChar.txt","a");
    fprintf(fp4,"%c-->",x);
    fclose(fp4);
}
