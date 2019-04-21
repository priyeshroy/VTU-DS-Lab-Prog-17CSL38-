#include <stdio.h>
#include <stdlib.h>
#define MAX 5
char CQ[MAX];
int f=-1,r=-1;
void insert(char ele)
{
    if(cqfull())
        printf("Queue is full\n");
    else
    {
        if(f==-1)
            f=0;
        r=(r+1)%MAX;
        CQ[r]=ele;
    }
}
char del()
{
    char ele;
    if(cqempty())
        {
            printf("Queue is empty\n");
            return;
        }
    else
    {
        ele=CQ[f];
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else
        {
            f=(f+1)%MAX;
        }
        return ele;
    }
}
int cqfull()
{
    if(f==r+1||(f==0&&r==MAX-1))
        return 1;
    return 0;
}
int cqempty()
{
    if(f==-1)
        return 1;
    return 0;
}
void display()
{
    int i;
    if(cqempty())
        printf("Empty Queue\n");
    else
    {
        printf("Front[%d]->",f);
        for(i=f;i!=r;i=(i+1)%MAX)
            printf("%c\t",CQ[i]);
        printf("%c",CQ[i]);
        printf("<-Rear[%d]",r);
    }
}
int main()
{
   int ch;
   char ele;
   while(1)
   {
       printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:printf("Enter the character\n");
                    scanf("%s",&ele);
                    insert(ele);
                    break;
            case 2:ele=del();
                    if(ele!=-1)
                        printf("Deleted character is %c",ele);
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
       }
   }
    return 0;
}

