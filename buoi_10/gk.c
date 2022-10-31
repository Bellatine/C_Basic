#include<stdio.h>
#include<string.h>
#define maxn 256
typedef struct
{
    char name[maxn];
    char sdt[maxn];
    char mail[maxn];
}address;
address a[100];
int n=5;
void quicksort(int l, int r)
{
    if(l<r)
    {
        int i=l, j=r;
        int m=(i+j)/2;
        while(strcmp(a[i].name,a[m].name)<0) i++;
        while(strcmp(a[j].name,a[m].name)>0) j--;
        if(i<=j)
        {
            address z=a[i];
            a[i]=a[j];
            a[j]=z;
            i++;
            j--;
        }
        if(l<=j) quicksort(l,j);
        if(i<=r) quicksort(i,r);
    }
}
int search(int l,int r,char s[maxn])
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(strcmp(a[m].name,s)==0) return m;
        else if(strcmp(a[m].name,s)>0)
            search(l,m,s);
        else if(strcmp(a[m].name,s)<0)
            search(m,r,s);
    }
    else return -1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a[i].name);
        scanf("%s",a[i].sdt);
        scanf("%s",a[i].mail);
    }
    quicksort(1,n);
    char u[maxn];
    scanf("%s",u);
    int i=search(1,n,u);
    if(i>0)
    printf("%s %s %s\n",a[i].name,a[i].sdt,a[i].mail);
    else return("NULL");
}
