#include<stdio.h>
#include<string.h>
#define maxn 300
typedef struct profile
{
    char name[maxn];
    char email[maxn];
    struct profile* next;
}profile;
profile* f,l;
profile* makeprofile(char* name, char* email)
{
   profile* node=(profile*)malloc(sizeof(profile));
   strcpy(node->name,name);
   strcpy(node->email,email);
   node->next=NULL;
   return node;
}
void intlist()
{
    first = NULL;
    last = NULL;
}
int listempty()
{
    return first==NULL && last==NULL;
}
void insertlast(char* name,char* email)
{
    profile* Profile = makeprofile(name,email);
    if(listempty())
    {
        first=Profile;
        last=Profile;
    }
    else
    {
        last->next=Profile;
        last=Profile;
    }
}
void printlist()
{
    for(profile* p=first;p!=NULL;p=p->next)
        printf("%s, %s\n",p->name,p->email);
}
profile* removeprofile(profile* f, char* name)
{
    if(listempty()) return NULL;
    if(strcmp(f->name,name)==0)
    {
        profile* tmp=f->next;
        free(f);
        if(tmp==NULL) last =NULL;
        return tmp;
    }
    else
    {
        f->next=removeprofile(f->next,name);
        return f;
    }
}
void load(char* filename)
{
    FILE* f=fopen(filename,"r");
    if(f==NULL)printf("Load data -> File not found\n");
    while(!feof(f))
    {
        char name[maxn],email[maxn];
        fscanf(f,"%s%s",name,email);
        insertlast(name,email);
    }
    fclose(f);
}
void processfind()
{
    char name[maxn];
    scanf("%s",name);
    profile* Profile=NULL;
    for(profile*p=first;p!=NULL;p=p->next)
        if(strcmp(p->name,name)==0)
    {
        Profile=p;
        break;
    }
    if(Profile==NULL)
        printf("not found profile %s\n",name);
    else
        printf("found file %s, %s\n",Profile->name, Profile->email);
}
void processload()
{
    char filename[maxn];
    scanf("%s",filename);
    FILE* f=fopen(filename,"w");
    for(profile* p = first;p!=NULL;p=p->next)
    {
        fprintf(f,"%s %s",p->name,p->email);
        if(p->next!=NULL)fprintf(f,"\n");
    }
    fclose(f);
}
void processinsert()
{
    char name[maxn], email[maxn];
    scanf("%s%s",name,email);
    insertlast(name,email);
}
void processremove()
{
    char name[maxn];
    scanf("%s",name);
    first=removeprofile(first, name);
}
int main()
{
    intlist();
    while(1)
    {
        printf("Enter command: ");
        char cmd[maxn];
        scanf("%s",cmd);
        if(strcmp(cmd,"Quit")==0) break;
        else if(strcmp(cmd,"Load")==0) processload()    ;
        else if(strcmp(cmd,"print")==0) printlist();
        else if(strcmp(cmd,"find")==0) processfind();
        else if(strcmp(cmd,"insert")==0) processinsert();
        else if(strcmp(cmd,"remove")==0) processremove();
        else if(strcmp(cmd,"store")==0) pro
    }
}
