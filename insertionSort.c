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
    for(int i=2;i<=n;i++)
    {
        int k=a[i],j=i;
        while(j>1&&a[j-1]>k)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=k;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
}
