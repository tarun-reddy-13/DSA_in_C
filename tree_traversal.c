#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node *TREE;
TREE getnode()
{
    TREE x;
    x=(TREE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("\nNo memory alloted");
        exit(0);
    }
    return x;
}
TREE insert(TREE root,int item)
{
    TREE tem,cur,pre;
    char path[20];
    int i,len;
    tem=getnode();
    tem->data=item;
    tem->lchild=NULL;
    tem->rchild=NULL;
    if(root==NULL)
    {
        root=tem;
        return root;
    }
    printf("\nEnter the path : ");
    scanf("%s",path);
    len=strlen(path);
    pre=NULL;
    cur=root;
    i=0;
    while(i<len&&cur!=NULL)
    {
        pre=cur;
        if(path[i]=='l'||path[i]=='L')
            cur=cur->lchild;
        else if(path[i]=='r'||path[i]=='R')
            cur=cur->rchild;
        else
        {
            printf("\nInvalid path");
            free(tem);
            return root;
        }
        i++;
    }
    if(cur!=NULL||i!=len)
    {
        printf("\nInsertion not possible");
        free(tem);
        return root;
    }
    if(path[--i]=='l'||path[--i]=='L')
        pre->lchild=tem;
    else
        pre->rchild=tem;
    return root;
}
void preorder(TREE root)
{
    if(root!=NULL)
    {
        printf(" %d",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void inorder(TREE root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf(" %d",root->data);
        inorder(root->rchild);
    }
}
void postorder(TREE root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf(" %d",root->data);
    }
}
int search(TREE root,int item,int flag)
{
    if(root!=NULL)
    {
        flag=search(root->lchild,item,flag);
        if(item==root->data)
        {
            return 1;
        }
        search(root->rchild,item,flag);
    }
}
void main()
{
    TREE root;
    root=NULL;
    int choice,item,flag;
    printf("\n1. INSERTION\n2. PREORDER TRAVERSAL\
        \n3. INORDER TRAVERSAL\n4. POSTORDER TRAVERSAL\n5. SEARCH FOR AN ELEMENT\
        \n0. EXIT");
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
            case 1: printf("\nEnter the element to be inseted : ");
                    scanf("%d",&item);
                    root=insert(root,item);
                    break;
        
            case 2: if(root==NULL)
                        printf("\nTree is empty");
                    else
                    {
                        printf("\nPreorder traversal : ");
                        preorder(root);
                    }
                    break;
            case 3: if(root==NULL)
                        printf("\nTree is empty");
                    else
                    {
                        printf("\nInorder traversal : ");
                        inorder(root);
                    }
                    break;
            case 4: if(root==NULL)
                        printf("\nTree is empty");
                    else
                    {
                        printf("\nPostorder traversal : ");
                        postorder(root);
                    }
                    break;
            case 5: if(root==NULL)
                        printf("\nTree is empty");
                    else
                    {
                        printf("\nEnter the element to be searched : ");
                        scanf("%d",&item);
                        flag=0;
                        flag=search(root,item,flag);
                            if(flag==1)
                            printf("\nSeach successful");
                        else
                            printf("\nSearch unsuccessful, element not found");
                    }
                    break;
            default: printf("\nInvalid choice");
        }
        printf("\n");
    }
}















