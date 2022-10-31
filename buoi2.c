#include<stdio.h>
#include<time.h>
#define lambda 0.4
#define maxn 100005

int x[maxn];
float y[maxn];
int n,u;
int abs(int a)
{
    if(a>=0) return a;
    else return -a;
}
void iny()
{
    for(int i=1;i<=n;i++)
        printf("%f ",y[i]);
}
void taoy(int k)
{
    if(k==1) y[1]=x[1];
    else
    {
        taoy(k-1);
        y[k]=y[k-1]*(1-lambda)+lambda*x[k];
        if(k==n) iny();
    }
}
int main()
{
    time_t t;
    srand((unsigned) time(&t));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        x[i]=rand()%101;
    }
    scanf("%d",&u);
    taoy(n);
    int v=y[n-1];
    int z=rand()%101;
    if(abs(z-u)>abs(z-v)) printf("may thang!");
    else if (abs(z-u)<abs(z-v)) printf("nguoi thang!");
    else printf("Hoa roi!");
}
