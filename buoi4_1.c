#include<stdio.h>
#include<string.h>
#define maxn 255
int n;
typedef struct
{
    char name[maxn];
    int age;
    float gpa;
    int p;
}hocvien;
hocvien a[maxn];
void nhapsoluong()
{
    printf("Nhap so luong hoc vien:");
    scanf("%d",&n);
    while(n<1||n>100)
    {
        printf("Nhap lai gia tri ");
        scanf("%d",&n);
    }
    printf("So hoc vien la: %d\n",n);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<strlen(a[i].name);j++) a[i].name[j]='\0';
        a[i].age=0;
        a[i].gpa=0;
        a[i].p=0;
    }
}
void nhapthongtin()
{
    for(int i=1;i<=n;i++)
    {
        getchar();
        printf("Nhap ten hoc vien: ");
        fgets(a[i].name,sizeof a[i].name, stdin);
        a[i].name[strlen(a[i].name)-1]='\0';
        printf("Nhap tuoi: ");
        scanf("%d",&a[i].age);
        while(a[i].age<0||a[i].age>125)
        {
            printf("Nhap lai tuoi ");
            scanf("%d",&a[i].age);
        }
        printf("Nhap GPA: ");
        scanf("%f",&a[i].gpa);
        while(a[i].gpa<0||a[i].gpa>4)
        {
            printf("Nhap lai gpa ");
            scanf("%f",&a[i].gpa);
        }
        printf("Sinh vien cung phong: ");
        scanf("%d",&a[i].p);
        while(a[i].p<0||a[i].p>n)
        {
            printf("Nhap lai ban cung phong ");
            scanf("%d",&a[i].p);
        }
    }
}
void timthongtin()
{
    int t,d;
    printf("nhap can tren: ");
    scanf("%d",&t);
    printf("nhap can duoi: ");
    scanf("%d",&d);
    if(t==-1) t=125;
    if(d==-1) d=0;
    int dem=0;
    for(int i=1;i<=n;i++)
        if(d<=a[i].age&&a[i].age<=t)
    {
        dem++;
        printf("%s\n",a[i].name);
    }
    if(dem==0) printf("-1");
}
void suathongtin()
{
    printf("Nhap chi so sv: ");
    int i;
    scanf("%d",&i);
    while(i<0||i>n)
    {
        printf("Nhap sai thong tin");
        int t;
        printf("Ban co muon nhap lai khong? \n '1' la co\n '2' la khong\n ");
        scanf("%d",&t);
        if(t==1)
            scanf("%d",&i);
        else break;
    }
    printf("Sua thong tin:\n");
    printf("Ten: ");
    getchar();
    fgets(a[i].name,sizeof a[i].name, stdin);
    a[i].name[strlen(a[i].name)-1]='\0';
    printf("Nhap tuoi: ");
    scanf("%d",&a[i].age);
    while(a[i].age<0||a[i].age>125)
    {
        printf("Nhap lai tuoi ");
        scanf("%d",&a[i].age);
    }
    printf("Nhap GPA: ");
    scanf("%f",&a[i].gpa);
    while(a[i].gpa<0||a[i].gpa>4)
    {
        printf("Nhap lai GPA ");
        scanf("%f",&a[i].gpa);
    }
    printf("Sinh vien cung phong: ");
    scanf("%d",&a[i].p);
    while(a[i].p<0||a[i].p>n)
    {
        printf("Nhap lai ban cung phong ");
        scanf("%d",&a[i].p);
    }
    for(int i=1;i<=n;i++)
    {
        printf("Ten: %s\n",a[i].name);
        printf("Tuoi: %d, GPA: %.1f, roommate: %s\n",a[i].age,a[i].gpa,a[a[i].p].name);
    }
}
int main()
{
     int m;
     do
     {
         printf("Nhap menu:");
         scanf("%d",&m);
         while(m<1||m>5)
         {
             printf("Nhap lai  menu: ");
             scanf("%d",&m);
         }
         if(m==5)
         {
             printf("\nCam on da su dung chuong trinh, Ket thuc chuong trinh!");
             break;
         }
         switch(m)
         {
                case 1: { nhapsoluong(); break;}
                case 2: { nhapthongtin(); break;}
                case 3: { timthongtin(); break;}
                case 4: { suathongtin(); break;}
        }
     }while(1);
}
