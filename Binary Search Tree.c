#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node * newnode(int item)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}
struct node * insert(struct node *node,int key)
{
    if(node==NULL)return newnode(key);
    if(key<node->data)
        node->left=insert(node->left,key);
    else if(key>node->data)
        node->right=insert(node->right,key);
    return node;
}
int search(struct node *root,int key)
{
    if(root==NULL)return -1;
    if(root->data==key)return 1;
    if(root->data>key)return search(root->left,key);
    return search(root->right,key);
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *root=NULL;
    int n,ch,i,ele,f;
    while(1)
    {
        printf("1.Create\n2.Traverse In order\n3.Search \n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of nodes\n");
                    scanf("%d",&n);
                    for(i=1;i<=n;i++)
                    {
                        printf("Enter element\n");
                        scanf("%d",&ele);
                        root=insert(root,ele);
                    }
                    break;
            case 2:inorder(root);
                    break;
            case 3:printf("Enter element\n");
                   scanf("%d",&ele);
                   f=search(root,ele);
                   if(f==1)
                    printf("Found");
                   else
                    printf("Not found");
                   break;
            case 4:exit(0);
        }
    }
    return 0;
}

