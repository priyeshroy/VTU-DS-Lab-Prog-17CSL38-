#include <stdio.h>
#include <stdlib.h>
#define MAX 3
char s[MAX];
int top=-1;
int isfull()
{
    if(top==MAX-1)
        return 1;
    return 0;
}
int isempty()
{
    if(top==-1)
        return 1;
    return 0;
}
void push(char ch)
{
    if(!isfull())
    s[++top]=ch;
    else
        printf("\nOverflow\n");
}
char pop()
{
    char ch;
    if(!isempty())
    {
        ch=s[top--];
        return ch;
    }
    else
    {
        printf("\nUnderflow\n");
        return -1;
    }
}
void display()
{
    if(isempty())
        printf("Stack is Empty\n");
    else
    {
        int i;
        printf("Contents are:\n");
        for(i=0;i<=top;i++)
        {
            printf("%c\t",s[i]);
        }
        printf("\n");
    }
}
int palin(char str[3])
{
    int i;
    top=-1;
    for(i=0;str[i];i++)
        push(str[i]);
    for(i=0;str[i];i++)
    {
        if(str[i]!=pop())
            return 0;
    }
    return 1;
}
int main()
{   int ch;
    char ele;
    char p[3];
    int pal;
    while(1)
    {
    printf("1.Push\n2.Pop\n3.Display\n4.Palindrome\n5.Exit\nEnter Choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("Enter a number\n");
                scanf("%s",&ele);
                push(ele);
                break;
        case 2:ele=pop();
                if(ele!=-1)
                    printf("Popped %c\n",ele);
                break;
        case 3:display();
                break;
        case 4:printf("Enter a three letter string\n");
                scanf("%s",&p);
                pal=palin(p);
                if(pal==1)
                    printf("Palindrome\n");
                else
                    printf("Not a palindrome\n");
                break;
        default:exit(0);
    }
    }
    return 0;
}

