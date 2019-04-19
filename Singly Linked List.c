#include<stdio.h>
#include<stdlib.h>
struct node
{
		char usn[3];
		char name[5];
		char branch[3];
		char sem[3];
		char phone[10];
		struct node *link;
};
struct node *head=NULL;
struct node *createnode()
{
	struct node *temp;
	temp=malloc(sizeof(struct node));
	fflush(stdin);
	printf("Enter the usn: ");
	scanf("%s",temp->usn);
	printf("Enter the name: ");
	scanf("%s",temp->name);
	printf("Enter the branch: ");
	scanf("%s",temp->branch);
	printf("Enter the sem: ");
	scanf("%s",temp->sem);
	printf("Enter the phone no: ");
	scanf("%s",temp->phone);
	temp->link=NULL;
	return temp;
}
void Insertfront()
{
	struct node *SLL=NULL;
	SLL=createnode();
	if(head!=NULL)
		SLL->link=head;
	head=SLL;
}
void Delfront()
{
	struct node *SLL=head;
	printf("The deleted node is: \n");
	printf("usn=%s\n",SLL->usn);
	printf("name=%s\n",SLL->name);
	printf("branch=%s\n",SLL->branch);
	printf("sem=%s\n",SLL->sem);
	printf("phone no=%s\n",SLL->phone);
	head=SLL->link;
	free(SLL);
}
void Insertend()
{
		struct node *SLL,*temp=head;
		SLL=createnode();
		if(head==NULL)
			head=SLL;
		else
		{
				while(temp->link!=NULL)
					temp=temp->link;
		}
		temp->link=SLL;
}
void Deleteend()
{
	struct node *temp=head;
	struct node *t;
	if(head==NULL)
		printf("Linked list is empty\n");
	else
	{
		while(temp->link!=NULL)
		{
			t=temp;
			temp=temp->link;
		}
		printf("The deleted node is: \n");
		printf("usn=%s\n",temp->usn);
		printf("name=%s\n",temp->name);
		printf("branch=%s\n",temp->branch);
		printf("sem=%s\n",temp->sem);
		printf("phone no=%s\n",temp->phone);
		free(t->link);
		t->link=NULL;
	}
}
void Create()
{
	int i,n;
	printf("Enter the no. of students\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		insertfront();
	}
}
void Display()
{
	int c=0;
	struct node *temp=head;
	while(temp!=NULL)
	{
		fflush(stdout);
		printf("\n %s\t",temp->usn);
		printf("%s\t",temp->name);
		printf("%s\t",temp->branch);
		printf("%s\t",temp->sem);
		printf("%s\t",temp->phone);
		temp=temp->link;
		c=c+1;
	}
	printf("The no. of nodes: %d",c);
}
void Stack()
{
	int choice;
	printf("\n 1:PUSH \n 2:POP \n 3:DISPLAY \n Enter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("Enter the elements to be pushed onto the stack \n");
				Insertfront();
				break;
		case 2: printf("The popped node is: \n");
				Delfront();
				break;
		case 3: printf("The stack is: \n");
				Display();
				break;
	}
}
int main()
{
	int ch1,ch2,ch3;
	clrscr();
	while(1)
	{
		printf("\n Enter your choice: \n 1:Create\n 2:Display and Count\n 3:Insert and delete at end\n 4:Insert and delete from front\n 5:SLL as stack\n 6:Exit");
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
			case 5: Stack();
					break;
			case 6: exit(0);
		}
	}
}



