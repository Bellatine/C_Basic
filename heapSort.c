#include<stdio.h>
#define maxn 10004
int a[maxn],n;
void upheap(int i)
{
    int j=i/2;
    if(i>1&&a[i]<a[j])
    {
        int z=a[i];
        a[i]=a[j];
        a[j]=z;
        upheap(j);
    }
}
void downheap(int i)
{
    int x=2*i;
    int y=2*i+1;
    if(x<n)
    {
        if(a[x]>a[y]) x=y;
        if(a[i]>a[x])
        {
            int z=a[i];
            a[i]=a[x];
            a[x]=z;
            downheap(x);
        }
    }
}
int main()
{
    FILE *dl;
    dl=fopen("taodulieu.txt","r");
    fscanf(dl,"%d",&n);
    for(int i=1;i<=n;i++)
        a[i]=maxn;
    for(int i=1;i<=n;i++)
    {
        int t;
        fscanf(dl,"%d",&t);
        a[i]=t;
        upheap(i);
    }
    int m=n;
    for(int i=1;i<=m;i++)
    {
        printf("%d ",a[1]);
        a[1]=a[n];
        a[n]=maxn;
        n--;
        downheap(1);
    }
}
