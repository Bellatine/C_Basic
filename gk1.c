#include<stdio.h>
#define maxn 10004
int n;
int f[maxn][maxn];
typedef struct
{
    int gt;
    struct queue* next;
}queue;
queue* r[maxn];
queue* ktao(int i)
{
    queue* x=(queue*)malloc(sizeof(queue));
    x->gt=i;
    x->next=NULL;
    return x;
}
void push(int i, int j)
{
    queue* x = ktao(j);
    if(r[i]==NULL)
    {
        r[i]=x;
        f[i][j]=1;
        return;
    }
    queue* y = r[i];
    while(y->next!=NULL)
    {
        y=y->next;
    }
    y->next=x;
    f[i][j]=1;
}
void in(int i)
{
    queue*  y=r[i];
    while(y!=NULL)
    {
        printf("%d ",y->gt);
        y=y->next;
    }
}
void nhapn()
{
    printf("Nhap so queue: ");
    scanf("%d",&n);
    while(n<0||n>10)
    {
        printf("Nhap lai n: ");
        scanf("%d",&n);
    }
}
void nhapij()
{
    int i,j;
    printf("Nhap i,j: ");
    scanf("%d",&i);
    scanf("%d",&j);
    if(i<0||i>n||j<1||f[i][j]==1)
    {
        printf("Nhap sai!\n");
        return;
    }
    push(i,j);
    in(i);
    int m;
    printf("\n1: YES\n2: NO\n");
    scanf("%d",&m);
    if(m==1) nhapij();

}
void chucnang3()
{
    int i;
    printf("Nhap queue i: ");
    scanf("%d",&i);
    queue*  y=r[i];
    while(y!=NULL)
    {
        printf("%d->",y->gt);
        y=y->next;
    }
    printf("NULL\n");
}
void chucnang4()
{
    int kt[maxn];
    queue* y;
    for(int i=1;i<=maxn-2;i++) kt[i]=0;
    printf("Chuc nang 4:\n");
    for(int i=1;i<=n;i++)
    {
        y=r[i];
        while(y!=NULL)
        {
            if(kt[y->gt]==0) kt[y->gt]=1;
            else if(kt[y->gt]==1) kt[y->gt]=-1;
            y=y->next;
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        while(kt[r[i]->gt]==-1) r[i]=r[i]->next;
        queue* y=r[i];
        while(y->next!=NULL)
        {
            queue* x=y->next;
            if(kt[x->gt]==-1)
            {
                y->next=x->next;
            }
            y=y->next;
        }
        in(i);
    }*/
    for(int i=1;i<=n;i++)
    {
        queue* y=r[i];
        while(y!=NULL)
        {
            if(kt[y->gt]!=-1)
                printf("%d->",y->gt);
            y=y->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    int m;
    while(1)
    {
        printf("Chon menu: ");
        scanf("%d",&m);
        while(m<1||m>5)
        {
            printf("Nhap lai m: ");
            scanf("%d",&m);
        }
        if(m==5) break;
        switch(m)
        {
            case (1):{nhapn(); break;}
            case (2):{nhapij(); break;}
            case (3):{chucnang3(); break;}
            case (4):{chucnang4(); break;}
        }
    }
}
