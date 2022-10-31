#include<stdio.h>
#define maxn 100005
int a[maxn],n;
int main()
{
    FILE *dl;
    dl=fopen("taodulieu.txt","r");
    fscanf(dl,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(dl,"%d",&a[i]);
    int kt=1;
    while(kt==1)
    {
        kt=0;
        for(int i=1;i<n;i++)
            if(a[i]>a[i+1])
        {
            int z=a[i];
            a[i]=a[i+1];
            a[i+1]=z;
            kt=1;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
}
