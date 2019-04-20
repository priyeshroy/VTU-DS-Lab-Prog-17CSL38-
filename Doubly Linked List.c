#include<stdio.h>
#include<stdlib.h>
struct node
{
		char ssn[3];
		char name[10];
		char dept[5];
		char desig[5];
		char sal[6];
		char phone[10];
		struct node *rlink;
		struct node *llink;
};
struct node *head=NULL;
struct node *createnode()
{
	struct node *temp;
	temp=malloc(sizeof(struct node));
	printf("Enter the ssn:\n ");
	gets(temp->ssn);
	printf("Enter the name:\n ");
	gets(temp->name);
	printf("Enter the department:\n ");
	gets(temp->dept);
	printf("Enter the designation:\n ");
	gets(temp->desig);
	printf("Enter the salary:");
	gets(temp->sal);
	printf("Enter the phone no: ");
	gets(temp->phone);
	temp->rlink=NULL;
	temp->llink=NULL;
	return temp;
}
void Insertfront()
{
	struct node *DLL=NULL;
	DLL=createnode();
	if(head!=NULL)
		DLL->rlink=head;
		head->llink=DLL;
	head=DLL;
}
void Delfront()
{
	struct node *DLL=head;
	printf("The deleted node is: \n");
	printf("ssn=%s\n",DLL->ssn);
	printf("name=%s\n",DLL->name);
	printf("dept=%s\n",DLL->dept);
	printf("desig=%s\n",DLL->desig);
	printf("salary=%s\n",DLL->sal);
	printf("phone no=%s\n",DLL->phone);
	head=DLL->rlink;
	head->lliNk=NULL;
	free(DLL);
}
void Insertend()
{
		struct node *DLL,*temp=head;
		DLL=createnode();
		if(head==NULL)
			head=DLL;
		else
		{
				while(temp->rlink!=NULL)
					temp=temp->rlink;
		}
		temp->rlink=DLL;
		DLL->llink=temp;
}
void Deleteend()
{
	struct node *temp=head;
	struct node *t;
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		while(temp->rlink!=NULL)
		{
			t=temp;
			temp=temp->rlink;
		}
		printf("The deleted node is: \n");
		printf("ssn=%s\n",temp->usn);
		printf("name=%s\n",temp->name);
		printf("dept=%s\n",temp->dept);
		printf("desig=%s\n",temp->desig);
		printf("salary=%s\n",temp->sal);
		printf("phone no=%s\n",temp->phone);
		free(temp);
		t->rlink=NULL;
	}
}
void Create()
{
	int i,n;
	printf("Enter the no. of employees\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		insertend();
	}
}
void Display()
{
	int c=0;
	struct node *temp=head;
	while(temp!=NULL)
	{
		fflush(stdout);
		printf("\n %s\t",temp->ssn);
		printf("\n %s\t",temp->name);
		printf("\n %s\t",temp->dept);
		printf("\n %s\t",temp->desig);
		printf("\n %s\t",temp->sal);
		printf("\ %s\t",temp->phone);
		temp=temp->rlink;
		c=c+1;
	}
	printf("The no. of nodes: %d",c);
}
void Dequeue()
{
	int choice;
	printf("\n 1:Insert at front \n 2:Insert at rear \n 3:Delete from front \n 4:Delete from rear\n 5:Display\n Enter your choice:\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("Enter the details to be inserted: \n");
				insertfront();
				break;
		case 2: printf("Enter the details to be inserted: \n");
				insertend();
				break;
		case 3: printf("The deleted node is: \n");
				delend();
				break;
	}
}
int main()
{
	int ch1,ch2,ch3;
	while(1)
	{
		printf("\n Enter your choice: \n 1:Create\n 2:Display and Count\n 3:Insert and delete at end\n 4:Insert and delete from front\n 5:DLL as dequeue\n 6:Exit");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1: Create();
					break;
			case 2: Display();
					break;
			case 3: printf("Enter your choice: \n 1:Insert \n 2:Delete\n");
					scanf("%d",&ch2);
					if(ch2==1)
						Insertend();
					else
						Deleteend();		
					break;
			case 4: printf("Enter your choice: \n1:Insert \n 2:Delete\n");
					scanf("%d",&ch3);
					if(ch3==1)
						Insertfront();
					else
						Delfront();
					break;
			case 5: Dequeue();
					break;
			case 6: exit(0);
		}
	}
}



