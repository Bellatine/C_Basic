#include<stdio.h>
#include<string.h>
typedef struct node
{
    int gt;
    struct node* left;
    struct node* right;
}node;
node* root;
node* makenode(int a)
{
    node* p=(node*)malloc(sizeof(node));
    p->gt=a;
    p->left=NULL;
    p->right=NULL;
    return p;
}
node* find(node*r, int a)
{
    if(r==NULL) return NULL;
    if(r->gt==a) return r;
    node* p=r->left;
    while(p!=NULL)
    {
        node* q=find(p, a);
        if(q!=NULL) return q;
        p=p->right;
    }
}
void addleft(int r, int l)
{
    node* p=find(root, r);
    if(p==NULL) return;
    if(p->left==NULL) p->left=makenode(l);
    else printf("already");
    return;
}
void addright(int r, int r)
{
    node* p=find(root, r);
    if(p==NULL) return;
    if(p->right==NULL) p->right=makenode(r);
    else printf("already");
    return;
}
void in(node* r)
{
    if(r==NULL) return;
    printf("%d: ",r->gt);
    if(r->left!=NULL) printf("leftchild: %d ",r->left->gt);
    else printf("NULL ");
    if(r->right!=NULL) printf("rightchild: %d ",r->right->gt);
    else printf("NULL ");
    in(r->left);
    in(r->right);
}
