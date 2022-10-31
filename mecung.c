#include<stdio.h>
#define maxn 1003
int a[maxn][maxn],
typedef struct ptu
{
    int h,c,buoc;
    struct ptu cha,sau;
}ptu;
ptu* danhsach[maxn*maxn];
ptu* dau,cuoi;
int ds;
int m,n,r0,c0,tham[maxn][maxn];
int
ptu* khoitao(int h0, int c0, int buoc0, ptu* cha0)
{
    ptu* x=(ptu*)malloc(sizeof(ptu));
    x->h=h0;
    x->c=c0;
    x->buoc=buoc0;
    x->cha=cha0;
    x->sau=NULL;
    return x;
}
int empty()
{
    return dau==NULL && cuoi==NULL;
}
void push(ptu* x)
{
    if(empty())
    {
        dau=x;
        cuoi=x;
    }
    else
    {
        cuoi->sau=x;
        cuoi=x;
    }
}
ptu* pop()
{
    if(empty()) return NULL;
    ptu* x=dau;
    dau=x->next;
    if(dau==NULL) cuoi=NULL;
    return x;
}
int loang(int hang,int cot)
{
    return a[hang][cot]==0 && tham[hang][cot]==0;
}
int gioihan()
