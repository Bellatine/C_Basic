#include<stdio.h>
#include<string.h>
int n,c,i;
typedef struct sv
{
    char name[225];
    char ID[225];
    char grade[225];
    float height;
    struct sv* next;
}sv;
sv* begin=NULL;
sv* end=NULL;
sv* make(char ten[225],char id[225],char lop[225],float cao )
{
    sv* x=(sv*)malloc(sizeof(sv));
    strcpy(x->name,ten);
    strcpy(x->ID,id);
    strcpy(x->grade,lop);
    x->height=cao;
    x->next=NULL;
}
void push(sv* x)
{
    if(begin==NULL&&end==NULL)
    {
        begin=x;
        end=x;
    }
    else
    {
        end->next=x;
        end=x;
    }
}
void pop()
{
    if(begin==NULL&&end==NULL) return;
    sv* x=begin;
    begin=x->next;
    if(begin==NULL) end=NULL;
    return;
}
void chucnang1()
{
    printf("Nhap so hoc vien: ");
    scanf("%d",&n);
    while(n<0||n>100)
    {
        printf("Nhap lai n: ");
        scanf("%d",&n);
    }
    printf("Nhap so nguoi 1 hang: ");
    scanf("%d",&c);
    while(c<0||c>100)
    {
        printf("Nhap lai c: ");
        scanf("%d",&c);
    }
    printf("So nguoi xep hang la: %d\n",n);
    printf("So nguoi mot hang la: %d\n",c);
}
int count()
{
    if(begin==NULL) return 0;
    sv* x=begin;
    int j=0;
    while(x!=NULL)
    {
        j++;
        x=x->next;
    }
    return j;
}
void chucnang2()
{
    char kt;
    do{
    char ten[225];
    char id[225];
    char lop[225];
    float cao;
    getchar();
    printf("Nhap ten: ");
    fgets(ten,sizeof(ten),stdin);
    ten[strlen(ten)-1]='\0';
    printf("Nhap ID: ");
    fgets(id,sizeof(id),stdin);
    id[strlen(id)-1]='\0';
    printf("Nhap lop: ");
    fgets(lop,sizeof(lop),stdin);
    lop[strlen(lop)-1]='\0';
    int u;
    printf("Chieu cao: ");
    scanf("%f",&cao);
    while(cao<0||cao>5)
    {
        printf("Nhap sai, nhap lai: ");
        scanf("%f",&cao);
    }
    printf("Nhap vi tri muon dung: ");
    scanf("%d",&u);
    while(u<0||u>c)
    {
        printf("Nhap sai, nhap lai: ");
        scanf("%d",&u);
    }
    sv* x=make(ten,id,lop,cao);
    if(u>count())
    {
        printf("hang %d chua co ai nhung chua den luot xep! \n",u);
        printf("Vi tri tiep theo duoc xep la: %d\n",count());

    }
    else if(u<count())
    {
        printf("Hang %d da co nguoi xep!\n",u);
        printf("Vi tri xep duoc la: %d\n",count());
    }
    push(x);
    printf("So luong hoc vien trong hang: %d\n", count());
    getchar();
    printf("Ban muon tiep tuc ko? Y/N?: ");
    scanf("%c",&kt);
    }
    while((kt=='Y'||kt=='y')&&count()<=c) ;
}
sv* search(float u)
{
    if(begin==NULL) return NULL;
    sv* x=begin;
    while(x!=NULL)
    {
        if(x->height==u)  return x;
        x=x->next;
    }
    return NULL;
}
void chucnang3()
{
    char kt;
    do{
    float u;
    printf("Nhap chieu cao can tim: ");
    scanf("%f",&u);
    sv* x=search(u);
    if(x!=NULL)
    {
        printf("Ten: %s\n",x->name);
        printf("ID: %s\n",x->ID);
        printf("Grade: %s\n",x->grade);
        printf("Height: %f\n",x->height);
    }
    else printf("ERROL\n");
    getchar();
    printf("Ban muon tiep tuc ko? Y/N?: ");
    scanf("%c",&kt);
    }
    while(kt=='Y'||kt=='y') ;
}
int ktra(char id[225])
{
    if(begin==NULL) return -1;
    int j=0;
    sv* x=begin;
    while(x!=NULL)
    {
        if(strcmp(x->ID,id)==0) return j;
        j++;
        x=x->next;
    }
    return -1;
}
void xoa(char id[225])
{
    while(strcmp(begin->ID,id)!=0)
        pop();
    pop();
}
void chucnang4()
{
    char kt;
    do{
    getchar();
    char id[225];
    printf("Nhap ID can tim: ");
    fgets(id,sizeof(id),stdin);
    id[strlen(id)-1]='\0';
    if(ktra(id)==-1) printf("Khong tim thay hoc vien!\n");
    else
    {
        printf("So hoc vien dung truoc la: %d\n", ktra(id));
        xoa(id);
        printf("So hoc vien con lai la: %d\n", count());
    }
    printf("Ban muon tiep tuc ko? Y/N?: ");
    scanf("%c",&kt);
    }
    while(kt=='Y'||kt=='y') ;
}
int main()
{
    int a;
    do
    {
        printf("Nhap menu muon chon: ");
        scanf("%d",&a);
        while(a<0||a>5)
        {
            printf("Nhap sai! Nhap lai: ");
            scanf("%d",&a);
        }
        if(a==5)
        {
            printf("Ket thuc chuong trinh!");
            break;
        }
        switch(a)
        {
            case 1: {chucnang1(); break;}
            case 2: {chucnang2(); break;}
            case 3: {chucnang3(); break;}
            case 4: {chucnang4(); break;}
        }

    }while(1);
}
