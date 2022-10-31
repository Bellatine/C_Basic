#include<stdio.h>
#include<string.h>
#define maxn 256
int n=0;
typedef struct profile
{
    char ho[maxn];
    char dem[maxn];
    char ten[maxn];
    int y,m,d;
}profile;
profile a[maxn];
void upheap(int i)
{
    int j=i/2;
    if(i>1&&strcmp(a[i].ten,a[j].ten)<0)
    {
        profile z=a[i];
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
        if(strcmp(a[x].ten,a[y].ten)>0) x=y;
        if(strcmp(a[i].ten,a[x].ten)>0)
        {
            profile z=a[i];
            a[i]=a[x];
            a[x]=z;
            downheap(x);
        }
    }
}
int main()
{
    //FILE *dl;
    //dl=fopen("TEST.txt","r");
    //int n=0;
    char z='#';
    do
    {
        n++;
        scanf("%s",a[n].ho);
        if(strcmp(a[n].ho,z)==0) break;
        scanf("%s",a[n].dem);
        scanf("%s",a[n].ten);
        scanf("%d",a[n].y);
        scanf("%d",a[n].m);
        scanf("%d",a[n].d);
        upheap(n);
    }while(1);
    int m=n;
    printf("1");
    for(int i=1;i<=m;i++)
    {
        printf("!");
        printf("%s %s %s\n%d-%d-%d",a[1].ho,a[1].dem,a[1].ten,a[1].y,a[1].m,a[1].d);
        a[1]=a[n];
        n--;
        downheap(1);
    }
    //fscanf(dl,"%d",&n);
    //for(int i=1;i<=n;i++)
    //    a[i]=maxn;
    //for(int i=1;i<=n;i++)
    //{
    //    int t;
    //    fscanf(dl,"%d",&t);
    //    a[i]=t;
    //    upheap(i);
    //}
    //int m=n;
    //for(int i=1;i<=m;i++)
    //{
    //    printf("%d ",a[1]);
   //     a[1]=a[n];
   //     a[n]=maxn;
    //    n--;
    //    downheap(1);
    //}
}
