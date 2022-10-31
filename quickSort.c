#include<stdio.h>
#define maxn 100005
int a[maxn],n;
void quicksort(int l, int r)
{
    if(l<r)
    {
        int i=l, j=r;
        int m=(i+j)/2;
        while(a[i]<a[m]) i++;
        while(a[j]>a[m]) j--;
        if(i<=j)
        {
            int z=a[i];
            a[i]=a[j];
            a[j]=z;
            i++;
            j--;
        }
        if(l<=j) quicksort(l,j);
        if(i<=r) quicksort(i,r);
    }
}
int search(int l, int r, int u)
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(a[m]>u) search(l,m-1,u);
        else if(a[m]<u) search(m+1,r,u);
        else if(a[m]==u) return m;
    }
    else return -1;
    //else if(l==r&&a[l]==u) return l;
}
int main()
{
    //FILE *dl;
    //dl=fopen("taodulieu.txt","r");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    //printf("%d",a[10]);
    quicksort(1,n);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    int u=search(1,n,12);
    printf("\n %d",u);
}
