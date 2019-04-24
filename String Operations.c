#include <stdio.h>
#include <stdlib.h>
void read(char *s)
{
    gets(s);
}
void strcopy(char *s1,char *s2)
{
    int i;
    for(i=0;s2[i]!='\0';i++)
        s1[i]=s2[i];
    s1[i]='\0';
}
int matchnreplace(char *str,char *pat,char *rep)
{
    char ans[100];
    int c=0,m=0,i=0,j=0,flag=0,k;
    while(str[c]!='\0')
    {
        if(pat[i]==str[m])
        {
            i++;m++;
            if(pat[i]=='\0')
            {
                flag=1;
                for(k=0;rep[k]!='\0';k++,j++)
                    ans[j]=rep[k];
                i=0;
                c=m;
            }
        }
            else
            {
                ans[j]=str[c];
                j++;c++;m=c;
                i=0;
            }
    }
    ans[j]='\0';
    strcopy(str,ans);
    return flag;
}
int main()
{
    int f;
    char str[100],pat[50],rep[50];
    printf("Enter the String\n");
    read(str);
    printf("Enter the pattern\n");
    read(pat);
    printf("Enter the replacement\n");
    read(rep);
    f=matchnreplace(str,pat,rep);
    if(f==1)
    {
        printf("Pattern found\n");
        printf("New String:%s",str);
    }
    else
        printf("Pattern not found");
    return 0;
}

