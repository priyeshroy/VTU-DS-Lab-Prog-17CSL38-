#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int coeff;
    int px,py,pz,flag;
    struct node *link;
};
struct node * addterm(struct node *p,int coeff,int x,int y,int z)
{
        struct node *temp=malloc(sizeof(struct node));
        struct node *temp1=p;
        temp->coeff=coeff;
        temp->px=x;
        temp->py=y;
        temp->pz=z;
        while(temp1->link!=p)
            temp1=temp1->link;
        temp1->link=temp;
        temp->link=p;
        return p;
}
struct node * mkheader()
{
        struct node *p=malloc(sizeof(struct node));
        p->link=p;
        return p;
}
void printpoly(struct node *p)
{
    struct node *po=p->link;
    while(po!=p)
    {
        printf("%d x^%d y^%d z^%d",po->coeff,po->px,po->py,po->pz);
        if(po->link!=p)
            printf("+");
        po=po->link;
    }
    printf("\n");
}
void read(struct node *t1,int n)
{
    int i;
    int c,x,y,z;
    for(i=1;i<=n;i++)
    {
        printf("Enter Coefficient and powers of x,y and z\n");
        scanf("%d%d%d%d",&c,&x,&y,&z);
        t1=addterm(t1,c,x,y,z);
    }
    printpoly(t1);
}
double evaluate(struct node *p)
{
    struct node *po=p->link;
    double sum=0;
    int x,y,z;
    printf("Enter values of x,y and z\n");
    scanf("%d%d%d",&x,&y,&z);
    while(po!=p)
    {
        sum+=po->coeff*pow(x,po->px)*pow(y,po->py)*pow(z,po->pz);
        po=po->link;
    }
    return sum;
}
struct node * add(struct node *h1,struct node *h2)
{
    int cf1,cf2,x1,x2,y1,y2,z1,z2;
    struct node *h3=mkheader();
    struct node *t1,*t2;
    t1=h1->link;
    while(h1!=t1)
    {
       cf1=t1->coeff;
       x1=t1->px;
       y1=t1->py;
       z1=t1->pz;
       t2=h2->link;
       while(h2!=t2)
       {
            cf2=t2->coeff;
            x2=t2->px;
            y2=t2->py;
            z2=t2->pz;
            if(x1==x2&&y1==y2&&z1==z2)
                break;
            t2=t2->link;
       }
       if(t2!=h2)
       {
           h3=addterm(h3,cf1+cf2,x1,y1,z1);
           t2->flag=1;
       }
       else
        h3=addterm(h3,cf1,x1,y1,z1);
       t1=t1->link;
    }
    t2=h2->link;
    while(t2!=h2)
    {
        if(t2->flag!=1)
            h3=addterm(h3,t2->coeff,t2->px,t2->py,t2->pz);
        t2=t2->link;
    }
    return h3;
}

int main()
{
    int ch,n;
    double sum;
    struct node *polysum;
    struct node *p=mkheader();
    struct node *p2=mkheader();
    while(1)
    {
        printf("1.Evaluate\n2.Add\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of terms of polynomial\n");
                    scanf("%d",&n);
                    read(p,n);
                    sum=evaluate(p);
                    printf("Sum:%f",sum);
                    break;
            case 2:printf("enter number of terms of polynomial 2\n");
                    scanf("%d",&n);
                    read(p2,n);
                    polysum=add(p,p2);
                    printpoly(polysum);
                    break;
            case 3:exit(0);
        }
    }
    return 0;
}

