#include<stdio.h>
#include<time.h>
#include<string.h>
#define maxn 256
char s1[maxn][maxn],s2[maxn][maxn],s3[maxn][maxn];
int n,m;
int main()
{
    FILE *f;
    f=fopen("test.inp","r");
    FILE *dl;
    dl=fopen("TEST.txt","w");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(f,"%s",s1[i]);
    for(int i=1;i<=n;i++)
        fscanf(f,"%s",s2[i]);
    for(int i=1;i<=n;i++)
        fscanf(f,"%s",s3[i]);
    fscanf(f,"%d",&m);
    srand((int)time(0));
    for(int i=1;i<=m;i++)
    {
        int z=1+rand()%n;
        fprintf(dl,"%s ",s1[z]);
        z=1+rand()%n;
        fprintf(dl,"%s ",s2[z]);
        z=1+rand()%n;
        fprintf(dl,"%s\n",s3[z]);
        z=1900+rand()%121;
        fprintf(dl,"%d-",z);
        z=3+rand()%10;
        fprintf(dl,"%d-",z);
        z=1+rand()%30;
        fprintf(dl,"%d\n",z);
    }
    fprintf(dl,"#");
}
