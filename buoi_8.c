#include<stdio.h>
#include<string.h>
char st[255],R[255];
typedef struct node
{
    char name[255];
    struct node* left;
    struct node* right;
}node;
node* root;
node* makenode(char st)
{
    node* p=(node*)malloc(sizeof(node));
    strcpy(p->name,st);
    p->left=NULL;
    p->right=NULL;
    return p;
}
node* find(node*r, char st)
{
    if(r==NULL) return NULL;
    if(strcmp(r->name,st)==0) return r;
    node* p=r->left;
    while(p!=NULL)
    {
        node* q=find(p, st);
        if(q!=NULL) return q;
        p=p->right;
    }
}
void addchild(char R,char st)
{
    node* r=find(root, R);
    if(r==NULL) return;
    node* p=r->left;
    while(1)
    {
        if(p->right==NULL)
        {
            node* q=makenode(st);
            p->right=q;
            break;
        }
        p=p->right;
    }
}
void in(node* r)
{
    if(r==NULL) return;
    printf("%s\n",r->name);
    in(r->left);
    in(r->right);

}
void input()
{
    FILE* f=fopen("buoi_8.txt","r");
    char c;
    int n=0;
    int kt=0;
    while((c=fgetc(f))!=EOF)
    {
        if(c!='\n'&&c!='$')
        {
            if(c!=' ')
            {
                if(n==0) R[strlen(R)]=c;
                else st[strlen(st)]=c;
            }
            else
            {
                if(kt==0) {root=makenode(R); kt=1;}
                //if(n>0) addchild(R,st);
                printf("%s\n", st);
                for(int i=strlen(st);i>=0;i--) st[i]='\0';
                n++;
                //printf("%s\n", st);
            }
        }
        else if(c=='$')
        {
            printf("%s\n", st);
            printf("%s\n", R);
            //addchild(R,st);
            for(int i=strlen(R);i>=0;i--) R[i]='\0';
            for(int i=strlen(st);i>=0;i--) st[i]='\0';
            n=0;
        }
    }
}
int main()
{
    FILE* f=fopen("buoi_8.txt","r");
    char c[256];
    int n=0;
    int kt=0;
    while(fgets(c,256,f)!=NULL)
    {
        c[strlen(c)-1]='\0';
        printf("%s\n",c);
        for(int i=0;i<strlen(c);i++)
        {

            if(c[i]!=' '&&c[i]!='$')
                if(n==0) R[strlen(R)]=c[i];

            if(c[i]==' '||c[i]=='$')

        }
    }
    //input();
    //in(root);
}
