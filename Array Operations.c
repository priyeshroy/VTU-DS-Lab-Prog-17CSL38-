#include <stdio.h>
#include <stdlib.h>
int n;
void Read(int a[10])
{
    int i;
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}
void Print(int a[10])
{
    int i;
    printf("Elements of array are:\n");
    for(i=0;i<n;i++)
        printf("%d",a[i]);
}
void Insert(int a[10],int ele,int pos)
{
    int i;
    for(i=n-1;i>=pos-1;i--)
        a[i+1]=a[i];
    a[pos-1]=ele;
    n++;
}
int Delete(int a[10],int pos)
{
    int i,ele;
    ele=a[pos-1];
    for(i=pos-1;i<n;i++)
        a[i]=a[i+1];
    n--;
    return ele;
}
int main()
{
    int ch,ele,pos;
    int a[10];
    while(1)
    {
        printf("\n1.Read\t2.Print\t3.Insert\t4.Delete\t5.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of terms\n");
                    scanf("%d",&n);
                    Read(a);
                    break;
            case 2:Print(a);
                    break;
            case 3:printf("Enter position\n");
                    scanf("%d",&pos);
                    printf("Enter element \n");
                    scanf("%d",&ele);
                    Insert(a,ele,pos);
                    break;
            case 4:printf("Enter position\n");
                    scanf("%d",&pos);
                    ele=Delete(a,pos);
                    printf("Element deleted is:%d\n",ele);
                    break;
            case 5:exit(0);
        }
    }
    return 0;
}

